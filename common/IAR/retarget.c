/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#include "UrtLib.h"

//rewrite putchar to support printf in IAR
int putchar(int c)
{
   UrtTx(pADI_UART0,c);
   while(!(pADI_UART0->COMLSR&BITM_UART_COMLSR_TEMT));
   return c;
}