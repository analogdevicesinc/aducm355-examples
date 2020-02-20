/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#include "I2cLib.h"

/**
	@brief int I2cMCfg(ADI_I2C_TypeDef *pI2C, int iDMACfg, int iIntSources, int iConfig)
			========== Configure the I2C master channel.
   @param pI2C :{pADI_I2C0}
		- pADI_I2C0 for I2C0.
	@param iDMACfg :{0|BITM_I2C_MCTL_MTXDMA|BITM_I2C_MCTL_MRXDMA} \n
		- 0 by default to disable all DMA operation.
		- BITM_I2C_MCTL_MTXDMA to enable I2C Master Tx DMA requests.
		- BITM_I2C_MCTL_MRXDMA to enable I2C Master Rx DMA requests.
	@param iIntSources :{0|BITM_I2C_MCTL_IENCMP|BITM_I2C_MCTL_IENACK|BITM_I2C_MCTL_IENALOST|BITM_I2C_MCTL_IENMTX|BITM_I2C_MCTL_IENMRX} \n
		- 0 by default to disable all interrupt sources.
		- BITM_I2C_MCTL_IENCMP to enable interrupts when a Stop condition is detected. 0 by default.
		- BITM_I2C_MCTL_IENACK to enable interrupts when a NACK is detected. 0 by default.
		- BITM_I2C_MCTL_IENALOST to enable interrupts when bus arbitration is lost. 0 by default.
		- BITM_I2C_MCTL_IENMTX to enable Transmit interrupts. 0 by default.
		- BITM_I2C_MCTL_IENMRX to enable Receive interrupts. 0 by default.
	@param iConfig :{0|BITM_I2C_MCTL_LOOPBACK|I2CMCON_COMPETE_EN|I2CMCON_MASEN_EN}	\n
		- 0 by default.
		- BITM_I2C_MCTL_LOOPBACK to enable I2C loopback mode. 0 by default.
		- BITM_I2C_MCTL_COMPETE to enable I2C Master to compete for control of bus. 0 by default.
		- BITM_I2C_MCTL_MASEN to enable I2C Master mode. 0 by default.
   @return 1
**/

int I2cMCfg(ADI_I2C_TypeDef *pI2C, int iDMACfg, int iIntSources, int iConfig)
{
   int i1;

   i1 = iDMACfg;
   i1 |= iIntSources;
   i1 |= iConfig;
   pI2C->MCTL = i1;

   return 1;
}


/**
	@brief int I2cAutoStretch(ADI_I2C_TypeDef *pI2C,int iMode, int iStretch, int iPeriod)
			========== Configure the I2C Automatic Clock stretching.
   @param pI2C :{pADI_I2C0}
		- pADI_I2C0 for I2C0.
	@param iMode :{MASTER, SLAVE} \n
		- 0 or MASTER  to Automatically control I2C Master clock stretch.
		- 1 or SLAVE  to Automatically control I2C Slave clock stretch.
	@param iStretch :{STRETCH_DIS,STRETCH_EN}	\n
		- 0 or STRETCH_DIS to Automatically disable clock stretching.
		- 1 or STRETCH_EN to Automatically enable clock stretching.
  @param iPeriod :{0,1,2,3,4,5,6,7,8,9,0xA,0xB,0xC,0xD,0xE,0xF}	\n
  @return 1
**/
int I2cAutoStretch(ADI_I2C_TypeDef *pI2C,int iMode, int iStretch, int iPeriod)
{
   if (iMode == MASTER)
   {
      if (iStretch == STRETCH_EN)		// Enable master clock stretching
         pI2C->ASTRETCH_SCL |= (iStretch | iPeriod);
      else                              // Disable master clock stretching
         pI2C->ASTRETCH_SCL &= 0xFFF0;
   }
   else	// Slave clock stretch control
   {
      if (iStretch == STRETCH_EN)		// Enable Slave clock stretching
         pI2C->ASTRETCH_SCL |= ((iStretch | iPeriod)<<4);
      else                              // Disable Slave clock stretching
         pI2C->ASTRETCH_SCL &= 0xFF0F;
   }
   return 1;
}

