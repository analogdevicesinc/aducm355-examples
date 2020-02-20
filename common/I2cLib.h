/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#ifndef I2CLIB_H
#define I2CLIB_H

#ifdef __cplusplus
extern "C" {
#endif 

#include <ADuCM355.h>

extern int I2cMCfg(ADI_I2C_TypeDef *pI2C, int iDMACfg, int iIntSources, int iConfig);
extern int I2cAutoStretch(ADI_I2C_TypeDef *pI2C,int iMode, int iStretch, int iPeriod);
extern int I2cFifoFlush(ADI_I2C_TypeDef *pI2C,int iMode, int iFlush);
extern int I2cSCfg(ADI_I2C_TypeDef *pI2C,int iDMACfg, int iIntSources, int iConfig);
extern int I2cRx(ADI_I2C_TypeDef *pI2C,int iMode);
extern int I2cTx(ADI_I2C_TypeDef *pI2C,int iMode, int iTx);
extern int I2cBaud(ADI_I2C_TypeDef *pI2C,int iHighPeriod, int iLowPeriod);
extern int I2cMWrCfg(ADI_I2C_TypeDef *pI2C,unsigned int uiDevAddr);
extern int I2cMRdCfg(ADI_I2C_TypeDef *pI2C,unsigned int uiDevAddr, int iNumBytes, int iExt);
extern int I2cSta(ADI_I2C_TypeDef *pI2C,int iMode);
extern int I2cMRdCnt(ADI_I2C_TypeDef *pI2C);		
extern int I2cSGCallCfg(ADI_I2C_TypeDef *pI2C,int iHWGCallAddr);
extern int I2C0SIDCfg(int iSlaveID0, int iSlaveID1,int iSlaveID2,int iSlaveID3);	
extern int I2C1SIDCfg(int iSlaveID0, int iSlaveID1,int iSlaveID2,int iSlaveID3);	

#define MASTER 0
#define SLAVE 1
#define DISABLE 0
#define ENABLE 1

#define STRETCH_DIS 0
#define STRETCH_EN 1

#ifdef __cplusplus
}
#endif 

#endif // #define I2CLIB_H
