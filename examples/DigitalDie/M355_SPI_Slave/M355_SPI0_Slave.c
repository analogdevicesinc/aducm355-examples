/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

/*
Decription: 
- Interfaces to Master device via SPI0
- Expects to read 14 bytes
- Will write 14 bytes
- Use with M355_SPI_MASTER.c project
- Assumes EVAL-ADuCM355QSPZ  evaluation board

**/
#include <stdio.h>
#include <string.h>
#include "ad5940.h"
#include "DioLib.h"
#include "SpiLib.h"
#include "UrtLib.h"

// Function Definitions
void delay(long int);
void ClockInit(void);
void GPIOInit(void);
void SPISlaveSetup(void);
void UartInit(void);

volatile uint8_t ucDataReady = 0;
volatile uint8_t rxDat[14];	               // 16 byte buffer-array for SPI0 receive data
volatile uint8_t ucRxCount = 0;                // rxDat array control variable.
volatile uint8_t ucSpiCWrCnt = 0;              // SPI1 Tx counter
volatile uint8_t ucReceiveInProgress = 0;      // Flag to indicate Receive in progress. Cleared when expected # of bytes received
volatile unsigned char ucTransfer[] =          // Array of bytes returned to master. When displayed in ASCII = Hello Master /r/n
{0x48,0x65,0x6c,0x6c,0x6f,0x20,
0x4d,0x61,0x73,0x74,0x65,0x72,
0xD,0xA};

uint8_t ucCOMSTA0 = 0;                         // Variable used to store COMSTA0, UART status register
uint8_t ucCOMIID0 = 0;                         // Variable used to store COMIID0, UART Interrupt status register
uint8_t ucTxBufferEmpty  = 0;	               // Used to indicate that the UART Tx buffer is empty
uint8_t szTemp[64] = "";		       // Used to build string before printing to UART

int main (void)
{
  uint8_t n = 0;
  AD5940_Initialize();                        // Initialize AFE die
  ClockInit();
  SPISlaveSetup();
  GPIOInit();
  UartInit();                                 // Setup the UART for 230400-8-N
  
  while (1)
  {
    if(ucDataReady)
    {
      ucDataReady = 0;
      ucTxBufferEmpty = 0;                       // Start forwarding packet UART
      pADI_UART0->COMTX = rxDat[0];
      for (n = 1; n < 14 ; n++)                  // Send received packet to the PC via UART
      {
        while (ucTxBufferEmpty != 1){}
        ucTxBufferEmpty = 0;
        pADI_UART0->COMTX = rxDat[n];
      }
    }
  }
}

/* Initialize system clocks on digital die */
void ClockInit(void)
{
  pADI_CLKG0_OSC->KEY = 0xCB14;               // Select HFOSC as system clock.
  pADI_CLKG0_OSC->CTL =                       // Int 32khz LFOSC selected in LFMUX
       BITM_CLKG_OSC_CTL_HFOSCEN;
  
  pADI_CLKG0_CLK->CTL0 = 0;                   // PLCK,Flash reference clock,PLL=HFOSC
  pADI_CLKG0_CLK->CTL1 = 0;                   // ACLK,PCLK,HCLK divided by 1
  pADI_CLKG0_CLK->CTL5 = 0x00;                 // Enable clock to all peripherals - no clock gating
}

/* Initialize SPI0 in slave mode */
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
  SpiIenEn(pADI_SPI0, BITM_SPI_IEN_CS|                   // Interrupt on CS edge to detect Transfer is done
           (BITM_SPI_IEN_IRQMODE & 0x0));       // interrupt when 2x bytes received.transmitted
  SpiTx(pADI_SPI0,ucTransfer[0]);                // Init SPI1 Tx FIFO  
  SpiTx(pADI_SPI0,ucTransfer[1]);                // Init SPI1 Tx FIFO
  ucSpiCWrCnt=2;
  NVIC_EnableIRQ(SPI0_EVT_IRQn);              // Enable SPI0 interrupt source in NVIC
}

/* Initialize P2.4 to toggle LED */
void GPIOInit(void)
{
  DioOenPin(pADI_GPIO2,PIN4,1);               // Configure P2.4 as an output - DS2 on the evaluation board
  DioDsPin(pADI_GPIO2,PIN4,1);                // Set P2.4 output drive strength to max value
  DioPulPin(pADI_GPIO2, 0x10,1);              // Enable internal pull-up resistor on P2.4  
}

