/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#ifndef  DMALIB_H
#define  DMALIB_H

#include "ADuCM355.h"
#ifdef __cplusplus
extern "C"
{
#endif

#define FIFOCON (*((volatile uint32_t *)0x400C2008))
#define BITM_AFE_FIFOCON_DATAFIFOEN 0x00000800
#define BITM_AFE_FIFOCON_DATAFIFODMAREQEN 0x00001000

typedef struct
{
   unsigned int cycle_ctrl    :3;
   unsigned int   :1;
   unsigned int n_minus_1     :10;
   unsigned int r_power       :4;
   unsigned int   :3;
   unsigned int   :3;
   unsigned int src_size      :2;
   unsigned int src_inc       :2;
   unsigned int        :2;
   unsigned int dst_inc       :2;
} CtrlCfgBits;

// Define the structure of a DMA descriptor.
typedef struct dmaDesc
{
   unsigned int srcEndPtr;
   unsigned int destEndPtr;
   union
   {
      unsigned int   ctrlCfgVal;
      CtrlCfgBits    Bits;
   } ctrlCfg ;
   unsigned int reserved4Bytes;
} DmaDesc;

//Pointer to the base address of the primary data structure alignment consideration.
//In the base address,5 + log(2)M LSBs are reserved and must be written 0. M is number of channels.
#define DMACHAN_DSC_ALIGN 0x400
/* CCD allocation must be an integral power of two, i.e., 24 channels is allocated as 32 */
#define CCD_SIZE                       (32)

extern int DmaBase(void);
extern DmaDesc * Dma_GetDescriptor(unsigned int iChan);
extern int DmaSet(int iMask, int iEnable, int iAlt, int iPriority);
extern int DmaClr(int iMask, int iDisable, int iAlt, int iPriority);
extern int DmaSta(void);
extern int DmaErr(int iErrClr);

extern int AdcDmaReadSetup(int iType, int iCfg, int iNumVals, int *pucRX_DMA);
extern int AdcDmaWriteSetup(int iType, int iCfg, int iNumVals, int *pucTX_DMA);
extern int DacDmaWriteSetup(int iType, int iCfg, int iNumVals, int *pucTX_DMA);

extern int DmaPeripheralStructSetup(int iChan, int iCfg);
extern int DmaStructPtrOutSetup(int iChan, int iNumVals, const unsigned char *pucTX_DMA);
extern int DmaStructPtrInSetup(int iChan, int iNumVals, unsigned char *pucRX_DMA);
extern int DmaGo(unsigned int iChan, int iNumx, int iCfg);

extern void DataFifoCfg(uint32_t *poutdata,uint32_t number,uint32_t DataSrc);
extern uint8_t DataFifoECC(uint32_t data);

//DMA channel numbers.
#define	SPI1TX_C	      0
#define	SPI1RX_C	      1
#define	SPORT0A_C	   2
#define	SPORT0B_C	   3
#define	SPI0TX_C	      4
#define	SPI0RX_C	      5
#define	UART0TX_C	   8
#define	UART0RX_C	   9
#define	I2C0STX_C	   10
#define	I2C0SRX_C	   11
#define	I2C0M_C	      12
#define	CRYPTO0IN_C	   13
#define	CRYPTO0OUT_C	14
#define	Flash_C  	   15
#define	AFECMDFIFO_C     16
#define	AFEDATAFIFO_C     17
#define	SOFTDMA0_C     18
#define	SOFTDMA1_C     19
#define	SOFTDMA2_C     20
#define	SOFTDMA3_C     21
#define	SOFTDMA4_C     22
#define	SOFTDMA5_C     23

//DMA channel bit value.
#define	NONE	            0
#define	SPI1TX_B	         0x1
#define	SPI1RX_B	         0x2
#define	SPORT0A_B	      0x4
#define	SPORT0B_B	      0x8
#define	SPI0TX_B	         0x10
#define	SPI0RX_B	         0x20
#define	UART0TX_B	      0x100
#define	UART0RX_B	      0x200
#define	I2C0STX_B	      0x400
#define	I2C0SRX_B	      0x800
#define	I2C0M_B	         0x1000
#define	CRYPTO0IN_B	      0x2000
#define	CRYPTO0OUT_B	   0x4000
#define	Flash_B  	      0x8000
#define	AFECMDFIFO_B  	   0x10000
#define	AFEDATAFIFO_B  	   0x20000
#define	SOFTDMA0_B  	   0x40000
#define	SOFTDMA1_B  	   0x80000
#define	SOFTDMA2_B  	   0x100000
#define	SOFTDMA3_B  	   0x200000
#define	SOFTDMA4_B  	   0x400000
#define	SOFTDMA5_B  	   0x800000

//read or clear DMA error.
#define	DMA_ERR_RD		0
#define	DMA_ERR_CLR		1

//DMA type (Cycl_ctrl)
#define	DMA_STOP		0
#define	DMA_BASIC		1
#define	DMA_AUTO		2
#define	DMA_PING		3
#define	DMA_MSG_PRI		4
#define	DMA_MSG_ALT		5
#define	DMA_PSG_PRI		6
#define	DMA_PSG_ALT		7

//Bytes per transfer.
#define	DMA_SIZE_BYTE		 0
#define	DMA_SIZE_HWORD	 0x1000000
#define	DMA_SIZE_WORD		 0x2000000


//Destination Increment per transfer.
#define	DMA_DSTINC_BYTE		0
#define	DMA_DSTINC_HWORD	0x40000000
#define	DMA_DSTINC_WORD		0x80000000
#define	DMA_DSTINC_NO		  0xC0000000

//Source Increment per transfer.
#define	DMA_SRCINC_BYTE		0
#define	DMA_SRCINC_HWORD	0x4000000
#define	DMA_SRCINC_WORD		0x8000000
#define	DMA_SRCINC_NO		  0xC000000

#define iPrimary        0
#define ALTERNATE      CCD_SIZE

#define SIZE_BYTE    0
#define SIZE_HWORD   1
#define SIZE_WORD    2

#define DATAFIFO_ADC     0
#define DATAFIFO_DFT     0x4000
#define DATAFIFO_LPF     0x6000
#define DATAFIFO_VAR     0x8000
#define DATAFIFO_MEAN    0xA000

#ifdef __cplusplus
}
#endif

#endif   //#define DMALIB_H
