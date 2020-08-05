/******************************************************************************
@{
@file     EC.c
@brief    EC measurement of water quality.
@par      Revision History:
@version  V0.2
@author   ADI
@date     Feb 2020
@par      Revision History:
- V0.2, Feb 27th 2020: initial version.

Description:
-- For EC (electical conductivity) measurement.
-- EC_mode_4wireHsloop, HSLOOP used with ratio method
-- Frequency is sub Hz to 200kHz. 
-- Use high excitation voltage to improve the signal to noise ratio. No DC bias.
-- Multiple Rtia resistor to optimize wide range
-- Support automatic choice of Rtia and Rcal in EC_mode_4wireHsloop, range is subOhm to 1MOhm


Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.
This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/
#include "stdio.h"
#include "math.h"
#include "ad5940.h"
#include "meter.h"

ECcfg_Type ec_cfg = 
{
  .Sinfreq = 100.0f,              // Frequency of excitation signal
  .DACVoltPP = 500.0f,            // DAC output voltage in mV peak to peak. Maximum value is 800mVpp. Peak to peak voltage
  .ExcitBufGain = EXCITBUFGAIN_2, // Select from  EXCITBUFGAIN_2, EXCITBUFGAIN_0P25     
  .HsDacGain = HSDACGAIN_1,     // Select from  HSDACGAIN_1, HSDACGAIN_0P2 
  .AdcPgaGain = ADCPGA_1P5,       // PGA Gain select from GNPGA_1, GNPGA_1_5, GNPGA_2, GNPGA_4, GNPGA_9 !!! We must ensure signal is in range of +-1.5V which is limited by ADC input stage */   
  .HstiaRtiaSel = HSTIADERTIA_200,// Use internal RTIA, select from RTIA_INT_200, RTIA_INT_1K, RTIA_INT_5K, RTIA_INT_10K, RTIA_INT_20K, RTIA_INT_40K, RTIA_INT_80K, RTIA_INT_160K */
  .RcalVal = AFE_RCAL_0,          // Rcal value in Ohm */
  .EC_gain = 1.004f,              // conversion equation: gain
};

HSLoopCfg_Type echs_cfg;
DSPCfg_Type ecdsp_cfg;
SWMatrixCfg_Type ecsw_cfg;
HSTIACfg_Type echstia_cfg;

fImpCar_Type Rcal_ec;
fImpCar_Type Rz_ec;

Result_Imp ImpResult_EC={0,0,0};

/**************Measurement mode*************/
float Meter_EC(void)
{
  float Rcal_index = 0;
  float Rtia_index = 0;
  float Temp_Result = 0;
  Result_Imp Temp_Imp = {0,0,0};
  
  EC_Test(ec_cfg.HstiaRtiaSel,ec_cfg.RcalVal);
  Rcal_index = EC_RCALCho(&Rcal_ec,&Rz_ec);
  EC_Test(ec_cfg.HstiaRtiaSel,Rcal_index);
  Rtia_index = EC_RTIACho(&Rcal_ec,&Rz_ec,Rcal_index);
  printf("Rtia:%f,Rcal:%f",Rtia_index,Rcal_index);
  EC_Test(Rtia_index,Rcal_index);
  
  Temp_Imp = EC_Res_Cal(&Rcal_ec,&Rz_ec,Rcal_index);
  printf("EC(Mag):%.4f\n", Temp_Imp.Mag_result);
  Temp_Result = EC_Calculation(Temp_Imp.Mag_result,ec_cfg.EC_gain);
  return Temp_Result;
}

