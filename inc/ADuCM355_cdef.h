/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#ifndef _ADUCM355_CDEF_H
#define _ADUCM355_CDEF_H

#if defined(_LANGUAGE_C) || (defined(__GNUC__) && !defined(__ASSEMBLER__))
#include <stdint.h>
#endif /* _LANGUAGE_C */

/* pickup register bitfield and bit masks */
#include "ADuCM355.h"


#ifdef __cplusplus
  #define   __I     volatile             /*!< Defines 'read only' permissions                 */
#else
  #define   __I     volatile const       /*!< Defines 'read only' permissions                 */
#endif

#ifndef __O
#define   __O     volatile     /* write only */
#endif

#ifndef __IO
#define   __IO    volatile     /* read-write */
#endif

#if defined (_MISRA_RULES)
#pragma diag(push)
#pragma diag(suppress:misra_rule_5_1:"Allow names over 32 character limit")
#pragma diag(suppress:misra_rule_19_7:"ADI header allows function-like macros")
#pragma diag(suppress:misra_rule_19_13:"ADI headers can use the # and ## preprocessor operators")
#endif /* _MISRA_RULES */


/*  =================================================================================
 *      General Purpose Timer (TMR0)
 *  ================================================================================= */
#define pREG_TMR0_LOAD                   ((__IO     int16_t   *) REG_TMR0_LOAD)                   /*  16-bit load value */
#define pREG_TMR0_CURCNT                 ((__I      int16_t   *) REG_TMR0_CURCNT)                 /*  16-bit timer value */
#define pREG_TMR0_CTL                    ((__IO     uint16_t  *) REG_TMR0_CTL)                    /*  Control */
#define pREG_TMR0_CLRINT                 ((__O      uint16_t  *) REG_TMR0_CLRINT)                 /*  Clear Interrupt */
#define pREG_TMR0_CAPTURE                ((__I      int16_t   *) REG_TMR0_CAPTURE)                /*  Capture */
#define pREG_TMR0_ALOAD                  ((__IO     int16_t   *) REG_TMR0_ALOAD)                  /*  16-bit load value, asynchronous */
#define pREG_TMR0_ACURCNT                ((__I      int16_t   *) REG_TMR0_ACURCNT)                /*  16-bit timer value, asynchronous */
#define pREG_TMR0_STAT                   ((__I      uint16_t  *) REG_TMR0_STAT)                   /*  Status */
#define pREG_TMR0_PWMCTL                 ((__IO     uint16_t  *) REG_TMR0_PWMCTL)                 /*  PWM Control Register */
#define pREG_TMR0_PWMMATCH               ((__IO     int16_t   *) REG_TMR0_PWMMATCH)               /*  PWM Match Value */

/*  =================================================================================
 *      General Purpose Timer (TMR1)
 *  ================================================================================= */
#define pREG_TMR1_LOAD                   ((__IO     int16_t   *) REG_TMR1_LOAD)                   /*  16-bit load value */
#define pREG_TMR1_CURCNT                 ((__I      int16_t   *) REG_TMR1_CURCNT)                 /*  16-bit timer value */
#define pREG_TMR1_CTL                    ((__IO     uint16_t  *) REG_TMR1_CTL)                    /*  Control */
#define pREG_TMR1_CLRINT                 ((__O      uint16_t  *) REG_TMR1_CLRINT)                 /*  Clear Interrupt */
#define pREG_TMR1_CAPTURE                ((__I      int16_t   *) REG_TMR1_CAPTURE)                /*  Capture */
#define pREG_TMR1_ALOAD                  ((__IO     int16_t   *) REG_TMR1_ALOAD)                  /*  16-bit load value, asynchronous */
#define pREG_TMR1_ACURCNT                ((__I      int16_t   *) REG_TMR1_ACURCNT)                /*  16-bit timer value, asynchronous */
#define pREG_TMR1_STAT                   ((__I      uint16_t  *) REG_TMR1_STAT)                   /*  Status */
#define pREG_TMR1_PWMCTL                 ((__IO     uint16_t  *) REG_TMR1_PWMCTL)                 /*  PWM Control Register */
#define pREG_TMR1_PWMMATCH               ((__IO     int16_t   *) REG_TMR1_PWMMATCH)               /*  PWM Match Value */

/*  =================================================================================
 *      General Purpose Timer (TMR2)
 *  ================================================================================= */
#define pREG_TMR2_LOAD                   ((__IO     int16_t   *) REG_TMR2_LOAD)                   /*  16-bit load value */
#define pREG_TMR2_CURCNT                 ((__I      int16_t   *) REG_TMR2_CURCNT)                 /*  16-bit timer value */
#define pREG_TMR2_CTL                    ((__IO     uint16_t  *) REG_TMR2_CTL)                    /*  Control */
#define pREG_TMR2_CLRINT                 ((__O      uint16_t  *) REG_TMR2_CLRINT)                 /*  Clear Interrupt */
#define pREG_TMR2_CAPTURE                ((__I      int16_t   *) REG_TMR2_CAPTURE)                /*  Capture */
#define pREG_TMR2_ALOAD                  ((__IO     int16_t   *) REG_TMR2_ALOAD)                  /*  16-bit load value, asynchronous */
#define pREG_TMR2_ACURCNT                ((__I      int16_t   *) REG_TMR2_ACURCNT)                /*  16-bit timer value, asynchronous */
#define pREG_TMR2_STAT                   ((__I      uint16_t  *) REG_TMR2_STAT)                   /*  Status */
#define pREG_TMR2_PWMCTL                 ((__IO     uint16_t  *) REG_TMR2_PWMCTL)                 /*  PWM Control Register */
#define pREG_TMR2_PWMMATCH               ((__IO     int16_t   *) REG_TMR2_PWMMATCH)               /*  PWM Match Value */

/*  =================================================================================
 *      Real-Time Clock (RTC0)
 *  ================================================================================= */
#define pREG_RTC0_CR0                    ((__IO     uint16_t  *) REG_RTC0_CR0)                    /*  RTC Control 0 */
#define pREG_RTC0_SR0                    ((__IO     uint16_t  *) REG_RTC0_SR0)                    /*  RTC Status 0 */
#define pREG_RTC0_SR1                    ((__I      uint16_t  *) REG_RTC0_SR1)                    /*  RTC Status 1 */
#define pREG_RTC0_CNT0                   ((__IO     uint16_t  *) REG_RTC0_CNT0)                   /*  RTC Count 0 */
#define pREG_RTC0_CNT1                   ((__IO     uint16_t  *) REG_RTC0_CNT1)                   /*  RTC Count 1 */
#define pREG_RTC0_ALM0                   ((__IO     uint16_t  *) REG_RTC0_ALM0)                   /*  RTC Alarm 0 */
#define pREG_RTC0_ALM1                   ((__IO     uint16_t  *) REG_RTC0_ALM1)                   /*  RTC Alarm 1 */
#define pREG_RTC0_TRM                    ((__IO     uint16_t  *) REG_RTC0_TRM)                    /*  RTC Trim */
#define pREG_RTC0_GWY                    ((__O      uint16_t  *) REG_RTC0_GWY)                    /*  RTC Gateway */
#define pREG_RTC0_CR1                    ((__IO     uint16_t  *) REG_RTC0_CR1)                    /*  RTC Control 1 */
#define pREG_RTC0_SR2                    ((__IO     uint16_t  *) REG_RTC0_SR2)                    /*  RTC Status 2 */
#define pREG_RTC0_SNAP0                  ((__I      uint16_t  *) REG_RTC0_SNAP0)                  /*  RTC Snapshot 0 */
#define pREG_RTC0_SNAP1                  ((__I      uint16_t  *) REG_RTC0_SNAP1)                  /*  RTC Snapshot 1 */
#define pREG_RTC0_SNAP2                  ((__I      uint16_t  *) REG_RTC0_SNAP2)                  /*  RTC Snapshot 2 */
#define pREG_RTC0_MOD                    ((__I      uint16_t  *) REG_RTC0_MOD)                    /*  RTC Modulo */
#define pREG_RTC0_CNT2                   ((__I      uint16_t  *) REG_RTC0_CNT2)                   /*  RTC Count 2 */
#define pREG_RTC0_ALM2                   ((__IO     uint16_t  *) REG_RTC0_ALM2)                   /*  RTC Alarm 2 */
#define pREG_RTC0_SR3                    ((__IO     uint16_t  *) REG_RTC0_SR3)                    /*  RTC Status 3 */
#define pREG_RTC0_CR2IC                  ((__IO     uint16_t  *) REG_RTC0_CR2IC)                  /*  RTC Control 2 for Configuring Input Capture Channels */
#define pREG_RTC0_CR3OC                  ((__IO     uint16_t  *) REG_RTC0_CR3OC)                  /*  RTC Control 3 for Configuring Output Compare Channel */
#define pREG_RTC0_CR4OC                  ((__IO     uint16_t  *) REG_RTC0_CR4OC)                  /*  RTC Control 4 for Configuring Output Compare Channel */
#define pREG_RTC0_OCMSK                  ((__IO     uint16_t  *) REG_RTC0_OCMSK)                  /*  RTC Masks for Output Compare Channel */
#define pREG_RTC0_OC1ARL                 ((__IO     uint16_t  *) REG_RTC0_OC1ARL)                 /*  RTC Auto-Reload for Output Compare Channel 1 */
#define pREG_RTC0_IC2                    ((__I      uint16_t  *) REG_RTC0_IC2)                    /*  RTC Input Capture Channel 2 */
#define pREG_RTC0_IC3                    ((__I      uint16_t  *) REG_RTC0_IC3)                    /*  RTC Input Capture Channel 3 */
#define pREG_RTC0_IC4                    ((__I      uint16_t  *) REG_RTC0_IC4)                    /*  RTC Input Capture Channel 4 */
#define pREG_RTC0_OC1                    ((__IO     uint16_t  *) REG_RTC0_OC1)                    /*  RTC Output Compare Channel 1 */
#define pREG_RTC0_SR4                    ((__I      uint16_t  *) REG_RTC0_SR4)                    /*  RTC Status 4 */
#define pREG_RTC0_SR5                    ((__I      uint16_t  *) REG_RTC0_SR5)                    /*  RTC Status 5 */
#define pREG_RTC0_SR6                    ((__I      uint16_t  *) REG_RTC0_SR6)                    /*  RTC Status 6 */
#define pREG_RTC0_OC1TGT                 ((__I      uint16_t  *) REG_RTC0_OC1TGT)                 /*  RTC Output Compare Channel 1 Target */
#define pREG_RTC0_FRZCNT                 ((__I      uint16_t  *) REG_RTC0_FRZCNT)                 /*  RTC Freeze Count */

/*  =================================================================================
 *      Real-Time Clock (RTC1)
 *  ================================================================================= */
