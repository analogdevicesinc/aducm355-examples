/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

/**
* Note: This example will use LP loop to output voltage on CE0 pin.
* LPDAC reference: internal 2.5V
* LP PA(potentialstat amplifier) is used to buffer voltage from Vbias which connects to 12bit LPDAC output
*
*			This example program demonstrates 4 power modes of the ADuCM355:
*								1. Normal mode - HSDAC and ADC are powerd on, clk is 16MHz
2. High Power mode - HSDAC and ADC powered on ADC clk is 323MHz
3. Hibernate mode with Sensor bias maintained
4. Hibernate mode without sensor bias

Use S2 to wake from hibernate
Use S3 to cycle through tests
*
*
**/

#include "ad5940.h"
#include "AD5940.h"
#include <stdio.h>
#include "string.h"
#include "PwrLib.h"
#include "ClkLib.h"

#define PWRMODE_NORMAL					0			/* Normal power mode, ADC clk and system clk are 16MHz */
#define PWRMODE_HIGHPWR				1			/* High power mode. ADC clk is 32MHz, HSDAC update rate is 0x7 */
#define PWRMODE_HIBERNATE			2			/* Hibernate mode with sensor bias maintained */
#define PWRMODE_SHUTDOWN 		3			/* Hibernate mode with no sensor bias */


uint8_t ucButtonPress_S2 = 0;
uint8_t ucButtonPress_S3 = 0;
uint8_t TestIndex = 0;
uint8_t ucSleepStatus = 0;

void AD5940_PotentiostatCfg(void)
{
  AFERefCfg_Type ref_cfg;
  LPLoopCfg_Type lp_cfg;
  /* Initialize everything to zero(false/OFF/PowerDown), only turn on what we need */
  AD5940_StructInit(&ref_cfg, sizeof(ref_cfg));
  ref_cfg.LpBandgapEn = bTRUE;                        /* Enable low power bandgap */
  ref_cfg.LpRefBufEn = bTRUE;                         /* Enable the low power reference buffer - 2.5V output */
  AD5940_REFCfgS(&ref_cfg);                           /* Call reference configuration function */
  
  AD5940_StructInit(&lp_cfg, sizeof(lp_cfg));         /* Reset everything to zero(OFF) */
  /* Configure what we need below */
  lp_cfg.LpDacCfg.LpdacSel = LPDAC0;
  lp_cfg.LpDacCfg.DacData12Bit = 0x800;               /* Output midscale voltage (0.2V + 2.4V)/2 = 1.3V */
  lp_cfg.LpDacCfg.DacData6Bit = 0x1F;                    /* 6Bit DAC data */
  lp_cfg.LpDacCfg.DataRst =bFALSE;                    /* Do not keep DATA registers at reset status */
  lp_cfg.LpDacCfg.LpDacSW = LPDACSW_VBIAS2PIN|LPDACSW_VZERO2PIN;//LPDACSW_VBIAS2LPPA|LPDACSW_VBIAS2PIN|LPDACSW_VZERO2LPTIA|LPDACSW_VZERO2PIN;
  lp_cfg.LpDacCfg.LpDacRef = LPDACREF_2P5;            /* Select internal 2.5V reference */
  lp_cfg.LpDacCfg.LpDacSrc = LPDACSRC_MMR;            /* The LPDAC data comes from MMR not WG in this case */
  lp_cfg.LpDacCfg.LpDacVbiasMux = LPDACVBIAS_12BIT;   /* Connect Vbias signal to 12Bit LPDAC output */
  lp_cfg.LpDacCfg.LpDacVzeroMux = LPDACVZERO_6BIT;    /* Connect Vzero signal to 6bit LPDAC output */
  lp_cfg.LpDacCfg.PowerEn = bTRUE;                    /* Power up LPDAC */
  
  lp_cfg.LpAmpCfg.LpAmpSel = LPAMP0;
  lp_cfg.LpAmpCfg.LpAmpPwrMod = LPAMPPWR_NORM;        /* Set low power amplifiers to normal power mode */
  lp_cfg.LpAmpCfg.LpPaPwrEn = bTRUE;                  /* Enable LP PA(potentialstat amplifier) power */
  lp_cfg.LpAmpCfg.LpTiaPwrEn = bTRUE;                 /* Leave LPTIA power off */
  lp_cfg.LpAmpCfg.LpTiaSW = LPTIASW(12)|LPTIASW(15)|LPTIASW(8)|LPTIASW(2)|LPTIASW(7); /* Close these switches to make sure LPPA and LPTIA amplifiers are closed loop */
  AD5940_LPLoopCfgS(&lp_cfg);
  
}

