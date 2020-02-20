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
#include "RadiatedImmunity_Demo.h"
#include "M355_EMCFlash.h"
#include "PwrLib.h"

#define APPBUFF_SIZE 1000
uint32_t AppBuff[APPBUFF_SIZE];
float LFOSCFreq;

#define CO_uA_Per_PPM   80e-3

uint8_t ucUseArray1 = 0;
uint16_t uiSramCnt = 0;
uint16_t szSamplesinSRAM1[128];           // Array to store shifted ADC measurements for current channel - when full, moved to flash
uint16_t szSamplesinSRAM0[128];           // Array to store shifted ADC measurements for current channel - when full, moved to flash
int16_t ucPage = 0;

unsigned char ucTxBufferEmpty  = 0;	           // Used to indicate that the UART Tx buffer is empty
unsigned char szTemp[64] = "";		           // Used to build string before printing to UART

/* Print data to Uart and also store in Flash */
int32_t AMPShowResult(float *pData, uint32_t DataCount)
{
  AppAMPCfg_Type *pAmpCfg;
  AppAMPGetCfg(&pAmpCfg); 
  float Current_uA = 0.0;
  for(int i=0;i<DataCount;i++)
  {
    Current_uA = AppAMPCalcCurrent(pAmpCfg->SensorCh0.ResultBuffer[i], pAmpCfg->SensorCh0.RtiaCalValue.Magnitude);
    printf("Index %i:, %d , %.3f uA , %f ppm\n", i, pAmpCfg->SensorCh0.ResultBuffer[i], Current_uA, Current_uA/CO_uA_Per_PPM);
    
    if ((ucUseArray1 %2) == 1)
    {
      szSamplesinSRAM1[uiSramCnt++] = pAmpCfg->SensorCh0.ResultBuffer[i];
    }
    else
    {
      szSamplesinSRAM0[uiSramCnt++] = pAmpCfg->SensorCh0.ResultBuffer[i]; 
    }
    if (uiSramCnt >= 128)
    {
      uiSramCnt = 0;
      ucUseArray1++;
      BackUpToFlash();
    }
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
  
  /* Step1. Configure AFE clock */
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
  pAmpCfg->MaxSeqLen = 512;     /* @todo add checker in function */    
  pAmpCfg->NumOfData = -1;      /* Never stop until you stop it mannually by AppAMPCtrl() function */	
  
  pAmpCfg->RcalVal = 200.0;     /* Value of RCAl on board */
  pAmpCfg->M355FifoThresh = 16;
  pAmpCfg->AmpODR = 1;          /* Make one Gas reading every second */  
  
  /* Configure EC Sensor Parameters */
  pAmpCfg->SensorCh0.LpTiaRf = LPTIARF_100K;       /* 1Mohm Rfilter, 4.7uF cap connected external on AIN4 */
  pAmpCfg->SensorCh0.LpTiaRl = LPTIARLOAD_30R;     /* CO sensor datasheet specifies 10ohm Rload */
  pAmpCfg->SensorCh0.LptiaRtiaSel = LPTIARTIA_4K;  /* LPTIA gain resistor is 30kohm */
  pAmpCfg->SensorCh0.Vzero = 1260.0;               /* Set Vzero = 1260mV. Voltage on SE0 pin*/
  pAmpCfg->SensorCh0.SensorBias = 0.0;             /* 0V bias voltage */
  
  /* Configure ADC */
  pAmpCfg->ADCPgaGain = ADCPGA_1P5;
  pAmpCfg->ADCSinc3Osr = ADCSINC3OSR_4;
  pAmpCfg->ADCSinc2Osr = ADCSINC2OSR_22;
  pAmpCfg->DataFifoSrc = FIFOSRC_SINC2NOTCH;  
}

void AD5940_Main(void)
{  
  uint32_t temp;
  
  AppAMPCfg_Type *pAmpCfg;
  
  AppAMPGetCfg(&pAmpCfg);
  AD5940PlatformCfg();
  AD5940AMPStructInit(); 
  
  /* Initialise EC sensor and calibrate ADC and LPTIA gain resistor */
  AppECSnrInit(&pAmpCfg->SensorCh0, M355_CHAN0);
  
  /* Initialize AFE die, sequencer and FIFOs */
  AppAMPInit(AppBuff, APPBUFF_SIZE);    
  
  /*Check state of P1.3. If it is high start logging to flash, 
    if low print contents of flash to Uart*/
  StartDebugText();
  
  AD5940_Delay10us(100);               // Delay 1ms
  
  InitFlash();
  ucPage = 0;
  /* Start measurement */ 
  AppAMPCtrl(AMPCTRL_START, 0);         
  while(1)
  {
    /* Wait for data ready interrupt on internal GPIO pin */
    if(AD5940_GetMCUIntFlag())
    {
      AD5940_ClrMCUIntFlag(); /* Clear this flag */
      AppAMPISR(AppBuff, &temp); /* Deal with it and provide a buffer to store data we got */
      AMPShowResult((float*)AppBuff, temp); /* Show the results to UART */    
      /*Digital die sleep until INTC interrupt wakes it when FIFO full  */
      PwrCfg(ENUM_PMG_PWRMOD_HIBERNATE,MONITOR_VBAT_EN,0); 
    }    
  }
}

