/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#include "GptLib.h"

/**********************************************************************/
/*                           Digital Die Timer                        */
/*      Note: Only digital die timer have event capture function      */
/*            Only Afe dit timer have PWM function                    */
/**********************************************************************/

/**
	@brief uint32_t GptCfg(ADI_TMR_TypeDef *pTMR, uint32_t iClkSrc, uint32_t iScale, uint32_t iMode)
			==========Configures timer GPTx if not busy.
	@param pTMR :{pADI_TMR0,pADI_TMR1,pADI_TMR2}
		- pADI_TMR0 for timer 0.
		- pADI_TMR1 for timer 1.
      - pADI_TMR2 for timer 2.
	@param iClkSrc :{TCTL_CLK_PCLK,TCTL_CLK_HFOSC,TCTL_CLK_LFOSC}
		- TxCON.5,6
		- 0x0 or TCTL_CLK_PCLK, the timer is clocked by system clock.
		- 0x20 or TCTL_CLK_HFOSC, the timer is clocked by the 26MHz internal oscillator
		- 0x40 or TCTL_CLK_LFOSC, the timer is clocked by 32kHz internal oscillator on digital die.
	@param iScale :{TCTL_PRE_DIV1,TCTL_PRE_DIV16,TCTL_PRE_DIV64,TCTL_PRE_DIV256}
		- TxCON.0,1
		- 0x0 or TCTL_PRE_DIV1 for prescale of 1 (or 4 if SYNCBYP = 0).
		- 0x1 or TCTL_PRE_DIV16 for prescale of 16.
		- 0x2 or TCTL_PRE_DIV64 for prescale of 64.
		- 0x3 or TCTL_PRE_DIV256 for prescale of 256.
	@param iMode :{BITM_TMR_CTL_MODE|BITM_TMR_CTL_UP|BITM_TMR_CTL_RLD|BITM_TMR_CTL_EN|BITM_TMR_CTL_EVTEN}
		- TxCON.2-4,7,12
		- 0x8 or BITM_TMR_CTL_MODE for the timer periodic mode. Free-running mode (0) by default.
		- 0x4 or BITM_TMR_CTL_UP to count up. 0 to bit2 count up. .
		- 0x80 or BITM_TMR_CTL_RLD for reload on overflow. This is off by default.
		- 0x10 or BITM_TMR_CTL_EN to enable timer. Off by default.
		- 0x2000 or BITM_TMR_CTL_EVTEN to enable capture mode. This is off by default.
	@return 0 if timer interface busy or 1 if successfull.

**/

uint32_t GptCfg(ADI_TMR_TypeDef *pTMR, uint32_t iClkSrc, uint32_t iScale, uint32_t iMode)
{
   int	i1;
   if(pTMR->STAT & BITM_TMR_STAT_BUSY) return 0;
   i1 = pTMR->CTL & BITM_TMR_CTL_EVTRANGE; // to keep the selected event
   i1 |= iClkSrc;
   i1 |= iScale;
   i1 |= iMode;
   pTMR->CTL = i1;
   return 1;
}

/**
	@brief uint32_t GptLd(ADI_TMR_TypeDef *pTMR, uint32_t iTLd);
			==========Sets timer reload value.
	@param pTMR :{pADI_TMR0,pADI_TMR1,pADI_TMR2}
		- pADI_TMR0 for timer 0.
		- pADI_TMR1 for timer 1.
      - pADI_TMR2 for timer 2.
	@param iTLd :{0-65535}
		- Sets reload value GPTx_LOAD to iTLd.
	@return 1.
**/

uint32_t GptLd(ADI_TMR_TypeDef *pTMR, uint32_t iTLd)
{
   pTMR->LOAD= iTLd;
   return 1;
}


/**
	@brief uint32_t GptVal(ADI_TMR_TypeDef *pTMR);
			==========Reads timer value.
	@param pTMR :{pADI_TMR0,pADI_TMR1,pADI_TMR2}
		- pADI_TMR0 for timer 0.
		- pADI_TMR1 for timer 1.
      - pADI_TMR2 for timer 2.
	@return timer value GPTx_CURCNT.
**/

uint32_t GptVal(ADI_TMR_TypeDef *pTMR)
{
   return pTMR->CURCNT;
}

