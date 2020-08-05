/******************************************************************************
@{
@file     PH_IMP.c
@brief    pH Impedance measurement of water quality.
@par      Revision History:
@version  V0.2
@author   ADI
@date     Feb 2020
@par      Revision History:
- V0.2, Feb 27th 2020: initial version.

Description:
-- For PH IMP (PH Impedance) measurement.
-- EC_mode_2wireLploop, LPLOOP0 used with Voltammetry method

Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.
This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/
#include "stdio.h"
#include "math.h"
#include "ad5940.h"
#include "meter.h"

LPLoopCfg_Type imp_lp_cfg;
DSPCfg_Type imp_dsp_cfg;
HSDACCfg_Type imp_hsdac_cfg;
WGCfg_Type imp_wg_cfg;
ADCBaseCfg_Type imp_adc_cfg;

fImpCar_Type Vol_phimp;
fImpCar_Type Cur_phimp;

Result_Imp ImpResult_PHIMP={0,0,0};

PHIMPcfg_Type phimp_cfg = 
{
  .SweepCfg.SweepEn = bTRUE,
  .SweepCfg.SweepStart = 10.0f,
  .SweepCfg.SweepStop = 20.0f,
  .SweepCfg.SweepPoints = 2,
  .SweepCfg.SweepLog = bFALSE,
  .SweepCfg.SweepIndex = 0,	
  
  .Sinfreq = 10.0f,
  .SinVolt = 100.0f,
  .RtiaVal = LPTIA_EXT_RTIA,
  .AdcPgaGain = ADCPGA_1P5,
};

void Meter_PHIMP(void)
{
  uint32_t count = 0;
  Result_Imp Temp_Result = {0,0,0};
  while(count<phimp_cfg.SweepCfg.SweepPoints)
  {
    count++;
    PHIMP_Test();
    Temp_Result = PHIMP_Calculate(&Vol_phimp,&Cur_phimp);	
    UARTCmd_cmd_sent("Meas",16,1,Temp_Result.Freq,Temp_Result.Mag_result,Temp_Result.Pha_result,0);	
  }
}

/**
* @brief PH_IMP initialization function. 
**/
AD5940Err PHIMP_Init(void)
{
  if (phimp_cfg.SweepCfg.SweepEn == bTRUE)
  {
    phimp_cfg.SweepCfg.SweepIndex = 0;
    phimp_cfg.FreqofData = phimp_cfg.SweepCfg.SweepStart;
    phimp_cfg.SweepCurrFreq = phimp_cfg.SweepCfg.SweepStart;
    AD5940_SweepNext(&phimp_cfg.SweepCfg, &phimp_cfg.SweepNextFreq);
    phimp_cfg.Sinfreq = phimp_cfg.SweepCurrFreq;
  }
  else
  {
    phimp_cfg.SweepCurrFreq = phimp_cfg.Sinfreq;
  }
  /* Configure exitation signal and LPTIA */
  imp_wg_cfg.WgType = WGTYPE_SIN;
  imp_wg_cfg.SinCfg.SinAmplitudeWord = (uint16_t)(phimp_cfg.SinVolt/1100.0*2047) ;
  imp_wg_cfg.SinCfg.SinFreqWord = AD5940_WGFreqWordCal(phimp_cfg.Sinfreq,16000000);;
  imp_wg_cfg.SinCfg.SinOffsetWord = 0;
  imp_wg_cfg.SinCfg.SinPhaseWord = 0;
  imp_wg_cfg.GainCalEn = bFALSE;
  imp_wg_cfg.OffsetCalEn = bFALSE;
  AD5940_WGCfgS(&imp_wg_cfg);
  
  imp_hsdac_cfg.ExcitBufGain = EXCITBUFGAIN_2; // Don't care about it.
  imp_hsdac_cfg.HsDacGain = HSDACGAIN_1;        // Don't care about it.
  imp_hsdac_cfg.HsDacUpdateRate = 255;            //16MHz minimum updaterate 10*e6/255=62.7Hz
  AD5940_HSDacCfgS(&imp_hsdac_cfg);
  
  imp_lp_cfg.LpDacCfg.LpdacSel = LPDAC0;
  imp_lp_cfg.LpDacCfg.DacData12Bit = 0x800;               	/* Controlled by WG */
  imp_lp_cfg.LpDacCfg.DacData6Bit = 32;               //Vbias =1.3V, Vbias don't care and come from WG. WG is changed around the centre 0x800(1.3V)
  imp_lp_cfg.LpDacCfg.DataRst = bFALSE;                    /* Do not keep DATA registers at reset status */
  imp_lp_cfg.LpDacCfg.LpDacSW = LPDACSW_VBIAS2LPPA|LPDACSW_VZERO2LPTIA; //Veros and Vbias can't connect with cap.
  imp_lp_cfg.LpDacCfg.LpDacRef = LPDACREF_2P5;            /* Select internal 2.5V reference */
  imp_lp_cfg.LpDacCfg.LpDacSrc = LPDACSRC_WG;            /* The LPDAC data comes from  WG in this case */
  imp_lp_cfg.LpDacCfg.LpDacVbiasMux = LPDACVBIAS_6BIT;   /* Connect Vbias signal to 6Bit LPDAC output */
  imp_lp_cfg.LpDacCfg.LpDacVzeroMux = LPDACVZERO_12BIT;    /* Connect Vzero signal to 12bit LPDAC output */
  imp_lp_cfg.LpDacCfg.PowerEn = bTRUE;                    /* Power up LPDAC */
  
  imp_lp_cfg.LpAmpCfg.LpAmpSel = LPAMP0;
  imp_lp_cfg.LpAmpCfg.LpAmpPwrMod = LPAMPPWR_NORM;
  imp_lp_cfg.LpAmpCfg.LpPaPwrEn = bTRUE;
  imp_lp_cfg.LpAmpCfg.LpTiaPwrEn = bTRUE;
  imp_lp_cfg.LpAmpCfg.LpTiaRf = LPTIARF_1M;
  imp_lp_cfg.LpAmpCfg.LpTiaRload = LPTIARLOAD_SHORT;
  imp_lp_cfg.LpAmpCfg.LpTiaRtia = LPTIARTIA_OPEN;
  imp_lp_cfg.LpAmpCfg.LpTiaSW = LPTIASW(5)|LPTIASW(2)|LPTIASW(10)|LPTIASW(9); 
  AD5940_LPLoopCfgS(&imp_lp_cfg);
  
  /* Configure ADC */
  imp_dsp_cfg.ADCBaseCfg.ADCMuxN = ADCMUXN_VZERO0;
  imp_dsp_cfg.ADCBaseCfg.ADCMuxP = ADCMUXP_VBIAS0;
  imp_dsp_cfg.ADCBaseCfg.ADCPga = phimp_cfg.AdcPgaGain;
  
  imp_dsp_cfg.ADCFilterCfg.ADCAvgNum = ADCAVGNUM_16;
  imp_dsp_cfg.ADCFilterCfg.ADCRate = ADCRATE_800KHZ;	/* @todo what does this parameter decide */
  imp_dsp_cfg.ADCFilterCfg.ADCSinc2Osr = ADCSINC2OSR_22;
  imp_dsp_cfg.ADCFilterCfg.ADCSinc3Osr = ADCSINC3OSR_2;
  imp_dsp_cfg.ADCFilterCfg.BpNotch = bTRUE;
  imp_dsp_cfg.ADCFilterCfg.BpSinc3 = bFALSE;
  imp_dsp_cfg.ADCFilterCfg.Sinc2NotchEnable = bTRUE;
  imp_dsp_cfg.DftCfg.DftNum = DFTNUM_4096;
  imp_dsp_cfg.DftCfg.DftSrc = DFTSRC_SINC2NOTCH;
  imp_dsp_cfg.DftCfg.HanWinEn = bTRUE;
  
  AD5940_DSPCfgS(&imp_dsp_cfg);
  
  return AD5940ERR_OK;
  
}

