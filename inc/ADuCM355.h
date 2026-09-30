/******************************************************************************
Copyright (c) 2017-2026 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

/*!  \addtogroup MMR_Layout MMR/ISR Mappings
 *  @{
 */

#ifndef __ADUCM355_H__
#define __ADUCM355_H__
/* verify presence of a supported compiler (Keil or IAR or GCC at this time) */
#if !defined(__ICCARM__) && !defined(__CC_ARM) && !defined (__GNUC__)  && !defined (__ADSPGCC__) && !defined(M355VERI_EN)
#error "No supported compiler found, please install one of the minimum required compilers."
#endif

/* verify minimum required IAR compiler */
#ifdef __ICCARM__
#define MIN_CC_VERSION 07010001  /* known value for release 7.10.1 */
#if (MIN_CC_VERSION > __VER__)
#error "Unsupported compiler version, please install minimum required compiler version."
#endif
#endif

#define _LANGUAGE_C
#include <ADuCM355_cdef.h>
#include <ADuCM355_device.h>


/* pickup register bitfield and bit mask macros */
#include <ADuCM355_bitm.h>

#define __MPU_PRESENT          0u  /*!< MPU is not present                   */
#define __FPU_PRESENT          0u  /*!< FPU is not present                   */
#define __NVIC_PRIO_BITS       3u  /*!< Number of Bits for Priority Levels   */
#define __Vendor_SysTickConfig 0  /*!< 1 if different SysTick Config is used */

#if defined(__ARMCOMPILER_VERSION) && !defined(__STDC_VERSION__ )
  #if !defined(__INLINE)
    #define __INLINE __inline__
  #endif
  #if !defined(__STATIC_INLINE)
    #define __STATIC_INLINE static __inline__
  #endif
  #if !defined(__STATIC_FORCEINLINE)
    #define __STATIC_FORCEINLINE static __inline__ __attribute__((always_inline))
  #endif
#endif

#include "core_cm3.h"




#endif /* __ADUCM355_H__ */

/*
** EOF
*/

/*@}*/
