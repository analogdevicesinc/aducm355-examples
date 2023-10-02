/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/
#include "Ramp.h"

/**
User could configure following parameters
**/

#define APPBUFF_SIZE 1024
uint32_t AppBuff[APPBUFF_SIZE];
float LFOSCFreq;        /* Measured LFOSC frequency */
int imeas = 0;          /* the measurement type we are doing from OPT_RAMP_MEAS_Type */
const char *opt_ramp_meas[NUM_OPT_RAMP_MEAS] = {"I", "VSE0", "VRE0", "I2"};


/**
* @brief An example to deal with data read back from AD5940. Here we just print data to UART
* @note UART has limited speed, it has impact when sample rate is fast. Try to print some of the data not all of them.
* @param pData: the buffer stored data for this application. The data from FIFO has been pre-processed.
* @param DataCount: The available data count in buffer pData.
* @return return 0.
*/
static int32_t RampShowResult(float *pData, uint32_t DataCount)
{
  uint32_t index = 0;
  printf("\n%s\n\n",opt_ramp_meas[imeas]);
  /* Print data*/
  for(int i=0;i<DataCount;i++)
  {
    printf("index:%d, %.3f\n", index++, pData[i]);
    //i += 10;  /* Print though UART consumes too much time. */
  }
  
  return 0;
}

/**
* @brief The general configuration to AD5940 like FIFO/Sequencer/Clock. 
* @note This function will firstly reset AD5940 using reset pin.
* @return return 0.
*/
static int32_t AD5940PlatformCfg(void)
{
  CLKCfg_Type clk_cfg;
  SEQCfg_Type seq_cfg;  
  FIFOCfg_Type fifo_cfg;
  LFOSCMeasure_Type LfoscMeasure;
  
  AD5940_Initialize();    /* Call this right after AFE reset */
  /* Platform configuration */
  /* Step1. Configure clock */
  clk_cfg.HFOSCEn = bTRUE;
  clk_cfg.HFXTALEn = bFALSE;
  clk_cfg.LFOSCEn = bTRUE;
  clk_cfg.HfOSC32MHzMode = bFALSE;
  clk_cfg.SysClkSrc = SYSCLKSRC_HFOSC;
  clk_cfg.SysClkDiv = SYSCLKDIV_1;
  clk_cfg.ADCCLkSrc = ADCCLKSRC_HFOSC;
  clk_cfg.ADCClkDiv = ADCCLKDIV_1;
  AD5940_CLKCfg(&clk_cfg);
  /* Step2. Configure FIFO and Sequencer*/
  /* Configure FIFO and Sequencer */
  fifo_cfg.FIFOEn = bTRUE;           /* We will enable FIFO after all parameters configured */
  fifo_cfg.FIFOMode = FIFOMODE_FIFO;
  fifo_cfg.FIFOSize = FIFOSIZE_2KB;   /* 2kB for FIFO, The reset 4kB for sequencer */
  fifo_cfg.FIFOSrc = FIFOSRC_SINC3;   /* */
  fifo_cfg.FIFOThresh = 4;            /*  Don't care, set it by application paramter */
  AD5940_FIFOCfg(&fifo_cfg);
  seq_cfg.SeqMemSize = SEQMEMSIZE_4KB;  /* 4kB SRAM is used for sequencer, others for data FIFO */
  seq_cfg.SeqBreakEn = bFALSE;
  seq_cfg.SeqIgnoreEn = bTRUE;
  seq_cfg.SeqCntCRCClr = bTRUE;
  seq_cfg.SeqEnable = bFALSE;
  seq_cfg.SeqWrTimer = 0;
  AD5940_SEQCfg(&seq_cfg);
  /* Step3. Interrupt controller */
  AD5940_INTCCfg(AFEINTC_1, AFEINTSRC_ALLINT, bTRUE);   /* Enable all interrupt in INTC1, so we can check INTC flags */
  AD5940_INTCClrFlag(AFEINTSRC_ALLINT);
  AD5940_INTCCfg(AFEINTC_0, AFEINTSRC_DATAFIFOTHRESH|AFEINTSRC_ENDSEQ|AFEINTSRC_CUSTOMINT0, bTRUE); 
  AD5940_INTCClrFlag(AFEINTSRC_ALLINT);

  /* Measure LFOSC frequency */
  /**@note Calibrate LFOSC using system clock. The system clock accuracy decides measurment accuracy. Use XTAL to get better result. */
  LfoscMeasure.CalDuration = 1000.0;  /* 1000ms used for calibration. */
  LfoscMeasure.CalSeqAddr = 0;        /* Put sequence commands from start address of SRAM */
  LfoscMeasure.SystemClkFreq = 16000000.0f; /* 16MHz in this firmware. */
  AD5940_LFOSCMeasure(&LfoscMeasure, &LFOSCFreq);
  printf("LFOSC Freq:%f\n", LFOSCFreq);
  AD5940_SleepKeyCtrlS(SLPKEY_UNLOCK);         /*  */
  return 0;
}