/**
* @brief EC initialization function. 
**/
AD5940Err EC_Init(void)
{
  /* Configure exitation loop and HSTIA */
  echs_cfg.HsDacCfg.ExcitBufGain = ec_cfg.ExcitBufGain;
  echs_cfg.HsDacCfg.HsDacGain = ec_cfg.HsDacGain ;
  echs_cfg.HsDacCfg.HsDacUpdateRate = 50;
  
  echs_cfg.WgCfg.GainCalEn = bFALSE;
  echs_cfg.WgCfg.OffsetCalEn = bFALSE;
  echs_cfg.WgCfg.WgType = WGTYPE_SIN;
  echs_cfg.WgCfg.SinCfg.SinAmplitudeWord = (uint32_t)(ec_cfg.DACVoltPP/800.0f*2047 + 0.5f);;
  echs_cfg.WgCfg.SinCfg.SinFreqWord = AD5940_WGFreqWordCal(ec_cfg.Sinfreq,16000000);
  echs_cfg.WgCfg.SinCfg.SinOffsetWord = 0;
  echs_cfg.WgCfg.SinCfg.SinPhaseWord = 0;
  
  echs_cfg.HsTiaCfg.DiodeClose = bFALSE;
  echs_cfg.HsTiaCfg.HstiaBias = HSTIABIAS_1P1;
  echs_cfg.HsTiaCfg.HstiaCtia = 31; /* 31pF + 2pF */
  echs_cfg.HsTiaCfg.HstiaDeRload = HSTIADERLOAD_OPEN ;
  echs_cfg.HsTiaCfg.HstiaDeRtia = HSTIADERTIA_OPEN;
  echs_cfg.HsTiaCfg.HstiaRtiaSel = ec_cfg.HstiaRtiaSel;
  echs_cfg.HsTiaCfg.HstiaDe1Rload = HSTIADERLOAD_OPEN;
  echs_cfg.HsTiaCfg.HstiaDe1Rtia = HSTIADERTIA_OPEN;
  
  echs_cfg.SWMatCfg.Dswitch = SWD_RCAL0;
  echs_cfg.SWMatCfg.Nswitch = SWP_RCAL0;
  echs_cfg.SWMatCfg.Pswitch = SWN_RCAL1;
  echs_cfg.SWMatCfg.Tswitch = SWT_RCAL1|SWT_TRTIA;
  
  AD5940_HSLoopCfgS(&echs_cfg);
  
  /* Configure ADC */
  ecdsp_cfg.ADCBaseCfg.ADCMuxN = ADCMUXN_HSTIA_N;
  ecdsp_cfg.ADCBaseCfg.ADCMuxP = ADCMUXP_HSTIA_P;
  ecdsp_cfg.ADCBaseCfg.ADCPga = ec_cfg.AdcPgaGain;
  
  ecdsp_cfg.ADCFilterCfg.ADCAvgNum = ADCAVGNUM_16;
  ecdsp_cfg.ADCFilterCfg.ADCRate = ADCRATE_800KHZ;	/* @todo what does this parameter decide */
  ecdsp_cfg.ADCFilterCfg.ADCSinc2Osr = ADCSINC2OSR_22;
  ecdsp_cfg.ADCFilterCfg.ADCSinc3Osr = ADCSINC3OSR_2;
  ecdsp_cfg.ADCFilterCfg.BpNotch = bTRUE;
  ecdsp_cfg.ADCFilterCfg.BpSinc3 = bFALSE;
  ecdsp_cfg.ADCFilterCfg.Sinc2NotchEnable = bTRUE;	
  ecdsp_cfg.DftCfg.DftNum = DFTNUM_4096;
  ecdsp_cfg.DftCfg.DftSrc = DFTSRC_SINC2NOTCH;
  ecdsp_cfg.DftCfg.HanWinEn = bTRUE;
  
  AD5940_DSPCfgS(&ecdsp_cfg);
  
  return AD5940ERR_OK;
  
}

