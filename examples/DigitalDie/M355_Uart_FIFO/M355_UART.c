/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

/*
     Decription:
           Press Pushbutton S2 on Eval board to send a string to the UART
           Received string stored to array szInSring[]
           Default Baud rate is 57600-8-N-1
           Demonstrates use of Rx FIFO and associated interrupt handler


**/
#include <stdio.h>
#include <string.h>
#include "ad5940.h"
#include "UrtLib.h"
#include "DioLib.h"
#include "IntLib.h"

void delay(long int);
void ClockInit(void);
void UartInit(void);
void TestButtonPress(unsigned int uiNum);      // Sends string to UART when IRQ0 asserted
void WakeupIntInit(void);

volatile unsigned char ucCOMSTA0 = 0;          // Variable used to store COMSTA0, UART status register
volatile unsigned char ucCOMIID0 = 0;          // Variable used to store COMIID0, UART Interrupt status register
volatile unsigned char ucComRx = 0;            // Variable used to read UART Rx buffer contents into
unsigned char ucTxBufferEmpty  = 0;	       // Used to indicate that the UART Tx buffer is empty
unsigned char szTemp[64] = "";		       // Used to build string before printing to UART
unsigned char szInSring[64] = "";	       // Used to acquire incoming string from the UART
volatile unsigned char szbuffer[16];           // Debug buffer to test Rx FIFO
unsigned char ucButtonPress = 0;               // used to detect IRQ0 interrupt
unsigned int uiPressNum = 0;                   // Count number of PB0 button presses
unsigned char ucPacketReceived = 0;            // Flag to indicate UART byte received
unsigned char ucInCnt = 0;                     // Used to count incoming bytes over the UART
unsigned char ucNumRxIrqs = 0;                 // test variable to count number of Rx interrupts
unsigned char ucNumToIrqs = 0;                 // test variable to count number of Time-out interrupts
int iNumBytesInFifo = 0;                       // Used to determine the number of bytes in the UART FIFO
int main (void)
{
   AD5940_Initialize();
   ClockInit();
   UartInit();
   WakeupIntInit();
   while (1)
   {
      delay(100000);
      if (ucButtonPress == 1)
      {
         uiPressNum++;
         TestButtonPress(uiPressNum);
         ucButtonPress = 0;
      }
      if (ucPacketReceived ==1)
      {
         ucPacketReceived = 0;
      }
   }

}

void WakeupIntInit()
{
   DioPulPin(pADI_GPIO1,PIN0,1);
   DioIenPin(pADI_GPIO1,PIN0,1);
   EiCfg(EXTINT1,INT_EN,INT_RISE);
   NVIC_EnableIRQ(XINT_EVT1_IRQn);
}

void ClockInit(void)
{
   pADI_CLKG0_OSC->KEY = 0xCB14;               // Select HFOSC as system clock.
   pADI_CLKG0_OSC->CTL =                       // Int 32khz LFOSC selected in LFMUX
      BITM_CLKG_OSC_CTL_HFOSCEN;

   pADI_CLKG0_CLK->CTL0 = 0;                   // PLCK,Flash reference clock,PLL=HFOSC
   pADI_CLKG0_CLK->CTL1 = 0;                   // ACLK,PCLK,HCLK divided by 1
   //  pADI_CLKG0_CLK->CTL3 = ??                // Setup SPLL
   pADI_CLKG0_CLK->CTL5 = 0x00;                 // Enable clock to all peripherals - no clock gating
}

void UartInit(void)
{
   pADI_GPIO0->CFG |= 0x500000;                // Setup P0[11:10] as UART pins
   pADI_UART0->COMLCR2 = 0x3;                  // Set PCLk oversampling rate 32. (PCLK to UART baudrate generator is /32)
   UrtCfg(pADI_UART0,B57600,
          (BITM_UART_COMLCR_WLS|3),0);         // Configure UART for 115200 baud rate
   UrtFifoCfg(pADI_UART0, RX_FIFO_14BYTE,      // Configure the UART FIFOs for 14 bytes deep
              BITM_UART_COMFCR_FIFOEN);
   UrtFifoClr(pADI_UART0, BITM_UART_COMFCR_RFCLR// Clear the Rx/TX FIFOs
              |BITM_UART_COMFCR_TFCLR);
   //pADI_UART0->COMFCR |=0x2; // test to clear the RX FIFO
   UrtIntCfg(pADI_UART0,BITM_UART_COMIEN_ERBFI |
             BITM_UART_COMIEN_ETBEI |
                BITM_UART_COMIEN_ELSI);                  // Enable Rx, Tx and Rx buffer full Interrupts

   NVIC_EnableIRQ(UART_EVT_IRQn);              // Enable UART interrupt source in NVIC
}
void TestButtonPress(unsigned int uiNum)
{
   unsigned char i = 0;
   unsigned char nLen = 0;
   sprintf ( (char*)szTemp, "Button Pressed, %d \r\n",uiNum );// Scan string
   nLen = strlen((char*)szTemp);                  // Call function to calcualte the length of scanned string
   if (nLen <64)
   {
      for ( i = 0 ; i < nLen ; i++ )	          // loop to send String to UART
      {
         ucTxBufferEmpty = 0;	                  // Clear flag
         UrtTx(pADI_UART0,szTemp[i]);             // Load UART Tx register.
         while (ucTxBufferEmpty == 0)            // Wait for UART Tx interrupt
         {
         }
      }
   }
}
// Simple Delay routine
void delay (long int length)
{
	while (length >0)
    	length--;
}
void UART_Int_Handler()
{
   int i = 0;

   ucCOMSTA0 = UrtLinSta(pADI_UART0);
   ucCOMIID0 = UrtIntSta(pADI_UART0);
   //  ucCOMIID0 = pADI_UART0->COMIIR;
   if ((ucCOMIID0 & 0xE) == 0x2)	          // Transmit buffer empty
   {
      ucTxBufferEmpty = 1;
   }
   if ((ucCOMIID0 & 0xE) == 0x4)	          // Receive byte
   {
      ucNumRxIrqs++;
      iNumBytesInFifo = pADI_UART0->COMRFC;    // read the Num of bytes in FIFO
      for (i=0; i<iNumBytesInFifo;i++)
      {
         ucComRx = UrtRx(pADI_UART0);
         szInSring[ucInCnt++]= ucComRx;
      }
      if (ucInCnt >= 64)
      {
         ucInCnt = 0;
         ucPacketReceived = 1;
      }
   }
   if ((ucCOMIID0 & 0xE) == 0xC)	          // UART Time-out condition
   {
      ucNumToIrqs++;
      iNumBytesInFifo = pADI_UART0->COMRFC;    // read the Num of bytes in FIFO
      for (i=0; i<iNumBytesInFifo;i++)
      {
         ucComRx = UrtRx(pADI_UART0);
         szInSring[ucInCnt++]= ucComRx;
      }
      if (ucInCnt >= 64)
      {
         ucInCnt = 0;
         ucPacketReceived = 1;
      }
   }
   //test_String_For_Uart_FIFO_2Test_String_For_Uart_FIFO

}
void Ext_Int1_Handler()
{
   EiClr(BITM_XINT_CLR_IRQ1);
   ucButtonPress = 1;

}

