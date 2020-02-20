/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#ifndef __ADI_PROCESSOR_H__
#define __ADI_PROCESSOR_H__

#if !defined(__ADUCM355__) && !defined(__ADUCM35XTC__)
  #define __ADUCM355__
#endif

#if defined(__ADUCM355__)
#include <ADuCM355.h>
#endif

#if defined(__ADUCM35XTC__)
#include <ADuCM35xTC.h>
#endif

#endif /* __ADI_PROCESSOR_H__ */