/**
* @brief EC test. Automatic choice of Rtia and Rcal
* @param Rtia: the index of Rtia to provide automatically choose Rtia. 
* @param Rcal: the index of Rcal to provide automatically choose Rcal. 
**/
void EC_Test(int Rtia, int Rcal)
{	
  ImpResult_t ImpResult_ec;
  
  /* RLOAD Measurement */
  ecsw_cfg.Dswitch = SWD_CE0;
  ecsw_cfg.Pswitch = SWP_RE0;
  ecsw_cfg.Nswitch = SWN_AIN0;
  ecsw_cfg.Tswitch = SWT_SE0LOAD|SWT_TRTIA;
  AD5940_SWMatrixCfgS(&ecsw_cfg);
  AD5940_Delay10us(20);  /* Delay 200us */
  
  echstia_cfg.HstiaDeRload = HSTIADERLOAD_OPEN;
  echstia_cfg.HstiaDeRtia = HSTIADERTIA_OPEN;
  echstia_cfg.HstiaRtiaSel = Rtia;
  AD5940_HSTIACfgS(&echstia_cfg);
  
  AD5940_AFECtrlS(AFECTRL_HSTIAPWR|AFECTRL_INAMPPWR|AFECTRL_EXTBUFPWR|\
    AFECTRL_WG|AFECTRL_DACREFPWR|AFECTRL_HSDACPWR,bTRUE);
  AD5940_AFECtrlS(AFECTRL_ADCPWR|AFECTRL_SINC2NOTCH, bTRUE);  /* Enable Waveform generator */
  AD5940_AFECtrlS(AFECTRL_ADCCNV|AFECTRL_DFT, bTRUE);  /* Start ADC convert and DFT */
  AD5940_Delay10us(5);  /* Delay 50us */
  
  while(AD5940_INTCTestFlag(AFEINTC_1,AFEINTSRC_DFTRDY)== bFALSE)  
  {	;
  }
  AD5940_INTCClrFlag(AFEINTSRC_DFTRDY);
  AD5940_AFECtrlS(AFECTRL_ADCPWR|AFECTRL_ADCCNV|AFECTRL_DFT|AFECTRL_WG, bFALSE);  /* Stop ADC */
  ImpResult_ec.DFT_result[0] = convertDftToInt(AD5940_ReadAfeResult(AFERESULT_DFTREAL));
  ImpResult_ec.DFT_result[1] = convertDftToInt(AD5940_ReadAfeResult(AFERESULT_DFTIMAGE));
  
  /* RCAL Measurement */
  if (Rcal == AFE_RCAL_0)
  {
    /*switch to RCAL0*/
    ecsw_cfg.Dswitch = SWD_RCAL0;
    ecsw_cfg.Pswitch = SWP_RCAL0;
    ecsw_cfg.Nswitch = SWN_RCAL1;
    ecsw_cfg.Tswitch = SWT_RCAL1|SWT_TRTIA;
    ec_cfg.RcalVal = AFE_RCAL_0;
  }
  if (Rcal == AFE_RCAL_1)
  {
    /*switch to RCAL1*/
    ecsw_cfg.Dswitch = SWD_AIN3;
    ecsw_cfg.Pswitch = SWP_AIN3;
    ecsw_cfg.Nswitch = SWN_DE0LOAD;
    ecsw_cfg.Tswitch = SWT_DE0|SWT_TRTIA;
    
    echstia_cfg.HstiaDeRload = HSTIADERLOAD_0R;
    echstia_cfg.HstiaDeRtia = HSTIADERTIA_OPEN;
    echstia_cfg.HstiaRtiaSel = Rtia;
    AD5940_HSTIACfgS(&echstia_cfg);
  }
  AD5940_SWMatrixCfgS(&ecsw_cfg);
  AD5940_Delay10us(20);  /* Delay 200us */
  
  AD5940_AFECtrlS(AFECTRL_ADCPWR|AFECTRL_SINC2NOTCH|AFECTRL_WG, bTRUE);  /* Enable Waveform generator */
  AD5940_AFECtrlS(AFECTRL_ADCCNV|AFECTRL_DFT, bTRUE);  /* Start ADC convert and DFT */
  AD5940_Delay10us(5);  /* Delay 50us */
  
  while(AD5940_INTCTestFlag(AFEINTC_1,AFEINTSRC_DFTRDY)== bFALSE)  
  {	;
  }
  AD5940_INTCClrFlag(AFEINTSRC_DFTRDY);
  AD5940_AFECtrlS(AFECTRL_ADCPWR|AFECTRL_ADCCNV|AFECTRL_DFT|AFECTRL_WG, bFALSE);  /* Stop ADC */
  
  ImpResult_ec.DFT_result[2] = convertDftToInt(AD5940_ReadAfeResult(AFERESULT_DFTREAL));
  ImpResult_ec.DFT_result[3] = convertDftToInt(AD5940_ReadAfeResult(AFERESULT_DFTIMAGE));
  
  AD5940_AFECtrlS(AFECTRL_ADCPWR|AFECTRL_ADCCNV|AFECTRL_DFT|AFECTRL_WG, bFALSE);  /* Stop ADC convert and DFT */
  AD5940_AFECtrlS(AFECTRL_HSTIAPWR|AFECTRL_INAMPPWR|AFECTRL_EXTBUFPWR|\
    AFECTRL_WG|AFECTRL_DACREFPWR|AFECTRL_HSDACPWR,bFALSE);
  
  Rz_ec.Real = (float)ImpResult_ec.DFT_result[0];
  Rz_ec.Image = (float)(-ImpResult_ec.DFT_result[1]);//the Imaginary part in register is the opposite number
  Rcal_ec.Real = (float)ImpResult_ec.DFT_result[2];
  Rcal_ec.Image = (float)(-ImpResult_ec.DFT_result[3]);
  
} 


