/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#include "adi_config.h"
#include "startup_ADuCM355.h"
#include "system_ADuCM355.h"
 //  #include <device.h>
#include <system_ADuCM355.h>
#include "UrtLib.h"
#include "IntLib.h"
//#include "AdcLib.h"
#include "DioLib.h"
#ifdef _USING_UCOS_II_
#include <os_cpu.h>
#endif

/*
    Stack size considerations for RTOS environments:

    In the Cortex-M class processors, the hardware has two stacks: the main stack
    and the process stack.  The main stack is used at reset and by system exception
    handlers.  In simple applications (non-RTOS) you may only use this stack.  In
    more complex systems that use an RTOS you have a split between the main stack
    which is used by the kernel and exception handlers and the process stack which
    is used by the tasks and programmable interrupts (interrupts stack on top of
    the currently active task, so tasks stacks should be allocated for worst-case
    interrupt scenarios).  In the uCOS case, the process stack is the one that gets
    context-switched and used by the tasks, where we store the registers, etc.

    As RTOS tasks specify their own stack area, a minimal size of 4 for the process
    stack in order to retain symbols, etc., seems OK and we would not need any more.
    The main stack needs to be big enough to initialize the RTOS, run interrupts etc.

    As always, stack and heap size optimizations is a balancing act between usage
    and available memory.  It is entirely application-dependant.

*/


//*****************************************************************************
//
// The minimal vector table for a Cortex M3.  Note that the proper constructs
// must be placed on this to ensure that it ends up at physical address
// 0x0000.0000.
//
//*****************************************************************************

//****************************************************************************************************************
//
// When operating in an RTOS context, interrupts are dispatched by the NVIC controller
// to a second level dispatch function known as the OSAL (operating system abstraction layer) dispatch.
// The OSAL dispatch has common code that will interact with the RTOS.
//
// OSAL dispatched interrupts must pass their Interrupt ID (iid) to the common OSAL dispatcher.
//
// System interrupts (Reset through SysTick) should never dispatch through the OSAL.
//
// The IntFunc typedef is used for System Interrupts handlers. The parameter list for these interrupts is always 'void'.
//
// The ADIIntFunc typdef is used for Driver Interrupt Handlers. The parameter list for these handlers
// will change depending on the RTOS context. In an RTOS context the IID (Interrupt ID) must be passed to the OSAL
// dispatcher (along with a second arg of type void * which is handler specific). In a non-RTOS context the handler
// parameters is simply 'void'.
//
//*****************************************************************************************************************

// IVT typedefs
typedef void  ( *IntFunc )( void );
#if (ADI_CFG_ENABLE_RTOS_SUPPORT == 1)
typedef void  ( *ADIIntFunc )( uint32_t, void* );
#else
typedef void  ( *ADIIntFunc )( void );
#endif

typedef union { ADIIntFunc __fun; void * __ptr;  IntFunc __ifunc; } IntVector;

