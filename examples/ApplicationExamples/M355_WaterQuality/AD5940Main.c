/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/


/**
User could configure following parameters
**/
#include "ad5940.h"
#include "meter.h"

static int32_t AD5940PlatformCfg(void)
{
  CLKCfg_Type clk_cfg;
  AFERefCfg_Type ref_cfg;
  LPLoopCfg_Type lp_cfg;
  HSLoopCfg_Type hs_cfg;
  DSPCfg_Type dsp_cfg;
  
  /* Initislize AFE die */
  AD5940_Initialize();
  /* Configure AFE power mode and bandwidth */
  AD5940_AFEPwrBW(AFEPWR_HP, AFEBW_50KHZ);
  /* Platform configuration */
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
  /* Step2. Configure AFE reference */
  ref_cfg.HpBandgapEn = bTRUE;
  ref_cfg.Hp1V1BuffEn = bTRUE;
  ref_cfg.Hp1V8BuffEn = bTRUE;
  ref_cfg.Disc1V1Cap = bFALSE;
  ref_cfg.Disc1V8Cap = bFALSE;
  ref_cfg.Hp1V8ThemBuff = bFALSE;
  ref_cfg.Hp1V8Ilimit = bFALSE;
  ref_cfg.Lp1V1BuffEn = bFALSE;
  ref_cfg.Lp1V8BuffEn = bFALSE;
  ref_cfg.LpBandgapEn = bTRUE;
  ref_cfg.LpRefBufEn = bTRUE;
  ref_cfg.LpRefBoostEn = bFALSE;
  AD5940_REFCfgS(&ref_cfg);	
  /* Step3. Interrupt controller */
  AD5940_INTCCfg(AFEINTC_1, AFEINTSRC_ALLINT, bTRUE);   /* Enable all interrupt in INTC1, so we can check INTC flags */
  AD5940_INTCClrFlag(AFEINTSRC_ALLINT);
  AD5940_INTCCfg(AFEINTC_0, AFEINTSRC_ALLINT, bTRUE); 
  AD5940_INTCClrFlag(AFEINTSRC_ALLINT);
  /* Step4. Initialize everything to zero(false/OFF/PowerDown), only turn on what we need */
  AD5940_StructInit(&dsp_cfg, sizeof(dsp_cfg));       /* Reset everything to zero(OFF) */
  AD5940_StructInit(&lp_cfg, sizeof(lp_cfg));         /* Reset everything to zero(OFF) */
  AD5940_StructInit(&hs_cfg, sizeof(hs_cfg));         /* Reset everything to zero(OFF) */
  AD5940_HSLoopCfgS(&hs_cfg);
  AD5940_DSPCfgS(&dsp_cfg);
  AD5940_LPLoopCfgS(&lp_cfg);
  
  
  return 0;
}


void AD5940_Main(void)
{
  AD5940PlatformCfg();
  UARTCmd_cmd_sent("Ready",1,1,1,0,0,0);	
  
  while(1)
  {
    meter_process();
  }
}