#define pREG_RTC1_CR0                    ((__IO     uint16_t  *) REG_RTC1_CR0)                    /*  RTC Control 0 */
#define pREG_RTC1_SR0                    ((__IO     uint16_t  *) REG_RTC1_SR0)                    /*  RTC Status 0 */
#define pREG_RTC1_SR1                    ((__I      uint16_t  *) REG_RTC1_SR1)                    /*  RTC Status 1 */
#define pREG_RTC1_CNT0                   ((__IO     uint16_t  *) REG_RTC1_CNT0)                   /*  RTC Count 0 */
#define pREG_RTC1_CNT1                   ((__IO     uint16_t  *) REG_RTC1_CNT1)                   /*  RTC Count 1 */
#define pREG_RTC1_ALM0                   ((__IO     uint16_t  *) REG_RTC1_ALM0)                   /*  RTC Alarm 0 */
#define pREG_RTC1_ALM1                   ((__IO     uint16_t  *) REG_RTC1_ALM1)                   /*  RTC Alarm 1 */
#define pREG_RTC1_TRM                    ((__IO     uint16_t  *) REG_RTC1_TRM)                    /*  RTC Trim */
#define pREG_RTC1_GWY                    ((__O      uint16_t  *) REG_RTC1_GWY)                    /*  RTC Gateway */
#define pREG_RTC1_CR1                    ((__IO     uint16_t  *) REG_RTC1_CR1)                    /*  RTC Control 1 */
#define pREG_RTC1_SR2                    ((__IO     uint16_t  *) REG_RTC1_SR2)                    /*  RTC Status 2 */
#define pREG_RTC1_SNAP0                  ((__I      uint16_t  *) REG_RTC1_SNAP0)                  /*  RTC Snapshot 0 */
#define pREG_RTC1_SNAP1                  ((__I      uint16_t  *) REG_RTC1_SNAP1)                  /*  RTC Snapshot 1 */
#define pREG_RTC1_SNAP2                  ((__I      uint16_t  *) REG_RTC1_SNAP2)                  /*  RTC Snapshot 2 */
#define pREG_RTC1_MOD                    ((__I      uint16_t  *) REG_RTC1_MOD)                    /*  RTC Modulo */
#define pREG_RTC1_CNT2                   ((__I      uint16_t  *) REG_RTC1_CNT2)                   /*  RTC Count 2 */
#define pREG_RTC1_ALM2                   ((__IO     uint16_t  *) REG_RTC1_ALM2)                   /*  RTC Alarm 2 */
#define pREG_RTC1_SR3                    ((__IO     uint16_t  *) REG_RTC1_SR3)                    /*  RTC Status 3 */
#define pREG_RTC1_CR2IC                  ((__IO     uint16_t  *) REG_RTC1_CR2IC)                  /*  RTC Control 2 for Configuring Input Capture Channels */
#define pREG_RTC1_CR3OC                  ((__IO     uint16_t  *) REG_RTC1_CR3OC)                  /*  RTC Control 3 for Configuring Output Compare Channel */
#define pREG_RTC1_CR4OC                  ((__IO     uint16_t  *) REG_RTC1_CR4OC)                  /*  RTC Control 4 for Configuring Output Compare Channel */
#define pREG_RTC1_OCMSK                  ((__IO     uint16_t  *) REG_RTC1_OCMSK)                  /*  RTC Masks for Output Compare Channel */
#define pREG_RTC1_OC1ARL                 ((__IO     uint16_t  *) REG_RTC1_OC1ARL)                 /*  RTC Auto-Reload for Output Compare Channel 1 */
#define pREG_RTC1_IC2                    ((__I      uint16_t  *) REG_RTC1_IC2)                    /*  RTC Input Capture Channel 2 */
#define pREG_RTC1_IC3                    ((__I      uint16_t  *) REG_RTC1_IC3)                    /*  RTC Input Capture Channel 3 */
#define pREG_RTC1_IC4                    ((__I      uint16_t  *) REG_RTC1_IC4)                    /*  RTC Input Capture Channel 4 */
#define pREG_RTC1_OC1                    ((__IO     uint16_t  *) REG_RTC1_OC1)                    /*  RTC Output Compare Channel 1 */
#define pREG_RTC1_SR4                    ((__I      uint16_t  *) REG_RTC1_SR4)                    /*  RTC Status 4 */
#define pREG_RTC1_SR5                    ((__I      uint16_t  *) REG_RTC1_SR5)                    /*  RTC Status 5 */
#define pREG_RTC1_SR6                    ((__I      uint16_t  *) REG_RTC1_SR6)                    /*  RTC Status 6 */
#define pREG_RTC1_OC1TGT                 ((__I      uint16_t  *) REG_RTC1_OC1TGT)                 /*  RTC Output Compare Channel 1 Target */
#define pREG_RTC1_FRZCNT                 ((__I      uint16_t  *) REG_RTC1_FRZCNT)                 /*  RTC Freeze Count */

/*  =================================================================================
 *      System Identification and Debug Enable (SYS)
 *  ================================================================================= */
#define pREG_SYS_ADIID                   ((__I      uint16_t  *) REG_SYS_ADIID)                   /*  ADI Identification */
#define pREG_SYS_CHIPID                  ((__I      uint16_t  *) REG_SYS_CHIPID)                  /*  Chip Identifier */
#define pREG_SYS_SWDEN                   ((__O      uint16_t  *) REG_SYS_SWDEN)                   /*  Serial Wire Debug Enable */

/*  =================================================================================
 *      Watchdog Timer (WDT0)
 *  ================================================================================= */
#define pREG_WDT0_LOAD                   ((__IO     int16_t   *) REG_WDT0_LOAD)                   /*  Load value */
#define pREG_WDT0_CCNT                   ((__I      int16_t   *) REG_WDT0_CCNT)                   /*  Current count value */
#define pREG_WDT0_CTL                    ((__IO     uint16_t  *) REG_WDT0_CTL)                    /*  Control */
#define pREG_WDT0_RESTART                ((__O      int16_t   *) REG_WDT0_RESTART)                /*  Clear interrupt */
#define pREG_WDT0_STAT                   ((__I      uint16_t  *) REG_WDT0_STAT)                   /*  Status */

/*  =================================================================================
 *      I2C Master/Slave (I2C0)
 *  ================================================================================= */
#define pREG_I2C0_MCTL                   ((__IO     uint16_t  *) REG_I2C0_MCTL)                   /*  Master control */
#define pREG_I2C0_MSTAT                  ((__IO     uint16_t  *) REG_I2C0_MSTAT)                  /*  Master status */
#define pREG_I2C0_MRX                    ((__I      uint16_t  *) REG_I2C0_MRX)                    /*  Master receive data */
#define pREG_I2C0_MTX                    ((__IO     uint16_t  *) REG_I2C0_MTX)                    /*  Master transmit data */
#define pREG_I2C0_MRXCNT                 ((__IO     uint16_t  *) REG_I2C0_MRXCNT)                 /*  Master receive data count */
#define pREG_I2C0_MCRXCNT                ((__I      uint16_t  *) REG_I2C0_MCRXCNT)                /*  Master current receive data count */
#define pREG_I2C0_ADDR1                  ((__IO     uint16_t  *) REG_I2C0_ADDR1)                  /*  1st master address byte */
#define pREG_I2C0_ADDR2                  ((__IO     uint16_t  *) REG_I2C0_ADDR2)                  /*  2nd master address byte */
#define pREG_I2C0_BYT                    ((__IO     uint16_t  *) REG_I2C0_BYT)                    /*  Start byte */
#define pREG_I2C0_DIV                    ((__IO     uint16_t  *) REG_I2C0_DIV)                    /*  Serial clock period divisor */
#define pREG_I2C0_SCTL                   ((__IO     uint16_t  *) REG_I2C0_SCTL)                   /*  Slave control */
#define pREG_I2C0_SSTAT                  ((__IO     uint16_t  *) REG_I2C0_SSTAT)                  /*  Slave I2C Status/Error/IRQ */
#define pREG_I2C0_SRX                    ((__I      uint16_t  *) REG_I2C0_SRX)                    /*  Slave receive */
#define pREG_I2C0_STX                    ((__IO     uint16_t  *) REG_I2C0_STX)                    /*  Slave transmit */
#define pREG_I2C0_ALT                    ((__IO     uint16_t  *) REG_I2C0_ALT)                    /*  Hardware general call ID */
#define pREG_I2C0_ID0                    ((__IO     uint16_t  *) REG_I2C0_ID0)                    /*  1st slave address device ID */
#define pREG_I2C0_ID1                    ((__IO     uint16_t  *) REG_I2C0_ID1)                    /*  2nd slave address device ID */
#define pREG_I2C0_ID2                    ((__IO     uint16_t  *) REG_I2C0_ID2)                    /*  3rd slave address device ID */
#define pREG_I2C0_ID3                    ((__IO     uint16_t  *) REG_I2C0_ID3)                    /*  4th slave address device ID */
#define pREG_I2C0_STAT                   ((__IO     uint16_t  *) REG_I2C0_STAT)                   /*  Master and slave FIFO status */
#define pREG_I2C0_SHCTL                  ((__O      uint16_t  *) REG_I2C0_SHCTL)                  /*  Shared control */
#define pREG_I2C0_TCTL                   ((__IO     uint16_t  *) REG_I2C0_TCTL)                   /*  Timing Control Register */
#define pREG_I2C0_ASTRETCH_SCL           ((__IO     uint16_t  *) REG_I2C0_ASTRETCH_SCL)           /*  Automatic stretch SCL register */

/*  =================================================================================
 *      Serial Peripheral Interface (SPI0)
 *  ================================================================================= */
#define pREG_SPI0_STAT                   ((__IO     uint16_t  *) REG_SPI0_STAT)                   /*  Status */
#define pREG_SPI0_RX                     ((__I      uint16_t  *) REG_SPI0_RX)                     /*  Receive */
#define pREG_SPI0_TX                     ((__O      uint16_t  *) REG_SPI0_TX)                     /*  Transmit */
#define pREG_SPI0_DIV                    ((__IO     uint16_t  *) REG_SPI0_DIV)                    /*  SPI baud rate selection */
#define pREG_SPI0_CTL                    ((__IO     uint16_t  *) REG_SPI0_CTL)                    /*  SPI configuration 1 */
#define pREG_SPI0_IEN                    ((__IO     uint16_t  *) REG_SPI0_IEN)                    /*  SPI configuration 2 */
#define pREG_SPI0_CNT                    ((__IO     uint16_t  *) REG_SPI0_CNT)                    /*  Transfer byte count */
#define pREG_SPI0_DMA                    ((__IO     uint16_t  *) REG_SPI0_DMA)                    /*  SPI DMA enable */
#define pREG_SPI0_FIFO_STAT              ((__I      uint16_t  *) REG_SPI0_FIFO_STAT)              /*  FIFO Status */
#define pREG_SPI0_RD_CTL                 ((__IO     uint16_t  *) REG_SPI0_RD_CTL)                 /*  Read Control */
#define pREG_SPI0_FLOW_CTL               ((__IO     uint16_t  *) REG_SPI0_FLOW_CTL)               /*  Flow Control */
#define pREG_SPI0_WAIT_TMR               ((__IO     uint16_t  *) REG_SPI0_WAIT_TMR)               /*  Wait timer for flow control */
#define pREG_SPI0_CS_CTL                 ((__IO     uint16_t  *) REG_SPI0_CS_CTL)                 /*  Chip-Select control for multi-slave connections */
#define pREG_SPI0_CS_OVERRIDE            ((__IO     uint16_t  *) REG_SPI0_CS_OVERRIDE)            /*  Chip-Select Override */

/*  =================================================================================
 *      Serial Peripheral Interface (SPI1)
 *  ================================================================================= */
