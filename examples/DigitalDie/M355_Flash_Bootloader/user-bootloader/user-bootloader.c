/*! *****************************************************************************
 * \brief: Implements user bootloader
 * @version  V0.1
 * @author   Analog Devices
 * @date     July 2018

   Copyright (c) 2018 Analog Devices, Inc.  All Rights Reserved.
   This software is proprietary and confidential to Analog Devices, Inc. and its
   licensors

*****************************************************************************/
#include <stddef.h>     /* for 'NULL' */
#include <adi_types.h>
#include <ADuCM355.h>
#include "DioLib.h"
#include "ADuCM355_bitm.h"
#include "user-bootloader.h"

//////////////////////////////////////////////////////////
// #define WRITEPROTECT_BOOTLOADER
// #define DISABLE_SERIALWIRE

/* User Bootload Pin Definition !!! P1.0 !!! */
#define USER_BOOTLOADER_GPIOPORT pADI_GPIO1
#define USER_BOOTLOADER_GPIOPIN  PIN0

//////////////////////////////////////////////////////////

#define ATTRIBUTE_INTERRUPT
#define WEAK_PROTO(proto)              __weak proto
#define WEAK_FUNC(func)                __weak func
#define WEAK_PROTOTYPE(x) WEAK_PROTO ( void x (void)) ATTRIBUTE_INTERRUPT ;
#define WEAK_FUNCTION(x)  WEAK_FUNC  ( void x (void)) { while(1); }


/* Serial downloader protocol definition */
#define     PACKET_START_ID0        (0x07)
#define     PACKET_START_ID1        (0x0E)
#define     SERIAL_DOWNLOADER_ACK   (0x06)                          /* Positive response: ACK (0x06) */
#define     SERIAL_DOWNLOADER_NACK  (0x07)

#define     INFO_COMMAND            (0x45)
#define     DOWNLOAD_COMMAND        (0x57)
#define     RUN_COMMAND             (0x52)

//

typedef void  ( *IntFunc )( void );
typedef void  ( *ADIIntFunc )( void );
typedef union
{
    ADIIntFunc __fun;
    void      *__ptr;
    IntFunc    __ifunc;
} IntVector;

WEAK_FUNCTION( NmiSR                    )
WEAK_FUNCTION( MemManage_Handler        )
WEAK_FUNCTION( RESERVED_VECTOR          )

WEAK_PROTOTYPE( ResetISR                )


typedef struct
{
    uint8_t  ReadProtectionKeyHash[16];
    uint32_t ReadProtectionKeyHashCRC;
    uint32_t FinalUserCRCPage;
    uint32_t Unused;
    uint32_t WriteProtection;
} FlashMetaData;


#define FLASH_PAGE_SIZE 2048
/* Magic numbers for command ID field. */
#define CMD_ID0 0x07
#define CMD_ID1 0x0E

/* Positive and negative command responses. */
#define CMD_ACK 0x06
#define CMD_NAK 0x07

#define MIN_CMD_LEN 5    /* One-byte command and four-byte address fields. */
#define MAX_CMD_LEN 255

#define METADATA_OFFSET         0x180
#define KERNEL_COMMS_REG        *(unsigned long *)0x40007008
#define UART_ERRORMASK          0x00000018                      /*  Break Indicator or Frame Error */
#define UART_AB_ERRORMASK       0x0000000E                      /*  Mask for AutoBaud Errors BRKTO, NSETO, NEETO */

#define MAX_USERFLASH_PAGES     64                             /* Maximum number of pages available in User Flash*/

#define KERNEL_COMMS_REG        *(unsigned long *)0x40007008

/* Linker provided symbols */
extern uint32_t __relocated_application_start;
extern uint32_t FINAL_CRC_PAGE;  /* Linker Symbol */

__noreturn void SRAM_Downloader(void);

const unsigned char PRODUCTID_ADDR[12] = {'A', 'D', 'U', 'C', 'M', '3', '5', '5', ' ', ' ', ' ', ' '};

/* Local static Functions */
static bool_t DoEnterBootloader(void);
static __noreturn void RunUserCode(void);
static void    SetBaudRate      (void);
static uint8_t Hex_To_Ascii     (uint8_t hexval);

/**
 *  \brief Hard Fault Handler
 *
 *  \return Return description
 *
 *  \details Handler for Hard Fault Location within the "User Bootloder"
 */
