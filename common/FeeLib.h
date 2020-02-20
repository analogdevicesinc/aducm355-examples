/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#ifndef FEELIB_H
#define FEELIB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ADuCM355.h>
#include "adi_types.h"

/* ################ Function APIs for Flash ##################### */
extern uint8_t FeeMErs(void);
extern uint8_t FeePErs(uint32_t lAddr);
extern uint8_t FeeMultPageErs(uint32_t StartAddr,uint32_t EndAddr);
extern uint8_t FeeWr(uint32_t lAddr, uint64_t udData);
extern uint32_t FeeSta(void);
extern uint8_t FeeSign(uint32_t ulStartAddr, uint32_t ulEndAddr);
extern uint32_t FeeSig(void);
extern uint8_t FeeProTmp(uint32_t BlockNum);
extern uint8_t FeeIntCfg(uint8_t iIrq);
extern uint8_t FeeIntAbt(uint64_t IntNum);
extern uint32_t FeeAbtAdr(void);
extern uint32_t FeeCrc(int iLen, int *aiData);


#ifdef __cplusplus
}
#endif

#endif // #define FEELIB_H