#define pREG_SPI1_STAT                   ((__IO     uint16_t  *) REG_SPI1_STAT)                   /*  Status */
#define pREG_SPI1_RX                     ((__I      uint16_t  *) REG_SPI1_RX)                     /*  Receive */
#define pREG_SPI1_TX                     ((__O      uint16_t  *) REG_SPI1_TX)                     /*  Transmit */
#define pREG_SPI1_DIV                    ((__IO     uint16_t  *) REG_SPI1_DIV)                    /*  SPI baud rate selection */
#define pREG_SPI1_CTL                    ((__IO     uint16_t  *) REG_SPI1_CTL)                    /*  SPI configuration 1 */
#define pREG_SPI1_IEN                    ((__IO     uint16_t  *) REG_SPI1_IEN)                    /*  SPI configuration 2 */
#define pREG_SPI1_CNT                    ((__IO     uint16_t  *) REG_SPI1_CNT)                    /*  Transfer byte count */
#define pREG_SPI1_DMA                    ((__IO     uint16_t  *) REG_SPI1_DMA)                    /*  SPI DMA enable */
#define pREG_SPI1_FIFO_STAT              ((__I      uint16_t  *) REG_SPI1_FIFO_STAT)              /*  FIFO Status */
#define pREG_SPI1_RD_CTL                 ((__IO     uint16_t  *) REG_SPI1_RD_CTL)                 /*  Read Control */
#define pREG_SPI1_FLOW_CTL               ((__IO     uint16_t  *) REG_SPI1_FLOW_CTL)               /*  Flow Control */
#define pREG_SPI1_WAIT_TMR               ((__IO     uint16_t  *) REG_SPI1_WAIT_TMR)               /*  Wait timer for flow control */
#define pREG_SPI1_CS_CTL                 ((__IO     uint16_t  *) REG_SPI1_CS_CTL)                 /*  Chip-Select control for multi-slave connections */
#define pREG_SPI1_CS_OVERRIDE            ((__IO     uint16_t  *) REG_SPI1_CS_OVERRIDE)            /*  Chip-Select Override */

/*  =================================================================================
 *       (UART0)
 *  ================================================================================= */
#define pREG_UART0_COMRX                 ((__I      uint16_t  *) REG_UART0_COMRX)                 /*  Receive Buffer Register */
#define pREG_UART0_COMTX                 ((__O      uint16_t  *) REG_UART0_COMTX)                 /*  Transmit Holding Register */
#define pREG_UART0_COMIEN                ((__IO     uint16_t  *) REG_UART0_COMIEN)                /*  Interrupt Enable */
#define pREG_UART0_COMIIR                ((__I      uint16_t  *) REG_UART0_COMIIR)                /*  Interrupt ID */
#define pREG_UART0_COMLCR                ((__IO     uint16_t  *) REG_UART0_COMLCR)                /*  Line Control */
#define pREG_UART0_COMMCR                ((__IO     uint16_t  *) REG_UART0_COMMCR)                /*  Modem Control */
#define pREG_UART0_COMLSR                ((__I      uint16_t  *) REG_UART0_COMLSR)                /*  Line Status */
#define pREG_UART0_COMMSR                ((__I      uint16_t  *) REG_UART0_COMMSR)                /*  Modem Status */
#define pREG_UART0_COMSCR                ((__IO     uint16_t  *) REG_UART0_COMSCR)                /*  Scratch buffer */
#define pREG_UART0_COMFCR                ((__IO     uint16_t  *) REG_UART0_COMFCR)                /*  FIFO Control */
#define pREG_UART0_COMFBR                ((__IO     uint16_t  *) REG_UART0_COMFBR)                /*  Fractional Baud Rate */
#define pREG_UART0_COMDIV                ((__IO     int16_t   *) REG_UART0_COMDIV)                /*  Baudrate divider */
#define pREG_UART0_COMLCR2               ((__IO     uint16_t  *) REG_UART0_COMLCR2)               /*  second Line Control */
#define pREG_UART0_COMCTL                ((__IO     uint16_t  *) REG_UART0_COMCTL)                /*  UART control register */
#define pREG_UART0_COMRFC                ((__I      uint16_t  *) REG_UART0_COMRFC)                /*  RX FIFO byte count */
#define pREG_UART0_COMTFC                ((__I      uint16_t  *) REG_UART0_COMTFC)                /*  TX FIFO byte count */
#define pREG_UART0_COMRSC                ((__IO     uint16_t  *) REG_UART0_COMRSC)                /*  RS485 half-duplex Control */
#define pREG_UART0_COMACR                ((__IO     uint16_t  *) REG_UART0_COMACR)                /*  Auto Baud Control */
#define pREG_UART0_COMASRL               ((__I      uint16_t  *) REG_UART0_COMASRL)               /*  Auto Baud Status (Low) */
#define pREG_UART0_COMASRH               ((__I      uint16_t  *) REG_UART0_COMASRH)               /*  Auto Baud Status (High) */

/*  =================================================================================
 *      DMA (DMA0)
 *  ================================================================================= */
#define pREG_DMA0_STAT                   ((__I      uint32_t  *) REG_DMA0_STAT)                   /*  DMA Status */
#define pREG_DMA0_CFG                    ((__O      uint32_t  *) REG_DMA0_CFG)                    /*  DMA Configuration */
#define pREG_DMA0_PDBPTR                 ((__IO     int32_t   *) REG_DMA0_PDBPTR)                 /*  DMA channel primary control data base pointer */
#define pREG_DMA0_ADBPTR                 ((__I      int32_t   *) REG_DMA0_ADBPTR)                 /*  DMA channel alternate control data base pointer */
#define pREG_DMA0_SWREQ                  ((__O      uint32_t  *) REG_DMA0_SWREQ)                  /*  DMA channel software request */
#define pREG_DMA0_RMSK_SET               ((__IO     uint32_t  *) REG_DMA0_RMSK_SET)               /*  DMA channel request mask set */
#define pREG_DMA0_RMSK_CLR               ((__O      uint32_t  *) REG_DMA0_RMSK_CLR)               /*  DMA channel request mask clear */
#define pREG_DMA0_EN_SET                 ((__IO     uint32_t  *) REG_DMA0_EN_SET)                 /*  DMA channel enable set */
#define pREG_DMA0_EN_CLR                 ((__O      uint32_t  *) REG_DMA0_EN_CLR)                 /*  DMA channel enable clear */
#define pREG_DMA0_ALT_SET                ((__IO     uint32_t  *) REG_DMA0_ALT_SET)                /*  DMA channel primary-alternate set */
#define pREG_DMA0_ALT_CLR                ((__O      uint32_t  *) REG_DMA0_ALT_CLR)                /*  DMA channel primary-alternate clear */
#define pREG_DMA0_PRI_SET                ((__O      uint32_t  *) REG_DMA0_PRI_SET)                /*  DMA channel priority set */
#define pREG_DMA0_PRI_CLR                ((__O      uint32_t  *) REG_DMA0_PRI_CLR)                /*  DMA channel priority clear */
#define pREG_DMA0_ERRCHNL_CLR            ((__IO     uint32_t  *) REG_DMA0_ERRCHNL_CLR)            /*  DMA Per Channel Error Clear */
#define pREG_DMA0_ERR_CLR                ((__IO     uint32_t  *) REG_DMA0_ERR_CLR)                /*  DMA bus error clear */
#define pREG_DMA0_INVALIDDESC_CLR        ((__IO     uint32_t  *) REG_DMA0_INVALIDDESC_CLR)        /*  DMA Per Channel Invalid Descriptor Clear */
#define pREG_DMA0_BS_SET                 ((__IO     uint32_t  *) REG_DMA0_BS_SET)                 /*  DMA channel bytes swap enable set */
#define pREG_DMA0_BS_CLR                 ((__O      uint32_t  *) REG_DMA0_BS_CLR)                 /*  DMA channel bytes swap enable clear */
#define pREG_DMA0_SRCADDR_SET            ((__IO     uint32_t  *) REG_DMA0_SRCADDR_SET)            /*  DMA channel source address decrement enable set */
#define pREG_DMA0_SRCADDR_CLR            ((__O      uint32_t  *) REG_DMA0_SRCADDR_CLR)            /*  DMA channel source address decrement enable clear */
#define pREG_DMA0_DSTADDR_SET            ((__IO     uint32_t  *) REG_DMA0_DSTADDR_SET)            /*  DMA channel destination address decrement enable set */
#define pREG_DMA0_DSTADDR_CLR            ((__O      uint32_t  *) REG_DMA0_DSTADDR_CLR)            /*  DMA channel destination address decrement enable clear */
#define pREG_DMA0_REVID                  ((__I      uint32_t  *) REG_DMA0_REVID)                  /*  DMA Controller Revision ID */

/*  =================================================================================
 *      Flash Controller (FLCC0)
 *  ================================================================================= */
#define pREG_FLCC0_STAT                  ((__IO     uint32_t  *) REG_FLCC0_STAT)                  /*  Status */
#define pREG_FLCC0_IEN                   ((__IO     uint32_t  *) REG_FLCC0_IEN)                   /*  Interrupt Enable */
#define pREG_FLCC0_CMD                   ((__IO     uint32_t  *) REG_FLCC0_CMD)                   /*  Command */
#define pREG_FLCC0_KH_ADDR               ((__IO     uint32_t  *) REG_FLCC0_KH_ADDR)               /*  WRITE Address */
#define pREG_FLCC0_KH_DATA0              ((__IO     int32_t   *) REG_FLCC0_KH_DATA0)              /*  WRITE Lower Data */
#define pREG_FLCC0_KH_DATA1              ((__IO     int32_t   *) REG_FLCC0_KH_DATA1)              /*  WRITE Upper Data */
#define pREG_FLCC0_PAGE_ADDR0            ((__IO     uint32_t  *) REG_FLCC0_PAGE_ADDR0)            /*  Lower Page Address */
#define pREG_FLCC0_PAGE_ADDR1            ((__IO     uint32_t  *) REG_FLCC0_PAGE_ADDR1)            /*  Upper Page Address */
#define pREG_FLCC0_KEY                   ((__O      int32_t   *) REG_FLCC0_KEY)                   /*  Key */
#define pREG_FLCC0_WR_ABORT_ADDR         ((__I      int32_t   *) REG_FLCC0_WR_ABORT_ADDR)         /*  Write Abort Address */
#define pREG_FLCC0_WRPROT                ((__IO     int32_t   *) REG_FLCC0_WRPROT)                /*  Write Protection */
#define pREG_FLCC0_SIGNATURE             ((__I      int32_t   *) REG_FLCC0_SIGNATURE)             /*  Signature */
#define pREG_FLCC0_UCFG                  ((__IO     uint32_t  *) REG_FLCC0_UCFG)                  /*  User Configuration */
#define pREG_FLCC0_TIME_PARAM0           ((__IO     uint32_t  *) REG_FLCC0_TIME_PARAM0)           /*  Time Parameter 0 */
#define pREG_FLCC0_TIME_PARAM1           ((__IO     uint32_t  *) REG_FLCC0_TIME_PARAM1)           /*  Time parameter 1 */
#define pREG_FLCC0_ABORT_EN_LO           ((__IO     uint32_t  *) REG_FLCC0_ABORT_EN_LO)           /*  IRQ Abort Enable (lower bits) */
#define pREG_FLCC0_ABORT_EN_HI           ((__IO     uint32_t  *) REG_FLCC0_ABORT_EN_HI)           /*  IRQ Abort Enable (upper bits) */
#define pREG_FLCC0_ECC_CFG               ((__IO     uint32_t  *) REG_FLCC0_ECC_CFG)               /*  ECC Config */
#define pREG_FLCC0_ECC_ADDR              ((__I      uint32_t  *) REG_FLCC0_ECC_ADDR)              /*  ECC Status (Address) */
#define pREG_FLCC0_ADI_POR_SEC           ((__IO     uint32_t  *) REG_FLCC0_ADI_POR_SEC)           /*  ADI flash security */

/*  =================================================================================
 *      Cache Controller (FLCC0_CACHE)
 *  ================================================================================= */
#define pREG_FLCC0_CACHE_STAT            ((__I      uint32_t  *) REG_FLCC0_CACHE_STAT)            /*  Cache Status register */
#define pREG_FLCC0_CACHE_SETUP           ((__IO     uint32_t  *) REG_FLCC0_CACHE_SETUP)           /*  Cache Setup register */
#define pREG_FLCC0_CACHE_KEY             ((__O      int32_t   *) REG_FLCC0_CACHE_KEY)             /*  Cache Key register */

