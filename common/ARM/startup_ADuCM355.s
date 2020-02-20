;/**************************************************************************//**
; * @file     startup_ADuCM355.s
; * @brief    CMSIS Cortex-M ARMv7-M based Core Device Startup File for
; *           Device ADuCM355
; * @version  V5.4.0
; * @date     12. December 2018
; ******************************************************************************/
;/*
; * Copyright (c) 2009-2018 Arm Limited. All rights reserved.
; *
; * SPDX-License-Identifier: Apache-2.0
; *
; * Licensed under the Apache License, Version 2.0 (the License); you may
; * not use this file except in compliance with the License.
; * You may obtain a copy of the License at
; *
; * www.apache.org/licenses/LICENSE-2.0
; *
; * Unless required by applicable law or agreed to in writing, software
; * distributed under the License is distributed on an AS IS BASIS, WITHOUT
; * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
; * See the License for the specific language governing permissions and
; * limitations under the License.
;
; Portions Copyright (c) 2018 Analog Devices, Inc.
; */

#include "adi_config.h"
/* pickup register bitfield and bit mask macros */
#include "ADuCM355_bitm.h"

; ISRAM is enabled by default and can be disabled by using the following macro.
; ISRAM must be disabled here when using SRAM MODES 2 or 3.

;/*
;//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------
;*/

/* IDE prefers C-style comments for this CMSIS comment block */
// <c1> Disable ISRAM at startup
// <i> Enable Serial Number String.
 //#define ADI_DISABLE_INSTRUCTION_SRAM
// </c>

; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000400

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000C00

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __vector_table
                EXPORT  __vector_table_End
                EXPORT  __vector_table_Size

