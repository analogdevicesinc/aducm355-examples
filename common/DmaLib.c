/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#include <stdio.h>
#include <string.h>
#include "DmaLib.h"
#include "ad5940.h"


#if defined(__ARMCC_VERSION) || defined(__GNUC__)
DmaDesc dmaChanDesc     [CCD_SIZE*2] __attribute__ ((aligned (DMACHAN_DSC_ALIGN)));
#endif

#ifdef __ICCARM__
#pragma data_alignment=(DMACHAN_DSC_ALIGN)
DmaDesc dmaChanDesc     [CCD_SIZE*2];
#endif

/**
   @brief DmaDesc * Dma_GetDescriptor(unsigned int iChan);
         ========== Returns the Primary or Alternate structure descriptor of the
         specified channel.
   @param iChan :{SPI1TX_C,SPI1RX_C,SPORT0A_C,SPORT0B_C,SPI0TX_C,SPI0RX_C,SPI1TX_C,
         SPI1RX_C,UART0TX_C,UART0RX_C,I2C0STX_C,I2C0SRX_C,I2C0M_C,CRYPTO0IN_C,
         CRYPTO0OUT_C,Flash_C,AFEDATAFIFO_C,SOFTDMA0_C,SOFTDMA1_C,
         SOFTDMA2_C,SOFTDMA3_C,SOFTDMA4_C,SOFTDMA5_C,SPI1TX_C+ALTERNATE,
         SPI1RX_C+ALTERNATE,SPORT0A_C+ALTERNATE,SPORT0B_C+ALTERNATE,
         SPI0TX_C+ALTERNATE,SPI0RX_C+ALTERNATE,SPI1TX_C+ALTERNATE,
         SPI1RX_C+ALTERNATE,UART0TX_C+ALTERNATE,UART0RX_C+ALTERNATE,
         I2C0STX_C+ALTERNATE,I2C0SRX_C+ALTERNATE,I2C0M_C+ALTERNATE,
         CRYPTO0IN_C+ALTERNATE,CRYPTO0OUT_C+ALTERNATE,Flash_C+ALTERNATE,
         AFEDATAFIFO_C+ALTERNATE,SOFTDMA0_C+ALTERNATE,
         SOFTDMA1_C+ALTERNATE,SOFTDMA2_C+ALTERNATE,SOFTDMA3_C+ALTERNATE,
         SOFTDMA4_C+ALTERNATE,SOFTDMA5_C+ALTERNATE}
    - 0 or SPI1TX_C        for the SPI1 Transmit channel       - primary structure
    - 1 or SPI1RX_C        for the SPI1 Receive channel        - primary structure
    - 2 or SPORT0A_C       for the SPORT0A channel             - primary structure
    - 3 or SPORT0B_C       for the SPORT0B channel             - primary structure
    - 4 or SPI0TX_C        for the SPI0 Transmit channel       - primary structure
    - 5 or SPI0RX_C        for the SPI0 Receive channel        - primary structure
    - 6 or SPI1TX_C        for the SPI1 transmit channel       - primary structure
    - 7 or SPI1RX_C        for the SPI1 receive channel        - primary structure
    - 8 or UART0TX_C       for the UART Transmit channel       - primary structure
    - 9 or UART0RX_C       for the UART Receive channel        - primary structure
    - 10 or I2C0STX_C      for the I2C0 Slave transmit channel - primary structure
    - 11 or I2C0SRX_C      for the I2C0 Slave receive channel  - primary structure
    - 12 or I2C0M_C        for the I2C0 Master channel         - primary structure
    - 13 or CRYPTO0IN_C    for the crypto in channel           - primary structure
    - 14 or CRYPTO0OUT_C   for the crypto out channel          - primary structure
    - 15 or Flash_C        for the Flash channel               - primary structure
    - 17 or AFEDATAFIFO_C   for the AFE DATA FIFO channel      - primary structure
    - 18 to 23 or SOFTDMA0_C to SOFTDMA5_C for Software DMA    - primary structure

    - 32 or SPI1TX_C+ALTERNATE         for the SPI1 Transmit channel       - alternate structure
    - 33 or SPI1RX_C+ALTERNATE         for the SPI1 Receive channel        - alternate structure
    - 34 or SPORT0A_C+ALTERNATE        for the SPORT0A channel             - alternate structure
    - 35 or SPORT0B_C+ALTERNATE        for the SPORT0B channel             - alternate structure
    - 36 or SPI0TX_C+ALTERNATE         for the SPI0 Transmit channel       - alternate structure
    - 37 or SPI0RX_C+ALTERNATE         for the SPI0 Receive channel        - alternate structure
    - 38 or SPI1TX_C+ALTERNATE         for the SPI1 transmit channel       - alternate structure
    - 39 or SPI1RX_C+ALTERNATE         for the SPI1 receive channel        - alternate structure
    - 40 or UART0TX_C+ALTERNATE        for the UART Transmit channel       - alternate structure
    - 41 or UART0RX_C+ALTERNATE        for the UART Receive channel        - alternate structure
    - 42 or I2C0STX_C+ALTERNATE        for the I2C0 Slave transmit channel - alternate structure
    - 43 or I2C0SRX_C+ALTERNATE        for the I2C0 Slave receive channel  - alternate structure
    - 44 or I2C0M_C+ALTERNATE          for the I2C0 Master channel         - alternate structure
    - 45 or CRYPTO0IN_C+ALTERNATE      for the crypto in channel           - alternate structure
    - 46 or CRYPTO0OUT_C+ALTERNATE     for the crypto out channel          - alternate structure
    - 47 or Flash_C+ALTERNATE          for the Flash channel               - alternate structure
    - 49 or AFEDATAFIFO_C+ALTERNATE    for the AFE DATA FIFO channel      - alternate structure
    - 50 to 55 or SOFTDMA0_C+ALTERNATE to SOFTDMA5_C+ALTERNATE for Software DMA - alternate structure
   @return Pointer to the specific structure descriptor, or zero when .

**/

