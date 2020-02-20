/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#include "ADuCM355.h"

#define ADI_TEST_CRC_POLYNOMIAL  (0x04C11DB7)
#define ADI_AFE_SEQ_CRC8_POLYNOMIAL     (0x07000000)



/*============================= MACRO =======================*/
#define CRC_CTL_NOSWAP 0
#define CRC_CTL_MSBFIRST 0
#ifndef ENABLE
#define ENABLE 1
#endif
#ifndef DISABLE
#define DISABLE 0
#endif

/*====================== FUNCTION ===========================*/
/*
   Digital part CRC peripheral
*/
extern uint32_t CrcCfg(uint32_t swap,uint32_t dir,uint32_t poly, uint32_t enable);
extern uint32_t CrcGen(uint32_t inputData);
extern uint32_t CrcSetSeed(uint32_t seed);
extern uint32_t CrcGetSeed(void);

extern uint32_t SoftwareCrc(uint32_t inputData,uint32_t poly,uint32_t seed);

