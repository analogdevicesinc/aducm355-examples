/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#include "SpiLib.h"

/**
   @brief int SpiSta(ADI_SPI_TypeDef *pSPI)
         ========== Read the status register for the SPI.
   @param pSPI :{pADI_SPI0, pADI_SPI1}
      - pADI_SPI0 for SPI0.
      - pADI_SPI1 for SPI1.
   @return value of SPIx_STAT:
      - BITM_SPI_STAT_IRQ, Global SPI IRQ.
      - BITM_SPI_STAT_XFRDONE
      - BITM_SPI_STAT_TXEMPTY, SPI Tx FIFO empty.
      - BITM_SPI_STAT_TXDONE, SPI Tx done IRQ.
      - BITM_SPI_STAT_TXUNDR, SPI Tx underflow
      - BITM_SPI_STAT_TXIRQ, SPI Tx interrupt
      - BITM_SPI_STAT_RXIRQ, SPI Rx IRQ.
      - BITM_SPI_STAT_RXOVR, SPI Rx Overflow IRQ.
      - BITM_SPI_STAT_CS, bit 11 is CS status
      - BITM_SPI_STAT_CSERR, SPI CS error status
      - BITM_SPI_STAT_CSFALL, Chip select falling edge detected IRQ.
      - BITM_SPI_STAT_CSRISE, Chip select rising edge detected IRQ.
      - BITM_SPI_STAT_RDY, Detected edge on the RDY signal
**/
int SpiSta(ADI_SPI_TypeDef *pSPI)
{
   return pSPI->STAT;
}

/**
   @brief int SpiRx(ADI_SPI_TypeDef *pSPI)
         ========== Write 8 bits of iRx to SPIxRX.
   @param pSPI :{pADI_SPI0, pADI_SPI1}
      - pADI_SPI0 for SPI0.
      - pADI_SPI1 for SPI1.
   @return SPIRX value.
**/

int SpiRx(ADI_SPI_TypeDef *pSPI)
{
   return pSPI->RX;
}

/**
   @brief int SpiTx(ADI_SPI_TypeDef *pSPI, int iTx);
         ========== Write 8 bits of iTx to SPIxTX.
   @param pSPI :{pADI_SPI0, pADI_SPI1}
      - pADI_SPI0 for SPI0.
      - pADI_SPI1 for SPI1.
   @param iTx :{0-255}
      - Byte to transmit.
   @return 1.
**/

int SpiTx(ADI_SPI_TypeDef *pSPI, int iTx)
{
   pSPI->TX = iTx;
   return 1;
}

/**
   @brief int SpiBaud(ADI_SPI_TypeDef *pSPI, int iClkDiv)
         ========== Set the SPI clock rate in Master mode.
   @param pSPI :{pADI_SPI0, pADI_SPI1}
      - pADI_SPI0 for SPI0.
      - pADI_SPI1 for SPI1.
   @param iClkDiv :{0 - 63}
      -  iClkDiv to set the SPI baud rate - baud rate is SPI PCLK/2x(iCLKDiv+1).

   @return 1.
**/
int SpiBaud(ADI_SPI_TypeDef *pSPI, int iClkDiv)
{
   pSPI->DIV = iClkDiv;
   return 1;
}