/*  =================================================================================
 *       (GPIO0)
 *  ================================================================================= */
#define pREG_GPIO0_CFG                   ((__IO     uint32_t  *) REG_GPIO0_CFG)                   /*  Port  Configuration */
#define pREG_GPIO0_OEN                   ((__IO     uint16_t  *) REG_GPIO0_OEN)                   /*  Port output enable */
#define pREG_GPIO0_PE                    ((__IO     uint16_t  *) REG_GPIO0_PE)                    /*  Port output pullup/pulldown enable */
#define pREG_GPIO0_IEN                   ((__IO     uint16_t  *) REG_GPIO0_IEN)                   /*  Port  Input Path Enable */
#define pREG_GPIO0_IN                    ((__I      uint16_t  *) REG_GPIO0_IN)                    /*  Port  registered data input */
#define pREG_GPIO0_OUT                   ((__IO     uint16_t  *) REG_GPIO0_OUT)                   /*  Port data output */
#define pREG_GPIO0_SET                   ((__O      uint16_t  *) REG_GPIO0_SET)                   /*  Port data out set */
#define pREG_GPIO0_CLR                   ((__O      uint16_t  *) REG_GPIO0_CLR)                   /*  Port Data Out Clear */
#define pREG_GPIO0_TGL                   ((__O      uint16_t  *) REG_GPIO0_TGL)                   /*  Port Pin Toggle */
#define pREG_GPIO0_POL                   ((__IO     uint16_t  *) REG_GPIO0_POL)                   /*  Port Interrupt Polarity */
#define pREG_GPIO0_IENA                  ((__IO     uint16_t  *) REG_GPIO0_IENA)                  /*  Port Interrupt A Enable */
#define pREG_GPIO0_IENB                  ((__IO     uint16_t  *) REG_GPIO0_IENB)                  /*  Port Interrupt B Enable */
#define pREG_GPIO0_INT                   ((__IO     uint16_t  *) REG_GPIO0_INT)                   /*  Port Interrupt Status */
#define pREG_GPIO0_DS                    ((__IO     uint16_t  *) REG_GPIO0_DS)                    /*  Port Drive Strength Select */

/*  =================================================================================
 *       (GPIO1)
 *  ================================================================================= */
#define pREG_GPIO1_CFG                   ((__IO     uint32_t  *) REG_GPIO1_CFG)                   /*  Port  Configuration */
#define pREG_GPIO1_OEN                   ((__IO     uint16_t  *) REG_GPIO1_OEN)                   /*  Port output enable */
#define pREG_GPIO1_PE                    ((__IO     uint16_t  *) REG_GPIO1_PE)                    /*  Port output pullup/pulldown enable */
#define pREG_GPIO1_IEN                   ((__IO     uint16_t  *) REG_GPIO1_IEN)                   /*  Port  Input Path Enable */
#define pREG_GPIO1_IN                    ((__I      uint16_t  *) REG_GPIO1_IN)                    /*  Port  registered data input */
#define pREG_GPIO1_OUT                   ((__IO     uint16_t  *) REG_GPIO1_OUT)                   /*  Port data output */
#define pREG_GPIO1_SET                   ((__O      uint16_t  *) REG_GPIO1_SET)                   /*  Port data out set */
#define pREG_GPIO1_CLR                   ((__O      uint16_t  *) REG_GPIO1_CLR)                   /*  Port Data Out Clear */
#define pREG_GPIO1_TGL                   ((__O      uint16_t  *) REG_GPIO1_TGL)                   /*  Port Pin Toggle */
#define pREG_GPIO1_POL                   ((__IO     uint16_t  *) REG_GPIO1_POL)                   /*  Port Interrupt Polarity */
#define pREG_GPIO1_IENA                  ((__IO     uint16_t  *) REG_GPIO1_IENA)                  /*  Port Interrupt A Enable */
#define pREG_GPIO1_IENB                  ((__IO     uint16_t  *) REG_GPIO1_IENB)                  /*  Port Interrupt B Enable */
#define pREG_GPIO1_INT                   ((__IO     uint16_t  *) REG_GPIO1_INT)                   /*  Port Interrupt Status */
#define pREG_GPIO1_DS                    ((__IO     uint16_t  *) REG_GPIO1_DS)                    /*  Port Drive Strength Select */

/*  =================================================================================
 *       (GPIO2)
 *  ================================================================================= */
#define pREG_GPIO2_CFG                   ((__IO     uint32_t  *) REG_GPIO2_CFG)                   /*  Port  Configuration */
#define pREG_GPIO2_OEN                   ((__IO     uint16_t  *) REG_GPIO2_OEN)                   /*  Port output enable */
#define pREG_GPIO2_PE                    ((__IO     uint16_t  *) REG_GPIO2_PE)                    /*  Port output pullup/pulldown enable */
#define pREG_GPIO2_IEN                   ((__IO     uint16_t  *) REG_GPIO2_IEN)                   /*  Port  Input Path Enable */
#define pREG_GPIO2_IN                    ((__I      uint16_t  *) REG_GPIO2_IN)                    /*  Port  registered data input */
#define pREG_GPIO2_OUT                   ((__IO     uint16_t  *) REG_GPIO2_OUT)                   /*  Port data output */
#define pREG_GPIO2_SET                   ((__O      uint16_t  *) REG_GPIO2_SET)                   /*  Port data out set */
#define pREG_GPIO2_CLR                   ((__O      uint16_t  *) REG_GPIO2_CLR)                   /*  Port Data Out Clear */
#define pREG_GPIO2_TGL                   ((__O      uint16_t  *) REG_GPIO2_TGL)                   /*  Port Pin Toggle */
#define pREG_GPIO2_POL                   ((__IO     uint16_t  *) REG_GPIO2_POL)                   /*  Port Interrupt Polarity */
#define pREG_GPIO2_IENA                  ((__IO     uint16_t  *) REG_GPIO2_IENA)                  /*  Port Interrupt A Enable */
#define pREG_GPIO2_IENB                  ((__IO     uint16_t  *) REG_GPIO2_IENB)                  /*  Port Interrupt B Enable */
#define pREG_GPIO2_INT                   ((__IO     uint16_t  *) REG_GPIO2_INT)                   /*  Port Interrupt Status */
#define pREG_GPIO2_DS                    ((__IO     uint16_t  *) REG_GPIO2_DS)                    /*  Port Drive Strength Select */

/*  =================================================================================
 *      CRC Accelerator (CRC0)
 *  ================================================================================= */
#define pREG_CRC0_CTL                    ((__IO     uint32_t  *) REG_CRC0_CTL)                    /*  CRC Control Register */
#define pREG_CRC0_IPDATA                 ((__O      int32_t   *) REG_CRC0_IPDATA)                 /*  Input Data Word Register */
#define pREG_CRC0_RESULT                 ((__IO     int32_t   *) REG_CRC0_RESULT)                 /*  CRC Result Register */
#define pREG_CRC0_POLY                   ((__IO     uint32_t  *) REG_CRC0_POLY)                   /*  Programmable CRC Polynomial */
#define pREG_CRC0_IPBYTE                 ((__O      uint8_t   *) REG_CRC0_IPBYTE)                 /*  Input Data Byte */
#define pREG_CRC0_IPBITS0                ((__O      uint8_t   *) REG_CRC0_IPBITS0)                /*  Input Data Bits */
#define pREG_CRC0_IPBITS1                ((__O      uint8_t   *) REG_CRC0_IPBITS1)                /*  Input Data Bits */
#define pREG_CRC0_IPBITS2                ((__O      uint8_t   *) REG_CRC0_IPBITS2)                /*  Input Data Bits */
#define pREG_CRC0_IPBITS3                ((__O      uint8_t   *) REG_CRC0_IPBITS3)                /*  Input Data Bits */
#define pREG_CRC0_IPBITS4                ((__O      uint8_t   *) REG_CRC0_IPBITS4)                /*  Input Data Bits */
#define pREG_CRC0_IPBITS5                ((__O      uint8_t   *) REG_CRC0_IPBITS5)                /*  Input Data Bits */
#define pREG_CRC0_IPBITS6                ((__O      uint8_t   *) REG_CRC0_IPBITS6)                /*  Input Data Bits */
#define pREG_CRC0_IPBITS7                ((__O      uint8_t   *) REG_CRC0_IPBITS7)                /*  Input Data Bits */

/*  =================================================================================
 *      Random Number Generator (RNG0)
 *  ================================================================================= */
#define pREG_RNG0_CTL                    ((__IO     uint16_t  *) REG_RNG0_CTL)                    /*  RNG Control Register */
#define pREG_RNG0_LEN                    ((__IO     uint16_t  *) REG_RNG0_LEN)                    /*  RNG Sample Length Register */
#define pREG_RNG0_STAT                   ((__IO     uint16_t  *) REG_RNG0_STAT)                   /*  RNG Status Register */
#define pREG_RNG0_DATA                   ((__I      uint32_t  *) REG_RNG0_DATA)                   /*  RNG Data Register */
#define pREG_RNG0_OSCCNT                 ((__I      uint32_t  *) REG_RNG0_OSCCNT)                 /*  Oscillator Count */
#define pREG_RNG0_OSCDIFF0               ((__I      int8_t    *) REG_RNG0_OSCDIFF0)               /*  Oscillator Difference */
#define pREG_RNG0_OSCDIFF1               ((__I      int8_t    *) REG_RNG0_OSCDIFF1)               /*  Oscillator Difference */
#define pREG_RNG0_OSCDIFF2               ((__I      int8_t    *) REG_RNG0_OSCDIFF2)               /*  Oscillator Difference */
#define pREG_RNG0_OSCDIFF3               ((__I      int8_t    *) REG_RNG0_OSCDIFF3)               /*  Oscillator Difference */

/*  =================================================================================
 *      Cryptogaphic (CRYPT0)
 *  ================================================================================= */
