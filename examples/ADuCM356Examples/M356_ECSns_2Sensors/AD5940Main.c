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
#include "Amperometric.h"
#include "PwrLib.h"

#define APPBUFF_SIZE 1000
uint32_t AppBuff[APPBUFF_SIZE];
float LFOSCFreq;

/* It's your choice here what to do with the data. Here is just an example to print them to UART */
int32_t AMPShowResult(float *pData, uint32_t DataCount)
{
  AppAMPCfg_Type *pAmpCfg;
  AppAMPGetCfg(&pAmpCfg); 


  for(int i = 0; i<DataCount; i++)
  {
    printf("Index: %d Ch0: %.3fuA Ch1: %.3fuA \n", i, pAmpCfg->SensorCh0.ResultBuffer[i], pAmpCfg->SensorCh1.ResultBuffer[i]);
  }
  
  return 0;
}

/* Initialize AD5940 basic blocks like clock */
static int32_t AD5940PlatformCfg(void)
{
  CLKCfg_Type clk_cfg;
  LFOSCMeasure_Type LfoscMeasure;

  /* Platform configuration */
  AD5940_Initialize();
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
  
  /* Step3. Interrupt controller */
  AD5940_INTCCfg(AFEINTC_1, AFEINTSRC_ALLINT, bTRUE);           /* Enable all interrupt in Interrupt Controller 1, so we can check INTC flags */
  AD5940_INTCCfg(AFEINTC_0, AFEINTSRC_DATAFIFOTHRESH, bTRUE);   /* Interrupt Controller 0 will control GP0 to generate interrupt to MCU */
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

/* !!Change the application parameters here if you want to change it to none-default value */
void AD5940AMPStructInit(void)
{
  AppAMPCfg_Type *pAmpCfg;
  
  AppAMPGetCfg(&pAmpCfg);
  pAmpCfg->WuptClkFreq = LFOSCFreq;
  /* Configure general parameters */
  pAmpCfg->SeqStartAddr = 0;
  pAmpCfg->MaxSeqLen = 512; /* @todo add checker in function */  
  pAmpCfg->RcalVal = 200.0;
  pAmpCfg->NumOfData = -1;      /* Never stop until you stop it mannually by AppAMPCtrl() function */	
  pAmpCfg->AmpODR = 4;
  
  pAmpCfg->NumSamplesAvg = 8;   /* Take 8 samples each time device wakesup to average */
  
  pAmpCfg->M355FifoThresh = 2*pAmpCfg->NumSamplesAvg;  
  
  /* Configure EC Sensor Parameters */
  //CO Sensor is connected to CH0 on EVAL-ADuCM355QSPZ
  pAmpCfg->SensorCh0.LpTiaRf = LPTIARF_1M;              /* 1Mohm Rfilter, 4.7uF cap connected external on AIN4 */
  pAmpCfg->SensorCh0.LpTiaRl = LPTIARLOAD_10R;          /* CO sensor datasheet specifies 10ohm Rload */
  pAmpCfg->SensorCh0.LptiaRtiaSel = LPTIARTIA_30K;      /* LPTIA gain resistor is 30kohm */
  pAmpCfg->SensorCh0.Vzero = 500;                       /* Set Vzero = 500mV. VOltage on SE0 pin*/
  pAmpCfg->SensorCh0.SensorBias = 0;                    /* 0V bias voltage */
  
  //O2 Sensor is connected to CH1 on EVAL-ADuCM355QSPZ
  pAmpCfg->SensorCh1.LpTiaRf = LPTIARF_1M;              /* 1Mohm Rfilter */
  pAmpCfg->SensorCh1.LpTiaRl = LPTIARLOAD_10R;          /* 10 ohm rload */
  pAmpCfg->SensorCh1.LptiaRtiaSel = LPTIARTIA_2K;       /* Tia gain resistor is 2kohm */
  pAmpCfg->SensorCh1.Vzero = 900;                       /* Set vzero equal to 900mV. Voltage on SE1 pin */
  pAmpCfg->SensorCh1.SensorBias = 600;                  /* Apply 600mV bias to sensor */
  
}

void AD5940_Main(void)
{  
  uint32_t temp;
  
  AppAMPCfg_Type *pAmpCfg;
  
  AppAMPGetCfg(&pAmpCfg);
  AD5940PlatformCfg();
  AD5940AMPStructInit(); /* Configure your parameters in this function */ 
  
  /* Initialise 2 EC sensors */
  AppECSnrInit(&pAmpCfg->SensorCh0, M355_CHAN0);
  AppECSnrInit(&pAmpCfg->SensorCh1, M355_CHAN1);
  
  AppAMPInit(AppBuff, APPBUFF_SIZE);    /* Initialize application. Provide a buffer, which is used to store sequencer commands */
  AppAMPCtrl(AMPCTRL_START, 0);         /* Control measurment to start. Second parameter has no meaning with this command. */ 
  
  while(1)
  {
    /* Wait for data ready interrupt on internal GPIO pin */
    if(AD5940_GetMCUIntFlag())
    {
      AD5940_ClrMCUIntFlag(); /* Clear this flag */
      AppAMPISR(AppBuff, &temp); /* Deal with it and provide a buffer to store data we got */
      AMPShowResult((float*)AppBuff, temp); /* Show the results to UART */    
      /*Digital die sleep untill wakeup timer expires*/
      PwrCfg(ENUM_PMG_PWRMOD_HIBERNATE,MONITOR_VBAT_EN,0); //this line is all code for digital die entering hibernate
    }    
  }
}

