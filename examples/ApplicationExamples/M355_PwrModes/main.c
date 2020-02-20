/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#include <stdio.h>
#include "ad5940.h"
#include "IntLib.h"
#include "UrtLib.h"
#include "ClkLib.h"
#include "DioLib.h"
#include <system_ADuCM355.h>
void UartInit(void);
void ClockInit(void);           /* Initialize clocks on chip */
void GPIOInit(void);            /* Init debug GPIOs - optional */
void InitWakeupTimer(void);     /* Uncomment to use Wake-up timer  */
void ExtIntInit(void);          /* Init external interrupt on P1.1 - used to trigger entering Hibernate mode */


extern uint8_t ucButtonPress_S2;
extern uint8_t ucButtonPress_S3;

int main(void)
{
  void AD5940_Main(void);
  ClockInit();
  UartInit();
  AD5940_MCUResourceInit(0);    /* Inialize all peripherals etc. used for AFE. */
  ExtIntInit();                 /*Enable External interrupt - S2 button Eval board */
  AD5940_Main(); 
}

/* Initialize Digital die clocks */
void ClockInit(void)
{
  DigClkSel(DIGCLK_SOURCE_HFOSC);
  ClkDivCfg(1,1);   //HCLK = PCLK = 26MHz
}
void ExtIntInit(void)
{
  DioCfgPin(pADI_GPIO1,PIN0|PIN1,0);          //configure P1.0/1.1 as gpio
  DioIenPin(pADI_GPIO1,PIN0|PIN1,1);          // enable P1.0/1.1 as input
  DioPulPin(pADI_GPIO1,PIN0|PIN1,1);          // enable pull-up
  
  EiCfg(EXTINT1,INT_EN,INT_FALL);              // External IRQ1 enabled.
  NVIC_EnableIRQ(XINT_EVT1_IRQn);		         // Enable External Interrupt 1 source.
  
  DioIntPin(pADI_GPIO1,PIN1,INTB,1);          // Enable External interrupt B on P1.1
  NVIC_EnableIRQ(SYS_GPIO_INTB_IRQn);         // Enable GPIO_INTB interrupt source in NVIC
}
// Initialize UART for 230400-8-N-1
void UartInit(void)
{
  DioCfgPin(pADI_GPIO0,PIN10|PIN11,1);               // Setup P0.10, P0.11 as UART pin
  UrtCfg(pADI_UART0,B230400,
         (BITM_UART_COMLCR_WLS|3),0);         // Configure UART for 57600 baud rate
  UrtFifoCfg(pADI_UART0, RX_FIFO_1BYTE,      // Configure the UART FIFOs for 8 bytes deep
             BITM_UART_COMFCR_FIFOEN);
  UrtFifoClr(pADI_UART0, BITM_UART_COMFCR_RFCLR// Clear the Rx/TX FIFOs
             |BITM_UART_COMFCR_TFCLR);
}

void Ext_Int1_Handler(void)
{
  EiClr(BITM_XINT_CLR_IRQ1);  // Clear the IRQ flag
  ucButtonPress_S2 = 1;
}

// Interrupt handler for P1.1 - S3 button
void GPIO_B_Int_Handler(void)
{
  unsigned int uiIntSta = 0;
  uiIntSta = DioIntSta(pADI_GPIO1);
  if ((uiIntSta & 0x0002) ==0x0002)
  {
    DioIntClrPin(pADI_GPIO1,PIN1);
    ucButtonPress_S3 = 1;
  }
}

