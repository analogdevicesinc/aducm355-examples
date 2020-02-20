/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#include "RadiatedImmunity_Demo.h"
#include "ADuCM355.h"

/* This file contains auto generated source code that user defined */

/* 
  Application configuration structure. Specified by user from template.
  The variables are usable in this whole application.
  It includes basic configuration for sequencer generator and application related parameters
*/
AppAMPCfg_Type AppAmpCfg = 
{
  .bParaChanged = bFALSE,
  .SeqStartAddr = 0,
  .MaxSeqLen = 0,
  
  .SeqStartAddrCal = 0,
  .MaxSeqLenCal = 0,
  
  .SysClkFreq = 16000000.0,
  .WuptClkFreq = 32000.0,
  .AdcClkFreq = 16000000.0,
  .AmpODR = 1.0,                /* Sample time in seconds. I.e. every 5 sesonds make a measurement */
  .NumOfData = -1,
  .RcalVal = 200.0,           /* RCAL = 10kOhm */
  .PwrMod = AFEPWR_LP,
  .AMPInited = bFALSE,
  .StopRequired = bFALSE,
  
  /* ADC Configure*/
  .ADCPgaGain = ADCPGA_1P5,
  .ADCSinc3Osr = ADCSINC3OSR_4,
  .ADCSinc2Osr = ADCSINC2OSR_22,
  .DataFifoSrc = FIFOSRC_SINC2NOTCH,
  .ADCRefVolt = 1.82,			/* Measure voltage on ADCRefVolt pin and enter here*/
};

/**
   This function is provided for upper controllers that want to change 
   application parameters specially for user defined parameters.
*/
AD5940Err AppAMPGetCfg(void *pCfg)
{
  if(pCfg){
    *(AppAMPCfg_Type**)pCfg = &AppAmpCfg;
    return AD5940ERR_OK;
  }
  return AD5940ERR_PARA;
}

AD5940Err AppAMPCtrl(int32_t AmpCtrl, void *pPara)
{
  switch (AmpCtrl)
  {
    case AMPCTRL_START:
    {
      WUPTCfg_Type wupt_cfg;

      AD5940_ReadReg(REG_AFE_ADCDAT); /* Any SPI Operation can wakeup AFE */
      if(AppAmpCfg.AMPInited == bFALSE)
        return AD5940ERR_APPERROR;
      /* Start it */
      wupt_cfg.WuptEn = bTRUE;
      wupt_cfg.WuptEndSeq = WUPTENDSEQ_A;
      wupt_cfg.WuptOrder[0] = SEQID_0;
      wupt_cfg.SeqxSleepTime[SEQID_0] = 4-1;
      wupt_cfg.SeqxWakeupTime[SEQID_0] = (uint32_t)(AppAmpCfg.WuptClkFreq*AppAmpCfg.AmpODR)-4-1; 
      AD5940_WUPTCfg(&wupt_cfg);
      
      AppAmpCfg.FifoDataCount = 0;  /* restart */
      break;
    }
    case AMPCTRL_STOPNOW:
    {
      AD5940_ReadReg(REG_AFE_ADCDAT); /* Any SPI Operation can wakeup AFE */
      /* Start Wupt right now */
      AD5940_WUPTCtrl(bFALSE);
      AD5940_WUPTCtrl(bFALSE);  /* @todo is it sure this will stop Wupt? */
      break;
    }
    case AMPCTRL_STOPSYNC:
    {
      AppAmpCfg.StopRequired = bTRUE;
      break;
    }
    case AMPCTRL_SHUTDOWN:
    {
      AppAMPCtrl(AMPCTRL_STOPNOW, 0);  /* Stop the measurment if it's running. */
      /* Turn off LPloop related blocks which are not controlled automatically by sleep operation */
      AFERefCfg_Type aferef_cfg;
      LPLoopCfg_Type lp_loop;
      memset(&aferef_cfg, 0, sizeof(aferef_cfg));
      AD5940_REFCfgS(&aferef_cfg);
      memset(&lp_loop, 0, sizeof(lp_loop));
      AD5940_LPLoopCfgS(&lp_loop);
      AD5940_EnterSleepS();  /* Enter Hibernate */
    }
    break;
    default:
    break;
  }
  return AD5940ERR_OK;
}

