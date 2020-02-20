/* File: startup_ADuCM355.c
 * Startup file for Analog Devices ADuCM355 processor
 *
 * Based on startup_ARMCM3.c
 *
 */
/* Copyright (c) 2011 - 2014 ARM LIMITED
   Portions Copyright (c) 2016 - 2018 Analog Devices, Inc.

   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   - Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   - Neither the name of ARM nor the names of its contributors may be used
     to endorse or promote products derived from this software without
     specific prior written permission.
   *
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
   ---------------------------------------------------------------------------*/

#include <stdint.h>

/*----------------------------------------------------------------------------
  Linker generated Symbols
 *----------------------------------------------------------------------------*/
extern uint32_t __etext;
extern uint32_t __data_start__;
extern uint32_t __data_end__;
extern uint32_t __copy_table_start__;
extern uint32_t __copy_table_end__;
extern uint32_t __zero_table_start__;
extern uint32_t __zero_table_end__;
extern uint32_t __bss_start__;
extern uint32_t __bss_end__;
extern uint32_t __StackTop;

/*----------------------------------------------------------------------------
  Exception / Interrupt Handler Function Prototype
 *----------------------------------------------------------------------------*/
typedef void( *pFunc )( void );


/*----------------------------------------------------------------------------
  External References
 *----------------------------------------------------------------------------*/
#ifndef __START
extern void  _start(void) __attribute__((noreturn));    /* PreeMain (C library entry point) */
#else
extern int  __START(void) __attribute__((noreturn));    /* main entry point */
#endif

#ifndef __NO_SYSTEM_INIT
extern void SystemInit (void);            /* CMSIS System Initialization      */
#endif


/*----------------------------------------------------------------------------
  Internal References
 *----------------------------------------------------------------------------*/
void Default_Handler(void);                          /* Default empty handler */


/*----------------------------------------------------------------------------
  Security options
 *----------------------------------------------------------------------------*/

  __attribute__ ((section(".security_options")))
const uint32_t adi_aducm302x_security_options[]
  = {
        0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, // ReadProtectedKeyHash
        0xA79C3203u,                                        // CRC_ReadProtectedKeyHash
        0u,                                                 // LastCRCPage
        0xFFFFFFFFu,
        0xFFFFFFFFu,
};

/*----------------------------------------------------------------------------
  Checksum
 *----------------------------------------------------------------------------*/

// This needs to be placed at 0x7FC by the linker script for LastCRCPage == 0x0 
__attribute__ ((section(".checksum")))
const uint32_t checksum = 0xFFFFFFFFu;

/*----------------------------------------------------------------------------
  User Initial Stack & Heap
 *----------------------------------------------------------------------------*/
#ifndef __STACK_SIZE
  #define	__STACK_SIZE  0x00000400
#endif
static uint8_t stack[__STACK_SIZE] __attribute__ ((aligned(8), used, section(".stack")));

#ifndef __HEAP_SIZE
  #define	__HEAP_SIZE   0x00000C00
#endif
#if __HEAP_SIZE > 0
static uint8_t heap[__HEAP_SIZE]   __attribute__ ((aligned(8), used, section(".heap")));
#endif

/*----------------------------------------------------------------------------
  Exception / Interrupt Handler
 *----------------------------------------------------------------------------*/