/**
* @brief Rtia of HSTIA can be choosed according to the Rz.
Rtia is initialised as 200Ohm, Compare voltage of HSTIA negative input and output of Rcal and Rz.
If VolRcal and VolRz is bigger than 1.82V, the amplitude of excitation siganl is too big.
If VolRcal is bigger than VolRz, the Rtia is changed according to Rz.
If volRcal is smaller than VolRz, the Rtia is changed according to Rtia.
* @return index of Rtia
**/
float EC_RTIACho(fImpCar_Type *Rcal, fImpCar_Type *Rz,float Rcal_i)
{
  
  const uint32_t hsrtia_value_table[]={200,1000,5000,10000,20000,40000,80000,160000};	/* HSRTIA value table */
  const float hsdac_gain_table[]={1,0.5}; 	  /* HSRTIA value table */
  const float excitbuf_gain_table[]={2,0.25};	/* HSRTIA value table */
  
  float Rcal_Vol = 0;
  float Rz_Vol = 0;
  
  float Ria_ideal = 0;
  float scal = 0;
  uint32_t Rtia_index = 0;
  uint32_t m = 0;
  
  Rcal_Vol = AD5940_ADCCode2Volt(((uint32_t)AD5940_ComplexMag(Rcal)+32768),ec_cfg.AdcPgaGain,1.82)/4;
  Rz_Vol =  AD5940_ADCCode2Volt(((uint32_t)AD5940_ComplexMag(Rz)+32768),ec_cfg.AdcPgaGain,1.82)/4; //relative with PGA GAIN
  
  if ((Rcal_Vol>1820)|(Rz_Vol>1820)) 
  {
    printf("The excitation signal need to be smaller.\n");
  }
  else if (Rcal_Vol >= Rz_Vol)
  {
    Ria_ideal = 1500*Rcal_i/(ec_cfg.DACVoltPP*hsdac_gain_table[ec_cfg.HsDacGain]*excitbuf_gain_table[ec_cfg.ExcitBufGain])/1.5;
  }
  else if (Rcal_Vol < Rz_Vol)
  {
    scal = 1500/Rz_Vol/1.5;
    Ria_ideal =  scal*hsrtia_value_table[Rtia_index];
  }
  m = sizeof(hsrtia_value_table)/sizeof(uint32_t)-1;
  
  for(Rtia_index=m;;Rtia_index--)
  {
    if(hsrtia_value_table[Rtia_index] < Ria_ideal)
    {
      break;
    }
    else if(Rtia_index==0)
    {
      break;
    }
    else
      ;
  }
  
  return Rtia_index;	
}