/* Function to calibrate internal gain resistor for LPTIA channels */
static AD5940Err AppAMPRtiaCal(AppECSnsCfg_Type *sns_cfg, uint8_t LPAMP)
{
  fImpPol_Type RtiaCalValue;  /* Calibration result */
  LPRTIACal_Type lprtia_cal;
  AD5940_StructInit(&lprtia_cal, sizeof(lprtia_cal));

  lprtia_cal.LpAmpSel = LPAMP;
  lprtia_cal.bPolarResult = bTRUE;                /* Magnitude + Phase */
  lprtia_cal.AdcClkFreq = 16000000;
  lprtia_cal.SysClkFreq = 16000000;
  lprtia_cal.ADCSinc3Osr = ADCSINC3OSR_4;
  lprtia_cal.ADCSinc2Osr = ADCSINC2OSR_22;        /* Use SINC2 data as DFT data source */
  lprtia_cal.DftCfg.DftNum = DFTNUM_2048;         /* Maximum DFT number */
  lprtia_cal.DftCfg.DftSrc = DFTSRC_SINC2NOTCH;        /* @todo For frequency under 12Hz, need to optimize DFT source. Use SINC3 data as DFT source */
  lprtia_cal.DftCfg.HanWinEn = bTRUE;
  lprtia_cal.fFreq = 16000000/4/22/2048*3;  /* Sample 3 period of signal, 13.317Hz here. Do not use DC method, because it needs ADC/PGA calibrated firstly(but it's faster) */
  lprtia_cal.fRcal = 200;
  lprtia_cal.LpTiaRtia = sns_cfg->LptiaRtiaSel;
  lprtia_cal.LpAmpPwrMod = LPAMPPWR_NORM;
  lprtia_cal.bWithCtia = bFALSE;
  AD5940_LPRtiaCal(&lprtia_cal, &RtiaCalValue);
  sns_cfg->RtiaCalValue = RtiaCalValue;
  printf("Calibrated Rtia = %f \n", RtiaCalValue.Magnitude); 
  return AD5940ERR_OK;
}
/* Calibrate ADC Offset and Gain */
static AD5940Err AppADCPgaOffsetCal(void)
{
  ADCPGACal_Type pga_cal;

  /* Calibrate ADC PGA(offset and gain) */
  pga_cal.AdcClkFreq = AppAmpCfg.AdcClkFreq;
  pga_cal.SysClkFreq = AppAmpCfg.SysClkFreq;
  pga_cal.ADCPga = AppAmpCfg.ADCPgaGain;
  pga_cal.ADCSinc2Osr = ADCSINC2OSR_1333;	/* 800kSPS/4/1333 = 150Hz,  T = 6.67ms*/
  pga_cal.ADCSinc3Osr = ADCSINC3OSR_4;
  pga_cal.TimeOut10us = 10*100;			/* 10ms max */
  pga_cal.VRef1p82 = AppAmpCfg.ADCRefVolt;  
  pga_cal.VRef1p11  = 1.11;
  pga_cal.PGACalType = PGACALTYPE_OFFSETGAIN;
  AD5940_ADCPGACal(&pga_cal);
 
  return AD5940ERR_OK; 
}
void AppChargeECSensor(void)
{
  pADI_AFE->LPTIASW0 |= 0x2;                   // Close SW1 in LP loop to shot LPTIA0 output to inverting input
  AD5940_Delay10us(400000);                          // delay 4S 
  pADI_AFE->LPTIASW0 &= ~(0x2);                // Open SW1 in LP loop to shot LPTIA0 output to inverting input
}