/**
	@brief int I2cFifoFlush(ADI_I2C_TypeDef *pI2C,int iMode, int iFlush)
			========== Flush Master or Slave Tx FIFO
   @param pI2C :{pADI_I2C0}
		- pADI_I2C0 for I2C0.
	@param iMode :{MASTER, SLAVE}
		- 0 or MASTER for I2C Master operation.
		- 1 or SLAVE for I2C Slave operation.
	@param iFlush :{DISABLE, ENABLE}
		- 0 or DISABLE to disable flush of FIFO.
		- 1 or ENABLE to enable flush of FIFO.
	@return 1 if successful
**/

int I2cFifoFlush(ADI_I2C_TypeDef *pI2C,int iMode, int iFlush)
{
   if (iMode == 1) // slave
   {
      if (iFlush == 1)
         pI2C->STAT |= 0x100;
      else
         pI2C->STAT &= 0xEFF;
   }
   else           // master
   {
      if (iFlush == 1)
         pI2C->STAT |= 0x200;
      else
         pI2C->STAT &= 0xDFF;
   }
   return 1;
}

/**
	@brief int I2cSCfg(ADI_I2C_TypeDef *pI2C, int iDMACfg, int iIntSources, int iConfig)
			========== Configure the I2C channel.
   @param pI2C :{pADI_I2C0}
		- pADI_I2C0 for I2C0.
	@param iDMACfg :{0|BITP_I2C_SCTL_STXDMA|BITP_I2C_SCTL_SRXDMA} \n
		- 0 by default to disable all DMA operation.
		- BITM_I2C_SCTL_STXDMA to enable I2C Slave Tx DMA requests.
		- BITM_I2C_SCTL_SRXDMA to enable I2C Slave Rx DMA requests.
	@param iIntSources :{0|BITP_I2C_SCTL_IENREPST|BITP_I2C_SCTL_IENSTX|BITP_I2C_SCTL_IENSRX|BITP_I2C_SCTL_IENSTOP} \n
		- 0 by default to disable all interrupt sources.
		- BITM_I2C_SCTL_IENREPST to enable interrupts when a repeated Start condition is detected. 0 by default.
		- BITM_I2C_SCTL_IENSTX to enable Transmit interrupts. 0 by default.
		- BITM_I2C_SCTL_IENSRX to enable Receive interrupts. 0 by default.
		- BITM_I2C_SCTL_IENSTOP to enable interrupts when Stop condition is detected. 0 by default.
	@param iConfig :{0|BITP_I2C_SCTL_NACK|BITP_I2C_SCTL_EARLYTXR|BITP_I2C_SCTL_GCSBCLR|I2CSCON_HGCEN_EN|I2CSCON_GCEN_EN|I2CSCON_ADR10EN_EN|I2CSCON_SLVEN_EN}	\n
		- 0 by default.
		- BITM_I2C_SCTL_NACK to force NACK after next byte. 0 by default.
		- BITM_I2C_SCTL_EARLYTXR to enable early transmit request. 0 by default.
		- BITM_I2C_SCTL_GCSBCLR to clear general call status register.
		- BITM_I2C_SCTL_HGCEN to enable Hardware general calls. 0 by default.
		- BITM_I2C_SCTL_GCEN to enable general calls. 0 by default.
		- BITM_I2C_SCTL_ADR10EN to enable 10-bit addresses. 0 by default.
		- BITM_I2C_SCTL_SLVEN to enable Slave mode. 0 by default.
   @return 1
**/

int I2cSCfg(ADI_I2C_TypeDef *pI2C,int iDMACfg, int iIntSources, int iConfig)
{
   int i1;

   i1 = iDMACfg;
   i1 |= iIntSources;
   i1 |= iConfig;
   pI2C->SCTL = i1;

   return 1;
}


/**
	@brief int I2cRx(ADI_I2C_TypeDef *pI2C,int iMode)
			========== Reads 8 bits of I2CMRX or I2CSRX
   @param pI2C :{pADI_I2C0,pADI_I2C1}
		- pADI_I2C0 for I2C0.
	@param iMode :{MASTER, SLAVE}
		- 0 or MASTER for I2C Master operation.
		- 1 or SLAVE for I2C Slave operation.
	@return I2CSRX or I2CMRX
**/