/**
* @brief pH impedance test single time. 
**/
void PHIMP_Test(void)
{	
  ImpResult_t ImpResult_phimp;
  
  SnsACSigChainCfg(phimp_cfg.SweepCurrFreq);
  AD5940_WGFreqCtrlS(phimp_cfg.SweepCurrFreq, 16000000); //update the frequency
  
  /* Excitation signal voltage measurement */
  imp_adc_cfg.ADCMuxN = ADCMUXN_LPTIA0_N;
  imp_adc_cfg.ADCMuxP = ADCMUXP_VCE0;
  imp_adc_cfg.ADCPga = ADCPGA_1P5;
  AD5940_ADCBaseCfgS(&imp_adc_cfg);
  
  AD5940_Delay10us(20);  /* Delay 200us */
  
  AD5940_AFECtrlS(AFECTRL_ADCPWR|AFECTRL_WG|AFECTRL_SINC2NOTCH, bTRUE);  /* Enable Waveform generator */
  AD5940_AFECtrlS(AFECTRL_ADCCNV|AFECTRL_DFT, bTRUE);  /* Start ADC convert and DFT */
  AD5940_Delay10us(50000);  /* Delay 200us */
  
  while(AD5940_INTCTestFlag(AFEINTC_1,AFEINTSRC_DFTRDY)== bFALSE)  
  {	;
  }
  AD5940_INTCClrFlag(AFEINTSRC_DFTRDY);
  AD5940_AFECtrlS(AFECTRL_ADCPWR|AFECTRL_ADCCNV|AFECTRL_DFT|AFECTRL_SINC2NOTCH, bFALSE);  /* Stop ADC */
  ImpResult_phimp.DFT_result[0] = convertDftToInt(AD5940_ReadAfeResult(AFERESULT_DFTREAL));
  ImpResult_phimp.DFT_result[1] = convertDftToInt(AD5940_ReadAfeResult(AFERESULT_DFTIMAGE));
  
  /* Current Measurement */
  imp_adc_cfg.ADCMuxN = ADCMUXN_LPTIA0_N;
  imp_adc_cfg.ADCMuxP = ADCMUXP_AIN4;
  imp_adc_cfg.ADCPga = phimp_cfg.AdcPgaGain;
  AD5940_ADCBaseCfgS(&imp_adc_cfg);
  AD5940_Delay10us(20);  /* Delay 200us */
  
  AD5940_AFECtrlS(AFECTRL_ADCPWR|AFECTRL_SINC2NOTCH, bTRUE);  /* Enable Waveform generator */
  AD5940_AFECtrlS(AFECTRL_ADCCNV|AFECTRL_DFT, bTRUE);  /* Start ADC convert and DFT */
  AD5940_Delay10us(50);  /* Delay 200us */
  
  while(AD5940_INTCTestFlag(AFEINTC_1,AFEINTSRC_DFTRDY)== bFALSE)  
  {	;
  }
  AD5940_INTCClrFlag(AFEINTSRC_DFTRDY);
  AD5940_AFECtrlS(AFECTRL_ADCPWR|AFECTRL_ADCCNV|AFECTRL_DFT|AFECTRL_WG|AFECTRL_SINC2NOTCH, bFALSE);  /* Stop ADC */
  ImpResult_phimp.DFT_result[2] = convertDftToInt(AD5940_ReadAfeResult(AFERESULT_DFTREAL));
  ImpResult_phimp.DFT_result[3] = convertDftToInt(AD5940_ReadAfeResult(AFERESULT_DFTIMAGE));
  
  
  Vol_phimp.Real = (float)ImpResult_phimp.DFT_result[0];
  Vol_phimp.Image = (float)(-ImpResult_phimp.DFT_result[1]);//the Imaginary part in register is the opposite number
  Cur_phimp.Real = (float)ImpResult_phimp.DFT_result[2];
  Cur_phimp.Image = (float)(-ImpResult_phimp.DFT_result[3]);
  
  phimp_cfg.FreqofData = phimp_cfg.SweepCurrFreq;
  /* Calculate next frequency point */
  if(phimp_cfg.SweepCfg.SweepEn == bTRUE)
  {
    phimp_cfg.FreqofData = phimp_cfg.SweepCurrFreq;
    phimp_cfg.SweepCurrFreq = phimp_cfg.SweepNextFreq;
    AD5940_SweepNext(&phimp_cfg.SweepCfg, &phimp_cfg.SweepNextFreq);
  }
}

