/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

/* 
    Decription: 
	  - Sends SPI0 bytes to the Slave when External PB0 is asserted
      - Interfaces to Master device via SPI0
      - Expects to read 12 bytes
      - Will write 14 bytes
      - Assumes EVAL-ADuCM355QSPZ evaluation board

**/

#include <ADUCM355.h>
#include <DioLib.h>
#include <SpiLib.h>
#include <stdio.h>
#include <string.h>

// Function Definitions

void delay(long int);
void ClockInit(void);
void GPIOInit(void);
void SPISlaveSetup(void);

volatile unsigned char ucRdLength = 0;	          // Stores number of bytes to be read from Slave via SPI1
volatile unsigned char StartByteGone = 0;
unsigned int ucBytesToRD = 0;			  // Stores number of bytes to be read from Slave via SPI1
volatile uint32_t rxDat[16];	          // 16 byte buffer-array for SPI1 receive data
volatile uint8_t ucRxCount = 0;             // rxDat array control variable.
volatile uint8_t ucSpiCWrCnt = 0;            // SPI1 Tx counter
volatile uint8_t ucMsgType = 0;             // Indicates SPI read or write
volatile uint8_t ucReceiveInProgress = 0;
volatile unsigned char ucLoadCnt = 0;
volatile unsigned char ucTransfer[] =  
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
      DioTglPin(pADI_GPIO1,0x2000);               // Toggle LED5 - P1.13   
  
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
   SpiIenEn(pADI_SPI0,BITM_SPI_IEN_TXEMPTY|    // Interrupt when TX FIFO is empty
            BITM_SPI_IEN_CS|                   // Interrupt on CS edge to detect Transfer is done
            BITM_SPI_IEN_IRQMODE & 0x1);       // interrupt when 1x bytes received.transmitted
   SpiTx(pADI_SPI0,ucTransfer[0]);                // Init SPI1 Tx FIFO
   ucReceiveInProgress = 1;
   NVIC_EnableIRQ(SPI0_EVT_IRQn);              // Enable SPI0 interrupt source in NVIC
}
void GPIOInit(void)
{
   DioOenPin(pADI_GPIO0,PIN13,1);              // Configure P0.13 as an output - LED3 on the evaluation board
   DioDsPin(pADI_GPIO0,PIN13,1);               // Set P0.13 output drive strength to max value
   DioOenPin(pADI_GPIO1,0x3000,1);                  // Configure P1.12/P1.13 as an output - LED4 and LED5 on the evaluation board
   DioPulPin(pADI_GPIO0, 0xFFFF,1);                 // Enable internal pull-up resistors on P0[0:15]
   DioPulPin(pADI_GPIO1, 0xFFFF,1);                 // Enable internal pull-up resistors on P1[0:15]  
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
      pADI_SPI0->STAT |=BITM_SPI_STAT_RXIRQ;         // Clear the Rx interrupt
      if(ucRxCount == (ucBytesToRD))
      {
	ucReceiveInProgress = 0;
        ucRxCount	 = 0;
      }
   } 
     if((SPI0SSTATUS & BITM_SPI_STAT_TXEMPTY) == BITM_SPI_STAT_TXEMPTY) // Slave Tx Empty IRQ
   {
      SpiTx(pADI_SPI0,ucTransfer[ucSpiCWrCnt++]);     // send SPI0 byte 
      pADI_SPI0->STAT |=BITM_SPI_STAT_TXEMPTY;         // Clear the Tx underflow interrupt
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
                BITM_SPI_CTL_RFLUSH);	    // Flush Rx FIFO
      SpiFifoFlush(pADI_SPI0,0,0);
   }  
    if((SPI0SSTATUS & BITM_SPI_STAT_CSFALL) == BITM_SPI_STAT_CSFALL)   // Detect chip select falling edge				  
   {
     pADI_SPI0->STAT |=BITM_SPI_STAT_CSFALL;         // Clear the CS interrupt
   }
}



