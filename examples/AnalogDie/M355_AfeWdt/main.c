/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/



/*   
	 UART :230400-8-1
	 UART host(PC typically) sends ASCII character '1' to feed watchdog timer
	   or it will trigger reset(or Interrupt) after it expires specified
	   time, which is 16 seconds in this case
	 The Watchdog Window feature is enabled and set to 4 seconds by default
		- WDTLD - WDTMINLD (16s-12s = 4seconds)

	MACRO WDT_INTERRUPT_EN is used to decide whether trigger reset or
	Interrupt after WDT expire its time without feeding.
			
*/



#include "UrtLib.h"
#include "ClkLib.h"
#include "DioLib.h"
#include "AfeWdtLib.h"
#include "stdio.h"

/*
   when WDT_INTERRUPT_EN set to 1, WDT will generate inttrrupt instead of reset
   when WDT_INTERRUPT_EN set to 0, WDT will reset if it expire time without feed.
*/
#define WDT_INTERRUPT_EN   1

volatile char feedWDT = '0';  //this flag will be updated after recieving data from UART.
volatile uint32_t ucCOMIID0;
volatile uint32_t iNumBytesInFifo;
volatile uint16_t uiDebugWDT = 0;
volatile uint32_t u32AFEDieStaRdy = 0;         // Variable used to load AFEDIESTA
void ClockInit(void);
void UartInit(void);

void M355_GPIOInit(void)
{
   /*S2, S3 configuration*/
   DioCfgPin(pADI_GPIO1,PIN0,0);          //configure P1.0/1.1 as gpio
   DioIenPin(pADI_GPIO1,PIN0,1);          // enable P1.0/1.1 as input
   DioPulPin(pADI_GPIO1,PIN0,1);          // enable pull-up
   DioIntPolPin(pADI_GPIO1,PIN0,1);       // Set polarity of P1.0 interrupt to low-high transition

   DioIntPin(pADI_GPIO1,PIN0,INTA,1);          // Enable External interrupt A on P1.0

   NVIC_EnableIRQ(SYS_GPIO_INTA_IRQn);         // Enable GPIO_INTA interrupt source in NVIC
}


int main (void)
{
   AfeWdtGo(false);
   M355_GPIOInit();
   ClockInit();
   DioOenPin(pADI_GPIO0,PIN0 ,1);              // Configure P0.0 as an output - Header P2, Pin 15 of evaluation board
   DioDsPin(pADI_GPIO0,PIN0,1);                // Set P0.0 output drive strength to max value
   DioOenPin(pADI_GPIO0,PIN1 ,1);              // Configure P0.1 as an output - Header P2, Pin 14 of evaluation board
   DioDsPin(pADI_GPIO0,PIN1,1);                // Set P0.1 output drive strength to max value
   UartInit();
   printf("AFE WATCHDOG TIMER TEST\r\n");

   AfeWdtLd(0x800);                            // 16seconds (0x800) second timeout period
   delay_10us(1000);
  #if WDT_INTERRUPT_EN
   AfeWdtCfg(WDT_MODE_PERIODIC,
             ENUM_WDT_CTL_DIV256,
             WDT_IRQ_EN,
             WDT_CLKIN_DIV1);                  //32K/256=128Hz
   NVIC_EnableIRQ(AFE_Watchdog_IRQn);
   #else 
   AfeWdtCfg(WDT_MODE_PERIODIC,
             ENUM_WDT_CTL_DIV256,
             WDT_RESET_EN,
             WDT_CLKIN_DIV1);                  //128Hz  
   #endif
       
   AfeWdtWindowCfg(WDT_WINDOW_EN, 0x600);      // Enable Windowed watchdog mode, min period is WDTLD - WDTMINLD (16s-12s = 4seconds)
   AfeWdtPowerDown(AFEWDT_ALWAYS_ON);          // Afe watchdog keep runing while MCU in hibernate
   AfeWdtGo(true);                             // After this point, the Watchdog timer settings are locked - power cycle required to change

   printf("AFE watchdog started\r\n");
   uiDebugWDT = pADI_AFEWDT->WDTVALS;
   printf("WDTVALS:   %x \r\n",uiDebugWDT);
   uiDebugWDT = pADI_AFEWDT->WDTSTA;
   printf("WDTSTA:   %x \r\n",uiDebugWDT);
   uiDebugWDT = pADI_AFEWDT->WDTCON;
   printf("WDTCON:   %x \r\n",uiDebugWDT);
   while (1)
   {
      if(feedWDT=='1') //Host send '1' will feed watchdog timer
      {
         feedWDT = '0';
         AfeWdtKick();
         delay_10us(65000);
         printf("AFE watchdog refreshed\r\n");
         uiDebugWDT = pADI_AFEWDT->WDTVALS;
         printf("WDTVALS:   %x \r\n",uiDebugWDT);
         uiDebugWDT = pADI_AFEWDT->WDTSTA;
         printf("WDTSTA:   %x \r\n",uiDebugWDT);
         uiDebugWDT = pADI_AFEWDT->WDTCON;
         printf("WDTCON:   %x \r\n",uiDebugWDT);
      }
      delay_10us(5000);
   }
}