#define pREG_CRYPT0_CFG                  ((__IO     uint32_t  *) REG_CRYPT0_CFG)                  /*  Configuration Register */
#define pREG_CRYPT0_DATALEN              ((__IO     uint32_t  *) REG_CRYPT0_DATALEN)              /*  Payload Data Length */
#define pREG_CRYPT0_PREFIXLEN            ((__IO     uint32_t  *) REG_CRYPT0_PREFIXLEN)            /*  Authentication Data Length */
#define pREG_CRYPT0_INTEN                ((__IO     uint32_t  *) REG_CRYPT0_INTEN)                /*  Interrupt Enable Register */
#define pREG_CRYPT0_STAT                 ((__IO     uint32_t  *) REG_CRYPT0_STAT)                 /*  Status Register */
#define pREG_CRYPT0_INBUF                ((__O      int32_t   *) REG_CRYPT0_INBUF)                /*  Input Buffer */
#define pREG_CRYPT0_OUTBUF               ((__I      int32_t   *) REG_CRYPT0_OUTBUF)               /*  Output Buffer */
#define pREG_CRYPT0_NONCE0               ((__IO     uint32_t  *) REG_CRYPT0_NONCE0)               /*  Nonce Bits [31:0] */
#define pREG_CRYPT0_NONCE1               ((__IO     uint32_t  *) REG_CRYPT0_NONCE1)               /*  Nonce Bits [63:32] */
#define pREG_CRYPT0_NONCE2               ((__IO     uint32_t  *) REG_CRYPT0_NONCE2)               /*  Nonce Bits [95:64] */
#define pREG_CRYPT0_NONCE3               ((__IO     uint32_t  *) REG_CRYPT0_NONCE3)               /*  Nonce Bits [127:96] */
#define pREG_CRYPT0_AESKEY0              ((__O      uint32_t  *) REG_CRYPT0_AESKEY0)              /*  Key Bits[ 31:0 ] */
#define pREG_CRYPT0_AESKEY1              ((__O      uint32_t  *) REG_CRYPT0_AESKEY1)              /*  Key Bits [ 63:32 ] */
#define pREG_CRYPT0_AESKEY2              ((__O      uint32_t  *) REG_CRYPT0_AESKEY2)              /*  Key Bits [ 95:64 ] */
#define pREG_CRYPT0_AESKEY3              ((__O      uint32_t  *) REG_CRYPT0_AESKEY3)              /*  Key Bits [ 127:96 ] */
#define pREG_CRYPT0_AESKEY4              ((__O      uint32_t  *) REG_CRYPT0_AESKEY4)              /*  Key Bits [ 159:128 ] */
#define pREG_CRYPT0_AESKEY5              ((__O      uint32_t  *) REG_CRYPT0_AESKEY5)              /*  Key Bits [ 191:160 ] */
#define pREG_CRYPT0_AESKEY6              ((__O      uint32_t  *) REG_CRYPT0_AESKEY6)              /*  Key Bits [ 223:192 ] */
#define pREG_CRYPT0_AESKEY7              ((__O      uint32_t  *) REG_CRYPT0_AESKEY7)              /*  Key Bits [ 255:224 ] */
#define pREG_CRYPT0_CNTRINIT             ((__IO     uint32_t  *) REG_CRYPT0_CNTRINIT)             /*  Counter Initialization Vector */
#define pREG_CRYPT0_SHAH0                ((__IO     uint32_t  *) REG_CRYPT0_SHAH0)                /*  SHA Bits [ 31:0 ] */
#define pREG_CRYPT0_SHAH1                ((__IO     uint32_t  *) REG_CRYPT0_SHAH1)                /*  SHA Bits [ 63:32 ] */
#define pREG_CRYPT0_SHAH2                ((__IO     uint32_t  *) REG_CRYPT0_SHAH2)                /*  SHA Bits [ 95:64 ] */
#define pREG_CRYPT0_SHAH3                ((__IO     uint32_t  *) REG_CRYPT0_SHAH3)                /*  SHA Bits [ 127:96 ] */
#define pREG_CRYPT0_SHAH4                ((__IO     uint32_t  *) REG_CRYPT0_SHAH4)                /*  SHA Bits [ 159:128 ] */
#define pREG_CRYPT0_SHAH5                ((__IO     uint32_t  *) REG_CRYPT0_SHAH5)                /*  SHA Bits [ 191:160 ] */
#define pREG_CRYPT0_SHAH6                ((__IO     uint32_t  *) REG_CRYPT0_SHAH6)                /*  SHA Bits [ 223:192] */
#define pREG_CRYPT0_SHAH7                ((__IO     uint32_t  *) REG_CRYPT0_SHAH7)                /*  SHA Bits [ 255:224 ] */
#define pREG_CRYPT0_SHA_LAST_WORD        ((__IO     uint32_t  *) REG_CRYPT0_SHA_LAST_WORD)        /*  SHA Last Word and Valid Bits Information */
#define pREG_CRYPT0_CCM_NUM_VALID_BYTES  ((__IO     uint32_t  *) REG_CRYPT0_CCM_NUM_VALID_BYTES)  /*  NUM_VALID_BYTES */

/*  =================================================================================
 *      Power Management  (PMG0)
 *  ================================================================================= */
#define pREG_PMG0_IEN                    ((__IO     uint32_t  *) REG_PMG0_IEN)                    /*  Power Supply Monitor Interrupt Enable */
#define pREG_PMG0_PSM_STAT               ((__IO     uint32_t  *) REG_PMG0_PSM_STAT)               /*  Power supply monitor status */
#define pREG_PMG0_PWRMOD                 ((__IO     uint32_t  *) REG_PMG0_PWRMOD)                 /*  Power Mode Register */
#define pREG_PMG0_PWRKEY                 ((__O      uint32_t  *) REG_PMG0_PWRKEY)                 /*  Key protection for PWRMOD and  SRAMRET */
#define pREG_PMG0_SHDN_STAT              ((__I      uint32_t  *) REG_PMG0_SHDN_STAT)              /*  SHUTDOWN Status Register */
#define pREG_PMG0_SRAMRET                ((__IO     uint32_t  *) REG_PMG0_SRAMRET)                /*  Control for Retention SRAM during HIBERNATE Mode */
#define pREG_PMG0_RST_STAT               ((__IO     uint32_t  *) REG_PMG0_RST_STAT)               /*  Reset status */
#define pREG_PMG0_CTL1                   ((__IO     uint32_t  *) REG_PMG0_CTL1)                   /*  HPBUCK control */

/*  =================================================================================
 *      External interrupt configuration (XINT0)
 *  ================================================================================= */
#define pREG_XINT0_CFG0                  ((__IO     uint32_t  *) REG_XINT0_CFG0)                  /*  External Interrupt Configuration */
#define pREG_XINT0_EXT_STAT              ((__I      uint32_t  *) REG_XINT0_EXT_STAT)              /*  External Wakeup Interrupt Status */
#define pREG_XINT0_CLR                   ((__IO     uint32_t  *) REG_XINT0_CLR)                   /*  External Interrupt Clear */
#define pREG_XINT0_NMICLR                ((__IO     uint32_t  *) REG_XINT0_NMICLR)                /*  Non-Maskable Interrupt Clear */

/*  =================================================================================
 *      Clocking  (CLKG0_OSC)
 *  ================================================================================= */
#define pREG_CLKG0_OSC_KEY               ((__O      uint32_t  *) REG_CLKG0_OSC_KEY)               /*  Key Protection for OSCCTRL */
#define pREG_CLKG0_OSC_CTL               ((__IO     uint32_t  *) REG_CLKG0_OSC_CTL)               /*  Oscillator Control */

/*  =================================================================================
 *      Power Management  (PMG0_TST)
 *  ================================================================================= */
#define pREG_PMG0_TST_SRAM_CTL           ((__IO     uint32_t  *) REG_PMG0_TST_SRAM_CTL)           /*  Control for SRAM parity and instruction SRAM */
#define pREG_PMG0_TST_SRAM_INITSTAT      ((__IO     uint32_t  *) REG_PMG0_TST_SRAM_INITSTAT)      /*  Initialization Status Register */
#define pREG_PMG0_TST_CLR_LATCH_GPIOS    ((__O      uint16_t  *) REG_PMG0_TST_CLR_LATCH_GPIOS)    /*  CLEAR GPIO AFTER SHUTDOWN MODE */
#define pREG_PMG0_TST_SCRPAD_IMG         ((__IO     uint32_t  *) REG_PMG0_TST_SCRPAD_IMG)         /*  SCRATCH PAD IMAGE */
#define pREG_PMG0_TST_SCRPAD_3V_RD       ((__I      uint32_t  *) REG_PMG0_TST_SCRPAD_3V_RD)       /*  SCRATCH PAD SAVED IN BATTERY DOMAIN */

/*  =================================================================================
 *      Clocking  (CLKG0_CLK)
 *  ================================================================================= */
#define pREG_CLKG0_CLK_CTL0              ((__IO     uint32_t  *) REG_CLKG0_CLK_CTL0)              /*  Misc clock settings */
#define pREG_CLKG0_CLK_CTL1              ((__IO     uint32_t  *) REG_CLKG0_CLK_CTL1)              /*  Clock dividers */
#define pREG_CLKG0_CLK_CTL3              ((__IO     uint32_t  *) REG_CLKG0_CLK_CTL3)              /*  System PLL */
#define pREG_CLKG0_CLK_CTL5              ((__IO     uint32_t  *) REG_CLKG0_CLK_CTL5)              /*  User clock gating control */
#define pREG_CLKG0_CLK_STAT0             ((__IO     uint32_t  *) REG_CLKG0_CLK_STAT0)             /*  Clocking status */

/*  =================================================================================
 *      Bus matrix (BUSM0)
 *  ================================================================================= */
#define pREG_BUSM0_ARBIT0                ((__IO     uint32_t  *) REG_BUSM0_ARBIT0)                /*  Arbitration Priority Configuration for FLASH and SRAM0 */
#define pREG_BUSM0_ARBIT1                ((__IO     uint32_t  *) REG_BUSM0_ARBIT1)                /*  Arbitration Priority Configuration for SRAM1 and SIP */
#define pREG_BUSM0_ARBIT2                ((__IO     uint32_t  *) REG_BUSM0_ARBIT2)                /*  Arbitration Priority Configuration for APB32 and APB16 */
#define pREG_BUSM0_ARBIT3                ((__IO     uint32_t  *) REG_BUSM0_ARBIT3)                /*  Arbitration Priority Configuration for APB16 priority for core and for DMA1 */

/*  =================================================================================
 *       (AGPIO2)
 *  ================================================================================= */
#define pREG_AGPIO2_CON                  ((__IO     uint32_t  *) REG_AGPIO2_CON)                  /*  GPIO Port Configuration */
#define pREG_AGPIO2_OEN                  ((__IO     uint16_t  *) REG_AGPIO2_OEN)                  /*  GPIO Port Output Enable */
#define pREG_AGPIO2_PE                   ((__IO     uint16_t  *) REG_AGPIO2_PE)                   /*  GPIO Port Pullup/Pulldown Enable */
#define pREG_AGPIO2_IEN                  ((__IO     uint16_t  *) REG_AGPIO2_IEN)                  /*  GPIO Port Input Path Enable */
#define pREG_AGPIO2_IN                   ((__I      uint16_t  *) REG_AGPIO2_IN)                   /*  GPIO Port Registered Data Input */
#define pREG_AGPIO2_OUT                  ((__IO     uint16_t  *) REG_AGPIO2_OUT)                  /*  GPIO Port Data Output */
#define pREG_AGPIO2_SET                  ((__O      uint16_t  *) REG_AGPIO2_SET)                  /*  GPIO Port Data Out Set */
#define pREG_AGPIO2_CLR                  ((__O      uint16_t  *) REG_AGPIO2_CLR)                  /*  GPIO Port Data Out Clear */
#define pREG_AGPIO2_TGL                  ((__O      uint16_t  *) REG_AGPIO2_TGL)                  /*  GPIO Port Pin Toggle */

/*  =================================================================================
 *       (AFECON)
 *  ================================================================================= */
#define pREG_AFECON_ADIID                ((__I      uint16_t  *) REG_AFECON_ADIID)                /*  ADI Identification */
#define pREG_AFECON_CHIPID               ((__I      uint16_t  *) REG_AFECON_CHIPID)               /*  Chip Identification */
#define pREG_AFECON_CLKCON0              ((__IO     uint16_t  *) REG_AFECON_CLKCON0)              /*  Clock Divider Configuration */
#define pREG_AFECON_CLKEN1               ((__IO     uint16_t  *) REG_AFECON_CLKEN1)               /*  Clock Gate Enable */
#define pREG_AFECON_CLKSEL               ((__IO     uint16_t  *) REG_AFECON_CLKSEL)               /*  Clock Select */
#define pREG_AFECON_GPIOCLKMUXSEL        ((__IO     uint16_t  *) REG_AFECON_GPIOCLKMUXSEL)        /*  GPIO Clock MUX Select */
#define pREG_AFECON_CLKCON0KEY           ((__IO     uint16_t  *) REG_AFECON_CLKCON0KEY)           /*  Enable Clock Division to 8Mhz,4Mhz and 2Mhz */
#define pREG_AFECON_MKEY                 ((__O      uint16_t  *) REG_AFECON_MKEY)                 /*  MKEY */
#define pREG_AFECON_DSPUPDATEEN          ((__IO     uint16_t  *) REG_AFECON_DSPUPDATEEN)          /*  DSP Update Enable */