WEAK_FUNCTION( NmiSR                    )
WEAK_FUNCTION( HardFault_Handler        )
WEAK_FUNCTION( MemManage_Handler        )
WEAK_FUNCTION( BusFault_Handler         )
WEAK_FUNCTION( UsageFault_Handler       )
WEAK_FUNCTION( SVC_Handler              )
WEAK_FUNCTION( DebugMon_Handler         )
WEAK_FUNCTION( PENDSV_HANDLER           )
WEAK_FUNCTION( SysTick_Handler          )
ADI_WEAK_FUNCTION( RTC1_Int_Handler       )
ADI_WEAK_FUNCTION( Ext_Int0_Handler         )
ADI_WEAK_FUNCTION( Ext_Int1_Handler         )
ADI_WEAK_FUNCTION( Ext_Int2_Handler         )
ADI_WEAK_FUNCTION( Afe_Int3_Handler         )
ADI_WEAK_FUNCTION( WDog_Tmr_Int_Handler     )
ADI_WEAK_FUNCTION( Vreg_over_Int_Handler     )
ADI_WEAK_FUNCTION( Battery_Voltage_Int_Handler     )
ADI_WEAK_FUNCTION( RTC0_Int_Handler     )
ADI_WEAK_FUNCTION( GPIO_A_Int_Handler       )
ADI_WEAK_FUNCTION( GPIO_B_Int_Handler       )
ADI_WEAK_FUNCTION( GP_Tmr0_Int_Handler      )
ADI_WEAK_FUNCTION( GP_Tmr1_Int_Handler      )
ADI_WEAK_FUNCTION( Flash0_Int_Handler       )
ADI_WEAK_FUNCTION( UART_Int_Handler         )
ADI_WEAK_FUNCTION( SPI0_Int_Handler         )
ADI_WEAK_FUNCTION( SPI1_Int_Handler         )
ADI_WEAK_FUNCTION( I2C0_Slave_Int_Handler   )
ADI_WEAK_FUNCTION( I2C0_Master_Int_Handler  )
ADI_WEAK_FUNCTION( DMA_Err_Int_Handler      )
ADI_WEAK_FUNCTION( DMA_SPI1_TX_Int_Handler  )
ADI_WEAK_FUNCTION( DMA_SPI1_RX_Int_Handler  )
/** Placeholder: IRQn = 22 is reserved on the ADuCM355           */
/** Placeholder: IRQn = 23 is reserved on the ADuCM355           */
ADI_WEAK_FUNCTION( DMA_SPI0_TX_Int_Handler  )
ADI_WEAK_FUNCTION( DMA_SPI0_RX_Int_Handler  )
/** Placeholder: IRQn = 26 is reserved on the ADuCM355           */
/** Placeholder: IRQn = 27 is reserved on the ADuCM355           */
ADI_WEAK_FUNCTION( DMA_UART_TX_Int_Handler  )
ADI_WEAK_FUNCTION( DMA_UART_RX_Int_Handler  )
ADI_WEAK_FUNCTION( DMA_I2C0_STX_Int_Handler )
ADI_WEAK_FUNCTION( DMA_I2C0_SRX_Int_Handler )
ADI_WEAK_FUNCTION( DMA_I2C0_MX_Int_Handler  )
ADI_WEAK_FUNCTION( DMA_AES0_IN_Int_Handler  )
ADI_WEAK_FUNCTION( DMA_AES0_OUT_Int_Handler )
ADI_WEAK_FUNCTION( DMA_FLASH0_Int_Handler   )
/** Placeholder: IRQn = 36 is reserved on the ADuCM355           */
/** Placeholder: IRQn = 37 is reserved on the ADuCM355           */
ADI_WEAK_FUNCTION( Crypto_Int_Handler       )
ADI_WEAK_FUNCTION( DMA_ADC0_Int_Handler     )
ADI_WEAK_FUNCTION( GP_Tmr2_Int_Handler      )
/** Placeholder: IRQn = 41 is reserved on the ADuCM355           */
/** Placeholder: IRQn = 42 is reserved on the ADuCM355           */
ADI_WEAK_FUNCTION( PLL_Int_Handler          )
ADI_WEAK_FUNCTION( RNG_Int_Handler          )
/** Placeholder: IRQn = 45 is reserved on the ADuCM355           */
ADI_WEAK_FUNCTION( ADC_Int_Handler          )
ADI_WEAK_FUNCTION( AfeError_Int_Handler     )
ADI_WEAK_FUNCTION( AfeAdc_Int_Handler       )
ADI_WEAK_FUNCTION( AfeGeneral_Int_Handler   )
ADI_WEAK_FUNCTION( AfeCMDFifo_Int_Handler   )
ADI_WEAK_FUNCTION( AfeDATAFifo_Int_Handler  )
ADI_WEAK_FUNCTION( AfeWdt_Int_Handler       )
ADI_WEAK_FUNCTION( AfeCrcError_Int_Handler  )
ADI_WEAK_FUNCTION( AfeGpTimer0_Int_Handler  )
ADI_WEAK_FUNCTION( AfeGpTimer1_Int_Handler  )
ADI_WEAK_FUNCTION( DMA_AfeAdc_Int_Handler   )
ADI_WEAK_FUNCTION( DMA_AfeGeneral_Int_Handler  )
ADI_WEAK_FUNCTION( DMA_AfeCMDFifo_Int_Handler  )
ADI_WEAK_FUNCTION( DMA_AfeDATAFifo_Int_Handler )
ADI_WEAK_FUNCTION( DMA_SIP4_Int_Handler     )
ADI_WEAK_FUNCTION( DMA_SIP5_Int_Handler     )
ADI_WEAK_FUNCTION( DMA_SIP6_Int_Handler     )
ADI_WEAK_FUNCTION( DMA_SIP7_Int_Handler     )
WEAK_FUNCTION( RESERVED_VECTOR              )