/**
   @brief int SpiCfg(ADI_SPI_TypeDef *pSPI, int iCsErr, int iMasterEn, int iConfig);
      ========== Configure the SPI channel.
   @param pSPI :{pADI_SPI0, pADI_SPI1}
      - pADI_SPI0 for SPI0.
      - pADI_SPI1 for SPI1.
   @param iCsErr :{BITM_SPI_CTL_CSRST}
      - 0x4000 or BITM_SPI_CTL_CSRST to reset the bit counter after CS error. Recommend this bit is set
      - 0 to this parameter to not reset the bit shift counter after a CS error. Not recommended
   @param iMasterEn :{BITM_SPI_CTL_MASEN}
      - 0 to enable SPI in Slave mode.
      - 0x2 or BITM_SPI_CTL_MASEN to enable SPI in Master mode.
   @param iConfig :{BITM_SPI_CTL_SPIEN|BITM_SPI_CTL_CPHA|BITM_SPI_CTL_CPOL|BITM_SPI_CTL_WOM|BITM_SPI_CTL_LSB|BITM_SPI_CTL_TIM|
                    BITM_SPI_CTL_ZEN|BITM_SPI_CTL_RXOF|BITM_SPI_CTL_OEN|BITM_SPI_CTL_LOOPBACK|BITM_SPI_CTL_CON}
      - 0x800 or BITM_SPI_CTL_CON to enable continuous transfer. 0 to disable continuous mode. 0 by default.
      - 0x400 or BITM_SPI_CTL_LOOPBACK to enable loopback mode (connect MISO to MOSI). 0 to disable this mode. 0 by default.
      - 0x200 or BITM_SPI_CTL_OEN for MISO to operate as normal. 0 tidisable the output driver on the MISO pin, 0 by default.
      - 0x100 or BITM_SPI_CTL_RXOF to overwrite the valid data in the Rx register with the new serial byte received. 0 to discard the new serial byte received,0 by default.
      - 0x80 or BITM_SPI_CTL_ZEN to transmit 0x00 when there is no valid data in the Tx FIFO. 0 to transmit the last data. 0 by default
      - 0x40 or BITM_SPI_CTL_TIM for Initiate transfer with a write to the SPI TX register. 0 by default.
      - 0x20 or BITM_SPI_CTL_LSB for LSB transmitted first. 0 by default.
      - 0x10 or BITM_SPI_CTL_WOM for Open Circuit Data Output Enable. 0 to disable this bit. 0 by default.
      - 0x8 or BITM_SPI_CTL_CPOL for Serial clock idles high. 0 to idle low. 0 by default.
      - 0x4 or BITM_SPI_CTL_CPHA Clock pulses are the begininng of each bit. Clear this bit for clock pulse at end.
      - 0x1 or BITM_SPI_CTL_SPIEN to enable of the SPI peripheral. 0 by default.
   @return 1.
**/
int SpiCfg(ADI_SPI_TypeDef *pSPI, int iCsErr, int iMasterEn, int iConfig)
{
   int i1;
   i1  = iCsErr;
   i1 |= iMasterEn;
   i1 |= iConfig;
   pSPI->CTL = i1;
   return 1;
}
/**
   @brief int SpiIenEn(ADI_SPI_TypeDef *pSPI,int iIntType);
      ========== Configure the SPI interrupts.To enable an interrupt set bit in iIntType
   @param pSPI :{pADI_SPI0, pADI_SPI1}
      - pADI_SPI0 for SPI0.
      - pADI_SPI1 for SPI1.
   @param iIntType :{BITM_SPI_IEN_TXEMPTY|BITM_SPI_IEN_XFRDONE|BITM_SPI_IEN_TXDONE|BITM_SPI_IEN_RDY|
                     BITM_SPI_IEN_RDY|BITM_SPI_IEN_RXOVR|BITM_SPI_IEN_TXUNDR|BITM_SPI_IEN_CS|BITM_SPI_IEN_IRQMODE}
      - 0x4000 or BITM_SPI_IEN_TXEMPTY to enable Tx-FIFO Empty interrupt enable. 0 to disable it. 0 by default
      - 0x2000 or BITM_SPI_IEN_XFRDONE to enable SPI transfer completion interrupt enable. 0 to disable it. 0 by default
      - 0x1000 or BITM_SPI_IEN_TXDONE to enable SPI transmit done interrupt enable. 0 to disable it. 0 by default
      - 0x800 or BITM_SPI_IEN_RDY to enable Ready signal edge interrupt enable. 0 to disable it. 0 by default
      - 0x400 or BITM_SPI_IEN_RXOVR to enable Rx-overflow interrupt enable. 0 to disable it. 0 by default
      - 0x200 or BITM_SPI_IEN_TXUNDR to enable Tx-underflow interrupt enable. 0 to disable it. 0 by default
      - 0x100 or BITM_SPI_IEN_CS to enable interrupt on every CS edge in slave CON mode. 0 to disable it. 0 by default
      - 0x7 to 0x1 or BITM_SPI_IEN_IRQMODE to enable SPI IRQ mode bits. 0 to disable it. 0 by default
   @return pSPI->IEN.
**/
int SpiIenEn(ADI_SPI_TypeDef *pSPI,int iIntType)
{
   pSPI->IEN |= iIntType;
   return pSPI->IEN;
}
/**
   @brief int SpiIenDis(ADI_SPI_TypeDef *pSPI,int iIntType);
      ========== Disable SPI interrupts. To disable an interrupt set bit in iIntType
   @param pSPI :{pADI_SPI0, pADI_SPI1}
      - pADI_SPI0 for SPI0.
      - pADI_SPI1 for SPI1.
   @param iIntType :{BITM_SPI_IEN_TXEMPTY|BITM_SPI_IEN_XFRDONE|BITM_SPI_IEN_TXDONE|BITM_SPI_IEN_RDY|
                     BITM_SPI_IEN_RDY|BITM_SPI_IEN_RXOVR|BITM_SPI_IEN_TXUNDR|BITM_SPI_IEN_CS|BITM_SPI_IEN_IRQMODE}
      - 0x4000 or BITM_SPI_IEN_TXEMPTY to enable Tx-FIFO Empty interrupt enable. 0 to disable it. 0 by default
      - 0x2000 or BITM_SPI_IEN_XFRDONE to enable SPI transfer completion interrupt enable. 0 to disable it. 0 by default
      - 0x1000 or BITM_SPI_IEN_TXDONE to enable SPI transmit done interrupt enable. 0 to disable it. 0 by default
      - 0x800 or BITM_SPI_IEN_RDY to enable Ready signal edge interrupt enable. 0 to disable it. 0 by default
      - 0x400 or BITM_SPI_IEN_RXOVR to enable Rx-overflow interrupt enable. 0 to disable it. 0 by default
      - 0x200 or BITM_SPI_IEN_TXUNDR to enable Tx-underflow interrupt enable. 0 to disable it. 0 by default
      - 0x100 or BITM_SPI_IEN_CS to enable interrupt on every CS edge in slave CON mode. 0 to disable it. 0 by default
      - 0x7 to 0x1 or BITM_SPI_IEN_IRQMODE to enable SPI IRQ mode bits. 0 to disable it. 0 by default
   @return pSPI->IEN.
**/
int SpiIenDis(ADI_SPI_TypeDef *pSPI,int iIntType)
{
   pSPI->IEN &= ~(iIntType);
   return pSPI->IEN;
}
/**
   @brief int SpiFifoFlush(ADI_SPI_TypeDef *pSPI, int iTxFlush, int iRxFlush);
         ========== Function to flush Rx or Tx FIFOs.
   @param pSPI :{pADI_SPI0, pADI_SPI1}
      - pADI_SPI0 for SPI0.
      - pADI_SPI1 for SPI1.
   @param iTxFlush :{BITM_SPI_CTL_TFLUSH}
      - Set to Flush the Tx FIFO.
      - 0 to do nothing.
      - BITM_SPI_CTL_TFLUSH to flush Tx FIFO.
   @param iRxFlush :{BITM_SPI_CTL_RFLUSH}
      - Set to Flush the Tx FIFO.
      - 0 to do nothing.
      - BITM_SPI_CTL_RFLUSH to flush Rx FIFO.
   @return 1.
**/
int SpiFifoFlush(ADI_SPI_TypeDef *pSPI, int iTxFlush, int iRxFlush)
{
   if (iTxFlush == BITM_SPI_CTL_TFLUSH)
   {
      pSPI->CTL	|= BITM_SPI_CTL_TFLUSH;
      pSPI->CTL	-= BITM_SPI_CTL_TFLUSH;
   }
   if (iRxFlush == BITM_SPI_CTL_RFLUSH)
   {
      pSPI->CTL	|= BITM_SPI_CTL_RFLUSH;
      pSPI->CTL	-= BITM_SPI_CTL_RFLUSH;
   }
   return 1;
}

