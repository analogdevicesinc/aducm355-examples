/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/
#include <stdio.h>
#include "ad5940.h"
#include "ADuCM355.h"
#include "ClkLib.h"
#include "UrtLib.h"
#include "DioLib.h"



void UartInit(void);
void ClockInit(void);

int main(void)
{
  void AD5940_Main(void);
  ClockInit();
  UartInit();
  AD5940_MCUResourceInit(0);    /* Inialize all peripherals etc. used for AD5940/AFE. */
  AD5940_Main();
}

void ClockInit(void)
{
   DigClkSel(DIGCLK_SOURCE_HFOSC);
   ClkDivCfg(1,1);   //HCLK = PCLK = 26MHz
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

