/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/


/*
    IAR debug mode. View->Memory->Go to 0x12000. step execution see the content of flash.

**/
#include <stdio.h>
#include "FeeLib.h"

void ClockInit(void)
{
    pADI_CLKG0_OSC->KEY = 0xCB14;               // Select HFOSC as system clock.
    pADI_CLKG0_OSC->CTL = BITM_CLKG_OSC_CTL_HFOSCEN; // Int 32khz LFOSC selected in LFMUX
    pADI_CLKG0_CLK->CTL0 = 0;                   // PLCK,Flash reference clock,PLL=HFOSC
    pADI_CLKG0_CLK->CTL1 = 0;                   // ACLK,PCLK,HCLK divided by 1
    pADI_CLKG0_CLK->CTL5 = 0x00;                 // Enable clock to all peripherals - no clock gating
}

int main(void)
{
    uint32_t	i1;
    pADI_AFEWDT->WDTCON &= (~BITM_AFEWDT_WDTCON_EN);

    ClockInit();
    /* write data into flash*/
    for(i1 = 0x12000; i1 < 0x12100; i1 += 8)
    {
        FeeWr(i1, i1 + 0x55aabb00000000);
        while(FeeSta() & 1);
    }
    /* erase specified page */
    FeePErs(0x12000);
    while(FeeSta() & 1);		/* wait if commond busy */

    while(1)
    {

    }
}
