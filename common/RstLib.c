/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#include	"RstLib.h"

/**
	@brief int ReadRstSta(void)
			==========Read Rst_Stat status bits.
	@return Value of RST_STAT.
	@note .
**/

int ReadRstSta(void)
{
	return pADI_PMG0->RST_STAT;
}

	/**
	@brief int ClearRstSta(int iStaClr)
			==========Clear and read selected status bits.
	@param iStaClr :{RST_NONE|RSTSTA_POR|RSTSTA_EXTRST|RSTSTA_WDRST|RSTSTA_SWRST}	\n
		RSTSTA.0-3
		The bitwise OR of the respective data bits to clear:
			- 0x0 or RST_NONE to clear no bit
			- 0x1 or BITM_PMG_RST_STAT_POR  for Power on reset
			- 0x2 or BITM_PMG_RST_STAT_EXTRST  for external reset status bit.
			- 0x4 or BITM_PMG_RST_STAT_WDRST watchdog timer status bit.
			- 0x8 or BITM_PMG_RST_STAT_SWRST to indicate Software reset status bit.
			- 0x11 & BITM_PMG_RST_STAT_PORSRC & BITM_PMG_RST_STAT_POR for POR due to VBAT <1.7V status bit.
			- 0x21 & BITM_PMG_RST_STAT_PORSRC & BITM_PMG_RST_STAT_POR for POR due to LDO <1.08V status bit.
			- 0x31 & BITM_PMG_RST_STAT_PORSRC & BITM_PMG_RST_STAT_POR for POR due to VREG < failsafe voltage status bit
	@return Value of RSTSTA before it is written.  Bits as defined above.
	@note If iStaClr = RST_NONE then RSTSTA is read without changing it.
**/

int ClearRstSta(int iStaClr )
{
    (pADI_PMG0->RST_STAT) = (iStaClr& 0x3F);
    return pADI_PMG0->RST_STAT;
}



// AFE reset

/*
 *@brief uint8_t AfeRstSta(void)
		==== read back afe reset status
  @return value of RSTSTA in ALLWAYS ON mudule
  @note bit0: afe power-on reset
	bit1: afe external reset
	bit2: afe watchdog timeout reset
	bit3: MMR software reset
	bit4: Internal pin reset trigered by digital die
 */
uint8_t AfeRstSta(void)
{
	return pADI_ALLON->RSTSTA;
}

/*
 *@brief uint8_t AfeRstStaClear(uint8_t rstMask)
		==== clear afe reset status
  @param rstMask:{BITM_ALLON_RSTSTA_PINSWRST|BITM_ALLON_RSTSTA_MMRSWRST|BITM_ALLON_RSTSTA_WDRST|BITM_ALLON_RSTSTA_EXTRST|BITM_ALLON_RSTSTA_POR}
		- BITM_ALLON_RSTSTA_MMRSWRST, MMR software reset, refer to SWRTCON of AFECON
		- BITM_ALLON_RSTSTA_WDRST,  afe watchdog timeout reset
		- BITM_ALLON_RSTSTA_EXTRST, afe external reset
		- BITM_ALLON_RSTSTA_POR, afe power-on reset
		- 0xFF or ALLCON_RSTSTA_CLEAR_ALL,
  @return value of RSTSTA in ALLWAYS ON mudule
 */
uint8_t AfeRstStaClear(uint8_t rstMask)
{
	pADI_ALLON->RSTSTA = rstMask;
	return pADI_ALLON->RSTSTA;
}

/*
 *@brief uint32_t AfeDieSta(void)
		==== Read back AFE die status after a reset has occurred
  @return value of AFEDIESTA register
  @note bit0: Indicates status of on-chip kernel initialization after last reset
   0 - inidcates Initialization was successful
   1- indicates AFE initialization was not successful and AFE die registers should not be accessed.

 */
uint32_t AfeDieSta(void)
{
	return AFEDIESTA;
}
 



/**@}*/
