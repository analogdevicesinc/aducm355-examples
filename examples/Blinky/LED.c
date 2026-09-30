/******************************************************************************
Copyright (c) 2026 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

/*----------------------------------------------------------------------------
 * Name:    LED.c
 * Purpose: low level LED functions
 * Note(s):
 *----------------------------------------------------------------------------
 * All files for ADuCM355 provided by ADI, including this file, are
 * provided  as is without warranty of any kind, either expressed or implied.
 * The user assumes any and all risk from the use of this code.
 * It is the responsibility of the person integrating this code into an application
 * to ensure that the resulting application performs as required and is safe.
 *----------------------------------------------------------------------------*/

#include "LED.h"

#define SET		1

/*----------------------------------------------------------------------------
  initialize LED Pins
 *----------------------------------------------------------------------------*/
void LED_Init (void) {

  /* Enables GP2.4 as output */
	DioOenPin(pADI_GPIO2, PIN4, SET);
}

/*----------------------------------------------------------------------------
  Function that turns on the LED
 *----------------------------------------------------------------------------*/
void LED_On (void) {

	DioSetPin(pADI_GPIO2, PIN4);
}

/*----------------------------------------------------------------------------
  Function that turns off the LED
 *----------------------------------------------------------------------------*/
void LED_Off (void) {

	DioClrPin(pADI_GPIO2, PIN4);
}

/*----------------------------------------------------------------------------
  Function that adds delay
 *----------------------------------------------------------------------------*/
void delay (int length)
{
	while (length > 0)
	{
		length--;
	}
}
