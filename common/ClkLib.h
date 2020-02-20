/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#ifndef CLKLIB_H
#define CLKLIB_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ADuCM355.h"

/*! key*/
#define OSC_CTL_KEY  0xCB14u

#define   AFECLK_SOURCE_HFOSC   0u
#define   AFECLK_SOURCE_XTAL   1u
#define   AFECLK_SOURCE_EXT   3u
#define   DIGCLK_SOURCE_HFOSC 0u
#define   DIGCLK_SOURCE_AFE 3u


#define HCLK_SPEED   0u
#define AFE_ROOTCLK_SPEED   1u
#define DIG_ROOTCLK_SPPED   2u
#define AFESYSCLK_SPEED   3u

typedef enum
{
   AFE_SYSCLKDIV_1 = 1u,
   AFE_SYSCLKDIV_2 = 2u,
   AFE_SYSCLKDIV_4 = 4u,
   AFE_SYSCLKDIV_8 = 8u,
}AFE_SYSCLKDIV_TypeDef;



/*-------------------------------------------------------------------------*/
/*   combine all clock gates into 32 bit static variable clkGateStatus     */
/*      |CLKG_CLK_CTL5|MISC_CLKEN1|AFE_ADCFILTERCON|ALLON_CLKEN0|          */
/*      |   8 BIT     |    16 BIT |     4 BIT      |    4 BIT   |          */
/*-------------------------------------------------------------------------*/
//Digital Die clock gate
#define   CLK_GATE_GPT0  (0x01u<<24)		//clock for General purpose timer 0
#define   CLK_GATE_GPT1  (0x02u<<24)      //clock for General purpose timer 1
#define   CLK_GATE_GPT2  (0x04u<<24)      //clock for General purpose timer 2
#define   CLK_GATE_UCLKI2C  (0x08u<<24)	//I2C clock control
#define   CLK_GATE_GPIO  (0x10u<<24)      //GPIO clock control
#define   CLK_GATE_PER   (0x20u<<24)      //clock connected to all Peripherals
//Analog Die clock gate
#define   CLK_GATE_AFE_SRAM	(0x04u<<8)  //AFE 6K Byte SRAM clock
#define   CLK_GATE_AFE_ACLK	(0x20u<<8)  //AFEM control clock, including analog interface and digital signal processing
#define   CLK_GATE_AFE_GPT0	(0x40u<<8)  //AFE General purpose timer(PWM0)
#define   CLK_GATE_AFE_GPT1	(0x80u<<8)  //AFE General purpose timer(PWM1)
#define   CLK_GATE_AFE_SINC2	(0x01u<<4)	//SINC2 clock
#define   CLK_GATE_AFE_DACWAVE	(0x02u<<4)  //DAC Wave generation block clock
#define   CLK_GATE_AFE_DFT	(0x04u<<4)     //DFT block clock
#define   CLK_GATE_AFE_WDT	(0x01u)		   //AFE watch dog timer clock

#define   CLK_GATE_ALL	(CLK_GATE_GPT0|CLK_GATE_GPT1|CLK_GATE_GPT2|CLK_GATE_UCLKI2C\
                           |CLK_GATE_GPIO|CLK_GATE_PER|CLK_GATE_AFE_SRAM\
                              |CLK_GATE_AFE_ACLK|CLK_GATE_AFE_GPT0|CLK_GATE_AFE_GPT1|\
                                 |CLK_GATE_AFE_SINC2|CLK_GATE_AFE_DACWAVE|CLK_GATE_AFE_DFT|CLK_GATE_AFE_WDT)


extern uint8_t DigClkSel(uint32_t clkSource);
extern uint32_t ClkGateGet(void);
extern uint32_t ClkGateSet(uint32_t clkGtId, uint8_t iFlag);
extern uint8_t ClkDivCfg(uint32_t uiHclkDiv, uint32_t uiPclkDiv);
extern uint8_t clockUpdate(uint32_t clkId, uint32_t speed);
extern uint8_t D2DClkSpeedCheck(uint32_t HclkSpeed, uint32_t AfeSysClkSpeed);
extern void delay_10us(int32_t t);

#ifdef __cplusplus
}
#endif

#endif // #define CLKLIB_H
