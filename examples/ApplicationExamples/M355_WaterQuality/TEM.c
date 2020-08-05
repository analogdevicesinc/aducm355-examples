/******************************************************************************
@{
@file     TEM.c
@brief    TEM measurement of water quality.
@par      Revision History:
@version  V0.2
@author   ADI
@date     Feb 2020
@par      Revision History:
- V0.2, Feb 27th 2020: initial version.

Description:
-- For TEM (tempereture) measurement. 
-- Use RTD sensor. AIN1&RE1&AIN2&DE1
-- Enabling low frequencies will lead measurement to take several minutes.
-- Use low excitation voltage to minimize self-heat effect. No DC bias.
-- Ratio method, compare with RCAL1 resistor of 1K.
-- Support temperature conversion of sensor PT100 & PT1000.


Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.
This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/
#include "stdio.h"
#include "math.h"
#include "ad5940.h"
#include "meter.h"

TEMcfg_Type tem_cfg = 
{
  .Sinfreq = 100.0f,             // Frequency of excitation signal
  .DACVoltPP = 25.0f,           // DAC output voltage in mV peak to peak. Maximum value is 800mVpp. Peak to peak voltage
  .ExcitBufGain = EXCITBUFGAIN_2,// Select from  EXCTBUFGAIN_2, EXCTBUFGAIN_0P25     
  .HsDacGain = HSDACGAIN_1,      // Select from  HSDACGAIN_1, HSDACGAIN_0P2 
  .AdcPgaGain = ADCPGA_1P5,      // PGA Gain select, We must ensure signal is in range of +-1.5V which is limited by ADC input stage */   
  .HstiaRtiaSel = HSTIARTIA_1K,  // Use internal RTIA
  .RcalVal = AFE_RCAL_0,         // Rcal value in Ohm */
};

HSLoopCfg_Type temhs_cfg;
DSPCfg_Type temdsp_cfg;
SWMatrixCfg_Type temsw_cfg;

fImpCar_Type Rcal_tem;
fImpCar_Type Rz_tem;

Result_Imp ImpResult_TEM={0,0,0};

/**************Measurement mode*************/
float Meter_TEM(void)
{
  float Temp_Result=0;
  Result_Imp Temp_Imp = {0,0,0};
  TEM_Test();
  Temp_Imp = TEM_Res_Cal(&Rcal_tem,&Rz_tem);
  printf("TEM(Mag):%.4f\n", Temp_Imp.Mag_result);
  Temp_Result = TEM_Calculation(Temp_Imp.Mag_result);
  return Temp_Result;
}

/**
* @brief TEM initialization function. 
**/
AD5940Err TEM_Init(void)
{
  /* Configure exitation loop and HSTIA */
  temhs_cfg.HsDacCfg.ExcitBufGain = tem_cfg.ExcitBufGain;
  temhs_cfg.HsDacCfg.HsDacGain = tem_cfg.HsDacGain ;
  temhs_cfg.HsDacCfg.HsDacUpdateRate = 50;
  
  temhs_cfg.WgCfg.GainCalEn = bFALSE;
  temhs_cfg.WgCfg.OffsetCalEn = bFALSE;
  temhs_cfg.WgCfg.WgType = WGTYPE_SIN;
  temhs_cfg.WgCfg.SinCfg.SinAmplitudeWord = (uint32_t)(tem_cfg.DACVoltPP/800.0f*2047 + 0.5f);;
  temhs_cfg.WgCfg.SinCfg.SinFreqWord = AD5940_WGFreqWordCal(tem_cfg.Sinfreq,16000000);
  temhs_cfg.WgCfg.SinCfg.SinOffsetWord = 0;
  temhs_cfg.WgCfg.SinCfg.SinPhaseWord = 0;
  
  temhs_cfg.HsTiaCfg.DiodeClose = bFALSE;
  temhs_cfg.HsTiaCfg.HstiaBias = HSTIABIAS_1P1;
  temhs_cfg.HsTiaCfg.HstiaCtia = 31; /* 31pF + 2pF */
  temhs_cfg.HsTiaCfg.HstiaDeRload = HSTIADERLOAD_OPEN ;
  temhs_cfg.HsTiaCfg.HstiaDeRtia = HSTIADERTIA_OPEN;
  temhs_cfg.HsTiaCfg.HstiaRtiaSel = tem_cfg.HstiaRtiaSel;
  temhs_cfg.HsTiaCfg.HstiaDe1Rload = HSTIADERLOAD_OPEN;
  temhs_cfg.HsTiaCfg.HstiaDe1Rtia = HSTIADERTIA_OPEN;
  
  temhs_cfg.SWMatCfg.Dswitch = SWD_RCAL0;
  temhs_cfg.SWMatCfg.Nswitch = SWP_RCAL0;
  temhs_cfg.SWMatCfg.Pswitch = SWN_RCAL1;
  temhs_cfg.SWMatCfg.Tswitch = SWT_RCAL1|SWT_TRTIA;
  
  AD5940_HSLoopCfgS(&temhs_cfg);
  
  /* Configure ADC */
  temdsp_cfg.ADCBaseCfg.ADCMuxN = ADCMUXN_HSTIA_N;
  temdsp_cfg.ADCBaseCfg.ADCMuxP = ADCMUXP_HSTIA_P;
  temdsp_cfg.ADCBaseCfg.ADCPga = tem_cfg.AdcPgaGain;
  
  temdsp_cfg.ADCFilterCfg.ADCAvgNum = ADCAVGNUM_16;
  temdsp_cfg.ADCFilterCfg.ADCRate = ADCRATE_800KHZ;	/* @todo what does this parameter decide */
  temdsp_cfg.ADCFilterCfg.ADCSinc2Osr = ADCSINC2OSR_22;
  temdsp_cfg.ADCFilterCfg.ADCSinc3Osr = ADCSINC3OSR_4;
  temdsp_cfg.ADCFilterCfg.BpNotch = bTRUE;
  temdsp_cfg.ADCFilterCfg.BpSinc3 = bFALSE;
  temdsp_cfg.ADCFilterCfg.Sinc2NotchEnable = bTRUE;	
  temdsp_cfg.DftCfg.DftNum = DFTNUM_4096;
  temdsp_cfg.DftCfg.DftSrc = DFTSRC_SINC2NOTCH;
  temdsp_cfg.DftCfg.HanWinEn = bTRUE;  
  AD5940_DSPCfgS(&temdsp_cfg);
  
  return AD5940ERR_OK;
}