__vector_table       DCD     __initial_sp                ; Top of Stack
                DCD     Reset_Handler               ; Reset Handler
                DCD     NmiSR                       ; NMI Handler
                DCD     HardFault_Handler           ; Hard Fault Handler
                DCD     MemManage_Handler           ; MPU Fault Handler
                DCD     BusFault_Handler            ; Bus Fault Handler
                DCD     UsageFault_Handler          ; Usage Fault Handler
                DCD     0                           ; Reserved
                DCD     0                           ; Reserved
                DCD     0                           ; Reserved
                DCD     0                           ; Reserved
                DCD     SVC_Handler                 ; SVCall Handler
                DCD     DebugMon_Handler            ; Debug Monitor Handler
                DCD     0                           ; Reserved
                DCD     PENDSV_HANDLER              ; PendSV Handler
                DCD     SysTick_Handler             ; SysTick Handler

                ; External Interrupts
                DCD     RTC1_Int_Handler            ; Real Time Clock 1         /* 0  */
                DCD     Ext_Int0_Handler            ; External Interrupt 0      /* 1  */
                DCD     Ext_Int1_Handler            ; External Interrupt 1      /* 2  */
                DCD     Ext_Int2_Handler            ; External Interrupt 2      /* 3  */
                DCD     Afe_Int3_Handler            ; External Interrupt 3      /* 4  */
                DCD     WDog_Tmr_Int_Handler        ; Watchdog Timer            /* 5  */
                DCD     Vreg_over_Int_Handler       ; VREG Over                 /* 6  */
                DCD     Battery_Voltage_Int_Handler ; Battery Voltage Range     /* 7  */
                DCD     RTC0_Int_Handler            ; Real Time Clock 0         /* 8  */
                DCD     GPIO_A_Int_Handler          ; GPIO Int A                /* 9  */
                DCD     GPIO_B_Int_Handler          ; GPIO Int B                /* 10 */
                DCD     GP_Tmr0_Int_Handler         ; GP Timer 0                /* 11 */
                DCD     GP_Tmr1_Int_Handler         ; GP Timer 1                /* 12 */
                DCD     Flash0_Int_Handler          ; Flash Controller          /* 13 */
                DCD     UART_Int_Handler            ; UART0                     /* 14 */
                DCD     SPI0_Int_Handler            ; SPI0                      /* 15 */
                DCD     SPI1_Int_Handler            ; SPI-H                     /* 16 */
                DCD     I2C0_Slave_Int_Handler      ; I2C0 Slave                /* 17 */
                DCD     I2C0_Master_Int_Handler     ; I2C0 Master               /* 18 */
                DCD     DMA_Err_Int_Handler         ; DMA Error                 /* 19 */
                DCD     DMA_SPI1_TX_Int_Handler     ; DMA Channel 0 Done        /* 20 */
                DCD     DMA_SPI1_RX_Int_Handler     ; DMA Channel 1 Done        /* 21 */
                DCD     0                           ; Reserved                  /* 22 */
                DCD     0                           ; Reserved                  /* 23 */
                DCD     DMA_SPI0_TX_Int_Handler     ; DMA Channel 4 Done        /* 24 */
                DCD     DMA_SPI0_RX_Int_Handler     ; DMA Channel 5 Done        /* 25 */
                DCD     0                           ; Reserved                  /* 26 */
                DCD     0                           ; Reserved                  /* 27 */
                DCD     DMA_UART_TX_Int_Handler     ; DMA Channel 8 Done        /* 28 */
                DCD     DMA_UART_RX_Int_Handler     ; DMA Channel 9 Done        /* 29 */
                DCD     DMA_I2C0_STX_Int_Handler    ; DMA Channel 10 Done       /* 30 */
                DCD     DMA_I2C0_SRX_Int_Handler    ; DMA Channel 11 Done       /* 31 */
                DCD     DMA_I2C0_MX_Int_Handler     ; DMA Channel 12 Done       /* 32 */
                DCD     DMA_AES0_IN_Int_Handler     ; DMA Channel 13 Done       /* 33 */
                DCD     DMA_AES0_OUT_Int_Handler    ; DMA Channel 14 Done       /* 34 */
                DCD     DMA_FLASH0_Int_Handler      ; DMA Channel 15 Done       /* 35 */
                DCD     0                           ; Reserved                  /* 36 */
                DCD     0                           ; Reserved                  /* 37 */
                DCD     Crypto_Int_Handler          ; Crypto                    /* 38 */
                DCD     DMA_ADC0_Int_Handler        ; DMA Channel 24 Done       /* 39 */
                DCD     GP_Tmr2_Int_Handler         ; GP Timer 2                /* 40 */
                DCD     0                           ; Reserved                  /* 41 */
                DCD     0                           ; Reserved                  /* 42 */
                DCD     PLL_Int_Handler             ; PLL                       /* 43 */
                DCD     RNG_Int_Handler             ; Nandom Number Generator   /* 44 */
                DCD     0                           ; Reserved                  /* 45 */
                DCD     ADC_Int_Handler             ; ADC                       /* 46 */
                DCD     AfeError_Int_Handler        ;                           /* 47 */
                DCD     AfeAdc_Int_Handler          ;                           /* 48 */
                DCD     AfeGeneral_Int_Handler      ;                           /* 49 */
                DCD     AfeCMDFifo_Int_Handler      ;                           /* 50 */
                DCD     AfeDATAFifo_Int_Handler     ;                           /* 51 */
                DCD     AfeWdt_Int_Handler          ;                           /* 52 */
                DCD     AfeCrcError_Int_Handler     ;                           /* 53 */
                DCD     AfeGpTimer0_Int_Handler     ;                           /* 54 */
                DCD     AfeGpTimer1_Int_Handler     ;                           /* 55 */
                DCD     DMA_AfeCMDFifo_Int_Handler  ; DMA Channel 16 Done (SIP) /* 56 */
                DCD     DMA_AfeDATAFifo_Int_Handler ; DMA Channel 17 Done (SIP) /* 57 */
                DCD     DMA_SIP2_Int_Handler        ; DMA Channel 18 Done (SIP) /* 58 */
                DCD     DMA_SIP3_Int_Handler        ; DMA Channel 19 Done (SIP) /* 59 */
                DCD     DMA_SIP4_Int_Handler        ; DMA Channel 20 Done (SIP) /* 60 */
                DCD     DMA_SIP5_Int_Handler        ; DMA Channel 21 Done (SIP) /* 61 */
                DCD     DMA_SIP6_Int_Handler        ; DMA Channel 22 Done (SIP) /* 62 */
                DCD     DMA_SIP7_Int_Handler        ; DMA Channel 23 Done (SIP) /* 63 */
                DCD     0                           ; Reserved                  /* unused */
