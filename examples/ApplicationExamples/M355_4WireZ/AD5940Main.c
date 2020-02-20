/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#include "ad5940.h"
#include "AD5940.h"
#include <stdio.h>
#include "string.h"
#include "math.h"
#include "M355_4WireZ.h"

#define APPBUFF_SIZE 512
uint32_t AppBuff[APPBUFF_SIZE];

/* It's your choice here how to do with the data. Here is just an example to print them to UART */
int32_t BIAShowResult(uint32_t *pData, uint32_t DataCount)
{
  float freq;
  
  fImpPol_Type *pImp = (fImpPol_Type*)pData;
  AppBIACtrl(BIACTRL_GETFREQ, &freq);
  
  printf("Freq:%.2f  , ", freq);
  /*Process data*/
  for(int i=0;i<DataCount;i++)
  {
    printf(" %f ,  %f \n",pImp[i].Magnitude,pImp[i].Phase);
  }
  return 0;
}

/* Initialize AD5940 basic blocks like clock */
static int32_t AD5940PlatformCfg(void)
{
  CLKCfg_Type clk_cfg;
  FIFOCfg_Type fifo_cfg;
  
  /* Platform configuration */
  AD5940_Initialize();
  /* Step1. Configure clock */
  clk_cfg.ADCClkDiv = ADCCLKDIV_1;
  clk_cfg.ADCCLkSrc = ADCCLKSRC_HFOSC;
  clk_cfg.SysClkDiv = SYSCLKDIV_1;
  clk_cfg.SysClkSrc = SYSCLKSRC_HFOSC;
  clk_cfg.HfOSC32MHzMode = bFALSE;
  clk_cfg.HFOSCEn = bTRUE;
  clk_cfg.HFXTALEn = bFALSE;
  clk_cfg.LFOSCEn = bTRUE;
  AD5940_CLKCfg(&clk_cfg);
  /* Step2. Configure FIFO and Sequencer*/
  fifo_cfg.FIFOEn = bFALSE;
  fifo_cfg.FIFOMode = FIFOMODE_FIFO;
  fifo_cfg.FIFOSize = FIFOSIZE_4KB;                       /* 4kB for FIFO, The reset 2kB for sequencer */
  fifo_cfg.FIFOSrc = FIFOSRC_DFT;
  fifo_cfg.FIFOThresh = 4;//AppBIACfg.FifoThresh;        /* DFT result. One pair for RCAL, another for Rz. One DFT result have real part and imaginary part */
  AD5940_FIFOCfg(&fifo_cfg);                             /* Disable to reset FIFO. */
  fifo_cfg.FIFOEn = bTRUE;  
  AD5940_FIFOCfg(&fifo_cfg);                             /* Enable FIFO here */
  
  /* Step3. Interrupt controller */
  
  AD5940_INTCCfg(AFEINTC_1, AFEINTSRC_ALLINT, bTRUE);           /* Enable all interrupt in Interrupt Controller 1, so we can check INTC flags */
  AD5940_INTCCfg(AFEINTC_0, AFEINTSRC_DATAFIFOTHRESH, bTRUE);   /* Interrupt Controller 0 will control GP0 to generate interrupt to MCU */
  AD5940_INTCClrFlag(AFEINTSRC_ALLINT);

  AD5940_SleepKeyCtrlS(SLPKEY_UNLOCK);  /* Allow AFE to enter sleep mode. */
  return 0;
}

/* !!Change the application parameters here if you want to change it to none-default value */
void AD5940BIAStructInit(void)
{
  AppBIACfg_Type *pBIACfg;
  
  AppBIAGetCfg(&pBIACfg);
  
  pBIACfg->SeqStartAddr = 0;
  pBIACfg->MaxSeqLen = 512; /** @todo add checker in function */
  pBIACfg->AdcClkFreq = 16e6;
  pBIACfg->PwrMod = AFEPWR_LP;
  pBIACfg->HsDacUpdateRate = 0x1B;
  
  pBIACfg->RcalVal = 200.0;
  pBIACfg->DftNum = DFTNUM_8192;
  pBIACfg->NumOfData = -1;      /* Never stop until you stop it mannually by AppBIACtrl() function */
  pBIACfg->BiaODR = 20;         /* ODR(Sample Rate) 20Hz */
  pBIACfg->FifoThresh = 4;      /* 4 */
  pBIACfg->ADCSinc3Osr = ADCSINC3OSR_2;
  
  pBIACfg->SinFreq = 20;
  pBIACfg->SweepCfg.SweepEn = bTRUE;
  pBIACfg->SweepCfg.SweepStart = 5000;
  pBIACfg->SweepCfg.SweepStop = 50000.0;
  pBIACfg->SweepCfg.SweepPoints = 10;
  pBIACfg->SweepCfg.SweepLog = bFALSE;
  pBIACfg->SweepCfg.SweepIndex = 0;
  
  
}

void AD5940_Main(void)
{
  static uint32_t IntCount;
  uint32_t temp;
  
  AD5940PlatformCfg();
  
  AD5940BIAStructInit(); /* Configure your parameters in this function */
  
  AppBIAInit(AppBuff, APPBUFF_SIZE);    /* Initialize BIA application. Provide a buffer, which is used to store sequencer commands */
  AppBIACtrl(BIACTRL_START, 0);         /* Control BIA measurment to start. Second parameter has no meaning with this command. */
  
  while(1)
  {
    /* Check if interrupt flag which will be set when interrupt occured. */
    if(AD5940_GetMCUIntFlag())
    {
      IntCount++;
      AD5940_ClrMCUIntFlag(); /* Clear this flag */
      temp = APPBUFF_SIZE;
      AppBIAISR(AppBuff, &temp); /* Deal with it and provide a buffer to store data we got */
      BIAShowResult(AppBuff, temp); /* Show the results to UART */
    }

  }
}

/**
* @}
* @}
* */

