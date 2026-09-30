/******************************************************************************
Copyright (c) 2026 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

/*----------------------------------------------------------------------------
 * Name:    LED.h
 * Purpose: low level LED definitions
 * Note(s):
 *----------------------------------------------------------------------------
 * All files for ADuCM355 provided by ADI, including this file, are
 * provided  as is without warranty of any kind, either expressed or implied.
 * The user assumes any and all risk from the use of this code.
 * It is the responsibility of the person integrating this code into an application
 * to ensure that the resulting application performs as required and is safe.
 *----------------------------------------------------------------------------*/

#ifndef _LED_H_
#define _LED_H_

#include "system_ADuCM355.h"
#include "DioLib.h"
#include <stdio.h>

extern void LED_Init(void);
extern void LED_On  (void);
extern void LED_Off (void);
extern void delay	(int length);

#endif