/**
	@brief uint32_t GptCapRd(ADI_TMR_TypeDef *pTMR);
			==========Reads capture value. Allows capture of a new value.
	@param pTMR :{pADI_TMR0,pADI_TMR1,pADI_TMR2}
		- pADI_TMR0 for timer 0.
		- pADI_TMR1 for timer 1.
      - pADI_TMR2 for timer 2.
	@return capture value GPTx_CAPTURE.
**/

uint32_t GptCapRd(ADI_TMR_TypeDef *pTMR)
{
   return pTMR->CAPTURE;
}

/**
	@brief uint32_t GptCapSrc(ADI_TMR_TypeDef *pTMR, uint32_t iTCapSrc);
			==========Sets capture source.
	@param pTMR :{pADI_TMR0,pADI_TMR1,pADI_TMR2}
		- pADI_TMR0 for timer 0.
		- pADI_TMR1 for timer 1.
      - pADI_TMR2 for timer 2.
   @param iTCapSrc :{0-31}

	@return 1.
**/

uint32_t GptCapSrc(ADI_TMR_TypeDef *pTMR, uint32_t iTCapSrc)
{
   uint32_t	i1;
   if(pTMR->STAT & BITM_TMR_STAT_BUSY)
      return 0;
   i1 = pTMR->CTL & (~BITM_TMR_CTL_EVTRANGE);
   i1 |= (iTCapSrc << 8);
   pTMR->CTL = i1;
   return 1;
}


/**
	@brief int GptSta(ADI_TMR_TypeDef *pTMR);
			==========Reads timer status register.
	@param pTMR :{pADI_TMR0,pADI_TMR1,pADI_TMR2}
		- pADI_TMR0 for timer 0.
		- pADI_TMR1 for timer 1.
      - pADI_TMR2 for timer 2.
	@return GPTx_STAT.
**/

uint32_t GptSta(ADI_TMR_TypeDef *pTMR)
{
   return pTMR->STAT;
}

/**
	@brief uint32_t GptClrInt(ADI_TMR_TypeDef *pTMR, uint32_t iSource);
			==========clears current Timer interrupt by writing to TxCLRI.
	@param pTMR :{pADI_TMR0,pADI_TMR1,pADI_TMR2}
		- pADI_TMR0 for timer 0.
		- pADI_TMR1 for timer 1.
      - pADI_TMR2 for timer 2.
	@param iSource :{BITM_TMR_CLRINT_TIMEOUT,BITM_TMR_CLRINT_EVTCAPT}
		- 0x1 or BITM_TMR_CLRINT_TIMEOUT for time out.
		- 0x2 or BITM_TMR_CLRINT_EVTCAPT for capture event.
	@return 1.
**/

uint32_t GptClrInt(ADI_TMR_TypeDef *pTMR, uint32_t iSource)
{
   pTMR->CLRINT = iSource;
   return 1;
}

/**
	@brief uint32_t GptBsy(ADI_TMR_TypeDef *pTMR);
			==========Checks the busy bit.
	@param pTMR :{pADI_TMR0,pADI_TMR1,pADI_TMR2}
		- pADI_TMR0 for timer 0.
		- pADI_TMR1 for timer 1.
      - pADI_TMR2 for timer 2.
   @return busy bit: 0 is not busy, 1 is busy.
**/
uint32_t GptBsy(ADI_TMR_TypeDef *pTMR)
{
   if(pTMR->STAT & BITM_TMR_STAT_BUSY) return 1;
   else return 0;
   // if (pTMR == pADI_TMR0) return T1STA_BUSY_BBA;
   // else return T1STA_BUSY_BBA;
}