/**
* @brief TEM test. Automatic choice of Rtia and Rcal 
**/
void TEM_Test(void)
{	
  ImpResult_t ImpResult_tem;
  
  /* RLOAD Measurement */
  temsw_cfg.Dswitch = SWD_AIN1;
  temsw_cfg.Pswitch = SWP_RE1;
  temsw_cfg.Nswitch = SWN_AIN2;
  temsw_cfg.Tswitch = SWT_DE1|SWT_TRTIA;
  AD5940_SWMatrixCfgS(&temsw_cfg);
  AD5940_Delay10us(20);  /* Delay 200us */
  
  AD5940_AFECtrlS(AFECTRL_HSTIAPWR|AFECTRL_INAMPPWR|AFECTRL_EXTBUFPWR|\
    AFECTRL_WG|AFECTRL_DACREFPWR|AFECTRL_HSDACPWR,bTRUE);
  AD5940_AFECtrlS(AFECTRL_ADCPWR|AFECTRL_SINC2NOTCH, bTRUE);  /* Enable Waveform generator */
  AD5940_AFECtrlS(AFECTRL_ADCCNV|AFECTRL_DFT, bTRUE);  /* Start ADC convert and DFT */
  AD5940_Delay10us(5);  /* Delay 50us */
  
  while(AD5940_INTCTestFlag(AFEINTC_1,AFEINTSRC_DFTRDY)== bFALSE)  
  {	;
  }
  AD5940_INTCClrFlag(AFEINTSRC_DFTRDY);	
  ImpResult_tem.DFT_result[0] = convertDftToInt(AD5940_ReadAfeResult(AFERESULT_DFTREAL));
  ImpResult_tem.DFT_result[1] = convertDftToInt(AD5940_ReadAfeResult(AFERESULT_DFTIMAGE));
  AD5940_AFECtrlS(AFECTRL_ADCPWR|AFECTRL_ADCCNV|AFECTRL_DFT|AFECTRL_WG, bFALSE);  /* Stop ADC */
  
  
  /* RCAL Measurement */
  temsw_cfg.Dswitch = SWD_RCAL0;
  temsw_cfg.Pswitch = SWP_RCAL0;
  temsw_cfg.Nswitch = SWN_RCAL1;
  temsw_cfg.Tswitch = SWT_RCAL1|SWT_TRTIA;
  AD5940_SWMatrixCfgS(&temsw_cfg);
  AD5940_Delay10us(20);  /* Delay 200us */
  
  AD5940_AFECtrlS(AFECTRL_ADCPWR|AFECTRL_SINC2NOTCH|AFECTRL_WG, bTRUE);  /* Enable Waveform generator */
  AD5940_AFECtrlS(AFECTRL_ADCCNV|AFECTRL_DFT, bTRUE);  /* Start ADC convert and DFT */
  AD5940_Delay10us(5);  /* Delay 50us */
  
  while(AD5940_INTCTestFlag(AFEINTC_1,AFEINTSRC_DFTRDY)== bFALSE)  
  {	;
  }
  AD5940_INTCClrFlag(AFEINTSRC_DFTRDY);	
  ImpResult_tem.DFT_result[2] = convertDftToInt(AD5940_ReadAfeResult(AFERESULT_DFTREAL));
  ImpResult_tem.DFT_result[3] = convertDftToInt(AD5940_ReadAfeResult(AFERESULT_DFTIMAGE));
  AD5940_AFECtrlS(AFECTRL_ADCPWR|AFECTRL_ADCCNV|AFECTRL_DFT|AFECTRL_WG, bFALSE);  /* Stop ADC */
  
  
  AD5940_AFECtrlS(AFECTRL_ADCPWR|AFECTRL_ADCCNV|AFECTRL_DFT|AFECTRL_WG, bFALSE);  /* Stop ADC convert and DFT */
  AD5940_AFECtrlS(AFECTRL_HSTIAPWR|AFECTRL_INAMPPWR|AFECTRL_EXTBUFPWR|\
    AFECTRL_WG|AFECTRL_DACREFPWR|AFECTRL_HSDACPWR,bFALSE);
  
  Rz_tem.Real = (float)ImpResult_tem.DFT_result[0];
  Rz_tem.Image = (float)(-ImpResult_tem.DFT_result[1]);//the Imaginary part in register is the opposite number
  Rcal_tem.Real = (float)ImpResult_tem.DFT_result[2];
  Rcal_tem.Image = (float)(-ImpResult_tem.DFT_result[3]);
  
} 

