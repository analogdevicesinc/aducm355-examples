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
 */

#include <stdint.h>
#include "adi_config.h"
#include "system_ADuCM355.h"
#include <ADuCM355.h>
#ifdef RELOCATE_IVT
extern void __relocated_vector_table;
#else
extern void __vector_table;
#endif
uint32_t SystemCoreClock;

#ifdef ADI_DEBUG
/* not needed unless its debug mode */
uint32_t lfClock = 0u;    /* "lf_clk" coming out of LF mux             */
#endif
uint32_t hfClock = 0u;    /* "root_clk" output of HF mux               */
uint32_t gpioClock = 0u;    /* external GPIO clock                       */

/*!
 * Initialize the system
 *
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System and update the relocate vector table.
 */
void SystemInit (void)
{
   /* Switch the Interrupt Vector Table Offset Register
   * (VTOR) to point to the relocated IVT in SRAM
   */
   // prevents the activation of all exceptions for NMI
   //__set_FAULTMASK(1);  // do all this in safe way
   __disable_irq();
   // switch from boot ROM IVT to application's IVT
   // set the System Control Block, Vector Table Offset Register
#ifdef RELOCATE_IVT
   SCB->VTOR = (uint32_t) &__relocated_vector_table;
#else
   SCB->VTOR = (uint32_t) &__vector_table;
#endif

   /* set the RAM0_RET bit so the entire 8K of SRAM Bank0 is hibernate-preserved */
   adi_system_EnableRetention(ADI_SRAM_BANK_1,true);

   // set all three (USGFAULTENA, BUSFAULTENA, and MEMFAULTENA) fault enable bits
   // in the System Control Block, System Handler Control and State Register
   // otherwise these faults are handled as hard faults
   SCB->SHCSR = SCB_SHCSR_USGFAULTENA_Msk |
      SCB_SHCSR_BUSFAULTENA_Msk |
         SCB_SHCSR_MEMFAULTENA_Msk ;

   // flush instruction and data pipelines to insure assertion of new settings
   __ISB();  // MUST OCCURE IMMEDIATELY AFTER UPDATING SCB->CPACR!!!
   __DSB();

   adi_default_setting();
   //__set_FAULTMASK(0); //no exception masked.
   __enable_irq();

}


/*!
 * @brief  This enables or disables  the cache.
 * \n @param  bEnable : To specify whether to enable/disable cache.
 * \n              true : To enable cache.
 * \n
 * \n              false : To disable cache.
 * \n
 * @return none
 *
 */
void adi_system_EnableCache(bool_t bEnable)
{
   pADI_FLCC0_CACHE->KEY = CACHE_CONTROLLER_KEY;
   if(bEnable == true)
   {
      pADI_FLCC0_CACHE->SETUP |=BITM_FLCC_CACHE_SETUP_ICEN;
   }
   else
   {
      pADI_FLCC0_CACHE->SETUP &=(uint32_t)(~(BITM_FLCC_CACHE_SETUP_ICEN));
   }
}

/*!
 * @brief  This enables or disables instruction SRAM
 *
 * @param bEnable: To enable/disable the instruction SRAM.
 * \n              true : To enable cache.
 * \n
 * \n              false : To disable cache.
 * \n
 * @return none
 * @note:  Please note that respective linker file need to support the configuration.
 */
void adi_system_EnableISRAM(bool_t bEnable)
{
   if(bEnable == true)
   {
      pADI_PMG0_TST->SRAM_CTL |=BITM_PMG_TST_SRAM_CTL_INSTREN;
   }
   else
   {
      pADI_PMG0_TST->SRAM_CTL &=(uint32_t)(~(BITM_PMG_TST_SRAM_CTL_INSTREN));
   }
}

/*!
 * @brief  This enables/disable SRAM retention during the hibernation.
 * @param eBank:   Specify which SRAM bank. Only BANK1 and BANK2 are valid.
 * @param bEnable: To enable/disable the  retention for specified  SRAM bank.
 * \n              true : To enable retention during the hibernation.
 * \n
 * \n              false :To disable retention during the hibernation.
 * \n
 * @return : SUCCESS : Configured successfully.
 *           FAILURE :  For invalid bank.
 * @note: Please note that respective linker file need to support the configuration. Only BANK-1 and
          BANK-2 of SRAM is valid.
 */
uint32_t adi_system_EnableRetention(ADI_SRAM_BANK eBank,bool_t bEnable)
{
#ifdef ADI_DEBUG
   if((eBank != ADI_SRAM_BANK_1)&& (eBank != ADI_SRAM_BANK_2))
   {
      return(FAILURE);
   }

#endif
   pADI_PMG0->PWRKEY = PWRKEY_VALUE_KEY;
   if(bEnable == true)
   {
      pADI_PMG0->SRAMRET |= (eBank>>1);
   }
   else
   {
      pADI_PMG0->SRAMRET &=(uint32_t)(~((eBank>>1)));
   }
   return (SUCCESS);
}

void adi_default_setting()
{
}
/*@}*/
