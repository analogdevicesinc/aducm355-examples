/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

/*
     Decription: Control the LEDs on the EVAL-ADUCM355QSPZ board
           By varying the time-out period of Timer 0, 1 and 2

         UART Baudrate - 57600

         Timer 0 - Time out period about 645ms. Any time pressing S2 on Eval board
                  will be captured. UART will send the captured value and count over times

         Timer 1 -  Time out period is 244ms, when time out, AFEDIE_GPIO0 will toggle,
                  Pin 17 of P2 on EVAL board

         Timer 2 - Time out period is 1 second, when time out, AFEDIE_GPIO1 will toggle,
                  Pin 18 of P2 on EVAL board

**/
#include "ad5940.h"
#include "DioLib.h"
#include "UrtLib.h"
#include "GptLib.h"
#include "ClkLib.h"
#include <stdio.h>
#include <string.h>
void delay(long int);
void ClockInit(void);
void GPIOInit(void);
void GptInit(void);
void ExtIntInit(void);                         // enable External interrupt on Eval Board - S2 button

unsigned char ucButtonPress = 0;               // used to detect IRQ0 interrupt
volatile unsigned short usCaptureGPIOA_Int = 0;// Variable to capture T0 time of pushing button PB3
volatile unsigned int   T0OverCnt = 0;
void UartInit(void);

int main (void)
{
   AD5940_Initialize();
   ClockInit();
   GPIOInit();
   UartInit();
   ExtIntInit();                               // Enable Pushbutton interrupt - S2 on Eval board
   GptInit();

   while (1)
   {
      if(ucButtonPress)
      {
         ucButtonPress = 0 ;
         printf("Button press evetn capture time: %d\r\n",usCaptureGPIOA_Int);
         printf("Timer0 over cnt: %d\r\n",T0OverCnt);
      }
   }

}
// Enable External interrupt for Button S2 
void ExtIntInit(void)
{
   pADI_GPIO1->OEN &= 0xFFFE;			           //Disable P1.0 output.
   pADI_GPIO1->IEN |= 0x0001; 			        //Enable input path for P1.0 input.
   pADI_XINT0->CFG0 |= 0x80;		              //External IRQ1 enabled.
   NVIC_EnableIRQ(XINT_EVT1_IRQn);		        //Enable External Interrupt 1 source.
}
void ClockInit(void)
{
   ClkDivCfg(1,1);   //PCLK = HCLK = 26MHz
}


void GPIOInit(void)
{
   /*S2 configuration*/
   DioCfgPin(pADI_GPIO1,PIN0,0); //confige as gpio
   DioIenPin(pADI_GPIO1,PIN0,1); //enable input
   DioPulPin(pADI_GPIO1,PIN0,1);
   DioIntPin(pADI_GPIO1,PIN0,INTA,1);         // Enable External interrupt A on P1.0
   DioIntPolPin(pADI_GPIO1,PIN0,1);           // Set polarity of P1.0 interrupt to low-high transition

   /*AFEDIE GPIO0&1*/
   AfeDioCfgPin(pADI_AGPIO2,PIN0,2);   //set as GPIO
   AfeDioOenPin(pADI_AGPIO2,PIN0,1);
   AfeDioCfgPin(pADI_AGPIO2,PIN1,0);   //set as GPIO
   AfeDioOenPin(pADI_AGPIO2,PIN1,1);
   AfeDioSetPin(pADI_AGPIO2,PIN0|PIN1);   //set high

   NVIC_EnableIRQ(SYS_GPIO_INTA_IRQn);         // Enable GPIO_INTA interrupt source in NVIC
}

void GptInit(void)
{
   /* Configure Timer 0 */
   GptLd(pADI_TMR0,0xFFFF);                    // Load timer 0 - 645mS period 26000000/256/65536
   GptCfg(pADI_TMR0,TCTL_CLK_PCLK,
          TCTL_PRE_DIV256,0|BITM_TMR_CTL_EN|
             BITM_TMR_CTL_EVTEN);                      // Enable Timer0 for free running mode using PCLK as clock source
   GptCapSrc(pADI_TMR0,9);                     // Capture GPIO_INTA
   NVIC_EnableIRQ(TMR0_EVT_IRQn);              // Enable Timer 0  interrupt source in NVIC

   /* Configure Timer 1 */
   GptLd(pADI_TMR1,0xA000);                    // Load timer 1- 244mS period
   GptCfg(pADI_TMR1,TCTL_CLK_HFOSC,
          TCTL_PRE_DIV256,BITM_TMR_CTL_MODE|
             BITM_TMR_CTL_RLD|
                BITM_TMR_CTL_UP|
                   BITM_TMR_CTL_EN|
                      BITM_TMR_CTL_EVTEN);                      // Enable Timer1 for periodic mode, counting up, using HFOSC as clock source div64
   //GptCapSrc(pADI_TMR1,14);                    // Capture Timer 1
   NVIC_EnableIRQ(TMR1_EVT_IRQn);              // Enable Timer 1  interrupt source in NVIC

   /* Configure Timer 2 */
   GptLd(pADI_TMR2,0X800);                     // Load timer 2 - 1-second period
   GptCfg(pADI_TMR2,TCTL_CLK_LFOSC,
          TCTL_PRE_DIV16,BITM_TMR_CTL_MODE|
             BITM_TMR_CTL_RLD|
                BITM_TMR_CTL_EN);                         // Enable Timer2 for periodic mode, counting down, using LFOSC as clock source effectively div4
   NVIC_EnableIRQ(TMR2_EVT_IRQn);              // Enable Timer 2  interrupt source in NVIC
}