/*  =================================================================================
 *       (AFEWDT)
 *  ================================================================================= */
#define pREG_AFEWDT_WDTLD                ((__IO     int16_t   *) REG_AFEWDT_WDTLD)                /*  Watchdog Timer Load Value */
#define pREG_AFEWDT_WDTVALS              ((__I      int16_t   *) REG_AFEWDT_WDTVALS)              /*  Current Count Value */
#define pREG_AFEWDT_WDTCON               ((__IO     uint16_t  *) REG_AFEWDT_WDTCON)               /*  Watchdog Timer Control Register */
#define pREG_AFEWDT_WDTCLRI              ((__O      int16_t   *) REG_AFEWDT_WDTCLRI)              /*  Refresh Watchdog Register */
#define pREG_AFEWDT_WDTSTA               ((__IO     uint16_t  *) REG_AFEWDT_WDTSTA)               /*  Timer Status */
#define pREG_AFEWDT_WDTMINLD             ((__IO     int16_t   *) REG_AFEWDT_WDTMINLD)             /*  Minimum Load Value */

/*  =================================================================================
 *      Always On Register (ALLON)
 *  ================================================================================= */
#define pREG_ALLON_PWRMOD                ((__IO     uint16_t  *) REG_ALLON_PWRMOD)                /*  Power Modes */
#define pREG_ALLON_PWRKEY                ((__IO     int16_t   *) REG_ALLON_PWRKEY)                /*  Key Protection for PWRMOD */
#define pREG_ALLON_OSCKEY                ((__IO     int16_t   *) REG_ALLON_OSCKEY)                /*  Key Protection for OSCCON */
#define pREG_ALLON_OSCCON                ((__IO     uint16_t  *) REG_ALLON_OSCCON)                /*  Oscillator Control */
#define pREG_ALLON_EI2CON                ((__IO     uint16_t  *) REG_ALLON_EI2CON)                /*  External Interrupt Configuration 2 */
#define pREG_ALLON_EICLR                 ((__IO     uint16_t  *) REG_ALLON_EICLR)                 /*  External Interrupt Clear */
#define pREG_ALLON_RSTSTA                ((__IO     uint16_t  *) REG_ALLON_RSTSTA)                /*  Reset Status */
#define pREG_ALLON_PMUSTA                ((__I      uint16_t  *) REG_ALLON_PMUSTA)                /*  PMU Status */
#define pREG_ALLON_CLKEN0                ((__IO     uint16_t  *) REG_ALLON_CLKEN0)                /*  32KHz Peripheral Clock Enable */

/*  =================================================================================
 *      General Purpose Timer (AGPT0)
 *  ================================================================================= */
#define pREG_AGPT0_LD0                   ((__IO     int16_t   *) REG_AGPT0_LD0)                   /*  16-bit Load Value Register. */
#define pREG_AGPT0_VAL0                  ((__I      int16_t   *) REG_AGPT0_VAL0)                  /*  16-Bit Timer Value Register. */
#define pREG_AGPT0_CON0                  ((__IO     uint16_t  *) REG_AGPT0_CON0)                  /*  Control Register. */
#define pREG_AGPT0_CLRI0                 ((__O      uint16_t  *) REG_AGPT0_CLRI0)                 /*  Clear Interrupt Register. */
#define pREG_AGPT0_CAP0                  ((__I      int16_t   *) REG_AGPT0_CAP0)                  /*  Capture Register. */
#define pREG_AGPT0_ALD0                  ((__IO     int16_t   *) REG_AGPT0_ALD0)                  /*  16-Bit Load Value, Asynchronous. */
#define pREG_AGPT0_AVAL0                 ((__I      int16_t   *) REG_AGPT0_AVAL0)                 /*  16-Bit Timer Value, Asynchronous Register. */
#define pREG_AGPT0_STA0                  ((__I      uint16_t  *) REG_AGPT0_STA0)                  /*  Status Register. */
#define pREG_AGPT0_PWMCON0               ((__IO     uint16_t  *) REG_AGPT0_PWMCON0)               /*  PWM Control Register. */
#define pREG_AGPT0_PWMMAT0               ((__IO     int16_t   *) REG_AGPT0_PWMMAT0)               /*  PWM Match Value Register. */
#define pREG_AGPT0_INTEN                 ((__IO     uint16_t  *) REG_AGPT0_INTEN)                 /*  Interrupt Enable */

/*  =================================================================================
 *      General Purpose Timer (AGPT1)
 *  ================================================================================= */
#define pREG_AGPT1_LD1                   ((__IO     int16_t   *) REG_AGPT1_LD1)                   /*  16-bit Load Value Register */
#define pREG_AGPT1_VAL1                  ((__I      int16_t   *) REG_AGPT1_VAL1)                  /*  16-bit Timer Value Register */
#define pREG_AGPT1_CON1                  ((__IO     uint16_t  *) REG_AGPT1_CON1)                  /*  Control Register */
#define pREG_AGPT1_CLRI1                 ((__O      uint16_t  *) REG_AGPT1_CLRI1)                 /*  Clear Interrupt Register */
#define pREG_AGPT1_CAP1                  ((__I      int16_t   *) REG_AGPT1_CAP1)                  /*  Capture Register */
#define pREG_AGPT1_ALD1                  ((__IO     int16_t   *) REG_AGPT1_ALD1)                  /*  16-bit Load Value, Asynchronous Register */
#define pREG_AGPT1_AVAL1                 ((__I      int16_t   *) REG_AGPT1_AVAL1)                 /*  16-bit Timer Value, Asynchronous Register */
#define pREG_AGPT1_STA1                  ((__I      uint16_t  *) REG_AGPT1_STA1)                  /*  Status Register */
#define pREG_AGPT1_PWMCON1               ((__IO     uint16_t  *) REG_AGPT1_PWMCON1)               /*  PWM Control Register */
#define pREG_AGPT1_PWMMAT1               ((__IO     int16_t   *) REG_AGPT1_PWMMAT1)               /*  PWM Match Value Register */
#define pREG_AGPT1_INTEN1                ((__IO     uint16_t  *) REG_AGPT1_INTEN1)                /*  Interrupt Enable */

/*  =================================================================================
 *      CRC Accelerator (AFECRC)
 *  ================================================================================= */
#define pREG_AFECRC_CTL                  ((__IO     uint32_t  *) REG_AFECRC_CTL)                  /*  CRC Control Register */
#define pREG_AFECRC_IPDATA               ((__O      int32_t   *) REG_AFECRC_IPDATA)               /*  Data Input. */
#define pREG_AFECRC_RESULT               ((__IO     int32_t   *) REG_AFECRC_RESULT)               /*  CRC Residue */
#define pREG_AFECRC_POLY                 ((__IO     uint32_t  *) REG_AFECRC_POLY)                 /*  CRC Reduction Polynomial */
#define pREG_AFECRC_IPBITS               ((__O      uint8_t   *) REG_AFECRC_IPBITS)               /*  Input Data Bits */
#define pREG_AFECRC_IPBYTE               ((__O      uint8_t   *) REG_AFECRC_IPBYTE)               /*  Input Data Byte */
#define pREG_AFECRC_CRC_SIG_COMP         ((__IO     uint32_t  *) REG_AFECRC_CRC_SIG_COMP)         /*  CRC Signature Compare Data Input. */
#define pREG_AFECRC_CRCINTEN             ((__IO     uint32_t  *) REG_AFECRC_CRCINTEN)             /*  CRC Error Interrupt Enable Bit */
#define pREG_AFECRC_INTSTA               ((__IO     uint32_t  *) REG_AFECRC_INTSTA)               /*  CRC Error Interrupt Status Bit */

/*  =================================================================================
 *       (AFE)
 *  ================================================================================= */