/**
   @brief int SpiTxFifoFlush(ADI_SPI_TypeDef *pSPI, int iTxFlush)
         ========== Function to flush Tx FIFO.
   @param pSPI :{pADI_SPI0, pADI_SPI1}
      - pADI_SPI0 for SPI0.
      - pADI_SPI1 for SPI1.
   @param iTxFlush :{0,BITM_SPI_CTL_TFLUSH}
      - Set to Flush the Tx FIFO.
      - 0 to do nothing.
      - BITM_SPI_CTL_TFLUSH to flush Tx FIFO.
   @warning
                The flush bit stays set or cleared.
   @return 1.
**/
int SpiTxFifoFlush(ADI_SPI_TypeDef *pSPI, int iTxFlush)
{
   if (iTxFlush == BITM_SPI_CTL_TFLUSH)
   {
      pSPI->CTL	|= BITM_SPI_CTL_TFLUSH;
   }
   else
   {
      pSPI->CTL	&= (~BITM_SPI_CTL_TFLUSH);
   }
   return 1;
}

/**
   @brief int SpiRxFifoFlush(ADI_SPI_TypeDef *pSPI, int iRxFlush)
         ========== Function to flush Rx FIFO.
   @param pSPI :{pADI_SPI0, pADI_SPI1}
      - pADI_SPI0 for SPI0.
      - pADI_SPI1 for SPI1.
   @param iRxFlush :{0,BITM_SPI_CTL_RFLUSH}
      - Set to Flush the Rx FIFO.
      - 0 to do nothing.
      - BITM_SPI_CTL_RFLUSH to flush Rx FIFO
   @warning
                The flush bit stays set or cleared.
   @return 1.
**/
int SpiRxFifoFlush(ADI_SPI_TypeDef *pSPI, int iRxFlush)
{
   if (iRxFlush == BITM_SPI_CTL_RFLUSH)
   {
      pSPI->CTL	|= BITM_SPI_CTL_RFLUSH;
   }
   else
   {
      pSPI->CTL	&= (~BITM_SPI_CTL_RFLUSH);
   }
   return 1;
}
/**
   @brief int SpiFifoSta(ADI_SPI_TypeDef *pSPI)
         ========== Read the FIFO status register for the SPI.
   @param pSPI :{pADI_SPI0, pADI_SPI1}
      - pADI_SPI0 for SPI0.
      - pADI_SPI1 for SPI1.
   @return value of SPIx_FIFO_STAT:
- Bits 0 to 3 or BITM_SPI_FIFO_STAT_TX, reflect # of bytes in TX FIFO.
- Bits 8 to 11 or BITM_SPI_FIFO_STAT_RX, reflect # of bytes in RX FIFO.
   @return pSPI->FIFO_STAT
**/
int SpiFifoSta(ADI_SPI_TypeDef *pSPI)
{
   return pSPI->FIFO_STAT;
}
/**
   @brief int SpiDma(ADI_SPI_TypeDef *pSPI, int iDmaRxSel, int iDmaTxSel, int iDmaEn);
         ========== Enables/Disables DMA channel.
   @param pSPI :{pADI_SPI0, pADI_SPI1}
      - pADI_SPI0 for SPI0.
      - pADI_SPI1 for SPI1.
   @param iDmaRxSel :{0,BITM_SPI_DMA_RXEN}
      - 0 to disable SPI Rx DMA channel.
      - BITM_SPI_DMA_RXEN to enable SPI Rx DMA channel.
   @param iDmaTxSel :{0,BITM_SPI_DMA_TXEN}
      - 0 to disable SPI Tx DMA channel.
      - BITM_SPI_DMA_TXEN to enable SPI Tx DMA channel.
   @param iDmaEn :{0,BITM_SPI_DMA_EN}
      - 0 to disable SPI DMA mode.
      - BITM_SPI_DMA_EN to enable SPI DMA mode.
   @return 1.
*/
int SpiDma(ADI_SPI_TypeDef *pSPI, int iDmaRxSel, int iDmaTxSel, int iDmaEn)
{
   int	i1;
   i1 = iDmaRxSel;
   i1 |= iDmaTxSel;
   i1 |= iDmaEn;
   pSPI->DMA = i1;
   return 1;
}