// Interrupt Vector Table
#pragma segment="CSTACK"
#pragma location = ".intvec"
const IntVector __vector_table[] =
{
   // grab stack pointer "end" address from ICF file
   { .__ptr = __sfe( "CSTACK" ) },

   // exception mappings...
   { .__ifunc = ResetISR                 } ,  /* -15 */
   { .__ifunc = NmiSR                    } ,  /* -14 */
   { .__ifunc = HardFault_Handler        } ,  /* -13 */
   { .__ifunc = MemManage_Handler        } ,  /* -12 */
   { .__ifunc = BusFault_Handler         } ,  /* -11 */
   { .__ifunc = UsageFault_Handler       } ,  /* -10 */
   { .__ifunc = RESERVED_VECTOR          } ,  /* -09 */
   { .__ifunc = RESERVED_VECTOR          } ,  /* -08 */
   { .__ifunc = RESERVED_VECTOR          } ,  /* -07 */
   { .__ifunc = RESERVED_VECTOR          } ,  /* -06 */
   { .__ifunc = SVC_Handler              } ,  /* -05 */
   { .__ifunc = DebugMon_Handler         } ,  /* -04 */
   { .__ifunc = RESERVED_VECTOR          } ,  /* -03 */
   { .__ifunc = PENDSV_HANDLER           } ,  /* -02  (Micrium overrides weak binding if using uCOS)  */
   { .__ifunc = SysTick_Handler          } ,  /* -01  (Micrium overrides weak binding if using uCOS)  */

   /* programmable interrupt mappings... */
   {RTC1_Int_Handler       } ,                /* 0  */
   {Ext_Int0_Handler         } ,              /* 1  */
   {Ext_Int1_Handler         } ,              /* 2  */
   {Ext_Int2_Handler         } ,              /* 3  */
   {Afe_Int3_Handler         } ,              /* 4  */
   {WDog_Tmr_Int_Handler     } ,              /* 5  */
   {Vreg_over_Int_Handler    } ,              /* 6  */
   {Battery_Voltage_Int_Handler    } ,        /* 7  */
   {RTC0_Int_Handler         } ,              /* 8  */
   {GPIO_A_Int_Handler       } ,              /* 9  */
   {GPIO_B_Int_Handler       } ,              /* 10 */
   {GP_Tmr0_Int_Handler      } ,              /* 11 */
   {GP_Tmr1_Int_Handler      } ,              /* 12 */
   {Flash0_Int_Handler       } ,              /* 13 */
   {UART_Int_Handler         } ,              /* 14 */
   {SPI0_Int_Handler         } ,              /* 15 */
   {SPI1_Int_Handler         } ,              /* 16 */
   {I2C0_Slave_Int_Handler   } ,              /* 17 */
   {I2C0_Master_Int_Handler  } ,              /* 18 */
   {DMA_Err_Int_Handler      } ,              /* 19 */
   {DMA_SPI1_TX_Int_Handler  } ,              /* 20 */
   {DMA_SPI1_RX_Int_Handler  } ,              /* 21 */
   { .__ifunc = RESERVED_VECTOR } ,           /* 22 */
   { .__ifunc = RESERVED_VECTOR } ,           /* 23 */
   {DMA_SPI0_TX_Int_Handler  } ,              /* 24 */
   {DMA_SPI0_RX_Int_Handler  } ,              /* 25 */
   { .__ifunc = RESERVED_VECTOR } ,           /* 26 */
   { .__ifunc = RESERVED_VECTOR } ,           /* 27 */
   {DMA_UART_TX_Int_Handler  } ,              /* 28 */
   {DMA_UART_RX_Int_Handler  } ,              /* 29 */
   {DMA_I2C0_STX_Int_Handler } ,              /* 30 */
   {DMA_I2C0_SRX_Int_Handler } ,              /* 31 */
   {DMA_I2C0_MX_Int_Handler  } ,              /* 32 */
   {DMA_AES0_IN_Int_Handler  } ,              /* 33 */
   {DMA_AES0_OUT_Int_Handler } ,              /* 34 */
   {DMA_FLASH0_Int_Handler   } ,              /* 35 */
   { .__ifunc = RESERVED_VECTOR } ,           /* 36 */
   { .__ifunc = RESERVED_VECTOR } ,           /* 37 */
   {Crypto_Int_Handler       } ,              /* 38 */
   {DMA_ADC0_Int_Handler     } ,              /* 39 */
   {GP_Tmr2_Int_Handler      } ,              /* 40 */
   { .__ifunc = RESERVED_VECTOR } ,           /* 41 */
   { .__ifunc = RESERVED_VECTOR } ,           /* 42 */
   {PLL_Int_Handler          } ,              /* 43 */
   {RNG_Int_Handler          } ,              /* 44 */
   { .__ifunc = RESERVED_VECTOR } ,           /* 45 */
   {ADC_Int_Handler          } ,              /* 46 */
   {AfeError_Int_Handler     } ,              /* 47 */
   {AfeAdc_Int_Handler       } ,              /* 48 */
   {AfeGeneral_Int_Handler   } ,              /* 49 */
   {AfeCMDFifo_Int_Handler   } ,              /* 50 */
   {AfeDATAFifo_Int_Handler  } ,              /* 51 */
   {AfeWdt_Int_Handler       } ,              /* 52 */
   {AfeCrcError_Int_Handler  } ,              /* 53 */
   {AfeGpTimer0_Int_Handler  } ,              /* 54 */
   {AfeGpTimer1_Int_Handler  } ,              /* 55 */
   {DMA_AfeCMDFifo_Int_Handler } ,            /* 56 */
   {DMA_AfeDATAFifo_Int_Handler } ,           /* 57 */
   {DMA_SIP2_Int_Handler     } ,              /* 58 */
   {DMA_SIP3_Int_Handler     } ,              /* 59 */
   {DMA_SIP4_Int_Handler     } ,              /* 60 */
   {DMA_SIP5_Int_Handler     } ,              /* 61 */
   {DMA_SIP6_Int_Handler     } ,              /* 62 */
   {DMA_SIP7_Int_Handler     } ,              /* 63 */

} ;

