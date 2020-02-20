/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/


#include "ClkLib.h"

static uint32_t clkGateStatus;
static uint32_t DigRootClkSpeed = 26000000u;    //26MHz
static uint32_t AfeSysClkSpeed = 16000000u;     //16MHz
static uint32_t clk10UsDelay = 260;

/**
   @brief uint8_t DigClkSel(uint32_t clkSource)
          ======Select clock source for Digital die
   @param clkSource : {DIGCLK_SOURCE_HFOSC,DIGCLK_SOURCE_AFE}
   @return 1.
**/
uint8_t DigClkSel(uint32_t clkSource)
{
   if(clkSource == (pADI_CLKG0_CLK->CTL0&BITM_CLKG_CLK_CTL0_CLKMUX))
   {
      return 1;
   }
   else
   {
      switch(clkSource)
      {
      case DIGCLK_SOURCE_HFOSC:
         while(!(pADI_CLKG0_OSC->CTL&BITM_CLKG_OSC_CTL_HFOSCOK))
         {
            pADI_CLKG0_OSC->KEY = OSC_CTL_KEY;
            pADI_CLKG0_OSC->CTL |= BITM_CLKG_OSC_CTL_HFOSCEN;
            pADI_CLKG0_OSC->KEY = 0;
            //delay_us(50);
         }
         pADI_CLKG0_CLK->CTL0 = clkSource|(pADI_CLKG0_CLK->CTL0&(~BITM_CLKG_CLK_CTL0_CLKMUX));
         break;
      case DIGCLK_SOURCE_AFE:
         pADI_CLKG0_CLK->CTL0 = clkSource|(pADI_CLKG0_CLK->CTL0&(~BITM_CLKG_CLK_CTL0_CLKMUX));
         break;
      default:
         break;
      }
      return 1;
   }
}

/**
   @brief uint32_t ClkGateGet(void)
          ======get current clock gate status
   @return clkGateStatus.
**/
uint32_t ClkGateGet(void)
{
	uint32_t clken1;
	clkGateStatus = ((uint32_t)pADI_CLKG0_CLK->CTL5)<<24;
	clken1 = (uint32_t)(pADI_AFECON->CLKEN1);
	clken1 = (clken1&0x00FF);
	clkGateStatus |= clken1<<8;
	clkGateStatus |= ((uint32_t)pADI_AFE->ADCFILTERCON)>>12;
	clkGateStatus |= ((uint32_t)pADI_ALLON->CLKEN0);
	return clkGateStatus;
}

/**
   @brief extern uint32_t ClkGateSet(uint32_t clkGtId, uint8_t iFlag)
          ======enable/disable speicifed clock gates
   @param clkGtId :{CLK_GATE_GPT0|CLK_GATE_GPT1|CLK_GATE_GPT2|CLK_GATE_UCLKI2C|CLK_GATE_GPIO
			|CLK_GATE_PER|CLK_GATE_AFE_SRAM|CLK_GATE_AFE_ACLK|CLK_GATE_AFE_GPT0
         |CLK_GATE_AFE_GPT1|CLK_GATE_AFE_SINC2|CLK_GATE_AFE_DACWAVE
         |CLK_GATE_AFE_DFT|CLK_GATE_AFE_WDT|CLK_GATE_AFE_SLPWUT|CLK_GATE_AFE_TIACHOP}
   @param iFlag :{true,false}
         - true or 1, disable clock, GATE!!!
         - false or 0, enable clock
   @return clkGateStatus.
**/
uint32_t ClkGateSet(uint32_t clkGtId, uint8_t iFlag)
{
   uint32_t clken1;
   clken1 = (uint32_t)(pADI_AFECON->CLKEN1);
   clken1 = clken1&(~0x00000300);
   if(iFlag>0) //Gate, disable clock
   {
      pADI_AFECON->CLKEN1 = ((clkGtId&0x00FFFF00)>>8)|clken1;
      pADI_AFE->ADCFILTERCON  |= ((clkGtId&0x000000F0)<<12);
      pADI_ALLON->CLKEN0 |=  (clkGtId&0x0000000F);
      pADI_CLKG0_CLK->CTL5 |= (clkGtId>>24);
   }
   else  //enable clock, no gate
   {
      pADI_AFECON->CLKEN1 = (~((clkGtId&0x00FFFF00)>>8))&clken1;
      pADI_AFE->ADCFILTERCON  &= (~((clkGtId&0x000000F0)<<12));
      pADI_ALLON->CLKEN0 &=  (~(clkGtId&0x0000000F));
      pADI_CLKG0_CLK->CTL5 &= (~(clkGtId>>24));

   }
   return ClkGateGet();
}