/**
@brief void AD5940ADCMuxCfg(uint32_t *pMuxP, uint32_t *pMuxN
======== ADC mux configuration for different tests

@return None.
@Description:
- Selects the needed p+ and n- terminals for the ADC mux for each of the ramp
tests
*/
void AD5940ADCMuxCfg(void){
  uint32_t MuxP, MuxN;
  switch(imeas)
  {
  case OPT_RAMP_MEAS_VSE0: //VSE0
    MuxP = ADCMUXP_VSE0;
    MuxN = ADCMUXN_VSET1P1;
    break;
    
  case OPT_RAMP_MEAS_VRE0: //VRE0
    MuxP = ADCMUXP_VRE0;
    MuxN = ADCMUXN_VSET1P1;
    break;
    
  default: //current
    MuxP = ADCMUXP_LPTIA0_P;
    MuxN = ADCMUXN_LPTIA0_N;
    break;
  } /* switch(imeas) */
  AD5940_ADCMuxCfgS(MuxP, MuxN); 
}

/**
* @brief The interface for user to change application paramters.
* @return return 0.
*/
void AD5940RampStructInit(void)
{
  AppRAMPCfg_Type *pRampCfg;
  
  AppRAMPGetCfg(&pRampCfg);
  
  pRampCfg->bParaChanged = bTRUE;
  /* Step1: configure general parmaters */
  pRampCfg->SeqStartAddr = 0x10;               /* leave 16 commands for LFOSC calibration.  */
  pRampCfg->MaxSeqLen = 1024-0x10;             /* 4kB/4 = 1024  */
  pRampCfg->RcalVal = 200.0;                   /* 200Ohm RCAL on EVAL-ADuCM355QSPZ */
  pRampCfg->ADCRefVolt = 1820.0f;              /* The real ADC reference voltage. Measure it from capacitor C12 with DMM. */
  pRampCfg->FifoThresh = 800;                  /* Maximum value is 2kB/4-1 = 512-1. Set it to higher value to save power. */
  pRampCfg->SysClkFreq = 16000000.0f;           /* System clock is 16MHz by default */
  pRampCfg->LFOSCClkFreq = LFOSCFreq;           /* LFOSC frequency */
  /* Configure Current measurement channel */
  pRampCfg->LPTIARtiaSel = LPTIARTIA_200R;        /* Maximum current decides RTIA value */
  pRampCfg->LPTIARloadSel = LPTIARLOAD_SHORT;
  
  /* Configure ramp signal parameters */
  pRampCfg->RampStartVolt = -500.0f;          /* -500 mV */
  pRampCfg->RampPeakVolt = +500.0f;           /* +500mV */
  pRampCfg->VzeroStart = 1300.0f;              /* 1.3V */
  pRampCfg->VzeroPeak = 1300.0f;               /* 1.3V */
  pRampCfg->StepNumber = 400;                  /* Total steps. Equals to ADC sample number */
  pRampCfg->RampDuration = 10*1000;            /* Total duration of ramp signal. unit is ms. */
  pRampCfg->SampleDelay = 2.0f;                /* Time between update DAC and ADC sample. Unit is ms. */
  
}

void AD5940_Main(void)
{
  uint32_t temp;  
  AD5940PlatformCfg();
  AD5940RampStructInit();
  
  int RampTestReady = 1;
  /* Initialize RAMP application. Provide a buffer, which is used to store sequencer commands */
  AppRAMPInit(AppBuff, APPBUFF_SIZE);   
  while(1)
  {
    if(imeas < num_ramp_meas && RampTestReady){ /* cycle through tests defined in OPT_RAMP_MEAS_Type but wait until previous test is finished */
      RampTestReady = 0;
      AD5940ADCMuxCfg();
      AD5940_SEQCtrlS(bTRUE);                   /* Enable sequencer, and wait for trigger */
      AppRAMPCtrl(APPCTRL_START, 0);            /* Control IMP measurment to start. Second parameter has no meaning with this command. */
    }
    
    if(AD5940_GetMCUIntFlag())
    {
      AD5940_ClrMCUIntFlag();
      temp = APPBUFF_SIZE;
      AppRAMPISR(AppBuff, &temp);
      
      if (temp != 0){ // check if buffer is populated
        RampShowResult((float*)AppBuff, temp);
        imeas++;
        RampTestReady = 1; //Ramp test is finished so ready for next test
      }
    }
    
  }
}