#pragma location="ReadProtectedKeyHash"
__root const uint32_t ReadProKeyHsh[]={ 0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF};

#pragma location="CRC_ReadProtectedKeyHash"
__root const uint32_t CrcOfReadKey=0xA79C3203;

#pragma location="NumCRCPages"
__root const uint32_t NumOfCRCPages=0;



#ifdef RELOCATE_IVT
/*
   A relocated IVT is requested.  Provision for IVT relocation
   to RAM during startup.  This allows for dynamic interrupt
   vector patching required by RTOS.  Places the relocated IVT
   at the start of RAM.  Note: the IVT placement is required
   to be next power-of-two of the vector table size.  So the
   IVT includes 61   programmable interrupts, 15 system exception
   vectors and the main stack pointer, therefore we need
   (61 + 15 + 1)*4   = 308 bytes, which rounds up to a 512 (0x200)
   address  boundary (which address 0x20000000 satisfies).

   Also note use of the "__no_init" attribute to force the
   relocated IVT into the ".noinit" section.  This prevents
   the CRTL startup sequence from initializing the relocated
   IVT after we have activated it during the reset vector.
   so that the CRTL does not clear it.
*/
#define RELOCATION_ADDRESS   (0x20000000)
#define RELOCATION_ALIGNMENT      (0x200)
#define SIZEOF_IVT sizeof(__vector_table)
#if defined ( __ICCARM__ )
   #pragma data_alignment=RELOCATION_ALIGNMENT  /* IAR */