void HardFault_Handler (void)
{
    while(1);
}

// Interrupt Vector Table
#pragma segment="CSTACK"
#pragma location = ".intvec"
const IntVector __vector_table[] =
{
    // grab stack pointer "end" address from ICF file
    { .__ptr = __sfe( "CSTACK" ) },

    // exception mappings...
    { .__ifunc = ResetISR                 },   /* -15 */
    { .__ifunc = NmiSR                    },   /* -14 */
    { .__ifunc = HardFault_Handler        },   /* -13 */
    { .__ifunc = RESERVED_VECTOR          },   /* -12 */
    { .__ifunc = RESERVED_VECTOR          },   /* -11 */
    { .__ifunc = RESERVED_VECTOR          },   /* -10 */
    { .__ifunc = RESERVED_VECTOR          },   /* -09 */
    { .__ifunc = RESERVED_VECTOR          },   /* -08 */
    { .__ifunc = RESERVED_VECTOR          },   /* -07 */
    { .__ifunc = RESERVED_VECTOR          },   /* -06 */
    { .__ifunc = RESERVED_VECTOR          },   /* -05 */
    { .__ifunc = RESERVED_VECTOR          },   /* -04 */
    { .__ifunc = RESERVED_VECTOR          },   /* -03 */
    { .__ifunc = RESERVED_VECTOR          },   /* -02 */
    { .__ifunc = RESERVED_VECTOR          },   /* -01 */
} ;

