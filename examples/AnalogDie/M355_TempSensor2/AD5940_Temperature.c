/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#include "ad5940.h"
#include "ADucM355.h"


#define SINC3OSR_SEL    ADCSINC3OSR_4
#define SINC2OSR_SEL    ADCSINC2OSR_533

#define Vref_ADC        1835u

/* Initialize AFE basic blocks like clock */
static int32_t AD5940PlatformCfg(void){
  CLKCfg_Type clk_cfg;
  
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
    
  /* Step2. Interrupt controller */
  AD5940_INTCCfg(AFEINTC_1, AFEINTSRC_ALLINT, bTRUE);           /* Enable all interrupt in Interrupt Controller 1, so we can check INTC flags */
  AD5940_INTCCfg(AFEINTC_0, AFEINTSRC_ALLINT, bFALSE);   /* Interrupt Controller 0 will control GP0 to generate interrupt to MCU */
  AD5940_INTCClrFlag(AFEINTSRC_ALLINT);
  
  AD5940_SleepKeyCtrlS(SLPKEY_UNLOCK);  /* Enable AFE to enter sleep mode. */
  return 0;
}

/* Intitialize blocks for temperature measurement */
void AD5940_AnalogInit(void){
  AFERefCfg_Type aferef_cfg;
  ADCBaseCfg_Type adc_base;
  ADCFilterCfg_Type adc_filter;
  //init ad5940 for temeprature measurement.
  AD5940_AFECtrlS(AFECTRL_ALL, bFALSE);  /* Init all to disable state */
  aferef_cfg.HpBandgapEn = bTRUE;
  aferef_cfg.Hp1V1BuffEn = bTRUE;
  aferef_cfg.Hp1V8BuffEn = bTRUE;       /* The High speed buffers are automatically turned off during hibernate */
  aferef_cfg.Disc1V1Cap = bFALSE;
  aferef_cfg.Disc1V8Cap = bFALSE;
  aferef_cfg.Hp1V8ThemBuff = bTRUE;
  aferef_cfg.Hp1V8Ilimit = bTRUE;
  aferef_cfg.Lp1V1BuffEn = bFALSE;
  aferef_cfg.Lp1V8BuffEn = bFALSE;
  
  /* LP reference control - turn off them to save powr*/
  aferef_cfg.LpBandgapEn = bFALSE;
  aferef_cfg.LpRefBufEn = bFALSE;
  aferef_cfg.LpRefBoostEn = bFALSE;
  AD5940_REFCfgS(&aferef_cfg);	
  /* Initialize ADC basic function */
  adc_base.ADCMuxP = 0x25;
  adc_base.ADCMuxN = 0x15;
  adc_base.ADCPga = ADCPGA_1P5;
  AD5940_ADCBaseCfgS(&adc_base);
  /* Initialize ADC filters ADCRawData-->SINC3-->SINC2+NOTCH */
  adc_filter.ADCSinc3Osr = SINC3OSR_SEL;
  adc_filter.ADCSinc2Osr = SINC2OSR_SEL;
  adc_filter.ADCAvgNum = ADCAVGNUM_2;         /* Don't care about it. Average function is only used for DFT */
  adc_filter.ADCRate = ADCRATE_800KHZ;        /* If ADC clock is 32MHz, then set it to ADCRATE_1P6MHZ. Default is 16MHz, use ADCRATE_800KHZ. */
  adc_filter.BpNotch = bFALSE;                 /* SINC2+Notch is one block, when bypass notch filter, we can get fresh data from SINC2 filter. */
  adc_filter.BpSinc3 = bFALSE;                /* We use SINC3 filter. */
  adc_filter.Sinc3ClkEnable = bTRUE;          /* Enable SINC3 clock.  */
  adc_filter.Sinc2NotchClkEnable = bTRUE;     
  adc_filter.Sinc2NotchEnable = bTRUE;        /* Enable the SINC2+Notch block. You can also use function AD5940_AFECtrlS */
  adc_filter.DFTClkEnable = bFALSE;
  adc_filter.WGClkEnable = bFALSE;  
  AD5940_ADCFilterCfgS(&adc_filter);
  
  pADI_AFE->ADCBUFCON = 0x005F3D04;           // Set ADC input buffers/PGA for recommended chop configuration
  
  AD5940_AFECtrlS(AFECTRL_ADCPWR|AFECTRL_SINC2NOTCH, bTRUE);
}