/* Initialize the Electrochemical Sensor */
AD5940Err AppECSnrInit(AppECSnsCfg_Type *SnsCfg, uint8_t SnsSel)
{
  uint8_t LPDAC_SEL, LPAMP_SEL;
  AFERefCfg_Type aferef_cfg;
  LPLoopCfg_Type lp_loop;
  SWMatrixCfg_Type sw_cfg;  
  /* Select which channel to control */
  if(SnsSel == M355_CHAN0)
  {
    LPDAC_SEL = LPDAC0;
    LPAMP_SEL = LPAMP0;
  }
  else if(SnsSel == M355_CHAN1)
  {
    LPDAC_SEL = LPDAC1;
    LPAMP_SEL = LPAMP1;
  }
  
  /* Step 1: Calibrate ADC Offset */
  AppADCPgaOffsetCal();
  
  /* Step 2: Calibrate Rtia */
  AppAMPRtiaCal(SnsCfg, LPAMP_SEL);

  /* Step 3: Initialize Low Power Potentiostat Loop */
  aferef_cfg.HpBandgapEn = bTRUE;
  aferef_cfg.Hp1V1BuffEn = bTRUE;
  aferef_cfg.Hp1V8BuffEn = bTRUE;
  aferef_cfg.Disc1V1Cap = bFALSE;
  aferef_cfg.Disc1V8Cap = bFALSE;
  aferef_cfg.Hp1V8ThemBuff = bFALSE;
  aferef_cfg.Hp1V8Ilimit = bFALSE;
  aferef_cfg.Lp1V1BuffEn = bTRUE;
  aferef_cfg.Lp1V8BuffEn = bTRUE;
  /* LP reference control - turn off them to save powr*/
  aferef_cfg.LpBandgapEn = bTRUE;
  aferef_cfg.LpRefBufEn = bTRUE;
  aferef_cfg.LpRefBoostEn = bFALSE;
  AD5940_REFCfgS(&aferef_cfg);	
  
  lp_loop.LpDacCfg.LpdacSel = LPDAC_SEL;
  lp_loop.LpDacCfg.LpDacSrc = LPDACSRC_MMR;
  lp_loop.LpDacCfg.LpDacSW = LPDACSW_VBIAS2LPPA|LPDACSW_VBIAS2PIN|LPDACSW_VZERO2LPTIA|LPDACSW_VZERO2PIN;
  lp_loop.LpDacCfg.LpDacVzeroMux = LPDACVZERO_6BIT;
  lp_loop.LpDacCfg.LpDacVbiasMux = LPDACVBIAS_12BIT;
  lp_loop.LpDacCfg.LpDacRef = LPDACREF_2P5;
  lp_loop.LpDacCfg.DataRst = bFALSE;
  lp_loop.LpDacCfg.PowerEn = bTRUE;
  lp_loop.LpDacCfg.DacData6Bit = (uint32_t)((SnsCfg->Vzero-200)/DAC6BITVOLT_1LSB);
  lp_loop.LpDacCfg.DacData12Bit =(int32_t)((SnsCfg->SensorBias)/DAC12BITVOLT_1LSB) + lp_loop.LpDacCfg.DacData6Bit*64;
  if(lp_loop.LpDacCfg.DacData12Bit>lp_loop.LpDacCfg.DacData6Bit*64)
    lp_loop.LpDacCfg.DacData12Bit--;
  
  lp_loop.LpAmpCfg.LpAmpSel = LPAMP_SEL;
  lp_loop.LpAmpCfg.LpAmpPwrMod = LPAMPPWR_NORM;
  lp_loop.LpAmpCfg.LpPaPwrEn = bTRUE;
  lp_loop.LpAmpCfg.LpTiaPwrEn = bTRUE;
  lp_loop.LpAmpCfg.LpTiaRf = SnsCfg->LpTiaRf;
  lp_loop.LpAmpCfg.LpTiaRload = SnsCfg->LpTiaRl;
  lp_loop.LpAmpCfg.LpTiaRtia = SnsCfg->LptiaRtiaSel;
  lp_loop.LpAmpCfg.LpTiaSW = LPTIASW(5)|LPTIASW(2)|LPTIASW(3)|LPTIASW(6)|LPTIASW(4)|LPTIASW(12)|LPTIASW(13); 
  AD5940_LPLoopCfgS(&lp_loop);
  
  /* Step 4: Charge EC Sensor */
  AppChargeECSensor();
  
/* Step 5: Configure ADC for normal measurement */
  AppADCInit();
  
  sw_cfg.Dswitch = 0;
  sw_cfg.Pswitch = 0;
  sw_cfg.Nswitch = 0;
  sw_cfg.Tswitch = 0; 
  AD5940_SWMatrixCfgS(&sw_cfg);
  
  /* Enable all of them. They are automatically turned off during hibernate mode to save power */
  AD5940_AFECtrlS(AFECTRL_HPREFPWR|AFECTRL_SINC2NOTCH, bTRUE);
  AD5940_AFECtrlS(AFECTRL_SINC2NOTCH, bFALSE);
  
  return AD5940ERR_OK;
}

