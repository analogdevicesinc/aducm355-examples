/******************************************************************************
@{
@file     DO.c
@brief    DO measurement of water quality.
@par      Revision History:
@version  V0.2
@author   ADI
@date     Feb 2020
@par      Revision History:
- V0.2, Feb 27th 2020: initial version.

Decription:
-- For DO(dissolved oxygen) measurement
-- LPLOOP measure current with Vbias voltage is 675mV .
-- Support external Rtia 1MOhm and internal Rtia 512KOhm.

Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.
This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/
#include "stdio.h"
#include "math.h"
#include "ad5940.h"
#include "meter.h"

DOcfg_Type do_cfg = 
{
  .Vzero = 425.0f,
  .Vbias = 1100.0f,
  .HstiaRtiaSel = LPTIARTIA_512K,
  .ADCPgaGain = ADCPGA_1P5,
  .DO_gain = -24.497f, // sensor1 @23 centidegree	
  .DO_offset = 0.0f,
};

LPLoopCfg_Type dolp_cfg;
DSPCfg_Type dodsp_cfg;

/**************Measurement mode*************/
float Meter_DO(void)
{
  float Temp_Result=0;
  float Temp_Cur=0;
  
  Temp_Cur = DO_Test();
  printf("DO(Cur):%.4f\n", Temp_Cur);
  Temp_Result = DO_Calculate(Temp_Cur,do_cfg.DO_gain,do_cfg.DO_offset);
  
  return Temp_Result;
}

/**
* @brief DO initialization function. 
**/
AD5940Err DO_Init(void)
{
  /* Configure LPDAC and LPTIA */	
  dolp_cfg.LpDacCfg.LpdacSel = LPDAC1;
  dolp_cfg.LpDacCfg.DacData12Bit = (uint32_t)((do_cfg.Vbias-200)/DAC12BITVOLT_1LSB);;             
  dolp_cfg.LpDacCfg.DacData6Bit = (uint32_t)((do_cfg.Vzero-200)/DAC6BITVOLT_1LSB);               
  dolp_cfg.LpDacCfg.DataRst = bFALSE;                    /* Do not keep DATA registers at reset status */
  dolp_cfg.LpDacCfg.LpDacSW = LPDACSW_VBIAS2LPPA|LPDACSW_VZERO2LPTIA; //Veros and Vbias can't connect with cap.
  dolp_cfg.LpDacCfg.LpDacRef = LPDACREF_2P5;            /* Select internal 2.5V reference */
  dolp_cfg.LpDacCfg.LpDacSrc = LPDACSRC_MMR;            
  dolp_cfg.LpDacCfg.LpDacVbiasMux = LPDACVBIAS_12BIT;   /* Connect Vbias signal to 12Bit LPDAC output */
  dolp_cfg.LpDacCfg.LpDacVzeroMux = LPDACVZERO_6BIT;    /* Connect Vzero signal to 6bit LPDAC output */
  dolp_cfg.LpDacCfg.PowerEn = bTRUE;                    /* Power up LPDAC */
  
  dolp_cfg.LpAmpCfg.LpAmpSel = LPAMP1;
  dolp_cfg.LpAmpCfg.LpAmpPwrMod = LPAMPPWR_NORM;
  dolp_cfg.LpAmpCfg.LpPaPwrEn = bTRUE;
  dolp_cfg.LpAmpCfg.LpTiaPwrEn = bTRUE;
  dolp_cfg.LpAmpCfg.LpTiaRf = LPTIARF_1M;
  dolp_cfg.LpAmpCfg.LpTiaRload = LPTIARLOAD_SHORT;
  dolp_cfg.LpAmpCfg.LpTiaRtia = do_cfg.HstiaRtiaSel;
  dolp_cfg.LpAmpCfg.LpTiaSW = LPTIASW(10)|LPTIASW(2)|LPTIASW(12)|LPTIASW(13); 
  AD5940_LPLoopCfgS(&dolp_cfg);
  
  /* Configure ADC */
  dodsp_cfg.ADCBaseCfg.ADCMuxN = ADCMUXN_LPTIA1_N;
  dodsp_cfg.ADCBaseCfg.ADCMuxP = ADCMUXP_LPTIA1_P;
  dodsp_cfg.ADCBaseCfg.ADCPga = do_cfg.ADCPgaGain;
  
  dodsp_cfg.ADCFilterCfg.ADCAvgNum = ADCAVGNUM_16;
  dodsp_cfg.ADCFilterCfg.ADCRate = ADCRATE_800KHZ;	/* @todo what does this parameter decide */
  dodsp_cfg.ADCFilterCfg.ADCSinc2Osr = ADCSINC2OSR_667;
  dodsp_cfg.ADCFilterCfg.ADCSinc3Osr = ADCSINC3OSR_2;
  dodsp_cfg.ADCFilterCfg.BpNotch = bFALSE;
  dodsp_cfg.ADCFilterCfg.BpSinc3 = bFALSE;
  dodsp_cfg.ADCFilterCfg.Sinc2NotchEnable = bTRUE; 
  AD5940_DSPCfgS(&dodsp_cfg);
  
  return AD5940ERR_OK;
  
}

/**
* @brief DO Test. Measure the sensor voltage through AIN5 Pin
**/
float DO_Test(void)
{
  float DO_vol;
  float DO_cur;
  uint32_t DO_code;
  const uint32_t lprtia_value_table[]={0,200,1000,2000,3000,4000,6000,8000,10000\
    ,12000,16000,20000,24000,30000,32000,40000,48000\
      ,64000,85000,96000,100000,120000,128000,1680000,196000,256000,512000};	/* HSRTIA value table */
  AD5940_AFECtrlS(AFECTRL_ADCPWR|AFECTRL_SINC2NOTCH, bTRUE);
  AD5940_AFECtrlS(AFECTRL_ADCCNV, bTRUE);  /* Start ADC convert*/
  
  while(AD5940_INTCTestFlag(AFEINTC_1,AFEINTSRC_SINC2RDY)==bFALSE)
  {;
  }
  AD5940_INTCClrFlag(AFEINTSRC_SINC2RDY);
  AD5940_AFECtrlS(AFECTRL_ADCPWR|AFECTRL_ADCCNV|AFECTRL_SINC2NOTCH, bFALSE);  /* Stop ADC */
  
  DO_code = AD5940_ReadAfeResult(AFERESULT_SINC2);
  DO_vol = AD5940_ADCCode2Volt(DO_code,do_cfg.ADCPgaGain,1.82)*1000.0;
  DO_cur = DO_vol/lprtia_value_table[do_cfg.HstiaRtiaSel]*1000; //unit is uA
  return DO_cur;
}

/**
* @brief DO Calculate. Calculate the DO value from voltage
**/
float DO_Calculate(float DO_cur, float DO_gain, float DO_offset)
{
  float DO_Result = 0;
  DO_Result = DO_cur*DO_gain+DO_offset;
  
  return DO_Result;
}

/**
* @brief DO terniminate. Terminate the measurement and restore the original meter state 
**/
AD5940Err DO_Terminate(void)
{
  AD5940_StructInit(&dolp_cfg, sizeof(dolp_cfg));         /* Reset everything to zero(OFF) */
  AD5940_StructInit(&dodsp_cfg, sizeof(dodsp_cfg));         /* Reset everything to zero(OFF) */
  AD5940_DSPCfgS(&dodsp_cfg);
  
  return AD5940ERR_OK;
}

