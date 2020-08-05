/******************************************************************************
@{
@file     PH.c
@brief    pH measurement of water quality.
@par      Revision History:
@version  V0.2
@author   ADI
@date     Feb 2020
@par      Revision History:
- V0.2, Feb 27th 2020: initial version.

Description:
-- For PH measurement.
-- Super high signal source impedance with recommended buffer.
-- Reduce Power line 50/60Hz noise with on-chip filters set: SINC3+SINC2+Notch

Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.
This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#include "stdio.h"
#include "math.h"
#include "ad5940.h"
#include "meter.h"

LPDACCfg_Type phlpdac_cfg;
DSPCfg_Type phdsp_cfg;

PHcfg_Type ph_cfg =
{
  .Vzero = 1100,
  .ADCPgaGain = ADCPGA_1P5,
  .PH_gain = -0.017574f,    // sensor1 @23 centidegree
  .PH_offset = 26.303143f, //sensor2 @23 centidegree
};

/**************Measurement mode*************/
float Meter_PH(void)
{
  float Temp_Result=0;
  float Temp_Vol=0;
  Temp_Vol = PH_Test();
  printf("PH(Vol):%.4f\n", Temp_Vol);
  Temp_Result = PH_Calculate(Temp_Vol,ph_cfg.PH_gain,ph_cfg.PH_offset);
  return Temp_Result;
}

/**
* @brief PH initialization. set LPDAC to provide Vzero and configure ADC.
**/
AD5940Err PH_Init(void)
{
  /*Configure LPDAC0 to produce Vzero0 for external buffer*/
  phlpdac_cfg.LpdacSel = LPDAC0;
  phlpdac_cfg.DacData12Bit = 0;               /* Output midscale voltage (0.2V + 2.4V)/2 = 1.3V */
  phlpdac_cfg.DacData6Bit = (uint32_t)((ph_cfg.Vzero-200)/DAC6BITVOLT_1LSB);  /*set the Vzero=1100mV */
  phlpdac_cfg.DataRst = bFALSE;                    /* Do not keep DATA registers at reset status */
  phlpdac_cfg.LpDacSW = LPDACSW_VZERO2PIN;//  Output 1.1V voltage to Vzero0_Pin
  phlpdac_cfg.LpDacRef = LPDACREF_2P5;            /* Select internal 2.5V reference */
  phlpdac_cfg.LpDacSrc = LPDACSRC_MMR;            /* The LPDAC data comes from MMR not WG in this case */
  phlpdac_cfg.LpDacVbiasMux = LPDACVBIAS_12BIT;   /* Connect Vbias signal to 12Bit LPDAC output */
  phlpdac_cfg.LpDacVzeroMux = LPDACVZERO_6BIT;    /* Connect Vzero signal to 6bit LPDAC output */
  phlpdac_cfg.PowerEn = bTRUE;                    /* Power up LPDAC */
  AD5940_LPDACCfgS(&phlpdac_cfg);
  
  /*Configure ADC */
  phdsp_cfg.ADCBaseCfg.ADCMuxN = ADCMUXN_VREF1P1;
  phdsp_cfg.ADCBaseCfg.ADCMuxP = ADCMUXP_AIN5;
  phdsp_cfg.ADCBaseCfg.ADCPga = ph_cfg.ADCPgaGain;
  
  phdsp_cfg.ADCFilterCfg.ADCAvgNum = ADCAVGNUM_16;  /* Don't care becase it's disabled */
  phdsp_cfg.ADCFilterCfg.ADCRate = ADCRATE_800KHZ;	/* @todo Add explanation in UG that SINC3 filter clock is same as ADC, when ADC runs at 32MHz, clear this bit to enable clock divider for SINC3 filter. Make sure SINC3 clock is below 16MHz. */
  phdsp_cfg.ADCFilterCfg.ADCSinc2Osr = ADCSINC3OSR_2;
  phdsp_cfg.ADCFilterCfg.ADCSinc3Osr = ADCSINC2OSR_667;
  phdsp_cfg.ADCFilterCfg.BpSinc3 = bFALSE;
  phdsp_cfg.ADCFilterCfg.BpNotch = bFALSE;
  phdsp_cfg.ADCFilterCfg.Sinc2NotchEnable = bTRUE;
  AD5940_DSPCfgS(&phdsp_cfg);
  
  AD5940_Delay10us(100000);  /* Delay 200us */
  
  return AD5940ERR_OK;
}

/**
* @brief PH Test. Measure the sensor voltage through AIN5 Pin
**/
float PH_Test(void)
{	
  float PH_volt;
  uint32_t PH_code;
  
  AD5940_AFECtrlS(AFECTRL_ADCPWR|AFECTRL_SINC2NOTCH, bTRUE);
  AD5940_AFECtrlS(AFECTRL_ADCCNV, bTRUE);  /* Start ADC convert*/
  AD5940_Delay10us(5);  /* Delay 50us */
  
  while(AD5940_INTCTestFlag(AFEINTC_1,AFEINTSRC_SINC2RDY)==bFALSE)
  {;
  }
  AD5940_INTCClrFlag(AFEINTSRC_SINC2RDY);
  AD5940_AFECtrlS(AFECTRL_ADCPWR|AFECTRL_ADCCNV|AFECTRL_SINC2NOTCH, bFALSE);  /* Stop ADC */
  
  PH_code = AD5940_ReadAfeResult(AFERESULT_SINC2);
  PH_volt = AD5940_ADCCode2Volt(PH_code,ph_cfg.ADCPgaGain,1.82)*1000+1100;
  return PH_volt;
}

/**
* @brief PH Calculate. Calculate the pH value from voltage
**/
float PH_Calculate(float PH_volt, float PH_gain, float PH_offset)
{
  float PH_Result = 0;
  PH_Result = PH_volt*PH_gain+PH_offset;
  
  return PH_Result;
}

/**
* @brief PH terniminate. Terminate the measurement and restore the original meter state 
**/
AD5940Err PH_Terminate(void)
{
  AD5940_StructInit(&phlpdac_cfg, sizeof(phlpdac_cfg));         /* Reset everything to zero(OFF) */
  AD5940_StructInit(&phdsp_cfg, sizeof(phdsp_cfg));         /* Reset everything to zero(OFF) */
  AD5940_LPDACCfgS(&phlpdac_cfg);
  AD5940_DSPCfgS(&phdsp_cfg);
  
  return AD5940ERR_OK;
}