/**********************************************************************/
/*                           AFE Die Timer                            */
/*    Note: Only digital die timer have event capture function        */
/*          Only Afe dit timer have PWM function                      */
/*    Note: INTEN register need to be set to enable time-out interrupt*/
/**********************************************************************/
/**
	@brief uint32_t AfeGptCfg(void *pTMR, uint32_t iClkSrc, uint32_t iScale, uint32_t iMode)
			==========Configures timer GPTx if not busy.
   @param pTMR :{pADI_AGPT0,pADI_AGPT1}
		- pADI_AGPT0 for AFE timer 0.
		- pADI_AGPT1 for AFE timer 1.
	@param iClkSrc :{TCTL_CLK_PCLK,TCTL_CLK_HFOSC,TCTL_CLK_LFOSC}
		- TxCON.5,6
		- 0x0 or TCTL_CLK_PCLK, the timer is clocked by AFE system clock.
		- 0x20 or TCTL_CLK_HFOSC, the timer is clocked by the 16MHz internal oscillator
		- 0x40 or TCTL_CLK_LFOSC, the timer is clocked by 32kHz internal oscillator on digital die.
	@param iScale :{TCTL_PRE_DIV1,TCTL_PRE_DIV16,TCTL_PRE_DIV64,TCTL_PRE_DIV256}
		- TxCON.0,1
		- 0x0 or TCTL_PRE_DIV1 for prescale of 1 (or 4 if SYNCBYP = 0).
		- 0x1 or TCTL_PRE_DIV16 for prescale of 16.
		- 0x2 or TCTL_PRE_DIV64 for prescale of 64.
		- 0x3 or TCTL_PRE_DIV256 for prescale of 256.
	@param iMode :{BITM_TMR_CTL_MODE|BITM_TMR_CTL_UP|BITM_TMR_CTL_RLD|BITM_TMR_CTL_EN}
		- TxCON.2-4,7,12
		- 0x8 or BITM_TMR_CTL_MODE for the timer periodic mode. Free-running mode (0) by default.
		- 0x4 or BITM_TMR_CTL_UP to count up. 0 to bit2 count up. .
		- 0x80 or BITM_TMR_CTL_RLD for reload on overflow. This is off by default.
		- 0x10 or BITM_TMR_CTL_EN to enable timer. Off by default.
	@return 0 if timer interface busy or 1 if successfull.
**/

uint32_t AfeGptCfg(void *pTMR, uint32_t iClkSrc, uint32_t iScale, uint32_t iMode)
{
   ADI_AGPT0_TypeDef *p = (ADI_AGPT0_TypeDef *)pTMR;
   int	i1;
   if(p->STA0 & BITM_TMR_STAT_BUSY) return 0;
   i1 = p->CON0 & BITM_TMR_CTL_EVTRANGE; // to keep the selected event
   i1 |= iClkSrc;
   i1 |= iScale;
   i1 |= iMode;
   p->CON0 = i1;
   return 1;
}

/**
	@brief uint32_t AfeGptLd(void *pTMR, uint32_t iTLd);
			==========Sets timer reload value.
	@param pTMR :{pADI_AGPT0,pADI_AGPT1}
		- pADI_AGPT0 for AFE timer 0.
		- pADI_AGPT1 for AFE timer 1.
	@param iTLd :{0-65535}
		- Sets reload value GPTx_LOAD to iTLd.
	@return 1.
**/

uint32_t AfeGptLd(void *pTMR, uint32_t iTLd)
{
   ADI_AGPT0_TypeDef *p = (ADI_AGPT0_TypeDef *)pTMR;
   p->LD0= iTLd;
   return 1;
}


/**
	@brief int AfeGptVal(void *pTMR);
			==========Reads timer value.
	@param pTMR :{pADI_AGPT0,pADI_AGPT1}
		- pADI_AGPT0 for AFE timer 0.
		- pADI_AGPT1 for AFE timer 1.
	@return timer value GPTx_CURCNT.
**/

uint32_t AfeGptVal(void *pTMR)
{
   ADI_AGPT0_TypeDef *p = (ADI_AGPT0_TypeDef *)pTMR;
   return p->VAL0;
}


/**
	@brief int GptSta(void *pTMR);
			==========Reads timer status register.
	@param pTMR :{pADI_AGPT0,pADI_AGPT1}
		- pADI_AGPT0 for AFE timer 0.
		- pADI_AGPT1 for AFE timer 1.
	@return GPTx_STAT.
**/

uint32_t AfeGptSta(void *pTMR)
{
   ADI_AGPT0_TypeDef *p = (ADI_AGPT0_TypeDef *)pTMR;
   return p->STA0;
}