__vector_table_End

__vector_table_Size  EQU     __vector_table_End - __vector_table

                AREA    |.ARM.__at_0x180|, CODE, READONLY
                DCD     0xFFFFFFFF ; ReadProtectKeyHash
                DCD     0xFFFFFFFF ; ReadProtectKeyHash
                DCD     0xFFFFFFFF ; ReadProtectKeyHash
                DCD     0xFFFFFFFF ; ReadProtectKeyHash
                DCD     0xA79C3203 ; CrcOfReadProtectKeyHash
                DCD     0x00000000 ; LastCRCPage
                DCD     0xFFFFFFFF ; InCircuitWriteProtectCode
                DCD     0xFFFFFFFF ; FlashBlockWriteProtect

                AREA    |.ARM.__at_0x7FC|, CODE, READONLY
                DCD     0xFFFFFFFF ; LastCRCPage
                
#ifdef RELOCATE_IVT      
				AREA    |.ARM.__at_0x20000000|, DATA, NOINIT
				EXPORT  __relocated_vector_table
__relocated_vector_table SPACE __vector_table_Size
#endif	
                
                
                
                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  __main
#ifdef ADI_DISABLE_INSTRUCTION_SRAM
                ; Disable ISRAM before we access the stack or any data 
                
                ; Load the SRAM control register 
                LDR R1, =REG_PMG0_TST_SRAM_CTL;             
                LDR R0, [R1] ;
                ; Clear the ISRAM enable bit 
                BIC R0, R0, # BITM_PMG_TST_SRAM_CTL_INSTREN ; 
                ; Store ->  ISRAM memory can now be used as data. 
                STR R0, [R1] ;                             