AD5940Err AppADCInit(void)
{
  AppAMPCfg_Type *pAmpCfg;
  DSPCfg_Type dsp_cfg;
  AppAMPGetCfg(&pAmpCfg);
  
  dsp_cfg.ADCBaseCfg.ADCMuxN = ADCMUXN_LPTIA0_N;
  dsp_cfg.ADCBaseCfg.ADCMuxP = ADCMUXP_LPTIA0_P;
  dsp_cfg.ADCBaseCfg.ADCPga = pAmpCfg->ADCPgaGain;
  
  memset(&dsp_cfg.ADCDigCompCfg, 0, sizeof(dsp_cfg.ADCDigCompCfg));
  dsp_cfg.ADCFilterCfg.ADCAvgNum = ADCAVGNUM_16;  /* Don't care becase it's disabled */
  dsp_cfg.ADCFilterCfg.ADCRate = ADCRATE_800KHZ;	/* @todo Add explanation in UG that SINC3 filter clock is same as ADC, when ADC runs at 32MHz, clear this bit to enable clock divider for SINC3 filter. Make sure SINC3 clock is below 16MHz. */
  dsp_cfg.ADCFilterCfg.ADCSinc2Osr = pAmpCfg->ADCSinc2Osr;
  dsp_cfg.ADCFilterCfg.ADCSinc3Osr = pAmpCfg->ADCSinc3Osr;
  dsp_cfg.ADCFilterCfg.BpSinc3 = bFALSE;
  dsp_cfg.ADCFilterCfg.BpNotch = bFALSE;
  dsp_cfg.ADCFilterCfg.Sinc2NotchEnable = bTRUE;
  dsp_cfg.ADCFilterCfg.Sinc2NotchClkEnable = bTRUE;
  dsp_cfg.ADCFilterCfg.Sinc3ClkEnable = bTRUE;
  dsp_cfg.ADCFilterCfg.WGClkEnable = bFALSE;
  dsp_cfg.ADCFilterCfg.DFTClkEnable = bFALSE;
  
  memset(&dsp_cfg.StatCfg, 0, sizeof(dsp_cfg.StatCfg)); /* Don't care about Statistic */
  AD5940_DSPCfgS(&dsp_cfg);
  
  return AD5940ERR_OK;
}

