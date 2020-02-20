/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

/*
   -- UART baudrate - 57600
   -- Digital die CRC module test - this example compares the hardware CRC result
      with software generated CRC result. if they match then the test passes and sends
      message to  UART
   -- Test will run once. Press Reset to Run test again.
    
**/

#include "UrtLib.h"
#include "CrcLib.h"
#include "DioLib.h"
#include "stdio.h"
#include "string.h"

#ifndef M355_PRINT
   #if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__)
      #define STRING_BUFFER_LENGTH  200   //200 character
      char szTemp[STRING_BUFFER_LENGTH];
      static uint32_t UartPrint(void);
      #define M355_PRINT(s) sprintf((char*)szTemp,s);UartPrint()
   #endif
#endif      //M355_PRINT(s)

void ClockInit(void);
void UartInit(void);
uint32_t Crc0Test(void);

uint32_t uiPassorFail = 0;

int main()
{
   pADI_AFEWDT->WDTCON &=(~BITM_AFEWDT_WDTCON_EN); //Turn off WDT on AFE Die
   uiPassorFail = 0;
   
   ClockInit();                                // Initialize System clocks
   UartInit();                                 // Initialize UARt for 57600-8-N-1

   M355_PRINT("START CRC TEST\r\n");           // Print this string to the UART
   uiPassorFail = Crc0Test();                  // Call function to test HW an SW CRC check
   if ((uiPassorFail & 0x1) == 1)              // HW and SW CRC's match?
   {
      M355_PRINT("CRC0 TEST SUCCESS\r\n");
   }
   else
   {
       M355_PRINT("CRC0 TEST FAILED\r\n"); 
   }   
   while(1)
   {

   }
}

void ClockInit(void)
{
   pADI_CLKG0_OSC->KEY = 0xCB14;               // Select HFOSC as system clock.
   pADI_CLKG0_OSC->CTL =                       // Int 32khz LFOSC selected in LFMUX
      BITM_CLKG_OSC_CTL_HFOSCEN;
   pADI_CLKG0_CLK->CTL0 = 0;                   // PLCK,Flash reference clock,PLL=HFOSC
   pADI_CLKG0_CLK->CTL1 = 0;                   // ACLK,PCLK,HCLK divided by 1
   pADI_CLKG0_CLK->CTL5 = 0x00;                // Enable clock to all peripherals - no clock gating
}

void UartInit(void)
{
   DioCfgPin(pADI_GPIO0,PIN10|PIN11,1);        // Setup P0.10, P0.11 as UART pin
   UrtCfg(pADI_UART0,B57600,
          (BITM_UART_COMLCR_WLS|3),0);         // Configure UART for 57600 baud rate
   UrtFifoCfg(pADI_UART0, RX_FIFO_1BYTE,       // Configure the UART FIFOs for 8 bytes deep
              BITM_UART_COMFCR_FIFOEN);
   UrtFifoClr(pADI_UART0, BITM_UART_COMFCR_RFCLR// Clear the Rx/TX FIFOs
              |BITM_UART_COMFCR_TFCLR);
}

/**
   @brief uint32_t Crc0Test()
          Compare result of CRC0 module and software generated
   @return 1 if result match.
*/
uint32_t Crc0Test()
{
   uint32_t hardwareCrC, softwareCrc;
   
   CrcSetSeed(123);                            // Write seed value to result register
   CrcCfg(CRC_CTL_NOSWAP,                      // Configure CRC HW accelerator, no swapping
          CRC_CTL_MSBFIRST,                    // MSB of data word first into CRC engine
          ADI_TEST_CRC_POLYNOMIAL,             // See #define for polynomial type
          ENABLE);                             // Turn on CRC peripheral

   hardwareCrC = CrcGen(0x12345678);           // Load test data into IPDATA            
   softwareCrc = SoftwareCrc(0x12345678,       // Perform software CRC using same polynomial as HW used
                             ADI_TEST_CRC_POLYNOMIAL,
                             123);

   if (softwareCrc==hardwareCrC)               // Compare HW and SW results
      return 1;
   else
     return 0;
}


#if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__)
/**
   @brief uint32_t UartPrint(const char * restrict format, ... )
          send string s through UART interface
   @param s :
   @return 1.
*/
uint32_t UartPrint()
{
   uint32_t sLength;
   sLength = strlen(szTemp);
   if(sLength<STRING_BUFFER_LENGTH)
   {
      for(uint32_t ix=0;ix<sLength;ix++)
      {
         UrtTx(pADI_UART0,szTemp[ix]);
         while(!(UrtLinSta(pADI_UART0)&BITM_UART_COMLSR_TEMT)); //wait for tx finish
      }
      return 1;
   }
   else
   {
      return 0;
   }
}
#endif