#endif
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NmiSR     PROC
                EXPORT  NmiSR               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler         [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler          [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler        [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler          [WEAK]
                B       .
                ENDP
PENDSV_HANDLER  PROC
                EXPORT  PENDSV_HANDLER            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT RTC1_Int_Handler            [WEAK]
                EXPORT Ext_Int0_Handler            [WEAK]
                EXPORT Ext_Int1_Handler            [WEAK]
                EXPORT Ext_Int2_Handler            [WEAK]
                EXPORT Afe_Int3_Handler            [WEAK]
                EXPORT WDog_Tmr_Int_Handler        [WEAK]
                EXPORT Vreg_over_Int_Handler       [WEAK]
                EXPORT Battery_Voltage_Int_Handler [WEAK]
                EXPORT RTC0_Int_Handler            [WEAK]
                EXPORT GPIO_A_Int_Handler          [WEAK]
                EXPORT GPIO_B_Int_Handler          [WEAK]
                EXPORT GP_Tmr0_Int_Handler         [WEAK]
                EXPORT GP_Tmr1_Int_Handler         [WEAK]
                EXPORT Flash0_Int_Handler          [WEAK]
                EXPORT UART_Int_Handler            [WEAK]
                EXPORT SPI0_Int_Handler            [WEAK]
                EXPORT SPI1_Int_Handler            [WEAK]
                EXPORT I2C0_Slave_Int_Handler      [WEAK]
                EXPORT I2C0_Master_Int_Handler     [WEAK]
                EXPORT DMA_Err_Int_Handler         [WEAK]
                EXPORT DMA_SPI0_TX_Int_Handler     [WEAK]
                EXPORT DMA_SPI0_RX_Int_Handler     [WEAK]
                EXPORT DMA_SPI1_TX_Int_Handler     [WEAK]
                EXPORT DMA_SPI1_RX_Int_Handler     [WEAK]
                EXPORT DMA_UART_TX_Int_Handler     [WEAK]
                EXPORT DMA_UART_RX_Int_Handler     [WEAK]
                EXPORT DMA_I2C0_STX_Int_Handler    [WEAK]
                EXPORT DMA_I2C0_SRX_Int_Handler    [WEAK]
                EXPORT DMA_I2C0_MX_Int_Handler     [WEAK]
                EXPORT DMA_AES0_IN_Int_Handler     [WEAK]
                EXPORT DMA_AES0_OUT_Int_Handler    [WEAK]
                EXPORT DMA_FLASH0_Int_Handler      [WEAK]
                EXPORT Crypto_Int_Handler          [WEAK]
                EXPORT DMA_ADC0_Int_Handler        [WEAK]
                EXPORT GP_Tmr2_Int_Handler         [WEAK]
                EXPORT PLL_Int_Handler             [WEAK]
                EXPORT RNG_Int_Handler             [WEAK]
                EXPORT ADC_Int_Handler             [WEAK]
                EXPORT DMA_AfeCMDFifo_Int_Handler  [WEAK]
                EXPORT DMA_AfeDATAFifo_Int_Handler [WEAK]
                EXPORT DMA_SIP2_Int_Handler        [WEAK]
                EXPORT DMA_SIP3_Int_Handler        [WEAK]
                EXPORT DMA_SIP4_Int_Handler        [WEAK]
                EXPORT DMA_SIP5_Int_Handler        [WEAK]
                EXPORT DMA_SIP6_Int_Handler        [WEAK]
                EXPORT DMA_SIP7_Int_Handler        [WEAK]
                EXPORT AfeError_Int_Handler        [WEAK]
                EXPORT AfeAdc_Int_Handler          [WEAK]
                EXPORT AfeGeneral_Int_Handler      [WEAK]
                EXPORT AfeCMDFifo_Int_Handler      [WEAK]
                EXPORT AfeDATAFifo_Int_Handler     [WEAK]
                EXPORT AfeWdt_Int_Handler          [WEAK]
                EXPORT AfeCrcError_Int_Handler     [WEAK]
                EXPORT AfeGpTimer0_Int_Handler     [WEAK]
                EXPORT AfeGpTimer1_Int_Handler     [WEAK]

RTC1_Int_Handler
Ext_Int0_Handler
Ext_Int1_Handler
Ext_Int2_Handler
Afe_Int3_Handler
WDog_Tmr_Int_Handler
Vreg_over_Int_Handler
Battery_Voltage_Int_Handler
RTC0_Int_Handler
GPIO_A_Int_Handler
GPIO_B_Int_Handler
GP_Tmr0_Int_Handler
GP_Tmr1_Int_Handler
Flash0_Int_Handler
UART_Int_Handler
SPI0_Int_Handler
SPI1_Int_Handler
I2C0_Slave_Int_Handler
I2C0_Master_Int_Handler
DMA_Err_Int_Handler
DMA_SPI0_TX_Int_Handler
DMA_SPI0_RX_Int_Handler
DMA_SPI1_TX_Int_Handler
DMA_SPI1_RX_Int_Handler
DMA_UART_TX_Int_Handler
DMA_UART_RX_Int_Handler
DMA_I2C0_STX_Int_Handler
DMA_I2C0_SRX_Int_Handler
DMA_I2C0_MX_Int_Handler
DMA_AES0_IN_Int_Handler
DMA_AES0_OUT_Int_Handler
DMA_FLASH0_Int_Handler
Crypto_Int_Handler
DMA_ADC0_Int_Handler
GP_Tmr2_Int_Handler
PLL_Int_Handler
RNG_Int_Handler
ADC_Int_Handler
DMA_AfeCMDFifo_Int_Handler
DMA_AfeDATAFifo_Int_Handler
DMA_SIP2_Int_Handler
DMA_SIP3_Int_Handler
DMA_SIP4_Int_Handler
DMA_SIP5_Int_Handler
DMA_SIP6_Int_Handler
DMA_SIP7_Int_Handler
AfeError_Int_Handler
AfeAdc_Int_Handler
AfeGeneral_Int_Handler
AfeCMDFifo_Int_Handler
AfeDATAFifo_Int_Handler
AfeWdt_Int_Handler
AfeCrcError_Int_Handler
AfeGpTimer0_Int_Handler
AfeGpTimer1_Int_Handler
                B       .

                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap

__user_initial_stackheap PROC
                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR
                ENDP

                ALIGN

                ENDIF


                END