/**
* @brief EC resistor function. 
* @return Result of impedance: amplitude& phase, resistor & capacitor, Real and Image
**/
Result_Imp PHIMP_Calculate(fImpCar_Type *Rvol, fImpCar_Type *Rcur)
{
  
  fImpCar_Type res;
  fImpCar_Type Rphimp;
  
  Rcur->Image=-1*Rcur->Image;// the direction of current and vlotage is opposite
  Rcur->Real=-1*Rcur->Real;
  
  res.Real = phimp_cfg.RtiaVal;
  res.Image = 0;
  
  Rphimp = AD5940_ComplexDivFloat(Rvol,Rcur);
  Rphimp = AD5940_ComplexMulFloat(&Rphimp,&res);
  
  ImpResult_PHIMP.Freq = phimp_cfg.FreqofData;
  /**********Amplitude and phase*********/		
  ImpResult_PHIMP.Mag_result = AD5940_ComplexMag(&Rphimp);
  ImpResult_PHIMP.Pha_result = AD5940_ComplexPhase(&Rphimp)*180/PI;
  
  return ImpResult_PHIMP;	
}

/**
* @brief PHIMP terniminate. Terminate the measurement and restore the original meter state 
**/
AD5940Err PHIMP_Terminate(void)
{
  AD5940_StructInit(&imp_lp_cfg, sizeof(imp_lp_cfg));         /* Reset everything to zero(OFF) */
  AD5940_StructInit(&imp_dsp_cfg, sizeof(imp_dsp_cfg));         /* Reset everything to zero(OFF) */
  AD5940_StructInit(&imp_hsdac_cfg, sizeof(imp_hsdac_cfg));         /* Reset everything to zero(OFF) */
  AD5940_StructInit(&imp_wg_cfg, sizeof(imp_wg_cfg));         /* Reset everything to zero(OFF) */
  AD5940_WGCfgS(&imp_wg_cfg);
  AD5940_DSPCfgS(&imp_dsp_cfg);
  AD5940_LPLoopCfgS(&imp_lp_cfg);
  AD5940_HSDacCfgS(&imp_hsdac_cfg);
  
  return AD5940ERR_OK;
}