/* 
  Configure sequencer to measure EC current on SE0
*/
AD5940Err AppM355SeqMeasureGen(void)
{
  AD5940Err error = AD5940ERR_OK;
  uint32_t const *pSeqCmd;
  uint32_t SeqLen;
  AppAMPCfg_Type *pAmpCfg;
  AppAMPGetCfg(&pAmpCfg);
  uint32_t WaitClks;
  ClksCalInfo_Type clks_cal;
  
  clks_cal.DataType = DATATYPE_SINC2;
  clks_cal.DataCount = 10;
  clks_cal.ADCSinc2Osr = pAmpCfg->ADCSinc2Osr;
  clks_cal.ADCSinc3Osr = pAmpCfg->ADCSinc3Osr;
  clks_cal.ADCAvgNum = 0;
  clks_cal.RatioSys2AdcClk = pAmpCfg->SysClkFreq/pAmpCfg->AdcClkFreq;
  AD5940_ClksCalculate(&clks_cal, &WaitClks);
  WaitClks += 15;
  AD5940_SEQGenCtrl(bTRUE);
  /* Measure Ch0 */
  AD5940_ADCMuxCfgS(ADCMUXP_LPTIA0_P, ADCMUXN_LPTIA0_N);
  AD5940_AFECtrlS(AFECTRL_ADCPWR|AFECTRL_SINC2NOTCH, bTRUE);
  AD5940_SEQGenInsert(SEQ_WAIT(16*250));  
  AD5940_AFECtrlS(AFECTRL_ADCCNV, bTRUE);  /* Start ADC convert*/
  AD5940_SEQGenInsert(SEQ_WAIT(WaitClks));  /* wait for first data ready */
  AD5940_AFECtrlS(AFECTRL_ADCPWR|AFECTRL_ADCCNV|AFECTRL_SINC2NOTCH, bFALSE);  /* Stop ADC */
  
  AD5940_EnterSleepS();/* Goto hibernate */
  /* Sequence end. */
  error = AD5940_SEQGenFetchSeq(&pSeqCmd, &SeqLen);
  AD5940_SEQGenCtrl(bFALSE); /* Stop seuqncer generator */
  
  if(error == AD5940ERR_OK)
  {
    pAmpCfg->M355SeqInfo.SeqId = SEQID_0;
    pAmpCfg->M355SeqInfo.SeqRamAddr = pAmpCfg->SeqStartAddr ;
    pAmpCfg->M355SeqInfo.pSeqCmd = pSeqCmd;
    pAmpCfg->M355SeqInfo.SeqLen = SeqLen;
    /* Write command to SRAM */     
    AD5940_SEQCmdWrite(pAmpCfg->M355SeqInfo.SeqRamAddr, pSeqCmd, SeqLen);
  }
  else
    return error; /* Error */
  return AD5940ERR_OK;
}


/* This function initializes the application   */
AD5940Err AppAMPInit(uint32_t *pBuffer, uint32_t BufferSize)
{
  AD5940Err error = AD5940ERR_OK;
  SEQCfg_Type seq_cfg;
  FIFOCfg_Type fifo_cfg;
  
  if(AD5940_WakeUp(10) > 10)  /* Wakup AFE by read register, read 10 times at most */
    return AD5940ERR_WAKEUP;  /* Wakeup Failed */
  
  /* Configure sequencer and stop it */
  seq_cfg.SeqMemSize = SEQMEMSIZE_2KB;  /* 2kB SRAM is used for sequencer, others for data FIFO */
  seq_cfg.SeqBreakEn = bFALSE;
  seq_cfg.SeqIgnoreEn = bFALSE;
  seq_cfg.SeqCntCRCClr = bTRUE;
  seq_cfg.SeqEnable = bFALSE;
  seq_cfg.SeqWrTimer = 0;
  AD5940_SEQCfg(&seq_cfg);
  /* Reconfigure FIFO */
  AD5940_FIFOCtrlS(DFTSRC_SINC3, bFALSE);									/* Disable FIFO firstly */
  fifo_cfg.FIFOEn = bTRUE;
  fifo_cfg.FIFOMode = FIFOMODE_FIFO;
  fifo_cfg.FIFOSize = FIFOSIZE_4KB;                       /* 4kB for FIFO, The reset 2kB for sequencer */
  fifo_cfg.FIFOSrc = AppAmpCfg.DataFifoSrc;
  fifo_cfg.FIFOThresh = AppAmpCfg.M355FifoThresh;              
  AD5940_FIFOCfg(&fifo_cfg);

  AD5940_INTCClrFlag(AFEINTSRC_ALLINT); 
   
  /* Start sequence generator */
  /* Initialize sequencer generator */
  if((AppAmpCfg.AMPInited == bFALSE)||\
    (AppAmpCfg.bParaChanged == bTRUE))
  {
    if(pBuffer == 0)  return AD5940ERR_PARA;
    if(BufferSize == 0) return AD5940ERR_PARA;   
    AD5940_SEQGenInit(pBuffer, BufferSize);
    
    /* Generate M355 sequence */   
    error = AppM355SeqMeasureGen();
    if(error != AD5940ERR_OK) return error;
    AppAmpCfg.M355SeqInfo.WriteSRAM = bFALSE;
    AD5940_SEQInfoCfg(&AppAmpCfg.M355SeqInfo);
       
    AppAmpCfg.bParaChanged = bFALSE; /* Clear this flag as we already implemented the new configuration */
  }
  
  AD5940_SEQCtrlS(bTRUE);  /* Enable sequencer, and wait for trigger. It's disabled in initialization sequence */
  AD5940_ClrMCUIntFlag();   /* Clear interrupt flag generated before */
  AD5940_AFEPwrBW(AppAmpCfg.PwrMod, AFEBW_250KHZ);
  AppAmpCfg.AMPInited = bTRUE;  /* AMP application has been initialized. */
  return AD5940ERR_OK;
}

