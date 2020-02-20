/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#include "ad5940.h"
#include "DioLib.h"
#include "I2cLib.h"

// Function Definitions

void delay(long int);
void ClockInit(void);
void GPIOInit(void);
void I2CInit(void);


volatile unsigned char ucSlaveToMaster[] =      // Buffer used during I2C "writes to Slave"
{0x48,0x65,0x6c,0x6c,0x6f,0x20,
0x4d,0x61,0x73,0x74,0x65,0x72,
0xD,0xA};
volatile unsigned int rxDat[16];	        // 16 byte buffer-array for I2C receive data
unsigned char ucTxCnt = 0;                      // Counts number of I2C bytes transmitted
unsigned char ucRxCnt =0;                       // Counts number of I2C bytes received
unsigned char ucEmptyCnt = 0;
unsigned char ucStopCnt =0;
unsigned char ucTestExtraRead = 0;
unsigned char ucFirFLASH_PAGE_SIZEstDataWrite = 0;

int main (void)
{
   AD5940_Initialize();
   ClockInit();
   I2CInit();

   while (1)
   {
      delay(800000);
   }
}

void ClockInit(void)
{
   pADI_CLKG0_OSC->KEY = 0xCB14;                // Select HFOSC as system clock.
   pADI_CLKG0_OSC->CTL =                        // Int 32khz LFOSC selected in LFMUX
      BITM_CLKG_OSC_CTL_HFOSCEN;

   pADI_CLKG0_CLK->CTL0 = 0;                    // PLCK,Flash reference clock,PLL=HFOSC
   pADI_CLKG0_CLK->CTL1 = 0;                    // ACLK,PCLK,HCLK divided by 1
   pADI_CLKG0_CLK->CTL5 = 0x00;                  // Enable clock to all peripherals - no clock gating
}

void I2CInit(void)
{
   DioCfgPin(pADI_GPIO0,PIN4,1);                // Setup P0.4 as I2C SCL pin
   DioCfgPin(pADI_GPIO0,PIN5,1);                // Setup P0.5 as I2C SDA pin
   DioDsPin(pADI_GPIO0,PIN4|PIN5,1);
   I2C0SIDCfg(0xA0,0xA6,0xA8,0xA0);             // Configure Slave ID value;
   I2cFifoFlush(pADI_I2C0,SLAVE,ENABLE);        // Enable flush of Slave FIFOs
   I2cFifoFlush(pADI_I2C0,SLAVE,DISABLE);
   I2cSCfg(pADI_I2C0,0,                         // I2C  - no DMA
           BITM_I2C_SCTL_IENREPST |                 // Enable repeated Start detect interrupt
              BITM_I2C_SCTL_IENSTOP |                  // enable Stop detect interrupt
                 BITM_I2C_SCTL_IENSTX |                   // enable transmit interrupt
                    BITM_I2C_SCTL_IENSRX,                    // enable receive interrupt
                    BITM_I2C_SCTL_EARLYTXR |                 // enable early transmit request - enable to support higher baud rates
                       BITM_I2C_SCTL_SLVEN);                    // Enable I2C Slave
   I2cAutoStretch(pADI_I2C0,
                  SLAVE,STRETCH_EN,0x8);        // Enable automatic clock stretching
   NVIC_EnableIRQ(I2C_SLV_EVT_IRQn);            // Enable I2C interrupt source in NVIC
}

// Simple Delay routine
void delay (long int length)
{
	while (length >0)
    	length--;
}

void I2C0_Slave_Int_Handler()
{
   unsigned int I2CSSTATUS = 0;

   I2CSSTATUS = I2cSta(pADI_I2C0,SLAVE);
   if ((I2CSSTATUS & 0x8) == 0x8)               // If I2C Slave Rx IRQ
   {
      rxDat[ucRxCnt++] = I2cRx(pADI_I2C0,SLAVE);// get byte data
      if (ucRxCnt >=16)                          // Check for an overflow of the buffer
         ucRxCnt = 0;
   }
   if ((I2CSSTATUS & 0x4) == 0x4)                 // If I2C Master Tx IRQ
   {
      I2cTx(pADI_I2C0,SLAVE,ucSlaveToMaster[ucTxCnt++]);// Load Tx FIFO
      if (ucTxCnt >=14)                          // Check for an overflow of the buffer
         ucTxCnt = 0;
   }
   if ((I2CSSTATUS & 0x2) == 0x2)              // Slave Transmit underflow
   {
      I2cTx(pADI_I2C0,SLAVE,ucSlaveToMaster[ucTxCnt++]);// Load Tx FIFO
      if (ucTxCnt >=14)                          // Check for an overflow of the buffer
         ucTxCnt = 0;
   }
   if ((I2CSSTATUS & 0x10) == 0x10)            // Slave receive overflow
   {

   }
   if ((I2CSSTATUS & 0x20) == 0x20)             // If I2C NOACK
   {

   }
   if ((I2CSSTATUS & 0x80) == 0x80)             // I2C General Call Interrupt
   {

   }
   if ((I2CSSTATUS & 0x400) == 0x400)          // If I2C Stop after Start condition detected IRQ
   {
      I2cFifoFlush(pADI_I2C0,SLAVE,ENABLE);    // Enable flush of Slave FIFOs
      I2cFifoFlush(pADI_I2C0,SLAVE,DISABLE);
      ucTxCnt = 0;
      ucRxCnt = 0;
      rxDat[15]++;

   }
   if ((I2CSSTATUS & 0x2000) == 0x2000)        // If I2C Repeated Start detected IRQ
   {
   }
}