void AD5940_HSLoopCfg(void)
{
  HSLoopCfg_Type hs_loop;
  
  hs_loop.HsDacCfg.ExcitBufGain = EXCITBUFGAIN_2;
  hs_loop.HsDacCfg.HsDacGain = HSDACGAIN_1;
  hs_loop.HsDacCfg.HsDacUpdateRate = 0x1B;
  
  hs_loop.HsTiaCfg.DiodeClose = bFALSE;
  hs_loop.HsTiaCfg.HstiaBias = HSTIABIAS_1P1;
  hs_loop.HsTiaCfg.HstiaCtia = 16; /* 31pF + 2pF */
  hs_loop.HsTiaCfg.HstiaDeRload = HSTIADERLOAD_OPEN;
  hs_loop.HsTiaCfg.HstiaDeRtia = HSTIADERTIA_OPEN;
  hs_loop.HsTiaCfg.HstiaRtiaSel = HSTIARTIA_1K;
  
  hs_loop.SWMatCfg.Dswitch = SWD_OPEN;
  hs_loop.SWMatCfg.Pswitch = SWP_PL|SWP_PL2;
  hs_loop.SWMatCfg.Nswitch = SWN_NL|SWN_NL2;
  hs_loop.SWMatCfg.Tswitch = SWT_TRTIA;
  
  hs_loop.WgCfg.WgType = WGTYPE_SIN;
  hs_loop.WgCfg.GainCalEn = bFALSE;
  hs_loop.WgCfg.OffsetCalEn = bFALSE;
  
  hs_loop.WgCfg.SinCfg.SinFreqWord = AD5940_WGFreqWordCal(1000, 16e6);
  hs_loop.WgCfg.SinCfg.SinAmplitudeWord = (uint32_t)(600/800.0f*2047 + 0.5f);
  hs_loop.WgCfg.SinCfg.SinOffsetWord = 0;
  hs_loop.WgCfg.SinCfg.SinPhaseWord = 0;
  AD5940_HSLoopCfgS(&hs_loop);
  
  /* Enable all of them. They are automatically turned off during hibernate mode to save power */
  AD5940_AFECtrlS(AFECTRL_HPREFPWR|AFECTRL_HSTIAPWR|AFECTRL_INAMPPWR|AFECTRL_EXTBUFPWR|\
    AFECTRL_WG|AFECTRL_DACREFPWR|AFECTRL_HSDACPWR|\
      AFECTRL_SINC2NOTCH, bTRUE);
}