/**
* Measure 2nd temp sensor. 21 ADC resultsare required
*/
float AD5940_TemperatureMeasure(void)
{
  uint16_t TempResult = 0;
  float fTempResult1 = 0.0;
  float fTempResult4 = 0.0;
  float fTempResult16 = 0.0;
  float average = 0.0;
  float Vbe1,Vbe2,T;

  pADI_AFE->TEMPCON1 = 0;       //Power up temp sensor
  AD5940_Delay10us(1000);
  /* Step 1: Measure 16 VBE voltage individualy and find average */
  for(uint8_t i = 0; i<16; i++)
  {
    pADI_AFE->TEMPCON1 = (1u<<i);
    AD5940_Delay10us(100);
    AD5940_AFECtrlS(AFECTRL_ADCCNV|AFECTRL_SINC2NOTCH, bTRUE);  /* Start ADC convert */
    while(AD5940_INTCTestFlag(AFEINTC_1, AFEINTSRC_SINC2RDY) == bFALSE);
    TempResult = pADI_AFE->ADCDAT;
    AD5940_AFECtrlS(AFECTRL_ADCCNV|AFECTRL_SINC2NOTCH, bFALSE);  /* Stop ADC convert */
    AD5940_INTCClrFlag(AFEINTSRC_SINC2RDY);    
    average += TempResult;
  }
  fTempResult16 = (average/16.0);
  
  /* Step 2: Close switches in groups of 4 VBE voltage and calculate average of the 4 */
  TempResult = 0;
  average = 0.0;
  for(uint8_t i=0;i<16;)
  {
    pADI_AFE->TEMPCON1 = (0x000F<<i);  // Connect 4x Isources to the VBE transistor in groups
    i += 4;
    AD5940_Delay10us(100);
    AD5940_AFECtrlS(AFECTRL_ADCCNV|AFECTRL_SINC2NOTCH, bTRUE);  /* Start ADC convert */
    while(AD5940_INTCTestFlag(AFEINTC_1, AFEINTSRC_SINC2RDY) == bFALSE);
    TempResult = (pADI_AFE->ADCDAT & 0xFFFF);
    AD5940_AFECtrlS(AFECTRL_ADCCNV|AFECTRL_SINC2NOTCH, bFALSE);  /* Stop ADC convert */
    AD5940_INTCClrFlag(AFEINTSRC_SINC2RDY);  
    average += TempResult;
  }
  fTempResult4 = (average / 4.0);  

  Vbe1 = (fTempResult4 - fTempResult16);
  
  /* Step 3: Close all switches and to connect all sources to VBE */
  TempResult = 0;
  pADI_AFE->TEMPCON1 =  0x00FFFF;  // Connect all Isources to the VBE transistor 
  AD5940_Delay10us(100);
  AD5940_AFECtrlS(AFECTRL_ADCCNV|AFECTRL_SINC2NOTCH, bTRUE);  /* Start ADC convert */
  while(AD5940_INTCTestFlag(AFEINTC_1, AFEINTSRC_SINC2RDY) == bFALSE);
  TempResult = (pADI_AFE->ADCDAT & 0xFFFF);
  AD5940_AFECtrlS(AFECTRL_ADCCNV|AFECTRL_SINC2NOTCH, bFALSE);  /* Stop ADC convert */
  AD5940_INTCClrFlag(AFEINTSRC_SINC2RDY);   
  fTempResult1 = TempResult;

  Vbe2 = (fTempResult1 - fTempResult4);
    
  T = 2768.231*(4.0*(Vbe1)-(Vbe2))/65535.0*Vref_ADC*2/1000/1.5 - 273.15;
  return T;
}


void AD5940_Main(void)
{
  float temperature = 0.0;
  AD5940PlatformCfg();
  AD5940_AnalogInit();
  
  while(1)
  {
      temperature = AD5940_TemperatureMeasure();
      printf("Temperature: %.3f \n", temperature);
      AD5940_Delay10us(200000);
  }
}