/* Cortex-M3 Processor Exceptions */
void Reset_Handler               (void) __attribute__ ((weak, alias("Reset_Handler_C")));
void NMI_Handler                 (void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_HANDLER                 (void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void PENDSV_HANDLER              (void) __attribute__ ((weak, alias("Default_Handler")));
void SYSTICK_HANDLER             (void) __attribute__ ((weak, alias("Default_Handler")));

/* programmable interrupt mappings... */
void RTC1_Int_Handler                  (void) __attribute__ ((weak, alias("Default_Handler")));
void Ext_Int0_Handler                  (void) __attribute__ ((weak, alias("Default_Handler")));
void Ext_Int1_Handler                  (void) __attribute__ ((weak, alias("Default_Handler")));
void Ext_Int2_Handler                  (void) __attribute__ ((weak, alias("Default_Handler")));
void Afe_Int3_Handler                  (void) __attribute__ ((weak, alias("Default_Handler")));
void WDog_Tmr_Int_Handler              (void) __attribute__ ((weak, alias("Default_Handler")));
void Vreg_over_Int_Handler             (void) __attribute__ ((weak, alias("Default_Handler")));
void Battery_Voltage_Int_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void RTC0_Int_Handler                  (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIO_A_Int_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIO_B_Int_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
void GP_Tmr0_Int_Handler               (void) __attribute__ ((weak, alias("Default_Handler")));
void GP_Tmr1_Int_Handler               (void) __attribute__ ((weak, alias("Default_Handler")));
void Flash0_Int_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
void UART_Int_Handler                  (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI0_Int_Handler                  (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI1_Int_Handler                  (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C0_Slave_Int_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C0_Master_Int_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_Err_Int_Handler               (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_SPI1_TX_Int_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_SPI1_RX_Int_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_SPI0_TX_Int_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_SPI0_RX_Int_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_UART_TX_Int_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_UART_RX_Int_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_I2C0_STX_Int_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_I2C0_SRX_Int_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_I2C0_MX_Int_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_AES0_IN_Int_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_AES0_OUT_Int_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_FLASH0_Int_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void Crypto_Int_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_ADC0_Int_Handler              (void) __attribute__ ((weak, alias("Default_Handler")));
void GP_Tmr2_Int_Handler               (void) __attribute__ ((weak, alias("Default_Handler")));
void PLL_Int_Handler                   (void) __attribute__ ((weak, alias("Default_Handler")));
void RNG_Int_Handler                   (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC_Int_Handler                   (void) __attribute__ ((weak, alias("Default_Handler")));
void AfeError_Int_Handler              (void) __attribute__ ((weak, alias("Default_Handler")));
void AfeAdc_Int_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
void AfeGeneral_Int_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void AfeCMDFifo_Int_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void AfeDATAFifo_Int_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void AfeWdt_Int_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
void AfeCrcError_Int_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void AfeGpTimer0_Int_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void AfeGpTimer1_Int_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_AfeCMDFifo_Int_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_AfeDATAFifo_Int_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_SIP2_Int_Handler              (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_SIP3_Int_Handler              (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_SIP4_Int_Handler              (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_SIP5_Int_Handler              (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_SIP6_Int_Handler              (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_SIP7_Int_Handler              (void) __attribute__ ((weak, alias("Default_Handler")));

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/
const pFunc __vector_table[] __attribute__ ((section(".vectors"))) = {
  /* Cortex-M3 Exceptions Handler */
  (pFunc)&__StackTop,                       /* Initial Stack Pointer */
  Reset_Handler,                            /* -15 */
  NMI_Handler,                              /* -14 */
  HardFault_Handler,                        /* -13 */
  MemManage_Handler,                        /* -12 */
  BusFault_Handler,                         /* -11 */
  UsageFault_Handler,                       /* -10 */
  0,                                        /* -9  */
  0,                                        /* -8  */
  0,                                        /* -7  */
  0,                                        /* -6  */
  SVC_HANDLER,                              /* -5  */
  DebugMon_Handler,                         /* -4  */
  0,                                        /* -3  */
  PENDSV_HANDLER,                           /* -2  */
  SYSTICK_HANDLER,                          /* -1  */

  /* External interrupts */
  RTC1_Int_Handler,                         /* 0  */
  Ext_Int0_Handler,                         /* 1  */
  Ext_Int1_Handler,                         /* 2  */
  Ext_Int2_Handler,                         /* 3  */
  Afe_Int3_Handler,                         /* 4  */
  WDog_Tmr_Int_Handler,                     /* 5  */
  Vreg_over_Int_Handler,                    /* 6  */
  Battery_Voltage_Int_Handler,              /* 7  */
  RTC0_Int_Handler,                         /* 8  */
  GPIO_A_Int_Handler,                       /* 9  */
  GPIO_B_Int_Handler,                       /* 10 */
  GP_Tmr0_Int_Handler,                      /* 11 */
  GP_Tmr1_Int_Handler,                      /* 12 */
  Flash0_Int_Handler,                       /* 13 */
  UART_Int_Handler,                         /* 14 */
  SPI0_Int_Handler,                         /* 15 */
  SPI1_Int_Handler,                         /* 16 */
  I2C0_Slave_Int_Handler,                   /* 17 */
  I2C0_Master_Int_Handler,                  /* 18 */
  DMA_Err_Int_Handler,                      /* 19 */
  DMA_SPI1_TX_Int_Handler,                  /* 20 */
  DMA_SPI1_RX_Int_Handler,                  /* 21 */
  0,                                        /* 22 */
  0,                                        /* 23 */
  DMA_SPI0_TX_Int_Handler,                  /* 24 */
  DMA_SPI0_RX_Int_Handler,                  /* 25 */
  0,                                        /* 26 */
  0,                                        /* 27 */
  DMA_UART_TX_Int_Handler,                  /* 28 */
  DMA_UART_RX_Int_Handler,                  /* 29 */
  DMA_I2C0_STX_Int_Handler,                 /* 30 */
  DMA_I2C0_SRX_Int_Handler,                 /* 31 */
  DMA_I2C0_MX_Int_Handler,                  /* 32 */
  DMA_AES0_IN_Int_Handler,                  /* 33 */
  DMA_AES0_OUT_Int_Handler,                 /* 34 */
  DMA_FLASH0_Int_Handler,                   /* 35 */
  0,                                        /* 36 */
  0,                                        /* 37 */
  Crypto_Int_Handler,                       /* 38 */
  DMA_ADC0_Int_Handler,                     /* 39 */
  GP_Tmr2_Int_Handler,                      /* 40 */
  0,                                        /* 41 */
  0,                                        /* 42 */
  PLL_Int_Handler,                          /* 43 */
  RNG_Int_Handler,                          /* 44 */
  0,                                        /* 45 */
  ADC_Int_Handler,                          /* 46 */
  AfeError_Int_Handler,                     /* 47 */
  AfeAdc_Int_Handler,                       /* 48 */
  AfeGeneral_Int_Handler,                   /* 49 */
  AfeCMDFifo_Int_Handler,                   /* 50 */
  AfeDATAFifo_Int_Handler,                  /* 51 */
  AfeWdt_Int_Handler,                       /* 52 */
  AfeCrcError_Int_Handler,                  /* 53 */
  AfeGpTimer0_Int_Handler,                  /* 54 */
  AfeGpTimer1_Int_Handler,                  /* 55 */
  DMA_AfeCMDFifo_Int_Handler,               /* 56 */
  DMA_AfeDATAFifo_Int_Handler,              /* 57 */
  DMA_SIP2_Int_Handler,                     /* 58 */
  DMA_SIP3_Int_Handler,                     /* 59 */
  DMA_SIP4_Int_Handler,                     /* 60 */
  DMA_SIP5_Int_Handler,                     /* 61 */
  DMA_SIP6_Int_Handler,                     /* 62 */
  DMA_SIP7_Int_Handler,                     /* 63 */
};



/*----------------------------------------------------------------------------
  Reset Handler C is called immediately on controller reset
 *----------------------------------------------------------------------------*/
void Reset_Handler_C(void) {
  uint32_t *pSrc, *pDest;
  uint32_t *pTable __attribute__((unused));

/*  Firstly it copies data from read only memory to RAM. There are two schemes
 *  to copy. One can copy more than one sections. Another can only copy
 *  one section.  The former scheme needs more instructions and read-only
 *  data to implement than the latter.
 *  Macro __STARTUP_COPY_MULTIPLE is used to choose between two schemes.  */

#ifdef __STARTUP_COPY_MULTIPLE
/*  Multiple sections scheme.
 *
 *  Between symbol address __copy_table_start__ and __copy_table_end__,
 *  there are array of triplets, each of which specify:
 *    offset 0: LMA of start of a section to copy from
 *    offset 4: VMA of start of a section to copy to
 *    offset 8: size of the section to copy. Must be multiply of 4
 *
 *  All addresses must be aligned to 4 bytes boundary.
 */
  pTable = &__copy_table_start__;

  for (; pTable < &__copy_table_end__; pTable = pTable + 3) {
		pSrc  = (uint32_t*)*(pTable + 0);
		pDest = (uint32_t*)*(pTable + 1);
		for (; pDest < (uint32_t*)(*(pTable + 1) + *(pTable + 2)) ; ) {
      *pDest++ = *pSrc++;
		}
	}
#else
/*  Single section scheme.
 *
 *  The ranges of copy from/to are specified by following symbols
 *    __etext: LMA of start of the section to copy from. Usually end of text
 *    __data_start__: VMA of start of the section to copy to
 *    __data_end__: VMA of end of the section to copy to
 *
 *  All addresses must be aligned to 4 bytes boundary.
 */
  pSrc  = &__etext;
  pDest = &__data_start__;

  for ( ; pDest < &__data_end__ ; ) {
    *pDest++ = *pSrc++;
  }
#endif /*__STARTUP_COPY_MULTIPLE */

/*  This part of work usually is done in C library startup code. Otherwise,
 *  define this macro to enable it in this startup.
 *
 *  There are two schemes too. One can clear multiple BSS sections. Another
 *  can only clear one section. The former is more size expensive than the
 *  latter.
 *
 *  Define macro __STARTUP_CLEAR_BSS_MULTIPLE to choose the former.
 *  Otherwise efine macro __STARTUP_CLEAR_BSS to choose the later.
 */
#ifdef __STARTUP_CLEAR_BSS_MULTIPLE
/*  Multiple sections scheme.
 *
 *  Between symbol address __copy_table_start__ and __copy_table_end__,
 *  there are array of tuples specifying:
 *    offset 0: Start of a BSS section
 *    offset 4: Size of this BSS section. Must be multiply of 4
 */
  pTable = &__zero_table_start__;

  for (; pTable < &__zero_table_end__; pTable = pTable + 2) {
		pDest = (uint32_t*)*(pTable + 0);
		for (; pDest < (uint32_t*)(*(pTable + 0) + *(pTable + 1)) ; ) {
      *pDest++ = 0;
		}
	}
#elif defined (__STARTUP_CLEAR_BSS)
/*  Single BSS section scheme.
 *
 *  The BSS section is specified by following symbols
 *    __bss_start__: start of the BSS section.
 *    __bss_end__: end of the BSS section.
 *
 *  Both addresses must be aligned to 4 bytes boundary.
 */
  pDest = &__bss_start__;

  for ( ; pDest < &__bss_end__ ; ) {
    *pDest++ = 0ul;
  }
#endif /* __STARTUP_CLEAR_BSS_MULTIPLE || __STARTUP_CLEAR_BSS */

#ifndef __NO_SYSTEM_INIT
	SystemInit();
#endif

#ifndef __START
#define __START _start
#endif
	__START();

}


/*----------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *----------------------------------------------------------------------------*/
void Default_Handler(void) {

	while(1);
}