void AD5940_PowerModeCfg(uint8_t PwrMode)
{
  CLKCfg_Type clk_cfg;
  switch(PwrMode)
  {
  case PWRMODE_NORMAL:
    {	
      ClkDivCfg(2,2);
      clk_cfg.ADCClkDiv = ADCCLKDIV_1;
      clk_cfg.ADCCLkSrc = ADCCLKSRC_HFOSC;
      clk_cfg.SysClkDiv = SYSCLKDIV_1;
      clk_cfg.SysClkSrc = SYSCLKSRC_HFOSC;
      clk_cfg.HfOSC32MHzMode = bFALSE;
      clk_cfg.HFOSCEn = bTRUE;
      clk_cfg.HFXTALEn = bFALSE;
      clk_cfg.LFOSCEn = bTRUE;
      AD5940_CLKCfg(&clk_cfg);
      AD5940_AFEPwrBW(AFEPWR_LP, AFEBW_50KHZ);
      ClkDivCfg(1,1);		
      break;
    }
  case PWRMODE_HIGHPWR:
    {
      AD5940_AFEPwrBW(AFEPWR_HP, AFEBW_250KHZ);
     // AD5940_Delay10us(10000);
      ClkDivCfg(2,2);
      clk_cfg.ADCClkDiv = ADCCLKDIV_1;
      clk_cfg.ADCCLkSrc = ADCCLKSRC_HFOSC;
      clk_cfg.SysClkDiv = SYSCLKDIV_2;
      clk_cfg.SysClkSrc = SYSCLKSRC_HFOSC;
      clk_cfg.HfOSC32MHzMode = bTRUE;
      clk_cfg.HFOSCEn = bTRUE;
      clk_cfg.HFXTALEn = bFALSE;
      clk_cfg.LFOSCEn = bTRUE;
      AD5940_CLKCfg(&clk_cfg);
      ClkDivCfg(1,1);				
      break;
    }
  case PWRMODE_HIBERNATE:
    {
      AD5940_EnterSleepS();                 //Enter AD5940 into hibernate. Sineosr bias is maintainded by default
      PwrCfg(ENUM_PMG_PWRMOD_HIBERNATE,     // Place digital die in Hibernate
             BITM_PMG_PWRMOD_MONVBATN,
             BITM_PMG_SRAMRET_BNK2EN);
      break;
    }
  case PWRMODE_SHUTDOWN:
    {
      AD5940_ReadReg(REG_AFE_ADCDAT);     // dummy read reg to wake AFE die if it is asleep
      AD5940_ShutDownS();                 //Enter AD5940 into shutdown. Sensor bias is disabled
      PwrCfg(ENUM_PMG_PWRMOD_HIBERNATE,     // Place digital die in Hibernate
             BITM_PMG_PWRMOD_MONVBATN,
             BITM_PMG_SRAMRET_BNK2EN);
      break;
    }
  }	
}

void AD5940_Main(void)
{
  
  AD5940_Initialize();
  AD5940_SleepKeyCtrlS(SLPKEY_UNLOCK);  /* Allow AFE to enter sleep mode. */
  
  /* Configure potentiostat loop */
  AD5940_PotentiostatCfg();
  AD5940_HSLoopCfg();
  while(1)
  {
    if(ucButtonPress_S3 == 1 && ucSleepStatus == 0)
    {
      ucButtonPress_S3 = 0;
      if(TestIndex == 0)
      {
        printf("Normal mode. Press S3 to enter high power mode \n");
        AD5940_PowerModeCfg(PWRMODE_NORMAL);
      }
      else if(TestIndex == 1)
      {
        printf("High Power mode. Press S3 to enter hibernate mode \n");
        AD5940_PowerModeCfg(PWRMODE_HIGHPWR);
      }
      else if(TestIndex == 2)
      {
        printf("Entering hibernate mode. Press S2 to wake the device \n");
        ucSleepStatus = 1;
        AD5940_PowerModeCfg(PWRMODE_NORMAL);
        AD5940_PowerModeCfg(PWRMODE_HIBERNATE);
      }
      else if(TestIndex == 3)
      {
        printf("Entering shutdown mode. Press S2 to wake the device \n");
        ucSleepStatus = 1;
        AD5940_PowerModeCfg(PWRMODE_SHUTDOWN);
      }
      TestIndex++;
      if(TestIndex>3)
        TestIndex = 0;
    }
    
    //device has woken from hibernate
    if(ucButtonPress_S2 == 1 && ucSleepStatus == 1)
    {
      printf("Device has woken \n");			
      ucSleepStatus = 0;
      ucButtonPress_S2 = 0;
      /* Configure device */
      AD5940_PotentiostatCfg(); 
      AD5940_HSLoopCfg();      
    }
  }
}