/**
	@brief uint32_t GptClrInt(void *pTMR, uint32_t iSource);
			==========clears current Timer interrupt by writing to TxCLRI.
	@param pTMR :{pADI_AGPT0,pADI_AGPT1}
		- pADI_AGPT0 for AFE timer 0.
		- pADI_AGPT1 for AFE timer 1.
	@param iSource :{BITM_TMR_CLRINT_TIMEOUT}
		- 0x1 or BITM_TMR_CLRINT_TIMEOUT for time out.
	@return 1.
**/

uint32_t AfeGptClrInt(void *pTMR, uint32_t iSource)
{
   ADI_AGPT0_TypeDef *p = (ADI_AGPT0_TypeDef *)pTMR;
   p->CLRI0 = iSource;
   return 1;
}

/**
	@brief int GptBsy(void *pTMR);
			==========Checks the busy bit.
	@param pTMR :{pADI_AGPT0,pADI_AGPT1}
		- pADI_AGPT0 for AFE timer 0.
		- pADI_AGPT1 for AFE timer 1.
   @return busy bit: 0 is not busy, 1 is busy.
**/
uint32_t AfeGptBsy(void *pTMR)
{
   ADI_AGPT0_TypeDef *p = (ADI_AGPT0_TypeDef *)pTMR;
   if(p->STA0 & BITM_TMR_STAT_BUSY) return 1;
   else return 0;
   // if (pTMR == pADI_TMR0) return T1STA_BUSY_BBA;
   // else return T1STA_BUSY_BBA;
}

/**
	@brief uint32_t PwmCfg(void *pTMR, uint32_t uiIdleCfg,uint32_t uiMatchEn)
			==========Configures Timers PWM mode
	@param pTMR :{pADI_AGPT0,pADI_AGPT1}
		- pADI_AGPT0 for AFE timer 0.
		- pADI_AGPT1 for AFE timer 1.
	@param uiIdleCfg :{PWM_IDLELOW, PWM_IDLEHI}
		- 0 or  PWM_IDLELOW for PWM output to idle low
		- 0x2 or PWM_IDLEHI for PWM output to idle high
	@param uiMatchEn :{PWM_TOGGLE_MODE, PWM_MATCH_MODE}
		- 0 or  PWM_TOGGLE_MODE for PWM toggle mode
		- 0x1 or PWM_MATCH_MODE for PWM match mode
@return 1
**/
uint32_t AfePwmCfg(void *pTMR, uint32_t uiIdleCfg,uint32_t uiMatchEn)
{
   uint32_t i = 0;
   ADI_AGPT0_TypeDef *p = (ADI_AGPT0_TypeDef *)pTMR;

   i = (p->PWMCON0 &0x3);
   i |= (uiIdleCfg|uiMatchEn);
   p->PWMCON0 = i;

   return 1;
}
/**
	@brief uint32_t PwmMatch(void *pTMR, uint32_t uiMatch)
           ==========Configures Timers PWM match mode period
	@param pTMR :{pADI_AGPT0,pADI_AGPT1}
		- pADI_AGPT0 for AFE timer 0.
		- pADI_AGPT1 for AFE timer 1.
	@param uiMatch :{0-65535}
		- Sets timer match value for PWM match mode
   @return 1
**/
uint32_t AfePwmMatch(void *pTMR, uint32_t uiMatch)
{
   ADI_AGPT0_TypeDef *p = (ADI_AGPT0_TypeDef *)pTMR;
   p->PWMMAT0 = uiMatch;
   return 1;
}

/**
	@brief uint32_t AfeGptIntEn(void *pTMR, uint32_t enable)
           ==========Configures Timers PWM match mode period
	@param pTMR :{pADI_AGPT0,pADI_AGPT1}
		- pADI_AGPT0 for AFE timer 0.
		- pADI_AGPT1 for AFE timer 1.
	@param enable :{0,1}
		- 0, disable time out interrupt
      - 1, Enable time out interrupt
   @return pTMR->INTEN
**/
uint32_t AfeGptIntEn(void *pTMR, uint32_t enable)
{
   ADI_AGPT0_TypeDef *p = (ADI_AGPT0_TypeDef *)pTMR;
   p->INTEN = enable;
   return p->INTEN;
}


/**@}*/