/**
* @brief TEM resistor function. 
* @return Result of impedance: amplitude& phase, resistor & capacitor, Real and Image
**/
Result_Imp TEM_Res_Cal(fImpCar_Type *Rcal, fImpCar_Type *Rz)
{
  
  fImpCar_Type res;
  fImpCar_Type Rec;
  
  res.Real = tem_cfg.RcalVal;
  res.Image = 0;
  
  Rec = AD5940_ComplexDivFloat(Rcal,Rz);
  Rec = AD5940_ComplexMulFloat(&Rec,&res);
  
  ImpResult_TEM.Freq = tem_cfg.Sinfreq;
  /**********Amplitude and phase*********/		
  ImpResult_TEM.Mag_result = AD5940_ComplexMag(&Rec);
  ImpResult_TEM.Pha_result = AD5940_ComplexPhase(&Rec)*180/PI;
  /********Resistor and capcitor************/		
  //	res.Real = 1;
  //	res.Image = 0;
  //	Rec = AD5940_ComplexDivFloat(&res,Rz);
  //	ImpResult_TEM.Mag_result = 1/Rec.Real;
  //	ImpResult_TEM.Pha_result = Rec.Image/2/PI/tem_cfg.Sinfreq*1e12f;
  /*********Real and Image******/
  //	ImpResult_TEM.Mag_result = Rec.Real;
  //	ImpResult_TEM.Pha_result = Rec.Image;
  return ImpResult_TEM;	
}

/**
* @brief  Convert the resistor to temeperature.
Automatic judgment of sensor type including PT100&PT1000.
The range of PT100 is 0~600 centigrade degree.
* @return The temperature of PT100/PT1000
**/
float TEM_Calculation(float Res)
{
  int32_t err1 = (int32_t)Res-1000;
  int32_t err2 = (int32_t)Res-100;
  
  float A = 0;
  float B = 0;
  float temp = 0;
  int32_t R0 = 0;
  
  /*PT1000 range Rt=R0(1+At+Bt^2)*/
  if (sqrt(err1^2)<sqrt(err2^2))
  {
    //printf("PT1000(Tem):");
    R0 = 1000;
    A = 0.0038623139728;
    B = -0.00000065314932626;
  }
  /*PT100 range -200~600 centigrade degree, when the temperature is 0~600, Rt=R0(1+At+Bt^2);
  when the temperature is -200~0, Rt=R0(1+At+Bt^2+C*(t-100)*t^3),this code provide conversion of 0~600,
  */
  else
  {
    //printf("PT100(Tem):"); 
    R0 = 100;
    A = 3.90802e-3;
    B = -0.5802e-6;
  }
  temp = sqrt((4*B*(R0-Res)+A*A*R0)/4/B/B/R0)+A/2/B;//B is a a nagative number.
  
  //printf("%.4f\n",temp);
  return temp;
}

/**
* @brief TEM terniminate. Terminate the measurement and restore the original meter state 
**/
AD5940Err TEM_Terminate(void)
{
  AD5940_StructInit(&temhs_cfg, sizeof(temhs_cfg));         /* Reset everything to zero(OFF) */
  AD5940_StructInit(&temdsp_cfg, sizeof(temdsp_cfg));         /* Reset everything to zero(OFF) */
  AD5940_StructInit(&temsw_cfg, sizeof(temsw_cfg));         /* Reset everything to zero(OFF) */
  AD5940_HSLoopCfgS(&temhs_cfg);
  AD5940_DSPCfgS(&temdsp_cfg);
  AD5940_SWMatrixCfgS(&temsw_cfg);
  
  return AD5940ERR_OK;
}