/* Initialize Uart for 230400-8-N */
void UartInit(void)
{
  DioCfgPin(pADI_GPIO0,PIN11,1);               // Setup P0[11:10] as UART pins
  DioCfgPin(pADI_GPIO0,PIN10,1);
  pADI_UART0->COMLCR2 = 0x3;                  // Set PCLk oversampling rate 32. (PCLK to UART baudrate generator is /32)
  UrtCfg(pADI_UART0,B230400,
         (BITM_UART_COMLCR_WLS|3),0);         // Configure UART for 230400 baud rate
  UrtFifoCfg(pADI_UART0, RX_FIFO_14BYTE,      // Configure the UART FIFOs for 8 bytes deep
             BITM_UART_COMFCR_FIFOEN);
  UrtFifoClr(pADI_UART0, BITM_UART_COMFCR_RFCLR// Clear the Rx/TX FIFOs
             |BITM_UART_COMFCR_TFCLR);
  UrtIntCfg(pADI_UART0,BITM_UART_COMIEN_ERBFI |
            BITM_UART_COMIEN_ETBEI |
              BITM_UART_COMIEN_ELSI);                  // Enable Rx, Tx and Rx buffer full Interrupts
  NVIC_EnableIRQ(UART_EVT_IRQn);              // Enable UART interrupt source in NVIC
}

/* Simple delay routine */
void delay (long int length)
{
  while (length >0)
    length--;
}

/* SPIO Interrupt Handler */
void SPI0_Int_Handler()
{
  uint32_t SPI0SSTATUS = 0;
  SPI0SSTATUS = SpiSta(pADI_SPI0);
  
  /* Receive IRQ */
  if((SPI0SSTATUS & BITM_SPI_STAT_RXIRQ) == BITM_SPI_STAT_RXIRQ) // Slave Recieve IRQ
  {
    if(ucReceiveInProgress == 1)
    {
      rxDat[ucRxCount++] = SpiRx(pADI_SPI0);         // read SPI0 FIFO
      SpiTx(pADI_SPI0,ucTransfer[ucSpiCWrCnt++]);     // send SPI0 byte
      pADI_SPI0->STAT |=BITM_SPI_STAT_RXIRQ;         // Clear the Rx interrupt
    }
  }
  
  /* CS Rising IRQ to indicate transaction complete */
  if((SPI0SSTATUS & BITM_SPI_STAT_CSRISE) == BITM_SPI_STAT_CSRISE)   // Detect chip select rising edge
  {
    rxDat[ucRxCount] = SpiRx(pADI_SPI0); // read last byte
    ucRxCount = 0;
    ucSpiCWrCnt = 0;
    ucReceiveInProgress = 0;
    if(rxDat[0] != NULL)
      ucDataReady = 1;
    pADI_SPI0->STAT |=BITM_SPI_STAT_CSRISE;         // Clear the Transfer done interrupt
    /* Flush FIFOs */
    SpiRxFifoFlush(pADI_SPI0,
                   BITM_SPI_CTL_RFLUSH);       // Flush Master Rx FIFO
    SpiRxFifoFlush(pADI_SPI0,0);
    
    SpiTxFifoFlush(pADI_SPI0,                   // Flush Tx FIFO
                   BITM_SPI_CTL_TFLUSH);
    SpiTxFifoFlush(pADI_SPI0,
                   0);
    
    /* Load buffers for next transaction */
    SpiTx(pADI_SPI0,ucTransfer[ucSpiCWrCnt++]);
    SpiTx(pADI_SPI0,ucTransfer[ucSpiCWrCnt++]);
    SpiTx(pADI_SPI0,ucTransfer[ucSpiCWrCnt++]);
  }
  /* CS falling IRQ to indicate transaction started */
  if((SPI0SSTATUS & BITM_SPI_STAT_CSFALL) == BITM_SPI_STAT_CSFALL)   // Detect chip select falling edge
  {
    ucReceiveInProgress = 1;
    pADI_SPI0->STAT |=BITM_SPI_STAT_CSFALL;          // Clear the CS interrupt
  }
}

/* Uart Interrupt Handler */
void UART_Int_Handler(void)
{
  ucCOMSTA0 = UrtLinSta(pADI_UART0);
  ucCOMIID0 = UrtIntSta(pADI_UART0);
  if ((ucCOMIID0 & 0xE) == 0x2)	          // Transmit buffer empty
  {
    ucTxBufferEmpty = 1;
  }
  if ((ucCOMIID0 & 0xE) == 0x4)	          // Receive byte
  {
    
  }
  if ((ucCOMIID0 & 0xE) == 0xC)	          // UART Time-out condition
  {
    
  }
}


