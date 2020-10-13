/*! *****************************************************************************
* \brief: Implements bootloader
* @version  V0.1
* @author   Analog Devices
* @date     October 2020

Copyright (c) 2020 Analog Devices, Inc.  All Rights Reserved.
This software is proprietary and confidential to Analog Devices, Inc. and its licensors

*****************************************************************************/
#include <stddef.h>     /* for 'NULL' */
#include <adi_types.h>
#include "AD5940.h"
#include "DioLib.h"
#include "UrtLib.h"
#include "ClkLib.h"
#include <stdio.h>

void ClockInit(void);
void GPIOInit(void);
void UartInit(void);
void TestButtonPress(unsigned int uiNum);      // Sends string to UART when IRQ0 asserted

volatile uint32_t ucButtonPress = 0;           // Flag set when S2 or S3 button is pressed.
extern void __vector_table;

/**
*  \brief Set the VTOR to point to the user firmware exception table.
*
*  \return None
*
*  \details The bootloader is already performing this step but IAR is bypassing 
*           running the bootloader when clicking reset in the IDE. It performs a type 0
*           reset and then sets the PC to what it thinks is the reset vector.
*  
*           Therefore for interrupts to work in the debugger, we need this.
*/
void __iar_init_core (void)
{
  SCB->VTOR = (uint32_t) &__vector_table;
}


/**
*  \brief Brief description
*
*  \return Return description
*
*  \details This is just a simple program that prints data to the 
*           Uart when the buttons on the EVAL-ADuCm355QSPZ are pressed. 
*/
int main (void)
{
  /* Initialize the AFE die */
  AD5940_Initialize();
  
  ClockInit();                                // Init system clocks
  UartInit();                                 // Init UART for 230400-8-N-1
  GPIOInit();                                 // Init GPIO pins
  
  printf("Press button S2 or S3 to start test\r\n"); // Start message sent to UART
  while (1)
  {
    if(ucButtonPress > 0)
    {
      printf("Button %d pressed\r\n", ucButtonPress);
      ucButtonPress = 0;
      DioTglPin(pADI_GPIO2, PIN4);          // Flash LED
    }
  }
}

void GPIOInit(void)
{
  /*S2, S3 configuration*/
  DioCfgPin(pADI_GPIO1, PIN0 | PIN1, 0);      //configure P1.0/1.1 as gpio
  DioIenPin(pADI_GPIO1, PIN0 | PIN1, 1);      // enable P1.0/1.1 as input
  DioPulPin(pADI_GPIO1, PIN0 | PIN1, 1);      // enable pull-up
  DioIntPolPin(pADI_GPIO1, PIN0 | PIN1, 1);   // Set polarity of P1.0 interrupt to low-high transition
  
  DioOenPin(pADI_GPIO2, PIN4, 1);             // Enable P2.4 as Output to toggle DS2 LED
  DioPulPin(pADI_GPIO2, PIN4, 1);             // Enable pull-up
  
  DioIntPin(pADI_GPIO1, PIN0, INTA, 1);       // Enable External interrupt A on P1.0
  DioIntPin(pADI_GPIO1, PIN1, INTB, 1);       // Enable External interrupt B on P1.1
  
  NVIC_EnableIRQ(SYS_GPIO_INTA_IRQn);         // Enable GPIO_INTA interrupt source in NVIC
  NVIC_EnableIRQ(SYS_GPIO_INTB_IRQn);         // Enable GPIO_INTB interrupt source in NVIC
}

// Clock digital die with Internal 26MHz oscillator
void ClockInit(void)
{
  DigClkSel(DIGCLK_SOURCE_HFOSC);
  ClkDivCfg(1, 1);
}

void UartInit(void)
{
  DioCfgPin(pADI_GPIO0, PIN10 | PIN11, 1);    // Setup P0.10, P0.11 as UART pin
  UrtCfg(pADI_UART0, B230400,
         (BITM_UART_COMLCR_WLS | 3), 0);      // Configure UART for 57600 baud rate
  UrtFifoCfg(pADI_UART0, RX_FIFO_1BYTE,       // Configure the UART FIFOs for 8 bytes deep
             BITM_UART_COMFCR_FIFOEN);
  UrtFifoClr(pADI_UART0, BITM_UART_COMFCR_RFCLR// Clear the Rx/TX FIFOs
             | BITM_UART_COMFCR_TFCLR);
  
  UrtIntCfg(pADI_UART0, BITM_UART_COMIEN_ERBFI | BITM_UART_COMIEN_ELSI);
}

// Interrupt handler for P1.0 - S2 button
void GPIO_A_Int_Handler()
{
  unsigned int uiIntSta = 0;
  
  uiIntSta = DioIntSta(pADI_GPIO1);
  if ((uiIntSta & 0x0001) == 0x0001)
  {
    DioIntClrPin(pADI_GPIO1, PIN0);
    ucButtonPress = 2;
  }
}
// Interrupt handler for P1.1 - S3 button
void GPIO_B_Int_Handler()
{
  unsigned int uiIntSta = 0;
  
  uiIntSta = DioIntSta(pADI_GPIO1);
  if ((uiIntSta & 0x0002) == 0x0002)
  {
    DioIntClrPin(pADI_GPIO1, PIN1);
    ucButtonPress = 3;
  }
}