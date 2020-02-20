/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

/*
     Decription: 
		- Sends 12x bytes to the Slave when External S2 is asserted
		- Interfaces to slave device via I2C0
		- Can receive 14 bytes from Slave when S3 is asserted - will send these to UART
		- UART settings are: 57600-8-N
		- Assumes EVAL-ADuCM355QSPZ evaluation board

**/

#include "ad5940.h"
#include "DioLib.h"
#include "UrtLib.h"
#include "I2cLib.h"
#include <stdio.h>
#include <string.h>

// Function Definitions

void delay(long int);
void ClockInit(void);
void GPIOInit(void);
void I2CInit(void);
void UartInit(void);
void I2CMasterSetup(void);
unsigned char I2CWritePacket(unsigned int length);// Writes 5x Bytes to Slave
unsigned char I2CReadPacket( unsigned int length);// reads bytes back from Slave

volatile unsigned char ucMasToSlave[] =           // Buffer used during I2C "writes to Slave"
{0x48,0x65,0x6c,0x6c,0x6f,0x20,
0x53,0x6c,0x61,0x76,0x65,0x20};
unsigned char ucI2CWrCnt = 0;                     // Counter for controlling I2C writes
unsigned int ucLength = 0;                        // Indicates "number of bytes" for I2C read or write
volatile unsigned char ucTransmitInProgress =0;   // Indicates I2C Tx FIFO ready for data
volatile unsigned char ucReceiveInProgress = 0;   // Indicates I2C Rx sequence with the Slave is complete
volatile unsigned int rxDat[16];	          // 16 byte buffer-array for I2C receive data
volatile unsigned char ucRxCount = 0;             // rxDat array control variable.
volatile unsigned char ucWriteToSlave = 0;        // Flag to indicate external interrupt triggered so send packet to slave
volatile unsigned char ucReadFromSlave = 0;       // Flag to indicate external interrupt triggered so read packet from slave

volatile unsigned char ucCOMSTA0 = 0;             // Variable used to store COMSTA0, UART status register
volatile unsigned char ucCOMIID0 = 0;             // Variable used to store COMIID0, UART Interrupt status register
unsigned char ucTxBufferEmpty  = 0;	          // Used to indicate that the UART Tx buffer is empty
unsigned char szTemp[64] = "";		          // Used to build string before printing to UART
unsigned int ucBytesToRD = 0;		          // Stores number of bytes to be read from Slave via I2C
int main (void)
{
   AD5940_Initialize();
   ClockInit();
   I2CInit();
   GPIOInit();
   UartInit();                                    // Setup the UART for 230400-8-N

   while (1)
   {
      delay(800000);
      if (ucWriteToSlave == 1)
      {
         ucWriteToSlave = 0;
         ucLength = 12;
         I2CWritePacket(ucLength);                 // Start sending the array ucMasToSlave[12] to the slave
         NVIC_EnableIRQ(SYS_GPIO_INTA_IRQn);       // Enable GPIO_INTA interrupt source in NVIC
      }
      if (ucReadFromSlave == 1)
      {
         ucReadFromSlave =0;
         ucLength = 14;
         I2CReadPacket(ucLength);
         delay(800000);
         NVIC_EnableIRQ(SYS_GPIO_INTB_IRQn);       // Enable GPIO_INTB interrupt source in NVIC
      }
   }

}

void ClockInit(void)
{
   pADI_CLKG0_OSC->KEY = 0xCB14;                  // Select HFOSC as system clock.
   pADI_CLKG0_OSC->CTL =                          // Int 32khz LFOSC selected in LFMUX
      BITM_CLKG_OSC_CTL_HFOSCEN;

   pADI_CLKG0_CLK->CTL0 = 0;                      // PLCK,Flash reference clock,PLL=HFOSC
   pADI_CLKG0_CLK->CTL1 = 0;                      // ACLK,PCLK,HCLK divided by 1
   pADI_CLKG0_CLK->CTL5 = 0x00;                    // Enable clock to all peripherals - no clock gating
}

