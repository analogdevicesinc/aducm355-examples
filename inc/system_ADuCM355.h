/**************************************************************************//**
 * @file     system_ADuCM355.c
 * @brief    CMSIS Cortex-M# Device Peripheral Access Layer Source File for
 *           Device ADuCM355
 * @version  V5.00
 * @date     10. January 2018
 ******************************************************************************/
/*
 * Copyright (c) 2009-2018 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 
 * Portions Copyright (c) 2018 Analog Devices, Inc.
 */


/*! \addtogroup SYS_Driver System Interfaces
 *  @{
 * add result types to doxygen
 */

#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include <stddef.h>     /* for 'NULL' */
#include <adi_types.h>
#include <ADuCM355.h>

#define SUCCESS 0
#define FAILURE 1
#include <adi_config.h>
/* System clock constant */
#define __HFOSC     26000000u

/* System clock constant (may also be 16000000) */
#define __HFXTAL    26000000u

 /*System clock constant (same whether internal osc or external xtal) */
#define __LFCLK        32768u

 /*Selecting HFOSC as input for generating root clock*/
#define HFMUX_INTERNAL_OSC_VAL      (0u << BITP_CLKG_CLK_CTL0_CLKMUX)

 /*Selecting HFXTL as input for generating root clock*/
#define HFMUX_EXTERNAL_XTAL_VAL     (1u << BITP_CLKG_CLK_CTL0_CLKMUX)

 /*Selecting SPLL as input for generating root clock*/
#define HFMUX_SYSTEM_SPLL_VAL       (2u << BITP_CLKG_CLK_CTL0_CLKMUX)

 /*Selecting GPIO as input for generating root clock*/
#define HFMUX_GPIO_VAL              (3u << BITP_CLKG_CLK_CTL0_CLKMUX)

/*! Cache controller key */
#define CACHE_CONTROLLER_KEY 0xF123F456
/*! Power  key */
#define PWRKEY_VALUE_KEY 0x4859
/**
 *  Enumeration of different channel of the SPORT
 *
 */
typedef enum
{
    /*! SRAM_BANK_0 */
    ADI_SRAM_BANK_0      = 1,
    /*! SRAM_BANK_1 */
    ADI_SRAM_BANK_1      = 2,
    /*! SRAM_BANK_2 */
    ADI_SRAM_BANK_2      = 4,
    /*! SRAM_BANK_3 */
    ADI_SRAM_BANK_3      = 8,
    /*! SRAM_BANK_4 */
    ADI_SRAM_BANK_4      = 16,
    /*! SRAM_BANK_5 */
    ADI_SRAM_BANK_5      = 32

} ADI_SRAM_BANK;
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);
void adi_system_EnableCache(bool_t bEnable);
uint32_t  adi_system_EnableRetention(ADI_SRAM_BANK eBank,bool_t bEnable);
void adi_system_EnableISRAM(bool_t bEnable);
void adi_default_setting(void);
#endif /* __SYSTEM_H__ */


/*@}*//*
** EOF
*/
