/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#include "ad5940.h"
#include <FeeLib.h>


//uint32_t uiReadAddr = 0;

#define	BACKUP_FLASH_BASE     		0x10800		 		   	// Base of Prog Flash User Space for backup of ADC samples
#define  FLASH_LOG_CHECK 	(*(volatile unsigned long *) 	uiReadAddr)

/*=========================== Function declarations ====================*/
void BackUpToFlash(void);
void InitFlash(void);
void StartDebugText(void);
void FlashToUART(void);
void SendEndOfLog(void);
void delay1 (long int length);