/**
@brief Filter configuration based on different frequency
*/
AD5940Err SnsACSigChainCfg(float freq)
{
  if (freq < .11){
    imp_dsp_cfg.ADCFilterCfg.ADCSinc2Osr = ADCSINC2OSR_1333;
    imp_dsp_cfg.ADCFilterCfg.ADCSinc3Osr = ADCSINC3OSR_5;
    imp_dsp_cfg.DftCfg.DftNum = DFTNUM_2048;
  }
  else if (freq < .51){
    imp_dsp_cfg.ADCFilterCfg.ADCSinc2Osr = ADCSINC2OSR_640;
    imp_dsp_cfg.ADCFilterCfg.ADCSinc3Osr = ADCSINC3OSR_4;
    imp_dsp_cfg.DftCfg.DftNum = DFTNUM_8192;
  }
  else if(freq<5){
    imp_dsp_cfg.ADCFilterCfg.ADCSinc2Osr = ADCSINC2OSR_533;
    imp_dsp_cfg.ADCFilterCfg.ADCSinc3Osr = ADCSINC3OSR_4;
    imp_dsp_cfg.DftCfg.DftNum = DFTNUM_4096;                    
  }  
  else if(freq<450){
    imp_dsp_cfg.ADCFilterCfg.ADCSinc2Osr = ADCSINC2OSR_22;
    imp_dsp_cfg.ADCFilterCfg.ADCSinc3Osr = ADCSINC3OSR_4;
    imp_dsp_cfg.DftCfg.DftNum = DFTNUM_4096;   
  }
  else{
    imp_dsp_cfg.ADCFilterCfg.ADCSinc2Osr = ADCSINC2OSR_178;
    imp_dsp_cfg.ADCFilterCfg.ADCSinc3Osr = ADCSINC3OSR_4;
    imp_dsp_cfg.DftCfg.DftNum = DFTNUM_16384;
  }
  AD5940_DSPCfgS(&imp_dsp_cfg);
  
  return AD5940ERR_OK;
}