/**
   @brief int SpiCount(ADI_SPI_TypeDef *pSPI, int iSpiCnt, int iWr, int iFrameContEn);
         ========== Write iSpiCnt to SPI Transfer Byte Count Register
   @param pSPI :{pADI_SPI0, pADI_SPI1}
      - pADI_SPI0 for SPI0.
      - pADI_SPI1 for SPI1.
   @param iSpiCnt :{0-8191}
      - Bytes to transmit.
   @param iWr :{0,1}
	   - 0 to read mode only (ignores iMcr).
	   - 1 to write and read mode.
   @param iFrameContEn :{0,BITM_SPI_CNT_FRAMECONT}
	   - 0 for normal operation - no continuous framing.
           - 1 or BITM_SPI_CNT_FRAMECONT to continuously send the number of bytes specified in SPIx_CNT[13:0].
   @return SPICNT, Number of bytes received.
**/

int SpiCount(ADI_SPI_TypeDef *pSPI, int iSpiCnt, int iWr, int iFrameContEn)
{
   if(iWr) pSPI->CNT = ((iSpiCnt & BITM_SPI_CNT_VALUE)
                        |iFrameContEn);
   return	pSPI->CNT;
}
/**
   @brief SpiRdCmd(ADI_SPI_TypeDef *pSPI, int iCfg, int iTxBytes, int iCmdEn)
         ========== Configure SPI for read Command mode - useful when bytes need to be written before reading
   @param pSPI :{pADI_SPI0, pADI_SPI1}
      - pADI_SPI0 for SPI0.
      - pADI_SPI1 for SPI1.
   @param iCfg :{BITM_SPI_RD_CTL_THREEPIN|BITM_SPI_RD_CTL_OVERLAP}
      - 0x2 or BITM_SPI_RD_CTL_OVERLAP - set to overlap reading of data while writing. 0 for no overlap
      - 0x100 or BITM_SPI_RD_CTL_THREEPIN - set for 3-pin SPI mode. 0 for normal 4-pin mode. 0 by default
   @param iTxBytes :{0-15}
	   - sets number of bytes - 1 to be transmitted before reading starts during a read command
   @param iCmdEn :{BITM_SPI_RD_CTL_CMDEN}
	   - 1 or BITM_SPI_RD_CTL_CMDEN for read command mode
           - 0 for normal SPI read operation.
   @return SPI_RD_CTL, Number of bytes received.
**/
int SpiRdCmd(ADI_SPI_TypeDef *pSPI, int iCfg, int iTxBytes, int iCmdEn)
{
   pSPI->RD_CTL = iCfg|iTxBytes|iCmdEn;
   return pSPI->RD_CTL;
}
/**
   @brief int SpiFlowCtl(ADI_SPI_TypeDef *pSPI, int iCfg, int iRdBurstSize, int iWaitTime)
         ========== Configures SPI Flow control register and wait state timer between bursts
   @param pSPI :{pADI_SPI0, pADI_SPI1}
      - pADI_SPI0 for SPI0.
      - pADI_SPI1 for SPI1.
   @param iCfg :{BITM_SPI_FLOW_CTL_MODE|BITM_SPI_FLOW_CTL_RDYPOL}
      - 0x0 & BITM_SPI_FLOW_CTL_MODE to disable flow control
          0x1 & BITM_SPI_FLOW_CTL_MODE to enable flow control based on WAIT_TMR
          0x2 & BITM_SPI_FLOW_CTL_MODE to enable flow control based on RDY signal
          0x3 & BITM_SPI_FLOW_CTL_MODE to enable flow control based on MISO signal
      - 0x10 or BITM_SPI_FLOW_CTL_RDYPOL - Set this bit high for active high polarity on RDY or MISO. 0 for active low. 0 by default
   @param iRdBurstSize :{0-15}
	   - sets number of bytes - 1 to be read in a burst
   @param iWaitTime :{0-65535}
	   - Sets wait period between bursts when BITM_SPI_FLOW_CTL_MODE=01b
   @return 1.
**/
int SpiFlowCtl(ADI_SPI_TypeDef *pSPI, int iCfg, int iRdBurstSize, int iWaitTime)
{
   pSPI->FLOW_CTL = iCfg|iRdBurstSize;
   pSPI->WAIT_TMR = iWaitTime;

   return 1;
}
/**
   @brief int SpiCsCfg(ADI_SPI_TypeDef *pSPI, int iCsCfg, int iCSoverRide)
         ========== Configures Chip select control registers
   @param pSPI :{pADI_SPI0, pADI_SPI1}
      - pADI_SPI0 for SPI0.
      - pADI_SPI1 for SPI1.
   @param iCsCfg :{CS0|CS1|CS2|CS3}
      - 0x0 or 0x1 or CS0 For chip select 0
      - 0x2 or CS1 For chip select 1
      - 0x4 or CS2 For chip select 2
      - 0x8 or CS3 For chip select 3
   @param iCSoverRide :{0|FORCE_CS_HIGH|FORCE_CS_LOW}
      - 0 for normal Chip select operation
- 0x1 or FORCE_CS_HIGH to force a high on the selected SPI chip select
- 0x2 or FORCE_CS_LOW to force a low on the selected SPI chip select
   @return 1.
**/
int SpiCsCfg(ADI_SPI_TypeDef *pSPI, int iCsCfg, int iCSoverRide)
{
   pSPI->CS_CTL = iCsCfg;
   pSPI->CS_OVERRIDE = iCSoverRide;

   return 1;
}

/**@}*/