DmaDesc * Dma_GetDescriptor(unsigned int iChan)
{
   if (iChan < CCD_SIZE*2)
   {
      return &(dmaChanDesc[iChan]);
   }
   else
      return 0x0;
}

/**
	@brief int DmaBase(void)
			========== Sets the Address of DMA Data base pointer.
	@return 1.
**/
int DmaBase(void)
{
   volatile unsigned int uiBasPtr = 0;

   memset(dmaChanDesc,0x0,sizeof(dmaChanDesc));       // Clear all the DMA descriptors (individual blocks will update their  descriptors
   uiBasPtr = (unsigned int)&dmaChanDesc;             // Setup the DMA base pointer.
   pADI_DMA0->CFG = 1;                              // Enable DMA controller
   pADI_DMA0->PDBPTR = uiBasPtr;
   return 1;
}

/**
   @brief int DmaSet(int iMask, int iEnable, int iAlt, int iPriority)
         ========== Controls Mask, Primary Enable, Alternate enable and priority enable bits
   @param iMask :{0|SPI1TX_B|SPI1RX_B|SPI0TX_B|SPI0RX_B|SPI1TX_B|SPI1RX_B|UART0TX_B|UART0RX_B
                  |I2C0STX_B|I2C0SRX_B|I2C0M_B|CRYPTO0IN_B|CRYPTO0OUT_B|Flash_B
                  |AFEDATAFIFO_B|SOFTDMA0_B|SOFTDMA1_B|SOFTDMA2_B|SOFTDMA3_B|SOFTDMA4_B|SOFTDMA5_B}
      - Select a combination of peripheral mask bits to mask DMA requests.
      - 0 = to Mask no DMA source(No effect).
      - 0x1 or SPI1TX_B       to mask SPI1 Transmit
      - 0x2 or SPI1RX_B       to mask SPI1 Receive
        ... or ......_B       to mask ......
      - 0x800000 or SOFTDMA5_B  to mask Software DMA 5

   @param iEnable :{0|SPI1TX_B|SPI1RX_B|SPI0TX_B|SPI0RX_B|SPI1TX_B|SPI1RX_B|UART0TX_B|UART0RX_B
                  |I2C0STX_B|I2C0SRX_B|I2C0M_B|CRYPTO0IN_B|CRYPTO0OUT_B|Flash_B
                  |AFEDATAFIFO_B|SOFTDMA0_B|SOFTDMA1_B|SOFTDMA2_B|SOFTDMA3_B|SOFTDMA4_B|SOFTDMA5_B}
      - Select a combination of peripheral enable bits to be set.
      - 0 = to enable no DMA source
      - 0x1 or SPI1TX_B       to enable SPI1 Transmit
      - 0x2 or SPI1RX_B       to enable SPI1 Receive
        ... or ......_B       to enable ......
      - 0x800000 or SOFTDMA7_B  to enable Software DMA 7
   @param iAlt :{0|SPI1TX_B|SPI1RX_B|SPI0TX_B|SPI0RX_B|SPI1TX_B|SPI1RX_B|UART0TX_B|UART0RX_B
                  |I2C0STX_B|I2C0SRX_B|I2C0M_B|CRYPTO0IN_B|CRYPTO0OUT_B|Flash_B
                  |AFEDATAFIFO_B|SOFTDMA0_B|SOFTDMA1_B|SOFTDMA2_B|SOFTDMA3_B|SOFTDMA4_B|SOFTDMA5_B}
      - Select a combination of peripheral alternate bits to be set.
      - 0 = to set alternate no DMA source
      - 0x1 or SPI1TX_B       to Selects the alternate data structure for channel SPI1 Transmit
      - 0x2 or SPI1RX_B       to Selects the alternate data structure for channel alternate SPI1 Receive
        ... or ......_B       to Selects the alternate data structure for channel alternate ......
      - 0x800000 or SOFTDMA5_B  to Selects the alternate data structure for channel alternate Software DMA 5
   @param iPriority :{0|SPI1TX_B|SPI1RX_B|SPI0TX_B|SPI0RX_B|SPI1TX_B|SPI1RX_B|UART0TX_B|UART0RX_B
                  |I2C0STX_B|I2C0SRX_B|I2C0M_B|CRYPTO0IN_B|CRYPTO0OUT_B|Flash_B
                  |AFEDATAFIFO_B|SOFTDMA0_B|SOFTDMA1_B|SOFTDMA2_B|SOFTDMA3_B|SOFTDMA4_B|SOFTDMA5_B}
      - Select a combination of peripheral priority bits to be set.
      - 0 to leave priority level of all channels as they are
      - 0x1 or SPI1TX_B          Channel SPI1 Transmit uses the high priority level.
      - 0x2 or SPI1RX_B          Channel SPI1 Receive uses the high priority level.
        ... or ......_B          Channel ..... uses the high priority level.
      - 0x800000 or SOFTDMA5_B   Channel Software DMA 5 uses the high priority level.
   @return 1.
**/
int DmaSet(int iMask, int iEnable, int iAlt, int iPriority)
{
   pADI_DMA0->RMSK_SET = iMask;
   pADI_DMA0->EN_SET = iEnable;
   pADI_DMA0->ALT_SET = iAlt;
   pADI_DMA0->PRI_SET = iPriority;
   return 1;
}

