/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#ifndef GPTLIB_H
#define GPTLIB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ADuCM355.h>

extern uint32_t GptCfg(ADI_TMR_TypeDef *pTMR, uint32_t iClkSrc, uint32_t iScale, uint32_t iMode);
extern uint32_t GptLd(ADI_TMR_TypeDef *pTMR, uint32_t iTLd);
extern uint32_t GptVal(ADI_TMR_TypeDef *pTMR);
extern uint32_t GptCapRd(ADI_TMR_TypeDef *pTMR);
extern uint32_t GptCapSrc(ADI_TMR_TypeDef *pTMR, uint32_t iTCapSrc);
extern uint32_t GptSta(ADI_TMR_TypeDef *pTMR);
extern uint32_t GptClrInt(ADI_TMR_TypeDef *pTMR, uint32_t iSource);
extern uint32_t GptBsy(ADI_TMR_TypeDef *pTMR);

/*AFE Die Timer*/
extern uint32_t AfeGptCfg(void *pTMR, uint32_t iClkSrc, uint32_t iScale, uint32_t iMode);
extern uint32_t AfeGptLd(void *pTMR, uint32_t iTLd);
extern uint32_t AfeGptVal(void *pTMR);
extern uint32_t AfeGptSta(void *pTMR);
extern uint32_t AfeGptClrInt(void *pTMR, uint32_t iSource);
extern uint32_t AfeGptBsy(void *pTMR);
extern uint32_t AfePwmCfg(void *pTMR, uint32_t uiIdleCfg,uint32_t uiMatchEn);
extern uint32_t AfePwmMatch(void *pTMR, uint32_t uiMatch);
extern uint32_t AfeGptIntEn(void *pTMR, uint32_t enable);

#define TCTL_CLK_PCLK  0
#define	TCTL_CLK_HFOSC 0x20
#define	TCTL_CLK_LFOSC 0x40

#define TCTL_PRE_DIV1    0x0
#define TCTL_PRE_DIV16	 0x1
#define TCTL_PRE_DIV64	 0x2
#define TCTL_PRE_DIV256	 0x3

#define T0CON_EVENT_WUT     (0x0   << 8 )
#define T0CON_EVENT_EXT0    (0x1   << 8 )
#define T0CON_EVENT_EXT1    (0x2   << 8 )
#define T0CON_EVENT_EXT2    (0x3   << 8 )
#define T0CON_EVENT_EXT3    (0x4   << 8 )
#define T0CON_EVENT_EXT4    (0x5   << 8 )
#define T0CON_EVENT_EXT5    (0x6   << 8 )
#define T0CON_EVENT_EXT6    (0x7   << 8 )
#define T0CON_EVENT_EXT7    (0x8   << 8 )
#define T0CON_EVENT_EXT8    (0x9   << 8 )
#define T0CON_EVENT_T3      (0xA   << 8 )


#define T0CON_EVENT_LV0     (0xD   << 8 )

#define T0CON_EVENT_T1      (0xF   << 8 )


#define T1CON_EVENT_EXT4    (0x0   << 8 )
#define T1CON_EVENT_EXT5    (0x1   << 8 )
#define T1CON_EVENT_EXT6    (0x2   << 8 )
#define T1CON_EVENT_FLASH   (0x3   << 8 )
#define T1CON_EVENT_UART    (0x4   << 8 )
#define T1CON_EVENT_SPI0    (0x5   << 8 )
#define T1CON_EVENT_PLA0    (0x6   << 8 )
#define T1CON_EVENT_PLA1    (0x7   << 8 )
#define T1CON_EVENT_DMAERR  (0x8   << 8 )
#define T1CON_EVENT_DMADONE (0x9   << 8 )
#define T1CON_EVENT_I2C1S   (0xD   << 8 )
#define T1CON_EVENT_I2C1M   (0xE   << 8 )
#define T1CON_EVENT_T2      (0xF   << 8 )


#define T2CON_EVENT_EXT7    (0x0   << 8 )
#define T2CON_EVENT_EXT8    (0x1   << 8 )
#define T2CON_EVENT_SPI1    (0x2   << 8 )
#define T2CON_EVENT_I2C0S   (0x3   << 8 )
#define T2CON_EVENT_I2C0M   (0x4   << 8 )
#define T2CON_EVENT_PLA2    (0x5   << 8 )
#define T2CON_EVENT_PLA3    (0x6   << 8 )
#define T2CON_EVENT_PWMT    (0x7   << 8 )
#define T2CON_EVENT_PWM0    (0x8   << 8 )
#define T2CON_EVENT_PWM1    (0x9   << 8 )
#define T2CON_EVENT_PWM2    (0xA   << 8 )
#define T2CON_EVENT_PWM3    (0xB   << 8 )
#define T2CON_EVENT_LV1     (0xC   << 8 )
#define T2CON_EVENT_EXT0    (0xD   << 8 )
#define T2CON_EVENT_EXT1    (0xE   << 8 )
#define T2CON_EVENT_T1      (0xF   << 8 )

#define PWM_IDLELOW	          0x0
#define PWM_IDLEHI	          0x2
#define PWM_TOGGLE_MODE        0x0
#define PWM_MATCH_MODE         0x1

#ifdef __cplusplus
}
#endif

#endif // #define GPTLIB_H