/**
* @brief Rcal can be choosed according to the Rz.
Rcal is initialised as 1KOhm, Compare voltage of HSTIA negative input and output of Rcal and Rz.
If VolRcal is 10 times of VolRz, Rcal is changed to 100KHom between AIN3&DE0
* @return index o fRcal
**/
float EC_RCALCho(fImpCar_Type *Rcal, fImpCar_Type *Rz)
{
  uint32_t Rcal_Value=0;
  float Rz_mag;
  float Rcal_mag;
  
  Rcal_mag= AD5940_ComplexMag(Rcal);
  Rz_mag= AD5940_ComplexMag(Rz);
  
  if (Rcal_mag/Rz_mag>20)
  {
    Rcal_Value = AFE_RCAL_1;
  }
  if (Rcal_mag/Rz_mag<=20)
  {
    Rcal_Value = AFE_RCAL_0;
  }
  return Rcal_Value;	
}

/**
* @brief EC resistor function. 
* @return Result of impedance: amplitude& phase, resistor & capacitor, Real and Image
**/
Result_Imp EC_Res_Cal(fImpCar_Type *Rcal, fImpCar_Type *Rz, float Rcal_i)
{
  
  fImpCar_Type res;
  fImpCar_Type Rec;
  
  res.Real = Rcal_i;
  res.Image = 0;
  
  Rec = AD5940_ComplexDivFloat(Rcal,Rz);
  Rec = AD5940_ComplexMulFloat(&Rec,&res);
  
  ImpResult_EC.Freq = ec_cfg.Sinfreq;
  /**********Amplitude and phase*********/		
  ImpResult_EC.Mag_result = AD5940_ComplexMag(&Rec);
  ImpResult_EC.Pha_result = AD5940_ComplexPhase(&Rec)*180/PI;
  /********Resistor and capcitor************/		
  //	res.Real = 1;
  //	res.Image = 0;
  //	Rec = AD5940_ComplexDivFloat(&res,Rz);
  //	ImpResult_EC.Mag_result = 1/Rec.Real;
  //	ImpResult_EC.Pha_result = Rec.Image/2/PI/ec_cfg.Sinfreq*1e12f;
  
  /*********Real and Image******/
  //	ImpResult_EC.Mag_result = Rec.Real;
  //	ImpResult_EC.Pha_result = Rec.Image;
  
  return ImpResult_EC;	
}

/**
* @brief EC conversion function. 
* @param EC_Res: result of impedance.
* @param EC_gain: calibrated cell constant of sensor 
* @return EC_value:  
**/
float EC_Calculation(float EC_Res, float EC_gain)
{
  float EC_Value=0;
  
  EC_Value = 1/EC_Res*EC_gain*1e6;
  
  return EC_Value;
}

/**
* @brief EC terniminate. Terminate the measurement and restore the original meter state 
**/
AD5940Err EC_Terminate(void)
{
  AD5940_StructInit(&echs_cfg, sizeof(echs_cfg));         /* Reset everything to zero(OFF) */
  AD5940_StructInit(&ecdsp_cfg, sizeof(ecdsp_cfg));         /* Reset everything to zero(OFF) */
  AD5940_StructInit(&ecsw_cfg, sizeof(ecsw_cfg));         /* Reset everything to zero(OFF) */
  AD5940_HSLoopCfgS(&echs_cfg);
  AD5940_DSPCfgS(&ecdsp_cfg);
  AD5940_SWMatrixCfgS(&ecsw_cfg);
  return AD5940ERR_OK;
}