/**
   @brief int DmaClr(int iMask, int iDisable, int iAlt, int iPriority)
			========== Controls Mask, Primary Enable, Alternate enable and priority Clear bits
   @param iMask :{0|SPI1TX_B|SPI1RX_B|SPI0TX_B|SPI0RX_B|SPI1TX_B|SPI1RX_B|UART0TX_B|UART0RX_B
                  |I2C0STX_B|I2C0SRX_B|I2C0M_B|CRYPTO0IN_B|CRYPTO0OUT_B|Flash_B
                  |AFEDATAFIFO_B|SOFTDMA0_B|SOFTDMA1_B|SOFTDMA2_B|SOFTDMA3_B|SOFTDMA4_B|SOFTDMA5_B}
      - Select a combination of peripheral mask bits to mask DMA requests.
      - 0 = to Mask no DMA source(No effect).
      - 0x1 or SPI1TX_B       to disable mask SPI1 Transmit
      - 0x2 or SPI1RX_B       to disable  mask SPI1 Receive
        ... or ......_B       to disable  mask ......
      - 0x800000 or SOFTDMA5_B  to disable  mask Software DMA 5

   @param iEnable :{0|SPI1TX_B|SPI1RX_B|SPI0TX_B|SPI0RX_B|SPI1TX_B|SPI1RX_B|UART0TX_B|UART0RX_B
                  |I2C0STX_B|I2C0SRX_B|I2C0M_B|CRYPTO0IN_B|CRYPTO0OUT_B|Flash_B
                  |AFEDATAFIFO_B|SOFTDMA0_B|SOFTDMA1_B|SOFTDMA2_B|SOFTDMA3_B|SOFTDMA4_B|SOFTDMA5_B}
      - Select a combination of peripheral enable bits to be set.
      - 0 = to enable no DMA source
      - 0x1 or SPI1TX_B       to disable SPI1 Transmit
      - 0x2 or SPI1RX_B       to disable SPI1 Receive
        ... or ......_B       to disable ......
      - 0x800000 or SOFTDMA5_B  to disable Software DMA 5
   @param iAlt :{0|SPI1TX_B|SPI1RX_B|SPI0TX_B|SPI0RX_B|SPI1TX_B|SPI1RX_B|UART0TX_B|UART0RX_B
                  |I2C0STX_B|I2C0SRX_B|I2C0M_B|CRYPTO0IN_B|CRYPTO0OUT_B|Flash_B
                  |AFEDATAFIFO_B|SOFTDMA0_B|SOFTDMA1_B|SOFTDMA2_B|SOFTDMA3_B|SOFTDMA4_B|SOFTDMA5_B}
      - Select a combination of peripheral alternate bits to be set.
      - 0 = to set alternate no DMA source
      - 0x1 or SPI1TX_B       to Selects the primary data structure for channel SPI1 Transmit
      - 0x2 or SPI1RX_B       to Selects the primary data structure for channel alternate SPI1 Receive
        ... or ......_B       to Selects the primary data structure for channel alternate ......
      - 0x800000 or SOFTDMA5_B  to Selects the alternate data structure for channel alternate Software DMA 5
   @param iPriority :{0|SPI1TX_B|SPI1RX_B|SPI0TX_B|SPI0RX_B|SPI1TX_B|SPI1RX_B|UART0TX_B|UART0RX_B
                  |I2C0STX_B|I2C0SRX_B|I2C0M_B|CRYPTO0IN_B|CRYPTO0OUT_B|Flash_B
                  |AFEDATAFIFO_B|SOFTDMA0_B|SOFTDMA1_B|SOFTDMA2_B|SOFTDMA3_B|SOFTDMA4_B|SOFTDMA5_B}
      - Select a combination of peripheral priority bits to be set.
      - 0 to leave priority level of all channels as they are
      - 0x1 or SPI1TX_B          Channel SPI1 Transmit uses the default priority level.
      - 0x2 or SPI1RX_B          Channel SPI1 Receive uses the default priority level.
        ... or ......_B          Channel ..... uses the high default level.
      - 0x800000 or SOFTDMA5_B   Channel Software DMA 5 uses the default priority level.
   @return 1.
**/
int DmaClr(int iMask, int iDisable, int iAlt, int iPriority)
{
   pADI_DMA0->RMSK_CLR = iMask;
   pADI_DMA0->EN_CLR = iDisable;
   pADI_DMA0->ALT_CLR = iAlt;
   pADI_DMA0->PRI_CLR = iPriority;
   return 1;
}

/**
   @brief int DmaSta(void)
      ========== Reads the status of the DMA controller.
   @return value of DMASTA	/n
      bit 0 - enabled	/n
//      bits [7:4]--this field is not available for ADuCM3029
//      - 0 = Idle
//      - 1 = Reading channel controller data
//      - 2 = Reading source data end pointer
//      - 3 = Reading destination end pointer
//      - 4 = Reading source data
//      - 5 = Writing destination data
//      - 6 = Waiting for DMArequest to clear
//      - 7 = Writing channel controller data
//      - 8 = Stalled
//      - 9 = Done
//      - 10 = Scatter gather transition.
      bits [20:16]
      - number of DMA channels available -1

**/
int DmaSta(void)
{
   return pADI_DMA0->STAT;
}

/**
   @brief int DmaErr(int iErrClr)
         ========== Reads and optionally clears DMA error bit.
   @param iErrClr :{DMA_ERR_RD,DMA_ERR_CLR}
      - 0 or DMA_ERR_RD only reads error bit.
      - 1 or DMA_ERR_CLR reads then clears error bit.
   @return value of DMA_ERR_CLR
      - 0 - flags no error
      - none zero - flags error.
**/
int DmaErr(int iErrClr)
{
   int reg;
   reg = pADI_DMA0->ERR_CLR;
   if(iErrClr)
         pADI_DMA0->ERR_CLR = reg; //clear error status
   return reg;
}