int I2cRx(ADI_I2C_TypeDef *pI2C,int iMode)
{
   int i1;

   i1 = iMode;
   if (i1 == 1)
   {
      return pI2C->SRX;
   }
   else
   {
      return pI2C->MRX;
   }
}


/**
	@brief int I2cTx(ADI_I2C_TypeDef *pI2C,int iMode, int iTx)
			========== Write 8 bits of iTx to I2CMTX ro I2CSTX
   @param pI2C :{pADI_I2C0,pADI_I2C1}
		- pADI_I2C0 for I2C0.
	@param iMode :{MASTER, SLAVE}
		- 0 or MASTER for I2C Master operation.
		- 1 or SLAVE for I2C Slave operation.
	@param iTx :{0-255}	\n
		Byte to transmit.
	@return 1 if successful
**/

int I2cTx(ADI_I2C_TypeDef *pI2C,int iMode, int iTx)
{
   unsigned int i1;

   i1 = iTx;
   if (iMode == 1)
      pI2C->STX = i1;
   else
      pI2C->MTX = i1;
   return 1;
}


/**
	@brief int I2cBaud(ADI_I2C_TypeDef *pI2C,int iHighPeriod, int iLowPeriod)
	========== Set the I2C clock rate in Master mode - CLK3 setting not accounted for

	@brief iHighPeriod configures the Master Clock high period               \n
	@brief iLowPeriod configures the Master Clock low period            \n
   @param pI2C :{pADI_I2C0}
		- pADI_I2C0 for I2C0.
	@param iHighPeriod :{0-255}                                       \n
		- 0x1D for 400kHz operation.

	@param iLowPeriod :{0-255}	                             \n
		- 0x20 for 400kHz operation.

	@return 1
**/

int I2cBaud(ADI_I2C_TypeDef *pI2C,int iHighPeriod, int iLowPeriod)
{
   unsigned int i1;

   i1 =  iLowPeriod;
   i1 |= (iHighPeriod << 8);
   pI2C->DIV = i1;
   return 1;
}


/**
	@brief int I2cMWrCfg(ADI_I2C_TypeDef *pI2C,unsigned int uiDevAddr)
			========== Configure I2C_ADR1/I2C_ADR2 - Device address register.
	@param pI2C :{pADI_I2C0}
		- pADI_I2C0 for I2C0.
	@param uiDevAddr :{0-1023}     \n
	@ This function write uiDevAddr to I2CADR1 address, lsb =0
	@return 1
**/

int I2cMWrCfg(ADI_I2C_TypeDef *pI2C,unsigned int uiDevAddr)
{
   uiDevAddr &= 0xFFFE;		// Ensure write bit is configured
   if (uiDevAddr > 0xFF)  	// Check for 10-bit address
   {
      pI2C->ADDR2 = (uiDevAddr & 0xFF);
      pI2C->ADDR1	= ((uiDevAddr >> 7) & 0x6) | 0xF0;
   }
   else
   {
      pI2C->ADDR1 = uiDevAddr & 0xFF;
      pI2C->ADDR2 = 0x00;
   }
   return 1;
}


/**
	@brief int I2cMRdCfg(ADI_I2C_TypeDef *pI2C,unsigned int uiDevAddr, int iNumBytes, int iExt)
			========== Configure I2C_MRXCNT - Master read control register.
	@param pI2C :{pADI_I2C0}
		- pADI_I2C0 for I2C0.
	@param uiDevAddr :{0-1023}     \n
	@param iNumBytes :{0-65535}     \n
	@param iExt :{0,BITM_I2C_MRXCNT_EXTEND}
		- 0 for Master to Read 1 to 256 bytes
		- BITM_I2C_MRXCNT_EXTEND for Master to read more than 256 bytes
	@return 1
**/

int I2cMRdCfg(ADI_I2C_TypeDef *pI2C,unsigned int uiDevAddr, int iNumBytes, int iExt)
{
   pI2C->MRXCNT = (iNumBytes - 1);
   pI2C->MRXCNT |= iExt;
   if (uiDevAddr > 0xFF)  		// Check for 10-bit address
   {
      pI2C->ADDR2	= (uiDevAddr & 0xFF);
      pI2C->ADDR1	= ((uiDevAddr >> 7) & 0x6) | 0xF0;
   }
   else
   {
      pI2C->ADDR1 = uiDevAddr & 0xFF;
      pI2C->ADDR2 = 0x00;
   }
   pI2C->ADDR1 |= 0x1;			// Ensure read bit is set to 1
   return 1;
}

