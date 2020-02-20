/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#include "AfeWdtLib.h"

/**
   @brief uint8_t AfeWdtLd(uint16_t uTld);
         ========== Sets timer reload value.
   @param uTld :{0-0xFFFF}
      - Sets reload value.
   @return 1.
**/
uint8_t AfeWdtLd(uint16_t uTld)
{
   pADI_AFEWDT->WDTLD = uTld;
   return 1;
}

/**
   @brief uint16_t AfeWdtVal(void);
         ========== Reads timer value.
   @return Timer value.
**/
uint16_t AfeWdtVal(void)
{
   return pADI_AFEWDT->WDTVALS;
}

/**
   @brief uint8_t AfeWdtCfg(WDT_MODE_Type Mod, uint8_t uPre, bool_t bInt, bool_t bClkInDiv2)
         ========== Configures the watchdog timer.
	@param Mod: {WDT_MODE_FREE,WDT_MODE_PERIODIC}
		- 0 or WDT_MODE_FREE: operate in free running mode
		- 1 or WDT_MODE_PERIODIC: operate in periodic running mode
	@param uPre: {ENUM_WDT_CTL_DIV1,ENUM_WDT_CTL_DIV16,ENUM_WDT_CTL_DIV256,ENUM_WDT_CTL_RESERVED}
      - ENUM_WDT_CTL_DIV1, for a prescaler of 1.
      - ENUM_WDT_CTL_DIV16, for a prescaler of 16.
      - ENUM_WDT_CTL_DIV256, for a prescaler of 256.
      - ENUM_WDT_CTL_RESERVED, reserved.
   @param bInt :{WDT_IRQ_EN,WDT_RESET_EN}
      - WDT_RESET_EN, to generate a reset on a timer timeout.
      - WDT_IRQ_EN, to generate an interrupt on a timer timeout.
   @param bClkInDiv2 :{WDT_CLKIN_DIV1,WDT_CLKIN_DIV2}
      - 0, to clock AFE watchdog timer straight from 32kHz oscillator
      - BITM_AFEWDT_WDTCON_CLKDIV2, to clock AFE watchdog timer from 32kHz/2 source

   @return 1.
**/
uint8_t AfeWdtCfg(WDT_MODE_Type Mod, uint8_t uPre, bool_t bInt, bool_t bClkInDiv2)
{
  uint16_t uiValForWDTCON = 0;

  uiValForWDTCON = pADI_AFEWDT->WDTCON;
   if(Mod == WDT_MODE_FREE) // Free running mode
   {
     uiValForWDTCON &=(~BITM_AFEWDT_WDTCON_MDE);
   }
	else  // Periodic mode
   {
     uiValForWDTCON |= BITM_AFEWDT_WDTCON_MDE;
   }
   uiValForWDTCON &= (~ENUM_WDT_CTL_RESERVED);
   uiValForWDTCON |= uPre;


    if(bInt==true) // interrupt on time-out?
   {
     uiValForWDTCON |= BITM_AFEWDT_WDTCON_IRQ|BITM_AFEWDT_WDTCON_WDTIRQEN;
   }
	else          // reset on time-out?
   {
     uiValForWDTCON &= (~BITM_AFEWDT_WDTCON_IRQ);
   }

   if(bClkInDiv2==true) // 32kHz oscillator input div1 or div2
   {
     uiValForWDTCON |= BITM_AFEWDT_WDTCON_CLKDIV2;
   }
	else
   {
     uiValForWDTCON &= (~BITM_AFEWDT_WDTCON_CLKDIV2);
   }

   pADI_AFEWDT->WDTCON = uiValForWDTCON;
	return 1;
}

/**
   @brief uint8_t AfeWdtWindowCfg(bool_t bEnable, uint16_t uMIN_LOAD)
         ========== Configures the watchdog timer Windowed feature.
	@param bEnable: {WDT_WINDOW_DIS,WDT_WINDOW_EN}
		- 0 or WDT_WINDOW_DIS: operate in free running mode
		- 1 or WDT_WINDOW_EN: operate in periodic running mode
	@param uMIN_LOAD: {0-0xFFFF}
      - Sets Minimum Timeout value - an attempt to refresh timer before this time has elapsed will cause a reset

   @return 1.
**/
uint8_t AfeWdtWindowCfg(bool_t bEnable, uint16_t uMIN_LOAD)
{
  if (bEnable ==  WDT_WINDOW_EN)
     pADI_AFEWDT->WDTCON |= BITM_AFEWDT_WDTCON_MINLOAD_EN;
  else
     pADI_AFEWDT->WDTCON &= ~(BITM_AFEWDT_WDTCON_MINLOAD_EN);
  
  pADI_AFEWDT->WDTMINLD = uMIN_LOAD;
  	return 1;
}

/**
   @brief uint16_t AfeWdtPowerDown(bool_t bPdStop)
         ========== Configures AFE watchdog for power down mode.
	@param bPdStop: {AFEWDT_ALWAYS_ON, AFEWDT_OFF_FOR_PD}
		- 0 or AFEWDT_ALWAYS_ON: AFE Watchdog timer always on
		- 1 or AFEWDT_OFF_FOR_PD: AFE Watchdog timer off in power down and debug modes
   @return 1.
**/
uint16_t AfeWdtPowerDown(bool_t bPdStop)
{
  if(bPdStop==true) // AFE watchdog timer off in power down and debug modes
   {
     pADI_AFEWDT->WDTCON |= BITM_AFEWDT_WDTCON_PDSTOP;
   }
	else           // AFE watchdog timer always On
   {
     pADI_AFEWDT->WDTCON &= (~BITM_AFEWDT_WDTCON_PDSTOP);
   }

  return 1;
}

/**
   @brief uint8_t AfeWdtGo(bool_t bEnable);
         ========== Enable or reset the watchdog timer.
	@param bEnable: {true,false}
		- true: enable watch dog timer
		- false: disable watch dog timer
   @return 1.
**/
uint8_t AfeWdtGo(bool_t bEnable)
{
   if(bEnable==true)
   {
		 pADI_AFEWDT->WDTCON |= BITM_AFEWDT_WDTCON_EN;
   }
	else
   {
		 pADI_AFEWDT->WDTCON &=(~BITM_AFEWDT_WDTCON_EN);
   }
   return 1;
}

/**
   @brief uint8_t AfeWdtKick(void)
         ========== Refresh the watchdog timer
   @return 1
**/
uint8_t AfeWdtKick(void)
{
  pADI_AFEWDT->WDTCLRI = WDT_RESTART_KEY;
   return 1;
}


/**
   @brief uint16_t WdtSta(void);
         ========== Returns timer Status.
   @return value of pADI_AFEWDT->WDTSTA:
      - AFEWDT_STA_IRQ, bit0, wdt interrupt pending/not pending
      - AFEWDT_STA_CLRI,bit1, CLRI write sync in progress.
      - AFEWDT_STA_TLD,bit2, Load Register write sync in progress.
      - AFEWDT_STA_CON,bit3 Control Register write sync in progress.
      - AFEWDT_STA_LOCK, bit4, 0 if pADI_AFEWDT->WDTCON has not been writen to. 1 when pADI_AFEWDT->WDTCON has been written.
**/
uint16_t AfeWdtSta(void)
{
   return	(pADI_AFEWDT->WDTSTA);
}

/**@}*/
