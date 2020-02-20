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
#include "ChronoAmperometric.h"

#define APPBUFF_SIZE 1000
#define n 8

#if defined ( __ICCARM__ )
#pragma location="never_retained_ram"
uint32_t AppBuff[n][APPBUFF_SIZE];
#elif defined (__CC_ARM)
uint32_t AppBuff[n][APPBUFF_SIZE] __attribute__((section(".ARM.__at_0x20040000"))); // use up to 32K bytes max, compiler linker file must have been modified for this to work !! Use "USER_SRAM_MODE = 2" setting;
#elif defined (__GNUC__)
__attribute__ ((section(".never_retained_ram")))
uint32_t AppBuff[n][APPBUFF_SIZE];
#else
#pragma message("WARNING: Need to place this variable in a large RAM section using your selected toolchain.")
#endif



float LFOSCFreq;
uint32_t IntCount = 0;

uint32_t pindex;//position in dataset
int newTest = -1; //check if new test started

/* It's your choice here what to do with the data. Here is just an example to print to UART */
int32_t AMPShowResult(float *pData, uint32_t DataCount)
{
  
  if (newTest < imeas){
    pindex = 0;
    newTest++;
    printf("\n%s\n",opt_chronoamp_meas[imeas]);
  }
  
  for(int i=0;i<DataCount;i++)
  {
    if(imeas == OPT_CHRONOAMP_MEAS_VSE0 || imeas == OPT_CHRONOAMP_MEAS_VRE0)
      printf("index:%ld, %f\n", pindex++, AD5940_ADCCode2Volt(pData[i], ADCPGA_1P5, 1.82));
    else 
      printf("index:%ld, %f\n", pindex++, AppCHRONOAMPCalcCurrent(pData[i]));
  }
  return 0;
}

/* Initialize AD5940 basic blocks like clock */
static int32_t AD5940PlatformCfg(void)
{
  CLKCfg_Type clk_cfg;
  FIFOCfg_Type fifo_cfg;
  LFOSCMeasure_Type LfoscMeasure;
    
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
  fifo_cfg.FIFOThresh = 4;//AppAMPCfg.FifoThresh;        /* DFT result. One pair for RCAL, another for Rz. One DFT result have real part and imaginary part */
  AD5940_FIFOCfg(&fifo_cfg);                             /* Disable to reset FIFO. */
  fifo_cfg.FIFOEn = bTRUE;  
  AD5940_FIFOCfg(&fifo_cfg);                             /* Enable FIFO here */
  
  /* Step3. Interrupt controller */
  AD5940_INTCCfg(AFEINTC_1, AFEINTSRC_ALLINT, bTRUE);           /* Enable all interrupt in Interrupt Controller 1, so we can check INTC flags */
  AD5940_INTCClrFlag(AFEINTSRC_ALLINT);
  AD5940_INTCCfg(AFEINTC_0, AFEINTSRC_DATAFIFOTHRESH|AFEINTSRC_ENDSEQ, bTRUE);   /* Interrupt Controller 0 will control GP0 to generate interrupt to MCU */
  AD5940_INTCClrFlag(AFEINTSRC_ALLINT);
  
  AD5940_SleepKeyCtrlS(SLPKEY_UNLOCK);  /* Enable AFE to enter sleep mode. */
  /* Measure LFOSC frequency */
  LfoscMeasure.CalDuration = 1000.0;  /* 1000ms used for calibration. */
  LfoscMeasure.CalSeqAddr = 0;
  LfoscMeasure.SystemClkFreq = 16000000.0f; /* 16MHz in this firmware. */
  AD5940_LFOSCMeasure(&LfoscMeasure, &LFOSCFreq);
  printf("Freq:%f\n", LFOSCFreq); 
  
  return 0;
}

/**
@brief void AD5940ADCMuxCfg(uint32_t *pMuxP, uint32_t *pMuxN)
======== ADC mux configuration for different tests

@return None.
@Description:
- Selects the needed p+ and n- terminals for the ADC mux for each of the chronoamp
tests
*/
void AD5940ADCMuxCfg(uint32_t *pMuxP, uint32_t *pMuxN){
  switch(imeas)
  {
  case OPT_CHRONOAMP_MEAS_VSE0: //VSE0
    *pMuxP = ADCMUXP_VSE0;
    *pMuxN = ADCMUXN_VSET1P1;
    break;
    
  case OPT_CHRONOAMP_MEAS_VRE0: //VRE0
    *pMuxP = ADCMUXP_VRE0;
    *pMuxN = ADCMUXN_VSET1P1;
    break;
    
  default: //current
    *pMuxP = ADCMUXP_LPTIA0_P;
    *pMuxN = ADCMUXN_LPTIA0_N;
    break;
  } /* switch(imeas) */
}


