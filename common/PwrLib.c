/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#include	"PwrLib.h"
#include "AD5940.h"

/**
	@brief uint32_t PwrCfg(uint32_t Mode,uint32_t MonVbBat,uint32_t SramRet)
			========== Sets MCU power mode.
	@param Mode :{ENUM_PMG_PWRMOD_FLEXI,ENUM_PMG_PWRMOD_HIBERNATE,ENUM_PMG_PWRMOD_SHUTDOWN}
		- 0 or ENUM_PMG_PWRMOD_FLEXI for Flexi mode.
		- 2 or ENUM_PMG_PWRMOD_HIBERNATE to enter hibernate mode - a Cortex-M3 DEEPSLEEP mode
		- 3 or ENUM_PMG_PWRMOD_SHUTDOWN to enter Shutdown mode- a Cortex-M3 DEEPSLEEP mode
	@param MonVbBat :{BITM_PMG_PWRMOD_MONVBATN}
		- 0 or MONITOR_VBAT_EN to monitor VBAT during hibernate mode.
      - 0x8 or MONITOR_VBAT_DIS to disable monitoring of VBAT during Hibernate mode
	@param SramRet :{0|BITM_PMG_SRAMRET_BNK1EN|BITM_PMG_SRAMRET_BNK2EN}
		- 0 to Only retain Bank0(0x20000000 - 0x20001FFF) of SRAM during hibernate
		- 1 or BITM_PMG_SRAMRET_BNK1EN to retain Bank1(0x20002000 - 0x20003FFF) of SRAM during hibernate.
      - 2 or BITM_PMG_SRAMRET_BNK2EN to retain Bank2 of SRAM during hibernate.
               Bank2 is 0x10000000 to 0x10003FFF when Instruction SRAM is enabled(31bit of pADI_PMG0_TST->SRAM_CTL)
               Bank2 is 0x20004000 to 0x20007FFF when Instruction SRAM is disabled.
	@note
	@return 1.
**/
uint32_t PwrCfg(uint32_t Mode,uint32_t MonVbBat,uint32_t SramRet)
{
   int32_t index = 0;
   uint32_t savedWDT;
   savedWDT = pADI_WDT0->CTL;  //None of the watchdog timer registers are retained in hibernate mode
   if ((Mode == 2) || (Mode == 3))
   {
      SCB->SCR = 0x04;		// sleepdeep mode - write to the Cortex-m3 System Control register bit2
   }
   pADI_PMG0->PWRKEY = 0x4859;	// key1
   pADI_PMG0->PWRMOD = Mode|MonVbBat;
   pADI_PMG0->SRAMRET = SramRet;

   for (index=0;index<2;index++);
   __WFI();
   for (index=0;index<2;index++);
   pADI_WDT0->CTL = savedWDT;  //restore WDT control register.
   return 1;
}

/**
	@brief uint32_t PwrRead(void)
			========== reads MCU control register including WCENACK bit.
	@return 1.
**/
uint32_t PwrRead(void)
{
	return pADI_PMG0->PWRMOD;
}

/**
   @brief uint32_t AfePwrCfg(uint16_t Mode)
         ========= set AFE power mode
   @param iMode:{AFE_HIBERNATE,AFE_ACTIVE}
         -AFE_HIBERNATE, AFE block enter hibernate mode
         -AFE_ACTIVE, AFE block active, wake up form hibernate
   @return 1
 **/
uint32_t AfePwrCfg(uint16_t Mode)
{
   if(Mode == AFE_HIBERNATE)
   {
      pADI_ALLON->PWRKEY = 0x4859;
      pADI_ALLON->PWRKEY = 0xF27B;
      pADI_ALLON->PWRMOD = 0x0001;	//make sure pwrmod value is active. 
      /*minimize leakage in the unused switches*/
      pADI_AFE->NSWFULLCON |= 0x0C00;
      pADI_AFE->PSWFULLCON |= 0x6000;
      pADI_AFE->SWCON |= 0X10000;
   }
   else
   {
      /*dummy read to wake up AFE when AFE in hibernate*/
      uint32_t reg;
      do
      {
         reg = pADI_AFECON->CHIPID;
      }while(reg != pADI_AFECON->CHIPID); //check if AFE woke up
   }
   pADI_ALLON->PWRKEY = 0x4859;
   pADI_ALLON->PWRKEY = 0xF27B;
   pADI_ALLON->PWRMOD = (pADI_ALLON->PWRMOD&(~BITM_ALLON_PWRMOD_PWRMOD))|Mode;

   return 1;
}

/**
   @brief uint32_t PSMIntEn(uint32_t Msk)
         ========= set AFE power mode
   @param Msk:{BITM_PMG_IEN_IENBAT|BITM_PMG_IEN_VREGOVR|
               BITM_PMG_IEN_VREGUNDR|BITM_PMG_IEN_VBAT}
         -BITM_PMG_IEN_IENBAT,Interrupt Enable for VBAT range
         -BITM_PMG_IEN_VREGOVR, Enable Interrupt when VREG overvoltage: above 1.32V
         -BITM_PMG_IEN_VREGUNDR, Enalbe Interrupt when VREG undervoltage: below 1V
         -BITM_PMG_IEN_VBAT,Enable Interrupt(NMI) for VBAT < 1.83
   @return 1
 **/
uint32_t PSMIntEn(uint32_t Msk)
{
   uint32_t reg;
   reg = pADI_PMG0->IEN;
   reg &= ~(BITM_PMG_IEN_IENBAT|BITM_PMG_IEN_VREGOVR|BITM_PMG_IEN_VREGUNDR \
            |BITM_PMG_IEN_VBAT);
   reg |= Msk;
   pADI_PMG0->IEN = reg;
   return 1;
}

/**
   @brief uint32_t PSMRangeCfg(PSM_RANGBAT_Type rangeBat)
         ========= set AFE power mode
   @param rangeBat:{PSM_RANGBAT_BT2_75,PSM_RANGBAT_2_75_1_6}
         -PSM_RANGBAT_GT2_75,generate intterrupt if VBAT greater than 2.75V
         -PSM_RANGBAT_2_75_1_6, generate intterrupt if VBAT between 2.75V to 1.6V
   @return 1
 **/
uint32_t PSMRangeCfg(PSM_RANGBAT_Type rangeBat)
{
   uint32_t reg;
   reg = pADI_PMG0->IEN;
   reg &= ~BITM_PMG_IEN_RANGEBAT;
   reg |= rangeBat;
   pADI_PMG0->IEN = reg;
   return 1;
}



/**@}*/
