/******************************************************************************
Copyright (c) 2026 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

/*----------------------------------------------------------------------------
 * Name:    Blinky.c
 * Purpose: LED Flasher
 * Note(s):
 *----------------------------------------------------------------------------
 * All files for ADuCM355 provided by ADI, including this file, are
 * provided  as is without warranty of any kind, either expressed or implied.
 * The user assumes any and all risk from the use of this code.
 * It is the responsibility of the person integrating this code into an application
 * to ensure that the resulting application performs as required and is safe.
 *----------------------------------------------------------------------------*/

#include "LED.h"

int main()
{

	int count = 0;
	printf("Hello World!\n");
	LED_Init();

	while(1)
	{
		LED_On();			/* Turn on LED          */
		delay(100000);		/* Delay                */
		LED_Off();			/* Turn off LED         */
		delay(100000);		/* Delay                */

		printf ("count = %d\n", count++);
	}

}

