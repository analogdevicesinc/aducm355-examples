/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

/*
     Decription: 
	  -Sends SPI0 bytes to the Slave when External S2 is asserted
      - Interfaces to slave device via SPI0
      - Can receive 14 bytes from Slave when S3 is asserted - will send these to UART (57600-8-1-N)
      - P0.0 = SCLK
      - P0.1 = MOSI
      - P0.2 = MISO
      - P0.3 = CS0
      - Assumes EVAL-ADuCM355QSPZ evaluation board


**/

#include <stdio.h>
#include <string.h>
#include "UrtLib.h"
#include "ad5940.h"
#include "DioLib.h"
#include "SpiLib.h"

// Function Definitions

void delay(long int);
void ClockInit(void);
void GPIOInit(void);
void SpiMasterInit(void);
void UartInit(void);
uint8_t SPIWritePacket(unsigned int length);   // Writes 5x Bytes to Slave
uint8_t SPIReadPacket( unsigned int length);   // reads bytes back from Slave

uint8_t ucMasToSlave[] =                       // Buffer used during I2C "writes to Slave"
{0x48,0x65,0x6c,0x6c,0x6f,0x20,
0x53,0x6c,0x61,0x76,0x65,0x20};
uint8_t ucSpiCWrCnt = 0;                       // Counter for controlling SPI writes
uint8_t ucLength = 0;                          // Indicates "number of bytes" for SPI read or write
volatile uint8_t ucTransmitInProgress =0;      // Indicates SPI Tx FIFO ready for data
volatile uint8_t ucReceiveInProgress = 0;      // Indicates SPI Rx sequence with the Slave is complete
uint32_t rxDat[16];	                          // 16 byte buffer-array for I2C receive data
uint8_t ucRxCount = 0;                         // rxDat array control variable.
uint8_t ucWriteToSlave = 0;                    // Flag to indicate external interrupt triggered so send packet to slave
uint8_t ucReadFromSlave = 0;                   // Flag to indicate external interrupt triggered so read packet from slave