/**
   @brief int DmaPeripheralStructSetup(int iChan, int iCfg)
         ==========Sets up DMA config structure for the required channel

   @param iChan :{SPI1TX_C,SPI1RX_C,SPORT0A_C,SPORT0B_C,SPI0TX_C,SPI0RX_C,SPI1TX_C,
         SPI1RX_C,UART0TX_C,UART0RX_C,I2C0STX_C,I2C0SRX_C,I2C0M_C,CRYPTO0IN_C,
         CRYPTO0OUT_C,Flash_C,AFEDATAFIFO_C,SOFTDMA0_C,SOFTDMA1_C,SOFTDMA2_C,SOFTDMA3_C,
         SOFTDMA4_C,SOFTDMA5_C,SOFTDMA6_C,SOFTDMA7_C,SPI1TX_C+ALTERNATE,
         SPI1RX_C+ALTERNATE,SPORT0A_C+ALTERNATE,SPORT0B_C+ALTERNATE,
         SPI0TX_C+ALTERNATE,SPI0RX_C+ALTERNATE,SPI1TX_C+ALTERNATE,
         SPI1RX_C+ALTERNATE,UART0TX_C+ALTERNATE,UART0RX_C+ALTERNATE,
         I2C0STX_C+ALTERNATE,I2C0SRX_C+ALTERNATE,I2C0M_C+ALTERNATE,
         CRYPTO0IN_C+ALTERNATE,CRYPTO0OUT_C+ALTERNATE,Flash_C+ALTERNATE,AFEDATAFIFO_C+ALTERNATE,
         SOFTDMA0_C+ALTERNATE,SOFTDMA1_C+ALTERNATE,SOFTDMA2_C+ALTERNATE,
         SOFTDMA3_C+ALTERNATE,SOFTDMA4_C+ALTERNATE,SOFTDMA5_C+ALTERNATE,
         SOFTDMA6_C+ALTERNATE,SOFTDMA7_C+ALTERNATE}
    - 0 or SPI1TX_C        for the SPI1 Transmit channel       - primary structure
    - 1 or SPI1RX_C        for the SPI1 Receive channel        - primary structure
    - 2 or SPORT0A_C       for the SPORT0A channel             - primary structure
    - 3 or SPORT0B_C       for the SPORT0B channel             - primary structure
    - 4 or SPI0TX_C        for the SPI0 Transmit channel       - primary structure
    - 5 or SPI0RX_C        for the SPI0 Receive channel        - primary structure
    - 6 or SPI1TX_C        for the SPI1 transmit channel       - primary structure
    - 7 or SPI1RX_C        for the SPI1 receive channel        - primary structure
    - 8 or UART0TX_C       for the UART Transmit channel       - primary structure
    - 9 or UART0RX_C       for the UART Receive channel        - primary structure
    - 10 or I2C0STX_C      for the I2C0 Slave transmit channel - primary structure
    - 11 or I2C0SRX_C      for the I2C0 Slave receive channel  - primary structure
    - 12 or I2C0M_C        for the I2C0 Master channel         - primary structure
    - 13 or CRYPTO0IN_C    for the crypto in channel           - primary structure
    - 14 or CRYPTO0OUT_C   for the crypto out channel          - primary structure
    - 15 or Flash_C        for the Flash channel               - primary structure
    - 17 or AFEDATAFIFO_C   for the AFE DATA FIFO channel      - primary structure
    - 18 to 23 or SOFTDMA0_C to SOFTDMA5_C for Software DMA    - primary structure

    - 32 or SPI1TX_C+ALTERNATE         for the SPI1 Transmit channel       - alternate structure
    - 33 or SPI1RX_C+ALTERNATE         for the SPI1 Receive channel        - alternate structure
    - 34 or SPORT0A_C+ALTERNATE        for the SPORT0A channel             - alternate structure
    - 35 or SPORT0B_C+ALTERNATE        for the SPORT0B channel             - alternate structure
    - 36 or SPI0TX_C+ALTERNATE         for the SPI0 Transmit channel       - alternate structure
    - 37 or SPI0RX_C+ALTERNATE         for the SPI0 Receive channel        - alternate structure
    - 38 or SPI1TX_C+ALTERNATE         for the SPI1 transmit channel       - alternate structure
    - 39 or SPI1RX_C+ALTERNATE         for the SPI1 receive channel        - alternate structure
    - 40 or UART0TX_C+ALTERNATE        for the UART Transmit channel       - alternate structure
    - 41 or UART0RX_C+ALTERNATE        for the UART Receive channel        - alternate structure
    - 42 or I2C0STX_C+ALTERNATE        for the I2C0 Slave transmit channel - alternate structure
    - 43 or I2C0SRX_C+ALTERNATE        for the I2C0 Slave receive channel  - alternate structure
    - 44 or I2C0M_C+ALTERNATE          for the I2C0 Master channel         - alternate structure
    - 45 or CRYPTO0IN_C+ALTERNATE      for the crypto in channel           - alternate structure
    - 46 or CRYPTO0OUT_C+ALTERNATE     for the crypto out channel          - alternate structure
    - 47 or Flash_C+ALTERNATE          for the Flash channel               - alternate structure
    - 49 or AFEDATAFIFO_C+ALTERNATE    for the AFE DATA FIFO channel      - alternate structure
    - 50 to 55 or SOFTDMA0_C+ALTERNATE to SOFTDMA5_C+ALTERNATE for Software DMA - alternate structure
   @param iCfg :{DMA_DSTINC_BYTE|DMA_DSTINC_HWORD|DMA_DSTINC_WORD|DMA_DSTINC_NO|
                 DMA_SRCINC_BYTE|DMA_SRCINC_HWORD|DMA_SRCINC_WORD|DMA_SRCINC_NO|
                 DMA_SIZE_BYTE|DMA_SIZE_HWORD|DMA_SIZE_WORD}
   - Choose one of DMA_DSTINC_BYTE,DMA_DSTINC_HWORD,DMA_DSTINC_WORD,DMA_DSTINC_NO for destination address increment
   - Choose one of DMA_SRCINC_BYTE,DMA_SRCINC_HWORD,DMA_SRCINC_WORD,DMA_SRCINC_NO for source address increment
   - Choose one of DMA_SIZE_BYTE (byte),DMA_SIZE_HWORD (half-word),DMA_SIZE_WORD(word) for source data size

   @return 1:

**/
int DmaPeripheralStructSetup(int iChan, int iCfg)
{
	DmaDesc *Desc;

   Desc = Dma_GetDescriptor(iChan);
   memset(Desc,0,sizeof(Desc));
    // Common configuration of all the descriptors used here
   Desc->ctrlCfg.Bits.cycle_ctrl       = (iCfg & 0x7);
   Desc->ctrlCfg.Bits.r_power          = 0;
   Desc->ctrlCfg.Bits.src_size         = ((iCfg & 0x3000000)>>24);

   Desc->ctrlCfg.Bits.n_minus_1        = 0;
   Desc->ctrlCfg.Bits.src_inc          = ((iCfg & 0xC000000)>>26);
   Desc->ctrlCfg.Bits.dst_inc          = ((iCfg & 0xC0000000)>>30);

   //*Dma_GetDescriptor(iChan) = Desc;     // structure

   return 1;
}