/* !!Change the application parameters here if you want to change it to none-default value */
void AD5940AMPStructInit(void)
{
  AppCHRONOAMPCfg_Type *pAMPCfg; 
  AppCHRONOAMPGetCfg(&pAMPCfg);
  
  uint32_t MuxP = 0; //ADC Mux p+ terminal
  uint32_t MuxN = 0; //ADC Mux n- terminal
  AD5940ADCMuxCfg(&MuxP, &MuxN);
  
  pAMPCfg->bParaChanged = bTRUE;
  
  /* Configure general parameters */
  pAMPCfg->WuptClkFreq = LFOSCFreq;	/* Use measured 32kHz clock freq for accurate wake up timer */
  pAMPCfg->SeqStartAddr = 0;
  pAMPCfg->MaxSeqLen = 512; 		
  pAMPCfg->RcalVal = 200.0;
  pAMPCfg->NumOfData = -1;      	/* Never stop until you stop it mannually by AppAMPCtrl() function */
  
  pAMPCfg->AmpODR = 1;
  pAMPCfg->FifoThresh = 500;
  pAMPCfg->ADCRefVolt = 1.82;		/* Measure voltage on VREF_1V8 pin and add here */
  

  /* Configure EC Sensor parameters */
  pAMPCfg->SensorCh0.LptiaRtiaSel = LPTIARTIA_1K;	/* Select TIA gain resistor. */
  pAMPCfg->SensorCh0.LpTiaRl = LPTIARLOAD_SHORT; 
  pAMPCfg->SensorCh0.SensorBias = 0;              /* Sensor bias voltage between reference and sense electrodes*/
  pAMPCfg->SensorCh0.Vzero = 1100;
  
  /* Configure Pulse */
  pAMPCfg->pulseAmplitude = 400;		/* Pulse amplitude on counter electrode (mV) */
  pAMPCfg->pulseLength = 100;		/* Length of voltage pulse in ms */
  
  pAMPCfg->DataFifoSrc = FIFOSRC_SINC2NOTCH;
  pAMPCfg->ADCSinc3Osr = ADCSINC3OSR_4;
  pAMPCfg->ADCSinc2Osr = ADCSINC2OSR_22;
  
  //input to ADC
  pAMPCfg->ADCMuxP = MuxP;  
  pAMPCfg->ADCMuxN = MuxN;
  pAMPCfg->TestType = opt_chronoamp_meas[imeas];
}

void AD5940_Main(void)
{
  uint32_t temp[n];
  AppCHRONOAMPCfg_Type *pAMPCfg;
  AppCHRONOAMPGetCfg(&pAMPCfg);
  AD5940PlatformCfg();  
  AD5940AMPStructInit(); /* Configure your parameters in this function */
  
  int ChronoampTestReady = 1;
  
  while(1)
  {
    
    if(imeas < num_chronoamp_meas && ChronoampTestReady){ //cycle through tests defined in OPT_CHRONOAMP_MEAS_Type but wait until previous test is finished
      ChronoampTestReady = 0;
      AD5940AMPStructInit();
      
      AppCHRONOAMPInit(AppBuff[0], APPBUFF_SIZE);    /* Initialize AMP application. Provide a buffer, which is used to store sequencer commands */
      AD5940_Delay10us(10000);
      AppCHRONOAMPCtrl(CHRONOAMPCTRL_PULSETEST, 0);         /* Control AMP measurment. AMPCTRL_PULSETEST carries out pulse test*/
    }
    
    /* Check if interrupt flag which will be set when interrupt occured. */
    if(AD5940_GetMCUIntFlag())
    {
      AD5940_ClrMCUIntFlag(); /* Clear this flag */
      temp[IntCount] = APPBUFF_SIZE;
      AppCHRONOAMPISR(AppBuff[IntCount], &temp[IntCount]); /* Deal with it and provide a buffer to store data we got */
      
      
      if(pAMPCfg->EndSeq) /* End sequence only set at end of transient */
      {
        
        for(int i = 0; i<IntCount; i++)
        {
          AMPShowResult((float*)AppBuff[i], temp[i]); /* Show the results to UART */
        }
        
        pAMPCfg->EndSeq = bFALSE;
	pAMPCfg->bMeasureTransient = bFALSE;
        IntCount = 0;
        
        imeas++;
        ChronoampTestReady = 1; // Test is finished so ready for next test
        
      }
    }
  }
}