void ClockInit(void)
{
   DigClkSel(DIGCLK_SOURCE_HFOSC);
   ClkDivCfg(1,1);   //HCLK=PCLK=26MHz
}

void UartInit(void)
{
   DioCfgPin(pADI_GPIO0,PIN10|PIN11,1);               // Setup P0.10, P0.11 as UART pin
   pADI_UART0->COMLCR2 = 0x3;                  // Set PCLk oversampling rate 32. (PCLK to UART baudrate generator is /32)
   UrtCfg(pADI_UART0,B230400,
          (BITM_UART_COMLCR_WLS|3),0);         // Configure UART for 57600 baud rate
   UrtFifoCfg(pADI_UART0, RX_FIFO_1BYTE,      // Rx Trigger interrupt after 1 byte received
              BITM_UART_COMFCR_FIFOEN);
   // Clear the Rx/TX FIFOs
   UrtFifoClr(pADI_UART0, BITM_UART_COMFCR_RFCLR|BITM_UART_COMFCR_TFCLR);
   // Enable Rx, Tx and Rx buffer full Interrupts
   UrtIntCfg(pADI_UART0,BITM_UART_COMIEN_ERBFI|BITM_UART_COMIEN_ELSI);
   NVIC_EnableIRQ(UART_EVT_IRQn);
}

void AfeWdt_Int_Handler(void)
{
//   AfeWdtKick();
   printf("AFE watchdog Interrupt happen\r\n");
   pADI_AFEWDT->WDTCLRI |= 0x1;
}

void UART_Int_Handler(void)
{
   UrtLinSta(pADI_UART0);
   ucCOMIID0 = UrtIntSta(pADI_UART0);
   if ((ucCOMIID0 & 0xE) == 0x4)	          // Receive byte
   {
      iNumBytesInFifo = pADI_UART0->COMRFC;    // read the Num of bytes in FIFO
      for (uint8_t i=0; i<iNumBytesInFifo;i++)
      {
         feedWDT = UrtRx(pADI_UART0);
      }
   }
   if ((ucCOMIID0 & 0xE) == 0xC)	          // UART Time-out condition
   {
      iNumBytesInFifo = pADI_UART0->COMRFC;    // read the Num of bytes in FIFO
      for (uint8_t i=0; i<iNumBytesInFifo;i++)
      {
         feedWDT = UrtRx(pADI_UART0);
      }
   }
}
// Interrupt handler for P1.0 - S2 button
void GPIO_A_Int_Handler(void)
{
  unsigned int uiIntSta = 0;

   uiIntSta = DioIntSta(pADI_GPIO1);
   if ((uiIntSta & 0x0001) ==0x0001)
   {
      DioIntClrPin(pADI_GPIO1,PIN0);
      feedWDT = '1';
   }  
}