/**
	@brief int I2cSta(ADI_I2C_TypeDef *pI2C,int iMode)
			========== Read the status register for the I2C Master or Slave.
	@param pI2C :{pADI_I2C0}
		- pADI_I2C0 for I2C0.
   @param iMode :{MASTER, SLAVE}
		- 0 or MASTER for I2C Master operation.
		- 1 or SLAVE for I2C Slave operation.
	@return value of I2C_SSTAT:
		- I2C_SSTAT.0 = Tx FIFO status
		- I2C_SSTAT.1 = I2C Tx FIFO under-run
		- I2C_SSTAT.2 = I2C Tx Request
		- I2C_SSTAT.3 = I2C Rx Request
		- I2C_SSTAT.4 = I2C Rx FIFO overflow
		- I2C_SSTAT.5 = I2C Slave NACK of address byte
		- I2C_SSTAT.6 = I2C Slave busy
		- I2C_SSTAT.7 = I2C general call interrupt
		- I2C_SSTAT.9:8 = I2C general call ID
		- I2C_SSTAT.10 = I2C Stop condition detected
		- I2C_SSTAT.12:11 = I2C ID Match status
		- I2C_SSTAT.13 = I2C repeated Start condition detected
		- I2CSSTA.14 = I2C Start + matching address condition detected
	@return value of I2CMSTA:
                - I2C_MSTAT.[0:1] = Tx FIFO status
		- I2C_MSTAT.2 = I2C Tx Request
		- I2C_MSTAT.3 = I2C Rx Request
		- I2C_MSTAT.4 = I2C NACK of address byte from Slave
		- I2C_MSTAT.5 = I2C Arbitration lost
		- I2C_MSTAT.6 = I2C Master busy
		- I2C_MSTAT.7 = I2C NACK of data byte from Slave
		- I2C_MSTAT.8 = I2C Stop condition detected
		- I2C_MSTAT.9 = Rx overflow
		- I2C_MSTAT.10 = I2C Bus busy
		- I2C_MSTAT.11 = I2C Stop detected
		- I2C_MSTAT.12 = I2C Tx Under-run condition
**/

int I2cSta(ADI_I2C_TypeDef *pI2C,int iMode)
{
   if (iMode == 1)
      return pI2C->SSTAT;
   else
      return pI2C->MSTAT;
}


/**
	@brief int I2cMRdCnt(ADI_I2C_TypeDef *pI2C)
			========== Master Read count register - read by master to keep track of number of bytes received.
	@param pI2C :{pADI_I2C0}
		- pADI_I2C0 for I2C0.
	@return value of I2C_MCRXCNT.
**/

int I2cMRdCnt(ADI_I2C_TypeDef *pI2C)
{
   return pI2C->MCRXCNT;
}


/**
	@brief int I2cSGCallCfg(ADI_I2C_TypeDef *pI2C,int iHWGCallAddr)
			========== Configure ID value for Hardware General Calls.
	@param pI2C :{pADI_I2C0}
		- pADI_I2C0 for I2C0.
	@param iHWGCallAddr :{0-255}
	@return 1
**/

int I2cSGCallCfg(ADI_I2C_TypeDef *pI2C,int iHWGCallAddr)
{
   pI2C->ALT = iHWGCallAddr;
   return 1;
}


/**
	@brief int I2C0SIDCfg(int iSlaveID0, int iSlaveID1,int iSlaveID2,int iSlaveID3)
			========== Configure ID value for Slave address - value betweeen 0-0xFF.

	@param iSlaveID0 :{0-255}
	@param iSlaveID1 :{0-255}
	@param iSlaveID2 :{0-255}
	@param iSlaveID3 :{0-255}
	@return 1
**/

int I2C0SIDCfg(int iSlaveID0, int iSlaveID1,int iSlaveID2,int iSlaveID3)
{
   pADI_I2C0->ID0 = iSlaveID0;
   pADI_I2C0->ID1 = iSlaveID1;
   pADI_I2C0->ID2 = iSlaveID2;
   pADI_I2C0->ID3 = iSlaveID3;
   return 1;
}

/**@}*/