/**
   @brief int DmaStructPtrOutSetup(int iChan, int iNumVals, const unsigned char *pucTX_DMA)
            ==========For DMA operations where the destination is fixed (peripheral register is fixed)
   @param iChan :{SPI1TX_C,SPORT0A_C,SPORT0B_C,SPI0TX_C,SPI1TX_C,
         UART0TX_C,I2C0STX_C,I2C0M_C,CRYPTO0IN_C,
         Flash_C,SPI1TX_C+ALTERNATE,SPORT0A_C+ALTERNATE,SPORT0B_C+ALTERNATE,
         SPI0TX_C+ALTERNATE,SPI1TX_C+ALTERNATE,UART0TX_C+ALTERNATE,
         I2C0STX_C+ALTERNATE,I2C0M_C+ALTERNATE,CRYPTO0IN_C+ALTERNATE,Flash_C+ALTERNATE}
    - 0 or SPI1TX_C        for the SPI1 Transmit channel       - primary structure
    - 2 or SPORT0A_C       for the SPORT0A channel             - primary structure
    - 3 or SPORT0B_C       for the SPORT0B channel             - primary structure
    - 4 or SPI0TX_C        for the SPI0 Transmit channel       - primary
    - 6 or SPI1TX_C        for the SPI1 transmit channel       - primary structure
    - 8 or UART0TX_C       for the UART Transmit channel       - primary structure
    - 10 or I2C0STX_C      for the I2C0 Slave transmit channel - primary structure
    - 12 or I2C0M_C        for the I2C0 Master channel         - primary structure
    - 13 or CRYPTO0IN_C    for the crypto in channel           - primary structure
    - 15 or Flash_C        for the Flash channel               - primary
    - 17 or AFEDATAFIFO_C   for the AFE DATA FIFO channel      - primary structure

    - 32 or SPI1TX_C+ALTERNATE         for the SPI1 Transmit channel       - alternate structure
    - 34 or SPORT0A_C+ALTERNATE        for the SPORT0A channel             - alternate structure
    - 35 or SPORT0B_C+ALTERNATE        for the SPORT0B channel             - alternate structure
    - 36 or SPI0TX_C+ALTERNATE         for the SPI0 Transmit channel       - alternate structure
    - 38 or SPI1TX_C+ALTERNATE         for the SPI1 transmit channel       - alternate structure
    - 40 or UART0TX_C+ALTERNATE        for the UART Transmit channel       - alternate structure
    - 42 or I2C0STX_C+ALTERNATE        for the I2C0 Slave transmit channel - alternate
    - 44 or I2C0M_C+ALTERNATE          for the I2C0 Master channel         - alternate structure
    - 45 or CRYPTO0IN_C+ALTERNATE      for the crypto in channel           - alternate structure
    - 47 or Flash_C+ALTERNATE          for the Flash channel               - alternate structure
    - 49 or AFEDATAFIFO_C+ALTERNATE    for the AFE DATA FIFO channel      - alternate structure
   @param iNumVals :{1-1024}
   - 1 to 1024. Number of values to transfer
   @param *pucTX_DMA :{0-0xFFFFFFFF}
   - Pass Source pointer  address for DMA transfers
   @return 1 if suceeded or 0 if it fails
   @warning DmaPeripheralStructSetup() must be called first

**/
int DmaStructPtrOutSetup(int iChan, int iNumVals, const unsigned char *pucTX_DMA)
{
   int iByt = 0;  // number of bytes per dma value to be transmitted
   int temp;

   temp = iChan;
   if(temp > 31)
   {//alternate channel
      temp = temp - 31;
   }

   if(temp == SPI1TX_C)
      dmaChanDesc[iChan].destEndPtr = (unsigned int)&pADI_SPI1->TX;
   else if(temp == SPORT0A_C)
      dmaChanDesc[iChan].destEndPtr = 0;///@todo Does M355 have SPORTA ?
   else if(temp == SPORT0B_C)
      dmaChanDesc[iChan].destEndPtr = 0;///@todo Does M355 have SPORTA ?
   else if(temp == SPI0TX_C)
      dmaChanDesc[iChan].destEndPtr = (unsigned int)&pADI_SPI0->TX;
   else if(temp == SPI1TX_C)
      dmaChanDesc[iChan].destEndPtr = 0;///@todo Does M355 have SPI1 ?
   else if(temp == UART0TX_C)
      dmaChanDesc[iChan].destEndPtr = (unsigned int)&pADI_UART0->COMTX;
   else if(temp == I2C0STX_C)
      dmaChanDesc[iChan].destEndPtr = (unsigned int)&pADI_I2C0->STX;
   else if(temp == I2C0M_C)
      dmaChanDesc[iChan].destEndPtr = (unsigned int)(&pADI_I2C0->MTX);
   else if(temp == CRYPTO0IN_C)
      dmaChanDesc[iChan].destEndPtr = 0;///@todo Does M355 have CRYPTO ?
   else if(temp == Flash_C)
   {
      dmaChanDesc[iChan].destEndPtr = (unsigned int)&pADI_FLCC0->KH_DATA1;
      dmaChanDesc[iChan].ctrlCfg.Bits.r_power = 1;
   }
   else
      return 0;//channel number error
   switch(dmaChanDesc[iChan].ctrlCfg.Bits.src_size)
   {
      case  SIZE_BYTE:
         iByt = 1;
         break;
      case SIZE_HWORD:
         iByt = 2;
         break;
      case SIZE_WORD:
         iByt = 4;
         break;
      default:
         return 0;
   }
   dmaChanDesc[iChan].srcEndPtr = (unsigned int)(pucTX_DMA+ iByt*(iNumVals - 0x1));///@todo : swap byte order?
   return 1;
}
/**
   @brief int DmaStructPtrInSetup(int iChan, int iNumVals, unsigned char *pucRX_DMA);
	 			==========For DMA operations where the source is fixed (peripheral register is fixed)
   @param iChan :{SPI1RX_C,SPORT0A_C,SPORT0B_C,SPI0RX_C,SPI1RX_C,UART0RX_C,I2C0SRX_C,I2C0M_C,
         CRYPTO0OUT_C,SPI1RX_C+ALTERNATE,SPORT0A_C+ALTERNATE,SPORT0B_C+ALTERNATE,
         SPI0RX_C+ALTERNATE,SPI1RX_C+ALTERNATE,UART0RX_C+ALTERNATE,
         I2C0SRX_C+ALTERNATE,I2C0M_C+ALTERNATE,CRYPTO0OUT_C+ALTERNATE}
    - 1 or SPI1RX_C        for the SPI1 Receive channel        - primary structure
    - 2 or SPORT0A_C       for the SPORT0A channel             - primary structure
    - 3 or SPORT0B_C       for the SPORT0B channel             - primary structure
    - 5 or SPI0RX_C        for the SPI0 Receive channel        - primary structure
    - 7 or SPI1RX_C        for the SPI1 receive channel        - primary structure
    - 9 or UART0RX_C       for the UART Receive channel        - primary
    - 11 or I2C0SRX_C      for the I2C0 Slave receive channel  - primary structure
    - 12 or I2C0M_C        for the I2C0 Master channel         - primary structure
    - 14 or CRYPTO0OUT_C   for the crypto out channel          - primary structure
    - 17 or AFEDATAFIFO_C   for the AFE DATA FIFO channel      - primary structure

    - 33 or SPI1RX_C+ALTERNATE         for the SPI1 Receive channel        - alternate structure
    - 34 or SPORT0A_C+ALTERNATE        for the SPORT0A channel             - alternate structure
    - 35 or SPORT0B_C+ALTERNATE        for the SPORT0B channel             - alternate structure
    - 37 or SPI0RX_C+ALTERNATE         for the SPI0 Receive channel        - alternate structure
    - 39 or SPI1RX_C+ALTERNATE         for the SPI1 receive channel        - alternate
    - 41 or UART0RX_C+ALTERNATE        for the UART Receive channel        - alternate structure
    - 43 or I2C0SRX_C+ALTERNATE        for the I2C0 Slave receive channel  - alternate structure
    - 44 or I2C0M_C+ALTERNATE          for the I2C0 Master channel         - alternate
    - 46 or CRYPTO0OUT_C+ALTERNATE     for the crypto out channel          - alternate
    - 49 or AFEDATAFIFO_C+ALTERNATE    for the AFE DATA FIFO channel      - alternate structure
   @param iNumVals :{1-1024}
    - 1 to 1024. Number of values to transfer
   @param *pucRX_DMA :{0-0xFFFFFFFF}
    - Pass pointer to destination address for DMA transfers
   @return 1 if suceeded or 0 if it fails
   @warning DmaPeripheralStructSetup() must be called first

**/
int DmaStructPtrInSetup(int iChan, int iNumVals, unsigned char *pucRX_DMA)
{
   int iByt = 0;  // number of bytes per dma value to be transmitted
   int temp;

   temp = iChan;
   if(temp >= 32)
   {//alternate channel
      temp = temp - 32;
   }
   if(temp == SPI1RX_C)
      dmaChanDesc[iChan].srcEndPtr = (unsigned int)&pADI_SPI1->RX;
   else if(temp == SPORT0A_C)
      dmaChanDesc[iChan].srcEndPtr = 0;///@todo Does M355 have SPORTA ?
   else if(temp == SPORT0B_C)
      dmaChanDesc[iChan].srcEndPtr = 0;///@todo Does M355 have SPORTA ?
   else if(temp == SPI0RX_C)
      dmaChanDesc[iChan].srcEndPtr = (unsigned int)&pADI_SPI0->RX;
   else if(temp == SPI1RX_C)
      dmaChanDesc[iChan].srcEndPtr = 0;///@todo Does M355 have SPI1 ?
   else if(temp == UART0RX_C)
      dmaChanDesc[iChan].srcEndPtr = (unsigned int)&pADI_UART0->COMRX;
   else if(temp == I2C0SRX_C)
      dmaChanDesc[iChan].srcEndPtr = (unsigned int)&pADI_I2C0->SRX;
   else if(temp == I2C0M_C)
      dmaChanDesc[iChan].srcEndPtr = (unsigned int)(&pADI_I2C0->MRX);
   else if(temp == CRYPTO0OUT_C)
      dmaChanDesc[iChan].srcEndPtr = 0;///@todo Does M355 have CRYPTO ?
   else if(temp == AFEDATAFIFO_C)
      //dmaChanDesc[iChan].srcEndPtr = (unsigned int)(&pADI_AFE->DATAFIFORD);
      dmaChanDesc[iChan].srcEndPtr = (unsigned int)(0x400C206C);
   else
      return 0;//channel number error

   switch(dmaChanDesc[iChan].ctrlCfg.Bits.src_size)
   {
      case  SIZE_BYTE:
         iByt = 1;
         break;
      case SIZE_HWORD:
         iByt = 2;
         break;
      case SIZE_WORD:
         iByt = 4;
         break;
      default:
         return 0;
   }
   if(iNumVals>1024) iNumVals = 1024;
   dmaChanDesc[iChan].destEndPtr = (unsigned int)(pucRX_DMA+ iByt*(iNumVals - 0x1));///@todo : swap byte order?
   return 1;
}
/**
   @brief int DmaGo(unsigned int iChan, int iNumx, int iCfg)
            ==========Used to re-enable DMA config structure
   @param iChan :{SPI1TX_C,SPI1RX_C,SPORT0A_C,SPORT0B_C,SPI0TX_C,SPI0RX_C,SPI1TX_C,
         SPI1RX_C,UART0TX_C,UART0RX_C,I2C0STX_C,I2C0SRX_C,I2C0M_C,CRYPTO0IN_C,
         CRYPTO0OUT_C,Flash_C,AFEDATAFIFO_C,SOFTDMA0_C,SOFTDMA1_C,
         SOFTDMA2_C,SOFTDMA3_C,SOFTDMA4_C,SOFTDMA5_C,SPI1TX_C+ALTERNATE,
         SPI1RX_C+ALTERNATE,SPORT0A_C+ALTERNATE,SPORT0B_C+ALTERNATE,
         SPI0TX_C+ALTERNATE,SPI0RX_C+ALTERNATE,SPI1TX_C+ALTERNATE,
         SPI1RX_C+ALTERNATE,UART0TX_C+ALTERNATE,UART0RX_C+ALTERNATE,
         I2C0STX_C+ALTERNATE,I2C0SRX_C+ALTERNATE,I2C0M_C+ALTERNATE,
         CRYPTO0IN_C+ALTERNATE,CRYPTO0OUT_C+ALTERNATE,Flash_C+ALTERNATE,
         AFEDATAFIFO_C+ALTERNATE,SOFTDMA0_C+ALTERNATE,
         SOFTDMA1_C+ALTERNATE,SOFTDMA2_C+ALTERNATE,SOFTDMA3_C+ALTERNATE,
         SOFTDMA4_C+ALTERNATE,SOFTDMA5_C+ALTERNATE}
    - 0 or SPI1TX_C        for the SPI1 Transmit channel       - primary structure
    - 1 or SPI1RX_C        for the SPI1 Receive channel        - primary structure
    - 2 or SPORT0A_C       for the SPORT0A channel             - primary structure
    - 3 or SPORT0B_C       for the SPORT0B channel             - primary structure
    - 4 or SPI0TX_C        for the SPI0 Transmit channel       - primary structure
    - 5 or SPI0RX_C        for the SPI0 Receive channel        - primary structure
    - 6 or SPI1TX_C        for the SPI1 transmit channel       - primary structure
    - 7 or SPI1RX_C        for the SPI1 receive channel        - primary structure
    - 8 or UART0TX_C       for the UART Transmit channel       - primary structure
    - 9 or UART0RX_C       for the UART Receive channel        - primary structure
    - 10 or I2C0STX_C      for the I2C0 Slave transmit channel - primary structure
    - 11 or I2C0SRX_C      for the I2C0 Slave receive channel  - primary structure
    - 12 or I2C0M_C        for the I2C0 Master channel         - primary structure
    - 13 or CRYPTO0IN_C    for the crypto in channel           - primary structure
    - 14 or CRYPTO0OUT_C   for the crypto out channel          - primary structure
    - 15 or Flash_C        for the Flash channel               - primary structure
    - 17 or AFEDATAFIFO_C   for the AFE DATA FIFO channel      - primary structure
    - 18 to 23 or SOFTDMA0_C to SOFTDMA5_C for Software DMA    - primary structure

    - 32 or SPI1TX_C+ALTERNATE         for the SPI1 Transmit channel       - alternate structure
    - 33 or SPI1RX_C+ALTERNATE         for the SPI1 Receive channel        - alternate structure
    - 34 or SPORT0A_C+ALTERNATE        for the SPORT0A channel             - alternate structure
    - 35 or SPORT0B_C+ALTERNATE        for the SPORT0B channel             - alternate structure
    - 36 or SPI0TX_C+ALTERNATE         for the SPI0 Transmit channel       - alternate structure
    - 37 or SPI0RX_C+ALTERNATE         for the SPI0 Receive channel        - alternate structure
    - 38 or SPI1TX_C+ALTERNATE         for the SPI1 transmit channel       - alternate structure
    - 39 or SPI1RX_C+ALTERNATE         for the SPI1 receive channel        - alternate structure
    - 40 or UART0TX_C+ALTERNATE        for the UART Transmit channel       - alternate structure
    - 41 or UART0RX_C+ALTERNATE        for the UART Receive channel        - alternate structure
    - 42 or I2C0STX_C+ALTERNATE        for the I2C0 Slave transmit channel - alternate structure
    - 43 or I2C0SRX_C+ALTERNATE        for the I2C0 Slave receive channel  - alternate structure
    - 44 or I2C0M_C+ALTERNATE          for the I2C0 Master channel         - alternate structure
    - 45 or CRYPTO0IN_C+ALTERNATE      for the crypto in channel           - alternate structure
    - 46 or CRYPTO0OUT_C+ALTERNATE     for the crypto out channel          - alternate structure
    - 47 or Flash_C+ALTERNATE          for the Flash channel               - alternate structure
    - 49 or AFEDATAFIFO_C+ALTERNATE    for the AFE DATA FIFO channel      - alternate structure
    - 50 to 55 or SOFTDMA0_C+ALTERNATE to SOFTDMA5_C+ALTERNATE for Software DMA - alternate structure
   @param iCfg :{DMA_STOP|DMA_BASIC|DMA_AUTO|DMA_PING|DMA_PSG_PRI|DMA_PSG_ALT}
    - Choose one of DMA_STOP,DMA_BASIC,DMA_AUTO,DMA_PING,DMA_PSG_PRI,DMA_PSG_ALT
   @param iNumx :{1-1024}
    - Number of values to transfer
 @return 1 if suceeded or 0 if it fails

**/
int DmaGo(unsigned int iChan, int iNumx, int iCfg)
{
   if((iChan > 55) || ((iChan > 23) && (iChan < 32)))
      return 0;

	dmaChanDesc[iChan].ctrlCfg.Bits.cycle_ctrl       = (iCfg & 0x7);
	dmaChanDesc[iChan].ctrlCfg.Bits.n_minus_1        = iNumx - 0x1;
	return 1;
}