void UartInit(void)
{
   DioCfgPin(pADI_GPIO0,PIN10,1);               // Setup P0.10 as UART pin
   DioCfgPin(pADI_GPIO0,PIN11,1);               // Setup P0.11 as UART pin
   UrtCfg(pADI_UART0,B57600,
          (BITM_UART_COMLCR_WLS|3),0);         // Configure UART for 57600 baud rate
   UrtFifoCfg(pADI_UART0, RX_FIFO_1BYTE,      // Configure the UART FIFOs for 8 bytes deep
              BITM_UART_COMFCR_FIFOEN);
   UrtFifoClr(pADI_UART0, BITM_UART_COMFCR_RFCLR// Clear the Rx/TX FIFOs
              |BITM_UART_COMFCR_TFCLR);

   UrtIntCfg(pADI_UART0,BITM_UART_COMIEN_ERBFI|BITM_UART_COMIEN_ELSI);
//   NVIC_EnableIRQ(UART_EVT_IRQn);              // Enable UART interrupt source in NVIC
}
// Pushbutton Interrupt handler - S2 on LGA Evaluation board
void Ext_Int1_Handler()
{
     delay(1000);
     pADI_XINT0->CLR = 0x2;                      // Clear the IRQ flag
     DioSetPin(pADI_GPIO0,PIN12);                  // Set P0.12 - turn LED On
     ucButtonPress = 1;
}

void GP_Tmr0_Int_Handler()
{
   volatile int uiT0STA = 0;

   uiT0STA = GptSta(pADI_TMR0);
   if ((uiT0STA&0x2)==0x2) //Capture event pending
   {

      GptClrInt(pADI_TMR0,
                BITM_TMR_CLRINT_EVTCAPT);       // Clear Event capture interrupt
      usCaptureGPIOA_Int= GptCapRd(pADI_TMR0);   // read Capture event value
   }
   if((uiT0STA&0x0001)==0x0001)  //timeout event pending
   {
      GptClrInt(pADI_TMR0,BITM_TMR_CLRINT_TIMEOUT);// Clear Timer 0 timeout interrupt
      T0OverCnt++;
   }

}

void GP_Tmr1_Int_Handler()
{
   volatile int uiT1STA = 0;

   uiT1STA = GptSta(pADI_TMR1);
   if ((uiT1STA&0x2)==0x2)
   {
      GptClrInt(pADI_TMR1,
                BITM_TMR_CLRINT_EVTCAPT);       // Clear Event capture interrupt
   }
   if((uiT1STA&0x0001)==0x0001)  //timeout event pending
   {
      GptClrInt(pADI_TMR1,BITM_TMR_CLRINT_TIMEOUT);// Clear Timer 1 timeout interrupt
      AfeDioTglPin(pADI_AGPIO2, 1);                 // Toggle  AGPIO0
   }
}

void GP_Tmr2_Int_Handler()
{
   volatile int uiT2STA = 0;

   uiT2STA = GptSta(pADI_TMR2);
   if ((uiT2STA&0x2)==0x2)
   {
      GptClrInt(pADI_TMR2,
                BITM_TMR_CLRINT_EVTCAPT);       // Clear Event capture interrupt
   }
   if((uiT2STA&0x0001)==0x0001)  //timeout event pending
   {
      GptClrInt(pADI_TMR2,BITM_TMR_CLRINT_TIMEOUT);// Clear Timer 2 timeout interrupt
      AfeDioTglPin(pADI_AGPIO2, 2);                 // Toggle  AGPIO1
   }
}

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
// Simple Delay routine
void delay (long int length)
{
	while (length >0)
    	length--;
}