#pragma location="ReadProtectedKeyHash"
#ifdef DISABLE_SERIALWIRE
__root const uint32_t ReadProKeyHsh[] = { 0x12345678, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
#else
__root const uint32_t ReadProKeyHsh[] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
#endif

#pragma location="CRC_ReadProtectedKeyHash"
__root const uint32_t CrcOfReadKey = 0xA79C3203;

#pragma location="FinalCRCPage"
__root const uint32_t FinalCRCPage = (uint32_t) &FINAL_CRC_PAGE;


#pragma location="WriteProtect"
#ifdef WRITEPROTECT_BOOTLOADER
__root const uint32_t WriteProtection = (uint32_t)0xFFFFFFFE;
#else
__root const uint32_t WriteProtection = (uint32_t)0xFFFFFFFF;
#endif
/*The pages are protected in groups of four, with each bit
in the 32-bit word corresponding to four continuous flash
pages*/


//*****************************************************************************
// IAR system startup functions.
//*****************************************************************************
WEAK_PROTO( void __iar_init_core (void));
WEAK_PROTO( void __iar_init_vfp  (void));
extern      void __cmain();

//*****************************************************************************
// Function    : ResetISR (-15)
// Description : Reset event handler
//*****************************************************************************

WEAK_FUNC (void ResetISR (void))
{
    // Call IAR system startup
    __iar_init_core();
    __iar_init_vfp();

    __cmain();

    // Stick here if main returns
    while(1);
}


/**
 *  \brief
 *
 *  \return None
 *
 *  \details More details
 */
void ConfigureGPIOForUBM(bool_t enable)
{
    if(enable)
    {
        /* User Bootmode Pin Configuration */
        DioCfgPin(USER_BOOTLOADER_GPIOPORT, USER_BOOTLOADER_GPIOPIN, 0);  // GPIO mode...
        DioIenPin(USER_BOOTLOADER_GPIOPORT, USER_BOOTLOADER_GPIOPIN, 1);  // ....input...
        DioPulPin(USER_BOOTLOADER_GPIOPORT, USER_BOOTLOADER_GPIOPIN, 1);  // ... enable pull-up ...
    }
    else
    {
        /* User Bootmode Pin Configuration clean-up */
        DioCfgPin(USER_BOOTLOADER_GPIOPORT, USER_BOOTLOADER_GPIOPIN, 0);  // GPIO mode...
        DioIenPin(USER_BOOTLOADER_GPIOPORT, USER_BOOTLOADER_GPIOPIN, 0);  // ....input...
        DioPulPin(USER_BOOTLOADER_GPIOPORT, USER_BOOTLOADER_GPIOPIN, 0);  // ... enable pull-up ...
    }


}

/**
 *  \brief "User Bootloader" main function
 *
 *  \return 
 *
 *  \details Decide on whether to run "User Firmware" or "Bootloader" functionality
 */
__noreturn void main (void)
{

    if (DoEnterBootloader())
    {
        SRAM_Downloader();
    }
    else
    {
        RunUserCode();
    }
}

/**
 *  \brief Decide whether to enter the bootloader or continue to user firmware
 *
 *  \return True, if downloader is to be entered, else False
 *
 *  \details Residing in a write protected 8K block at the start of flash, this application will run
 *           after all resets and either run the bootloader to downloader a new user firmware, or
 *           exit to an existing user firmware if valid.
 *
 */
static bool_t DoEnterBootloader(void)
{
    bool_t enter = false;

    /* Highest Priority: Operator may force entry to bootloader via GPIO */
    ConfigureGPIOForUBM(true);
    if ((DioRd(USER_BOOTLOADER_GPIOPORT) & USER_BOOTLOADER_GPIOPIN) == 0)
    {
        enter = true;
    }
    else
    {
        /* If the user firmware is not present, or valid then default to bootloader */
        if (Blank_Check() == '-' ||  CRC_Check() == 'F')
        {
            enter = true;
        }
    }
    ConfigureGPIOForUBM(false);


    return enter;
}



/**
 *  \brief This function Checks whether the user firmware area is blank or not
 *
 *  \return X :  Indicated Flash is not Blank
 *
                         X :  Indicated Flash is not Blank
                        - :  Indicated Flash is Blank


 *  \details Perform a sign of the user firmware area. If sign matches that for all erased then it is blank
 *
 *           We cannot use the BLANKCHECK commmand as the bootloader is present.
 *
 */
uint8_t Blank_Check(void)
{
    bool_t Repeat = true;
    uint32_t FlashStatus;

    while(Repeat)
    {
        Repeat = false;


        pADI_FLCC0->STAT = 0xFFFF; /* Clear all pending status */

        /* Write the Page 0 as Start address */
        pADI_FLCC0->PAGE_ADDR0 = (uint32_t)&__relocated_application_start;
        pADI_FLCC0->PAGE_ADDR1 = (MAX_USERFLASH_PAGES - 1) << 11; /* Covert the page number into page address */
        /* Write the Page N as End address */
        pADI_FLCC0->KEY = ENUM_FLCC_KEY_USERKEY;
        pADI_FLCC0->CMD = ENUM_FLCC_CMD_SIGN;

        /* Wait until the command is complete */
        do
        {
            FlashStatus = pADI_FLCC0->STAT;
        }
        while((FlashStatus & BITM_FLCC_STAT_CMDCOMP) == 0x0);

        switch ((FlashStatus & BITM_FLCC_STAT_CMDFAIL) >> BITP_FLCC_STAT_CMDFAIL)
        {
        case 0x0: /* if CMDFAIL value is 0x0, then CRC passed */
        case 0x2: /* if CMDFAIL value is 0x2, then CRC failed */
            break;
        default:
            /* If CMDFAIl is neither 0x0/0x2, repeat CRC Check */
            Repeat = true;
            break;
        }
    }

    if (pADI_FLCC0->SIGNATURE != 0xCF1FB703)
        return 'X';
    else
        return '-';
}



/**
 *  \brief This function Checks whether the CRC of USER Flash Page 0 is valid or not
 *
 *  \return True, if checksum passed, else False
 *
 *      Function name   :   CRC_Check
    Description     :   This function Checks whether the CRC of USER Flash Page 0 is valid or not amd stores
                        the status in 'FLASH_CRCSTATUS' variable
                        P :  Indicated Checksum passed
                        F :  Indicated Checksum failed
 *
 *  \details
 *           
 */
uint8_t CRC_Check(void)
{
    uint8_t Valid = 'F';
    bool_t Repeat = true;
    uint32_t FlashStatus;
    FlashMetaData *pUserFirmwareMeta = (FlashMetaData *)((uint32_t)&__relocated_application_start + METADATA_OFFSET);

    while(Repeat)
    {
        Repeat = false;

        /* If last page is beyond the valid flash range, then skip CRC calculation and return CRC failure */
        if ((pUserFirmwareMeta->FinalUserCRCPage > (uint32_t)&FINAL_CRC_PAGE) && (pUserFirmwareMeta->FinalUserCRCPage < MAX_USERFLASH_PAGES ))
        {
            pADI_FLCC0->STAT = 0xFFFF; /* Clear all pending status */

            /* Write the Page 0 as Start address */
            pADI_FLCC0->PAGE_ADDR0 = (uint32_t)&__relocated_application_start;
            pADI_FLCC0->PAGE_ADDR1 = pUserFirmwareMeta->FinalUserCRCPage << 11; /* Covert the page number into page address */
            /* Write the Page N as End address */
            pADI_FLCC0->KEY = ENUM_FLCC_KEY_USERKEY;
            pADI_FLCC0->CMD = ENUM_FLCC_CMD_SIGN;

            /* Wait until the command is complete */
            do
            {
                FlashStatus = pADI_FLCC0->STAT;
}
            while((FlashStatus & BITM_FLCC_STAT_CMDCOMP) == 0x0);

            switch ((FlashStatus & BITM_FLCC_STAT_CMDFAIL) >> BITP_FLCC_STAT_CMDFAIL)
            {
            case 0x0: /* if CMDFAIL value is 0x0, then CRC passed */
                Valid = 'P';
                break;
            case 0x2: /* if CMDFAIL value is 0x2, then CRC failed */
                Valid = 'F';
                break;
            default:
                /* If CMDFAIl is neither 0x0/0x2, repeat CRC Check */
                Repeat = true;
                break;
            }
            /* Clean-Up */
            pADI_FLCC0->PAGE_ADDR0 = 0x0;
            pADI_FLCC0->PAGE_ADDR1 = 0x0;
            pADI_FLCC0->KEY = 0x0;
        }
    }

    return Valid;
}



/**
 *  \brief Switch to running "user firmware"
 *
 *  \return None
 *
 *  \details Exit from the "user bootloader" and hand control over to the "user firmware"
 *           
 */
static __noreturn void RunUserCode(void)
{
    uint32_t *application_vector_table = ( uint32_t *) &__relocated_application_start;

    /* Relocate the VTOR to pointer to the application vector table */
    SCB->VTOR = (uint32_t) application_vector_table;
    /* Use the stack pointer from the application */
    __set_MSP(application_vector_table[0]);

    /* Jump to the application entry point */
    ((IntFunc)application_vector_table[1])();
}

/**
 *  \brief AutoBaud on received Backspace character
 *
 *  \return None
 *
 *  \details    This function enables UART for Autobaud detection and determines the Baudrate rate.
 *                       Uart Timer is used to measure a UART character to determine the baud rate. This
 *                       timer expects to see the ASCII carriage return character 0x0D which can be typed
 *                       into a terminal interface or sent from a dedicated software program. The timer will
 *                       measure the time over eight data bits from the rising edge beginning the first data
 *                       bit to the rising edge ending the last data bit. The 16-bit timer has a 3-bit
 *                       pre-scale which effectively divides the count by eight to provide the number of
 *                       clock cycles for one data bit. This value is used by software to configure the UART
 *                       baud rate.
 *
 *                       Out of reset PCLK = 6.5 MHz,
 *                       Baudrate = uclk/(2*(M+N/2^11)*16*COMDIV)
 *
 */
void SetBaudRate(void)
{
    bool_t   bComplete = false;
    uint8_t  RegVal;
    uint32_t UclkTicksInUartBit;
    uint32_t val_M = 1;
    uint32_t val_N = 0;
    uint32_t val_COMDIV = 1;

    while (!bComplete)
    {
        /* Configure LSR register with  PEN = 0, STOP = 1, WLS = 8-bits */
        pADI_UART0->COMLCR = 0x3;

        /* Set the oversampling rate to 16 */
        pADI_UART0->COMLCR2 = 0x2;

        /* Enable the Autobaud detection in AB Control register */
        /* Set the First rising edge as Start edge and last(9th) edge as End edge */
        /* as 0xD is the autobaud character */
        pADI_UART0->COMACR =  0x311;

        /* Wait for Done bit to be set in UART_ASRL register */
        do
        {
            RegVal = pADI_UART0->COMASRL;
            if (RegVal & UART_AB_ERRORMASK)
            {
                /* If errors occured in AB deection start the auto-baud search */
                pADI_UART0->COMACR =  0x0; /* Disable the timer */
                pADI_UART0->COMACR =  0x311; /* Re-enable the timer */
            }
        }
        while((RegVal & 0x1) == 0x0 );   /* Wait till AB Done is set */

        /* The autobaud value is the number of UCLKS in 8 UART Bits.
           Divide by 8 == shift right by 3 bits
           i.e UCLK/BR
        */
        UclkTicksInUartBit = ((pADI_UART0->COMASRL >> 4) | (pADI_UART0->COMASRH << 12)) >> 3;

        pADI_UART0->COMACR =  0x0; /* Disable the Auto Baud timer */

        /***************************************************************************/
        /*      Baudrate = uclk/((M+N/2^11)*16*COMDIV)                             */
        /*      uclk/baudrate = 16*(1+N/2^11)*COMDIV  ,  Fixing M=1                */
        /*      COMDIV=(uclk/baudrate)/32                                          */
        /*      N= ((UCLK/BR/COMDIV)*2048/16) - 2048                               */
        /***************************************************************************/

        val_COMDIV = UclkTicksInUartBit >> 4; // Divide by 16

        if (val_COMDIV)
        {
            bComplete = true;
            pADI_UART0->COMDIV = UclkTicksInUartBit >> 4;

            val_N = ((UclkTicksInUartBit << 7) / (UclkTicksInUartBit >> 4)) - 2048;

            pADI_UART0->COMFBR = (  (1     << BITP_UART_COMFBR_FBEN    ) |
                                    (val_M << BITP_UART_COMFBR_DIVM    ) |
                                    (val_N << BITP_UART_COMFBR_DIVN   ));

            /* Enable UART */
            pADI_UART0->COMCTL = BITM_UART_COMCTL_FORCECLKON;
        }

    }

}



/**************************************************************************************************************
    Function name   :   SRAM_Downloader
    Description     :   This function enable the UART Tx/Tx and SPI Rx/Tx and detects which interface is
                            active and  accordingly uses the interface(UART or SPI) to download the code to
                            processors SRAM
**************************************************************************************************************/
__noreturn void SRAM_Downloader(void)
{
    /* Load the status of the die2die interface */
    /* Check if ok */
    /* If not ok, skip turning off AFE watchdog */
    if (KERNEL_COMMS_REG == 0x0)
    {
        pADI_AFEWDT->WDTCON = 0xC9;
    }
    /* Enable the UART Rx and UART Tx in GPIO mux */
    DioCfgPin(pADI_GPIO0, PIN10, 1);  // TX UART mode...
    DioCfgPin(pADI_GPIO0, PIN11, 1);  // RX UART mode...

    /* Calculate the baud rate and configure UART */
    SetBaudRate();

    /* Send Part Info after AutoBaud competion */
    Send_Info();

    /* Start receiving the commands here */
    StartDownloadPacket();
}



/* Receive character from UART. */
static uint8_t uart_getc(void)
{
    while (!(*pREG_UART0_COMLSR & BITM_UART_COMLSR_DR));      /* Wait for received byte. */
    return *pREG_UART0_COMRX;
}

/* Send character to UART. */
static void uart_putc(uint8_t c)
{
    while (!(*pREG_UART0_COMLSR & BITM_UART_COMLSR_THRE));    /* Wait for empty transmit buffer. */
    *pREG_UART0_COMTX = c;

}

/* Send half word to UART. */
static void uart_puth(uint32_t h)
{
  uart_putc((h >> 0) & 0xFF);
  uart_putc((h >> 8) & 0xFF);
}


/* Send word to UART. */
static void uart_putw(uint32_t w)
{
  uart_putc((w >> 0) & 0xFF);
  uart_putc((w >> 8) & 0xFF);
  uart_putc((w >> 16) & 0xFF);
  uart_putc((w >> 24) & 0xFF);
}


/* Initialize flash controller. */
static void flash_init(void)
{
    *pREG_FLCC0_IEN  = 0;                                     /* Clear interrupts. */
    *pREG_FLCC0_STAT = 0xFFFFFFFF;                            /* Clear status register. */
    *pREG_FLCC0_ECC_CFG = BITM_FLCC_ECC_CFG_INFOEN | BITM_FLCC_ECC_CFG_EN;
    /* Enable ECC for user space. */
}

/* Initiate flash controller command and return succes. */
static bool flash_command(uint32_t cmd)
{
    *pREG_FLCC0_STAT = BITM_FLCC_STAT_CMDCOMP |               /* Clear status. */
                       BITM_FLCC_STAT_CMDFAIL;
    *pREG_FLCC0_CMD = cmd;
    while (!(*pREG_FLCC0_STAT & BITM_FLCC_STAT_CMDCOMP));     /* Wait for completion. */
    return (*pREG_FLCC0_STAT & BITM_FLCC_STAT_CMDFAIL) == 0;  /* Return success. */
}


/* Check whether flash is blank. */
static bool flash_blank_check(void)
{

    return Blank_Check() == '-';
}

/**
   @brief uint8_t FlashErasePages(uint32_t StartAddr,uint32_t EndAddr);
      ========== Erase multiple pages

   @param StartAddr :{0-0x1FFFF}
      -  address from which page to start erase
   @param EndAddr :{0-0x1FFFF}
      -  address until which page to erase
   @return 1
**/
static bool FlashErasePages(uint32_t StartAddr, uint32_t EndAddr)
{
    uint32_t addr;
    addr = StartAddr >= (uint32_t)&__relocated_application_start ? StartAddr : (uint32_t)&__relocated_application_start;
    while(addr <= EndAddr)
    {
        pADI_FLCC0->KEY = ENUM_FLCC_KEY_USERKEY;
        pADI_FLCC0->PAGE_ADDR0 = addr;
        if(!flash_command(ENUM_FLCC_CMD_ERASEPAGE))
            return false;
        addr += FLASH_PAGE_SIZE;
    }
    return true;
}


/**
 *  \brief Erase all of user flash
 *
 *  \return Returns success
 *
 *  \details This would normally issue a MASSERASE command, and this
 *           would remove any active read or write protected.
 *
 *           Here we cannot issue a mass erase command as
 *              1) If it worked, then the bootloader would be removed too.
 *              2) It can't work, in the case that the bootloader is write
 *                 write protected. (MASSERASE command is blocked if ANY
 *                 page is write protected.)
 *
 *           Therefore we will PAGEERASE all USER FIRMWARE pages.
 */

static bool flash_mass_erase(void)
{
    return FlashErasePages((uint32_t)&__relocated_application_start,
                           0x20000 - FLASH_PAGE_SIZE);
}

static bool flash_page_erase(uint32_t addr, uint32_t count)
{
   return FlashErasePages(addr, addr + count * FLASH_PAGE_SIZE - 1);
}

/* Write 64-bit data chunk to 8-byte aligned address. Returns success. */
static bool flash_write(uint32_t addr, uint64_t data)
{
    bool success = true;
    if (addr < (uint32_t)&__relocated_application_start)
    {
        success =  true;
    }
    else
    {
        *pREG_FLCC0_KH_ADDR = addr;
        *pREG_FLCC0_KH_DATA0 = data;
        *pREG_FLCC0_KH_DATA1 = data >> 32;
        success =  flash_command(ENUM_FLCC_CMD_WRITE);
    }

    if (!success)
        while(1);

    return success;

}

/* Receive command from UART and process it.
 * Returns true if command is valid and successful.
 */
static bool process_cmd(void)
{
    /* Wait for command ID. */
    uint8_t c0, c1 = 0;
    do
    {
        c0 = c1;
        c1 = uart_getc();
    }
    while (c0 != CMD_ID0 && c1 != CMD_ID1);

    /* Get and check command length. Checking against MAX_CMD_LEN is unnecessary
     * as the one-byte length field cannot exceed it.
     */
    uint8_t cmd_len = uart_getc();
    if (cmd_len < MIN_CMD_LEN)
        return false;

    /* Get command code. */
    uint8_t cmd = uart_getc();

    /* Get big-endian address. */
    uint8_t checksum = cmd_len + cmd;
    uint32_t addr = 0;
    for (size_t i = 0; i < 4; i++)
    {
        uint8_t c = uart_getc();
        checksum += c;
        addr = addr << 8 | c;
    }

    /* Get data. */
#ifdef __ICCARM__
#pragma data_alignment = 8
#else
#error Unsupported compiler
#endif
    static uint8_t data[MAX_CMD_LEN - MIN_CMD_LEN];
    size_t data_len = cmd_len - MIN_CMD_LEN;
    for (size_t i = 0; i < data_len; i++)
        checksum += (data[i] = uart_getc());

    /* Test checksum. */
    checksum += uart_getc();
    if (checksum != 0)
        return false;

    /* Erase All command. Try blank check before doing the actual erase.
     * If either is successful, the flash controller will lift any read/write restriction.
     */
    if (cmd == 'A' && data_len == 0)
        return flash_blank_check() || flash_mass_erase();

    if (cmd == 'E' && data_len == 1)
        return flash_page_erase(addr, data[0]);

    /* Write command. Requires 8-byte aligned address and length. */
    if (cmd == 'W' && addr % 8 == 0 && data_len % 8 == 0)
    {
        for (size_t i = 0; i < data_len; i += 8)
        {
            if (!flash_write(addr + i, *(uint64_t *)(data + i)))
                return false;
        }
        return true;
    }

    /* Unknown or malformed command. */
    return false;
}

int Run_Command(void)
{
    /* Wait for carriage return from host. */
    while (uart_getc() != 0xD);

    /* Send acknowledgement. */
    static const char reply[24] =
    {
        'A', 'D', 'u', 'C', 'M', '3', '0', '2', 'x', ' ', ' ',  ' ', ' ', ' ', ' ',
        '0', '0', '0',
        ' ', ' ', ' ', ' ',
        0xA, 0xD
    };
    for (size_t i = 0; i < sizeof reply; i++)
        uart_putc(reply[i]);

    /* Initialize flash controller. */
    flash_init();

    /* Process commands coming in via UART and send response. */
    for (;;)
    {
        bool ok = process_cmd();
        uart_putc(ok ? CMD_ACK : CMD_NAK);
    }
}

/* Addresses of Product infomation in Info Space */
#define     SERIALID_ADDR           0x00040770                      /* Address where 16-Byte Serial ID is stored  */
#define     KERNALREV_ADDR          0x00040730                      /* Address where 2-Byte Kernel Revision is stored */
#define     WRITE_PROTECT_KEY       0x4E6F5772                      /* 'NoWr': Write Protection Key */
#define     ICWP_KEYADDRESS         0x00000198                      /* In Circuit Write Protection key address in User Flash */
#define     WP_KEYADDRESS           0x0000019C                      /* Flash Page Write Protection key address in User Flash */
/**************************************************************************************************************
    Function name   :   Send_Info
    Description     :   This function sends the Part Information data to the Host
                            in return to autoBaud as well as Info request command a
                            Charater over UART.

    Register Usage      :   R4  holds the Info space address
**************************************************************************************************************/
void Send_Info(void)
{
    uint32_t *pPtr32 = (uint32_t *)PRODUCTID_ADDR;
    uint8_t *pPtr8;
    uint32_t Loop;

    /* Send 15-Bytes of Product Identified Data, 9-byte Identifer followed by 6 Spaces*/
    pPtr32 = (uint32_t *)PRODUCTID_ADDR;
    uart_putw(*(pPtr32++));
    uart_putw(*(pPtr32++));
    /* Load the byte 9 of Procut ID in R0 */
    /* Mask th Bytes 10-12 as they do not contain valid data */
    uart_putc((*(pPtr32++)) & 0xFF);

    /* Transmit 6-bytes of Space charaters */
    uart_putc(0x20);
    uart_putc(0x20);
    uart_putc(0x20);
    uart_putc(0x20);
    uart_putc(0x20);
    uart_putc(0x20);

    /* Send 3-bytes of Hardware and Firmware(Kernel) version numbers */
    pPtr32 = (uint32_t *)REG_SYS_CHIPID;
    /* Extract Silicon revision and convert to ASCII */
    uart_putc(Hex_To_Ascii((*(pPtr32++)) & 0xF));

    /* Read the 2-byte Kernal Revision in R2 */
    pPtr32 = (uint32_t *)KERNALREV_ADDR;
    uart_puth((*(pPtr32++)) & 0xFFFF);

    /* Check and send user code blank status */
    uart_putc(Blank_Check());

    /* Check and send user code CRC status */
    uart_putc(CRC_Check());

    /* Check and send Write protection status */
    /* If Key Matches NoWr, store the Write protection Flag in R0*/
    /* Else, store the No Write protection Flag in R0*/
    pPtr32 = (uint32_t *)ICWP_KEYADDRESS;
    if(*pPtr32 == WRITE_PROTECT_KEY)
    {
        uart_putc('-');
    }
    else
    {
        uart_putc('W');
    }


    /* Check and send read protection status */
    uart_putc('-');

    /* Send One Space Character */
    uart_putc(' ');

    /* Send 16-byte serial number stored @0x00040770 as 32-bytes ACSII charactes*/
    pPtr8 = (uint8_t *)SERIALID_ADDR;
    for (Loop = 0; Loop < 16; Loop++)
    {
        uart_putc(Hex_To_Ascii(((*pPtr8) >> 0) & 0xF));
        uart_putc(Hex_To_Ascii(((*pPtr8) >> 4) & 0xF));
        pPtr8++;
    }

    /* Line Feed */
    uart_putc(0xA);


    /* Carriage return */
    uart_putc(0xD);


}




/**************************************************************************************************************
    Function name   :   Hex_To_Ascii
    Description     :   This function converts the 4-bit Hex value in R1 into 8-bit ASCII value  and
                            stores the result in R0

    Register Usage      :   R0 holds converted ASCII output
                            R1 holds the input
**************************************************************************************************************/
static uint8_t Hex_To_Ascii(uint8_t hexval)
{
    uint8_t asciival = hexval;

    if (hexval < 10)
    {
        /* If value is between 0-9, Add 0x30 to get equivalent ASCII value */
        asciival += 0x30;
    }
    else
    {
        /* If value is between 0xA-0xF, Add 0x37 to get equivalent ASCII value */
        asciival += 0x37;
    }

    return asciival;
}

/**************************************************************************************************************
    Function name   : StartDownloadPacket
    Description     :


    Register Usage      :

**************************************************************************************************************/
__noreturn void StartDownloadPacket(void)
{
    uint8_t  RxChar;
    uint8_t  BytesInPacket;
    uint8_t  BytesRemaining_R10;
    uint8_t  CheckSum_R4;
    uint8_t  Command_R11;
    uint8_t  AckStatus;
    uint32_t Address_R12;


    RxChar = uart_getc();
    while(1)
    {
        if(RxChar != PACKET_START_ID0)  /* Read 1 byte */
        {
            /* Is it expected first byte? */
            /* If not, repeat until correct byte received */
            RxChar = uart_getc();
            continue;
        }
        RxChar = uart_getc();
        if (RxChar == PACKET_START_ID1)
        {
            /* DownloadPacket */
            BytesInPacket = uart_getc();
            BytesRemaining_R10 = BytesInPacket;

            /* Check if no of bytes is atleast 5 because minimum is (1 command + 4 address bytes) */
            if(BytesInPacket >= 5)
            {
                /* Store running Checksum */
                CheckSum_R4 = BytesInPacket;

                /**************************************
                Read Data 1 (command code)
                ***************************************/
                RxChar = uart_getc();
                CheckSum_R4 += RxChar;
                Command_R11 = RxChar;

                /*************************************
                Read Data 2-5 (h,u,m,l)
                **************************************/
                RxChar = uart_getc();
                CheckSum_R4 += RxChar;
                Address_R12 = ((uint32_t)RxChar) << 24;

                RxChar = uart_getc();
                CheckSum_R4 += RxChar;
                Address_R12 |= ((uint32_t)RxChar) << 16;

                RxChar = uart_getc();
                CheckSum_R4 += RxChar;
                Address_R12 |= ((uint32_t)RxChar) << 8;

                RxChar = uart_getc();
                CheckSum_R4 += RxChar;
                Address_R12 |= ((uint32_t)RxChar) << 0;


                BytesRemaining_R10 -= 0x5;

                /* If it is not a download command then wait for a valid command */
                if (BytesRemaining_R10 && (Command_R11 != DOWNLOAD_COMMAND))
                    continue;

                while (BytesRemaining_R10--)
                {
                    Address_R12 = Address_R12;
                    /*-----------------------*/
                    /*   DOWNLOAD COMMAND (This was downloading routines into SRAM in the factory version) */
                    /*-----------------------*/
                    RxChar = uart_getc();
                    CheckSum_R4 += RxChar;
                }

                RxChar = uart_getc();
                CheckSum_R4 += RxChar;

                if(CheckSum_R4 != 0x0)
                {
                    AckStatus = SERIAL_DOWNLOADER_NACK;
                }
                else
                {
                    AckStatus = SERIAL_DOWNLOADER_ACK;
                }
                uart_putc(AckStatus);

                if(AckStatus != SERIAL_DOWNLOADER_ACK)
                {
                    continue;
                }

                if (Command_R11 == INFO_COMMAND)
                {
                    Send_Info();

                }
                else if (Command_R11 == RUN_COMMAND)
                {
                    Run_Command();
                }

            }
        }
    }



}