/**
   @brief void DataFifoCfg(uint32_t *poutdata,uint32_t number, uint32_t DataSrc)
          Configure Data FIFO and DMA controller to allow DMA transmit data
   @param poutdata:
      pointer of Data array
   @param number:
      number of Data
   @param DataSrc:{DATAFIFO_ADC,DATAFIFO_DFT,DATAFIFO_LPF,DATAFIFO_VAR,DATAFIFO_MEAN}
		- 0 or DATAFIFO_ADC to select the ADCDAT as the DATA FIFO Source
		- 0x4000 or DATAFIFO_DFT to select the DFTREAL and DFTIMAG as the DATA FIFO Source
		- 0x6000 or DATAFIFO_LPF to select the SINC2DAT as the DATA FIFO Source
		- 0x8000 or DATAFIFO_VAR to select the STATSVAR as the DATA FIFO Source
		- 0xA000 or DATAFIFO_MEAN to select the STATSMEAN register as the DATA FIFO Source
   @return none.
*/
void DataFifoCfg(uint32_t *poutdata,uint32_t number,uint32_t DataSrc)
{
   uint32_t reg;
   uint32_t remainNum = 0;

   DmaBase();
   DmaSet(0,AFEDATAFIFO_B,0,0);
   /*Enable Data FIFO DMA channel*/
   pADI_DMA0->EN_SET |= AFEDATAFIFO_B;
   /*Data FIFO channel configuration*/
   DmaPeripheralStructSetup(AFEDATAFIFO_C,DMA_DSTINC_WORD|DMA_SRCINC_NO|DMA_SIZE_WORD);

   if(number<=1024)  //basic mode
   {
      DmaStructPtrInSetup(AFEDATAFIFO_C,number,(uint8_t *)poutdata);
      DmaGo(AFEDATAFIFO_C,number,DMA_BASIC);
   }
   else  //ping-pong mode if transfer number greater than 1024
   {
      DmaStructPtrInSetup(AFEDATAFIFO_C,1024,(uint8_t *)poutdata);
      DmaPeripheralStructSetup(AFEDATAFIFO_C+ALTERNATE,DMA_DSTINC_WORD|DMA_SRCINC_NO|DMA_SIZE_WORD);
      DmaGo(AFEDATAFIFO_C,1024,DMA_PING);
      remainNum = number - 1024;
      if(remainNum<=1024)
      {
         DmaStructPtrInSetup(AFEDATAFIFO_C+ALTERNATE,remainNum,(uint8_t *)(poutdata+1024));
         DmaGo(AFEDATAFIFO_C+ALTERNATE,remainNum,DMA_PING);
      }
      else
      {
         DmaStructPtrInSetup(AFEDATAFIFO_C+ALTERNATE,1024,(uint8_t *)(poutdata+1024));
         DmaGo(AFEDATAFIFO_C+ALTERNATE,1024,DMA_PING);
      }
   }

   /*set Data source for data FIFO, Enable data FIFO DMA request, Enable Data FIFO*/
   reg = FIFOCON&(~BITM_AFE_FIFOCON_DATAFIFOSRCSEL);  //sinc3
   reg |= BITM_AFE_FIFOCON_DATAFIFOEN|BITM_AFE_FIFOCON_DATAFIFODMAREQEN|DataSrc;
   FIFOCON = reg;

   NVIC_EnableIRQ(DMA0_CH17_DONE_IRQn);
}

/**
   @brief uint8_t DataFifoECC(uint32_t data)
          check ECC for data recieved from data FIFO
   @param data:{}
		- data, the 32 bit data for ECC check
   @return {1,0}
      - 1, ECC check success
      - 0, ECC check fail
*/
uint8_t DataFifoECC(uint32_t data)
{
   uint8_t eccBit[7]={0};
   uint32_t eccMsk[7] = {0x014840ff,0x0124ff90,0x00ff0808,\
                                       0x0101a444,0x00f092a6,\
                                       0x001f7161,0x00820f1b};
   uint32_t tmp;
   uint8_t result = 0;
   for(int32_t bit=6;bit>=0;bit--)
   {
      tmp = data&eccMsk[bit];
      /*check parity*/
      for (uint32_t i=0;i<25;i++)
      {
         eccBit[bit] = eccBit[bit]^(tmp&0x00000001);
         tmp = tmp>>1;
      }
      result = (result<<1)|eccBit[bit];
   }
   data = data>>25;
   return result==(data);
}


/**@}*/