#elif defined (__CC_ARM)
   __align(RELOCATION_ALIGNMENT)                /* Keil */
#else
   #pragma message("WARNING: NO ALIGHMENT DEFINED FOR IVT RELOCATION")
#endif
/* reserve no-init aligned IVT space at top of RAM */
SECTION_PLACE(KEEP_VAR(__no_init IntVector __relocated_vector_table[SIZEOF_IVT/4]), RELOCATION_ADDRESS);
#endif


#ifdef __ARMCC_VERSION
// We want a warning if semi-hosting libraries are used.
#pragma import(__use_no_semihosting_swi)
#endif
//*****************************************************************************
//
// Application Entry point
//
//*****************************************************************************
extern int main(void);


//*****************************************************************************
// Symbols defined by the GNU linker.
//*****************************************************************************
#ifdef __GNUC__
extern unsigned long _etext;
extern unsigned long _data;
extern unsigned long _edata;
extern unsigned long _bss ;
extern unsigned long _ebss;
#endif

//*****************************************************************************
// IAR system startup functions.
//*****************************************************************************
#ifdef __ICCARM__
WEAK_PROTO( void __iar_init_core (void));
WEAK_PROTO( void __iar_init_vfp  (void));
extern      void __cmain(void);
#endif


//*****************************************************************************
// Function    : ResetISR (-15)
// Description : Reset event handler
//*****************************************************************************

WEAK_FUNC (void ResetISR (void))
{

   /* reset the main SP to clean up any leftovers from the boot rom. */
   __set_MSP( (uint32_t) __vector_table[0].__ptr );

   /* Unlock the PWRMOD register by writing the two keys to the PWRKEY register */
   pADI_PMG0->PWRKEY = PWRKEY_VALUE_KEY;
   pADI_PMG0->SRAMRET &= (uint32_t)(~( BITM_PMG_SRAMRET_BNK2EN | BITM_PMG_SRAMRET_BNK1EN));
   /* set the RAM0_RET bit so the entire 8K of SRAM Bank0 is hibernate-preserved */

   adi_system_EnableRetention(ADI_SRAM_BANK_1,true);

   /* To disable the instruction SRAM and entire 64K of SRAM is used as DSRAM */
#ifdef  ADI_DISABLE_INSTRUCTION_SRAM
   adi_system_EnableISRAM(false);
#endif


   /* To enable the instruction cache  */
#ifdef  ENABLE_CACHE
   adi_system_EnableCache(true);
#endif

#ifdef RELOCATE_IVT
   int i;
   uint8_t *pSrc, *pDst;

   /* copy the IVT (avoid use of memcpy here so it does not become locked into flash) */
   for (i=0, pSrc=(uint8_t*)__vector_table, pDst=(uint8_t*)__relocated_vector_table; i<SIZEOF_IVT; i++)
      *pDst++ = *pSrc++;
#endif

#ifdef __GNUC__

   unsigned long *pulSrc, *pulDest;

   // Copy initialised data from flash into RAM
   pulSrc = &_etext;
   for(pulDest = &_data; pulDest < &_edata; )
   {
      *pulDest++ = *pulSrc++;
   }

   // Clear the bss segment
   for(pulDest = &_bss; pulDest < &_ebss; )
   {
      *pulDest++ = 0;
   }
   adi_default_setting();
   // Call application main directly.
   main();

#elif __ICCARM__


   // Call IAR system startup

   __iar_init_core();
   __iar_init_vfp();

   adi_default_setting();
   __cmain();

#else



   adi_default_setting();
   // Call application main directly.
   main();

#endif

   // Stick here if main returns
   while(1);
}

