/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#ifndef __ADI_VERSION_H__
#define __ADI_VERSION_H__

/* use a 32-bit versioning scheme that supports numerical compares */
#define ADI_VERSION_MAJOR     1u     /* must be <= 255 */
#define ADI_VERSION_MINOR     0u     /* must be <= 255 */
#define ADI_VERSION_BUILD     1u     /* must be <= 255 */
#define ADI_VERSION_PATCH     1u     /* must be <= 255 */

#define ADI_CONSTRUCT_VERSION(a,b,c,d)  (((a) << 24u) | ((b) << 16u) | ((c) << 8u) | (d))

/* known versions */
#define ADI_VERSION_1_0_0_0   ADI_CONSTRUCT_VERSION(1u,0u,0u,0u)

/* test current version against known predefines (see SystemInit() example in system.c) */
#define ADI_VERSION_CURRENT   ADI_CONSTRUCT_VERSION(ADI_VERSION_MAJOR, ADI_VERSION_MINOR, ADI_VERSION_BUILD, ADI_VERSION_PATCH)

#endif /* __ADI_VERSION_H__ */