#define pREG_AFE_AFECON                  ((__IO     uint32_t  *) REG_AFE_AFECON)                  /*  AFE Configuration */
#define pREG_AFE_SWCON                   ((__IO     uint32_t  *) REG_AFE_SWCON)                   /*  Switch Matrix Configuration */
#define pREG_AFE_HSDACCON                ((__IO     uint32_t  *) REG_AFE_HSDACCON)                /*  High Speed DAC Configuration */
#define pREG_AFE_WGCON                   ((__IO     uint32_t  *) REG_AFE_WGCON)                   /*  Waveform Generator Configuration */
#define pREG_AFE_WGFCW                   ((__IO     uint32_t  *) REG_AFE_WGFCW)                   /*  Waveform Generator - Sinusoid Frequency Control Word */
#define pREG_AFE_WGPHASE                 ((__IO     uint32_t  *) REG_AFE_WGPHASE)                 /*  Waveform Generator - Sinusoid Phase Offset */
#define pREG_AFE_WGOFFSET                ((__IO     uint32_t  *) REG_AFE_WGOFFSET)                /*  Waveform Generator - Sinusoid Offset */
#define pREG_AFE_WGAMPLITUDE             ((__IO     uint32_t  *) REG_AFE_WGAMPLITUDE)             /*  Waveform Generator - Sinusoid Amplitude */
#define pREG_AFE_ADCFILTERCON            ((__IO     uint32_t  *) REG_AFE_ADCFILTERCON)            /*  ADC Output Filters Configuration */
#define pREG_AFE_HSDACDAT                ((__IO     uint32_t  *) REG_AFE_HSDACDAT)                /*  HS DAC Code */
#define pREG_AFE_LPREFBUFCON             ((__IO     uint32_t  *) REG_AFE_LPREFBUFCON)             /*  LPREF_BUF_CON */
#define pREG_AFE_ADCDAT                  ((__IO     uint32_t  *) REG_AFE_ADCDAT)                  /*  ADC Raw Result */
#define pREG_AFE_DFTREAL                 ((__IO     uint32_t  *) REG_AFE_DFTREAL)                 /*  DFT Result, Real Part */
#define pREG_AFE_DFTIMAG                 ((__IO     uint32_t  *) REG_AFE_DFTIMAG)                 /*  DFT Result, Imaginary Part */
#define pREG_AFE_SINC2DAT                ((__IO     uint32_t  *) REG_AFE_SINC2DAT)                /*  Supply Rejection Filter Result */
#define pREG_AFE_TEMPSENSDAT             ((__IO     uint32_t  *) REG_AFE_TEMPSENSDAT)             /*  Temperature Sensor Result */
#define pREG_AFE_ADCINTIEN               ((__IO     uint32_t  *) REG_AFE_ADCINTIEN)               /*  ADC Interrupt Enable Register */
#define pREG_AFE_ADCINTSTA               ((__IO     uint32_t  *) REG_AFE_ADCINTSTA)               /*  ADC Interrupt Status */
#define pREG_AFE_AFEGENINTSTA            ((__IO     uint32_t  *) REG_AFE_AFEGENINTSTA)            /*  Analog Generation Interrupt */
#define pREG_AFE_ADCMIN                  ((__IO     uint32_t  *) REG_AFE_ADCMIN)                  /*  ADC Minimum Value Check */
#define pREG_AFE_ADCMINSM                ((__IO     uint32_t  *) REG_AFE_ADCMINSM)                /*  ADCMIN Hysteresis Value */
#define pREG_AFE_ADCMAX                  ((__IO     uint32_t  *) REG_AFE_ADCMAX)                  /*  ADC Maximum Value Check */
#define pREG_AFE_ADCMAXSMEN              ((__IO     uint32_t  *) REG_AFE_ADCMAXSMEN)              /*  ADCMAX Hysteresis Value */
#define pREG_AFE_ADCDELTA                ((__IO     uint32_t  *) REG_AFE_ADCDELTA)                /*  ADC Delta Value */
#define pREG_AFE_HPOSCCON                ((__IO     uint32_t  *) REG_AFE_HPOSCCON)                /*  HPOSC Configuration */
#define pREG_AFE_DFTCON                  ((__IO     uint32_t  *) REG_AFE_DFTCON)                  /*  AFE DSP Configuration */
#define pREG_AFE_LPTIASW1                ((__IO     uint32_t  *) REG_AFE_LPTIASW1)                /*  ULPTIA Switch Configuration for Channel 1 */
#define pREG_AFE_LPTIASW0                ((__IO     uint32_t  *) REG_AFE_LPTIASW0)                /*  ULPTIA Switch Configuration for Channel 0 */
#define pREG_AFE_LPTIACON1               ((__IO     uint32_t  *) REG_AFE_LPTIACON1)               /*  ULPTIA Control Bits Channel 1 */
#define pREG_AFE_LPTIACON0               ((__IO     uint32_t  *) REG_AFE_LPTIACON0)               /*  ULPTIA Control Bits Channel 0 */
#define pREG_AFE_HSRTIACON               ((__IO     uint32_t  *) REG_AFE_HSRTIACON)               /*  High Power RTIA Configuration */
#define pREG_AFE_DE1RESCON               ((__IO     uint32_t  *) REG_AFE_DE1RESCON)               /*  DE1 HSTIA Resistors Configuration */
#define pREG_AFE_DE0RESCON               ((__IO     uint32_t  *) REG_AFE_DE0RESCON)               /*  DE0 HSTIA Resistors Configuration */
#define pREG_AFE_HSTIACON                ((__IO     uint32_t  *) REG_AFE_HSTIACON)                /*  HSTIA Amplifier Configuration */
#define pREG_AFE_DACDCBUFCON             ((__IO     uint32_t  *) REG_AFE_DACDCBUFCON)             /*  DAC DC Buffer Configuration */
#define pREG_AFE_LPDACDAT0               ((__IO     uint32_t  *) REG_AFE_LPDACDAT0)               /*  LPDAC Data-out */
#define pREG_AFE_LPDACSW0                ((__IO     uint32_t  *) REG_AFE_LPDACSW0)                /*  LPDAC0 Switch Control */
#define pREG_AFE_LPDACCON0               ((__IO     uint32_t  *) REG_AFE_LPDACCON0)               /*  LPDAC Control Bits */
#define pREG_AFE_LPDACDAT1               ((__IO     uint32_t  *) REG_AFE_LPDACDAT1)               /*  Low Power DAC1 data register */
#define pREG_AFE_LPDACSW1                ((__IO     uint32_t  *) REG_AFE_LPDACSW1)                /*  Control register for switches to LPDAC1 */
#define pREG_AFE_LPDACCON1               ((__IO     uint32_t  *) REG_AFE_LPDACCON1)               /*  ULP_DACCON1 */
#define pREG_AFE_DSWFULLCON              ((__IO     uint32_t  *) REG_AFE_DSWFULLCON)              /*  Switch Matrix Full Configuration (D) */
#define pREG_AFE_NSWFULLCON              ((__IO     uint32_t  *) REG_AFE_NSWFULLCON)              /*  Switch Matrix Full Configuration (N) */
#define pREG_AFE_PSWFULLCON              ((__IO     uint32_t  *) REG_AFE_PSWFULLCON)              /*  Switch Matrix Full Configuration (P) */
#define pREG_AFE_TSWFULLCON              ((__IO     uint32_t  *) REG_AFE_TSWFULLCON)              /*  Switch Matrix Full Configuration (T) */
#define pREG_AFE_TEMPCON0                ((__IO     uint32_t  *) REG_AFE_TEMPCON0)                /*  Temp Sensor Configuration */
#define pREG_AFE_BUFSENCON               ((__IO     uint32_t  *) REG_AFE_BUFSENCON)               /*  HP and LP Buffer Control */
#define pREG_AFE_ADCCON                  ((__IO     uint32_t  *) REG_AFE_ADCCON)                  /*  ADC Configuration */
#define pREG_AFE_DSWSTA                  ((__I      uint32_t  *) REG_AFE_DSWSTA)                  /*  Switch Matrix Status (D) */
#define pREG_AFE_PSWSTA                  ((__I      uint32_t  *) REG_AFE_PSWSTA)                  /*  Switch Matrix Status (P) */
#define pREG_AFE_NSWSTA                  ((__I      uint32_t  *) REG_AFE_NSWSTA)                  /*  Switch Matrix Status (N) */
#define pREG_AFE_TSWSTA                  ((__I      uint32_t  *) REG_AFE_TSWSTA)                  /*  Switch Matrix Status (T) */
#define pREG_AFE_STATSVAR                ((__I      uint32_t  *) REG_AFE_STATSVAR)                /*  Variance Output */
#define pREG_AFE_STATSCON                ((__IO     uint32_t  *) REG_AFE_STATSCON)                /*  Statistics Control */
#define pREG_AFE_STATSMEAN               ((__I      uint32_t  *) REG_AFE_STATSMEAN)               /*  Statistics Mean Output */
#define pREG_AFE_REPEATADCCNV            ((__IO     uint32_t  *) REG_AFE_REPEATADCCNV)            /*  REPEAT ADC Conversions */
#define pREG_AFE_CALDATLOCK              ((__IO     uint32_t  *) REG_AFE_CALDATLOCK)              /*  Calibration Data Lock */
#define pREG_AFE_ADCOFFSETHSTIA          ((__IO     uint32_t  *) REG_AFE_ADCOFFSETHSTIA)          /*  ADC Offset Calibration High Speed TIA Channel */
#define pREG_AFE_ADCGAINTEMPSENS0        ((__IO     uint32_t  *) REG_AFE_ADCGAINTEMPSENS0)        /*  ADC Gain Calibration Temp Sensor Channel */
#define pREG_AFE_ADCOFFSETTEMPSENS0      ((__IO     uint32_t  *) REG_AFE_ADCOFFSETTEMPSENS0)      /*  ADC Offset Calibration Temp Sensor Channel 0 */
#define pREG_AFE_ADCGAINGN1              ((__IO     uint32_t  *) REG_AFE_ADCGAINGN1)              /*  ADCPGAGN1: ADC Gain Calibration Auxiliary Input Channel */
#define pREG_AFE_ADCOFFSETGN1            ((__IO     uint32_t  *) REG_AFE_ADCOFFSETGN1)            /*  ADC Offset Calibration Auxiliary Channel (PGA Gain=1) */
#define pREG_AFE_DACGAIN                 ((__IO     uint32_t  *) REG_AFE_DACGAIN)                 /*  DACGAIN */
#define pREG_AFE_DACOFFSETATTEN          ((__IO     uint32_t  *) REG_AFE_DACOFFSETATTEN)          /*  DAC Offset with Attenuator Enabled (LP Mode) */
#define pREG_AFE_DACOFFSET               ((__IO     uint32_t  *) REG_AFE_DACOFFSET)               /*  DAC Offset with Attenuator Disabled (LP Mode) */
#define pREG_AFE_ADCGAINGN1P5            ((__IO     uint32_t  *) REG_AFE_ADCGAINGN1P5)            /*  ADC Gain Calibration Auxiliary Input Channel (PGA Gain=1.5) */
#define pREG_AFE_ADCGAINGN2              ((__IO     uint32_t  *) REG_AFE_ADCGAINGN2)              /*  ADC Gain Calibration Auxiliary Input Channel (PGA Gain=2) */
#define pREG_AFE_ADCGAINGN4              ((__IO     uint32_t  *) REG_AFE_ADCGAINGN4)              /*  ADC Gain Calibration Auxiliary Input Channel (PGA Gain=4) */
#define pREG_AFE_ADCPGAOFFSETCANCEL      ((__IO     uint32_t  *) REG_AFE_ADCPGAOFFSETCANCEL)      /*  ADC Offset Cancellation (Optional) */
#define pREG_AFE_ADCGNHSTIA              ((__IO     uint32_t  *) REG_AFE_ADCGNHSTIA)              /*  ADC Gain Calibration for HS TIA Channel */
#define pREG_AFE_ADCOFFSETLPTIA0         ((__IO     uint32_t  *) REG_AFE_ADCOFFSETLPTIA0)         /*  ADC Offset Calibration ULP-TIA0 Channel */
#define pREG_AFE_ADCGNLPTIA0             ((__IO     uint32_t  *) REG_AFE_ADCGNLPTIA0)             /*  ADC GAIN Calibration for LP TIA0 Channel */
#define pREG_AFE_ADCPGAGN4OFCAL          ((__IO     uint32_t  *) REG_AFE_ADCPGAGN4OFCAL)          /*  ADC Gain Calibration with DC Cancellation(PGA G=4) */
#define pREG_AFE_ADCGAINGN9              ((__IO     uint32_t  *) REG_AFE_ADCGAINGN9)              /*  ADC Gain Calibration Auxiliary Input Channel (PGA Gain=9) */
#define pREG_AFE_ADCOFFSETEMPSENS1       ((__IO     uint32_t  *) REG_AFE_ADCOFFSETEMPSENS1)       /*  ADC Offset Calibration  Temp Sensor Channel 1 */
#define pREG_AFE_ADCGAINTEMPSENS1        ((__IO     uint32_t  *) REG_AFE_ADCGAINTEMPSENS1)        /*  ADC Gain Calibration Temperature Sensor Channel */
#define pREG_AFE_DACOFFSETATTENHP        ((__IO     uint32_t  *) REG_AFE_DACOFFSETATTENHP)        /*  DAC Offset with Attenuator Enabled (HP Mode) */
#define pREG_AFE_DACOFFSETHP             ((__IO     uint32_t  *) REG_AFE_DACOFFSETHP)             /*  DAC Offset with Attenuator Disabled (HP Mode) */
#define pREG_AFE_ADCOFFSETLPTIA1         ((__IO     uint32_t  *) REG_AFE_ADCOFFSETLPTIA1)         /*  ADC Offset Calibration LP TIA1 Channel */
#define pREG_AFE_ADCGNLPTIA1             ((__IO     uint32_t  *) REG_AFE_ADCGNLPTIA1)             /*  ADC GAIN Calibration for LP TIA1 Channel */
#define pREG_AFE_ADCOFFSETGN2            ((__IO     uint32_t  *) REG_AFE_ADCOFFSETGN2)            /*  Offset Calibration Auxiliary Channel (PGA Gain =2) */
#define pREG_AFE_ADCOFFSETGN1P5          ((__IO     uint32_t  *) REG_AFE_ADCOFFSETGN1P5)          /*  Offset Calibration Auxiliary Channel (PGA Gain =1.5) */
#define pREG_AFE_ADCOFFSETGN9            ((__IO     uint32_t  *) REG_AFE_ADCOFFSETGN9)            /*  Offset Calibration Auxiliary Channel (PGA Gain =9) */
#define pREG_AFE_ADCOFFSETGN4            ((__IO     uint32_t  *) REG_AFE_ADCOFFSETGN4)            /*  Offset Calibration Auxiliary Channel (PGA Gain =4) */
#define pREG_AFE_PMBW                    ((__IO     uint32_t  *) REG_AFE_PMBW)                    /*  Power Mode Configuration */
#define pREG_AFE_SWMUX                   ((__IO     uint32_t  *) REG_AFE_SWMUX)                   /*  Switch Mux for ECG */
#define pREG_AFE_TEMPCON1                ((__IO     uint32_t  *) REG_AFE_TEMPCON1)                /*  AFE_TEMPSEN_DIO */
#define pREG_AFE_TESTDAC                 ((__IO     uint32_t  *) REG_AFE_TESTDAC)                 /*  DAC Test */
#define pREG_AFE_ADCBUFCON               ((__IO     uint32_t  *) REG_AFE_ADCBUFCON)               /*  Configure ADC Input Buffer */