uint8_t ucCOMSTA0 = 0;                         // Variable used to store COMSTA0, UART status register
uint8_t ucCOMIID0 = 0;                         // Variable used to store COMIID0, UART Interrupt status register
uint8_t ucTxBufferEmpty  = 0;	                 // Used to indicate that the UART Tx buffer is empty
uint8_t szTemp[64] = "";		                // Used to build string before printing to UART
uint8_t ucBytesToRD = 0;		                 // Stores number of bytes to be read from Slave via SPI
int main (void)
{
   AD5940_Initialize();
   ClockInit();
   SpiMasterInit();
   GPIOInit();
   UartInit();                                 // Setup the UART for 230400-8-N

   while (1)
   {
      delay(800000);
      DioTglPin(pADI_GPIO1,0x2000);               // Toggle LED5
      if (ucWriteToSlave == 1)
      {
         ucWriteToSlave = 0;
         ucLength = 12;
         SPIWritePacket(ucLength);              // Start sending the array ucMasToSlave[12] to the slave
         delay(800000);
         NVIC_EnableIRQ(SYS_GPIO_INTA_IRQn);    // Enable GPIO_INTA interrupt source in NVIC
      }
      if (ucReadFromSlave == 1)
      {
         ucReadFromSlave =0;
         ucLength = 14;
         SPIReadPacket(ucLength);
         delay(800000);
         NVIC_EnableIRQ(SYS_GPIO_INTB_IRQn);    // Enable GPIO_INTB interrupt source in NVIC
      }
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

void SpiMasterInit(void)
{
   DioCfgPin(pADI_GPIO0,PIN0,1);               // Setup P0.0 as SPI SCLK pin
   DioCfgPin(pADI_GPIO0,PIN1,1);               // Setup P0.1 as SPI MOSI pin
   DioCfgPin(pADI_GPIO0,PIN2,1);               // Setup P0.2 as SPI MISO pin
   DioCfgPin(pADI_GPIO0,PIN3,1);               // Setup P0.3 as SPI CS0 pin

   SpiBaud(pADI_SPI0,26);                      // generate 500kHz SCLK
   SpiCfg(pADI_SPI0,BITM_SPI_CTL_CSRST,        // Configure SPI to reset after a bit shift error is detected
          BITM_SPI_CTL_MASEN,                   // Enable master mode
          BITM_SPI_CTL_CON|                     // Enable continous transfer mode
             BITM_SPI_CTL_OEN|                     // Select MISO pin to operate as normal -
                BITM_SPI_CTL_RXOF|                    // overwrite data in Rx FIFO during overflow states
                   BITM_SPI_CTL_ZEN|                     // transmit 00 when no valid data in Tx FIFO
                      BITM_SPI_CTL_TIM|                     // initiate trasnfer with a write to SPITX
                         BITM_SPI_CTL_SPIEN);                  // Enable SPI. SCLK idles low/ data clocked on SCLK falling edge
   NVIC_EnableIRQ(SPI0_EVT_IRQn);              // Enable SPI0 interrupt source in NVIC
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

void UartInit(void)
{
   DioCfgPin(pADI_GPIO0,PIN11,1);               // Setup P0[11:10] as UART pins
   DioCfgPin(pADI_GPIO0,PIN10,1);
   pADI_UART0->COMLCR2 = 0x3;                  // Set PCLk oversampling rate 32. (PCLK to UART baudrate generator is /32)
   UrtCfg(pADI_UART0,B57600,
          (BITM_UART_COMLCR_WLS|3),0);         // Configure UART for 115200 baud rate
   UrtFifoCfg(pADI_UART0, RX_FIFO_14BYTE,      // Configure the UART FIFOs for 8 bytes deep
              BITM_UART_COMFCR_FIFOEN);
   UrtFifoClr(pADI_UART0, BITM_UART_COMFCR_RFCLR// Clear the Rx/TX FIFOs
              |BITM_UART_COMFCR_TFCLR);
   UrtIntCfg(pADI_UART0,BITM_UART_COMIEN_ERBFI |
             BITM_UART_COMIEN_ETBEI |
                BITM_UART_COMIEN_ELSI);                  // Enable Rx, Tx and Rx buffer full Interrupts

   NVIC_EnableIRQ(UART_EVT_IRQn);              // Enable UART interrupt source in NVIC
}
// This function Starts an SPI0 Write sequence
unsigned char SPIWritePacket(unsigned int length )
{
   // Transmit
   ucTransmitInProgress = 1;
   SpiIenEn(pADI_SPI0,BITM_SPI_STAT_TXUNDR|     // interrupt if Tx FIFO underflow
            BITM_SPI_IEN_XFRDONE|               // interrupt when CS goes inactive at endo transfer
               (BITM_SPI_IEN_IRQMODE &0x1 ));      // Interrupt after 2x bytes sent
   SpiTxFifoFlush(pADI_SPI0,                   // Flush Tx FIFO
                  BITM_SPI_CTL_TFLUSH);
   SpiTxFifoFlush(pADI_SPI0,
                  0);
   SpiCount(pADI_SPI0,length, 1,0);            // Setup to transfer 12 bytes to slave
   pADI_SPI0->CTL |= BITM_SPI_CTL_TIM;        // SPI interrupt on Tx
   ucSpiCWrCnt = 0;
   SpiTx(pADI_SPI0,ucMasToSlave[ucSpiCWrCnt++]);// send SPI0 byte
   SpiTx(pADI_SPI0,ucMasToSlave[ucSpiCWrCnt++]);// send SPI0 byte
   while (ucTransmitInProgress == 1)
   {}

   return 1;
}
// Function used to commence SPI Read sequence
unsigned char SPIReadPacket( unsigned int length)
{
   uint8_t n = 0;
   // receive
   ucRxCount = 0;
   pADI_SPI0->CTL &= ~(BITM_SPI_CTL_TIM);     // SPI interrupt on Rx
   SpiRxFifoFlush(pADI_SPI0,
                  BITM_SPI_CTL_RFLUSH);       // Flush Master Rx FIFO
   SpiRxFifoFlush(pADI_SPI0,0);
   SpiCount(pADI_SPI0,length, 1,0);               // Setup to read 14 bytes from slave
   ucBytesToRD = length;
   rxDat[ucRxCount++] = SpiRx(pADI_SPI0);     // read SPI0 FIFO;
   ucReceiveInProgress = 1;

   while (ucReceiveInProgress == 1) {}        // Wait for SPI0 packet to be recieved - flag cleared in SPI0 read IRQ handler

   ucTxBufferEmpty = 0;                       // Start forwarding packet UART
   ucLength = 0;
   pADI_UART0->COMTX = rxDat[0];
   for (n = 1; n < 14 ; n++)                  // Send received packet to the PC via UART
   {
      while (ucTxBufferEmpty != 1){}
      ucTxBufferEmpty = 0;
      pADI_UART0->COMTX = rxDat[n];
   }
   return 1;
}
// Simple Delay routine
void delay (long int length)
{
	while (length >0)
    	length--;
}
void SPI0_Int_Handler()
{
   uint32_t SPI0MSTATUS = 0;

   SPI0MSTATUS = SpiSta(pADI_SPI0);                   // Read SPI0STA register
   // Transmit complete IRQ
   if((SPI0MSTATUS & BITM_SPI_STAT_TXIRQ) == BITM_SPI_STAT_TXIRQ)
   {
      if (ucSpiCWrCnt < ucLength)
      {                                                // Tx FIFO ready for another byte
         SpiTx(pADI_SPI0,ucMasToSlave[ucSpiCWrCnt++]);// send SPI0 byte
         SpiTx(pADI_SPI0,ucMasToSlave[ucSpiCWrCnt++]);// send SPI0 byte
         //     rxDat[ucRxCount++] = SpiRx(pADI_SPI0);      // read SPI0 FIFO
      }
      else
      {
         ucTransmitInProgress = 0;
      }
      pADI_SPI0->STAT |=BITM_SPI_STAT_TXIRQ;           // Clear the Tx interrupt
   }
   if((SPI0MSTATUS & BITM_SPI_STAT_TXUNDR) == BITM_SPI_STAT_TXUNDR)
   {
      if (ucSpiCWrCnt < ucLength)
      {                                                // Tx FIFO ready for another byte
         SpiTx(pADI_SPI0,ucMasToSlave[ucSpiCWrCnt++]); // send SPI0 byte
         //     rxDat[ucRxCount++] = SpiRx(pADI_SPI0);      // read SPI0 FIFO
      }
      else
      {
         ucTransmitInProgress = 0;
      }
      pADI_SPI0->STAT |=BITM_SPI_STAT_TXUNDR;           // Clear the Tx underflow interrupt
   }
   // Receive IRQ
   if((SPI0MSTATUS & BITM_SPI_STAT_RXIRQ) == BITM_SPI_STAT_RXIRQ)
   {
      if (ucReceiveInProgress == 1)
      {
         while (((pADI_SPI0->FIFO_STAT)& 0xF00) != 0x000)
         {
            rxDat[ucRxCount++] = SpiRx(pADI_SPI0);    // read SPI0 FIFO
            if(ucRxCount == (ucBytesToRD))
            {
               ucRxCount = 0;
               ucReceiveInProgress = 0;
            }
         }
      }
      pADI_SPI0->STAT |=BITM_SPI_STAT_RXIRQ;      // Clear the Rx interrupt
   }
   // Transfer complete
   if((SPI0MSTATUS & BITM_SPI_STAT_XFRDONE) == BITM_SPI_STAT_XFRDONE)
   {
      ucRxCount = 0;
      ucSpiCWrCnt = 0;
      ucReceiveInProgress = 0;
      pADI_SPI0->STAT |=BITM_SPI_STAT_XFRDONE;    // Clear the Transfer done interrupt
      SpiFifoFlush(pADI_SPI0,0,
                   BITM_SPI_CTL_RFLUSH);	             // Flush Master Rx FIFO
      SpiFifoFlush(pADI_SPI0,0,
                   0);
   }
}
void UART_Int_Handler()
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
void GPIO_A_Int_Handler()
{
   unsigned int uiIntSta = 0;
   unsigned short usLED3 = 0;

   uiIntSta = DioIntSta(pADI_GPIO1);
   if ((uiIntSta & 0x0001) ==0x0001)
   {
      DioIntClrPin(pADI_GPIO1,PIN0);
      usLED3 = DioRd(pADI_GPIO2);                  // read P2.4
      if ((usLED3 & 0x10) == 0x10)
         DioClrPin(pADI_GPIO2,0x10);                // Clear P2.4
      else
         DioSetPin(pADI_GPIO2,0x10);                // Set P2.4
      ucWriteToSlave = 1;                          // Initate write to slave
   }
   NVIC_DisableIRQ(SYS_GPIO_INTA_IRQn);           // Disable GPIO_INTA interrupt source in NVIC
}
void GPIO_B_Int_Handler()
{
   unsigned int uiIntSta = 0;
   unsigned short usLED3 = 0;
   
   uiIntSta = DioIntSta(pADI_GPIO1);
   if ((uiIntSta & 0x0002) ==0x0002)
   {
      DioIntClrPin(pADI_GPIO1,PIN1);
      DioTglPin(pADI_GPIO1,0x1000);
      ucReadFromSlave = 1;
      
      usLED3 = DioRd(pADI_GPIO2);                  // read P2.4
      if ((usLED3 & 0x10) == 0x10)
         DioClrPin(pADI_GPIO2,0x10);                // Clear P2.4
      else
         DioSetPin(pADI_GPIO2,0x10);                // Set P2.4
   }
   NVIC_DisableIRQ(SYS_GPIO_INTB_IRQn);           // Disable GPIO_INTB interrupt source in NVIC
}

