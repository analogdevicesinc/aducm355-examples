/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#if !defined (__CC_ARM) && !defined(__GNUC__)
#define RELOCATE_IVT 1             // Map interrupt vector table into SRAM - Comment out to map to flash
#endif

/* ISRAM is enable by default and can be disabled by below macro */
#define ADI_DISABLE_INSTRUCTION_SRAM

/* To enable the  cache. Please note taht linker description  file need to
   have appropriate memeory mapping.  */
/* #define ENABLE_CACHE */