/* Modify registers when AFE wakeup */
static AD5940Err AppAMPRegModify(int32_t * const pData, uint32_t *pDataCount)
{
  if(AppAmpCfg.NumOfData > 0)
  {
    AppAmpCfg.FifoDataCount += *pDataCount/4;
    if(AppAmpCfg.FifoDataCount >= AppAmpCfg.NumOfData)
    {
      AD5940_WUPTCtrl(bFALSE);
      return AD5940ERR_OK;
    }
  }
  if(AppAmpCfg.StopRequired == bTRUE)
  {
    AD5940_WUPTCtrl(bFALSE);
    return AD5940ERR_OK;
  }
  return AD5940ERR_OK;
}

/* Depending on the data type, do appropriate data pre-process before return back to controller */
static AD5940Err AppAMPDataProcess(int32_t * const pData, uint32_t *pDataCount)
{
  uint32_t i, datacount;
  datacount = *pDataCount;

  for(i=0; i<datacount; i++)
    { 
      pData[i] &= 0xffff;
      AppAmpCfg.SensorCh0.ResultBuffer[i] = pData[i];
    }
  return AD5940ERR_OK;
}

/**

*/
AD5940Err AppAMPISR(void *pBuff, uint32_t *pCount)
{
  uint32_t FifoCnt;
  if(AD5940_WakeUp(10) > 10)  /* Wakup AFE by read register, read 10 times at most */
    return AD5940ERR_WAKEUP;  /* Wakeup Failed */
  AD5940_SleepKeyCtrlS(SLPKEY_LOCK);
	
  *pCount = 0;  
  if(AD5940_INTCTestFlag(AFEINTC_0, AFEINTSRC_DATAFIFOTHRESH) == bTRUE)
  {
    FifoCnt = AD5940_FIFOGetCnt();
    AD5940_FIFORd((uint32_t *)pBuff, FifoCnt);
    AD5940_INTCClrFlag(AFEINTSRC_DATAFIFOTHRESH);
    AppAMPRegModify(pBuff, &FifoCnt);   /* If there is need to do AFE re-configure, do it here when AFE is in active state */
		AD5940_SleepKeyCtrlS(SLPKEY_UNLOCK); 
    AD5940_EnterSleepS();  /* Manually put AFE back to hibernate mode. This operation only takes effect when register value is ACTIVE previously */
    /* Process data */ 
    AppAMPDataProcess((int32_t*)pBuff,&FifoCnt); 
    *pCount = FifoCnt;
    return 0;
  }
  
  return 0;
} 
/* Calculate current in uA */
float AppAMPCalcCurrent(uint32_t ADCcode, float RtiaVal)
{
  float fCurrent, fVoltage = 0.0;
  fVoltage = AD5940_ADCCode2Volt(ADCcode, AppAmpCfg.ADCPgaGain, AppAmpCfg.ADCRefVolt);
  fCurrent = fVoltage/RtiaVal;
  return -fCurrent*1000000;
}
