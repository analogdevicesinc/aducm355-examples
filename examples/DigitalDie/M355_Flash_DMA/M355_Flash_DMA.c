/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

/*
   Decription:
		- UART 57600
		- Using DMA to copy data from RAM to RAM and from RAM to FLASH. 
		- Uart send message to serial port to indicate if success or not.
		- Test will run once. Press reset button to run again.

**/

#include <stdio.h>

#include "DioLib.h"
#include "FeeLib.h"
#include "DmaLib.h"
#include "UrtLib.h"

#define DATA_SZ (64)

int flash_dma_done = 0;
int software_dma_done = 0;
unsigned int  uiRamDataSrc[DATA_SZ];
unsigned int  uiRamDataDes[DATA_SZ];
unsigned int uiAdr = 0x10000;//write data to this address of flash
unsigned int *pFlashData = (unsigned int *)0x10000;

void ClockInit(void);
void UartInit(void);
int SoftDMA_Test(void);
int FlashDMA_Test(void);

int main(void)
{
    int ret, ret2;
    pADI_AFEWDT->WDTCON &= (~BITM_AFEWDT_WDTCON_EN);

    for(uint32_t i = 0; i < 500000; i++);

    ClockInit();
    UartInit();
    for(uint8_t i = 0; i < DATA_SZ; i++)
    {
        uiRamDataSrc[i] = 0x12345600 + i;
        uiRamDataDes[i] = 0;//clear
    }
    DmaBase();//Init data base pointer of DMA controller
    ret = SoftDMA_Test();
    if(ret)
        printf("Software DMA test success\r\n");
    else
        printf("Software DMA test fail\r\n");


    ret2 = FlashDMA_Test();
    if(ret2)
        printf("Flash DMA test success\r\n");
    else
        printf("Flash DMA test fail\r\n");

    while(1)
    {

    }
}

void ClockInit(void)
{
    pADI_CLKG0_OSC->KEY = 0xCB14;               // Select HFOSC as system clock.
    pADI_CLKG0_OSC->CTL = BITM_CLKG_OSC_CTL_HFOSCEN; // Int 32khz LFOSC selected in LFMUX
    pADI_CLKG0_CLK->CTL0 = 0;                   // PLCK,Flash reference clock,PLL=HFOSC
    pADI_CLKG0_CLK->CTL1 = 0;                   // ACLK,PCLK,HCLK divided by 1
    pADI_CLKG0_CLK->CTL5 = 0x00;                 // Enable clock to all peripherals - no clock gating
}

int SoftDMA_Test(void)
{
    DmaDesc Desc_SoftDMA;
    DmaDesc *pDesc;
    //For software DMA, manually init the descriptor
    Desc_SoftDMA.ctrlCfg.Bits.cycle_ctrl = 0;
    Desc_SoftDMA.ctrlCfg.Bits.src_size = 2;//size:word
    Desc_SoftDMA.ctrlCfg.Bits.dst_inc = 2;//increase word
    Desc_SoftDMA.ctrlCfg.Bits.src_inc = 2;//inc: word
    Desc_SoftDMA.ctrlCfg.Bits.n_minus_1 = 0;//64-1;
    Desc_SoftDMA.ctrlCfg.Bits.r_power = 0;
    Desc_SoftDMA.destEndPtr = (unsigned int)&uiRamDataDes[DATA_SZ - 1];
    Desc_SoftDMA.srcEndPtr = (unsigned int)&uiRamDataSrc[DATA_SZ - 1];
    Desc_SoftDMA.reserved4Bytes = 0;
    //Write the discriptor to system memroy. Here we use alternate channel
    pDesc = Dma_GetDescriptor(SOFTDMA0_C + ALTERNATE);
    if(pDesc == 0)
        return 0;
    *pDesc = Desc_SoftDMA;
    DmaSet(0, SOFTDMA0_B, SOFTDMA0_B, 0); //Enable Software DMA0 and set Alternate Bit
    DmaGo(SOFTDMA0_C + ALTERNATE, DATA_SZ, DMA_AUTO); //configure transfer size and DMA mode

    NVIC_EnableIRQ(DMA0_CH18_DONE_IRQn);//software 0 dma interrupt

    pADI_DMA0->SWREQ = SOFTDMA0_B;

    while(software_dma_done == 0);//wait dma complete

    //compare data
    for(uint8_t i = 0; i < DATA_SZ; i++)
    {
        if(uiRamDataDes[i] != (0x12345600 + i))
            return 0;//error
    }
    return 1;
}

int FlashDMA_Test(void)
{
    char flag_need_erase = 0;
    //compare data
    for(uint8_t i = 0; i < DATA_SZ; i++)
    {
        if(pFlashData[i] != 0xffffffff)
        {
            flag_need_erase = 1;
            break;
        }
    }
    if(flag_need_erase)
    {
        FeePErs(uiAdr);
        while(FeeSta() & 1);		/* wait if commond busy */
    }

    NVIC_EnableIRQ(DMA0_CH15_DONE_IRQn);//flash dma interrupt
    DmaPeripheralStructSetup(Flash_C, DMA_DSTINC_NO |
                             DMA_SRCINC_WORD | DMA_SIZE_WORD);                                 // Setup Flash DMA structure

    DmaStructPtrOutSetup(Flash_C, DATA_SZ, (unsigned char *)uiRamDataSrc); // Setup source/destination pointer fields
    DmaSet(0, Flash_B, 0, 0);                                            // Enable DMA structure for flash
    DmaGo(Flash_C, DATA_SZ, DMA_BASIC);                               // Enable Flash DMA structure

    pADI_FLCC0->KH_ADDR = (uint32_t)uiAdr;
    pADI_FLCC0->KEY = 0x676C7565;
    pADI_FLCC0->UCFG |= (BITM_FLCC_UCFG_KHDMAEN);                           // Enable Flash DMA mode, this starts the DMA transfer

    while(flash_dma_done == 0);
    //compare data
    for(uint8_t i = 0; i < DATA_SZ; i++)
    {
        if(pFlashData[i] != (0x12345600 + i))
            return 0;//error
    }

    return 1;
}

void UartInit(void)
{
    DioCfgPin(pADI_GPIO0, PIN10, 1);             // Setup P0.10 as UART pin
    DioCfgPin(pADI_GPIO0, PIN11, 1);             // Setup P0.11 as UART pin
    pADI_UART0->COMLCR2 = 0x3;                  // Set PCLk oversampling rate 32. (PCLK to UART baudrate generator is /32)
    UrtCfg(pADI_UART0, B57600,
           (BITM_UART_COMLCR_WLS | 3), 0);      // Configure UART for 115200 baud rate
    UrtFifoCfg(pADI_UART0, RX_FIFO_14BYTE,      // Configure the UART FIFOs for 8 bytes deep
               BITM_UART_COMFCR_FIFOEN);
    UrtFifoClr(pADI_UART0, BITM_UART_COMFCR_RFCLR// Clear the Rx/TX FIFOs
               | BITM_UART_COMFCR_TFCLR);
}

void DMA_FLASH0_Int_Handler()
{
    pADI_FLCC0->KEY = 0x676C7565;
    pADI_FLCC0->UCFG &= (~BITM_FLCC_UCFG_KHDMAEN);           // Disable Flash DMA mode
    flash_dma_done = 1;
}


void DMA_SIP2_Int_Handler()
{
    software_dma_done = 1;
}