/**
   @brief uint8_t ClkDivCfg(uint32_t uiHclkDiv, uint32_t uiPclkDiv)
          ======configure clock divider
   @param uiHclkDiv :{1-32}
            - HCLK = ROOT_CLK/iHclkDiv
   @param uiPclkDiv : {1-32}
            - PLCK = ROOT_CLK/iPclkDiv
   @return 1.
   @note radio of HCLK to AFE system clock must be within the range of 3:1 and 1:3
   @note frequency of PCLK must always be smaller or equal to the frequency of HCLK
**/
uint8_t ClkDivCfg(uint32_t uiHclkDiv, uint32_t uiPclkDiv)
{
   uint32_t hclkSpeed;

   hclkSpeed = DigRootClkSpeed/uiHclkDiv;
   while(!D2DClkSpeedCheck(hclkSpeed,AfeSysClkSpeed))
   {  }  //D2D check fail, iHclkDiv not suitable, cannot go further
   while(uiHclkDiv > uiPclkDiv)
   {  }  //frequency of PCLK must always be smaller or equal to the frequency of HCLK
   pADI_CLKG0_CLK->CTL1 = (uiPclkDiv<<BITP_CLKG_CLK_CTL1_PCLKDIVCNT)|(uiHclkDiv<<BITP_CLKG_CLK_CTL1_HCLKDIVCNT) \
            |(uiPclkDiv<<BITP_CLKG_CLK_CTL1_ACLKDIVCNT);
   clockUpdate(HCLK_SPEED,hclkSpeed);
   return 1;
}

/**
   @brief uint8_t AfeAdcClkDiv(uint32_t clkDiv)
          ======set speed of AFE ADC clock
   @param clkDiv : {1,2}
            - 1, ADC clock = AFE source clock
            - 2, ADC clock = AFE source clock/2
   @return 1.
   @note ADC can only run in 16MHz or 32MHz, 32MHz is used in AC impedance measurement with exitation signal frequecy
         hiher than 80KHz.
**/


/**
   @brief uint8_t AfeHFOsc32M(uint32_t En)
          ======Set AFE internal HF OSC 16MHz or 32MHz
   @param speed : {0,BITM_AFE_HPOSCCON_CLK32MHZEN}
      - 0x4, set AFE HF OSC to 16MHz
      - 0x0, set AFE HF OSC to 32MHz
   @return 1.
   @note ADC clock can run in 16MHz and 32MHz, while AFE system clock doesn't support
      32MHz, set them appropriately by calling AfeSysClkDiv() and AfeAdcClkDiv()
**/


/**
   @brief uint8_t clockUpdate(uint32_t clkId, uint32_t speed)
          ======update internal clock speed variable clkHclkSpeed,DigRootClkSpeed,
            AfeRootClkSpeed,AfeSysClkSpeed
   @param clkId : {HCLK_SPEED,AFE_ROOTCLK_SPEED,DIG_ROOTCLK_SPPED,AFESYSCLK_SPEED}
   @param speed : {}
   @return 1.
**/
uint8_t clockUpdate(uint32_t clkId, uint32_t speed)
{
   switch(clkId)
   {
   case HCLK_SPEED:  clk10UsDelay = ((uint32_t)(speed/100000.0/5+0.5));break;
   case DIG_ROOTCLK_SPPED: DigRootClkSpeed = speed; break;
   case AFESYSCLK_SPEED: AfeSysClkSpeed = speed; break;
   default: break;
   }
   return 1;
}

/**
   @brief uint8_t D2DClkSpeedCheck(uint32_t HclkSpeed, uint32_t AfeSysClkSpeed)
          ======check if (AFE system clock)/HCLK within (1/3 ~ 3)
   @param HclkSpeed : {}
   @param AfeSysClkSpeed : {}
   @return True or False.
**/
uint8_t D2DClkSpeedCheck(uint32_t HclkSpeed, uint32_t AfeSysClkSpeed)
{
   uint8_t check;
   check = (HclkSpeed<(3*AfeSysClkSpeed))&&((3*HclkSpeed)>(AfeSysClkSpeed));
   return check;
}


#if defined ( __ICCARM__ )
   #pragma optimize=low  /* IAR */
#elif defined (__CC_ARM)
  #pragma push /* Save existing optimization level */
  #pragma O0   /* Optimization level now O0 */               /* Keil */
#elif defined (__GNUC__)
#pragma GCC push_options
#pragma GCC optimize ("O0")
#else
   #pragma message("WARNING: Need to specify low optimisation for delay_10us function")
#endif

void delay_10us(int32_t t)
{
   int32_t clk1 = clk10UsDelay;
   int32_t clk2 = clk1;
   while(t>0)
   {
      t--;
      clk1 = clk2 - 1;
      while(clk1>0)
      {
         clk1--;
      }
   }
}

#if defined ( __ICCARM__ )

#elif defined (__GNUC__)
#pragma GCC pop_options
#elif defined (__CC_ARM)
#pragma pop /* Restore original optimization level */
#else

#endif

/**@}*/
