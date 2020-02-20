/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

/*
     Decription: 
      - Interfaces to Master device via SPI0
      - Expects to read 12 bytes
      - Will write 14 bytes
      - Use with M355_SPI_MASTER.c project
      - Assumes EVAL-ADuCM355QSPZ  evaluation board

**/
#include <stdio.h>
#include <string.h>
#include "ad5940.h"
#include "DioLib.h"
#include "SpiLib.h"

// Function Definitions

void delay(long int);
void ClockInit(void);
void GPIOInit(void);
void SPISlaveSetup(void);

unsigned int ucBytesToRD = 0;		       // Stores number of bytes to be read from Slave via SPI1
volatile uint32_t rxDat[16];	               // 16 byte buffer-array for SPI0 receive data
volatile uint8_t ucRxCount = 0;                // rxDat array control variable.
volatile uint8_t ucSpiCWrCnt = 0;              // SPI1 Tx counter
volatile uint8_t ucReceiveInProgress = 0;      // Flag to indicate Receive in progress. Cleared when expected # of bytes received
volatile unsigned char ucTransfer[] =          // Array of bytes returned to master. When displayed in ASCII = Hello Master /r/n
{0x48,0x65,0x6c,0x6c,0x6f,0x20,
0x4d,0x61,0x73,0x74,0x65,0x72,
0xD,0xA};
int main (void)
{
   AD5940_Initialize();
   ClockInit();
   SPISlaveSetup();
   GPIOInit();
   ucBytesToRD = 12;
   while (1)
   {
      delay(800000);
      DioTglPin(pADI_GPIO2,0x10);               // Toggle LED5 - P2.4

   }

}

void ClockInit(void)
{
   pADI_CLKG0_OSC->KEY = 0xCB14;               // Select HFOSC as system clock.
   pADI_CLKG0_OSC->CTL =                       // Int 32khz LFOSC selected in LFMUX
      BITM_CLKG_OSC_CTL_HFOSCEN;

   pADI_CLKG0_CLK->CTL0 = 0;                   // PLCK,Flash reference clock,PLL=HFOSC
   pADI_CLKG0_CLK->CTL1 = 0;                   // ACLK,PCLK,HCLK divided by 1
   pADI_CLKG0_CLK->CTL5 = 0x00;                 // Enable clock to all peripherals - no clock gating
}

void SPISlaveSetup(void)
{
   DioCfgPin(pADI_GPIO0,PIN0,1);               // Setup P0.0 as SPI SCLK pin
   DioCfgPin(pADI_GPIO0,PIN1,1);               // Setup P0.1 as SPI MOSI pin
   DioCfgPin(pADI_GPIO0,PIN2,1);               // Setup P0.2 as SPI MISO pin
   DioCfgPin(pADI_GPIO0,PIN3,1);               // Setup P0.3 as SPI CS0 pin

   SpiCfg(pADI_SPI0,BITM_SPI_CTL_CSRST,        // Configure SPI to reset after a bit shift error is detected
          0,                                    // Enable Slave mode
          BITM_SPI_CTL_CON|                     // Enable continous transfer mode
             BITM_SPI_CTL_OEN|                     // Select MISO pin to operate as normal -
                BITM_SPI_CTL_RXOF|                    // overwrite data in Rx FIFO during overflow states
                   BITM_SPI_CTL_ZEN|                     // transmit 00 when no valid data in Tx FIFO
                      BITM_SPI_CTL_SPIEN);                  // Enable SPI. SCLK idles low/ data clocked on SCLK falling edge
   SpiIenEn(pADI_SPI0,BITM_SPI_STAT_TXUNDR|    // Interrupt when TX FIFO underflow
            BITM_SPI_IEN_CS|                   // Interrupt on CS edge to detect Transfer is done
               (BITM_SPI_IEN_IRQMODE & 0x1));       // interrupt when 2x bytes received.transmitted
   SpiTx(pADI_SPI0,ucTransfer[0]);                // Init SPI1 Tx FIFO
   ucReceiveInProgress = 1;
   NVIC_EnableIRQ(SPI0_EVT_IRQn);              // Enable SPI0 interrupt source in NVIC
}
void GPIOInit(void)
{
   DioOenPin(pADI_GPIO2,PIN4,1);               // Configure P2.4 as an output - DS2 on the evaluation board
   DioDsPin(pADI_GPIO2,PIN4,1);                // Set P2.4 output drive strength to max value
   DioPulPin(pADI_GPIO2, 0x10,1);              // Enable internal pull-up resistor on P2.4

}

// Simple Delay routine
void delay (long int length)
{
	while (length >0)
    	length--;
}
void SPI0_Int_Handler()
{
   uint32_t SPI0SSTATUS = 0;

   SPI0SSTATUS = SpiSta(pADI_SPI0);
 	// Receive
   if((SPI0SSTATUS & BITM_SPI_STAT_RXIRQ) == BITM_SPI_STAT_RXIRQ) // Slave Recieve IRQ
   {
      rxDat[ucRxCount++] = SpiRx(pADI_SPI0);         // read SPI0 FIFO
      rxDat[ucRxCount++] = SpiRx(pADI_SPI0);         // read SPI0 FIFO
      pADI_SPI0->STAT |=BITM_SPI_STAT_RXIRQ;         // Clear the Rx interrupt
      SpiTx(pADI_SPI0,ucTransfer[ucSpiCWrCnt++]);     // send SPI0 byte
      SpiTx(pADI_SPI0,ucTransfer[ucSpiCWrCnt++]);     // send SPI0 byte
      if(ucRxCount == (ucBytesToRD))
      {
         ucReceiveInProgress = 0;
         ucRxCount	 = 0;
      }
   }
   if((SPI0SSTATUS & BITM_SPI_STAT_TXUNDR) == BITM_SPI_STAT_TXUNDR) // Slave Tx FIFO underflow IRQ
   {
      SpiTx(pADI_SPI0,ucTransfer[ucSpiCWrCnt++]);     // send SPI0 byte
      pADI_SPI0->STAT |=BITM_SPI_STAT_TXUNDR;         // Clear the Tx underflow interrupt
      if(ucSpiCWrCnt == 14)
      {
         ucReceiveInProgress = 0;
         ucSpiCWrCnt = 0;
      }
   }
   if((SPI0SSTATUS & BITM_SPI_STAT_CSRISE) == BITM_SPI_STAT_CSRISE)   // Detect chip select rising edge
   {
      ucRxCount = 0;
      ucSpiCWrCnt = 0;
      pADI_SPI0->STAT |=BITM_SPI_STAT_CSRISE;         // Clear the Transfer done interrupt
      SpiFifoFlush(pADI_SPI0,0,
                   BITM_SPI_CTL_RFLUSH);	              // Flush Rx FIFO
      SpiFifoFlush(pADI_SPI0,0,0);
   }
   if((SPI0SSTATUS & BITM_SPI_STAT_CSFALL) == BITM_SPI_STAT_CSFALL)   // Detect chip select falling edge
   {
      pADI_SPI0->STAT |=BITM_SPI_STAT_CSFALL;          // Clear the CS interrupt
   }
}



