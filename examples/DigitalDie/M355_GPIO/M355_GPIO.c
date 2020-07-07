/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

/*
   Decription:
		- Press Pushbutton PB0 on Eval board to send a string to the UART reflecting GPIO status
		- Default Baud rate is 230400-8-N-1
		- Pressing S2 button will send "Button S2 pressed"
		- Pressing S3 button will send "Button S3 pressed"
		- DS2 LED will flash each time either S2 or S3 button on evaluation board is pressed.
		- Chips unique ID number will also be printed.


**/
#include "ad5940.h"
#include "UrtLib.h"
#include "DioLib.h"
#include "ClkLib.h"
#include <stdio.h>
#include <string.h>

void ClockInit(void);
void GPIOInit(void);
void UartInit(void);
void TestButtonPress(unsigned int uiNum);      // Sends string to UART when IRQ0 asserted

volatile uint32_t ucButtonPress = 0;           // Flag set when S2 or S3 button is pressed.
volatile uint32_t u32AFEDieStaRdy = 0;         // Variable used to load AFEDIESTA

volatile uint32_t ucUniqueID = 0;              // Used to read off 16x byte unique ID number
volatile uint32_t *pSerialNum;                 // Pointer used to access location of unique Serial ID number

int main (void)
{
  int i = 0;
  
  AD5940_Initialize();
  ClockInit();                                // Init system clocks
  UartInit();                                 // Init UART for 230400-8-N-1
  GPIOInit();                                 // Init GPIO pins
   

   printf("Press button S2 or S3 to start test \r\n"); // Start message sent to UART
   while (1)
   {
      if(ucButtonPress>0)
      {
         printf("Button %ld pressed\r\n",ucButtonPress);
         ucButtonPress = 0;
         DioTglPin(pADI_GPIO2,PIN4);           // Flash LED
         pSerialNum = (volatile uint32_t *)0x40770; // Set pointer to location of unique Part ID number
         printf("Print Chips Unique ID number in Hex:\r\n");
         for (i=0;i<4;i++)                     // Print 16x bytes to UART
         {
           ucUniqueID = (*(pSerialNum));
           *pSerialNum++;
           printf("%lx",ucUniqueID);
         }
         printf("\r\n");
      }

   }
}


void GPIOInit(void)
{
   /*S2, S3 configuration*/
   DioCfgPin(pADI_GPIO1,PIN0|PIN1,0);          //configure P1.0/1.1 as gpio
   DioIenPin(pADI_GPIO1,PIN0|PIN1,1);          // enable P1.0/1.1 as input
   DioPulPin(pADI_GPIO1,PIN0|PIN1,1);          // enable pull-up
   DioIntPolPin(pADI_GPIO1,PIN0|PIN1,1);       // Set polarity of P1.0 interrupt to low-high transition
   
   DioOenPin(pADI_GPIO2,PIN4,1);               // Enable P2.4 as Output to toggle DS2 LED
   DioPulPin(pADI_GPIO2,PIN4,1);               // Enable pull-up

   DioIntPin(pADI_GPIO1,PIN0,INTA,1);          // Enable External interrupt A on P1.0
   DioIntPin(pADI_GPIO1,PIN1,INTB,1);          // Enable External interrupt B on P1.1

   NVIC_EnableIRQ(SYS_GPIO_INTA_IRQn);         // Enable GPIO_INTA interrupt source in NVIC
   NVIC_EnableIRQ(SYS_GPIO_INTB_IRQn);         // Enable GPIO_INTB interrupt source in NVIC
}

// Clock digital die with Internal 26MHz oscillator
void ClockInit(void)
{
   DigClkSel(DIGCLK_SOURCE_HFOSC);
   ClkDivCfg(1,1);
}

void UartInit(void)
{
   DioCfgPin(pADI_GPIO0,PIN10|PIN11,1);        // Setup P0.10, P0.11 as UART pin
   UrtCfg(pADI_UART0,B230400,
          (BITM_UART_COMLCR_WLS|3),0);         // Configure UART for 230400 baud rate
   UrtFifoCfg(pADI_UART0, RX_FIFO_1BYTE,       // Configure the UART FIFOs for 8 bytes deep
              BITM_UART_COMFCR_FIFOEN);
   UrtFifoClr(pADI_UART0, BITM_UART_COMFCR_RFCLR// Clear the Rx/TX FIFOs
              |BITM_UART_COMFCR_TFCLR);

   UrtIntCfg(pADI_UART0,BITM_UART_COMIEN_ERBFI|BITM_UART_COMIEN_ELSI);
}

// Interrupt handler for P1.0 - S2 button
void GPIO_A_Int_Handler()
{
   unsigned int uiIntSta = 0;

   uiIntSta = DioIntSta(pADI_GPIO1);
   if ((uiIntSta & 0x0001) ==0x0001)
   {
      DioIntClrPin(pADI_GPIO1,PIN0);
      ucButtonPress = 2;
   }
}
// Interrupt handler for P1.1 - S3 button
void GPIO_B_Int_Handler()
{
   unsigned int uiIntSta = 0;

   uiIntSta = DioIntSta(pADI_GPIO1);
   if ((uiIntSta & 0x0002) ==0x0002)
   {
      DioIntClrPin(pADI_GPIO1,PIN1);
      ucButtonPress = 3;
   }
}