void I2CInit(void)
{
   DioCfgPin(pADI_GPIO0,PIN4,1);                  // Setup P0.4 as I2C SCL pin
   DioCfgPin(pADI_GPIO0,PIN5,1);                  // Setup P0.5 as I2C SDA pin
   DioDsPin(pADI_GPIO0,PIN4,1);
   DioDsPin(pADI_GPIO0,PIN5,1);
   I2cBaud(pADI_I2C0, 0x80, 0x81);                // 390kHz baud
   I2cMCfg(pADI_I2C0,0,
           BITM_I2C_MCTL_IENCMP |                     // Enable stop detect interrupt
              BITM_I2C_MCTL_IENACK |                     // enable NACK detect interrupt
                 BITM_I2C_MCTL_IENMTX |                     // enable transmit interrupt
                    BITM_I2C_MCTL_IENMRX,                      // enable receive interrupt
                    BITM_I2C_MCTL_MASEN);                      // Enable I2C master
   //I2cAutoStretch(pADI_I2C0,
   //               MASTER,STRETCH_EN,0x7);         // Enable automatic clock stretching

   NVIC_EnableIRQ(I2C_MST_EVT_IRQn);              // Enable I2C interrupt source in NVIC
}
void GPIOInit(void)
{
   /*S2 configuration*/
   DioCfgPin(pADI_GPIO1,PIN0,0); //confige as gpio
   DioIenPin(pADI_GPIO1,PIN0,1); //enable input
   DioPulPin(pADI_GPIO1,PIN0,1);
   DioIntPin(pADI_GPIO1,PIN0,INTA,1);         // Enable External interrupt A on P1.0
   DioIntPolPin(pADI_GPIO1,PIN0,1);           // Set polarity of P1.0 interrupt to low-high transition

   /*S3 configuration*/
   DioCfgPin(pADI_GPIO1,PIN1,0); //confige as gpio
   DioIenPin(pADI_GPIO1,PIN1,1); //enable input
   DioPulPin(pADI_GPIO1,PIN1,1);
   DioIntPin(pADI_GPIO1,PIN1,INTB,1);         // Enable External interrupt A on P1.1
   DioIntPolPin(pADI_GPIO1,PIN1,1);           // Set polarity of P1.1 interrupt to low-high transition

   NVIC_EnableIRQ(SYS_GPIO_INTA_IRQn);         // Enable GPIO_INTA interrupt source in NVIC
   NVIC_EnableIRQ(SYS_GPIO_INTB_IRQn);         // Enable GPIO_INTB interrupt source in NVIC
}
void UartInit(void)
{
   DioCfgPin(pADI_GPIO0,PIN11,1);                  // Setup P0[11:10] as UART pins
   DioCfgPin(pADI_GPIO0,PIN10,1);
   pADI_UART0->COMLCR2 = 0x3;                     // Set PCLk oversampling rate 32. (PCLK to UART baudrate generator is /32)
   UrtCfg(pADI_UART0,B57600,
          (BITM_UART_COMLCR_WLS|3),0);            // Configure UART for 230400 baud rate
   UrtFifoCfg(pADI_UART0, RX_FIFO_14BYTE,         // Configure the UART FIFOs for 8 bytes deep
              BITM_UART_COMFCR_FIFOEN);
   UrtFifoClr(pADI_UART0, BITM_UART_COMFCR_RFCLR   // Clear the Rx/TX FIFOs
              |BITM_UART_COMFCR_TFCLR);
   UrtIntCfg(pADI_UART0,BITM_UART_COMIEN_ERBFI |
             BITM_UART_COMIEN_ETBEI |
                BITM_UART_COMIEN_ELSI);                     // Enable Rx, Tx and Rx buffer full Interrupts

   NVIC_EnableIRQ(UART_EVT_IRQn);                 // Enable UART interrupt source in NVIC
}
// This function Starts an I2C Write sequence
unsigned char I2CWritePacket(unsigned int length )
{
   // Transmit
   ucTransmitInProgress = 1;
   I2cFifoFlush(pADI_I2C0,MASTER,ENABLE);	  // Flush Master Tx FIFO
   I2cFifoFlush(pADI_I2C0,MASTER,DISABLE);
   I2cTx(pADI_I2C0,MASTER,ucMasToSlave[0]);       // send I2c byte
   I2cMWrCfg(pADI_I2C0,0xA0);                     // set i2c address	 (LSB = 0, Master Write)
   ucI2CWrCnt = 1;
   while (ucTransmitInProgress == 1)
   {}
   return 1;
}
// Function used to commence I2C Read sequence
unsigned char I2CReadPacket( unsigned int length)
{
   unsigned char n = 0;

   ucBytesToRD = length - 1;
   // Transmit
   ucTransmitInProgress = 1;
   I2cFifoFlush(pADI_I2C0,MASTER,ENABLE);	  // Flush Master Tx FIFO
   I2cFifoFlush(pADI_I2C0,MASTER,DISABLE);

   ucRxCount = 0;
   I2cMRdCfg(pADI_I2C0,0xA0,length,0);           // read "length" number of bytes from slave

   ucReceiveInProgress = 1;

   while (ucReceiveInProgress == 1) {}           // Wait for I2C packet to be recieved - flag cleared in I2C0 read IRQ handler

   ucTxBufferEmpty = 0;                          // Start forwarding packet UART
   ucLength = 0;
   pADI_UART0->COMTX = rxDat[0];
   for (n = 1; n < 14 ; n++)                     // Send received packet to the PC via UART
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
void I2C0_Master_Int_Handler()
{
   unsigned int I2CMSTATUS = 0;

   I2CMSTATUS = I2cSta(pADI_I2C0,MASTER);
   if((I2CMSTATUS & 0x4) == 0x4)  	          // Master Transmit IRQ
   {
      if (ucI2CWrCnt < ucLength)
      {                                         // Tx FIFO ready for another byte
         I2cTx(pADI_I2C0,MASTER,ucMasToSlave[ucI2CWrCnt++]);
      }
      else
      {
         ucTransmitInProgress = 0;
      }
   }
   // Receive
   if((I2CMSTATUS & 0x8) == 0x8)		  // Master Recieve IRQ
   {
      rxDat[ucRxCount++] = I2cRx(pADI_I2C0,MASTER);
      if(ucRxCount == (ucBytesToRD+1))
         ucReceiveInProgress = 0;
   }
   if((I2CMSTATUS & 0x10) == 0x10)		  // NACK Address detected
   {
      ucTransmitInProgress = 0;
   }
   if((I2CMSTATUS & 0x40) == 0x40)		  // NACK data detected
   {

   }
   if((I2CMSTATUS & 0x100) == 0x100)		  // Transmission Complete/Stop detected
   {
      ucReceiveInProgress = 0;
      ucRxCount = 0;
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

   uiIntSta = DioIntSta(pADI_GPIO1);
   if ((uiIntSta & 0x0001) ==0x0001)
   {
      DioIntClrPin(pADI_GPIO1,PIN0);
      ucWriteToSlave = 1;
   }

}
void GPIO_B_Int_Handler()
{
   unsigned int uiIntSta = 0;

   uiIntSta = DioIntSta(pADI_GPIO1);
   if ((uiIntSta & 0x0002) ==0x0002)
   {
      DioIntClrPin(pADI_GPIO1,PIN1);
      ucReadFromSlave = 1;
   }

}