/*  =================================================================================
 *      Cortex-M3 Interrupt Controller (NVIC0)
 *  ================================================================================= */
#define pREG_NVIC0_INTNUM                ((__IO     uint32_t  *) REG_NVIC0_INTNUM)                /*  Interrupt Control Type */
#define pREG_NVIC0_STKSTA                ((__IO     uint32_t  *) REG_NVIC0_STKSTA)                /*  Systick Control and Status */
#define pREG_NVIC0_STKLD                 ((__IO     uint32_t  *) REG_NVIC0_STKLD)                 /*  Systick Reload Value */
#define pREG_NVIC0_STKVAL                ((__IO     uint32_t  *) REG_NVIC0_STKVAL)                /*  Systick Current Value */
#define pREG_NVIC0_STKCAL                ((__IO     uint32_t  *) REG_NVIC0_STKCAL)                /*  Systick Calibration Value */
#define pREG_NVIC0_INTSETE0              ((__IO     uint32_t  *) REG_NVIC0_INTSETE0)              /*  IRQ0..31 Set_Enable */
#define pREG_NVIC0_INTSETE1              ((__IO     uint32_t  *) REG_NVIC0_INTSETE1)              /*  IRQ32..63 Set_Enable */
#define pREG_NVIC0_INTCLRE0              ((__IO     uint32_t  *) REG_NVIC0_INTCLRE0)              /*  IRQ0..31 Clear_Enable */
#define pREG_NVIC0_INTCLRE1              ((__IO     uint32_t  *) REG_NVIC0_INTCLRE1)              /*  IRQ32..63 Clear_Enable */
#define pREG_NVIC0_INTSETP0              ((__IO     uint32_t  *) REG_NVIC0_INTSETP0)              /*  IRQ0..31 Set_Pending */
#define pREG_NVIC0_INTSETP1              ((__IO     uint32_t  *) REG_NVIC0_INTSETP1)              /*  IRQ32..63 Set_Pending */
#define pREG_NVIC0_INTCLRP0              ((__IO     uint32_t  *) REG_NVIC0_INTCLRP0)              /*  IRQ0..31 Clear_Pending */
#define pREG_NVIC0_INTCLRP1              ((__IO     uint32_t  *) REG_NVIC0_INTCLRP1)              /*  IRQ32..63 Clear_Pending */
#define pREG_NVIC0_INTACT0               ((__IO     uint32_t  *) REG_NVIC0_INTACT0)               /*  IRQ0..31 Active Bit */
#define pREG_NVIC0_INTACT1               ((__IO     uint32_t  *) REG_NVIC0_INTACT1)               /*  IRQ32..63 Active Bit */
#define pREG_NVIC0_INTPRI0               ((__IO     uint32_t  *) REG_NVIC0_INTPRI0)               /*  IRQ0..3 Priority */
#define pREG_NVIC0_INTPRI1               ((__IO     uint32_t  *) REG_NVIC0_INTPRI1)               /*  IRQ4..7 Priority */
#define pREG_NVIC0_INTPRI2               ((__IO     uint32_t  *) REG_NVIC0_INTPRI2)               /*  IRQ8..11 Priority */
#define pREG_NVIC0_INTPRI3               ((__IO     uint32_t  *) REG_NVIC0_INTPRI3)               /*  IRQ12..15 Priority */
#define pREG_NVIC0_INTPRI4               ((__IO     uint32_t  *) REG_NVIC0_INTPRI4)               /*  IRQ16..19 Priority */
#define pREG_NVIC0_INTPRI5               ((__IO     uint32_t  *) REG_NVIC0_INTPRI5)               /*  IRQ20..23 Priority */
#define pREG_NVIC0_INTPRI6               ((__IO     uint32_t  *) REG_NVIC0_INTPRI6)               /*  IRQ24..27 Priority */
#define pREG_NVIC0_INTPRI7               ((__IO     uint32_t  *) REG_NVIC0_INTPRI7)               /*  IRQ28..31 Priority */
#define pREG_NVIC0_INTPRI8               ((__IO     uint32_t  *) REG_NVIC0_INTPRI8)               /*  IRQ32..35 Priority */
#define pREG_NVIC0_INTPRI9               ((__IO     uint32_t  *) REG_NVIC0_INTPRI9)               /*  IRQ36..39 Priority */
#define pREG_NVIC0_INTPRI10              ((__IO     uint32_t  *) REG_NVIC0_INTPRI10)              /*  IRQ40..43 Priority */
#define pREG_NVIC0_INTCPID               ((__IO     uint32_t  *) REG_NVIC0_INTCPID)               /*  CPUID Base */
#define pREG_NVIC0_INTSTA                ((__IO     uint32_t  *) REG_NVIC0_INTSTA)                /*  Interrupt Control State */
#define pREG_NVIC0_INTVEC                ((__IO     uint32_t  *) REG_NVIC0_INTVEC)                /*  Vector Table Offset */
#define pREG_NVIC0_INTAIRC               ((__IO     uint32_t  *) REG_NVIC0_INTAIRC)               /*  Application Interrupt/Reset Control */
#define pREG_NVIC0_INTCON0               ((__IO     uint16_t  *) REG_NVIC0_INTCON0)               /*  System Control */
#define pREG_NVIC0_INTCON1               ((__IO     uint32_t  *) REG_NVIC0_INTCON1)               /*  Configuration Control */
#define pREG_NVIC0_INTSHPRIO0            ((__IO     uint32_t  *) REG_NVIC0_INTSHPRIO0)            /*  System Handlers 4-7 Priority */
#define pREG_NVIC0_INTSHPRIO1            ((__IO     uint32_t  *) REG_NVIC0_INTSHPRIO1)            /*  System Handlers 8-11 Priority */
#define pREG_NVIC0_INTSHPRIO3            ((__IO     uint32_t  *) REG_NVIC0_INTSHPRIO3)            /*  System Handlers 12-15 Priority */
#define pREG_NVIC0_INTSHCSR              ((__IO     uint32_t  *) REG_NVIC0_INTSHCSR)              /*  System Handler Control and State */
#define pREG_NVIC0_INTCFSR               ((__IO     uint32_t  *) REG_NVIC0_INTCFSR)               /*  Configurable Fault Status */
#define pREG_NVIC0_INTHFSR               ((__IO     uint32_t  *) REG_NVIC0_INTHFSR)               /*  Hard Fault Status */
#define pREG_NVIC0_INTDFSR               ((__IO     uint32_t  *) REG_NVIC0_INTDFSR)               /*  Debug Fault Status */
#define pREG_NVIC0_INTMMAR               ((__IO     uint32_t  *) REG_NVIC0_INTMMAR)               /*  Mem Manage Address */
#define pREG_NVIC0_INTBFAR               ((__IO     uint32_t  *) REG_NVIC0_INTBFAR)               /*  Bus Fault Address */
#define pREG_NVIC0_INTAFSR               ((__IO     uint32_t  *) REG_NVIC0_INTAFSR)               /*  Auxiliary Fault Status */
#define pREG_NVIC0_INTPFR0               ((__IO     uint32_t  *) REG_NVIC0_INTPFR0)               /*  Processor Feature Register 0 */
#define pREG_NVIC0_INTPFR1               ((__IO     uint32_t  *) REG_NVIC0_INTPFR1)               /*  Processor Feature Register 1 */
#define pREG_NVIC0_INTDFR0               ((__IO     uint32_t  *) REG_NVIC0_INTDFR0)               /*  Debug Feature Register 0 */
#define pREG_NVIC0_INTAFR0               ((__IO     uint32_t  *) REG_NVIC0_INTAFR0)               /*  Auxiliary Feature Register 0 */
#define pREG_NVIC0_INTMMFR0              ((__IO     uint32_t  *) REG_NVIC0_INTMMFR0)              /*  Memory Model Feature Register 0 */
#define pREG_NVIC0_INTMMFR1              ((__IO     uint32_t  *) REG_NVIC0_INTMMFR1)              /*  Memory Model Feature Register 1 */
#define pREG_NVIC0_INTMMFR2              ((__IO     uint32_t  *) REG_NVIC0_INTMMFR2)              /*  Memory Model Feature Register 2 */
#define pREG_NVIC0_INTMMFR3              ((__IO     uint32_t  *) REG_NVIC0_INTMMFR3)              /*  Memory Model Feature Register 3 */
#define pREG_NVIC0_INTISAR0              ((__IO     uint32_t  *) REG_NVIC0_INTISAR0)              /*  ISA Feature Register 0 */
#define pREG_NVIC0_INTISAR1              ((__IO     uint32_t  *) REG_NVIC0_INTISAR1)              /*  ISA Feature Register 1 */
#define pREG_NVIC0_INTISAR2              ((__IO     uint32_t  *) REG_NVIC0_INTISAR2)              /*  ISA Feature Register 2 */
#define pREG_NVIC0_INTISAR3              ((__IO     uint32_t  *) REG_NVIC0_INTISAR3)              /*  ISA Feature Register 3 */
#define pREG_NVIC0_INTISAR4              ((__IO     uint32_t  *) REG_NVIC0_INTISAR4)              /*  ISA Feature Register 4 */
#define pREG_NVIC0_INTTRGI               ((__IO     uint32_t  *) REG_NVIC0_INTTRGI)               /*  Software Trigger Interrupt Register */
#define pREG_NVIC0_INTPID4               ((__IO     uint32_t  *) REG_NVIC0_INTPID4)               /*  Peripheral Identification Register 4 */
#define pREG_NVIC0_INTPID5               ((__IO     uint32_t  *) REG_NVIC0_INTPID5)               /*  Peripheral Identification Register 5 */
#define pREG_NVIC0_INTPID6               ((__IO     uint32_t  *) REG_NVIC0_INTPID6)               /*  Peripheral Identification Register 6 */
#define pREG_NVIC0_INTPID7               ((__IO     uint32_t  *) REG_NVIC0_INTPID7)               /*  Peripheral Identification Register 7 */
#define pREG_NVIC0_INTPID0               ((__IO     uint32_t  *) REG_NVIC0_INTPID0)               /*  Peripheral Identification Bits7:0 */
#define pREG_NVIC0_INTPID1               ((__IO     uint32_t  *) REG_NVIC0_INTPID1)               /*  Peripheral Identification Bits15:8 */
#define pREG_NVIC0_INTPID2               ((__IO     uint32_t  *) REG_NVIC0_INTPID2)               /*  Peripheral Identification Bits16:23 */
#define pREG_NVIC0_INTPID3               ((__IO     uint32_t  *) REG_NVIC0_INTPID3)               /*  Peripheral Identification Bits24:31 */
#define pREG_NVIC0_INTCID0               ((__IO     uint32_t  *) REG_NVIC0_INTCID0)               /*  Component Identification Bits7:0 */
#define pREG_NVIC0_INTCID1               ((__IO     uint32_t  *) REG_NVIC0_INTCID1)               /*  Component Identification Bits15:8 */
#define pREG_NVIC0_INTCID2               ((__IO     uint32_t  *) REG_NVIC0_INTCID2)               /*  Component Identification Bits16:23 */
#define pREG_NVIC0_INTCID3               ((__IO     uint32_t  *) REG_NVIC0_INTCID3)               /*  Component Identification Bits24:31 */

#if defined (_MISRA_RULES)
#pragma diag(pop)
#endif /* _MISRA_RULES */


#endif

