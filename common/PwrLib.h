/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#ifndef PWRLIB_H
#define PWRLIB_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ADuCM355.h"
#include "adi_types.h"

typedef enum
{
   PSM_RANGBAT_GT2_75 = (0U<<BITP_PMG_IEN_RANGEBAT),
   PSM_RANGBAT_2_75_1_6 = (1U<<BITP_PMG_IEN_RANGEBAT),
}PSM_RANGBAT_Type;

#define MONITOR_VBAT_EN 0
#define MONITOR_VBAT_DIS   8
#define AFE_HIBERNATE	(2u)
#define AFE_ACTIVE	(1u)

extern uint32_t PwrCfg(uint32_t Mode,uint32_t MonVbBat,uint32_t SramRet);
extern uint32_t PwrRead(void);
extern uint32_t AfePwrCfg(uint16_t Mode);
extern uint32_t PSMIntEn(uint32_t Msk);
extern uint32_t PSMRangeCfg(PSM_RANGBAT_Type rangeBat);


#ifdef __cplusplus
}
#endif

#endif // #define PWRLIB_H
