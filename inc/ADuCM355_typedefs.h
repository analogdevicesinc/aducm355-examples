/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#ifndef _ADUCM355_TYPEDEFS_H
#define _ADUCM355_TYPEDEFS_H

/* pickup integer types */
#if defined(_LANGUAGE_C) || (defined(__GNUC__) && !defined(__ASSEMBLER__))
#include <stdint.h>
#endif /* _LANGUAGE_C */

#if defined ( __CC_ARM   )
#pragma push
#pragma anon_unions
#endif


#if defined (_MISRA_RULES)
/*
  anonymous unions violate ISO 9899:1990 and therefore MISRA Rule 1.1.
  Use of unions violates MISRA Rule 18.4.
  Anonymous unions are required for this implementation.
  Re-use of identifiers violates MISRA Rule 5.7.
  Field names are repeated for the ADuCM355 register map.
*/
#pragma diag(push)
#pragma diag(suppress:misra_rule_1_1:"Allow anonymous unions")
#pragma diag(suppress:misra_rule_5_1:"Allow names over 32 character limit")
#pragma diag(suppress:misra_rule_5_3:"Header will re-use typedef identifiers")
#pragma diag(suppress:misra_rule_5_6:"Header will re-use identifiers in the same scope")
#pragma diag(suppress:misra_rule_5_7:"Header will re-use identifiers")
#pragma diag(suppress:misra_rule_18_4:"Allow the use of a union")
#endif /* _MISRA_RULES */

/** @defgroup LOAD 16-bit load value (LOAD) Register
 *  16-bit load value (LOAD) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_LOAD_Struct
 *! \brief  16-bit load value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_LOAD_t__
typedef struct _ADI_TMR_LOAD_t {
  union {
    struct {
      int16_t VALUE      : 16;  /**< Load value */
    };
    int16_t VALUE16;
  };
} ADI_TMR_LOAD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_LOAD_t__ */

/*@}*/

/** @defgroup CURCNT 16-bit timer value (CURCNT) Register
 *  16-bit timer value (CURCNT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_CURCNT_Struct
 *! \brief  16-bit timer value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_CURCNT_t__
typedef struct _ADI_TMR_CURCNT_t {
  union {
    struct {
      int16_t VALUE      : 16;  /**< Current count */
    };
    int16_t VALUE16;
  };
} ADI_TMR_CURCNT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_CURCNT_t__ */

/*@}*/

/** @defgroup CTL Control (CTL) Register
 *  Control (CTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_CTL_Struct
 *! \brief  Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_CTL_t__
typedef struct _ADI_TMR_CTL_t {
  union {
    struct {
      uint16_t PRE        :  2;  /**< Prescaler */
      uint16_t UP         :  1;  /**< Count up */
      uint16_t MODE       :  1;  /**< Timer mode */
      uint16_t EN         :  1;  /**< Timer enable */
      uint16_t CLK        :  2;  /**< Clock select */
      uint16_t RLD        :  1;  /**< Reload control */
      uint16_t EVTRANGE   :  5;  /**< Event select range */
      uint16_t EVTEN      :  1;  /**< Event select */
      uint16_t RSTEN      :  1;  /**< Counter and prescale reset enable */
      uint16_t SYNCBYP    :  1;  /**< Synchronization bypass */
    };
    uint16_t VALUE16;
  };
} ADI_TMR_CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_CTL_t__ */

/*@}*/

/** @defgroup CLRINT Clear Interrupt (CLRINT) Register
 *  Clear Interrupt (CLRINT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_CLRINT_Struct
 *! \brief  Clear Interrupt Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_CLRINT_t__
typedef struct _ADI_TMR_CLRINT_t {
  union {
    struct {
      uint16_t TIMEOUT    :  1;  /**< Clear timeout interrupt */
      uint16_t EVTCAPT    :  1;  /**< Clear captured event interrupt */
      uint16_t reserved2  : 14;
    };
    uint16_t VALUE16;
  };
} ADI_TMR_CLRINT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_CLRINT_t__ */

/*@}*/

/** @defgroup CAPTURE Capture (CAPTURE) Register
 *  Capture (CAPTURE) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_CAPTURE_Struct
 *! \brief  Capture Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_CAPTURE_t__
typedef struct _ADI_TMR_CAPTURE_t {
  union {
    struct {
      int16_t VALUE      : 16;  /**< 16-bit captured value */
    };
    int16_t VALUE16;
  };
} ADI_TMR_CAPTURE_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_CAPTURE_t__ */

/*@}*/

/** @defgroup ALOAD 16-bit load value, asynchronous (ALOAD) Register
 *  16-bit load value, asynchronous (ALOAD) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_ALOAD_Struct
 *! \brief  16-bit load value, asynchronous Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_ALOAD_t__
typedef struct _ADI_TMR_ALOAD_t {
  union {
    struct {
      int16_t VALUE      : 16;  /**< Load value, asynchronous */
    };
    int16_t VALUE16;
  };
} ADI_TMR_ALOAD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_ALOAD_t__ */

/*@}*/

/** @defgroup ACURCNT 16-bit timer value, asynchronous (ACURCNT) Register
 *  16-bit timer value, asynchronous (ACURCNT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_ACURCNT_Struct
 *! \brief  16-bit timer value, asynchronous Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_ACURCNT_t__
typedef struct _ADI_TMR_ACURCNT_t {
  union {
    struct {
      int16_t VALUE      : 16;  /**< Counter value */
    };
    int16_t VALUE16;
  };
} ADI_TMR_ACURCNT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_ACURCNT_t__ */

/*@}*/

/** @defgroup STAT Status (STAT) Register
 *  Status (STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_STAT_Struct
 *! \brief  Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_STAT_t__
typedef struct _ADI_TMR_STAT_t {
  union {
    struct {
      uint16_t TIMEOUT    :  1;  /**< Timeout event occurred */
      uint16_t CAPTURE    :  1;  /**< Capture event pending */
      uint16_t reserved2  :  4;
      uint16_t BUSY       :  1;  /**< Timer Busy */
      uint16_t PDOK       :  1;  /**< Clear Interrupt Register synchronization */
      uint16_t CNTRST     :  1;  /**< Counter reset occurring */
      uint16_t reserved9  :  7;
    };
    uint16_t VALUE16;
  };
} ADI_TMR_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_STAT_t__ */

/*@}*/

/** @defgroup PWMCTL PWM Control Register (PWMCTL) Register
 *  PWM Control Register (PWMCTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_PWMCTL_Struct
 *! \brief  PWM Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_PWMCTL_t__
typedef struct _ADI_TMR_PWMCTL_t {
  union {
    struct {
      uint16_t MATCH      :  1;  /**< PWM Match enabled */
      uint16_t IDLESTATE  :  1;  /**< PWM Idle State */
      uint16_t reserved2  : 14;
    };
    uint16_t VALUE16;
  };
} ADI_TMR_PWMCTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_PWMCTL_t__ */

/*@}*/

/** @defgroup PWMMATCH PWM Match Value (PWMMATCH) Register
 *  PWM Match Value (PWMMATCH) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_TMR_PWMMATCH_Struct
 *! \brief  PWM Match Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_PWMMATCH_t__
typedef struct _ADI_TMR_PWMMATCH_t {
  union {
    struct {
      int16_t VALUE      : 16;  /**< PWM Match Value */
    };
    int16_t VALUE16;
  };
} ADI_TMR_PWMMATCH_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_PWMMATCH_t__ */

/*@}*/

/** @defgroup CR0 RTC Control 0 (CR0) Register
 *  RTC Control 0 (CR0) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_RTC_CR0_MOD60ALM
 *! \brief  Periodic, modulo-60 alarm time in prescaled RTC time units beyond a modulo-60 boundary (MOD60ALM) Enumerations
 *  ========================================================================= */
typedef enum
{
  RTC_CR0_EXAMPLE_1_THIRTY_TIME_UNITS_DECIMAL    = 30,  /**< Example of setting a modulo-60 periodic interrupt from the RTC to be issued to the CPU at 30 time units past a modulo-60 boundary. */
  RTC_CR0_EXAMPLE_2_FIFTYFIVE_TIME_UNITS_DECIMAL = 55   /**< Example of setting a modulo-60 periodic interrupt from the RTC to be issued to the CPU at 55 time units past a modulo-60 boundary. */
} ADI_RTC_CR0_MOD60ALM;


/* ==========================================================================
 *! \struct ADI_RTC_CR0_Struct
 *! \brief  RTC Control 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_CR0_t__
typedef struct _ADI_RTC_CR0_t {
  union {
    struct {
      uint16_t CNTEN      :  1;  /**< Global enable for the RTC */
      uint16_t ALMEN      :  1;  /**< Enable the RTC alarm (absolute) operation */
      uint16_t ALMINTEN   :  1;  /**< Enable sourced alarm interrupts to the CPU */
      uint16_t TRMEN      :  1;  /**< Enable RTC digital trimming */
      uint16_t MOD60ALMEN :  1;  /**< Enable RTC modulo-60 counting of time past a modulo-60 boundary */
      uint16_t MOD60ALM   :  6;  /**< Periodic, modulo-60 alarm time in prescaled RTC time units beyond a modulo-60 boundary */
      uint16_t MOD60ALMINTEN :  1;  /**< Enable periodic Modulo-60 RTC alarm sourced interrupts to the CPU */
      uint16_t ISOINTEN      :  1;  /**< Enable RTC power-domain isolation sourced interrupts to the CPU when isolation of the RTC power domain is activated and subsequently de-activated */
      uint16_t WPNDERRINTEN  :  1;  /**< Enable Write pending error sourced interrupts to the CPU when an RTC register-write pending error occurs */
      uint16_t WSYNCINTEN    :  1;  /**< Enable Write synchronization sourced interrupts to the CPU */
      uint16_t WPNDINTEN     :  1;  /**< Enable Write Pending sourced interrupts to the CPU */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_CR0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_CR0_t__ */

/*@}*/

/** @defgroup SR0 RTC Status 0 (SR0) Register
 *  RTC Status 0 (SR0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SR0_Struct
 *! \brief  RTC Status 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SR0_t__
typedef struct _ADI_RTC_SR0_t {
  union {
    struct {
      uint16_t reserved0  :  1;
      uint16_t ALMINT     :  1;  /**< Alarm interrupt source */
      uint16_t MOD60ALMINT :  1;  /**< Modulo-60 RTC alarm interrupt source */
      uint16_t ISOINT      :  1;  /**< RTC power-domain isolation interrupt source */
      uint16_t WPNDERRINT  :  1;  /**< Write pending error interrupt source */
      uint16_t WSYNCINT    :  1;  /**< Write synchronization interrupt */
      uint16_t WPNDINT     :  1;  /**< Write pending interrupt */
      uint16_t WSYNCCR0    :  1;  /**< Synchronization status of posted writes to RTC Control 0 Register */
      uint16_t WSYNCSR0    :  1;  /**< Synchronization status of posted clearances to interrupt sources in RTC Status 0 Register */
      uint16_t WSYNCCNT0   :  1;  /**< Synchronization status of posted writes to RTC Count 0 Register */
      uint16_t WSYNCCNT1   :  1;  /**< Synchronization status of posted writes to RTC Count 1 Register */
      uint16_t WSYNCALM0   :  1;  /**< Synchronization status of posted writes to RTC Alarm 0 Register */
      uint16_t WSYNCALM1   :  1;  /**< Synchronization status of posted writes to RTC Alarm 1 Register */
      uint16_t WSYNCTRM    :  1;  /**< Synchronization status of posted writes to RTC Trim Register */
      uint16_t ISOENB      :  1;  /**< Visibility status of 32 kHz sourced registers, taking account of power-domain isolation */
      uint16_t reserved15  :  1;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SR0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SR0_t__ */

/*@}*/

/** @defgroup SR1 RTC Status 1 (SR1) Register
 *  RTC Status 1 (SR1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SR1_Struct
 *! \brief  RTC Status 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SR1_t__
typedef struct _ADI_RTC_SR1_t {
  union {
    struct {
      uint16_t reserved0  :  7;
      uint16_t WPNDCR0    :  1;  /**< Pending status of posted writes to RTC Control 0 Register */
      uint16_t WPNDSR0    :  1;  /**< Pending status of posted clearances of interrupt sources in RTC Status 0 Register */
      uint16_t WPNDCNT0   :  1;  /**< Pending status of posted writes to RTC Count 0 Register */
      uint16_t WPNDCNT1   :  1;  /**< Pending status of posted writes to RTC Count 1 Register */
      uint16_t WPNDALM0   :  1;  /**< Pending status of posted writes to RTC ALARM 0 Register */
      uint16_t WPNDALM1   :  1;  /**< Pending status of posted writes to RTC ALARM 1 Register */
      uint16_t WPNDTRM    :  1;  /**< Pending status of posted writes to RTC Trim Register */
      uint16_t reserved14 :  2;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SR1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SR1_t__ */

/*@}*/

/** @defgroup CNT0 RTC Count 0 (CNT0) Register
 *  RTC Count 0 (CNT0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_CNT0_Struct
 *! \brief  RTC Count 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_CNT0_t__
typedef struct _ADI_RTC_CNT0_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Lower 16 prescaled (non-fractional) bits of the RTC real-time count */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_CNT0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_CNT0_t__ */

/*@}*/

/** @defgroup CNT1 RTC Count 1 (CNT1) Register
 *  RTC Count 1 (CNT1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_CNT1_Struct
 *! \brief  RTC Count 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_CNT1_t__
typedef struct _ADI_RTC_CNT1_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Upper 16 prescaled (non-fractional) bits of the RTC real-time count */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_CNT1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_CNT1_t__ */

/*@}*/

/** @defgroup ALM0 RTC Alarm 0 (ALM0) Register
 *  RTC Alarm 0 (ALM0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_ALM0_Struct
 *! \brief  RTC Alarm 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_ALM0_t__
typedef struct _ADI_RTC_ALM0_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Lower 16 prescaled (that is, non-fractional) bits of the RTC alarm target time */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_ALM0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_ALM0_t__ */

/*@}*/

/** @defgroup ALM1 RTC Alarm 1 (ALM1) Register
 *  RTC Alarm 1 (ALM1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_ALM1_Struct
 *! \brief  RTC Alarm 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_ALM1_t__
typedef struct _ADI_RTC_ALM1_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Upper 16 prescaled (non-fractional) bits of the RTC alarm target time */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_ALM1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_ALM1_t__ */

/*@}*/

/** @defgroup TRM RTC Trim (TRM) Register
 *  RTC Trim (TRM) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_TRM_Struct
 *! \brief  RTC Trim Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_TRM_t__
typedef struct _ADI_RTC_TRM_t {
  union {
    struct {
      uint16_t VALUE      :  3;  /**< Trim value in prescaled RTC time units to be added or subtracted from the RTC count at the end of a periodic interval selected by RTC Trim Register */
      uint16_t ADD        :  1;  /**< Trim Polarity */
      uint16_t IVL        :  2;  /**< Trim interval in prescaled RTC time units */
      uint16_t IVL2EXPMIN :  4;  /**< Minimum power-of-two interval of prescaled RTC time units, which RTC Trim Register can select */
      uint16_t reserved10 :  6;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_TRM_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_TRM_t__ */

/*@}*/

/** @defgroup GWY RTC Gateway (GWY) Register
 *  RTC Gateway (GWY) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_GWY_Struct
 *! \brief  RTC Gateway Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_GWY_t__
typedef struct _ADI_RTC_GWY_t {
  union {
    struct {
      uint16_t SWKEY      : 16;  /**< Software-keyed command issued by the CPU */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_GWY_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_GWY_t__ */

/*@}*/

/** @defgroup CR1 RTC Control 1 (CR1) Register
 *  RTC Control 1 (CR1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_CR1_Struct
 *! \brief  RTC Control 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_CR1_t__
typedef struct _ADI_RTC_CR1_t {
  union {
    struct {
      uint16_t CNTINTEN   :  1;  /**< Enable for the RTC count interrupt source */
      uint16_t PSINTEN    :  1;  /**< Enable for the prescaled, modulo-1 interrupt source */
      uint16_t RTCTRMINTEN :  1;  /**< Enable for the RTC Trim interrupt source */
      uint16_t CNTROLLINTEN :  1;  /**< Enable for the RTC count roll-over interrupt source in RTC Status 2 Register */
      uint16_t CNTMOD60ROLLINTEN :  1;  /**< Enable for the RTC modulo-60 count roll-over interrupt source in RTC Status 2 Register */
      uint16_t PRESCALE2EXP      :  4;  /**< Prescale power of 2 division factor for the RTC base clock */
      uint16_t reserved9         :  7;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_CR1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_CR1_t__ */

/*@}*/

/** @defgroup SR2 RTC Status 2 (SR2) Register
 *  RTC Status 2 (SR2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SR2_Struct
 *! \brief  RTC Status 2 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SR2_t__
typedef struct _ADI_RTC_SR2_t {
  union {
    struct {
      uint16_t CNTINT     :  1;  /**< RTC count interrupt source */
      uint16_t PSINT      :  1;  /**< RTC prescaled, modulo-1 boundary interrupt source */
      uint16_t TRMINT     :  1;  /**< RTC Trim interrupt source */
      uint16_t CNTROLLINT :  1;  /**< RTC count roll-over interrupt source */
      uint16_t CNTMOD60ROLLINT :  1;  /**< RTC modulo-60 count roll-over interrupt source */
      uint16_t CNTROLL         :  1;  /**< RTC count roll-over */
      uint16_t CNTMOD60ROLL    :  1;  /**< RTC count modulo-60 roll-over */
      uint16_t TRMBDYMIR       :  1;  /**< Mirror of the RTCTRMBDY field of RTC Modulo Register */
      uint16_t reserved8       :  4;
      uint16_t WPNDCR1MIR      :  1;  /**< Pending status of posted writes to RTC Control 1 Register */
      uint16_t WPNDALM2MIR     :  1;  /**< Pending status of posted writes to RTC Alarm 2 Register */
      uint16_t WSYNCCR1MIR     :  1;  /**< Synchronization status of posted writes to RTC Control 1 Register */
      uint16_t WSYNCALM2MIR    :  1;  /**< Synchronization status of posted writes to RTC Alarm 2 Register */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SR2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SR2_t__ */

/*@}*/

/** @defgroup SNAP0 RTC Snapshot 0 (SNAP0) Register
 *  RTC Snapshot 0 (SNAP0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SNAP0_Struct
 *! \brief  RTC Snapshot 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SNAP0_t__
typedef struct _ADI_RTC_SNAP0_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Constituent part of the 47-bit RTC Input Capture Channel 0, containing a sticky snapshot of  RTC Count 0 Register */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SNAP0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SNAP0_t__ */

/*@}*/

/** @defgroup SNAP1 RTC Snapshot 1 (SNAP1) Register
 *  RTC Snapshot 1 (SNAP1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SNAP1_Struct
 *! \brief  RTC Snapshot 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SNAP1_t__
typedef struct _ADI_RTC_SNAP1_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Constituent part of the 47-bit RTC Input Capture Channel 0, containing a sticky snapshot of  RTC Count 1 Register */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SNAP1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SNAP1_t__ */

/*@}*/

/** @defgroup SNAP2 RTC Snapshot 2 (SNAP2) Register
 *  RTC Snapshot 2 (SNAP2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SNAP2_Struct
 *! \brief  RTC Snapshot 2 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SNAP2_t__
typedef struct _ADI_RTC_SNAP2_t {
  union {
    struct {
      uint16_t VALUE      : 15;  /**< Constituent part of the 47-bit RTC Input Capture Channel 0, containing a sticky snapshot of RTC Count 2 Register */
      uint16_t reserved15 :  1;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SNAP2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SNAP2_t__ */

/*@}*/

/** @defgroup MOD RTC Modulo (MOD) Register
 *  RTC Modulo (MOD) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_MOD_Struct
 *! \brief  RTC Modulo Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_MOD_t__
typedef struct _ADI_RTC_MOD_t {
  union {
    struct {
      uint16_t CNTMOD60   :  6;  /**< Modulo-60 value of prescaled  RTC Count 1 and RTC Count 0 Registers */
      uint16_t INCR       :  4;  /**< Most recent increment value added to the RTC Count in RTC Count 1 and RTC Count 0 Registers */
      uint16_t TRMBDY     :  1;  /**< Trim boundary indicator that the most recent RTC count increment has coincided with trimming of the count value */
      uint16_t CNT0_4TOZERO :  5;  /**< Mirror of RTC Count 0 Register [4:0] */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_MOD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_MOD_t__ */

/*@}*/

/** @defgroup CNT2 RTC Count 2 (CNT2) Register
 *  RTC Count 2 (CNT2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_CNT2_Struct
 *! \brief  RTC Count 2 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_CNT2_t__
typedef struct _ADI_RTC_CNT2_t {
  union {
    struct {
      uint16_t VALUE      : 15;  /**< Fractional bits of the RTC real-time count */
      uint16_t reserved15 :  1;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_CNT2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_CNT2_t__ */

/*@}*/

/** @defgroup ALM2 RTC Alarm 2 (ALM2) Register
 *  RTC Alarm 2 (ALM2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_ALM2_Struct
 *! \brief  RTC Alarm 2 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_ALM2_t__
typedef struct _ADI_RTC_ALM2_t {
  union {
    struct {
      uint16_t VALUE      : 15;  /**< Fractional (non-prescaled) bits of the RTC alarm target time */
      uint16_t reserved15 :  1;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_ALM2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_ALM2_t__ */

/*@}*/

/** @defgroup SR3 RTC Status 3 (SR3) Register
 *  RTC Status 3 (SR3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SR3_Struct
 *! \brief  RTC Status 3 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SR3_t__
typedef struct _ADI_RTC_SR3_t {
  union {
    struct {
      uint16_t RTCIC0IRQ  :  1;  /**< Sticky Interrupt Source for the RTC Input Capture Channel 0 */
      uint16_t reserved1  :  1;
      uint16_t RTCIC2IRQ  :  1;  /**< Sticky Interrupt Source for the RTC Input Capture Channel 2 */
      uint16_t RTCIC3IRQ  :  1;  /**< Sticky Interrupt Source for the RTC Input Capture Channel 3 */
      uint16_t RTCIC4IRQ  :  1;  /**< Sticky Interrupt Source for the RTC Input Capture Channel 4 */
      uint16_t reserved5  :  3;
      uint16_t ALMINTMIR  :  1;  /**< Read-only mirror of the ALMINT interrupt source in RTC Status 0 Register, acting as RTCOC0IRQ */
      uint16_t RTCOC1IRQ  :  1;  /**< Sticky Interrupt Source for Output Compare Channel 1 */
      uint16_t reserved10 :  6;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SR3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SR3_t__ */

/*@}*/

/** @defgroup CR2IC RTC Control 2 for Configuring Input Capture Channels (CR2IC) Register
 *  RTC Control 2 for Configuring Input Capture Channels (CR2IC) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_CR2IC_Struct
 *! \brief  RTC Control 2 for Configuring Input Capture Channels Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_CR2IC_t__
typedef struct _ADI_RTC_CR2IC_t {
  union {
    struct {
      uint16_t RTCIC0EN   :  1;  /**< Enable for the RTC Input Capture Channel 0 */
      uint16_t reserved1  :  1;
      uint16_t RTCIC2EN   :  1;  /**< Enable for the RTC Input Capture Channel 2 */
      uint16_t RTCIC3EN   :  1;  /**< Enable for the RTC Input Capture Channel 3 */
      uint16_t RTCIC4EN   :  1;  /**< Enable for the RTC Input Capture Channel 4 */
      uint16_t RTCIC0LH   :  1;  /**< Polarity of the active-going capture edge for the RTC Input Capture Channel 0 */
      uint16_t reserved6  :  1;
      uint16_t RTCIC2LH   :  1;  /**< Polarity of the active-going capture edge for the RTC Input Capture Channel 2 */
      uint16_t RTCIC3LH   :  1;  /**< Polarity of the active-going capture edge for the RTC Input Capture Channel 3 */
      uint16_t RTCIC4LH   :  1;  /**< Polarity of the active-going capture edge for the RTC Input Capture Channel 4 */
      uint16_t RTCIC0IRQEN :  1;  /**< Interrupt Enable for the RTC Input Capture Channel 0 */
      uint16_t reserved11  :  1;
      uint16_t RTCIC2IRQEN :  1;  /**< Interrupt Enable for the RTC Input Capture Channel 2 */
      uint16_t RTCIC3IRQEN :  1;  /**< Interrupt Enable for the RTC Input Capture Channel 3 */
      uint16_t RTCIC4IRQEN :  1;  /**< Interrupt Enable for the RTC Input Capture Channel 4 */
      uint16_t RTCICOWUSEN :  1;  /**< Enable Overwrite of Unread Snapshots for all RTC Input Capture Channels */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_CR2IC_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_CR2IC_t__ */

/*@}*/

/** @defgroup CR3OC RTC Control 3 for Configuring Output Compare Channel (CR3OC) Register
 *  RTC Control 3 for Configuring Output Compare Channel (CR3OC) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_CR3OC_Struct
 *! \brief  RTC Control 3 for Configuring Output Compare Channel Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_CR3OC_t__
typedef struct _ADI_RTC_CR3OC_t {
  union {
    struct {
      uint16_t reserved0  :  1;
      uint16_t RTCOC1EN   :  1;  /**< Enable for Output Compare Channel 1 */
      uint16_t reserved2   :  7;
      uint16_t RTCOC1IRQEN :  1;  /**< Interrupt Enable for Output Compare Channel 1 */
      uint16_t reserved10  :  6;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_CR3OC_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_CR3OC_t__ */

/*@}*/

/** @defgroup CR4OC RTC Control 4 for Configuring Output Compare Channel (CR4OC) Register
 *  RTC Control 4 for Configuring Output Compare Channel (CR4OC) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_RTC_CR4OC_RTCOC1MSKEN
 *! \brief  Enable for thermometer-code masking of the Output Compare 1 Channel (RTCOC1MSKEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  RTC_CR4OC_EN000 = 0,  /**< Do not apply a mask to the 16-bit Output Compare channel OC1.                                                                 */
  RTC_CR4OC_EN001 = 1   /**< Apply a thermometer-decoded mask to the 16-bit Output Compare channel OC1 provided that channel is enabled via CR3OC:RTCOC1EN */
} ADI_RTC_CR4OC_RTCOC1MSKEN;


/* ==========================================================================
 *! \struct ADI_RTC_CR4OC_Struct
 *! \brief  RTC Control 4 for Configuring Output Compare Channel Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_CR4OC_t__
typedef struct _ADI_RTC_CR4OC_t {
  union {
    struct {
      uint16_t reserved0   :  1;
      uint16_t RTCOC1MSKEN :  1;  /**< Enable for thermometer-code masking of the Output Compare 1 Channel */
      uint16_t reserved2   :  7;
      uint16_t RTCOC1ARLEN :  1;  /**< Enable for auto-reloading when output compare match occurs */
      uint16_t reserved10  :  6;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_CR4OC_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_CR4OC_t__ */

/*@}*/

/** @defgroup OCMSK RTC Masks for Output Compare Channel (OCMSK) Register
 *  RTC Masks for Output Compare Channel (OCMSK) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_OCMSK_Struct
 *! \brief  RTC Masks for Output Compare Channel Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_OCMSK_t__
typedef struct _ADI_RTC_OCMSK_t {
  union {
    struct {
      uint16_t RTCOCMSK   : 16;  /**< Concatenation of thermometer-encoded masks for the 16-bit output compare channels */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_OCMSK_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_OCMSK_t__ */

/*@}*/

/** @defgroup OC1ARL RTC Auto-Reload for Output Compare Channel 1 (OC1ARL) Register
 *  RTC Auto-Reload for Output Compare Channel 1 (OC1ARL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_OC1ARL_Struct
 *! \brief  RTC Auto-Reload for Output Compare Channel 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_OC1ARL_t__
typedef struct _ADI_RTC_OC1ARL_t {
  union {
    struct {
      uint16_t RTCOC1ARL  : 16;  /**< Auto-reload value when output compare match occurs */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_OC1ARL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_OC1ARL_t__ */

/*@}*/

/** @defgroup IC2 RTC Input Capture Channel 2 (IC2) Register
 *  RTC Input Capture Channel 2 (IC2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_IC2_Struct
 *! \brief  RTC Input Capture Channel 2 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_IC2_t__
typedef struct _ADI_RTC_IC2_t {
  union {
    struct {
      uint16_t RTCIC2     : 16;  /**< RTC Input Capture Channel 2 */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_IC2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_IC2_t__ */

/*@}*/

/** @defgroup IC3 RTC Input Capture Channel 3 (IC3) Register
 *  RTC Input Capture Channel 3 (IC3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_IC3_Struct
 *! \brief  RTC Input Capture Channel 3 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_IC3_t__
typedef struct _ADI_RTC_IC3_t {
  union {
    struct {
      uint16_t RTCIC3     : 16;  /**< RTC Input Capture Channel 3 */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_IC3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_IC3_t__ */

/*@}*/

/** @defgroup IC4 RTC Input Capture Channel 4 (IC4) Register
 *  RTC Input Capture Channel 4 (IC4) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_IC4_Struct
 *! \brief  RTC Input Capture Channel 4 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_IC4_t__
typedef struct _ADI_RTC_IC4_t {
  union {
    struct {
      uint16_t RTCIC4     : 16;  /**< RTC Input Capture Channel 4 */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_IC4_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_IC4_t__ */

/*@}*/

/** @defgroup OC1 RTC Output Compare Channel 1 (OC1) Register
 *  RTC Output Compare Channel 1 (OC1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_OC1_Struct
 *! \brief  RTC Output Compare Channel 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_OC1_t__
typedef struct _ADI_RTC_OC1_t {
  union {
    struct {
      uint16_t RTCOC1     : 16;  /**< RTC Output Compare 1 Channel. Scheduled alarm target time with optional auto-reload */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_OC1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_OC1_t__ */

/*@}*/

/** @defgroup SR4 RTC Status 4 (SR4) Register
 *  RTC Status 4 (SR4) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SR4_Struct
 *! \brief  RTC Status 4 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SR4_t__
typedef struct _ADI_RTC_SR4_t {
  union {
    struct {
      uint16_t WSYNCSR3   :  1;  /**< Synchronization status of posted clearances to interrupt sources in RTC Status 3 Register */
      uint16_t WSYNCCR2IC :  1;  /**< Synchronization status of posted writes to RTC Control 2 for Configuring Input Capture Channels Register */
      uint16_t WSYNCCR3OC :  1;  /**< Synchronization status of posted writes to RTC Control 3 for Configuring Output Compare Channel Register */
      uint16_t WSYNCCR4OC :  1;  /**< Synchronization status of posted writes to RTC Control 4 for Configuring Output Compare Channel Register */
      uint16_t WSYNCOCMSK :  1;  /**< Synchronization status of posted writes to RTC Masks for Output Compare Channel Register */
      uint16_t WSYNCOC1ARL :  1;  /**< Synchronization status of posted writes to RTC Auto-Reload for Output Compare Channel 1 Register */
      uint16_t WSYNCOC1    :  1;  /**< Synchronization status of posted writes to RTC Output Compare Channel 1 Register */
      uint16_t reserved7   :  3;
      uint16_t RSYNCIC0    :  1;  /**< Synchronization status of posted reads of RTC Input Channel 0 */
      uint16_t reserved11  :  1;
      uint16_t RSYNCIC2    :  1;  /**< Synchronization status of posted reads of RTC Input Channel 2 */
      uint16_t RSYNCIC3    :  1;  /**< Synchronization status of posted reads of RTC Input Channel 3 */
      uint16_t RSYNCIC4    :  1;  /**< Synchronization status of posted reads of RTC Input Channel 4 */
      uint16_t reserved15  :  1;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SR4_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SR4_t__ */

/*@}*/

/** @defgroup SR5 RTC Status 5 (SR5) Register
 *  RTC Status 5 (SR5) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SR5_Struct
 *! \brief  RTC Status 5 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SR5_t__
typedef struct _ADI_RTC_SR5_t {
  union {
    struct {
      uint16_t WPNDSR0    :  1;  /**< Pending status of posted clearances of interrupt sources in RTC Status 3 Register */
      uint16_t WPENDCR2IC :  1;  /**< Pending status of posted writes to RTC Control 2 for Configuring Input Capture Channels Register */
      uint16_t WPENDCR3OC :  1;  /**< Pending status of posted writes to RTC Control 3 for Configuring Output Compare Channel Register */
      uint16_t WPENDCR4OC :  1;  /**< Pending status of posted writes to RTC Control 4 for Configuring Output Compare Channel Register */
      uint16_t WPENDOCMSK :  1;  /**< Pending status of posted writes to RTC Masks for Output Compare Channel Register */
      uint16_t WPENDOC1ARL :  1;  /**< Pending status of posted writes to RTC Auto-Reload for Output Compare Channel 1 Register */
      uint16_t WPENDOC1    :  1;  /**< Pending status of posted writes to Output Compare Channel 1 */
      uint16_t reserved7   :  3;
      uint16_t RPENDIC0    :  1;  /**< Pending status of posted reads of RTC Input Channel 0 */
      uint16_t reserved11  :  1;
      uint16_t RPENDIC2    :  1;  /**< Pending status of posted reads of RTC Input Channel 2 */
      uint16_t RPENDIC3    :  1;  /**< Pending status of posted reads of RTC Input Channel 3 */
      uint16_t RPENDIC4    :  1;  /**< Pending status of posted reads of RTC Input Channel 4 */
      uint16_t reserved15  :  1;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SR5_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SR5_t__ */

/*@}*/

/** @defgroup SR6 RTC Status 6 (SR6) Register
 *  RTC Status 6 (SR6) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_SR6_Struct
 *! \brief  RTC Status 6 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_SR6_t__
typedef struct _ADI_RTC_SR6_t {
  union {
    struct {
      uint16_t RTCIC0UNR  :  1;  /**< Sticky unread status of the RTC Input Capture Channel 0 */
      uint16_t reserved1  :  1;
      uint16_t RTCIC2UNR  :  1;  /**< Sticky unread status of the RTC Input Capture Channel 2 */
      uint16_t RTCIC3UNR  :  1;  /**< Sticky unread status of the RTC Input Capture Channel 3 */
      uint16_t RTCIC4UNR  :  1;  /**< Sticky unread status of the RTC Input Capture Channel 4 */
      uint16_t reserved5  :  3;
      uint16_t RTCIC0SNAP :  1;  /**< Confirmation that RTC Snapshot 0, 1, 2 registers reflect the value of RTC Input Capture Channel 0 */
      uint16_t RTCFRZCNTPTR :  2;  /**< Pointer for the triple-read sequence of the RTC Freeze Count MMR */
      uint16_t reserved11   :  5;
    };
    uint16_t VALUE16;
  };
} ADI_RTC_SR6_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_SR6_t__ */

/*@}*/

/** @defgroup OC1TGT RTC Output Compare Channel 1 Target (OC1TGT) Register
 *  RTC Output Compare Channel 1 Target (OC1TGT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_OC1TGT_Struct
 *! \brief  RTC Output Compare Channel 1 Target Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_OC1TGT_t__
typedef struct _ADI_RTC_OC1TGT_t {
  union {
    struct {
      uint16_t RTCOC1TGT  : 16;  /**< Current, cumulative target time for Output Compare Channel 1, taking account of any auto-reloading */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_OC1TGT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_OC1TGT_t__ */

/*@}*/

/** @defgroup FRZCNT RTC Freeze Count (FRZCNT) Register
 *  RTC Freeze Count (FRZCNT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RTC_FRZCNT_Struct
 *! \brief  RTC Freeze Count Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_FRZCNT_t__
typedef struct _ADI_RTC_FRZCNT_t {
  union {
    struct {
      uint16_t RTCFRZCNT  : 16;  /**< RTC Freeze Count */
    };
    uint16_t VALUE16;
  };
} ADI_RTC_FRZCNT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_FRZCNT_t__ */

/*@}*/

/** @defgroup ADIID ADI Identification (ADIID) Register
 *  ADI Identification (ADIID) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SYS_ADIID_Struct
 *! \brief  ADI Identification Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SYS_ADIID_t__
typedef struct _ADI_SYS_ADIID_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Reads a fixed value of 0x4144 to indicate to debuggers that they are connected to an Analog Devices implemented Cortex based part */
    };
    uint16_t VALUE16;
  };
} ADI_SYS_ADIID_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SYS_ADIID_t__ */

/*@}*/

/** @defgroup CHIPID Chip Identifier (CHIPID) Register
 *  Chip Identifier (CHIPID) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SYS_CHIPID_Struct
 *! \brief  Chip Identifier Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SYS_CHIPID_t__
typedef struct _ADI_SYS_CHIPID_t {
  union {
    struct {
      uint16_t REV        :  4;  /**< Silicon revision */
      uint16_t PARTID     : 12;  /**< Part identifier */
    };
    uint16_t VALUE16;
  };
} ADI_SYS_CHIPID_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SYS_CHIPID_t__ */

/*@}*/

/** @defgroup SWDEN Serial Wire Debug Enable (SWDEN) Register
 *  Serial Wire Debug Enable (SWDEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SYS_SWDEN_Struct
 *! \brief  Serial Wire Debug Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SYS_SWDEN_t__
typedef struct _ADI_SYS_SWDEN_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< To enable SWD interface */
    };
    uint16_t VALUE16;
  };
} ADI_SYS_SWDEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SYS_SWDEN_t__ */

/*@}*/

/** @defgroup LOAD Load value (LOAD) Register
 *  Load value (LOAD) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_WDT_LOAD_Struct
 *! \brief  Load value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_WDT_LOAD_t__
typedef struct _ADI_WDT_LOAD_t {
  union {
    struct {
      int16_t VALUE      : 16;  /**< Load value */
    };
    int16_t VALUE16;
  };
} ADI_WDT_LOAD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_WDT_LOAD_t__ */

/*@}*/

/** @defgroup CCNT Current count value (CCNT) Register
 *  Current count value (CCNT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_WDT_CCNT_Struct
 *! \brief  Current count value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_WDT_CCNT_t__
typedef struct _ADI_WDT_CCNT_t {
  union {
    struct {
      int16_t VALUE      : 16;  /**< Current count value */
    };
    int16_t VALUE16;
  };
} ADI_WDT_CCNT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_WDT_CCNT_t__ */

/*@}*/

/** @defgroup CTL Control (CTL) Register
 *  Control (CTL) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_WDT_CTL_PRE
 *! \brief  Prescaler (PRE) Enumerations
 *  ========================================================================= */
typedef enum
{
  WDT_CTL_DIV1     = 0,  /**< source clock/1.             */
  WDT_CTL_DIV16    = 1,  /**< source clock/16.            */
  WDT_CTL_DIV256   = 2,  /**< source clock/256 (default). */
  WDT_CTL_RESERVED = 3   /**< Reserved                    */
} ADI_WDT_CTL_PRE;


/* ==========================================================================
 *! \struct ADI_WDT_CTL_Struct
 *! \brief  Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_WDT_CTL_t__
typedef struct _ADI_WDT_CTL_t {
  union {
    struct {
      uint16_t reserved0  :  1;
      uint16_t IRQ        :  1;  /**< Timer interrupt */
      uint16_t PRE        :  2;  /**< Prescaler */
      uint16_t reserved4  :  1;
      uint16_t EN         :  1;  /**< Timer enable */
      uint16_t MODE       :  1;  /**< Timer mode */
      uint16_t SPARE      :  1;  /**< Unused spare bit */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_WDT_CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_WDT_CTL_t__ */

/*@}*/

/** @defgroup RESTART Clear interrupt (RESTART) Register
 *  Clear interrupt (RESTART) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_WDT_RESTART_Struct
 *! \brief  Clear interrupt Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_WDT_RESTART_t__
typedef struct _ADI_WDT_RESTART_t {
  union {
    struct {
      int16_t CLRWORD    : 16;  /**< Clear watchdog */
    };
    int16_t VALUE16;
  };
} ADI_WDT_RESTART_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_WDT_RESTART_t__ */

/*@}*/

/** @defgroup STAT Status (STAT) Register
 *  Status (STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_WDT_STAT_Struct
 *! \brief  Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_WDT_STAT_t__
typedef struct _ADI_WDT_STAT_t {
  union {
    struct {
      uint16_t IRQ        :  1;  /**< WDT Interrupt */
      uint16_t CLRIRQ     :  1;  /**< Clear Interrupt Register write sync in progress */
      uint16_t LOADING    :  1;  /**< Load Register write sync in progress */
      uint16_t COUNTING   :  1;  /**< Control Register write sync in progress */
      uint16_t LOCKED     :  1;  /**< Lock status bit */
      uint16_t RSTCTL     :  1;  /**< Reset Control Register written and locked */
      uint16_t reserved6  : 10;
    };
    uint16_t VALUE16;
  };
} ADI_WDT_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_WDT_STAT_t__ */

/*@}*/

/** @defgroup MCTL Master control (MCTL) Register
 *  Master control (MCTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_MCTL_Struct
 *! \brief  Master control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_MCTL_t__
typedef struct _ADI_I2C_MCTL_t {
  union {
    struct {
      uint16_t MASEN      :  1;  /**< Master enable */
      uint16_t COMPLETE   :  1;  /**< Start back-off disable */
      uint16_t LOOPBACK   :  1;  /**< Internal loopback enable */
      uint16_t STRETCHSCL :  1;  /**< Stretch SCL enable */
      uint16_t IENMRX     :  1;  /**< Receive request interrupt enable */
      uint16_t IENMTX     :  1;  /**< Transmit request interrupt enable. */
      uint16_t IENALOST   :  1;  /**< Arbitration lost interrupt enable */
      uint16_t IENACK     :  1;  /**< ACK not received interrupt enable */
      uint16_t IENCMP     :  1;  /**< Transaction completed (or stop detected) interrupt enable */
      uint16_t MXMITDEC   :  1;  /**< Decrement master TX FIFO status when a byte has been transmitted */
      uint16_t MRXDMA     :  1;  /**< Enable master Rx DMA request */
      uint16_t MTXDMA     :  1;  /**< Enable master Tx DMA request */
      uint16_t BUSCLR     :  1;  /**< Bus-Clear Enable */
      uint16_t STOPBUSCLR :  1;  /**< Prestop Bus-Clear */
      uint16_t reserved14 :  2;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_MCTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_MCTL_t__ */

/*@}*/

/** @defgroup MSTAT Master status (MSTAT) Register
 *  Master status (MSTAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_MSTAT_Struct
 *! \brief  Master status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_MSTAT_t__
typedef struct _ADI_I2C_MSTAT_t {
  union {
    struct {
      uint16_t MTXF       :  2;  /**< Master Transmit FIFO status */
      uint16_t MTXREQ     :  1;  /**< When read is master Transmit request; when write is Clear master transmit interrupt bit */
      uint16_t MRXREQ     :  1;  /**< Master Receive request */
      uint16_t NACKADDR   :  1;  /**< ACK not received in response to an address */
      uint16_t ALOST      :  1;  /**< Arbitration lost */
      uint16_t MBUSY      :  1;  /**< Master busy */
      uint16_t NACKDATA   :  1;  /**< ACK not received in response to data write */
      uint16_t TCOMP      :  1;  /**< Transaction complete or stop detected */
      uint16_t MRXOVR     :  1;  /**< Master Receive FIFO overflow */
      uint16_t LINEBUSY   :  1;  /**< Line is busy */
      uint16_t MSTOP      :  1;  /**< STOP driven by this I2C Master */
      uint16_t MTXUNDR    :  1;  /**< Master Transmit Underflow */
      uint16_t SDAFILT    :  1;  /**< State of SDA Line */
      uint16_t SCLFILT    :  1;  /**< State of SCL Line */
      uint16_t reserved15 :  1;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_MSTAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_MSTAT_t__ */

/*@}*/

/** @defgroup MRX Master receive data (MRX) Register
 *  Master receive data (MRX) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_MRX_Struct
 *! \brief  Master receive data Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_MRX_t__
typedef struct _ADI_I2C_MRX_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Master receive register */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_MRX_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_MRX_t__ */

/*@}*/

/** @defgroup MTX Master transmit data (MTX) Register
 *  Master transmit data (MTX) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_MTX_Struct
 *! \brief  Master transmit data Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_MTX_t__
typedef struct _ADI_I2C_MTX_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Master transmit register */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_MTX_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_MTX_t__ */

/*@}*/

/** @defgroup MRXCNT Master receive data count (MRXCNT) Register
 *  Master receive data count (MRXCNT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_MRXCNT_Struct
 *! \brief  Master receive data count Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_MRXCNT_t__
typedef struct _ADI_I2C_MRXCNT_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Receive count */
      uint16_t EXTEND     :  1;  /**< Extended read */
      uint16_t reserved9  :  7;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_MRXCNT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_MRXCNT_t__ */

/*@}*/

/** @defgroup MCRXCNT Master current receive data count (MCRXCNT) Register
 *  Master current receive data count (MCRXCNT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_MCRXCNT_Struct
 *! \brief  Master current receive data count Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_MCRXCNT_t__
typedef struct _ADI_I2C_MCRXCNT_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Current receive count */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_MCRXCNT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_MCRXCNT_t__ */

/*@}*/

/** @defgroup ADDR1 1st master address byte (ADDR1) Register
 *  1st master address byte (ADDR1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_ADDR1_Struct
 *! \brief  1st master address byte Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_ADDR1_t__
typedef struct _ADI_I2C_ADDR1_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Address byte 1 */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_ADDR1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_ADDR1_t__ */

/*@}*/

/** @defgroup ADDR2 2nd master address byte (ADDR2) Register
 *  2nd master address byte (ADDR2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_ADDR2_Struct
 *! \brief  2nd master address byte Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_ADDR2_t__
typedef struct _ADI_I2C_ADDR2_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Address byte 2 */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_ADDR2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_ADDR2_t__ */

/*@}*/

/** @defgroup BYT Start byte (BYT) Register
 *  Start byte (BYT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_BYT_Struct
 *! \brief  Start byte Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_BYT_t__
typedef struct _ADI_I2C_BYT_t {
  union {
    struct {
      uint16_t SBYTE      :  8;  /**< Start byte */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_BYT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_BYT_t__ */

/*@}*/

/** @defgroup DIV Serial clock period divisor (DIV) Register
 *  Serial clock period divisor (DIV) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_DIV_Struct
 *! \brief  Serial clock period divisor Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_DIV_t__
typedef struct _ADI_I2C_DIV_t {
  union {
    struct {
      uint16_t LOW        :  8;  /**< Serial clock low time */
      uint16_t HIGH       :  8;  /**< Serial clock high time */
    };
    uint16_t VALUE16;
  };
} ADI_I2C_DIV_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_DIV_t__ */

/*@}*/

/** @defgroup SCTL Slave control (SCTL) Register
 *  Slave control (SCTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_SCTL_Struct
 *! \brief  Slave control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_SCTL_t__
typedef struct _ADI_I2C_SCTL_t {
  union {
    struct {
      uint16_t SLVEN      :  1;  /**< Slave enable */
      uint16_t ADR10EN    :  1;  /**< Enabled 10-bit addressing */
      uint16_t GCEN       :  1;  /**< General call enable */
      uint16_t HGCEN      :  1;  /**< Hardware general call enable */
      uint16_t GCSBCLR    :  1;  /**< General call status bit clear */
      uint16_t EARLYTXR   :  1;  /**< Early transmit request mode */
      uint16_t reserved6  :  1;
      uint16_t NACK       :  1;  /**< NACK next communication */
      uint16_t IENSTOP    :  1;  /**< Stop condition detected interrupt enable */
      uint16_t IENSRX     :  1;  /**< Slave Receive request interrupt enable */
      uint16_t IENSTX     :  1;  /**< Slave Transmit request interrupt enable */
      uint16_t STXDEC     :  1;  /**< Decrement Slave Tx FIFO status when a byte has been transmitted */
      uint16_t IENREPST   :  1;  /**< Repeated start interrupt enable */
      uint16_t SRXDMA     :  1;  /**< Enable slave Rx DMA request */
      uint16_t STXDMA     :  1;  /**< Enable slave Tx DMA request */
      uint16_t reserved15 :  1;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_SCTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_SCTL_t__ */

/*@}*/

/** @defgroup SSTAT Slave I2C Status/Error/IRQ (SSTAT) Register
 *  Slave I2C Status/Error/IRQ (SSTAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_SSTAT_Struct
 *! \brief  Slave I2C Status/Error/IRQ Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_SSTAT_t__
typedef struct _ADI_I2C_SSTAT_t {
  union {
    struct {
      uint16_t STXFSEREQ  :  1;  /**< Slave Tx FIFO Status or early request */
      uint16_t STXUNDR    :  1;  /**< Slave Transmit FIFO underflow */
      uint16_t STXREQ     :  1;  /**< When read is slave transmit request; when write is clear slave transmit interrupt bit */
      uint16_t SRXREQ     :  1;  /**< Slave Receive request */
      uint16_t SRXOVR     :  1;  /**< Slave Receive FIFO overflow */
      uint16_t NOACK      :  1;  /**< Ack not generated by the slave */
      uint16_t SBUSY      :  1;  /**< Slave busy */
      uint16_t GCINT      :  1;  /**< General call interrupt */
      uint16_t GCID       :  2;  /**< General ID */
      uint16_t STOP       :  1;  /**< Stop after start and matching address */
      uint16_t IDMAT      :  2;  /**< Device ID matched */
      uint16_t REPSTART   :  1;  /**< Repeated start and matching address */
      uint16_t START      :  1;  /**< Start and matching address */
      uint16_t reserved15 :  1;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_SSTAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_SSTAT_t__ */

/*@}*/

/** @defgroup SRX Slave receive (SRX) Register
 *  Slave receive (SRX) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_SRX_Struct
 *! \brief  Slave receive Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_SRX_t__
typedef struct _ADI_I2C_SRX_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Slave receive register */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_SRX_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_SRX_t__ */

/*@}*/

/** @defgroup STX Slave transmit (STX) Register
 *  Slave transmit (STX) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_STX_Struct
 *! \brief  Slave transmit Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_STX_t__
typedef struct _ADI_I2C_STX_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Slave transmit register */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_STX_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_STX_t__ */

/*@}*/

/** @defgroup ALT Hardware general call ID (ALT) Register
 *  Hardware general call ID (ALT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_ALT_Struct
 *! \brief  Hardware general call ID Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_ALT_t__
typedef struct _ADI_I2C_ALT_t {
  union {
    struct {
      uint16_t ID         :  8;  /**< Slave Alt */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_ALT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_ALT_t__ */

/*@}*/

/** @defgroup ID0 1st slave address device ID (ID0) Register
 *  1st slave address device ID (ID0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_ID0_Struct
 *! \brief  1st slave address device ID Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_ID0_t__
typedef struct _ADI_I2C_ID0_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Slave device ID 0 */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_ID0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_ID0_t__ */

/*@}*/

/** @defgroup ID1 2nd slave address device ID (ID1) Register
 *  2nd slave address device ID (ID1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_ID1_Struct
 *! \brief  2nd slave address device ID Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_ID1_t__
typedef struct _ADI_I2C_ID1_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Slave device ID 1 */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_ID1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_ID1_t__ */

/*@}*/

/** @defgroup ID2 3rd slave address device ID (ID2) Register
 *  3rd slave address device ID (ID2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_ID2_Struct
 *! \brief  3rd slave address device ID Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_ID2_t__
typedef struct _ADI_I2C_ID2_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Slave device ID 2 */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_ID2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_ID2_t__ */

/*@}*/

/** @defgroup ID3 4th slave address device ID (ID3) Register
 *  4th slave address device ID (ID3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_ID3_Struct
 *! \brief  4th slave address device ID Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_ID3_t__
typedef struct _ADI_I2C_ID3_t {
  union {
    struct {
      uint16_t VALUE      :  8;  /**< Slave device ID 3 */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_ID3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_ID3_t__ */

/*@}*/

/** @defgroup STAT Master and slave FIFO status (STAT) Register
 *  Master and slave FIFO status (STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_STAT_Struct
 *! \brief  Master and slave FIFO status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_STAT_t__
typedef struct _ADI_I2C_STAT_t {
  union {
    struct {
      uint16_t STXF       :  2;  /**< Slave transmit FIFO status */
      uint16_t SRXF       :  2;  /**< Slave receive FIFO status */
      uint16_t MTXF       :  2;  /**< Master transmit FIFO status */
      uint16_t MRXF       :  2;  /**< Master receive FIFO status */
      uint16_t SFLUSH     :  1;  /**< Flush the slave transmit FIFO */
      uint16_t MFLUSH     :  1;  /**< Flush the master transmit FIFO */
      uint16_t reserved10 :  6;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_STAT_t__ */

/*@}*/

/** @defgroup SHCTL Shared control (SHCTL) Register
 *  Shared control (SHCTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_SHCTL_Struct
 *! \brief  Shared control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_SHCTL_t__
typedef struct _ADI_I2C_SHCTL_t {
  union {
    struct {
      uint16_t RST        :  1;  /**< Reset START STOP detect circuit */
      uint16_t reserved1  : 15;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_SHCTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_SHCTL_t__ */

/*@}*/

/** @defgroup TCTL Timing Control Register (TCTL) Register
 *  Timing Control Register (TCTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_TCTL_Struct
 *! \brief  Timing Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_TCTL_t__
typedef struct _ADI_I2C_TCTL_t {
  union {
    struct {
      uint16_t THDATIN    :  5;  /**< Data In Hold Start */
      uint16_t reserved5  :  3;
      uint16_t FILTEROFF  :  1;  /**< Input Filter Control */
      uint16_t reserved9  :  7;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_TCTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_TCTL_t__ */

/*@}*/

/** @defgroup ASTRETCH_SCL Automatic stretch SCL register (ASTRETCH_SCL) Register
 *  Automatic stretch SCL register (ASTRETCH_SCL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_I2C_ASTRETCH_SCL_Struct
 *! \brief  Automatic stretch SCL Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_ASTRETCH_SCL_t__
typedef struct _ADI_I2C_ASTRETCH_SCL_t {
  union {
    struct {
      uint16_t MST        :  4;  /**< master automatic stretch mode */
      uint16_t SLV        :  4;  /**< slave automatic stretch mode */
      uint16_t MSTTMO     :  1;  /**< master automatic stretch timeout */
      uint16_t SLVTMO     :  1;  /**< slave automatic stretch timeout */
      uint16_t reserved10 :  6;
    };
    uint16_t VALUE16;
  };
} ADI_I2C_ASTRETCH_SCL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_ASTRETCH_SCL_t__ */

/*@}*/

/** @defgroup STAT Status (STAT) Register
 *  Status (STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_STAT_Struct
 *! \brief  Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_STAT_t__
typedef struct _ADI_SPI_STAT_t {
  union {
    struct {
      uint16_t IRQ        :  1;  /**< SPI Interrupt status */
      uint16_t XFRDONE    :  1;  /**< SPI transfer completion */
      uint16_t TXEMPTY    :  1;  /**< SPI Tx FIFO empty interrupt */
      uint16_t TXDONE     :  1;  /**< SPI Tx Done in read command mode */
      uint16_t TXUNDR     :  1;  /**< SPI Tx FIFO underflow */
      uint16_t TXIRQ      :  1;  /**< SPI Tx IRQ */
      uint16_t RXIRQ      :  1;  /**< SPI Rx IRQ */
      uint16_t RXOVR      :  1;  /**< SPI Rx FIFO overflow */
      uint16_t reserved8  :  3;
      uint16_t CS         :  1;  /**< CS Status */
      uint16_t CSERR      :  1;  /**< Detected a CS error condition in slave mode */
	  uint16_t CSRISE     :  1;  /**< Detected a rising edge on CS, in slave CON mode */
      uint16_t CSFALL     :  1;  /**< Detected a falling edge on CS, in slave CON mode */
      uint16_t RDY        :  1;  /**< Detected an edge on Ready indicator for flow-control */
    };
    uint16_t VALUE16;
  };
} ADI_SPI_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_STAT_t__ */

/*@}*/

/** @defgroup RX Receive (RX) Register
 *  Receive (RX) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_RX_Struct
 *! \brief  Receive Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_RX_t__
typedef struct _ADI_SPI_RX_t {
  union {
    struct {
      uint16_t BYTE1      :  8;  /**< 8-bit receive buffer */
      uint16_t BYTE2      :  8;  /**< 8-bit receive buffer, used only in DMA modes */
    };
    uint16_t VALUE16;
  };
} ADI_SPI_RX_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_RX_t__ */

/*@}*/

/** @defgroup TX Transmit (TX) Register
 *  Transmit (TX) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_TX_Struct
 *! \brief  Transmit Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_TX_t__
typedef struct _ADI_SPI_TX_t {
  union {
    struct {
      uint16_t BYTE1      :  8;  /**< 8-bit transmit buffer */
      uint16_t BYTE2      :  8;  /**< 8-bit transmit buffer, used only in DMA modes */
    };
    uint16_t VALUE16;
  };
} ADI_SPI_TX_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_TX_t__ */

/*@}*/

/** @defgroup DIV SPI baud rate selection (DIV) Register
 *  SPI baud rate selection (DIV) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_DIV_Struct
 *! \brief  SPI baud rate selection Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_DIV_t__
typedef struct _ADI_SPI_DIV_t {
  union {
    struct {
      uint16_t VALUE      :  6;  /**< SPI clock divider */
      uint16_t reserved6  : 10;
    };
    uint16_t VALUE16;
  };
} ADI_SPI_DIV_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_DIV_t__ */

/*@}*/

/** @defgroup CTL SPI configuration 1 (CTL) Register
 *  SPI configuration 1 (CTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_CTL_Struct
 *! \brief  SPI configuration 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_CTL_t__
typedef struct _ADI_SPI_CTL_t {
  union {
    struct {
      uint16_t SPIEN      :  1;  /**< SPI enable */
      uint16_t MASEN      :  1;  /**< Master mode enable */
      uint16_t CPHA       :  1;  /**< Serial clock phase mode */
      uint16_t CPOL       :  1;  /**< Serial Clock Polarity */
      uint16_t WOM        :  1;  /**< SPI Wired Or mode */
      uint16_t LSB        :  1;  /**< LSB first transfer enable */
      uint16_t TIM        :  1;  /**< SPI transfer and interrupt mode */
      uint16_t ZEN        :  1;  /**< Transmit zeros enable */
      uint16_t RXOF       :  1;  /**< RX overflow overwrite enable */
      uint16_t OEN        :  1;  /**< Slave MISO output enable */
      uint16_t LOOPBACK   :  1;  /**< Loopback enable */
      uint16_t CON        :  1;  /**< Continuous transfer enable */
      uint16_t RFLUSH     :  1;  /**< SPI Rx FIFO Flush enable */
      uint16_t TFLUSH     :  1;  /**< SPI Tx FIFO Flush enable */
      uint16_t CSRST      :  1;  /**< Reset Mode for CS Error bit */
      uint16_t reserved15 :  1;
    };
    uint16_t VALUE16;
  };
} ADI_SPI_CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_CTL_t__ */

/*@}*/

/** @defgroup IEN SPI configuration 2 (IEN) Register
 *  SPI configuration 2 (IEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_IEN_Struct
 *! \brief  SPI configuration 2 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_IEN_t__
typedef struct _ADI_SPI_IEN_t {
  union {
    struct {
      uint16_t IRQMODE    :  3;  /**< SPI IRQ mode bits */
      uint16_t reserved3  :  5;
      uint16_t CS         :  1;  /**< Enable interrupt on every CS edge in slave CON mode */
      uint16_t TXUNDR     :  1;  /**< Tx-underflow interrupt enable */
      uint16_t RXOVR      :  1;  /**< Rx-overflow interrupt enable */
      uint16_t RDY        :  1;  /**< Ready signal edge interrupt enable */
      uint16_t TXDONE     :  1;  /**< SPI transmit done interrupt enable */
      uint16_t XFRDONE    :  1;  /**< SPI transfer completion interrupt enable */
      uint16_t TXEMPTY    :  1;  /**< Tx-FIFO Empty interrupt enable */
      uint16_t reserved15 :  1;
    };
    uint16_t VALUE16;
  };
} ADI_SPI_IEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_IEN_t__ */

/*@}*/

/** @defgroup CNT Transfer byte count (CNT) Register
 *  Transfer byte count (CNT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_CNT_Struct
 *! \brief  Transfer byte count Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_CNT_t__
typedef struct _ADI_SPI_CNT_t {
  union {
    struct {
      uint16_t VALUE      : 14;  /**< Transfer byte count */
      uint16_t reserved14 :  1;
      uint16_t FRAMECONT  :  1;  /**< Continue frame */
    };
    uint16_t VALUE16;
  };
} ADI_SPI_CNT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_CNT_t__ */

/*@}*/

/** @defgroup DMA SPI DMA enable (DMA) Register
 *  SPI DMA enable (DMA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_DMA_Struct
 *! \brief  SPI DMA enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_DMA_t__
typedef struct _ADI_SPI_DMA_t {
  union {
    struct {
      uint16_t EN         :  1;  /**< Enable DMA for data transfer */
      uint16_t TXEN       :  1;  /**< Enable transmit DMA request */
      uint16_t RXEN       :  1;  /**< Enable receive DMA request */
      uint16_t reserved3  : 13;
    };
    uint16_t VALUE16;
  };
} ADI_SPI_DMA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_DMA_t__ */

/*@}*/

/** @defgroup FIFO_STAT FIFO Status (FIFO_STAT) Register
 *  FIFO Status (FIFO_STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_FIFO_STAT_Struct
 *! \brief  FIFO Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_FIFO_STAT_t__
typedef struct _ADI_SPI_FIFO_STAT_t {
  union {
    struct {
      uint16_t TX         :  4;  /**< SPI Tx FIFO status */
      uint16_t reserved4  :  4;
      uint16_t RX         :  4;  /**< SPI Rx FIFO status */
      uint16_t reserved12 :  4;
    };
    uint16_t VALUE16;
  };
} ADI_SPI_FIFO_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_FIFO_STAT_t__ */

/*@}*/

/** @defgroup RD_CTL Read Control (RD_CTL) Register
 *  Read Control (RD_CTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_RD_CTL_Struct
 *! \brief  Read Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_RD_CTL_t__
typedef struct _ADI_SPI_RD_CTL_t {
  union {
    struct {
      uint16_t CMDEN      :  1;  /**< Read command enable */
      uint16_t OVERLAP    :  1;  /**< Tx/Rx Overlap mode */
      uint16_t TXBYTES    :  4;  /**< Transmit byte count minus 1 for read command */
      uint16_t reserved6  :  2;
      uint16_t THREEPIN   :  1;  /**< Three pin SPI mode */
      uint16_t reserved9  :  7;
    };
    uint16_t VALUE16;
  };
} ADI_SPI_RD_CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_RD_CTL_t__ */

/*@}*/

/** @defgroup FLOW_CTL Flow Control (FLOW_CTL) Register
 *  Flow Control (FLOW_CTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_FLOW_CTL_Struct
 *! \brief  Flow Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_FLOW_CTL_t__
typedef struct _ADI_SPI_FLOW_CTL_t {
  union {
    struct {
      uint16_t MODE       :  2;  /**< Flow control mode */
      uint16_t reserved2  :  2;
      uint16_t RDYPOL     :  1;  /**< Polarity of RDY/MISO line */
      uint16_t reserved5  :  3;
      uint16_t RDBURSTSZ  :  4;  /**< Read data burst size minus 1 */
      uint16_t reserved12 :  4;
    };
    uint16_t VALUE16;
  };
} ADI_SPI_FLOW_CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_FLOW_CTL_t__ */

/*@}*/

/** @defgroup WAIT_TMR Wait timer for flow control (WAIT_TMR) Register
 *  Wait timer for flow control (WAIT_TMR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_WAIT_TMR_Struct
 *! \brief  Wait timer for flow control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_WAIT_TMR_t__
typedef struct _ADI_SPI_WAIT_TMR_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Wait timer for flow-control */
    };
    uint16_t VALUE16;
  };
} ADI_SPI_WAIT_TMR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_WAIT_TMR_t__ */

/*@}*/

/** @defgroup CS_CTL Chip-Select control for multi-slave connections (CS_CTL) Register
 *  Chip-Select control for multi-slave connections (CS_CTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_CS_CTL_Struct
 *! \brief  Chip-Select control for multi-slave connections Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_CS_CTL_t__
typedef struct _ADI_SPI_CS_CTL_t {
  union {
    struct {
      uint16_t SEL        :  4;  /**< Chip-Select control */
      uint16_t reserved4  : 12;
    };
    uint16_t VALUE16;
  };
} ADI_SPI_CS_CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_CS_CTL_t__ */

/*@}*/

/** @defgroup CS_OVERRIDE Chip-Select Override (CS_OVERRIDE) Register
 *  Chip-Select Override (CS_OVERRIDE) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_SPI_CS_OVERRIDE_Struct
 *! \brief  Chip-Select Override Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_CS_OVERRIDE_t__
typedef struct _ADI_SPI_CS_OVERRIDE_t {
  union {
    struct {
      uint16_t CTL        :  2;  /**< CS Override Control */
      uint16_t reserved2  : 14;
    };
    uint16_t VALUE16;
  };
} ADI_SPI_CS_OVERRIDE_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_CS_OVERRIDE_t__ */

/*@}*/

/** @defgroup COMRX Receive Buffer Register (COMRX) Register
 *  Receive Buffer Register (COMRX) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_COMRX_Struct
 *! \brief  Receive Buffer Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_COMRX_t__
typedef struct _ADI_UART_COMRX_t {
  union {
    struct {
      uint16_t RBR        :  8;  /**< Receive Buffer Register */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_UART_COMRX_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_COMRX_t__ */

/*@}*/

/** @defgroup COMTX Transmit Holding Register (COMTX) Register
 *  Transmit Holding Register (COMTX) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_COMTX_Struct
 *! \brief  Transmit Holding Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_COMTX_t__
typedef struct _ADI_UART_COMTX_t {
  union {
    struct {
      uint16_t THR        :  8;  /**< Transmit Holding Register */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_UART_COMTX_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_COMTX_t__ */

/*@}*/

/** @defgroup COMIEN Interrupt Enable (COMIEN) Register
 *  Interrupt Enable (COMIEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_COMIEN_Struct
 *! \brief  Interrupt Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_COMIEN_t__
typedef struct _ADI_UART_COMIEN_t {
  union {
    struct {
      uint16_t ERBFI      :  1;  /**< Receive buffer full interrupt */
      uint16_t ETBEI      :  1;  /**< Transmit buffer empty interrupt */
      uint16_t ELSI       :  1;  /**< Rx status interrupt */
      uint16_t EDSSI      :  1;  /**< Modem status interrupt */
      uint16_t EDMAT      :  1;  /**< DMA requests in transmit mode */
      uint16_t EDMAR      :  1;  /**< DMA requests in receive mode */
      uint16_t reserved6  : 10;
    };
    uint16_t VALUE16;
  };
} ADI_UART_COMIEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_COMIEN_t__ */

/*@}*/

/** @defgroup COMIIR Interrupt ID (COMIIR) Register
 *  Interrupt ID (COMIIR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_COMIIR_Struct
 *! \brief  Interrupt ID Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_COMIIR_t__
typedef struct _ADI_UART_COMIIR_t {
  union {
    struct {
      uint16_t NIRQ       :  1;  /**< Interrupt flag */
      uint16_t STA        :  3;  /**< Interrupt status */
      uint16_t reserved4  :  2;
      uint16_t FEND       :  2;  /**< FIFO enabled */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_UART_COMIIR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_COMIIR_t__ */

/*@}*/

/** @defgroup COMLCR Line Control (COMLCR) Register
 *  Line Control (COMLCR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_COMLCR_Struct
 *! \brief  Line Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_COMLCR_t__
typedef struct _ADI_UART_COMLCR_t {
  union {
    struct {
      uint16_t WLS        :  2;  /**< Word Length Select */
      uint16_t STOP       :  1;  /**< Stop Bit */
      uint16_t PEN        :  1;  /**< Parity Enable */
      uint16_t EPS        :  1;  /**< Parity Select */
      uint16_t SP         :  1;  /**< Stick Parity */
      uint16_t BRK        :  1;  /**< Set Break */
      uint16_t reserved7  :  9;
    };
    uint16_t VALUE16;
  };
} ADI_UART_COMLCR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_COMLCR_t__ */

/*@}*/

/** @defgroup COMMCR Modem Control (COMMCR) Register
 *  Modem Control (COMMCR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_COMMCR_Struct
 *! \brief  Modem Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_COMMCR_t__
typedef struct _ADI_UART_COMMCR_t {
  union {
    struct {
      uint16_t DTR        :  1;  /**< Data Terminal Ready */
      uint16_t RTS        :  1;  /**< Request to send */
      uint16_t OUT1       :  1;  /**< Output 1 */
      uint16_t OUT2       :  1;  /**< Output 2 */
      uint16_t LOOPBACK   :  1;  /**< Loopback mode */
      uint16_t reserved5  : 11;
    };
    uint16_t VALUE16;
  };
} ADI_UART_COMMCR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_COMMCR_t__ */

/*@}*/

/** @defgroup COMLSR Line Status (COMLSR) Register
 *  Line Status (COMLSR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_COMLSR_Struct
 *! \brief  Line Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_COMLSR_t__
typedef struct _ADI_UART_COMLSR_t {
  union {
    struct {
      uint16_t DR         :  1;  /**< Data Ready */
      uint16_t OE         :  1;  /**< Overrun Error */
      uint16_t PE         :  1;  /**< Parity Error */
      uint16_t FE         :  1;  /**< Framing Error */
      uint16_t BI         :  1;  /**< Break Indicator */
      uint16_t THRE       :  1;  /**< COMTX Empty */
      uint16_t TEMT       :  1;  /**< COMTX and Shift Register Empty Status */
      uint16_t FIFOERR    :  1;  /**< data byte(s) in RX FIFO have either parity error, frame error or break indication. only used in 16550 mode; Read-clear if no more error in RX FIFO */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_UART_COMLSR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_COMLSR_t__ */

/*@}*/

/** @defgroup COMMSR Modem Status (COMMSR) Register
 *  Modem Status (COMMSR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_COMMSR_Struct
 *! \brief  Modem Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_COMMSR_t__
typedef struct _ADI_UART_COMMSR_t {
  union {
    struct {
      uint16_t DCTS       :  1;  /**< Delta CTS */
      uint16_t DDSR       :  1;  /**< Delta DSR */
      uint16_t TERI       :  1;  /**< Trailing Edge RI */
      uint16_t DDCD       :  1;  /**< Delta DCD */
      uint16_t CTS        :  1;  /**< Clear To Send */
      uint16_t DSR        :  1;  /**< Data Set Ready */
      uint16_t RI         :  1;  /**< Ring Indicator */
      uint16_t DCD        :  1;  /**< Data Carrier Detect */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_UART_COMMSR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_COMMSR_t__ */

/*@}*/

/** @defgroup COMSCR Scratch buffer (COMSCR) Register
 *  Scratch buffer (COMSCR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_COMSCR_Struct
 *! \brief  Scratch buffer Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_COMSCR_t__
typedef struct _ADI_UART_COMSCR_t {
  union {
    struct {
      uint16_t SCR        :  8;  /**< Scratch */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_UART_COMSCR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_COMSCR_t__ */

/*@}*/

/** @defgroup COMFCR FIFO Control (COMFCR) Register
 *  FIFO Control (COMFCR) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_UART_COMFCR_FDMAMD
 *! \brief  FIFO DMA mode (FDMAMD) Enumerations
 *  ========================================================================= */
typedef enum
{
  UART_COMFCR_MODE0 = 0,  /**< in DMA mode 0, RX DMA request will be asserted whenever there's data in RBR or RX FIFO and de-assert whenever RBR or RX FIFO is empty; TX DMA request will be asserted whenever THR or TX FIFO is empty and de-assert whenever data written to                               */
  UART_COMFCR_MODE1 = 1   /**< in DMA mode 1, RX DMA request will be asserted whenever RX FIFO trig level or time out reached and de-assert thereafter when RX FIFO is empty; TX DMA request will be asserted whenever TX FIFO is empty and de-assert thereafter when TX FIFO is completely filled up full; */
} ADI_UART_COMFCR_FDMAMD;


/* ==========================================================================
 *! \struct ADI_UART_COMFCR_Struct
 *! \brief  FIFO Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_COMFCR_t__
typedef struct _ADI_UART_COMFCR_t {
  union {
    struct {
      uint16_t FIFOEN     :  1;  /**< FIFO enable as to work in 16550 mode */
      uint16_t RFCLR      :  1;  /**< clear RX FIFO */
      uint16_t TFCLR      :  1;  /**< clear TX FIFO */
      uint16_t FDMAMD     :  1;  /**< FIFO DMA mode */
      uint16_t reserved4  :  2;
      uint16_t RFTRIG     :  2;  /**< RX FIFO Trig level */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_UART_COMFCR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_COMFCR_t__ */

/*@}*/

/** @defgroup COMFBR Fractional Baud Rate (COMFBR) Register
 *  Fractional Baud Rate (COMFBR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_COMFBR_Struct
 *! \brief  Fractional Baud Rate Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_COMFBR_t__
typedef struct _ADI_UART_COMFBR_t {
  union {
    struct {
      uint16_t DIVN       : 11;  /**< Fractional baud rate N divide bits 0 to 2047. */
      uint16_t DIVM       :  2;  /**< Fractional baud rate M divide bits 1 to 3 */
      uint16_t reserved13 :  2;
      uint16_t FBEN       :  1;  /**< Fractional baud rate generator enable */
    };
    uint16_t VALUE16;
  };
} ADI_UART_COMFBR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_COMFBR_t__ */

/*@}*/

/** @defgroup COMDIV Baudrate divider (COMDIV) Register
 *  Baudrate divider (COMDIV) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_COMDIV_Struct
 *! \brief  Baudrate divider Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_COMDIV_t__
typedef struct _ADI_UART_COMDIV_t {
  union {
    struct {
      int16_t DIV        : 16;  /**< Baud rate divider */
    };
    int16_t VALUE16;
  };
} ADI_UART_COMDIV_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_COMDIV_t__ */

/*@}*/

/** @defgroup COMLCR2 second Line Control (COMLCR2) Register
 *  second Line Control (COMLCR2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_COMLCR2_Struct
 *! \brief  second Line Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_COMLCR2_t__
typedef struct _ADI_UART_COMLCR2_t {
  union {
    struct {
      uint16_t OSR        :  2;  /**< Over Sample Rate */
      uint16_t reserved2  : 14;
    };
    uint16_t VALUE16;
  };
} ADI_UART_COMLCR2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_COMLCR2_t__ */

/*@}*/

/** @defgroup COMCTL UART control register (COMCTL) Register
 *  UART control register (COMCTL) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_UART_COMCTL_RXINV
 *! \brief  invert receiver line (RXINV) Enumerations
 *  ========================================================================= */
typedef enum
{
  UART_COMCTL_EN000 = 0,  /**< don't invert receiver line (idling high) */
  UART_COMCTL_EN001 = 1   /**< invert receiver line (idling low)        */
} ADI_UART_COMCTL_RXINV;


/* ==========================================================================
 *! \struct ADI_UART_COMCTL_Struct
 *! \brief  UART control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_COMCTL_t__
typedef struct _ADI_UART_COMCTL_t {
  union {
    struct {
      uint16_t reserved0  :  1;
      uint16_t ForceClkOn :  1;  /**< Force UCLKg on */
      uint16_t reserved2  :  2;
      uint16_t RXINV      :  1;  /**< invert receiver line */
      uint16_t reserved5  :  3;
      uint16_t REV        :  8;  /**< UART revision ID */
    };
    uint16_t VALUE16;
  };
} ADI_UART_COMCTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_COMCTL_t__ */

/*@}*/

/** @defgroup COMRFC RX FIFO byte count (COMRFC) Register
 *  RX FIFO byte count (COMRFC) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_COMRFC_Struct
 *! \brief  RX FIFO byte count Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_COMRFC_t__
typedef struct _ADI_UART_COMRFC_t {
  union {
    struct {
      uint16_t RFC        :  5;  /**< Current RX FIFO data bytes */
      uint16_t reserved5  : 11;
    };
    uint16_t VALUE16;
  };
} ADI_UART_COMRFC_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_COMRFC_t__ */

/*@}*/

/** @defgroup COMTFC TX FIFO byte count (COMTFC) Register
 *  TX FIFO byte count (COMTFC) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_COMTFC_Struct
 *! \brief  TX FIFO byte count Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_COMTFC_t__
typedef struct _ADI_UART_COMTFC_t {
  union {
    struct {
      uint16_t TFC        :  5;  /**< Current TX FIFO data bytes */
      uint16_t reserved5  : 11;
    };
    uint16_t VALUE16;
  };
} ADI_UART_COMTFC_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_COMTFC_t__ */

/*@}*/

/** @defgroup COMRSC RS485 half-duplex Control (COMRSC) Register
 *  RS485 half-duplex Control (COMRSC) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_COMRSC_Struct
 *! \brief  RS485 half-duplex Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_COMRSC_t__
typedef struct _ADI_UART_COMRSC_t {
  union {
    struct {
      uint16_t OENP       :  1;  /**< SOUT_EN polarity */
      uint16_t OENSP      :  1;  /**< SOUT_EN de-assert before full stop bit(s) */
      uint16_t DISRX      :  1;  /**< disable RX when transmitting */
      uint16_t DISTX      :  1;  /**< Hold off TX when receiving */
      uint16_t reserved4  : 12;
    };
    uint16_t VALUE16;
  };
} ADI_UART_COMRSC_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_COMRSC_t__ */

/*@}*/

/** @defgroup COMACR Auto Baud Control (COMACR) Register
 *  Auto Baud Control (COMACR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_COMACR_Struct
 *! \brief  Auto Baud Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_COMACR_t__
typedef struct _ADI_UART_COMACR_t {
  union {
    struct {
      uint16_t ABE        :  1;  /**< Auto Baud enable */
      uint16_t DNIEN      :  1;  /**< enable done interrupt */
      uint16_t TOIEN      :  1;  /**< enable time-out interrupt */
      uint16_t reserved3  :  1;
      uint16_t SEC        :  3;  /**< Starting Edge Count */
      uint16_t reserved7  :  1;
      uint16_t EEC        :  4;  /**< Ending Edge Count */
      uint16_t reserved12 :  4;
    };
    uint16_t VALUE16;
  };
} ADI_UART_COMACR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_COMACR_t__ */

/*@}*/

/** @defgroup COMASRL Auto Baud Status (Low) (COMASRL) Register
 *  Auto Baud Status (Low) (COMASRL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_COMASRL_Struct
 *! \brief  Auto Baud Status (Low) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_COMASRL_t__
typedef struct _ADI_UART_COMASRL_t {
  union {
    struct {
      uint16_t DONE       :  1;  /**< Auto Baud Done successfully */
      uint16_t BRKTO      :  1;  /**< Timed out due to long time break condition */
      uint16_t NSETO      :  1;  /**< Timed out due to no valid start edge found */
      uint16_t NEETO      :  1;  /**< Timed out due to no valid ending edge found */
      uint16_t CNT        : 12;  /**< CNT[11:0] Auto Baud Counter value */
    };
    uint16_t VALUE16;
  };
} ADI_UART_COMASRL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_COMASRL_t__ */

/*@}*/

/** @defgroup COMASRH Auto Baud Status (High) (COMASRH) Register
 *  Auto Baud Status (High) (COMASRH) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_UART_COMASRH_Struct
 *! \brief  Auto Baud Status (High) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_COMASRH_t__
typedef struct _ADI_UART_COMASRH_t {
  union {
    struct {
      uint16_t CNT        :  8;  /**< CNT[19:12] Auto Baud Counter value */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_UART_COMASRH_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_COMASRH_t__ */

/*@}*/

/** @defgroup STAT DMA Status (STAT) Register
 *  DMA Status (STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_STAT_Struct
 *! \brief  DMA Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_STAT_t__
typedef struct _ADI_DMA_STAT_t {
  union {
    struct {
      uint32_t MEN        :  1;  /**< Enable status of the controller */
      uint32_t reserved1  : 15;
      uint32_t CHANM1     :  5;  /**< Number of available DMA channels minus 1 */
      uint32_t reserved21 : 11;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_STAT_t__ */

/*@}*/

/** @defgroup CFG DMA Configuration (CFG) Register
 *  DMA Configuration (CFG) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_CFG_Struct
 *! \brief  DMA Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_CFG_t__
typedef struct _ADI_DMA_CFG_t {
  union {
    struct {
      uint32_t MEN        :  1;  /**< Controller enable */
      uint32_t reserved1  : 31;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_CFG_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_CFG_t__ */

/*@}*/

/** @defgroup PDBPTR DMA channel primary control data base pointer (PDBPTR) Register
 *  DMA channel primary control data base pointer (PDBPTR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_PDBPTR_Struct
 *! \brief  DMA channel primary control data base pointer Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_PDBPTR_t__
typedef struct _ADI_DMA_PDBPTR_t {
  union {
    struct {
      int32_t ADDR       : 32;  /**< Pointer to the base address of the primary data structure */
    };
    int32_t VALUE32;
  };
} ADI_DMA_PDBPTR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_PDBPTR_t__ */

/*@}*/

/** @defgroup ADBPTR DMA channel alternate control data base pointer (ADBPTR) Register
 *  DMA channel alternate control data base pointer (ADBPTR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_ADBPTR_Struct
 *! \brief  DMA channel alternate control data base pointer Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_ADBPTR_t__
typedef struct _ADI_DMA_ADBPTR_t {
  union {
    struct {
      int32_t ADDR       : 32;  /**< Base address of the alternate data structure */
    };
    int32_t VALUE32;
  };
} ADI_DMA_ADBPTR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_ADBPTR_t__ */

/*@}*/

/** @defgroup SWREQ DMA channel software request (SWREQ) Register
 *  DMA channel software request (SWREQ) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_SWREQ_Struct
 *! \brief  DMA channel software request Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_SWREQ_t__
typedef struct _ADI_DMA_SWREQ_t {
  union {
    struct {
      uint32_t CHAN       : 24;  /**< Generate software request */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_SWREQ_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_SWREQ_t__ */

/*@}*/

/** @defgroup RMSK_SET DMA channel request mask set (RMSK_SET) Register
 *  DMA channel request mask set (RMSK_SET) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_RMSK_SET_Struct
 *! \brief  DMA channel request mask set Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_RMSK_SET_t__
typedef struct _ADI_DMA_RMSK_SET_t {
  union {
    struct {
      uint32_t CHAN       : 24;  /**< Mask requests from DMA channels */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_RMSK_SET_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_RMSK_SET_t__ */

/*@}*/

/** @defgroup RMSK_CLR DMA channel request mask clear (RMSK_CLR) Register
 *  DMA channel request mask clear (RMSK_CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_RMSK_CLR_Struct
 *! \brief  DMA channel request mask clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_RMSK_CLR_t__
typedef struct _ADI_DMA_RMSK_CLR_t {
  union {
    struct {
      uint32_t CHAN       : 24;  /**< Clear Request Mask Set bits */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_RMSK_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_RMSK_CLR_t__ */

/*@}*/

/** @defgroup EN_SET DMA channel enable set (EN_SET) Register
 *  DMA channel enable set (EN_SET) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_EN_SET_Struct
 *! \brief  DMA channel enable set Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_EN_SET_t__
typedef struct _ADI_DMA_EN_SET_t {
  union {
    struct {
      uint32_t CHAN       : 24;  /**< Enable DMA channels */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_EN_SET_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_EN_SET_t__ */

/*@}*/

/** @defgroup EN_CLR DMA channel enable clear (EN_CLR) Register
 *  DMA channel enable clear (EN_CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_EN_CLR_Struct
 *! \brief  DMA channel enable clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_EN_CLR_t__
typedef struct _ADI_DMA_EN_CLR_t {
  union {
    struct {
      uint32_t CHAN       : 24;  /**< Disable DMA channels */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_EN_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_EN_CLR_t__ */

/*@}*/

/** @defgroup ALT_SET DMA channel primary-alternate set (ALT_SET) Register
 *  DMA channel primary-alternate set (ALT_SET) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_ALT_SET_Struct
 *! \brief  DMA channel primary-alternate set Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_ALT_SET_t__
typedef struct _ADI_DMA_ALT_SET_t {
  union {
    struct {
      uint32_t CHAN       : 24;  /**< Control struct status / select alt struct */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_ALT_SET_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_ALT_SET_t__ */

/*@}*/

/** @defgroup ALT_CLR DMA channel primary-alternate clear (ALT_CLR) Register
 *  DMA channel primary-alternate clear (ALT_CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_ALT_CLR_Struct
 *! \brief  DMA channel primary-alternate clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_ALT_CLR_t__
typedef struct _ADI_DMA_ALT_CLR_t {
  union {
    struct {
      uint32_t CHAN       : 24;  /**< Select primary data struct */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_ALT_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_ALT_CLR_t__ */

/*@}*/

/** @defgroup PRI_SET DMA channel priority set (PRI_SET) Register
 *  DMA channel priority set (PRI_SET) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_PRI_SET_Struct
 *! \brief  DMA channel priority set Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_PRI_SET_t__
typedef struct _ADI_DMA_PRI_SET_t {
  union {
    struct {
      uint32_t CHAN       : 24;  /**< Configure channel for high priority */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_PRI_SET_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_PRI_SET_t__ */

/*@}*/

/** @defgroup PRI_CLR DMA channel priority clear (PRI_CLR) Register
 *  DMA channel priority clear (PRI_CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_PRI_CLR_Struct
 *! \brief  DMA channel priority clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_PRI_CLR_t__
typedef struct _ADI_DMA_PRI_CLR_t {
  union {
    struct {
      uint32_t CHPRICLR   : 24;  /**< Configure channel for default priority level */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_PRI_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_PRI_CLR_t__ */

/*@}*/

/** @defgroup ERRCHNL_CLR DMA Per Channel Error Clear (ERRCHNL_CLR) Register
 *  DMA Per Channel Error Clear (ERRCHNL_CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_ERRCHNL_CLR_Struct
 *! \brief  DMA Per Channel Error Clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_ERRCHNL_CLR_t__
typedef struct _ADI_DMA_ERRCHNL_CLR_t {
  union {
    struct {
      uint32_t CHAN       : 24;  /**< Per channel Bus error status/ Per channel bus error clear */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_ERRCHNL_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_ERRCHNL_CLR_t__ */

/*@}*/

/** @defgroup ERR_CLR DMA bus error clear (ERR_CLR) Register
 *  DMA bus error clear (ERR_CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_ERR_CLR_Struct
 *! \brief  DMA bus error clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_ERR_CLR_t__
typedef struct _ADI_DMA_ERR_CLR_t {
  union {
    struct {
      uint32_t CHAN       : 24;  /**< Bus error status */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_ERR_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_ERR_CLR_t__ */

/*@}*/

/** @defgroup INVALIDDESC_CLR DMA Per Channel Invalid Descriptor Clear (INVALIDDESC_CLR) Register
 *  DMA Per Channel Invalid Descriptor Clear (INVALIDDESC_CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_INVALIDDESC_CLR_Struct
 *! \brief  DMA Per Channel Invalid Descriptor Clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_INVALIDDESC_CLR_t__
typedef struct _ADI_DMA_INVALIDDESC_CLR_t {
  union {
    struct {
      uint32_t CHAN       : 24;  /**< Per channel Invalid Descriptor status/ Per channel Invalid descriptor status clear */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_INVALIDDESC_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_INVALIDDESC_CLR_t__ */

/*@}*/

/** @defgroup BS_SET DMA channel bytes swap enable set (BS_SET) Register
 *  DMA channel bytes swap enable set (BS_SET) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_BS_SET_Struct
 *! \brief  DMA channel bytes swap enable set Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_BS_SET_t__
typedef struct _ADI_DMA_BS_SET_t {
  union {
    struct {
      uint32_t CHAN       : 24;  /**< Byte swap status */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_BS_SET_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_BS_SET_t__ */

/*@}*/

/** @defgroup BS_CLR DMA channel bytes swap enable clear (BS_CLR) Register
 *  DMA channel bytes swap enable clear (BS_CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_BS_CLR_Struct
 *! \brief  DMA channel bytes swap enable clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_BS_CLR_t__
typedef struct _ADI_DMA_BS_CLR_t {
  union {
    struct {
      uint32_t CHAN       : 24;  /**< Disable byte swap */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_BS_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_BS_CLR_t__ */

/*@}*/

/** @defgroup SRCADDR_SET DMA channel source address decrement enable set (SRCADDR_SET) Register
 *  DMA channel source address decrement enable set (SRCADDR_SET) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_SRCADDR_SET_Struct
 *! \brief  DMA channel source address decrement enable set Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_SRCADDR_SET_t__
typedef struct _ADI_DMA_SRCADDR_SET_t {
  union {
    struct {
      uint32_t CHAN       : 24;  /**< Source Address decrement status / configure Source address decrement */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_SRCADDR_SET_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_SRCADDR_SET_t__ */

/*@}*/

/** @defgroup SRCADDR_CLR DMA channel source address decrement enable clear (SRCADDR_CLR) Register
 *  DMA channel source address decrement enable clear (SRCADDR_CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_SRCADDR_CLR_Struct
 *! \brief  DMA channel source address decrement enable clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_SRCADDR_CLR_t__
typedef struct _ADI_DMA_SRCADDR_CLR_t {
  union {
    struct {
      uint32_t CHAN       : 24;  /**< Disable source address decrement */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_SRCADDR_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_SRCADDR_CLR_t__ */

/*@}*/

/** @defgroup DSTADDR_SET DMA channel destination address decrement enable set (DSTADDR_SET) Register
 *  DMA channel destination address decrement enable set (DSTADDR_SET) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_DSTADDR_SET_Struct
 *! \brief  DMA channel destination address decrement enable set Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_DSTADDR_SET_t__
typedef struct _ADI_DMA_DSTADDR_SET_t {
  union {
    struct {
      uint32_t CHAN       : 24;  /**< Destination Address decrement status / configure destination address decrement */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_DSTADDR_SET_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_DSTADDR_SET_t__ */

/*@}*/

/** @defgroup DSTADDR_CLR DMA channel destination address decrement enable clear (DSTADDR_CLR) Register
 *  DMA channel destination address decrement enable clear (DSTADDR_CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_DSTADDR_CLR_Struct
 *! \brief  DMA channel destination address decrement enable clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_DSTADDR_CLR_t__
typedef struct _ADI_DMA_DSTADDR_CLR_t {
  union {
    struct {
      uint32_t CHAN       : 24;  /**< Disable destination address decrement */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_DSTADDR_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_DSTADDR_CLR_t__ */

/*@}*/

/** @defgroup REVID DMA Controller Revision ID (REVID) Register
 *  DMA Controller Revision ID (REVID) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_DMA_REVID_Struct
 *! \brief  DMA Controller Revision ID Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_REVID_t__
typedef struct _ADI_DMA_REVID_t {
  union {
    struct {
      uint32_t VALUE      :  8;  /**< DMA Controller revision ID */
      uint32_t reserved8  : 24;
    };
    uint32_t VALUE32;
  };
} ADI_DMA_REVID_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_REVID_t__ */

/*@}*/

/** @defgroup STAT Status (STAT) Register
 *  Status (STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_STAT_Struct
 *! \brief  Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_STAT_t__
typedef struct _ADI_FLCC_STAT_t {
  union {
    struct {
      uint32_t CMDBUSY    :  1;  /**< Command busy */
      uint32_t WRCLOSE    :  1;  /**< WRITE registers are closed */
      uint32_t CMDCOMP    :  1;  /**< Command complete */
      uint32_t WRALCOMP   :  1;  /**< Write almost complete */
      uint32_t CMDFAIL    :  2;  /**< Provides information on command failures */
      uint32_t SLEEPING   :  1;  /**< Flash array is in low power (sleep) mode */
      uint32_t ECCERRCMD  :  2;  /**< ECC errors detected during user issued SIGN command */
      uint32_t ECCRDERR   :  2;  /**< ECC IRQ cause */
      uint32_t OVERLAP    :  1;  /**< Overlapping Command */
      uint32_t reserved12 :  1;
      uint32_t SIGNERR    :  1;  /**< Signature check failure during initialization */
      uint32_t INIT       :  1;  /**< Flash controller initialization in progress */
      uint32_t ECCINFOSIGN :  2;  /**< ECC status of flash initialization */
      uint32_t ECCERRCNT   :  3;  /**< ECC correction counter */
      uint32_t reserved20  :  5;
      uint32_t ECCICODE    :  2;  /**< ICode AHB Bus Error ECC status */
      uint32_t ECCDCODE    :  2;  /**< DCode AHB Bus Error ECC status */
      uint32_t CACHESRAMPERR :  1;  /**< SRAM parity errors in Cache Controller */
      uint32_t reserved30    :  2;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_STAT_t__ */

/*@}*/

/** @defgroup IEN Interrupt Enable (IEN) Register
 *  Interrupt Enable (IEN) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_FLCC_IEN_ECC_CORRECT
 *! \brief  Control whether to generate bus errors, interrupts, or neither in response to 1-bit ECC Correction events (ECC_CORRECT) Enumerations
 *  ========================================================================= */
typedef enum
{
  FLCC_IEN_NONE_COR    = 0,  /**< Do not generate a response to ECC events      */
  FLCC_IEN_BUS_ERR_COR = 1,  /**< Generate Bus Errors in response to ECC events */
  FLCC_IEN_IRQ_COR     = 2   /**< Generate IRQs in response to ECC events       */
} ADI_FLCC_IEN_ECC_CORRECT;


/*  =========================================================================
 *! \enum   ADI_FLCC_IEN_ECC_ERROR
 *! \brief  Control whether to generate bus errors, interrupts, or neither in response to 2-bit ECC Error events (ECC_ERROR) Enumerations
 *  ========================================================================= */
typedef enum
{
  FLCC_IEN_NONE_ERR    = 0,  /**< Do not generate a response to ECC events      */
  FLCC_IEN_BUS_ERR_ERR = 1,  /**< Generate Bus Errors in response to ECC events */
  FLCC_IEN_IRQ_ERR     = 2   /**< Generate IRQs in response to ECC events       */
} ADI_FLCC_IEN_ECC_ERROR;


/* ==========================================================================
 *! \struct ADI_FLCC_IEN_Struct
 *! \brief  Interrupt Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_IEN_t__
typedef struct _ADI_FLCC_IEN_t {
  union {
    struct {
      uint32_t CMDCMPLT   :  1;  /**< Command complete interrupt enable */
      uint32_t WRALCMPLT  :  1;  /**< Write almost complete interrupt enable */
      uint32_t CMDFAIL    :  1;  /**< Command fail interrupt enable */
      uint32_t reserved3   :  1;
      uint32_t ECC_CORRECT :  2;  /**< Control whether to generate bus errors, interrupts, or neither in response to 1-bit ECC Correction events */
      uint32_t ECC_ERROR   :  2;  /**< Control whether to generate bus errors, interrupts, or neither in response to 2-bit ECC Error events */
      uint32_t reserved8   : 24;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_IEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_IEN_t__ */

/*@}*/

/** @defgroup CMD Command (CMD) Register
 *  Command (CMD) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_FLCC_CMD_VALUE
 *! \brief  Commands (VALUE) Enumerations
 *  ========================================================================= */
typedef enum
{
  FLCC_CMD_IDLE        = 0,  /**< IDLE                                                                  */
  FLCC_CMD_ABORT       = 1,  /**< ABORT                                                                 */
  FLCC_CMD_SLEEP       = 2,  /**< Requests flash to enter Sleep mode                                    */
  FLCC_CMD_SIGN        = 3,  /**< SIGN                                                                  */
  FLCC_CMD_WRITE       = 4,  /**< WRITE                                                                 */
  FLCC_CMD_BLANK_CHECK = 5,  /**< Checks all of User Space; fails if any bits in user space are cleared */
  FLCC_CMD_ERASEPAGE   = 6,  /**< ERASEPAGE                                                             */
  FLCC_CMD_MASSERASE   = 7   /**< MASSERASE                                                             */
} ADI_FLCC_CMD_VALUE;


/* ==========================================================================
 *! \struct ADI_FLCC_CMD_Struct
 *! \brief  Command Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_CMD_t__
typedef struct _ADI_FLCC_CMD_t {
  union {
    struct {
      uint32_t VALUE      :  4;  /**< Commands */
      uint32_t reserved4  : 28;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_CMD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_CMD_t__ */

/*@}*/

/** @defgroup KH_ADDR WRITE Address (KH_ADDR) Register
 *  WRITE Address (KH_ADDR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_KH_ADDR_Struct
 *! \brief  WRITE Address Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_KH_ADDR_t__
typedef struct _ADI_FLCC_KH_ADDR_t {
  union {
    struct {
      uint32_t reserved0  :  3;
      uint32_t VALUE      : 16;  /**< Address to be written on a WRITE command */
      uint32_t reserved19 : 13;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_KH_ADDR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_KH_ADDR_t__ */

/*@}*/

/** @defgroup KH_DATA0 WRITE Lower Data (KH_DATA0) Register
 *  WRITE Lower Data (KH_DATA0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_KH_DATA0_Struct
 *! \brief  WRITE Lower Data Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_KH_DATA0_t__
typedef struct _ADI_FLCC_KH_DATA0_t {
  union {
    struct {
      int32_t VALUE      : 32;  /**< Lower half of 64-bit dual word data to be written on a WRITE command */
    };
    int32_t VALUE32;
  };
} ADI_FLCC_KH_DATA0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_KH_DATA0_t__ */

/*@}*/

/** @defgroup KH_DATA1 WRITE Upper Data (KH_DATA1) Register
 *  WRITE Upper Data (KH_DATA1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_KH_DATA1_Struct
 *! \brief  WRITE Upper Data Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_KH_DATA1_t__
typedef struct _ADI_FLCC_KH_DATA1_t {
  union {
    struct {
      int32_t VALUE      : 32;  /**< Upper half of 64-bit dual word data to be written on a WRITE command */
    };
    int32_t VALUE32;
  };
} ADI_FLCC_KH_DATA1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_KH_DATA1_t__ */

/*@}*/

/** @defgroup PAGE_ADDR0 Lower Page Address (PAGE_ADDR0) Register
 *  Lower Page Address (PAGE_ADDR0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_PAGE_ADDR0_Struct
 *! \brief  Lower Page Address Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_PAGE_ADDR0_t__
typedef struct _ADI_FLCC_PAGE_ADDR0_t {
  union {
    struct {
      uint32_t reserved0  : 10;
      uint32_t VALUE      :  9;  /**< Lower address bits of the page address */
      uint32_t reserved19 : 13;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_PAGE_ADDR0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_PAGE_ADDR0_t__ */

/*@}*/

/** @defgroup PAGE_ADDR1 Upper Page Address (PAGE_ADDR1) Register
 *  Upper Page Address (PAGE_ADDR1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_PAGE_ADDR1_Struct
 *! \brief  Upper Page Address Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_PAGE_ADDR1_t__
typedef struct _ADI_FLCC_PAGE_ADDR1_t {
  union {
    struct {
      uint32_t reserved0  : 10;
      uint32_t VALUE      :  9;  /**< Upper address bits of the page address */
      uint32_t reserved19 : 13;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_PAGE_ADDR1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_PAGE_ADDR1_t__ */

/*@}*/

/** @defgroup KEY Key (KEY) Register
 *  Key (KEY) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_FLCC_KEY_VALUE
 *! \brief  Key register (VALUE) Enumerations
 *  ========================================================================= */
typedef enum
{
  FLCC_KEY_USERKEY = 1735161189   /**< USERKEY */
} ADI_FLCC_KEY_VALUE;


/* ==========================================================================
 *! \struct ADI_FLCC_KEY_Struct
 *! \brief  Key Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_KEY_t__
typedef struct _ADI_FLCC_KEY_t {
  union {
    struct {
      int32_t VALUE      : 32;  /**< Key register */
    };
    int32_t VALUE32;
  };
} ADI_FLCC_KEY_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_KEY_t__ */

/*@}*/

/** @defgroup WR_ABORT_ADDR Write Abort Address (WR_ABORT_ADDR) Register
 *  Write Abort Address (WR_ABORT_ADDR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_WR_ABORT_ADDR_Struct
 *! \brief  Write Abort Address Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_WR_ABORT_ADDR_t__
typedef struct _ADI_FLCC_WR_ABORT_ADDR_t {
  union {
    struct {
      int32_t VALUE      : 32;  /**< Holds the address targeted by an ongoing write command and retains its value after an ABORT event */
    };
    int32_t VALUE32;
  };
} ADI_FLCC_WR_ABORT_ADDR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_WR_ABORT_ADDR_t__ */

/*@}*/

/** @defgroup WRPROT Write Protection (WRPROT) Register
 *  Write Protection (WRPROT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_WRPROT_Struct
 *! \brief  Write Protection Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_WRPROT_t__
typedef struct _ADI_FLCC_WRPROT_t {
  union {
    struct {
      int32_t WORD       : 32;  /**< Clear bits to write protect related groups of user space pages. Once cleared these bits can only be set again by resetting the part */
    };
    int32_t VALUE32;
  };
} ADI_FLCC_WRPROT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_WRPROT_t__ */

/*@}*/

/** @defgroup SIGNATURE Signature (SIGNATURE) Register
 *  Signature (SIGNATURE) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_SIGNATURE_Struct
 *! \brief  Signature Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_SIGNATURE_t__
typedef struct _ADI_FLCC_SIGNATURE_t {
  union {
    struct {
      int32_t VALUE      : 32;  /**< Provides read access to the most recently generated signature */
    };
    int32_t VALUE32;
  };
} ADI_FLCC_SIGNATURE_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_SIGNATURE_t__ */

/*@}*/

/** @defgroup UCFG User Configuration (UCFG) Register
 *  User Configuration (UCFG) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_UCFG_Struct
 *! \brief  User Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_UCFG_t__
typedef struct _ADI_FLCC_UCFG_t {
  union {
    struct {
      uint32_t KHDMAEN    :  1;  /**< Key Hole DMA enable */
      uint32_t AUTOINCEN  :  1;  /**< Auto address increment for Key hole access */
      uint32_t reserved2  : 30;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_UCFG_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_UCFG_t__ */

/*@}*/

/** @defgroup TIME_PARAM0 Time Parameter 0 (TIME_PARAM0) Register
 *  Time Parameter 0 (TIME_PARAM0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_TIME_PARAM0_Struct
 *! \brief  Time Parameter 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_TIME_PARAM0_t__
typedef struct _ADI_FLCC_TIME_PARAM0_t {
  union {
    struct {
      uint32_t DIVREFCLK  :  1;  /**< Divide Reference Clock (by 2) */
      uint32_t reserved1  :  3;
      uint32_t TNVS       :  4;  /**< PROG/ERASE to NVSTR setup time */
      uint32_t TPGS       :  4;  /**< NVSTR to Program setup time */
      uint32_t TPROG      :  4;  /**< Program time */
      uint32_t TNVH       :  4;  /**< NVSTR Hold time */
      uint32_t TRCV       :  4;  /**< Recovery time */
      uint32_t TERASE     :  4;  /**< Erase Time */
      uint32_t TNVH1      :  4;  /**< NVSTR Hold time during Mass Erase */
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_TIME_PARAM0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_TIME_PARAM0_t__ */

/*@}*/

/** @defgroup TIME_PARAM1 Time parameter 1 (TIME_PARAM1) Register
 *  Time parameter 1 (TIME_PARAM1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_TIME_PARAM1_Struct
 *! \brief  Time parameter 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_TIME_PARAM1_t__
typedef struct _ADI_FLCC_TIME_PARAM1_t {
  union {
    struct {
      uint32_t TWK        :  4;  /**< Wake up time */
      uint32_t reserved4  : 28;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_TIME_PARAM1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_TIME_PARAM1_t__ */

/*@}*/

/** @defgroup ABORT_EN_LO IRQ Abort Enable (lower bits) (ABORT_EN_LO) Register
 *  IRQ Abort Enable (lower bits) (ABORT_EN_LO) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_ABORT_EN_LO_Struct
 *! \brief  IRQ Abort Enable (lower bits) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_ABORT_EN_LO_t__
typedef struct _ADI_FLCC_ABORT_EN_LO_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< VALUE[31:0] Sys IRQ abort enable */
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_ABORT_EN_LO_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_ABORT_EN_LO_t__ */

/*@}*/

/** @defgroup ABORT_EN_HI IRQ Abort Enable (upper bits) (ABORT_EN_HI) Register
 *  IRQ Abort Enable (upper bits) (ABORT_EN_HI) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_ABORT_EN_HI_Struct
 *! \brief  IRQ Abort Enable (upper bits) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_ABORT_EN_HI_t__
typedef struct _ADI_FLCC_ABORT_EN_HI_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< VALUE[63:32] Sys IRQ abort enable */
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_ABORT_EN_HI_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_ABORT_EN_HI_t__ */

/*@}*/

/** @defgroup ECC_CFG ECC Config (ECC_CFG) Register
 *  ECC Config (ECC_CFG) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_ECC_CFG_Struct
 *! \brief  ECC Config Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_ECC_CFG_t__
typedef struct _ADI_FLCC_ECC_CFG_t {
  union {
    struct {
      uint32_t EN         :  1;  /**< ECC Enable */
      uint32_t INFOEN     :  1;  /**< Info space ECC Enable bit */
      uint32_t reserved2  :  6;
      uint32_t PTR        : 24;  /**< ECC start page pointer (user should write bits [31:8] of the start page address into bits [31:8] of this register) */
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_ECC_CFG_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_ECC_CFG_t__ */

/*@}*/

/** @defgroup ECC_ADDR ECC Status (Address) (ECC_ADDR) Register
 *  ECC Status (Address) (ECC_ADDR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_ECC_ADDR_Struct
 *! \brief  ECC Status (Address) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_ECC_ADDR_t__
typedef struct _ADI_FLCC_ECC_ADDR_t {
  union {
    struct {
      uint32_t VALUE      : 19;  /**< This register has the address for which ECC error is detected */
      uint32_t reserved19 : 13;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_ECC_ADDR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_ECC_ADDR_t__ */

/*@}*/

/** @defgroup ADI_POR_SEC ADI flash security (ADI_POR_SEC) Register
 *  ADI flash security (ADI_POR_SEC) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_ADI_POR_SEC_Struct
 *! \brief  ADI flash security Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_ADI_POR_SEC_t__
typedef struct _ADI_FLCC_ADI_POR_SEC_t {
  union {
    struct {
      uint32_t SECURE     :  1;  /**< Set this bit to prevent read or write access to User Space (sticky when set) */
      uint32_t reserved1  : 31;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_ADI_POR_SEC_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_ADI_POR_SEC_t__ */

/*@}*/

/** @defgroup STAT Cache Status register (STAT) Register
 *  Cache Status register (STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_CACHE_STAT_Struct
 *! \brief  Cache Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_CACHE_STAT_t__
typedef struct _ADI_FLCC_CACHE_STAT_t {
  union {
    struct {
      uint32_t ICEN       :  1;  /**< If this bit is set then I-Cache is enabled and when cleared I-Cache is disabled. */
      uint32_t reserved1  : 31;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_CACHE_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_CACHE_STAT_t__ */

/*@}*/

/** @defgroup SETUP Cache Setup register (SETUP) Register
 *  Cache Setup register (SETUP) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_CACHE_SETUP_Struct
 *! \brief  Cache Setup Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_CACHE_SETUP_t__
typedef struct _ADI_FLCC_CACHE_SETUP_t {
  union {
    struct {
      uint32_t ICEN       :  1;  /**< If this bit set, then I-Cache is enabled for AHB accesses. If 0, then I-cache is disabled, and all AHB accesses will be via Flash memory. */
      uint32_t reserved1  : 31;
    };
    uint32_t VALUE32;
  };
} ADI_FLCC_CACHE_SETUP_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_CACHE_SETUP_t__ */

/*@}*/

/** @defgroup KEY Cache Key register (KEY) Register
 *  Cache Key register (KEY) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_FLCC_CACHE_KEY_Struct
 *! \brief  Cache Key Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_CACHE_KEY_t__
typedef struct _ADI_FLCC_CACHE_KEY_t {
  union {
    struct {
      int32_t VALUE      : 32;  /**< Cache Key register */
    };
    int32_t VALUE32;
  };
} ADI_FLCC_CACHE_KEY_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_CACHE_KEY_t__ */

/*@}*/

/** @defgroup CFG Port  Configuration (CFG) Register
 *  Port  Configuration (CFG) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_CFG_Struct
 *! \brief  Port  Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_CFG_t__
typedef struct _ADI_GPIO_CFG_t {
  union {
    struct {
      uint32_t PIN00      :  2;  /**< Pin 0 configuration bits */
      uint32_t PIN01      :  2;  /**< Pin 1 configuration bits */
      uint32_t PIN02      :  2;  /**< Pin 2 configuration bits */
      uint32_t PIN03      :  2;  /**< Pin 3 configuration bits */
      uint32_t PIN04      :  2;  /**< Pin 4 configuration bits */
      uint32_t PIN05      :  2;  /**< Pin 5 configuration bits */
      uint32_t PIN06      :  2;  /**< Pin 6 configuration bits */
      uint32_t PIN07      :  2;  /**< Pin 7 configuration bits */
      uint32_t PIN08      :  2;  /**< Pin 8 configuration bits */
      uint32_t PIN09      :  2;  /**< Pin 9 configuration bits */
      uint32_t PIN10      :  2;  /**< Pin 10  configuration bits */
      uint32_t PIN11      :  2;  /**< Pin 11  configuration bits */
      uint32_t PIN12      :  2;  /**< Pin 12  configuration bits */
      uint32_t PIN13      :  2;  /**< Pin 13  configuration bits */
      uint32_t PIN14      :  2;  /**< Pin 14  configuration bits */
      uint32_t PIN15      :  2;  /**< Pin 15  configuration bits */
    };
    uint32_t VALUE32;
  };
} ADI_GPIO_CFG_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_CFG_t__ */

/*@}*/

/** @defgroup OEN Port output enable (OEN) Register
 *  Port output enable (OEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_OEN_Struct
 *! \brief  Port output enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_OEN_t__
typedef struct _ADI_GPIO_OEN_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Pin Output Drive enable */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_OEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_OEN_t__ */

/*@}*/

/** @defgroup PE Port output pullup/pulldown enable (PE) Register
 *  Port output pullup/pulldown enable (PE) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_PE_Struct
 *! \brief  Port output pullup/pulldown enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_PE_t__
typedef struct _ADI_GPIO_PE_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Pin Pull enable */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_PE_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_PE_t__ */

/*@}*/

/** @defgroup IEN Port  Input Path Enable (IEN) Register
 *  Port  Input Path Enable (IEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_IEN_Struct
 *! \brief  Port  Input Path Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_IEN_t__
typedef struct _ADI_GPIO_IEN_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Input path enable */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_IEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_IEN_t__ */

/*@}*/

/** @defgroup IN Port  registered data input (IN) Register
 *  Port  registered data input (IN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_IN_Struct
 *! \brief  Port  registered data input Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_IN_t__
typedef struct _ADI_GPIO_IN_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Registered data input */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_IN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_IN_t__ */

/*@}*/

/** @defgroup OUT Port data output (OUT) Register
 *  Port data output (OUT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_OUT_Struct
 *! \brief  Port data output Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_OUT_t__
typedef struct _ADI_GPIO_OUT_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Data out */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_OUT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_OUT_t__ */

/*@}*/

/** @defgroup SET Port data out set (SET) Register
 *  Port data out set (SET) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_SET_Struct
 *! \brief  Port data out set Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_SET_t__
typedef struct _ADI_GPIO_SET_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Set the output HIGH for the pin */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_SET_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_SET_t__ */

/*@}*/

/** @defgroup CLR Port Data Out Clear (CLR) Register
 *  Port Data Out Clear (CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_CLR_Struct
 *! \brief  Port Data Out Clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_CLR_t__
typedef struct _ADI_GPIO_CLR_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Set the output low  for the port pin */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_CLR_t__ */

/*@}*/

/** @defgroup TGL Port Pin Toggle (TGL) Register
 *  Port Pin Toggle (TGL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_TGL_Struct
 *! \brief  Port Pin Toggle Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_TGL_t__
typedef struct _ADI_GPIO_TGL_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Toggle the output of the port pin */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_TGL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_TGL_t__ */

/*@}*/

/** @defgroup POL Port Interrupt Polarity (POL) Register
 *  Port Interrupt Polarity (POL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_POL_Struct
 *! \brief  Port Interrupt Polarity Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_POL_t__
typedef struct _ADI_GPIO_POL_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Interrupt polarity */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_POL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_POL_t__ */

/*@}*/

/** @defgroup IENA Port Interrupt A Enable (IENA) Register
 *  Port Interrupt A Enable (IENA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_IENA_Struct
 *! \brief  Port Interrupt A Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_IENA_t__
typedef struct _ADI_GPIO_IENA_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Interrupt A enable */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_IENA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_IENA_t__ */

/*@}*/

/** @defgroup IENB Port Interrupt B Enable (IENB) Register
 *  Port Interrupt B Enable (IENB) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_IENB_Struct
 *! \brief  Port Interrupt B Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_IENB_t__
typedef struct _ADI_GPIO_IENB_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Interrupt B enable */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_IENB_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_IENB_t__ */

/*@}*/

/** @defgroup INT Port Interrupt Status (INT) Register
 *  Port Interrupt Status (INT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_INT_Struct
 *! \brief  Port Interrupt Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_INT_t__
typedef struct _ADI_GPIO_INT_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Interrupt Status */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_INT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_INT_t__ */

/*@}*/

/** @defgroup DS Port Drive Strength Select (DS) Register
 *  Port Drive Strength Select (DS) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_GPIO_DS_Struct
 *! \brief  Port Drive Strength Select Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_DS_t__
typedef struct _ADI_GPIO_DS_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Drive strength select */
    };
    uint16_t VALUE16;
  };
} ADI_GPIO_DS_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_DS_t__ */

/*@}*/

/** @defgroup CTL CRC Control Register (CTL) Register
 *  CRC Control Register (CTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRC_CTL_Struct
 *! \brief  CRC Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRC_CTL_t__
typedef struct _ADI_CRC_CTL_t {
  union {
    struct {
      uint32_t EN         :  1;  /**< CRC Peripheral Enable */
      uint32_t LSBFIRST   :  1;  /**< LSB First Calculation Order */
      uint32_t BITMIRR    :  1;  /**< Bit Mirroring */
      uint32_t BYTMIRR    :  1;  /**< Byte Mirroring */
      uint32_t W16SWP     :  1;  /**< Word16 Swap */
      uint32_t reserved5  : 23;
      uint32_t RevID      :  4;  /**< Revision ID */
    };
    uint32_t VALUE32;
  };
} ADI_CRC_CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRC_CTL_t__ */

/*@}*/

/** @defgroup IPDATA Input Data Word Register (IPDATA) Register
 *  Input Data Word Register (IPDATA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRC_IPDATA_Struct
 *! \brief  Input Data Word Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRC_IPDATA_t__
typedef struct _ADI_CRC_IPDATA_t {
  union {
    struct {
      int32_t VALUE      : 32;  /**< Data Input. */
    };
    int32_t VALUE32;
  };
} ADI_CRC_IPDATA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRC_IPDATA_t__ */

/*@}*/

/** @defgroup RESULT CRC Result Register (RESULT) Register
 *  CRC Result Register (RESULT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRC_RESULT_Struct
 *! \brief  CRC Result Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRC_RESULT_t__
typedef struct _ADI_CRC_RESULT_t {
  union {
    struct {
      int32_t VALUE      : 32;  /**< CRC Residue */
    };
    int32_t VALUE32;
  };
} ADI_CRC_RESULT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRC_RESULT_t__ */

/*@}*/

/** @defgroup POLY Programmable CRC Polynomial (POLY) Register
 *  Programmable CRC Polynomial (POLY) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRC_POLY_Struct
 *! \brief  Programmable CRC Polynomial Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRC_POLY_t__
typedef struct _ADI_CRC_POLY_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< CRC Reduction Polynomial */
    };
    uint32_t VALUE32;
  };
} ADI_CRC_POLY_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRC_POLY_t__ */

/*@}*/

/** @defgroup IPBITS Input Data Bits (IPBITS) Register
 *  Input Data Bits (IPBITS) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRC_IPBITS_Struct
 *! \brief  Input Data Bits Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRC_IPBITS_t__
typedef struct _ADI_CRC_IPBITS_t {
  union {
    struct {
      uint8_t DATA_BITS  :  8;  /**< Input Data Bits. */
    };
    uint8_t VALUE8;
  };
} ADI_CRC_IPBITS_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRC_IPBITS_t__ */

/*@}*/

/** @defgroup IPBYTE Input Data Byte (IPBYTE) Register
 *  Input Data Byte (IPBYTE) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRC_IPBYTE_Struct
 *! \brief  Input Data Byte Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRC_IPBYTE_t__
typedef struct _ADI_CRC_IPBYTE_t {
  union {
    struct {
      uint8_t DATA_BYTE  :  8;  /**< Input Data Byte. */
    };
    uint8_t VALUE8;
  };
} ADI_CRC_IPBYTE_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRC_IPBYTE_t__ */

/*@}*/

/** @defgroup CTL RNG Control Register (CTL) Register
 *  RNG Control Register (CTL) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_RNG_CTL_EN
 *! \brief  RNG Enable (EN) Enumerations
 *  ========================================================================= */
typedef enum
{
  RNG_CTL_DISABLE = 0,  /**< Disable the RNG */
  RNG_CTL_ENABLE  = 1   /**< Enable the RNG  */
} ADI_RNG_CTL_EN;


/*  =========================================================================
 *! \enum   ADI_RNG_CTL_SINGLE
 *! \brief  Generate a single number (SINGLE) Enumerations
 *  ========================================================================= */
typedef enum
{
  RNG_CTL_WORD   = 0,  /**< Buffer Word */
  RNG_CTL_SINGLE = 1   /**< Single Byte */
} ADI_RNG_CTL_SINGLE;


/* ==========================================================================
 *! \struct ADI_RNG_CTL_Struct
 *! \brief  RNG Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RNG_CTL_t__
typedef struct _ADI_RNG_CTL_t {
  union {
    struct {
      uint16_t EN         :  1;  /**< RNG Enable */
      uint16_t reserved1  :  2;
      uint16_t SINGLE     :  1;  /**< Generate a single number */
      uint16_t reserved4  : 12;
    };
    uint16_t VALUE16;
  };
} ADI_RNG_CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RNG_CTL_t__ */

/*@}*/

/** @defgroup LEN RNG Sample Length Register (LEN) Register
 *  RNG Sample Length Register (LEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RNG_LEN_Struct
 *! \brief  RNG Sample Length Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RNG_LEN_t__
typedef struct _ADI_RNG_LEN_t {
  union {
    struct {
      uint16_t RELOAD     : 12;  /**< Reload value for the sample counter */
      uint16_t PRESCALE   :  4;  /**< Prescaler for the sample counter */
    };
    uint16_t VALUE16;
  };
} ADI_RNG_LEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RNG_LEN_t__ */

/*@}*/

/** @defgroup STAT RNG Status Register (STAT) Register
 *  RNG Status Register (STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RNG_STAT_Struct
 *! \brief  RNG Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RNG_STAT_t__
typedef struct _ADI_RNG_STAT_t {
  union {
    struct {
      uint16_t RNRDY      :  1;  /**< Random number ready */
      uint16_t STUCK      :  1;  /**< Sampled data stuck high or low */
      uint16_t reserved2  : 14;
    };
    uint16_t VALUE16;
  };
} ADI_RNG_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RNG_STAT_t__ */

/*@}*/

/** @defgroup DATA RNG Data Register (DATA) Register
 *  RNG Data Register (DATA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RNG_DATA_Struct
 *! \brief  RNG Data Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RNG_DATA_t__
typedef struct _ADI_RNG_DATA_t {
  union {
    struct {
      uint32_t VALUE      :  8;  /**< Value of the CRC accumulator */
      uint32_t BUFF       : 24;  /**< Buffer for RNG data */
    };
    uint32_t VALUE32;
  };
} ADI_RNG_DATA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RNG_DATA_t__ */

/*@}*/

/** @defgroup OSCCNT Oscillator Count (OSCCNT) Register
 *  Oscillator Count (OSCCNT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RNG_OSCCNT_Struct
 *! \brief  Oscillator Count Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RNG_OSCCNT_t__
typedef struct _ADI_RNG_OSCCNT_t {
  union {
    struct {
      uint32_t VALUE      : 28;  /**< Oscillator count */
      uint32_t reserved28 :  4;
    };
    uint32_t VALUE32;
  };
} ADI_RNG_OSCCNT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RNG_OSCCNT_t__ */

/*@}*/

/** @defgroup OSCDIFF Oscillator Difference (OSCDIFF) Register
 *  Oscillator Difference (OSCDIFF) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_RNG_OSCDIFF_Struct
 *! \brief  Oscillator Difference Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RNG_OSCDIFF_t__
typedef struct _ADI_RNG_OSCDIFF_t {
  union {
    struct {
      int8_t DELTA      :  8;  /**< Oscillator Count difference */
    };
    int8_t VALUE8;
  };
} ADI_RNG_OSCDIFF_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RNG_OSCDIFF_t__ */

/*@}*/

/** @defgroup CFG Configuration Register (CFG) Register
 *  Configuration Register (CFG) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_CRYPT_CFG_BLKEN
 *! \brief  Enable BIT for the Crypto Block (BLKEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  CRYPT_CFG_ENABLE  = 0,  /**< Enable Crypto Block  */
  CRYPT_CFG_DISABLE = 1   /**< Disable Crypto Block */
} ADI_CRYPT_CFG_BLKEN;


/*  =========================================================================
 *! \enum   ADI_CRYPT_CFG_INDMAEN
 *! \brief  Enable DMA for Input Buffer (INDMAEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  CRYPT_CFG_DMA_DISABLE_INBUF = 0,  /**< Disable DMA Requesting for Input Buffer */
  CRYPT_CFG_DMA_ENABLE_INBUF  = 1   /**< Enable DMA Requesting for Input Buffer  */
} ADI_CRYPT_CFG_INDMAEN;


/*  =========================================================================
 *! \enum   ADI_CRYPT_CFG_OUTDMAEN
 *! \brief  Enable DMA for Output Buffer (OUTDMAEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  CRYPT_CFG_DMA_DISABLE_OUTBUF = 0,  /**< Disable DMA Requesting for Output Buffer */
  CRYPT_CFG_DMA_ENABLE_OUTBUF  = 1   /**< Enable DMA Requesting for Output Buffer  */
} ADI_CRYPT_CFG_OUTDMAEN;


/*  =========================================================================
 *! \enum   ADI_CRYPT_CFG_ENDIAN
 *! \brief  Endianness (ENDIAN) Enumerations
 *  ========================================================================= */
typedef enum
{
  CRYPT_CFG_LITTLE_ENDIAN = 0,  /**< Little Endian Format */
  CRYPT_CFG_BIG_ENDIAN    = 1   /**< Big Endian Format    */
} ADI_CRYPT_CFG_ENDIAN;


/*  =========================================================================
 *! \enum   ADI_CRYPT_CFG_SHADATSRC
 *! \brief  Select Data Input Source to SHA Engine (SHADATSRC) Enumerations
 *  ========================================================================= */
typedef enum
{
  CRYPT_CFG_INBUF = 0,  /**< SHA takes input from input buffer  */
  CRYPT_CFG_OPBUF = 1   /**< SHA takes input from output buffer */
} ADI_CRYPT_CFG_SHADATSRC;


/* ==========================================================================
 *! \struct ADI_CRYPT_CFG_Struct
 *! \brief  Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_CFG_t__
typedef struct _ADI_CRYPT_CFG_t {
  union {
    struct {
      uint32_t BLKEN      :  1;  /**< Enable BIT for the Crypto Block */
      uint32_t ENCR       :  1;  /**< Encrypt or Decrypt */
      uint32_t INDMAEN    :  1;  /**< Enable DMA for Input Buffer */
      uint32_t OUTDMAEN   :  1;  /**< Enable DMA for Output Buffer */
      uint32_t INFLUSH    :  1;  /**< Input Buffer Flush */
      uint32_t OUTFLUSH   :  1;  /**< Output Buffer Flush */
      uint32_t ENDIAN     :  1;  /**< Endianness */
      uint32_t reserved7  :  1;
      uint32_t KEYLEN     :  2;  /**< Select Key Length for AES Cipher */
      uint32_t reserved10 :  6;
      uint32_t ECBEN      :  1;  /**< Enable ECB Mode Operation */
      uint32_t CTREN      :  1;  /**< Enable CTR Mode Operation */
      uint32_t CBCEN      :  1;  /**< Enable CBC Mode Operation */
      uint32_t CCMEN      :  1;  /**< Enable CCM/CCM* Mode Operation */
      uint32_t CMACEN     :  1;  /**< Enable CMAC Mode Operation */
      uint32_t reserved21 :  4;
      uint32_t SHA256EN   :  1;  /**< Enable SHA-256 Operation */
      uint32_t SHAINIT    :  1;  /**< Restarts SHA Computation */
      uint32_t SHADATSRC  :  1;  /**< Select Data Input Source to SHA Engine */
      uint32_t RevID      :  4;  /**< Rev ID for Crypto on Glue Micro */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_CFG_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_CFG_t__ */

/*@}*/

/** @defgroup DATALEN Payload Data Length (DATALEN) Register
 *  Payload Data Length (DATALEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_DATALEN_Struct
 *! \brief  Payload Data Length Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_DATALEN_t__
typedef struct _ADI_CRYPT_DATALEN_t {
  union {
    struct {
      uint32_t VALUE      : 20;  /**< Length of Payload Data */
      uint32_t reserved20 : 12;
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_DATALEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_DATALEN_t__ */

/*@}*/

/** @defgroup PREFIXLEN Authentication Data Length (PREFIXLEN) Register
 *  Authentication Data Length (PREFIXLEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_PREFIXLEN_Struct
 *! \brief  Authentication Data Length Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_PREFIXLEN_t__
typedef struct _ADI_CRYPT_PREFIXLEN_t {
  union {
    struct {
      uint32_t VALUE      : 16;  /**< Length of Associated Data */
      uint32_t reserved16 : 16;
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_PREFIXLEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_PREFIXLEN_t__ */

/*@}*/

/** @defgroup INTEN Interrupt Enable Register (INTEN) Register
 *  Interrupt Enable Register (INTEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_INTEN_Struct
 *! \brief  Interrupt Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_INTEN_t__
typedef struct _ADI_CRYPT_INTEN_t {
  union {
    struct {
      uint32_t INRDYEN    :  1;  /**< Enable Input Ready Interrupt */
      uint32_t OUTRDYEN   :  1;  /**< Enables the Output Ready Interrupt. */
      uint32_t INOVREN    :  1;  /**< Enable Input Overflow Interrupt. */
      uint32_t OUTUNDREN  :  1;  /**< Enable the Output Underflow Interrupt */
      uint32_t reserved4  :  1;
      uint32_t SHADONEN   :  1;  /**< Enable SHA_Done Interrupt */
      uint32_t reserved6  : 26;
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_INTEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_INTEN_t__ */

/*@}*/

/** @defgroup STAT Status Register (STAT) Register
 *  Status Register (STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_STAT_Struct
 *! \brief  Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_STAT_t__
typedef struct _ADI_CRYPT_STAT_t {
  union {
    struct {
      uint32_t INRDY      :  1;  /**< Input Buffer Status */
      uint32_t OUTRDY     :  1;  /**< Output Data Ready */
      uint32_t INOVR      :  1;  /**< Overflow in the INPUT Buffer. */
      uint32_t OUTUNDR    :  1;  /**< Underflow Interrupt in the Output */
      uint32_t reserved4  :  1;
      uint32_t SHADONE    :  1;  /**< SHA Computation Complete */
      uint32_t SHABUSY    :  1;  /**< SHA Busy. in Computation */
      uint32_t INWORDS    :  3;  /**< Number of Words in the Input Buffer */
      uint32_t OUTWORDS   :  3;  /**< Number of Words in the Output Buffer */
      uint32_t reserved13 : 19;
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_STAT_t__ */

/*@}*/

/** @defgroup INBUF Input Buffer (INBUF) Register
 *  Input Buffer (INBUF) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_INBUF_Struct
 *! \brief  Input Buffer Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_INBUF_t__
typedef struct _ADI_CRYPT_INBUF_t {
  union {
    struct {
      int32_t VALUE      : 32;  /**< Input Buffer */
    };
    int32_t VALUE32;
  };
} ADI_CRYPT_INBUF_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_INBUF_t__ */

/*@}*/

/** @defgroup OUTBUF Output Buffer (OUTBUF) Register
 *  Output Buffer (OUTBUF) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_OUTBUF_Struct
 *! \brief  Output Buffer Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_OUTBUF_t__
typedef struct _ADI_CRYPT_OUTBUF_t {
  union {
    struct {
      int32_t VALUE      : 32;  /**< Output Buffer */
    };
    int32_t VALUE32;
  };
} ADI_CRYPT_OUTBUF_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_OUTBUF_t__ */

/*@}*/

/** @defgroup NONCE0 Nonce Bits [31:0] (NONCE0) Register
 *  Nonce Bits [31:0] (NONCE0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_NONCE0_Struct
 *! \brief  Nonce Bits [31:0] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_NONCE0_t__
typedef struct _ADI_CRYPT_NONCE0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Word 0: Nonce : Bits [31:0] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_NONCE0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_NONCE0_t__ */

/*@}*/

/** @defgroup NONCE1 Nonce Bits [63:32] (NONCE1) Register
 *  Nonce Bits [63:32] (NONCE1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_NONCE1_Struct
 *! \brief  Nonce Bits [63:32] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_NONCE1_t__
typedef struct _ADI_CRYPT_NONCE1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Word 1: Nonce : Bits [63:32] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_NONCE1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_NONCE1_t__ */

/*@}*/

/** @defgroup NONCE2 Nonce Bits [95:64] (NONCE2) Register
 *  Nonce Bits [95:64] (NONCE2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_NONCE2_Struct
 *! \brief  Nonce Bits [95:64] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_NONCE2_t__
typedef struct _ADI_CRYPT_NONCE2_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Word 2: Nonce : Bits [95:64] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_NONCE2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_NONCE2_t__ */

/*@}*/

/** @defgroup NONCE3 Nonce Bits [127:96] (NONCE3) Register
 *  Nonce Bits [127:96] (NONCE3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_NONCE3_Struct
 *! \brief  Nonce Bits [127:96] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_NONCE3_t__
typedef struct _ADI_CRYPT_NONCE3_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Word 3: Nonce : Bits [127:96] */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_NONCE3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_NONCE3_t__ */

/*@}*/

/** @defgroup AESKEY0 Key Bits[ 31:0 ] (AESKEY0) Register
 *  Key Bits[ 31:0 ] (AESKEY0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_AESKEY0_Struct
 *! \brief  Key Bits[ 31:0 ] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY0_t__
typedef struct _ADI_CRYPT_AESKEY0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Key: Bytes [3:0]; */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_AESKEY0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY0_t__ */

/*@}*/

/** @defgroup AESKEY1 Key Bits [ 63:32 ] (AESKEY1) Register
 *  Key Bits [ 63:32 ] (AESKEY1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_AESKEY1_Struct
 *! \brief  Key Bits [ 63:32 ] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY1_t__
typedef struct _ADI_CRYPT_AESKEY1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Key: Bytes [7:4]; */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_AESKEY1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY1_t__ */

/*@}*/

/** @defgroup AESKEY2 Key Bits [ 95:64 ] (AESKEY2) Register
 *  Key Bits [ 95:64 ] (AESKEY2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_AESKEY2_Struct
 *! \brief  Key Bits [ 95:64 ] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY2_t__
typedef struct _ADI_CRYPT_AESKEY2_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Key: Bytes [11:8]; */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_AESKEY2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY2_t__ */

/*@}*/

/** @defgroup AESKEY3 Key Bits [ 127:96 ] (AESKEY3) Register
 *  Key Bits [ 127:96 ] (AESKEY3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_AESKEY3_Struct
 *! \brief  Key Bits [ 127:96 ] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY3_t__
typedef struct _ADI_CRYPT_AESKEY3_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Key: Bytes [15:12]; */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_AESKEY3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY3_t__ */

/*@}*/

/** @defgroup AESKEY4 Key Bits [ 159:128 ] (AESKEY4) Register
 *  Key Bits [ 159:128 ] (AESKEY4) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_AESKEY4_Struct
 *! \brief  Key Bits [ 159:128 ] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY4_t__
typedef struct _ADI_CRYPT_AESKEY4_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Key: Bytes [3:0]; */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_AESKEY4_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY4_t__ */

/*@}*/

/** @defgroup AESKEY5 Key Bits [ 191:160 ] (AESKEY5) Register
 *  Key Bits [ 191:160 ] (AESKEY5) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_AESKEY5_Struct
 *! \brief  Key Bits [ 191:160 ] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY5_t__
typedef struct _ADI_CRYPT_AESKEY5_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Key: Bytes [7:4]; */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_AESKEY5_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY5_t__ */

/*@}*/

/** @defgroup AESKEY6 Key Bits [ 223:192 ] (AESKEY6) Register
 *  Key Bits [ 223:192 ] (AESKEY6) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_AESKEY6_Struct
 *! \brief  Key Bits [ 223:192 ] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY6_t__
typedef struct _ADI_CRYPT_AESKEY6_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Key: Bytes [11:8]; */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_AESKEY6_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY6_t__ */

/*@}*/

/** @defgroup AESKEY7 Key Bits [ 255:224 ] (AESKEY7) Register
 *  Key Bits [ 255:224 ] (AESKEY7) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_AESKEY7_Struct
 *! \brief  Key Bits [ 255:224 ] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY7_t__
typedef struct _ADI_CRYPT_AESKEY7_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Key: Bytes [15:12]; */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_AESKEY7_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_AESKEY7_t__ */

/*@}*/

/** @defgroup CNTRINIT Counter Initialization Vector (CNTRINIT) Register
 *  Counter Initialization Vector (CNTRINIT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_CNTRINIT_Struct
 *! \brief  Counter Initialization Vector Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_CNTRINIT_t__
typedef struct _ADI_CRYPT_CNTRINIT_t {
  union {
    struct {
      uint32_t VALUE      : 20;  /**< Counter Initialization Value */
      uint32_t reserved20 : 12;
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_CNTRINIT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_CNTRINIT_t__ */

/*@}*/

/** @defgroup SHAH0 SHA Bits [ 31:0 ] (SHAH0) Register
 *  SHA Bits [ 31:0 ] (SHAH0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_SHAH0_Struct
 *! \brief  SHA Bits [ 31:0 ] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH0_t__
typedef struct _ADI_CRYPT_SHAH0_t {
  union {
    struct {
      uint32_t SHAHASH0   : 32;  /**< Word 0: SHA Hash */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_SHAH0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH0_t__ */

/*@}*/

/** @defgroup SHAH1 SHA Bits [ 63:32 ] (SHAH1) Register
 *  SHA Bits [ 63:32 ] (SHAH1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_SHAH1_Struct
 *! \brief  SHA Bits [ 63:32 ] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH1_t__
typedef struct _ADI_CRYPT_SHAH1_t {
  union {
    struct {
      uint32_t SHAHASH1   : 32;  /**< Word 1: SHA Hash */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_SHAH1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH1_t__ */

/*@}*/

/** @defgroup SHAH2 SHA Bits [ 95:64 ] (SHAH2) Register
 *  SHA Bits [ 95:64 ] (SHAH2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_SHAH2_Struct
 *! \brief  SHA Bits [ 95:64 ] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH2_t__
typedef struct _ADI_CRYPT_SHAH2_t {
  union {
    struct {
      uint32_t SHAHASH2   : 32;  /**< Word 2: SHA Hash */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_SHAH2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH2_t__ */

/*@}*/

/** @defgroup SHAH3 SHA Bits [ 127:96 ] (SHAH3) Register
 *  SHA Bits [ 127:96 ] (SHAH3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_SHAH3_Struct
 *! \brief  SHA Bits [ 127:96 ] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH3_t__
typedef struct _ADI_CRYPT_SHAH3_t {
  union {
    struct {
      uint32_t SHAHASH3   : 32;  /**< Word 3: SHA Hash */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_SHAH3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH3_t__ */

/*@}*/

/** @defgroup SHAH4 SHA Bits [ 159:128 ] (SHAH4) Register
 *  SHA Bits [ 159:128 ] (SHAH4) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_SHAH4_Struct
 *! \brief  SHA Bits [ 159:128 ] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH4_t__
typedef struct _ADI_CRYPT_SHAH4_t {
  union {
    struct {
      uint32_t SHAHASH4   : 32;  /**< Word 4: SHA Hash */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_SHAH4_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH4_t__ */

/*@}*/

/** @defgroup SHAH5 SHA Bits [ 191:160 ] (SHAH5) Register
 *  SHA Bits [ 191:160 ] (SHAH5) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_SHAH5_Struct
 *! \brief  SHA Bits [ 191:160 ] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH5_t__
typedef struct _ADI_CRYPT_SHAH5_t {
  union {
    struct {
      uint32_t SHAHASH5   : 32;  /**< Word 5: SHA Hash */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_SHAH5_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH5_t__ */

/*@}*/

/** @defgroup SHAH6 SHA Bits [ 223:192] (SHAH6) Register
 *  SHA Bits [ 223:192] (SHAH6) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_SHAH6_Struct
 *! \brief  SHA Bits [ 223:192] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH6_t__
typedef struct _ADI_CRYPT_SHAH6_t {
  union {
    struct {
      uint32_t SHAHASH6   : 32;  /**< Word 6: SHA Hash */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_SHAH6_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH6_t__ */

/*@}*/

/** @defgroup SHAH7 SHA Bits [ 255:224 ] (SHAH7) Register
 *  SHA Bits [ 255:224 ] (SHAH7) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_SHAH7_Struct
 *! \brief  SHA Bits [ 255:224 ] Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH7_t__
typedef struct _ADI_CRYPT_SHAH7_t {
  union {
    struct {
      uint32_t SHAHASH7   : 32;  /**< Word 7: SHA Hash */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_SHAH7_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_SHAH7_t__ */

/*@}*/

/** @defgroup SHA_LAST_WORD SHA Last Word and Valid Bits Information (SHA_LAST_WORD) Register
 *  SHA Last Word and Valid Bits Information (SHA_LAST_WORD) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_SHA_LAST_WORD_Struct
 *! \brief  SHA Last Word and Valid Bits Information Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_SHA_LAST_WORD_t__
typedef struct _ADI_CRYPT_SHA_LAST_WORD_t {
  union {
    struct {
      uint32_t O_Last_Word :  1;  /**< Last SHA Input Word */
      uint32_t O_Bits_Valid :  5;  /**< Bits Valid in SHA Last Word Input */
      uint32_t reserved6    : 26;
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_SHA_LAST_WORD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_SHA_LAST_WORD_t__ */

/*@}*/

/** @defgroup CCM_NUM_VALID_BYTES NUM_VALID_BYTES (CCM_NUM_VALID_BYTES) Register
 *  NUM_VALID_BYTES (CCM_NUM_VALID_BYTES) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CRYPT_CCM_NUM_VALID_BYTES_Struct
 *! \brief  NUM_VALID_BYTES Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_CCM_NUM_VALID_BYTES_t__
typedef struct _ADI_CRYPT_CCM_NUM_VALID_BYTES_t {
  union {
    struct {
      uint32_t NUM_VALID_BYTES :  4;  /**< Number of Valid Bytes in CCM Last Data */
      uint32_t RESERVED_31_4   : 28;  /**< Reserved */
    };
    uint32_t VALUE32;
  };
} ADI_CRYPT_CCM_NUM_VALID_BYTES_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_CCM_NUM_VALID_BYTES_t__ */

/*@}*/

/** @defgroup IEN Power Supply Monitor Interrupt Enable (IEN) Register
 *  Power Supply Monitor Interrupt Enable (IEN) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_PMG_IEN_RANGEBAT
 *! \brief  Battery Monitor Range (RANGEBAT) Enumerations
 *  ========================================================================= */
typedef enum
{
  PMG_IEN_REGION1 = 0,  /**< Configure to generate interrupt if VBAT > 2.75V              */
  PMG_IEN_REGION2 = 1,  /**< Configure to generate interrupt if VBAT between 2.75V - 1.6V */
  PMG_IEN_REGION3 = 2,  /**< Configure to generate interrupt if VBAT between 2.3V - 1.6V  */
  PMG_IEN_NA      = 3   /**< N/A                                                          */
} ADI_PMG_IEN_RANGEBAT;


/* ==========================================================================
 *! \struct ADI_PMG_IEN_Struct
 *! \brief  Power Supply Monitor Interrupt Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_IEN_t__
typedef struct _ADI_PMG_IEN_t {
  union {
    struct {
      uint32_t VBAT       :  1;  /**< Enable Interrupt for VBAT */
      uint32_t VREGUNDR   :  1;  /**< Enable Interrupt when VREG under-voltage: below 1V */
      uint32_t VREGOVR    :  1;  /**< Enable Interrupt when VREG over-voltage: over- 1.32V */
      uint32_t reserved3  :  5;
      uint32_t RANGEBAT   :  2;  /**< Battery Monitor Range */
      uint32_t IENBAT     :  1;  /**< Interrupt enable for VBAT range */
      uint32_t reserved11 : 21;
    };
    uint32_t VALUE32;
  };
} ADI_PMG_IEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_IEN_t__ */

/*@}*/

/** @defgroup PSM_STAT Power supply monitor status (PSM_STAT) Register
 *  Power supply monitor status (PSM_STAT) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_PMG_PSM_STAT_RORANGE1
 *! \brief  VBAT range1 (> 2.75v) (RORANGE1) Enumerations
 *  ========================================================================= */
typedef enum
{
  PMG_PSM_STAT_BATSTAT1 = 0,  /**< VBAT NOT in the range specified */
  PMG_PSM_STAT_BATSTAT0 = 1   /**< VBAT in the range specified     */
} ADI_PMG_PSM_STAT_RORANGE1;


/* ==========================================================================
 *! \struct ADI_PMG_PSM_STAT_Struct
 *! \brief  Power supply monitor status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_PSM_STAT_t__
typedef struct _ADI_PMG_PSM_STAT_t {
  union {
    struct {
      uint32_t VBATUNDR   :  1;  /**< Status bit indicating an Alarm that battery is below 1.8V. */
      uint32_t VREGUNDR   :  1;  /**< Status bit for Alarm indicating VREG is below 1V. */
      uint32_t VREGOVR    :  1;  /**< Status bit for alarm indicating Overvoltage for VREG */
      uint32_t reserved3  :  4;
      uint32_t WICENACK   :  1;  /**< WIC Enable Acknowledge from Cortex */
      uint32_t RANGE1     :  1;  /**< VBAT range1 (> 2.75v) */
      uint32_t RANGE2     :  1;  /**< VBAT range2 (2.75v - 2.3v) */
      uint32_t RANGE3     :  1;  /**< VBAT range3 (2.3v - 1.6v) */
      uint32_t reserved11 :  2;
      uint32_t RORANGE1   :  1;  /**< VBAT range1 (> 2.75v) */
      uint32_t RORANGE2   :  1;  /**< VBAT range2 (2.75v - 2.3v) */
      uint32_t RORANGE3   :  1;  /**< VBAT range3 (2.3v - 1.6v) */
      uint32_t reserved16 : 16;
    };
    uint32_t VALUE32;
  };
} ADI_PMG_PSM_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_PSM_STAT_t__ */

/*@}*/

/** @defgroup PWRMOD Power Mode Register (PWRMOD) Register
 *  Power Mode Register (PWRMOD) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_PMG_PWRMOD_MODE
 *! \brief  Power Mode Bits (MODE) Enumerations
 *  ========================================================================= */
typedef enum
{
  PMG_PWRMOD_FLEXI     = 0,  /**< FLEXI Mode     */
  PMG_PWRMOD_HIBERNATE = 2,  /**< HIBERNATE Mode */
  PMG_PWRMOD_SHUTDOWN  = 3   /**< SHUTDOWN Mode  */
} ADI_PMG_PWRMOD_MODE;


/* ==========================================================================
 *! \struct ADI_PMG_PWRMOD_Struct
 *! \brief  Power Mode Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_PWRMOD_t__
typedef struct _ADI_PMG_PWRMOD_t {
  union {
    struct {
      uint32_t MODE       :  2;  /**< Power Mode Bits */
      uint32_t reserved2  :  1;
      uint32_t MONVBATN   :  1;  /**< Monitor VBAT during HIBERNATE Mode. Monitors VBAT by default */
      uint32_t reserved4  : 28;
    };
    uint32_t VALUE32;
  };
} ADI_PMG_PWRMOD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_PWRMOD_t__ */

/*@}*/

/** @defgroup PWRKEY Key protection for PWRMOD and  SRAMRET (PWRKEY) Register
 *  Key protection for PWRMOD and  SRAMRET (PWRKEY) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_PMG_PWRKEY_Struct
 *! \brief  Key protection for PWRMOD and  SRAMRET Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_PWRKEY_t__
typedef struct _ADI_PMG_PWRKEY_t {
  union {
    struct {
      uint32_t VALUE      : 16;  /**< Power control key register */
      uint32_t reserved16 : 16;
    };
    uint32_t VALUE32;
  };
} ADI_PMG_PWRKEY_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_PWRKEY_t__ */

/*@}*/

/** @defgroup SHDN_STAT SHUTDOWN Status Register (SHDN_STAT) Register
 *  SHUTDOWN Status Register (SHDN_STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_PMG_SHDN_STAT_Struct
 *! \brief  SHUTDOWN Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_SHDN_STAT_t__
typedef struct _ADI_PMG_SHDN_STAT_t {
  union {
    struct {
      uint32_t EXTINT0    :  1;  /**< Interrupt from External Interrupt 0 */
      uint32_t EXTINT1    :  1;  /**< Interrupt from External Interrupt 1 */
      uint32_t EXTINT2    :  1;  /**< Interrupt from External Interrupt 2 */
      uint32_t RTC        :  1;  /**< Interrupt from RTC */
      uint32_t reserved4  : 28;
    };
    uint32_t VALUE32;
  };
} ADI_PMG_SHDN_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_SHDN_STAT_t__ */

/*@}*/

/** @defgroup SRAMRET Control for Retention SRAM during HIBERNATE Mode (SRAMRET) Register
 *  Control for Retention SRAM during HIBERNATE Mode (SRAMRET) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_PMG_SRAMRET_Struct
 *! \brief  Control for Retention SRAM during HIBERNATE Mode Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_SRAMRET_t__
typedef struct _ADI_PMG_SRAMRET_t {
  union {
    struct {
      uint32_t BNK1EN     :  1;  /**< Enable retention bank 1 (8kB) */
      uint32_t BNK2EN     :  1;  /**< Enable retention bank 2 (16kB) */
      uint32_t reserved2  : 30;
    };
    uint32_t VALUE32;
  };
} ADI_PMG_SRAMRET_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_SRAMRET_t__ */

/*@}*/

/** @defgroup RST_STAT Reset status (RST_STAT) Register
 *  Reset status (RST_STAT) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_PMG_RST_STAT_PORSRC
 *! \brief  Power on reset Source (pmg_rst_src) (PORSRC) Enumerations
 *  ========================================================================= */
typedef enum
{
  PMG_RST_STAT_FAILSAFE_HV = 0,  /**< POR triggered because VBAT drops below Fail Safe */
  PMG_RST_STAT_RST_VBAT    = 1,  /**< POR trigger because VBAT supply (VBAT<1.7v)      */
  PMG_RST_STAT_RST_VREG    = 2,  /**< POR triggered because VDD supply (VDD < 1.08v)   */
  PMG_RST_STAT_FAILSAFE_LV = 3   /**< POR triggered because VREG drops below Fail Safe */
} ADI_PMG_RST_STAT_PORSRC;


/* ==========================================================================
 *! \struct ADI_PMG_RST_STAT_Struct
 *! \brief  Reset status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_RST_STAT_t__
typedef struct _ADI_PMG_RST_STAT_t {
  union {
    struct {
      uint32_t POR        :  1;  /**< Power-on reset */
      uint32_t EXTRST     :  1;  /**< External reset */
      uint32_t WDRST      :  1;  /**< Watchdog timeout */
      uint32_t SWRST      :  1;  /**< Software reset */
      uint32_t PORSRC     :  2;  /**< Power on reset Source (pmg_rst_src) */
      uint32_t reserved6  : 26;
    };
    uint32_t VALUE32;
  };
} ADI_PMG_RST_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_RST_STAT_t__ */

/*@}*/

/** @defgroup CTL1 HPBUCK control (CTL1) Register
 *  HPBUCK control (CTL1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_PMG_CTL1_Struct
 *! \brief  HPBUCK control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_CTL1_t__
typedef struct _ADI_PMG_CTL1_t {
  union {
    struct {
      uint32_t HPBUCKEN   :  1;  /**< Enable HP Buck */
      uint32_t reserved1  : 31;
    };
    uint32_t VALUE32;
  };
} ADI_PMG_CTL1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_CTL1_t__ */

/*@}*/

/** @defgroup CFG0 External Interrupt Configuration (CFG0) Register
 *  External Interrupt Configuration (CFG0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_XINT_CFG0_Struct
 *! \brief  External Interrupt Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_XINT_CFG0_t__
typedef struct _ADI_XINT_CFG0_t {
  union {
    struct {
      uint32_t IRQ0MDE    :  3;  /**< External Interrupt 0 Mode registers */
      uint32_t IRQ0EN     :  1;  /**< External Interrupt 0 Enable bit */
      uint32_t IRQ1MDE    :  3;  /**< External Interrupt 1 Mode registers */
      uint32_t IRQ1EN     :  1;  /**< External Interrupt 1 Enable bit */
      uint32_t IRQ2MDE    :  3;  /**< External Interrupt 2 Mode registers */
      uint32_t IRQ2EN     :  1;  /**< External Interrupt 2 Enable bit */
      uint32_t IRQ3MDE    :  3;  /**< External Interrupt 3 Mode registers */
      uint32_t IRQ3EN     :  1;  /**< External Interrupt 3 enable bit */
      uint32_t reserved16 :  4;
      uint32_t UART_RX_EN :  1;  /**< External Interrupt enable bit */
      uint32_t UART_RX_MDE :  3;  /**< External Interrupt using UART_RX wakeup Mode registers */
      uint32_t reserved24  :  8;
    };
    uint32_t VALUE32;
  };
} ADI_XINT_CFG0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_XINT_CFG0_t__ */

/*@}*/

/** @defgroup EXT_STAT External Wakeup Interrupt Status (EXT_STAT) Register
 *  External Wakeup Interrupt Status (EXT_STAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_XINT_EXT_STAT_Struct
 *! \brief  External Wakeup Interrupt Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_XINT_EXT_STAT_t__
typedef struct _ADI_XINT_EXT_STAT_t {
  union {
    struct {
      uint32_t STAT_EXTINT0 :  1;  /**< Interrupt status bit for External Interrupt 0 */
      uint32_t STAT_EXTINT1 :  1;  /**< Interrupt status bit for External Interrupt 1 */
      uint32_t STAT_EXTINT2 :  1;  /**< Interrupt status bit for External Interrupt 2 */
      uint32_t STAT_EXTINT3 :  1;  /**< Interrupt status bit for External Interrupt 3 */
      uint32_t reserved4        :  1;
      uint32_t STAT_UART_RXWKUP :  1;  /**< Interrupt status bit for UART RX wakeup interrupt */
      uint32_t reserved6        : 26;
    };
    uint32_t VALUE32;
  };
} ADI_XINT_EXT_STAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_XINT_EXT_STAT_t__ */

/*@}*/

/** @defgroup CLR External Interrupt Clear (CLR) Register
 *  External Interrupt Clear (CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_XINT_CLR_Struct
 *! \brief  External Interrupt Clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_XINT_CLR_t__
typedef struct _ADI_XINT_CLR_t {
  union {
    struct {
      uint32_t IRQ0       :  1;  /**< External interrupt 0 */
      uint32_t IRQ1       :  1;  /**< External interrupt 1 */
      uint32_t IRQ2       :  1;  /**< External interrupt 2 */
      uint32_t IRQ3       :  1;  /**< External interrupt 3 */
      uint32_t reserved4   :  1;
      uint32_t UART_RX_CLR :  1;  /**< External interrupt Clear for UART_RX WAKEUP interrupt */
      uint32_t reserved6   : 26;
    };
    uint32_t VALUE32;
  };
} ADI_XINT_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_XINT_CLR_t__ */

/*@}*/

/** @defgroup NMICLR Non-Maskable Interrupt Clear (NMICLR) Register
 *  Non-Maskable Interrupt Clear (NMICLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_XINT_NMICLR_Struct
 *! \brief  Non-Maskable Interrupt Clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_XINT_NMICLR_t__
typedef struct _ADI_XINT_NMICLR_t {
  union {
    struct {
      uint32_t CLR        :  1;  /**< NMI clear */
      uint32_t reserved1  : 31;
    };
    uint32_t VALUE32;
  };
} ADI_XINT_NMICLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_XINT_NMICLR_t__ */

/*@}*/

/** @defgroup KEY Key Protection for OSCCTRL (KEY) Register
 *  Key Protection for OSCCTRL (KEY) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CLKG_OSC_KEY_Struct
 *! \brief  Key Protection for OSCCTRL Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CLKG_OSC_KEY_t__
typedef struct _ADI_CLKG_OSC_KEY_t {
  union {
    struct {
      uint32_t VALUE      : 16;  /**< Oscillator key */
      uint32_t reserved16 : 16;
    };
    uint32_t VALUE32;
  };
} ADI_CLKG_OSC_KEY_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CLKG_OSC_KEY_t__ */

/*@}*/

/** @defgroup CTL Oscillator Control (CTL) Register
 *  Oscillator Control (CTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CLKG_OSC_CTL_Struct
 *! \brief  Oscillator Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CLKG_OSC_CTL_t__
typedef struct _ADI_CLKG_OSC_CTL_t {
  union {
    struct {
      uint32_t LFCLKMUX   :  1;  /**< 32 KHz clock select mux */
      uint32_t HFOSCEN    :  1;  /**< High frequency internal oscillator enable */
      uint32_t LFXTALEN   :  1;  /**< Low frequency crystal oscillator enable */
      uint32_t HFXTALEN   :  1;  /**< High frequency crystal oscillator enable */
      uint32_t LFXTAL_BYPASS :  1;  /**< Low frequency crystal oscillator Bypass */
      uint32_t LFXTAL_MON_EN :  1;  /**< LFXTAL clock monitor and Clock FAIL interrupt enable */
      uint32_t reserved6     :  2;
      uint32_t LFOSCOK       :  1;  /**< Status of LFOSC oscillator */
      uint32_t HFOSCOK       :  1;  /**< Status of HFOSC oscillator */
      uint32_t LFXTALOK      :  1;  /**< Status of LFXTAL oscillator */
      uint32_t HFXTALOK      :  1;  /**< Status of HFXTAL oscillator */
      uint32_t reserved12           : 19;
      uint32_t LFXTAL_MON_FAIL_STAT :  1;  /**< LF XTAL (crystal clock) Not Stable */
    };
    uint32_t VALUE32;
  };
} ADI_CLKG_OSC_CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CLKG_OSC_CTL_t__ */

/*@}*/

/** @defgroup SRAM_CTL Control for SRAM parity and instruction SRAM (SRAM_CTL) Register
 *  Control for SRAM parity and instruction SRAM (SRAM_CTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_PMG_TST_SRAM_CTL_Struct
 *! \brief  Control for SRAM parity and instruction SRAM Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_TST_SRAM_CTL_t__
typedef struct _ADI_PMG_TST_SRAM_CTL_t {
  union {
    struct {
      uint32_t BNK0EN     :  1;  /**< Enable initialization */
      uint32_t BNK1EN     :  1;  /**< Enable initialization */
      uint32_t BNK2EN     :  1;  /**< Enable initialization */
      uint32_t BNK3EN     :  1;  /**< Enable initialization */
      uint32_t BNK4EN     :  1;  /**< Enable initialization */
      uint32_t BNK5EN     :  1;  /**< Enable initialization */
      uint32_t reserved6  :  7;
      uint32_t STARTINIT  :  1;  /**< Write one to trigger initialization. Self-cleared */
      uint32_t AUTOINIT   :  1;  /**< Automatic initialization on wake up from Hibernate mode */
      uint32_t ABTINIT    :  1;  /**< Abort current initialization. Self-cleared */
      uint32_t PENBNK0    :  1;  /**< Enable parity check */
      uint32_t PENBNK1    :  1;  /**< Enable parity check */
      uint32_t PENBNK2    :  1;  /**< Enable parity check */
      uint32_t PENBNK3    :  1;  /**< Enable parity check */
      uint32_t PENBNK4    :  1;  /**< Enable parity check */
      uint32_t PENBNK5    :  1;  /**< Enable parity check */
      uint32_t reserved22 :  9;
      uint32_t INSTREN    :  1;  /**< Enables instruction SRAM */
    };
    uint32_t VALUE32;
  };
} ADI_PMG_TST_SRAM_CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_TST_SRAM_CTL_t__ */

/*@}*/

/** @defgroup SRAM_INITSTAT Initialization Status Register (SRAM_INITSTAT) Register
 *  Initialization Status Register (SRAM_INITSTAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_PMG_TST_SRAM_INITSTAT_Struct
 *! \brief  Initialization Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_TST_SRAM_INITSTAT_t__
typedef struct _ADI_PMG_TST_SRAM_INITSTAT_t {
  union {
    struct {
      uint32_t BNK0       :  1;  /**< 0:Not initialized; 1:Initialization completed */
      uint32_t BNK1       :  1;  /**< 0:Not initialized; 1:Initialization completed */
      uint32_t BNK2       :  1;  /**< 0:Not initialized; 1:Initialization completed */
      uint32_t BNK3       :  1;  /**< 0:Not initialized; 1:Initialization completed */
      uint32_t BNK4       :  1;  /**< 0:Not initialized; 1:Initialization completed */
      uint32_t BNK5       :  1;  /**< 0:Not initialized; 1:Initialization completed */
      uint32_t reserved6  : 26;
    };
    uint32_t VALUE32;
  };
} ADI_PMG_TST_SRAM_INITSTAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_TST_SRAM_INITSTAT_t__ */

/*@}*/

/** @defgroup CLR_LATCH_GPIOS CLEAR GPIO AFTER SHUTDOWN MODE (CLR_LATCH_GPIOS) Register
 *  CLEAR GPIO AFTER SHUTDOWN MODE (CLR_LATCH_GPIOS) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_PMG_TST_CLR_LATCH_GPIOS_Struct
 *! \brief  CLEAR GPIO AFTER SHUTDOWN MODE Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_TST_CLR_LATCH_GPIOS_t__
typedef struct _ADI_PMG_TST_CLR_LATCH_GPIOS_t {
  union {
    struct {
      uint16_t VALUE      : 16;  /**< Writing 0x58FA creates a pulse to clear the latches for the GPIOs */
    };
    uint16_t VALUE16;
  };
} ADI_PMG_TST_CLR_LATCH_GPIOS_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_TST_CLR_LATCH_GPIOS_t__ */

/*@}*/

/** @defgroup SCRPAD_IMG SCRATCH PAD IMAGE (SCRPAD_IMG) Register
 *  SCRATCH PAD IMAGE (SCRPAD_IMG) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_PMG_TST_SCRPAD_IMG_Struct
 *! \brief  SCRATCH PAD IMAGE Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_TST_SCRPAD_IMG_t__
typedef struct _ADI_PMG_TST_SCRPAD_IMG_t {
  union {
    struct {
      uint32_t DATA       : 32;  /**< Anything written to this register will be saved in 3V when going to shutdown mode */
    };
    uint32_t VALUE32;
  };
} ADI_PMG_TST_SCRPAD_IMG_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_TST_SCRPAD_IMG_t__ */

/*@}*/

/** @defgroup SCRPAD_3V_RD SCRATCH PAD SAVED IN BATTERY DOMAIN (SCRPAD_3V_RD) Register
 *  SCRATCH PAD SAVED IN BATTERY DOMAIN (SCRPAD_3V_RD) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_PMG_TST_SCRPAD_3V_RD_Struct
 *! \brief  SCRATCH PAD SAVED IN BATTERY DOMAIN Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_TST_SCRPAD_3V_RD_t__
typedef struct _ADI_PMG_TST_SCRPAD_3V_RD_t {
  union {
    struct {
      uint32_t DATA       : 32;  /**< Read Only register. Reading the scratch pad stored in shutdown mode */
    };
    uint32_t VALUE32;
  };
} ADI_PMG_TST_SCRPAD_3V_RD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_TST_SCRPAD_3V_RD_t__ */

/*@}*/

/** @defgroup CTL0 Misc clock settings (CTL0) Register
 *  Misc clock settings (CTL0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CLKG_CLK_CTL0_Struct
 *! \brief  Misc clock settings Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_CTL0_t__
typedef struct _ADI_CLKG_CLK_CTL0_t {
  union {
    struct {
      uint32_t CLKMUX     :  2;  /**< Clock mux select */
      uint32_t reserved2  :  6;
      uint32_t RCLKMUX    :  2;  /**< Flash reference clock and HPBUCK clock source mux */
      uint32_t reserved10 :  1;
      uint32_t SPLLIPSEL  :  1;  /**< SPLL source select mux */
      uint32_t reserved12 :  2;
      uint32_t LFXTALIE   :  1;  /**< Low frequency crystal interrupt enable */
      uint32_t HFXTALIE   :  1;  /**< High frequency crystal interrupt enable */
      uint32_t reserved16 : 16;
    };
    uint32_t VALUE32;
  };
} ADI_CLKG_CLK_CTL0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_CTL0_t__ */

/*@}*/

/** @defgroup CTL1 Clock dividers (CTL1) Register
 *  Clock dividers (CTL1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CLKG_CLK_CTL1_Struct
 *! \brief  Clock dividers Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_CTL1_t__
typedef struct _ADI_CLKG_CLK_CTL1_t {
  union {
    struct {
      uint32_t HCLKDIVCNT :  6;  /**< HCLK divide count */
      uint32_t reserved6  :  2;
      uint32_t PCLKDIVCNT :  6;  /**< PCLK divide count */
      uint32_t reserved14 :  2;
      uint32_t ACLKDIVCNT :  8;  /**< ACLK Divide Count. */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_CLKG_CLK_CTL1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_CTL1_t__ */

/*@}*/

/** @defgroup CTL3 System PLL (CTL3) Register
 *  System PLL (CTL3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CLKG_CLK_CTL3_Struct
 *! \brief  System PLL Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_CTL3_t__
typedef struct _ADI_CLKG_CLK_CTL3_t {
  union {
    struct {
      uint32_t SPLLNSEL   :  5;  /**< System PLL N multiplier */
      uint32_t reserved5  :  3;
      uint32_t SPLLDIV2   :  1;  /**< System PLL division by 2 */
      uint32_t SPLLEN     :  1;  /**< System PLL enable */
      uint32_t SPLLIE     :  1;  /**< System PLL interrupt enable */
      uint32_t SPLLMSEL   :  4;  /**< System PLL M Divider */
      uint32_t reserved15 :  1;
      uint32_t SPLLMUL2   :  1;  /**< system PLL multiply by 2 */
      uint32_t reserved17 : 15;
    };
    uint32_t VALUE32;
  };
} ADI_CLKG_CLK_CTL3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_CTL3_t__ */

/*@}*/

/** @defgroup CTL5 User clock gating control (CTL5) Register
 *  User clock gating control (CTL5) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CLKG_CLK_CTL5_Struct
 *! \brief  User clock gating control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_CTL5_t__
typedef struct _ADI_CLKG_CLK_CTL5_t {
  union {
    struct {
      uint32_t GPTCLK0OFF :  1;  /**< GP timer 0 user control */
      uint32_t GPTCLK1OFF :  1;  /**< GP timer 1 user control */
      uint32_t GPTCLK2OFF :  1;  /**< GP timer 2 user control */
      uint32_t UCLKI2COFF :  1;  /**< I2C clock user control */
      uint32_t GPIOCLKOFF :  1;  /**< GPIO clock control */
      uint32_t PERCLKOFF  :  1;  /**< This bit is used to disable all clocks connected to all peripherals */
      uint32_t reserved6  : 26;
    };
    uint32_t VALUE32;
  };
} ADI_CLKG_CLK_CTL5_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_CTL5_t__ */

/*@}*/

/** @defgroup STAT0 Clocking status (STAT0) Register
 *  Clocking status (STAT0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_CLKG_CLK_STAT0_Struct
 *! \brief  Clocking status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_STAT0_t__
typedef struct _ADI_CLKG_CLK_STAT0_t {
  union {
    struct {
      uint32_t SPLL       :  1;  /**< System PLL status */
      uint32_t SPLLLK     :  1;  /**< System PLL lock */
      uint32_t SPLLUNLK   :  1;  /**< System PLL unlock */
      uint32_t reserved3  :  5;
      uint32_t LFXTAL     :  1;  /**< LF crystal status */
      uint32_t LFXTALOK   :  1;  /**< LF crystal stable */
      uint32_t LFXTALNOK  :  1;  /**< LF crystal not stable */
      uint32_t reserved11 :  1;
      uint32_t HFXTAL     :  1;  /**< HF crystal status */
      uint32_t HFXTALOK   :  1;  /**< HF crystal stable */
      uint32_t HFXTALNOK  :  1;  /**< HF crystal not stable */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_CLKG_CLK_STAT0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_STAT0_t__ */

/*@}*/

/** @defgroup ARBIT0 Arbitration Priority Configuration for FLASH and SRAM0 (ARBIT0) Register
 *  Arbitration Priority Configuration for FLASH and SRAM0 (ARBIT0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_BUSM_ARBIT0_Struct
 *! \brief  Arbitration Priority Configuration for FLASH and SRAM0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_BUSM_ARBIT0_t__
typedef struct _ADI_BUSM_ARBIT0_t {
  union {
    struct {
      uint32_t FLSH_DCODE :  2;  /**< Flash priority for DCODE */
      uint32_t FLSH_SBUS  :  2;  /**< Flash priority for SBUS */
      uint32_t FLSH_DMA0  :  2;  /**< Flash priority for DMA0 */
      uint32_t reserved6   : 10;
      uint32_t SRAM0_DCODE :  2;  /**< SRAM0 priority for Dcode */
      uint32_t SRAM0_SBUS  :  2;  /**< SRAM0 priority for SBUS */
      uint32_t SRAM0_DMA0  :  2;  /**< SRAM0 priority for DMA0 */
      uint32_t reserved22  : 10;
    };
    uint32_t VALUE32;
  };
} ADI_BUSM_ARBIT0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_BUSM_ARBIT0_t__ */

/*@}*/

/** @defgroup ARBIT1 Arbitration Priority Configuration for SRAM1 and SIP (ARBIT1) Register
 *  Arbitration Priority Configuration for SRAM1 and SIP (ARBIT1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_BUSM_ARBIT1_Struct
 *! \brief  Arbitration Priority Configuration for SRAM1 and SIP Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_BUSM_ARBIT1_t__
typedef struct _ADI_BUSM_ARBIT1_t {
  union {
    struct {
      uint32_t SRAM1_DCODE :  2;  /**< SRAM1 priority for Dcode */
      uint32_t SRAM1_SBUS  :  2;  /**< SRAM1 priority for SBUS */
      uint32_t SRAM1_DMA0  :  2;  /**< SRAM1 priority for DMA0 */
      uint32_t reserved6   : 10;
      uint32_t SIP_DCODE   :  2;  /**< SIP priority for DCODE */
      uint32_t SIP_SBUS    :  2;  /**< SIP priority for SBUS */
      uint32_t SIP_DMA0    :  2;  /**< SIP priority for DMA0 */
      uint32_t reserved22  : 10;
    };
    uint32_t VALUE32;
  };
} ADI_BUSM_ARBIT1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_BUSM_ARBIT1_t__ */

/*@}*/

/** @defgroup ARBIT2 Arbitration Priority Configuration for APB32 and APB16 (ARBIT2) Register
 *  Arbitration Priority Configuration for APB32 and APB16 (ARBIT2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_BUSM_ARBIT2_Struct
 *! \brief  Arbitration Priority Configuration for APB32 and APB16 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_BUSM_ARBIT2_t__
typedef struct _ADI_BUSM_ARBIT2_t {
  union {
    struct {
      uint32_t APB32_DCODE :  2;  /**< APB32 priority for DCODE */
      uint32_t APB32_SBUS  :  2;  /**< APB32 priority for SBUS */
      uint32_t APB32_DMA0  :  2;  /**< APB32 priority for DMA0 */
      uint32_t reserved6   : 10;
      uint32_t APB16_DCODE :  2;  /**< APB16 priority for DCODE */
      uint32_t APB16_SBUS  :  2;  /**< APB16 priority for SBUS */
      uint32_t APB16_DMA0  :  2;  /**< APB16 priority for DMA0 */
      uint32_t reserved22  : 10;
    };
    uint32_t VALUE32;
  };
} ADI_BUSM_ARBIT2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_BUSM_ARBIT2_t__ */

/*@}*/

/** @defgroup ARBIT3 Arbitration Priority Configuration for APB16 priority for core and for DMA1 (ARBIT3) Register
 *  Arbitration Priority Configuration for APB16 priority for core and for DMA1 (ARBIT3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_BUSM_ARBIT3_Struct
 *! \brief  Arbitration Priority Configuration for APB16 priority for core and for DMA1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_BUSM_ARBIT3_t__
typedef struct _ADI_BUSM_ARBIT3_t {
  union {
    struct {
      uint32_t APB16_CORE :  1;  /**< APB16 priority for CORE */
      uint32_t APB16_DMA1 :  1;  /**< APB16 priority for DMA1 */
      uint32_t reserved2       : 14;
      uint32_t APB16_4DMA_CORE :  1;  /**< APB16 for dma priority for CORE */
      uint32_t APB16_4DMA_DMA1 :  1;  /**< APB16 for dma priority for DMA1 */
      uint32_t reserved18      : 14;
    };
    uint32_t VALUE32;
  };
} ADI_BUSM_ARBIT3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_BUSM_ARBIT3_t__ */

/*@}*/

/** @defgroup CON GPIO Port Configuration (CON) Register
 *  GPIO Port Configuration (CON) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPIO_CON_Struct
 *! \brief  GPIO Port Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPIO_CON_t__
typedef struct _ADI_AGPIO_CON_t {
  union {
    struct {
      uint32_t PIN0CFG    :  2;  /**< Pin 0 Configuration Bits */
      uint32_t PIN1CFG    :  2;  /**< Pin 1 Configuration Bits */
      uint32_t PIN2CFG    :  2;  /**< Pin 2 Configuration Bits */
      uint32_t PIN3CFG    :  2;  /**< Pin 3 Configuration Bits */
      uint32_t PIN4CFG    :  2;  /**< Pin 4 Configuration Bits */
      uint32_t PIN5CFG    :  2;  /**< Pin 5 Configuration Bits */
      uint32_t PIN6CFG    :  2;  /**< Pin 6 Configuration Bits */
      uint32_t PIN7CFG    :  2;  /**< Pin 7 Configuration Bits */
      uint32_t reserved16 : 16;
    };
    uint32_t VALUE32;
  };
} ADI_AGPIO_CON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPIO_CON_t__ */

/*@}*/

/** @defgroup OEN GPIO Port Output Enable (OEN) Register
 *  GPIO Port Output Enable (OEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPIO_OEN_Struct
 *! \brief  GPIO Port Output Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPIO_OEN_t__
typedef struct _ADI_AGPIO_OEN_t {
  union {
    struct {
      uint16_t OEN        : 16;  /**< Pin Output Drive enable */
    };
    uint16_t VALUE16;
  };
} ADI_AGPIO_OEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPIO_OEN_t__ */

/*@}*/

/** @defgroup PE GPIO Port Pullup/Pulldown Enable (PE) Register
 *  GPIO Port Pullup/Pulldown Enable (PE) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPIO_PE_Struct
 *! \brief  GPIO Port Pullup/Pulldown Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPIO_PE_t__
typedef struct _ADI_AGPIO_PE_t {
  union {
    struct {
      uint16_t PE         : 16;  /**< Pin Pull enable */
    };
    uint16_t VALUE16;
  };
} ADI_AGPIO_PE_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPIO_PE_t__ */

/*@}*/

/** @defgroup IEN GPIO Port Input Path Enable (IEN) Register
 *  GPIO Port Input Path Enable (IEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPIO_IEN_Struct
 *! \brief  GPIO Port Input Path Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPIO_IEN_t__
typedef struct _ADI_AGPIO_IEN_t {
  union {
    struct {
      uint16_t IEN        : 16;  /**< Input path enable */
    };
    uint16_t VALUE16;
  };
} ADI_AGPIO_IEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPIO_IEN_t__ */

/*@}*/

/** @defgroup IN GPIO Port Registered Data Input (IN) Register
 *  GPIO Port Registered Data Input (IN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPIO_IN_Struct
 *! \brief  GPIO Port Registered Data Input Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPIO_IN_t__
typedef struct _ADI_AGPIO_IN_t {
  union {
    struct {
      uint16_t IN         : 16;  /**< Registered data input */
    };
    uint16_t VALUE16;
  };
} ADI_AGPIO_IN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPIO_IN_t__ */

/*@}*/

/** @defgroup OUT GPIO Port Data Output (OUT) Register
 *  GPIO Port Data Output (OUT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPIO_OUT_Struct
 *! \brief  GPIO Port Data Output Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPIO_OUT_t__
typedef struct _ADI_AGPIO_OUT_t {
  union {
    struct {
      uint16_t OUT        : 16;  /**< Data out */
    };
    uint16_t VALUE16;
  };
} ADI_AGPIO_OUT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPIO_OUT_t__ */

/*@}*/

/** @defgroup SET GPIO Port Data Out Set (SET) Register
 *  GPIO Port Data Out Set (SET) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPIO_SET_Struct
 *! \brief  GPIO Port Data Out Set Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPIO_SET_t__
typedef struct _ADI_AGPIO_SET_t {
  union {
    struct {
      uint16_t SET        : 16;  /**< Set the output HIGH for the pin */
    };
    uint16_t VALUE16;
  };
} ADI_AGPIO_SET_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPIO_SET_t__ */

/*@}*/

/** @defgroup CLR GPIO Port Data Out Clear (CLR) Register
 *  GPIO Port Data Out Clear (CLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPIO_CLR_Struct
 *! \brief  GPIO Port Data Out Clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPIO_CLR_t__
typedef struct _ADI_AGPIO_CLR_t {
  union {
    struct {
      uint16_t CLR        : 16;  /**< Set the output low  for the port pin */
    };
    uint16_t VALUE16;
  };
} ADI_AGPIO_CLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPIO_CLR_t__ */

/*@}*/

/** @defgroup TGL GPIO Port Pin Toggle (TGL) Register
 *  GPIO Port Pin Toggle (TGL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPIO_TGL_Struct
 *! \brief  GPIO Port Pin Toggle Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPIO_TGL_t__
typedef struct _ADI_AGPIO_TGL_t {
  union {
    struct {
      uint16_t TGL        : 16;  /**< Toggle the output of the port pin */
    };
    uint16_t VALUE16;
  };
} ADI_AGPIO_TGL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPIO_TGL_t__ */

/*@}*/

/** @defgroup ADIID ADI Identification (ADIID) Register
 *  ADI Identification (ADIID) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFECON_ADIID_Struct
 *! \brief  ADI Identification Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFECON_ADIID_t__
typedef struct _ADI_AFECON_ADIID_t {
  union {
    struct {
      uint16_t ADIID      : 16;  /**< ADI Identifier. */
    };
    uint16_t VALUE16;
  };
} ADI_AFECON_ADIID_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFECON_ADIID_t__ */

/*@}*/

/** @defgroup CHIPID Chip Identification (CHIPID) Register
 *  Chip Identification (CHIPID) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFECON_CHIPID_Struct
 *! \brief  Chip Identification Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFECON_CHIPID_t__
typedef struct _ADI_AFECON_CHIPID_t {
  union {
    struct {
      uint16_t Revision   :  4;  /**< Silicon Revision Number */
      uint16_t PartID     : 12;  /**< Part Identifier */
    };
    uint16_t VALUE16;
  };
} ADI_AFECON_CHIPID_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFECON_CHIPID_t__ */

/*@}*/

/** @defgroup CLKCON0 Clock Divider Configuration (CLKCON0) Register
 *  Clock Divider Configuration (CLKCON0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFECON_CLKCON0_Struct
 *! \brief  Clock Divider Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFECON_CLKCON0_t__
typedef struct _ADI_AFECON_CLKCON0_t {
  union {
    struct {
      uint16_t SYSCLKDIV  :  6;  /**< System Clock Divider Configuration */
      uint16_t ADCCLKDIV  :  4;  /**< ADC Clock Divider Configuration */
      uint16_t SFFTCLKDIVCNT :  6;  /**< SFFT Clock Divider Configuration */
    };
    uint16_t VALUE16;
  };
} ADI_AFECON_CLKCON0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFECON_CLKCON0_t__ */

/*@}*/

/** @defgroup CLKEN1 Clock Gate Enable (CLKEN1) Register
 *  Clock Gate Enable (CLKEN1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFECON_CLKEN1_Struct
 *! \brief  Clock Gate Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFECON_CLKEN1_t__
typedef struct _ADI_AFECON_CLKEN1_t {
  union {
    struct {
      uint16_t reserved0  :  5;
      uint16_t ACLKDIS    :  1;  /**< ACLK Clock Enable */
      uint16_t GPT0DIS    :  1;  /**< GPT0 Clock Enable */
      uint16_t GPT1DIS    :  1;  /**< GPT1 Clock Enable */
      uint16_t reserved8  :  8;
    };
    uint16_t VALUE16;
  };
} ADI_AFECON_CLKEN1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFECON_CLKEN1_t__ */

/*@}*/

/** @defgroup CLKSEL Clock Select (CLKSEL) Register
 *  Clock Select (CLKSEL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFECON_CLKSEL_Struct
 *! \brief  Clock Select Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFECON_CLKSEL_t__
typedef struct _ADI_AFECON_CLKSEL_t {
  union {
    struct {
      uint16_t SYSCLKSEL  :  2;  /**< Select System Clock Source */
      uint16_t ADCCLKSEL  :  2;  /**< Select ADC Clock Source */
      uint16_t reserved4  : 12;
    };
    uint16_t VALUE16;
  };
} ADI_AFECON_CLKSEL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFECON_CLKSEL_t__ */

/*@}*/

/** @defgroup GPIOCLKMUXSEL GPIO Clock MUX Select (GPIOCLKMUXSEL) Register
 *  GPIO Clock MUX Select (GPIOCLKMUXSEL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFECON_GPIOCLKMUXSEL_Struct
 *! \brief  GPIO Clock MUX Select Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFECON_GPIOCLKMUXSEL_t__
typedef struct _ADI_AFECON_GPIOCLKMUXSEL_t {
  union {
    struct {
      uint16_t SEL        :  3;  /**< Configure Clock MUX Out to GPIO */
      uint16_t reserved3  : 13;
    };
    uint16_t VALUE16;
  };
} ADI_AFECON_GPIOCLKMUXSEL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFECON_GPIOCLKMUXSEL_t__ */

/*@}*/

/** @defgroup CLKCON0KEY Enable Clock Division to 8Mhz,4Mhz and 2Mhz (CLKCON0KEY) Register
 *  Enable Clock Division to 8Mhz,4Mhz and 2Mhz (CLKCON0KEY) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFECON_CLKCON0KEY_Struct
 *! \brief  Enable Clock Division to 8Mhz,4Mhz and 2Mhz Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFECON_CLKCON0KEY_t__
typedef struct _ADI_AFECON_CLKCON0KEY_t {
  union {
    struct {
      uint16_t divsysclk_ulp_en : 16;  /**< Enable Clock Division to 8Mhz,4Mhz and 2Mhz */
    };
    uint16_t VALUE16;
  };
} ADI_AFECON_CLKCON0KEY_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFECON_CLKCON0KEY_t__ */

/*@}*/

/** @defgroup MKEY MKEY (MKEY) Register
 *  MKEY (MKEY) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFECON_MKEY_Struct
 *! \brief  MKEY Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFECON_MKEY_t__
typedef struct _ADI_AFECON_MKEY_t {
  union {
    struct {
      uint16_t KEY        : 16;  /**< Key to Unlock SWRSTCON */
    };
    uint16_t VALUE16;
  };
} ADI_AFECON_MKEY_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFECON_MKEY_t__ */

/*@}*/

/** @defgroup DSPUPDATEEN DSP Update Enable (DSPUPDATEEN) Register
 *  DSP Update Enable (DSPUPDATEEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFECON_DSPUPDATEEN_Struct
 *! \brief  DSP Update Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFECON_DSPUPDATEEN_t__
typedef struct _ADI_AFECON_DSPUPDATEEN_t {
  union {
    struct {
      uint16_t DSPLOOP    :  1;  /**< ADC Digital Logic Test */
      uint16_t reserved1  : 15;
    };
    uint16_t VALUE16;
  };
} ADI_AFECON_DSPUPDATEEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFECON_DSPUPDATEEN_t__ */

/*@}*/

/** @defgroup WDTLD Watchdog Timer Load Value (WDTLD) Register
 *  Watchdog Timer Load Value (WDTLD) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFEWDT_WDTLD_Struct
 *! \brief  Watchdog Timer Load Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFEWDT_WDTLD_t__
typedef struct _ADI_AFEWDT_WDTLD_t {
  union {
    struct {
      int16_t LOAD       : 16;  /**< WDT Load Value */
    };
    int16_t VALUE16;
  };
} ADI_AFEWDT_WDTLD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFEWDT_WDTLD_t__ */

/*@}*/

/** @defgroup WDTVALS Current Count Value (WDTVALS) Register
 *  Current Count Value (WDTVALS) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFEWDT_WDTVALS_Struct
 *! \brief  Current Count Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFEWDT_WDTVALS_t__
typedef struct _ADI_AFEWDT_WDTVALS_t {
  union {
    struct {
      int16_t CCOUNT     : 16;  /**< Current WDT Count Value. */
    };
    int16_t VALUE16;
  };
} ADI_AFEWDT_WDTVALS_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFEWDT_WDTVALS_t__ */

/*@}*/

/** @defgroup WDTCON Watchdog Timer Control Register (WDTCON) Register
 *  Watchdog Timer Control Register (WDTCON) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_AFEWDT_WDTCON_PDSTOP
 *! \brief  Power Down Stop Enable (PDSTOP) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFEWDT_WDTCON_CONTINUE = 0,  /**< Continue Counting When In Hibernate */
  AFEWDT_WDTCON_STOP     = 1   /**< Stop Counter When In Hibernate.     */
} ADI_AFEWDT_WDTCON_PDSTOP;


/*  =========================================================================
 *! \enum   ADI_AFEWDT_WDTCON_IRQ
 *! \brief  WDT Interrupt Enable (IRQ) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFEWDT_WDTCON_RESET     = 0,  /**< Watchdog Timer timeout creates a reset.                        */
  AFEWDT_WDTCON_INTERRUPT = 1   /**< Watchdog Timer timeout creates an interrupt instead of reset.  */
} ADI_AFEWDT_WDTCON_IRQ;


/* ==========================================================================
 *! \struct ADI_AFEWDT_WDTCON_Struct
 *! \brief  Watchdog Timer Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFEWDT_WDTCON_t__
typedef struct _ADI_AFEWDT_WDTCON_t {
  union {
    struct {
      uint16_t PDSTOP     :  1;  /**< Power Down Stop Enable */
      uint16_t IRQ        :  1;  /**< WDT Interrupt Enable */
      uint16_t PRE        :  2;  /**< Prescaler. */
      uint16_t reserved4  :  1;
      uint16_t EN         :  1;  /**< Timer Enable */
      uint16_t MDE        :  1;  /**< Timer Mode Select */
      uint16_t Reserved1_7 :  1;  /**< Reserved */
      uint16_t CLKDIV2     :  1;  /**< Clock Source */
      uint16_t MINLOAD_EN  :  1;  /**< Timer Window Control */
      uint16_t WDTIRQEN    :  1;  /**< WDT Interrupt Enable */
      uint16_t RESERVED_15_11 :  5;  /**< RESERVED */
    };
    uint16_t VALUE16;
  };
} ADI_AFEWDT_WDTCON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFEWDT_WDTCON_t__ */

/*@}*/

/** @defgroup WDTCLRI Refresh Watchdog Register (WDTCLRI) Register
 *  Refresh Watchdog Register (WDTCLRI) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFEWDT_WDTCLRI_Struct
 *! \brief  Refresh Watchdog Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFEWDT_WDTCLRI_t__
typedef struct _ADI_AFEWDT_WDTCLRI_t {
  union {
    struct {
      int16_t CLRWDG     : 16;  /**< Refresh Register */
    };
    int16_t VALUE16;
  };
} ADI_AFEWDT_WDTCLRI_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFEWDT_WDTCLRI_t__ */

/*@}*/

/** @defgroup WDTSTA Timer Status (WDTSTA) Register
 *  Timer Status (WDTSTA) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_AFEWDT_WDTSTA_IRQ
 *! \brief  WDT Interrupt (IRQ) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFEWDT_WDTSTA_CLEARED = 0,  /**< Watchdog Timer Interrupt Not Pending */
  AFEWDT_WDTSTA_PENDING = 1   /**< Watchdog Timer Interrupt Pending     */
} ADI_AFEWDT_WDTSTA_IRQ;


/*  =========================================================================
 *! \enum   ADI_AFEWDT_WDTSTA_TLD
 *! \brief  WDTVAL Write Status (TLD) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFEWDT_WDTSTA_SYNC_COMPLETE    = 0,  /**< Arm and AFE Watchdog Clock Domains WDTLD values match */
  AFEWDT_WDTSTA_SYNC_IN_PROGRESS = 1   /**< Synchronize In Progress                               */
} ADI_AFEWDT_WDTSTA_TLD;


/*  =========================================================================
 *! \enum   ADI_AFEWDT_WDTSTA_LOCK
 *! \brief  Lock Status (LOCK) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFEWDT_WDTSTA_OPEN   = 0,  /**< Timer Operation Not Locked */
  AFEWDT_WDTSTA_LOCKED = 1   /**< Timer Enabled and Locked   */
} ADI_AFEWDT_WDTSTA_LOCK;


/* ==========================================================================
 *! \struct ADI_AFEWDT_WDTSTA_Struct
 *! \brief  Timer Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFEWDT_WDTSTA_t__
typedef struct _ADI_AFEWDT_WDTSTA_t {
  union {
    struct {
      uint16_t IRQ        :  1;  /**< WDT Interrupt */
      uint16_t CLRI       :  1;  /**< WDTCLRI Write Status */
      uint16_t TLD        :  1;  /**< WDTVAL Write Status */
      uint16_t CON        :  1;  /**< WDTCON Write Status */
      uint16_t LOCK       :  1;  /**< Lock Status */
      uint16_t OTPWRDONE  :  1;  /**< Reset Type Status */
      uint16_t TMINLD     :  1;  /**< WDTMINLD Write Status */
      uint16_t RESERVED_15_7 :  9;  /**< RESERVED */
    };
    uint16_t VALUE16;
  };
} ADI_AFEWDT_WDTSTA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFEWDT_WDTSTA_t__ */

/*@}*/

/** @defgroup WDTMINLD Minimum Load Value (WDTMINLD) Register
 *  Minimum Load Value (WDTMINLD) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFEWDT_WDTMINLD_Struct
 *! \brief  Minimum Load Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFEWDT_WDTMINLD_t__
typedef struct _ADI_AFEWDT_WDTMINLD_t {
  union {
    struct {
      int16_t MIN_LOAD   : 16;  /**< WDT Min Load Value */
    };
    int16_t VALUE16;
  };
} ADI_AFEWDT_WDTMINLD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFEWDT_WDTMINLD_t__ */

/*@}*/

/** @defgroup PWRMOD Power Modes (PWRMOD) Register
 *  Power Modes (PWRMOD) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ALLON_PWRMOD_Struct
 *! \brief  Power Modes Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ALLON_PWRMOD_t__
typedef struct _ADI_ALLON_PWRMOD_t {
  union {
    struct {
      uint16_t PWRMOD     :  2;  /**< Power Mode Control Bits */
      uint16_t reserved2  : 14;
    };
    uint16_t VALUE16;
  };
} ADI_ALLON_PWRMOD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ALLON_PWRMOD_t__ */

/*@}*/

/** @defgroup PWRKEY Key Protection for PWRMOD (PWRKEY) Register
 *  Key Protection for PWRMOD (PWRKEY) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ALLON_PWRKEY_Struct
 *! \brief  Key Protection for PWRMOD Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ALLON_PWRKEY_t__
typedef struct _ADI_ALLON_PWRKEY_t {
  union {
    struct {
      int16_t PWRKEY     : 16;  /**< PWRMOD Key Register */
    };
    int16_t VALUE16;
  };
} ADI_ALLON_PWRKEY_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ALLON_PWRKEY_t__ */

/*@}*/

/** @defgroup OSCKEY Key Protection for OSCCON (OSCKEY) Register
 *  Key Protection for OSCCON (OSCKEY) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ALLON_OSCKEY_Struct
 *! \brief  Key Protection for OSCCON Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ALLON_OSCKEY_t__
typedef struct _ADI_ALLON_OSCKEY_t {
  union {
    struct {
      int16_t OSCKEY     : 16;  /**< Oscillator Control Key Register. */
    };
    int16_t VALUE16;
  };
} ADI_ALLON_OSCKEY_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ALLON_OSCKEY_t__ */

/*@}*/

/** @defgroup OSCCON Oscillator Control (OSCCON) Register
 *  Oscillator Control (OSCCON) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ALLON_OSCCON_Struct
 *! \brief  Oscillator Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ALLON_OSCCON_t__
typedef struct _ADI_ALLON_OSCCON_t {
  union {
    struct {
      uint16_t LFOSCEN    :  1;  /**< Low Frequency Internal Oscillator Enable */
      uint16_t HFOSCEN    :  1;  /**< High Frequency Internal Oscillator Enable */
      uint16_t HFXTALEN   :  1;  /**< High Frequency Crystal Oscillator Enable */
      uint16_t reserved3  :  5;
      uint16_t LFOSCOK    :  1;  /**< Status of LFOSC Oscillator */
      uint16_t HFOSCOK    :  1;  /**< Status of HFOSC Oscillator */
      uint16_t HFXTALOK   :  1;  /**< Status of HFXTAL Oscillator */
      uint16_t reserved11 :  5;
    };
    uint16_t VALUE16;
  };
} ADI_ALLON_OSCCON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ALLON_OSCCON_t__ */

/*@}*/

/** @defgroup EI2CON External Interrupt Configuration 2 (EI2CON) Register
 *  External Interrupt Configuration 2 (EI2CON) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ALLON_EI2CON_Struct
 *! \brief  External Interrupt Configuration 2 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ALLON_EI2CON_t__
typedef struct _ADI_ALLON_EI2CON_t {
  union {
    struct {
      uint16_t BUSINTMDE  :  3;  /**< BUS Interrupt Detection Mode Registers */
      uint16_t BUSINTEN   :  1;  /**< BUS Interrupt Detection Enable Bit */
      uint16_t reserved4  : 12;
    };
    uint16_t VALUE16;
  };
} ADI_ALLON_EI2CON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ALLON_EI2CON_t__ */

/*@}*/

/** @defgroup EICLR External Interrupt Clear (EICLR) Register
 *  External Interrupt Clear (EICLR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ALLON_EICLR_Struct
 *! \brief  External Interrupt Clear Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ALLON_EICLR_t__
typedef struct _ADI_ALLON_EICLR_t {
  union {
    struct {
      uint16_t reserved0  :  8;
      uint16_t BUSINT     :  1;  /**< BUS Interrupt */
      uint16_t reserved9   :  6;
      uint16_t AUTCLRBUSEN :  1;  /**< Enable Auto Clear of Bus Interrupt */
    };
    uint16_t VALUE16;
  };
} ADI_ALLON_EICLR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ALLON_EICLR_t__ */

/*@}*/

/** @defgroup RSTSTA Reset Status (RSTSTA) Register
 *  Reset Status (RSTSTA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ALLON_RSTSTA_Struct
 *! \brief  Reset Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ALLON_RSTSTA_t__
typedef struct _ADI_ALLON_RSTSTA_t {
  union {
    struct {
      uint16_t POR        :  1;  /**< Power-on Reset */
      uint16_t EXTRST     :  1;  /**< External Reset */
      uint16_t WDRST      :  1;  /**< Watchdog Timeout */
      uint16_t MMRSWRST   :  1;  /**< MMR Software Reset */
      uint16_t reserved4  : 12;
    };
    uint16_t VALUE16;
  };
} ADI_ALLON_RSTSTA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ALLON_RSTSTA_t__ */

/*@}*/

/** @defgroup PMUSTA PMU Status (PMUSTA) Register
 *  PMU Status (PMUSTA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ALLON_PMUSTA_Struct
 *! \brief  PMU Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ALLON_PMUSTA_t__
typedef struct _ADI_ALLON_PMUSTA_t {
  union {
    struct {
      uint16_t PMUSTATE   :  3;  /**< PMU FSM States */
      uint16_t reserved3  : 13;
    };
    uint16_t VALUE16;
  };
} ADI_ALLON_PMUSTA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ALLON_PMUSTA_t__ */

/*@}*/

/** @defgroup CLKEN0 32KHz Peripheral Clock Enable (CLKEN0) Register
 *  32KHz Peripheral Clock Enable (CLKEN0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_ALLON_CLKEN0_Struct
 *! \brief  32KHz Peripheral Clock Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ALLON_CLKEN0_t__
typedef struct _ADI_ALLON_CLKEN0_t {
  union {
    struct {
      uint16_t WDTDIS     :  1;  /**< Watch Dog Timer Clock Disable */
      uint16_t SLPWUTDIS  :  1;  /**< Sleep/Wakeup Timer Clock Disable */
      uint16_t TIACHPDIS  :  1;  /**< TIA Chop Clock Disable */
      uint16_t reserved3  : 13;
    };
    uint16_t VALUE16;
  };
} ADI_ALLON_CLKEN0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ALLON_CLKEN0_t__ */

/*@}*/

/** @defgroup LD0 16-bit Load Value Register. (LD0) Register
 *  16-bit Load Value Register. (LD0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPT0_LD0_Struct
 *! \brief  16-bit Load Value Register. Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT0_LD0_t__
typedef struct _ADI_AGPT0_LD0_t {
  union {
    struct {
      int16_t LOAD       : 16;  /**< Load Value */
    };
    int16_t VALUE16;
  };
} ADI_AGPT0_LD0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT0_LD0_t__ */

/*@}*/

/** @defgroup VAL0 16-Bit Timer Value Register. (VAL0) Register
 *  16-Bit Timer Value Register. (VAL0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPT0_VAL0_Struct
 *! \brief  16-Bit Timer Value Register. Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT0_VAL0_t__
typedef struct _ADI_AGPT0_VAL0_t {
  union {
    struct {
      int16_t VAL        : 16;  /**< Current Count */
    };
    int16_t VALUE16;
  };
} ADI_AGPT0_VAL0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT0_VAL0_t__ */

/*@}*/

/** @defgroup CON0 Control Register. (CON0) Register
 *  Control Register. (CON0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPT0_CON0_Struct
 *! \brief  Control Register. Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT0_CON0_t__
typedef struct _ADI_AGPT0_CON0_t {
  union {
    struct {
      uint16_t PRE        :  2;  /**< Prescaler */
      uint16_t UP         :  1;  /**< Count up */
      uint16_t MOD        :  1;  /**< Timer Mode */
      uint16_t ENABLE     :  1;  /**< Timer Enable */
      uint16_t CLK        :  2;  /**< Clock Select */
      uint16_t RLD        :  1;  /**< Reload Control */
      uint16_t EVENT      :  5;  /**< Event Select Range */
      uint16_t EVTEN      :  1;  /**< Event Select */
      uint16_t RSTEN      :  1;  /**< Counter and Prescale Reset Enable */
      uint16_t SYNCBYP    :  1;  /**< Synchronization Bypass */
    };
    uint16_t VALUE16;
  };
} ADI_AGPT0_CON0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT0_CON0_t__ */

/*@}*/

/** @defgroup CLRI0 Clear Interrupt Register. (CLRI0) Register
 *  Clear Interrupt Register. (CLRI0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPT0_CLRI0_Struct
 *! \brief  Clear Interrupt Register. Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT0_CLRI0_t__
typedef struct _ADI_AGPT0_CLRI0_t {
  union {
    struct {
      uint16_t TMOUT      :  1;  /**< Clear Timeout Interrupt */
      uint16_t CAP        :  1;  /**< Clear Captured Event Interrupt */
      uint16_t reserved2  : 14;
    };
    uint16_t VALUE16;
  };
} ADI_AGPT0_CLRI0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT0_CLRI0_t__ */

/*@}*/

/** @defgroup CAP0 Capture Register. (CAP0) Register
 *  Capture Register. (CAP0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPT0_CAP0_Struct
 *! \brief  Capture Register. Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT0_CAP0_t__
typedef struct _ADI_AGPT0_CAP0_t {
  union {
    struct {
      int16_t CAP        : 16;  /**< 16-bit Captured Value */
    };
    int16_t VALUE16;
  };
} ADI_AGPT0_CAP0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT0_CAP0_t__ */

/*@}*/

/** @defgroup ALD0 16-Bit Load Value, Asynchronous. (ALD0) Register
 *  16-Bit Load Value, Asynchronous. (ALD0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPT0_ALD0_Struct
 *! \brief  16-Bit Load Value, Asynchronous. Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT0_ALD0_t__
typedef struct _ADI_AGPT0_ALD0_t {
  union {
    struct {
      int16_t ALOAD      : 16;  /**< Load Value, Asynchronous */
    };
    int16_t VALUE16;
  };
} ADI_AGPT0_ALD0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT0_ALD0_t__ */

/*@}*/

/** @defgroup AVAL0 16-Bit Timer Value, Asynchronous Register. (AVAL0) Register
 *  16-Bit Timer Value, Asynchronous Register. (AVAL0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPT0_AVAL0_Struct
 *! \brief  16-Bit Timer Value, Asynchronous Register. Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT0_AVAL0_t__
typedef struct _ADI_AGPT0_AVAL0_t {
  union {
    struct {
      int16_t AVAL       : 16;  /**< Counter Value */
    };
    int16_t VALUE16;
  };
} ADI_AGPT0_AVAL0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT0_AVAL0_t__ */

/*@}*/

/** @defgroup STA0 Status Register. (STA0) Register
 *  Status Register. (STA0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPT0_STA0_Struct
 *! \brief  Status Register. Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT0_STA0_t__
typedef struct _ADI_AGPT0_STA0_t {
  union {
    struct {
      uint16_t TMOUT      :  1;  /**< Timeout Event Occurred */
      uint16_t CAP        :  1;  /**< Capture Event Pending */
      uint16_t reserved2  :  4;
      uint16_t BUSY       :  1;  /**< Timer Busy */
      uint16_t PDOK       :  1;  /**< Clear Interrupt Register Synchronization */
      uint16_t RSTCNT     :  1;  /**< Counter Reset Occurring */
      uint16_t reserved9  :  7;
    };
    uint16_t VALUE16;
  };
} ADI_AGPT0_STA0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT0_STA0_t__ */

/*@}*/

/** @defgroup PWMCON0 PWM Control Register. (PWMCON0) Register
 *  PWM Control Register. (PWMCON0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPT0_PWMCON0_Struct
 *! \brief  PWM Control Register. Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT0_PWMCON0_t__
typedef struct _ADI_AGPT0_PWMCON0_t {
  union {
    struct {
      uint16_t MATCHEN    :  1;  /**< PWM Match Enabled */
      uint16_t IDLE       :  1;  /**< PWM Idle State */
      uint16_t reserved2  : 14;
    };
    uint16_t VALUE16;
  };
} ADI_AGPT0_PWMCON0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT0_PWMCON0_t__ */

/*@}*/

/** @defgroup PWMMAT0 PWM Match Value Register. (PWMMAT0) Register
 *  PWM Match Value Register. (PWMMAT0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPT0_PWMMAT0_Struct
 *! \brief  PWM Match Value Register. Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT0_PWMMAT0_t__
typedef struct _ADI_AGPT0_PWMMAT0_t {
  union {
    struct {
      int16_t MATCHVAL   : 16;  /**< PWM Match Value */
    };
    int16_t VALUE16;
  };
} ADI_AGPT0_PWMMAT0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT0_PWMMAT0_t__ */

/*@}*/

/** @defgroup INTEN Interrupt Enable (INTEN) Register
 *  Interrupt Enable (INTEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPT0_INTEN_Struct
 *! \brief  Interrupt Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT0_INTEN_t__
typedef struct _ADI_AGPT0_INTEN_t {
  union {
    struct {
      uint16_t INTEN      :  1;  /**< Interrupt Enable */
      uint16_t reserved1  : 15;
    };
    uint16_t VALUE16;
  };
} ADI_AGPT0_INTEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT0_INTEN_t__ */

/*@}*/

/** @defgroup LD1 16-bit Load Value Register (LD1) Register
 *  16-bit Load Value Register (LD1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPT1_LD1_Struct
 *! \brief  16-bit Load Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT1_LD1_t__
typedef struct _ADI_AGPT1_LD1_t {
  union {
    struct {
      int16_t LOAD       : 16;  /**< Load Value */
    };
    int16_t VALUE16;
  };
} ADI_AGPT1_LD1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT1_LD1_t__ */

/*@}*/

/** @defgroup VAL1 16-bit Timer Value Register (VAL1) Register
 *  16-bit Timer Value Register (VAL1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPT1_VAL1_Struct
 *! \brief  16-bit Timer Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT1_VAL1_t__
typedef struct _ADI_AGPT1_VAL1_t {
  union {
    struct {
      int16_t VAL        : 16;  /**< Current Count */
    };
    int16_t VALUE16;
  };
} ADI_AGPT1_VAL1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT1_VAL1_t__ */

/*@}*/

/** @defgroup CON1 Control Register (CON1) Register
 *  Control Register (CON1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPT1_CON1_Struct
 *! \brief  Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT1_CON1_t__
typedef struct _ADI_AGPT1_CON1_t {
  union {
    struct {
      uint16_t PRE        :  2;  /**< Prescaler */
      uint16_t UP         :  1;  /**< Count up */
      uint16_t MOD        :  1;  /**< Timer Mode */
      uint16_t ENABLE     :  1;  /**< Timer Enable */
      uint16_t CLK        :  2;  /**< Clock Select */
      uint16_t RLD        :  1;  /**< Reload Control */
      uint16_t EVENT      :  5;  /**< Event Select Range */
      uint16_t EVENTEN    :  1;  /**< Event Select */
      uint16_t RSTEN      :  1;  /**< Counter and Prescale Reset Enable */
      uint16_t SYNCBYP    :  1;  /**< Synchronization Bypass */
    };
    uint16_t VALUE16;
  };
} ADI_AGPT1_CON1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT1_CON1_t__ */

/*@}*/

/** @defgroup CLRI1 Clear Interrupt Register (CLRI1) Register
 *  Clear Interrupt Register (CLRI1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPT1_CLRI1_Struct
 *! \brief  Clear Interrupt Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT1_CLRI1_t__
typedef struct _ADI_AGPT1_CLRI1_t {
  union {
    struct {
      uint16_t TMOUT      :  1;  /**< Clear Timeout Interrupt */
      uint16_t CAP        :  1;  /**< Clear Captured Event Interrupt */
      uint16_t reserved2  : 14;
    };
    uint16_t VALUE16;
  };
} ADI_AGPT1_CLRI1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT1_CLRI1_t__ */

/*@}*/

/** @defgroup CAP1 Capture Register (CAP1) Register
 *  Capture Register (CAP1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPT1_CAP1_Struct
 *! \brief  Capture Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT1_CAP1_t__
typedef struct _ADI_AGPT1_CAP1_t {
  union {
    struct {
      int16_t CAP        : 16;  /**< 16-bit Captured Value. */
    };
    int16_t VALUE16;
  };
} ADI_AGPT1_CAP1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT1_CAP1_t__ */

/*@}*/

/** @defgroup ALD1 16-bit Load Value, Asynchronous Register (ALD1) Register
 *  16-bit Load Value, Asynchronous Register (ALD1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPT1_ALD1_Struct
 *! \brief  16-bit Load Value, Asynchronous Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT1_ALD1_t__
typedef struct _ADI_AGPT1_ALD1_t {
  union {
    struct {
      int16_t ALOAD      : 16;  /**< Load Value, Asynchronous */
    };
    int16_t VALUE16;
  };
} ADI_AGPT1_ALD1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT1_ALD1_t__ */

/*@}*/

/** @defgroup AVAL1 16-bit Timer Value, Asynchronous Register (AVAL1) Register
 *  16-bit Timer Value, Asynchronous Register (AVAL1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPT1_AVAL1_Struct
 *! \brief  16-bit Timer Value, Asynchronous Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT1_AVAL1_t__
typedef struct _ADI_AGPT1_AVAL1_t {
  union {
    struct {
      int16_t AVAL       : 16;  /**< Counter Value */
    };
    int16_t VALUE16;
  };
} ADI_AGPT1_AVAL1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT1_AVAL1_t__ */

/*@}*/

/** @defgroup STA1 Status Register (STA1) Register
 *  Status Register (STA1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPT1_STA1_Struct
 *! \brief  Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT1_STA1_t__
typedef struct _ADI_AGPT1_STA1_t {
  union {
    struct {
      uint16_t TMOUT      :  1;  /**< Timeout Event Occurred */
      uint16_t CAP        :  1;  /**< Capture Event Pending */
      uint16_t reserved2  :  4;
      uint16_t BUSY       :  1;  /**< Timer Busy */
      uint16_t PDOK       :  1;  /**< Clear Interrupt Register Synchronization */
      uint16_t RSTCNT     :  1;  /**< Counter Reset Occurring */
      uint16_t reserved9  :  7;
    };
    uint16_t VALUE16;
  };
} ADI_AGPT1_STA1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT1_STA1_t__ */

/*@}*/

/** @defgroup PWMCON1 PWM Control Register (PWMCON1) Register
 *  PWM Control Register (PWMCON1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPT1_PWMCON1_Struct
 *! \brief  PWM Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT1_PWMCON1_t__
typedef struct _ADI_AGPT1_PWMCON1_t {
  union {
    struct {
      uint16_t MATCHEN    :  1;  /**< PWM Match Enabled. */
      uint16_t IDLE       :  1;  /**< PWM Idle State. */
      uint16_t reserved2  : 14;
    };
    uint16_t VALUE16;
  };
} ADI_AGPT1_PWMCON1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT1_PWMCON1_t__ */

/*@}*/

/** @defgroup PWMMAT1 PWM Match Value Register (PWMMAT1) Register
 *  PWM Match Value Register (PWMMAT1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPT1_PWMMAT1_Struct
 *! \brief  PWM Match Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT1_PWMMAT1_t__
typedef struct _ADI_AGPT1_PWMMAT1_t {
  union {
    struct {
      int16_t MATCHVAL   : 16;  /**< PWM Match Value */
    };
    int16_t VALUE16;
  };
} ADI_AGPT1_PWMMAT1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT1_PWMMAT1_t__ */

/*@}*/

/** @defgroup INTEN1 Interrupt Enable (INTEN1) Register
 *  Interrupt Enable (INTEN1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AGPT1_INTEN1_Struct
 *! \brief  Interrupt Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT1_INTEN1_t__
typedef struct _ADI_AGPT1_INTEN1_t {
  union {
    struct {
      uint16_t INTEN      :  1;  /**< Interrupt Enable */
      uint16_t reserved1  : 15;
    };
    uint16_t VALUE16;
  };
} ADI_AGPT1_INTEN1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT1_INTEN1_t__ */

/*@}*/

/** @defgroup CTL CRC Control Register (CTL) Register
 *  CRC Control Register (CTL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFECRC_CTL_Struct
 *! \brief  CRC Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFECRC_CTL_t__
typedef struct _ADI_AFECRC_CTL_t {
  union {
    struct {
      uint32_t EN         :  1;  /**< CRC Peripheral Enable */
      uint32_t LSBFIRST   :  1;  /**< LSB First Calculation Order */
      uint32_t BITMIRR    :  1;  /**< Bit Mirroring. */
      uint32_t BYTMIRR    :  1;  /**< Byte Mirroring. */
      uint32_t W16SWP     :  1;  /**< Word16 Swap Enabled. */
      uint32_t reserved5  :  4;
      uint32_t MON_EN     :  1;  /**< Enable Apb32/Apb16 to Get Address/Data for CRC Calculation */
      uint32_t reserved10 : 18;
      uint32_t RevID      :  4;  /**< Revision ID */
    };
    uint32_t VALUE32;
  };
} ADI_AFECRC_CTL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFECRC_CTL_t__ */

/*@}*/

/** @defgroup IPDATA Data Input. (IPDATA) Register
 *  Data Input. (IPDATA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFECRC_IPDATA_Struct
 *! \brief  Data Input. Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFECRC_IPDATA_t__
typedef struct _ADI_AFECRC_IPDATA_t {
  union {
    struct {
      int32_t VALUE      : 32;  /**< Data Input. */
    };
    int32_t VALUE32;
  };
} ADI_AFECRC_IPDATA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFECRC_IPDATA_t__ */

/*@}*/

/** @defgroup RESULT CRC Residue (RESULT) Register
 *  CRC Residue (RESULT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFECRC_RESULT_Struct
 *! \brief  CRC Residue Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFECRC_RESULT_t__
typedef struct _ADI_AFECRC_RESULT_t {
  union {
    struct {
      int32_t VALUE      : 32;  /**< CRC Residue */
    };
    int32_t VALUE32;
  };
} ADI_AFECRC_RESULT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFECRC_RESULT_t__ */

/*@}*/

/** @defgroup POLY CRC Reduction Polynomial (POLY) Register
 *  CRC Reduction Polynomial (POLY) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFECRC_POLY_Struct
 *! \brief  CRC Reduction Polynomial Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFECRC_POLY_t__
typedef struct _ADI_AFECRC_POLY_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< CRC Reduction Polynomial */
    };
    uint32_t VALUE32;
  };
} ADI_AFECRC_POLY_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFECRC_POLY_t__ */

/*@}*/

/** @defgroup IPBITS Input Data Bits (IPBITS) Register
 *  Input Data Bits (IPBITS) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFECRC_IPBITS_Struct
 *! \brief  Input Data Bits Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFECRC_IPBITS_t__
typedef struct _ADI_AFECRC_IPBITS_t {
  union {
    struct {
      uint8_t DATA_BITS  :  8;  /**< Input Data Bits. */
    };
    uint8_t VALUE8;
  };
} ADI_AFECRC_IPBITS_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFECRC_IPBITS_t__ */

/*@}*/

/** @defgroup IPBYTE Input Data Byte (IPBYTE) Register
 *  Input Data Byte (IPBYTE) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFECRC_IPBYTE_Struct
 *! \brief  Input Data Byte Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFECRC_IPBYTE_t__
typedef struct _ADI_AFECRC_IPBYTE_t {
  union {
    struct {
      uint8_t DATA_BYTE  :  8;  /**< Input Data Byte. */
    };
    uint8_t VALUE8;
  };
} ADI_AFECRC_IPBYTE_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFECRC_IPBYTE_t__ */

/*@}*/

/** @defgroup CRC_SIG_COMP CRC Signature Compare Data Input. (CRC_SIG_COMP) Register
 *  CRC Signature Compare Data Input. (CRC_SIG_COMP) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFECRC_CRC_SIG_COMP_Struct
 *! \brief  CRC Signature Compare Data Input. Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFECRC_CRC_SIG_COMP_t__
typedef struct _ADI_AFECRC_CRC_SIG_COMP_t {
  union {
    struct {
      uint32_t CRC_SIG    : 32;  /**< CRC Signature Compare Data Input. */
    };
    uint32_t VALUE32;
  };
} ADI_AFECRC_CRC_SIG_COMP_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFECRC_CRC_SIG_COMP_t__ */

/*@}*/

/** @defgroup CRCINTEN CRC Error Interrupt Enable Bit (CRCINTEN) Register
 *  CRC Error Interrupt Enable Bit (CRCINTEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFECRC_CRCINTEN_Struct
 *! \brief  CRC Error Interrupt Enable Bit Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFECRC_CRCINTEN_t__
typedef struct _ADI_AFECRC_CRCINTEN_t {
  union {
    struct {
      uint32_t CRC_ERR_EN :  1;  /**< CRC Error Interrupt Enable Bit */
      uint32_t reserved_31_1 : 31;  /**< Reserved */
    };
    uint32_t VALUE32;
  };
} ADI_AFECRC_CRCINTEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFECRC_CRCINTEN_t__ */

/*@}*/

/** @defgroup INTSTA CRC Error Interrupt Status Bit (INTSTA) Register
 *  CRC Error Interrupt Status Bit (INTSTA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFECRC_INTSTA_Struct
 *! \brief  CRC Error Interrupt Status Bit Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFECRC_INTSTA_t__
typedef struct _ADI_AFECRC_INTSTA_t {
  union {
    struct {
      uint32_t CRC_ERR_ST :  1;  /**< CRC Error Interrupt Status Bit */
      uint32_t reserved1  : 31;
    };
    uint32_t VALUE32;
  };
} ADI_AFECRC_INTSTA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFECRC_INTSTA_t__ */

/*@}*/

/** @defgroup AFECON AFE Configuration (AFECON) Register
 *  AFE Configuration (AFECON) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_AFE_AFECON_DACEN
 *! \brief  High Power DAC Enable (DACEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_AFECON_OFF = 0,  /**< High Power DAC Disabled */
  AFE_AFECON_ON  = 1   /**< High Power DAC Enabled  */
} ADI_AFE_AFECON_DACEN;


/* ==========================================================================
 *! \struct ADI_AFE_AFECON_Struct
 *! \brief  AFE Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_AFECON_t__
typedef struct _ADI_AFE_AFECON_t {
  union {
    struct {
      uint32_t reserved0  :  5;
      uint32_t HPREFDIS   :  1;  /**< Disable High Power Reference */
      uint32_t DACEN      :  1;  /**< High Power DAC Enable */
      uint32_t ADCEN      :  1;  /**< ADC Power Enable */
      uint32_t ADCCONVEN  :  1;  /**< ADC Conversion Start Enable */
      uint32_t EXBUFEN    :  1;  /**< Enable Excitation Buffer */
      uint32_t INAMPEN    :  1;  /**< Enable Excitation Amplifier */
      uint32_t TIAEN      :  1;  /**< High Power TIA Enable */
      uint32_t TEMPSENSEN0 :  1;  /**< ADC Temperature Sensor Channel Enable */
      uint32_t TEMPCONVEN  :  1;  /**< ADC Temp Sensor Convert Enable */
      uint32_t WAVEGENEN   :  1;  /**< Waveform Generator Enable */
      uint32_t DFTEN       :  1;  /**< DFT Hardware Accelerator Enable */
      uint32_t SINC2EN     :  1;  /**< ADC Output 50/60Hz Filter Enable */
      uint32_t reserved17   :  2;
      uint32_t ALDOILIMITEN :  1;  /**< Analog LDO Current Limiting Enable */
      uint32_t DACREFEN     :  1;  /**< High Speed DAC Reference Enable */
      uint32_t DACBUFEN     :  1;  /**< Enable DC DAC Buffer */
      uint32_t reserved22   : 10;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_AFECON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_AFECON_t__ */

/*@}*/

/** @defgroup SWCON Switch Matrix Configuration (SWCON) Register
 *  Switch Matrix Configuration (SWCON) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_SWCON_Struct
 *! \brief  Switch Matrix Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_SWCON_t__
typedef struct _ADI_AFE_SWCON_t {
  union {
    struct {
      uint32_t DMUXCON    :  4;  /**< Control of D Switch MUX */
      uint32_t PMUXCON    :  4;  /**< Control of P Switch MUX */
      uint32_t NMUXCON    :  4;  /**< Control of N Switch MUX */
      uint32_t TMUXCON    :  4;  /**< Control of T Switch MUX. */
      uint32_t SWSOURCESEL :  1;  /**< Switch Control Select */
      uint32_t T9CON       :  1;  /**< Control of T[9] */
      uint32_t T10CON      :  1;  /**< Control of T[10] */
      uint32_t T11CON      :  1;  /**< Control of T[11] */
      uint32_t reserved20  : 12;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_SWCON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_SWCON_t__ */

/*@}*/

/** @defgroup HSDACCON High Speed DAC Configuration (HSDACCON) Register
 *  High Speed DAC Configuration (HSDACCON) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_HSDACCON_Struct
 *! \brief  High Speed DAC Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_HSDACCON_t__
typedef struct _ADI_AFE_HSDACCON_t {
  union {
    struct {
      uint32_t ATTENEN    :  1;  /**< PGA Stage Gain Attenuation */
      uint32_t RATE       :  8;  /**< DAC Update Rate */
      uint32_t reserved9  :  3;
      uint32_t INAMPGNMDE :  1;  /**< Excitation Amplifier Gain Control */
      uint32_t reserved13 : 19;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_HSDACCON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_HSDACCON_t__ */

/*@}*/

/** @defgroup WGCON Waveform Generator Configuration (WGCON) Register
 *  Waveform Generator Configuration (WGCON) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_WGCON_Struct
 *! \brief  Waveform Generator Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_WGCON_t__
typedef struct _ADI_AFE_WGCON_t {
  union {
    struct {
      uint32_t reserved0  :  1;
      uint32_t TYPESEL    :  2;  /**< Selects the Type of Waveform */
      uint32_t reserved3    :  1;
      uint32_t DACOFFSETCAL :  1;  /**< Bypass DAC Offset */
      uint32_t DACGAINCAL   :  1;  /**< Bypass DAC Gain */
      uint32_t reserved6    : 26;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_WGCON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_WGCON_t__ */

/*@}*/

/** @defgroup WGFCW Waveform Generator - Sinusoid Frequency Control Word (WGFCW) Register
 *  Waveform Generator - Sinusoid Frequency Control Word (WGFCW) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_WGFCW_Struct
 *! \brief  Waveform Generator - Sinusoid Frequency Control Word Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_WGFCW_t__
typedef struct _ADI_AFE_WGFCW_t {
  union {
    struct {
      uint32_t SINEFCW    : 24;  /**< Sinusoid Generator Frequency Control Word */
      uint32_t reserved24 :  8;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_WGFCW_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_WGFCW_t__ */

/*@}*/

/** @defgroup WGPHASE Waveform Generator - Sinusoid Phase Offset (WGPHASE) Register
 *  Waveform Generator - Sinusoid Phase Offset (WGPHASE) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_WGPHASE_Struct
 *! \brief  Waveform Generator - Sinusoid Phase Offset Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_WGPHASE_t__
typedef struct _ADI_AFE_WGPHASE_t {
  union {
    struct {
      uint32_t SINEOFFSET : 20;  /**< Sinusoid Phase Offset */
      uint32_t reserved20 : 12;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_WGPHASE_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_WGPHASE_t__ */

/*@}*/

/** @defgroup WGOFFSET Waveform Generator - Sinusoid Offset (WGOFFSET) Register
 *  Waveform Generator - Sinusoid Offset (WGOFFSET) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_WGOFFSET_Struct
 *! \brief  Waveform Generator - Sinusoid Offset Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_WGOFFSET_t__
typedef struct _ADI_AFE_WGOFFSET_t {
  union {
    struct {
      uint32_t SINEOFFSET : 12;  /**< Sinusoid Offset */
      uint32_t reserved12 : 20;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_WGOFFSET_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_WGOFFSET_t__ */

/*@}*/

/** @defgroup WGAMPLITUDE Waveform Generator - Sinusoid Amplitude (WGAMPLITUDE) Register
 *  Waveform Generator - Sinusoid Amplitude (WGAMPLITUDE) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_WGAMPLITUDE_Struct
 *! \brief  Waveform Generator - Sinusoid Amplitude Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_WGAMPLITUDE_t__
typedef struct _ADI_AFE_WGAMPLITUDE_t {
  union {
    struct {
      uint32_t SINEAMPLITUDE : 11;  /**< Sinusoid Amplitude */
      uint32_t reserved11    : 21;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_WGAMPLITUDE_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_WGAMPLITUDE_t__ */

/*@}*/

/** @defgroup ADCFILTERCON ADC Output Filters Configuration (ADCFILTERCON) Register
 *  ADC Output Filters Configuration (ADCFILTERCON) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCFILTERCON_Struct
 *! \brief  ADC Output Filters Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCFILTERCON_t__
typedef struct _ADI_AFE_ADCFILTERCON_t {
  union {
    struct {
      uint32_t ADCCLK     :  1;  /**< ADC Data Rate */
      uint32_t reserved1  :  3;
      uint32_t LPFBYPEN   :  1;  /**< 50/60Hz Low Pass Filter */
      uint32_t reserved5  :  1;
      uint32_t SINC3BYP   :  1;  /**< SINC3 Filter Bypass */
      uint32_t AVRGEN     :  1;  /**< Average Function Enable */
      uint32_t SINC2OSR   :  4;  /**< SINC2 OSR */
      uint32_t SINC3OSR   :  2;  /**< SINC3 OSR */
      uint32_t AVRGNUM    :  2;  /**< Number of Samples Averaged */
      uint32_t SINC2CLKENB :  1;  /**< SINC2 Filter Clock Enable */
      uint32_t DACWAVECLKENB :  1;  /**< DAC Wave Clock Enable */
      uint32_t DFTCLKENB     :  1;  /**< DFT Clock Enable */
      uint32_t reserved19    : 13;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCFILTERCON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCFILTERCON_t__ */

/*@}*/

/** @defgroup HSDACDAT HS DAC Code (HSDACDAT) Register
 *  HS DAC Code (HSDACDAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_HSDACDAT_Struct
 *! \brief  HS DAC Code Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_HSDACDAT_t__
typedef struct _ADI_AFE_HSDACDAT_t {
  union {
    struct {
      uint32_t DACDAT     : 12;  /**< DAC Code */
      uint32_t reserved12 : 20;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_HSDACDAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_HSDACDAT_t__ */

/*@}*/

/** @defgroup LPREFBUFCON LPREF_BUF_CON (LPREFBUFCON) Register
 *  LPREF_BUF_CON (LPREFBUFCON) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_LPREFBUFCON_Struct
 *! \brief  LPREF_BUF_CON Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_LPREFBUFCON_t__
typedef struct _ADI_AFE_LPREFBUFCON_t {
  union {
    struct {
      uint32_t LPREFDIS   :  1;  /**< Set This Bit Will Power Down Low Power Bandgap */
      uint32_t LPBUF2P5DIS :  1;  /**< Low Power Bandgap's Output Buffer */
      uint32_t BOOSTCURRENT :  1;  /**< Set: Drive 2 Dac ;Unset Drive 1 Dac, and Save Power */
      uint32_t reserved3    : 29;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_LPREFBUFCON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_LPREFBUFCON_t__ */

/*@}*/

/** @defgroup ADCDAT ADC Raw Result (ADCDAT) Register
 *  ADC Raw Result (ADCDAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCDAT_Struct
 *! \brief  ADC Raw Result Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCDAT_t__
typedef struct _ADI_AFE_ADCDAT_t {
  union {
    struct {
      uint32_t DATA       : 16;  /**< ADC Result */
      uint32_t reserved16 : 16;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCDAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCDAT_t__ */

/*@}*/

/** @defgroup DFTREAL DFT Result, Real Part (DFTREAL) Register
 *  DFT Result, Real Part (DFTREAL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_DFTREAL_Struct
 *! \brief  DFT Result, Real Part Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_DFTREAL_t__
typedef struct _ADI_AFE_DFTREAL_t {
  union {
    struct {
      uint32_t DATA       : 18;  /**< DFT Real */
      uint32_t reserved18 : 14;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_DFTREAL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_DFTREAL_t__ */

/*@}*/

/** @defgroup DFTIMAG DFT Result, Imaginary Part (DFTIMAG) Register
 *  DFT Result, Imaginary Part (DFTIMAG) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_DFTIMAG_Struct
 *! \brief  DFT Result, Imaginary Part Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_DFTIMAG_t__
typedef struct _ADI_AFE_DFTIMAG_t {
  union {
    struct {
      uint32_t DATA       : 18;  /**< DFT Imaginary */
      uint32_t reserved18 : 14;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_DFTIMAG_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_DFTIMAG_t__ */

/*@}*/

/** @defgroup SINC2DAT Supply Rejection Filter Result (SINC2DAT) Register
 *  Supply Rejection Filter Result (SINC2DAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_SINC2DAT_Struct
 *! \brief  Supply Rejection Filter Result Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_SINC2DAT_t__
typedef struct _ADI_AFE_SINC2DAT_t {
  union {
    struct {
      uint32_t DATA       : 16;  /**< LPF Result */
      uint32_t reserved16 : 16;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_SINC2DAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_SINC2DAT_t__ */

/*@}*/

/** @defgroup TEMPSENSDAT Temperature Sensor Result (TEMPSENSDAT) Register
 *  Temperature Sensor Result (TEMPSENSDAT) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_TEMPSENSDAT_Struct
 *! \brief  Temperature Sensor Result Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_TEMPSENSDAT_t__
typedef struct _ADI_AFE_TEMPSENSDAT_t {
  union {
    struct {
      uint32_t DATA       : 16;  /**< Temp Sensor */
      uint32_t reserved16 : 16;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_TEMPSENSDAT_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_TEMPSENSDAT_t__ */

/*@}*/

/** @defgroup ADCINTIEN ADC Interrupt Enable Register (ADCINTIEN) Register
 *  ADC Interrupt Enable Register (ADCINTIEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCINTIEN_Struct
 *! \brief  ADC Interrupt Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCINTIEN_t__
typedef struct _ADI_AFE_ADCINTIEN_t {
  union {
    struct {
      uint32_t ADCRDYIEN  :  1;  /**< ADCDAT Ready Interrupt */
      uint32_t DFTRDYIEN  :  1;  /**< DFT Result Ready Interrupt */
      uint32_t SINC2RDYIEN :  1;  /**< Low Pass Filter Result Interrupt */
      uint32_t TEMPRDYIEN  :  1;  /**< Temp Sensor Interrupt */
      uint32_t ADCMINFAILIEN :  1;  /**< ADCMIN Interrupt */
      uint32_t ADCMAXFAILIEN :  1;  /**< ADCMAX Interrupt */
      uint32_t ADCDELTAFAILIEN :  1;  /**< Delta Interrupt */
      uint32_t MEANIEN         :  1;  /**< Mean Interrupt */
      uint32_t VARIEN          :  1;  /**< Variance Interrupt */
      uint32_t reserved9       : 23;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCINTIEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCINTIEN_t__ */

/*@}*/

/** @defgroup ADCINTSTA ADC Interrupt Status (ADCINTSTA) Register
 *  ADC Interrupt Status (ADCINTSTA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCINTSTA_Struct
 *! \brief  ADC Interrupt Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCINTSTA_t__
typedef struct _ADI_AFE_ADCINTSTA_t {
  union {
    struct {
      uint32_t ADCRDY     :  1;  /**< ADC Result Ready Status */
      uint32_t DFTRDY     :  1;  /**< DFT Result Ready Status */
      uint32_t SINC2RDY   :  1;  /**< Low Pass Filter Result Status */
      uint32_t TEMPRDY    :  1;  /**< Temp Sensor Result Ready */
      uint32_t ADCMINERR  :  1;  /**< ADC Minimum Value */
      uint32_t ADCMAXERR  :  1;  /**< ADC Maximum Value */
      uint32_t ADCDIFFERR :  1;  /**< ADC Delta Ready */
      uint32_t MEANRDY    :  1;  /**< Mean Result Ready */
      uint32_t VARRDY     :  1;  /**< Variance Result Ready */
      uint32_t reserved9  : 23;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCINTSTA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCINTSTA_t__ */

/*@}*/

/** @defgroup AFEGENINTSTA Analog Generation Interrupt (AFEGENINTSTA) Register
 *  Analog Generation Interrupt (AFEGENINTSTA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_AFEGENINTSTA_Struct
 *! \brief  Analog Generation Interrupt Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_AFEGENINTSTA_t__
typedef struct _ADI_AFE_AFEGENINTSTA_t {
  union {
    struct {
      uint32_t CUSTOMIRQ0 :  1;  /**< Custom IRQ 0 */
      uint32_t CUSTOMIRQ1 :  1;  /**< Custom IRQ 1. */
      uint32_t CUSTOMIRQ2 :  1;  /**< Custom IRQ 2 */
      uint32_t CUSTOMIRQ3 :  1;  /**< Custom IRQ 3. */
      uint32_t reserved4  : 28;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_AFEGENINTSTA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_AFEGENINTSTA_t__ */

/*@}*/

/** @defgroup ADCMIN ADC Minimum Value Check (ADCMIN) Register
 *  ADC Minimum Value Check (ADCMIN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCMIN_Struct
 *! \brief  ADC Minimum Value Check Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCMIN_t__
typedef struct _ADI_AFE_ADCMIN_t {
  union {
    struct {
      uint32_t MINVAL     : 16;  /**< ADC Minimum Value Threshold */
      uint32_t reserved16 : 16;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCMIN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCMIN_t__ */

/*@}*/

/** @defgroup ADCMINSM ADCMIN Hysteresis Value (ADCMINSM) Register
 *  ADCMIN Hysteresis Value (ADCMINSM) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCMINSM_Struct
 *! \brief  ADCMIN Hysteresis Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCMINSM_t__
typedef struct _ADI_AFE_ADCMINSM_t {
  union {
    struct {
      uint32_t MINCLRVAL  : 16;  /**< ADCMIN Hysteresis Value */
      uint32_t reserved16 : 16;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCMINSM_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCMINSM_t__ */

/*@}*/

/** @defgroup ADCMAX ADC Maximum Value Check (ADCMAX) Register
 *  ADC Maximum Value Check (ADCMAX) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCMAX_Struct
 *! \brief  ADC Maximum Value Check Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCMAX_t__
typedef struct _ADI_AFE_ADCMAX_t {
  union {
    struct {
      uint32_t MAXVAL     : 16;  /**< ADC Max Threshold */
      uint32_t reserved16 : 16;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCMAX_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCMAX_t__ */

/*@}*/

/** @defgroup ADCMAXSMEN ADCMAX Hysteresis Value (ADCMAXSMEN) Register
 *  ADCMAX Hysteresis Value (ADCMAXSMEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCMAXSMEN_Struct
 *! \brief  ADCMAX Hysteresis Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCMAXSMEN_t__
typedef struct _ADI_AFE_ADCMAXSMEN_t {
  union {
    struct {
      uint32_t MAXSWEN    : 16;  /**< ADCMAX Hysteresis Value */
      uint32_t reserved16 : 16;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCMAXSMEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCMAXSMEN_t__ */

/*@}*/

/** @defgroup ADCDELTA ADC Delta Value (ADCDELTA) Register
 *  ADC Delta Value (ADCDELTA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCDELTA_Struct
 *! \brief  ADC Delta Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCDELTA_t__
typedef struct _ADI_AFE_ADCDELTA_t {
  union {
    struct {
      uint32_t DELTAVAL   : 16;  /**< ADCDAT Code Differences Limit Option */
      uint32_t reserved16 : 16;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCDELTA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCDELTA_t__ */

/*@}*/

/** @defgroup HPOSCCON HPOSC Configuration (HPOSCCON) Register
 *  HPOSC Configuration (HPOSCCON) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_HPOSCCON_Struct
 *! \brief  HPOSC Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_HPOSCCON_t__
typedef struct _ADI_AFE_HPOSCCON_t {
  union {
    struct {
      uint32_t reserved0  :  2;
      uint32_t CLK32MHZEN :  1;  /**< 16M/32M Output Selector Signal. */
      uint32_t reserved3  : 29;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_HPOSCCON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_HPOSCCON_t__ */

/*@}*/

/** @defgroup DFTCON AFE DSP Configuration (DFTCON) Register
 *  AFE DSP Configuration (DFTCON) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_DFTCON_Struct
 *! \brief  AFE DSP Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_DFTCON_t__
typedef struct _ADI_AFE_DFTCON_t {
  union {
    struct {
      uint32_t HANNINGEN  :  1;  /**< Hanning Window Enable */
      uint32_t reserved1  :  3;
      uint32_t DFTNUM     :  4;  /**< ADC Samples Used */
      uint32_t reserved8  : 12;
      uint32_t DFTINSEL   :  2;  /**< DFT Input Select */
      uint32_t reserved22 : 10;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_DFTCON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_DFTCON_t__ */

/*@}*/

/** @defgroup LPTIASW1 ULPTIA Switch Configuration for Channel 1 (LPTIASW1) Register
 *  ULPTIA Switch Configuration for Channel 1 (LPTIASW1) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_AFE_LPTIASW1_TIASWCON
 *! \brief  TIA SW[11:0] Control (TIASWCON) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_LPTIASW1_CAPA_LP     = 20,    /**< CAPA test with LP TIA                                                */
  AFE_LPTIASW1_NORM        = 44,    /**< Normal work mode                                                     */
  AFE_LPTIASW1_DIO         = 45,    /**< Normal work mode with back-back diode enabled.                       */
  AFE_LPTIASW1_SHORTSW     = 46,    /**< Work mode with short switch protection                               */
  AFE_LPTIASW1_LOWNOISE    = 108,   /**< Work mode, vzero-vbias=0.                                            */
  AFE_LPTIASW1_CAPA_RAMP_H = 148,   /**< CAPA test or Ramp test with HP TIA                                   */
  AFE_LPTIASW1_BUFDIS      = 384,   /**< Set PA/TIA as unity gain buffer.                                     */
  AFE_LPTIASW1_BUFEN       = 420,   /**< Set PA/TIA as unity gain buffer. Connect amp's output to CE1 & RC11. */
  AFE_LPTIASW1_TWOLEAD     = 1068,  /**< Two lead sensor, set PA as unity gain buffer.                        */
  AFE_LPTIASW1_BUFEN2      = 1188,  /**< Set PA/TIA as unity gain buffer.                                     */
  AFE_LPTIASW1_SESHORTRE   = 2048   /**< Close SW11 - Short SE1 to RE1,                                       */
} ADI_AFE_LPTIASW1_TIASWCON;


/* ==========================================================================
 *! \struct ADI_AFE_LPTIASW1_Struct
 *! \brief  ULPTIA Switch Configuration for Channel 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_LPTIASW1_t__
typedef struct _ADI_AFE_LPTIASW1_t {
  union {
    struct {
      uint32_t TIASWCON   : 12;  /**< TIA SW[11:0] Control */
      uint32_t PABIASSEL  :  1;  /**< TIA SW12 Control. Active High */
      uint32_t TIABIASSEL :  1;  /**< TIA SW13 Control. Active High */
      uint32_t reserved14 : 18;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_LPTIASW1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_LPTIASW1_t__ */

/*@}*/

/** @defgroup LPTIASW0 ULPTIA Switch Configuration for Channel 0 (LPTIASW0) Register
 *  ULPTIA Switch Configuration for Channel 0 (LPTIASW0) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_AFE_LPTIASW0_TIASWCON
 *! \brief  TIA SW[11:0] Control (TIASWCON) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_LPTIASW0_11        = 20,    /**< CAPA test with LP TIA                                                */
  AFE_LPTIASW0_NORM      = 44,    /**< Normal work mode                                                     */
  AFE_LPTIASW0_DIO       = 45,    /**< Normal work mode with back-back diode enabled.                       */
  AFE_LPTIASW0_SHORTSW   = 46,    /**< Work mode with short switch protection                               */
  AFE_LPTIASW0_LOWNOISE  = 108,   /**< Work mode, vzero-vbias=0.                                            */
  AFE_LPTIASW0_1         = 148,   /**< CAPA test or Ramp test with HP TIA                                   */
  AFE_LPTIASW0_BUFDIS    = 384,   /**< Set PA/TIA as unity gain buffer.                                     */
  AFE_LPTIASW0_BUFEN     = 420,   /**< Set PA/TIA as unity gain buffer. Connect amp's output to CE0 & RC01. */
  AFE_LPTIASW0_TWOLEAD   = 1068,  /**< Two lead sensor, set PA as unity gain buffer.                        */
  AFE_LPTIASW0_BUFEN2    = 1188,  /**< Set PA/TIA as unity gain buffer.                                     */
  AFE_LPTIASW0_SESHORTRE = 2048   /**< Close SW11 - Short SE0 to RE0.                                       */
} ADI_AFE_LPTIASW0_TIASWCON;


/* ==========================================================================
 *! \struct ADI_AFE_LPTIASW0_Struct
 *! \brief  ULPTIA Switch Configuration for Channel 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_LPTIASW0_t__
typedef struct _ADI_AFE_LPTIASW0_t {
  union {
    struct {
      uint32_t TIASWCON   : 12;  /**< TIA SW[11:0] Control */
      uint32_t PABIASSEL  :  1;  /**< TIA SW12 Control. Active High */
      uint32_t TIABIASSEL :  1;  /**< TIA SW13 Control. Active High */
      uint32_t VZEROSHARE :  1;  /**< TIA SW14 Control. Active High */
      uint32_t RECAL      :  1;  /**< TIA SW15 Control. Active High */
      uint32_t reserved16 : 16;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_LPTIASW0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_LPTIASW0_t__ */

/*@}*/

/** @defgroup LPTIACON1 ULPTIA Control Bits Channel 1 (LPTIACON1) Register
 *  ULPTIA Control Bits Channel 1 (LPTIACON1) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_AFE_LPTIACON1_TIAGAIN
 *! \brief  Set RTIA Gain Resistor (TIAGAIN) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_LPTIACON1_DISCONTIA   = 0,   /**< Disconnect TIA Gain resistor */
  AFE_LPTIACON1_TIAGAIN200  = 1,   /**< 200 Ohm                      */
  AFE_LPTIACON1_TIAGAIN1K   = 2,   /**< 1k ohm                       */
  AFE_LPTIACON1_TIAGAIN2K   = 3,   /**< 2k                           */
  AFE_LPTIACON1_TIAGAIN3K   = 4,   /**< 3k                           */
  AFE_LPTIACON1_TIAGAIN4K   = 5,   /**< 4k                           */
  AFE_LPTIACON1_TIAGAIN6K   = 6,   /**< 6k                           */
  AFE_LPTIACON1_TIAGAIN8K   = 7,   /**< 8k                           */
  AFE_LPTIACON1_TIAGAIN10K  = 8,   /**< 10k                          */
  AFE_LPTIACON1_TIAGAIN12K  = 9,   /**< 12k                          */
  AFE_LPTIACON1_TIAGAIN16K  = 10,  /**< 16k                          */
  AFE_LPTIACON1_TIAGAIN20K  = 11,  /**< 20k                          */
  AFE_LPTIACON1_TIAGAIN24K  = 12,  /**< 24k                          */
  AFE_LPTIACON1_TIAGAIN30K  = 13,  /**< 30k                          */
  AFE_LPTIACON1_TIAGAIN32K  = 14,  /**< 32k                          */
  AFE_LPTIACON1_TIAGAIN40K  = 15,  /**< 40k                          */
  AFE_LPTIACON1_TIAGAIN48K  = 16,  /**< 48k                          */
  AFE_LPTIACON1_TIAGAIN64K  = 17,  /**< 64k                          */
  AFE_LPTIACON1_TIAGAIN85K  = 18,  /**< 85k                          */
  AFE_LPTIACON1_TIAGAIN96K  = 19,  /**< 96k                          */
  AFE_LPTIACON1_TIAGAIN100K = 20,  /**< 100k                         */
  AFE_LPTIACON1_TIAGAIN120K = 21,  /**< 120k                         */
  AFE_LPTIACON1_TIAGAIN128K = 22,  /**< 128k                         */
  AFE_LPTIACON1_TIAGAIN160K = 23,  /**< 160k                         */
  AFE_LPTIACON1_TIAGAIN196K = 24,  /**< 196k                         */
  AFE_LPTIACON1_TIAGAIN256K = 25,  /**< 256k                         */
  AFE_LPTIACON1_TIAGAIN512K = 26   /**< 512k                         */
} ADI_AFE_LPTIACON1_TIAGAIN;


/*  =========================================================================
 *! \enum   ADI_AFE_LPTIACON1_TIARL
 *! \brief  Set RLOAD (TIARL) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_LPTIACON1_RL0    = 0,  /**< 0 ohm   */
  AFE_LPTIACON1_RL10   = 1,  /**< 10 ohm  */
  AFE_LPTIACON1_RL30   = 2,  /**< 30 ohm  */
  AFE_LPTIACON1_RL50   = 3,  /**< 50 ohm  */
  AFE_LPTIACON1_RL100  = 4,  /**< 100 ohm */
  AFE_LPTIACON1_RL1P6K = 5,  /**< 1.6kohm */
  AFE_LPTIACON1_RL3P1K = 6,  /**< 3.1kohm */
  AFE_LPTIACON1_RL3P5K = 7   /**< 3.6kohm */
} ADI_AFE_LPTIACON1_TIARL;


/*  =========================================================================
 *! \enum   ADI_AFE_LPTIACON1_TIARF
 *! \brief  Set LPF Resistor (TIARF) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_LPTIACON1_DISCONRF = 0,  /**< Disconnect TIA output from LPF pin */
  AFE_LPTIACON1_BYPRF    = 1,  /**< Bypass resistor                    */
  AFE_LPTIACON1_RF20K    = 2,  /**< 20k Ohm                            */
  AFE_LPTIACON1_RF100K   = 3,  /**< 100k Ohm                           */
  AFE_LPTIACON1_RF200K   = 4,  /**< 200k Ohm                           */
  AFE_LPTIACON1_RF400K   = 5,  /**< 400k Ohm                           */
  AFE_LPTIACON1_RF600K   = 6,  /**< 600k Ohm                           */
  AFE_LPTIACON1_RF1MOHM  = 7   /**< 1Meg Ohm                           */
} ADI_AFE_LPTIACON1_TIARF;


/* ==========================================================================
 *! \struct ADI_AFE_LPTIACON1_Struct
 *! \brief  ULPTIA Control Bits Channel 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_LPTIACON1_t__
typedef struct _ADI_AFE_LPTIACON1_t {
  union {
    struct {
      uint32_t TIAPDEN    :  1;  /**< TIA Power Down */
      uint32_t PAPDEN     :  1;  /**< PA Power Down */
      uint32_t HALFPWR    :  1;  /**< Half Power Mode Select */
      uint32_t IBOOST     :  2;  /**< Current Boost Control */
      uint32_t TIAGAIN    :  5;  /**< Set RTIA Gain Resistor */
      uint32_t TIARL      :  3;  /**< Set RLOAD */
      uint32_t TIARF      :  3;  /**< Set LPF Resistor */
      uint32_t CHOPEN     :  2;  /**< Chopping Enable */
      uint32_t reserved18 : 14;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_LPTIACON1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_LPTIACON1_t__ */

/*@}*/

/** @defgroup LPTIACON0 ULPTIA Control Bits Channel 0 (LPTIACON0) Register
 *  ULPTIA Control Bits Channel 0 (LPTIACON0) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_AFE_LPTIACON0_TIAGAIN
 *! \brief  Set RTIA (TIAGAIN) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_LPTIACON0_DISCONTIA   = 0,   /**< Disconnect TIA Gain resistor */
  AFE_LPTIACON0_TIAGAIN200  = 1,   /**< 200 Ohm                      */
  AFE_LPTIACON0_TIAGAIN1K   = 2,   /**< 1k ohm                       */
  AFE_LPTIACON0_TIAGAIN2K   = 3,   /**< 2k                           */
  AFE_LPTIACON0_TIAGAIN3K   = 4,   /**< 3k                           */
  AFE_LPTIACON0_TIAGAIN4K   = 5,   /**< 4k                           */
  AFE_LPTIACON0_TIAGAIN6K   = 6,   /**< 6k                           */
  AFE_LPTIACON0_TIAGAIN8K   = 7,   /**< 8k                           */
  AFE_LPTIACON0_TIAGAIN10K  = 8,   /**< 10k                          */
  AFE_LPTIACON0_TIAGAIN12K  = 9,   /**< 12k                          */
  AFE_LPTIACON0_TIAGAIN16K  = 10,  /**< 16k                          */
  AFE_LPTIACON0_TIAGAIN20K  = 11,  /**< 20k                          */
  AFE_LPTIACON0_TIAGAIN24K  = 12,  /**< 24k                          */
  AFE_LPTIACON0_TIAGAIN30K  = 13,  /**< 30k                          */
  AFE_LPTIACON0_TIAGAIN32K  = 14,  /**< 32k                          */
  AFE_LPTIACON0_TIAGAIN40K  = 15,  /**< 40k                          */
  AFE_LPTIACON0_TIAGAIN48K  = 16,  /**< 48k                          */
  AFE_LPTIACON0_TIAGAIN64K  = 17,  /**< 64k                          */
  AFE_LPTIACON0_TIAGAIN85K  = 18,  /**< 85k                          */
  AFE_LPTIACON0_TIAGAIN96K  = 19,  /**< 96k                          */
  AFE_LPTIACON0_TIAGAIN100K = 20,  /**< 100k                         */
  AFE_LPTIACON0_TIAGAIN120K = 21,  /**< 120k                         */
  AFE_LPTIACON0_TIAGAIN128K = 22,  /**< 128k                         */
  AFE_LPTIACON0_TIAGAIN160K = 23,  /**< 160k                         */
  AFE_LPTIACON0_TIAGAIN196K = 24,  /**< 196k                         */
  AFE_LPTIACON0_TIAGAIN256K = 25,  /**< 256k                         */
  AFE_LPTIACON0_TIAGAIN512K = 26   /**< 512k                         */
} ADI_AFE_LPTIACON0_TIAGAIN;


/*  =========================================================================
 *! \enum   ADI_AFE_LPTIACON0_TIARL
 *! \brief  Set RLOAD (TIARL) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_LPTIACON0_RL0    = 0,  /**< 0 ohm   */
  AFE_LPTIACON0_RL10   = 1,  /**< 10 ohm  */
  AFE_LPTIACON0_RL30   = 2,  /**< 30 ohm  */
  AFE_LPTIACON0_RL50   = 3,  /**< 50 ohm  */
  AFE_LPTIACON0_RL100  = 4,  /**< 100 ohm */
  AFE_LPTIACON0_RL1P6K = 5,  /**< 1.6kohm */
  AFE_LPTIACON0_RL3P1K = 6,  /**< 3.1kohm */
  AFE_LPTIACON0_RL3P5K = 7   /**< 3.6kohm */
} ADI_AFE_LPTIACON0_TIARL;


/*  =========================================================================
 *! \enum   ADI_AFE_LPTIACON0_TIARF
 *! \brief  Set LPF Resistor (TIARF) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_LPTIACON0_DISCONRF = 0,  /**< Disconnect TIA output from LPF pin */
  AFE_LPTIACON0_BYPRF    = 1,  /**< Bypass resistor                    */
  AFE_LPTIACON0_RF20K    = 2,  /**< 20k Ohm                            */
  AFE_LPTIACON0_RF100K   = 3,  /**< 100k Ohm                           */
  AFE_LPTIACON0_RF200K   = 4,  /**< 200k Ohm                           */
  AFE_LPTIACON0_RF400K   = 5,  /**< 400k Ohm                           */
  AFE_LPTIACON0_RF600K   = 6,  /**< 600k Ohm                           */
  AFE_LPTIACON0_RF1MOHM  = 7   /**< 1Meg Ohm                           */
} ADI_AFE_LPTIACON0_TIARF;


/* ==========================================================================
 *! \struct ADI_AFE_LPTIACON0_Struct
 *! \brief  ULPTIA Control Bits Channel 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_LPTIACON0_t__
typedef struct _ADI_AFE_LPTIACON0_t {
  union {
    struct {
      uint32_t TIAPDEN    :  1;  /**< TIA Power Down */
      uint32_t PAPDEN     :  1;  /**< PA Power Down */
      uint32_t HALFPWR    :  1;  /**< Half Power Mode Select */
      uint32_t IBOOST     :  2;  /**< Current Boost Control */
      uint32_t TIAGAIN    :  5;  /**< Set RTIA */
      uint32_t TIARL      :  3;  /**< Set RLOAD */
      uint32_t TIARF      :  3;  /**< Set LPF Resistor */
      uint32_t CHOPEN     :  2;  /**< Chopping Enable */
      uint32_t reserved18 : 14;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_LPTIACON0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_LPTIACON0_t__ */

/*@}*/

/** @defgroup HSRTIACON High Power RTIA Configuration (HSRTIACON) Register
 *  High Power RTIA Configuration (HSRTIACON) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_HSRTIACON_Struct
 *! \brief  High Power RTIA Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_HSRTIACON_t__
typedef struct _ADI_AFE_HSRTIACON_t {
  union {
    struct {
      uint32_t RTIACON    :  4;  /**< Configure General RTIA Value */
      uint32_t TIASW6CON  :  1;  /**< SW6 Control */
      uint32_t CTIACON    :  8;  /**< Configure Capacitor in Parallel with RTIA */
      uint32_t reserved13 : 19;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_HSRTIACON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_HSRTIACON_t__ */

/*@}*/

/** @defgroup DE1RESCON DE1 HSTIA Resistors Configuration (DE1RESCON) Register
 *  DE1 HSTIA Resistors Configuration (DE1RESCON) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_DE1RESCON_Struct
 *! \brief  DE1 HSTIA Resistors Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_DE1RESCON_t__
typedef struct _ADI_AFE_DE1RESCON_t {
  union {
    struct {
      uint32_t DE1RCON    :  8;  /**< DE1 RLOAD RTIA Setting */
      uint32_t reserved8  : 24;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_DE1RESCON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_DE1RESCON_t__ */

/*@}*/

/** @defgroup DE0RESCON DE0 HSTIA Resistors Configuration (DE0RESCON) Register
 *  DE0 HSTIA Resistors Configuration (DE0RESCON) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_DE0RESCON_Struct
 *! \brief  DE0 HSTIA Resistors Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_DE0RESCON_t__
typedef struct _ADI_AFE_DE0RESCON_t {
  union {
    struct {
      uint32_t DE0RCON    :  8;  /**< DE0 RLOAD RTIA Setting */
      uint32_t reserved8  : 24;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_DE0RESCON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_DE0RESCON_t__ */

/*@}*/

/** @defgroup HSTIACON HSTIA Amplifier Configuration (HSTIACON) Register
 *  HSTIA Amplifier Configuration (HSTIACON) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_HSTIACON_Struct
 *! \brief  HSTIA Amplifier Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_HSTIACON_t__
typedef struct _ADI_AFE_HSTIACON_t {
  union {
    struct {
      uint32_t VBIASSEL   :  2;  /**< Select HSTIA Positive Input */
      uint32_t reserved2  : 30;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_HSTIACON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_HSTIACON_t__ */

/*@}*/

/** @defgroup DACDCBUFCON DAC DC Buffer Configuration (DACDCBUFCON) Register
 *  DAC DC Buffer Configuration (DACDCBUFCON) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_AFE_DACDCBUFCON_CHANSEL
 *! \brief  DAC DC Channel Selection (CHANSEL) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_DACDCBUFCON_CHAN0 = 0,  /**< ULPDAC0 Sets DC level */
  AFE_DACDCBUFCON_CHAN1 = 1   /**< ULPDAC1 Sets DC level */
} ADI_AFE_DACDCBUFCON_CHANSEL;


/* ==========================================================================
 *! \struct ADI_AFE_DACDCBUFCON_Struct
 *! \brief  DAC DC Buffer Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_DACDCBUFCON_t__
typedef struct _ADI_AFE_DACDCBUFCON_t {
  union {
    struct {
      uint32_t Reserved_0 :  1;  /**< Reserved */
      uint32_t CHANSEL    :  1;  /**< DAC DC Channel Selection */
      uint32_t reserved2  : 30;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_DACDCBUFCON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_DACDCBUFCON_t__ */

/*@}*/

/** @defgroup LPDACDAT0 LPDAC Data-out (LPDACDAT0) Register
 *  LPDAC Data-out (LPDACDAT0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_LPDACDAT0_Struct
 *! \brief  LPDAC Data-out Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_LPDACDAT0_t__
typedef struct _ADI_AFE_LPDACDAT0_t {
  union {
    struct {
      uint32_t DACIN12    : 12;  /**< 12BITVAL, 1LSB=537uV */
      uint32_t DACIN6     :  6;  /**< 6BITVAL, 1LSB=34.375mV */
      uint32_t reserved18 : 14;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_LPDACDAT0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_LPDACDAT0_t__ */

/*@}*/

/** @defgroup LPDACSW0 LPDAC0 Switch Control (LPDACSW0) Register
 *  LPDAC0 Switch Control (LPDACSW0) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_AFE_LPDACSW0_LPMODEDIS
 *! \brief  Switch Control (LPMODEDIS) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_LPDACSW0_DACCONBIT5 = 0,  /**< ULPDAC Switch controlled by ULPDACCON0 bit 5 */
  AFE_LPDACSW0_OVRRIDE    = 1   /**< ULPDAC Switches override                     */
} ADI_AFE_LPDACSW0_LPMODEDIS;


/* ==========================================================================
 *! \struct ADI_AFE_LPDACSW0_Struct
 *! \brief  LPDAC0 Switch Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_LPDACSW0_t__
typedef struct _ADI_AFE_LPDACSW0_t {
  union {
    struct {
      uint32_t LPDACSW    :  5;  /**< LPDAC0 Switches Matrix */
      uint32_t LPMODEDIS  :  1;  /**< Switch Control */
      uint32_t reserved6  : 26;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_LPDACSW0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_LPDACSW0_t__ */

/*@}*/

/** @defgroup LPDACCON0 LPDAC Control Bits (LPDACCON0) Register
 *  LPDAC Control Bits (LPDACCON0) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_AFE_LPDACCON0_RSTEN
 *! \brief  Enable Writes to ULPDAC0 (RSTEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_LPDACCON0_WRITEDIS = 0,  /**< Disable ULPDAC0 Writes */
  AFE_LPDACCON0_WRITEEN  = 1   /**< Enable ULPDAC0 Writes  */
} ADI_AFE_LPDACCON0_RSTEN;


/*  =========================================================================
 *! \enum   ADI_AFE_LPDACCON0_PWDEN
 *! \brief  LPDAC0 Power Down (PWDEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_LPDACCON0_PWREN  = 0,  /**< ULPDAC0 Powered On  */
  AFE_LPDACCON0_PWRDIS = 1   /**< ULPDAC0 Powered Off */
} ADI_AFE_LPDACCON0_PWDEN;


/*  =========================================================================
 *! \enum   ADI_AFE_LPDACCON0_REFSEL
 *! \brief  Reference Select Bit (REFSEL) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_LPDACCON0_ULPREF = 0,  /**< ULP2P5V Ref    */
  AFE_LPDACCON0_AVDD   = 1   /**< AVDD Reference */
} ADI_AFE_LPDACCON0_REFSEL;


/*  =========================================================================
 *! \enum   ADI_AFE_LPDACCON0_VBIASMUX
 *! \brief  VBIAS MUX Select (VBIASMUX) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_LPDACCON0_12BIT = 0,  /**< Output 12Bit */
  AFE_LPDACCON0_EN    = 1   /**< output 6Bit  */
} ADI_AFE_LPDACCON0_VBIASMUX;


/*  =========================================================================
 *! \enum   ADI_AFE_LPDACCON0_VZEROMUX
 *! \brief  VZERO MUX Select (VZEROMUX) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_LPDACCON0_BITS6  = 0,  /**< VZERO 6BIT  */
  AFE_LPDACCON0_BITS12 = 1   /**< VZERO 12BIT */
} ADI_AFE_LPDACCON0_VZEROMUX;


/*  =========================================================================
 *! \enum   ADI_AFE_LPDACCON0_DACMDE
 *! \brief  LPDAC0 Switch Settings (DACMDE) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_LPDACCON0_NORM = 0,  /**< ULPDAC0 switches set for normal mode     */
  AFE_LPDACCON0_DIAG = 1   /**< ULPDAC0 switches set for Diagnostic mode */
} ADI_AFE_LPDACCON0_DACMDE;


/*  =========================================================================
 *! \enum   ADI_AFE_LPDACCON0_WAVETYPE
 *! \brief  LPDAC Data Source (WAVETYPE) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_LPDACCON0_MMR     = 0,  /**< Direct from ULPDACDAT0 */
  AFE_LPDACCON0_WAVEGEN = 1   /**< Waveform generator     */
} ADI_AFE_LPDACCON0_WAVETYPE;


/* ==========================================================================
 *! \struct ADI_AFE_LPDACCON0_Struct
 *! \brief  LPDAC Control Bits Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_LPDACCON0_t__
typedef struct _ADI_AFE_LPDACCON0_t {
  union {
    struct {
      uint32_t RSTEN      :  1;  /**< Enable Writes to ULPDAC0 */
      uint32_t PWDEN      :  1;  /**< LPDAC0 Power Down */
      uint32_t REFSEL     :  1;  /**< Reference Select Bit */
      uint32_t VBIASMUX   :  1;  /**< VBIAS MUX Select */
      uint32_t VZEROMUX   :  1;  /**< VZERO MUX Select */
      uint32_t DACMDE     :  1;  /**< LPDAC0 Switch Settings */
      uint32_t WAVETYPE   :  1;  /**< LPDAC Data Source */
      uint32_t reserved7  : 25;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_LPDACCON0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_LPDACCON0_t__ */

/*@}*/

/** @defgroup LPDACDAT1 Low Power DAC1 data register (LPDACDAT1) Register
 *  Low Power DAC1 data register (LPDACDAT1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_LPDACDAT1_Struct
 *! \brief  Low Power DAC1 data Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_LPDACDAT1_t__
typedef struct _ADI_AFE_LPDACDAT1_t {
  union {
    struct {
      uint32_t DACIN12    : 12;  /**< 12BITVAL, 1LSB=537uV */
      uint32_t DACIN6     :  6;  /**< 6BITVAL, 1LSB=34.375mV */
      uint32_t reserved18 : 14;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_LPDACDAT1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_LPDACDAT1_t__ */

/*@}*/

/** @defgroup LPDACSW1 Control register for switches to LPDAC1 (LPDACSW1) Register
 *  Control register for switches to LPDAC1 (LPDACSW1) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_AFE_LPDACSW1_LPMODEDIS
 *! \brief  Switch Control (LPMODEDIS) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_LPDACSW1_DACCONBIT5 = 0,  /**< ULPDAC Switch controlled by ULPDACCON1 bit 5 */
  AFE_LPDACSW1_OVRRIDE    = 1   /**< ULPDAC Switches override                     */
} ADI_AFE_LPDACSW1_LPMODEDIS;


/* ==========================================================================
 *! \struct ADI_AFE_LPDACSW1_Struct
 *! \brief  Control register for switches to LPDAC1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_LPDACSW1_t__
typedef struct _ADI_AFE_LPDACSW1_t {
  union {
    struct {
      uint32_t LPDACSW    :  5;  /**< ULPDAC0 Switches Matrix */
      uint32_t LPMODEDIS  :  1;  /**< Switch Control */
      uint32_t reserved6  : 26;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_LPDACSW1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_LPDACSW1_t__ */

/*@}*/

/** @defgroup LPDACCON1 ULP_DACCON1 (LPDACCON1) Register
 *  ULP_DACCON1 (LPDACCON1) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_AFE_LPDACCON1_RSTEN
 *! \brief  Enable Writes to ULPDAC1 (RSTEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_LPDACCON1_WRITEDIS = 0,  /**< Disable ULPDAC1 Writes */
  AFE_LPDACCON1_WRITEEN  = 1   /**< Enable ULPDAC1 Writes  */
} ADI_AFE_LPDACCON1_RSTEN;


/*  =========================================================================
 *! \enum   ADI_AFE_LPDACCON1_PWDEN
 *! \brief  ULPDAC0 Power (PWDEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_LPDACCON1_PWREN  = 0,  /**< ULPDAC1 Powered On  */
  AFE_LPDACCON1_PWRDIS = 1   /**< ULPDAC1 Powered Off */
} ADI_AFE_LPDACCON1_PWDEN;


/*  =========================================================================
 *! \enum   ADI_AFE_LPDACCON1_REFSEL
 *! \brief  REFSEL (REFSEL) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_LPDACCON1_ULPREF = 0,  /**<  */
  AFE_LPDACCON1_AVDD   = 1   /**<  */
} ADI_AFE_LPDACCON1_REFSEL;


/*  =========================================================================
 *! \enum   ADI_AFE_LPDACCON1_VBIASMUX
 *! \brief  BITSEL (VBIASMUX) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_LPDACCON1_DIS = 0,  /**< 12BIT Output */
  AFE_LPDACCON1_EN  = 1   /**< 6BIT Output  */
} ADI_AFE_LPDACCON1_VBIASMUX;


/*  =========================================================================
 *! \enum   ADI_AFE_LPDACCON1_VZEROMUX
 *! \brief  VZEROOUT (VZEROMUX) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_LPDACCON1_BITS6  = 0,  /**< VZERO 6BIT  */
  AFE_LPDACCON1_BITS12 = 1   /**< VZERO 12BIT */
} ADI_AFE_LPDACCON1_VZEROMUX;


/*  =========================================================================
 *! \enum   ADI_AFE_LPDACCON1_DACMDE
 *! \brief  LPDAC1 Switch Settings (DACMDE) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_LPDACCON1_NORM = 0,  /**< ULPDAC1 switches set for normal mode     */
  AFE_LPDACCON1_DIAG = 1   /**< ULPDAC1 switches set for Diagnostic mode */
} ADI_AFE_LPDACCON1_DACMDE;


/* ==========================================================================
 *! \struct ADI_AFE_LPDACCON1_Struct
 *! \brief  ULP_DACCON1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_LPDACCON1_t__
typedef struct _ADI_AFE_LPDACCON1_t {
  union {
    struct {
      uint32_t RSTEN      :  1;  /**< Enable Writes to ULPDAC1 */
      uint32_t PWDEN      :  1;  /**< ULPDAC0 Power */
      uint32_t REFSEL     :  1;  /**< REFSEL */
      uint32_t VBIASMUX   :  1;  /**< BITSEL */
      uint32_t VZEROMUX   :  1;  /**< VZEROOUT */
      uint32_t DACMDE     :  1;  /**< LPDAC1 Switch Settings */
      uint32_t WAVETYPE   :  1;  /**< DAC Input Source */
      uint32_t reserved7  : 25;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_LPDACCON1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_LPDACCON1_t__ */

/*@}*/

/** @defgroup DSWFULLCON Switch Matrix Full Configuration (D) (DSWFULLCON) Register
 *  Switch Matrix Full Configuration (D) (DSWFULLCON) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_DSWFULLCON_Struct
 *! \brief  Switch Matrix Full Configuration (D) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_DSWFULLCON_t__
typedef struct _ADI_AFE_DSWFULLCON_t {
  union {
    struct {
      uint32_t DR0        :  1;  /**< Control of Dr0 Switch. */
      uint32_t D2         :  1;  /**< Control of D2 Switch. */
      uint32_t D3         :  1;  /**< Control of D3 Switch. */
      uint32_t D4         :  1;  /**< Control of D4 Switch. */
      uint32_t D5         :  1;  /**< Control of D5 Switch. */
      uint32_t D6         :  1;  /**< Control of D6 Switch. */
      uint32_t D7         :  1;  /**< Control of D7 Switch. */
      uint32_t D8         :  1;  /**< Control of D8 Switch. */
      uint32_t reserved8  : 24;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_DSWFULLCON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_DSWFULLCON_t__ */

/*@}*/

/** @defgroup NSWFULLCON Switch Matrix Full Configuration (N) (NSWFULLCON) Register
 *  Switch Matrix Full Configuration (N) (NSWFULLCON) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_NSWFULLCON_Struct
 *! \brief  Switch Matrix Full Configuration (N) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_NSWFULLCON_t__
typedef struct _ADI_AFE_NSWFULLCON_t {
  union {
    struct {
      uint32_t N1         :  1;  /**< Control of N1 Switch. Set Will Close N1, Unset Open */
      uint32_t N2         :  1;  /**< Control of N2 Switch. Set Will Close N2, Unset Open */
      uint32_t N3         :  1;  /**< Control of N3 Switch. Set Will Close N3, Unset Open */
      uint32_t N4         :  1;  /**< Control of N4 Switch. Set Will Close N4, Unset Open */
      uint32_t N5         :  1;  /**< Control of N5 Switch. Set Will Close N5, Unset Open */
      uint32_t N6         :  1;  /**< Control of N6 Switch. Set Will Close N6, Unset Open */
      uint32_t N7         :  1;  /**< Control of N7 Switch. Set Will Close N7, Unset Open */
      uint32_t N8         :  1;  /**< Control of N8 Switch. Set Will Close N8, Unset Open */
      uint32_t N9         :  1;  /**< Control of N9 Switch. Set Will Close N9, Unset Open */
      uint32_t NR1        :  1;  /**< Control of Nr1 Switch. Set Will Close Nr1, Unset Open */
      uint32_t Nl         :  1;  /**< Control of NL Switch. */
      uint32_t NL2        :  1;  /**< Control of NL2 Switch. */
      uint32_t reserved12 : 20;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_NSWFULLCON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_NSWFULLCON_t__ */

/*@}*/

/** @defgroup PSWFULLCON Switch Matrix Full Configuration (P) (PSWFULLCON) Register
 *  Switch Matrix Full Configuration (P) (PSWFULLCON) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_PSWFULLCON_Struct
 *! \brief  Switch Matrix Full Configuration (P) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_PSWFULLCON_t__
typedef struct _ADI_AFE_PSWFULLCON_t {
  union {
    struct {
      uint32_t PR0        :  1;  /**< PR0 Switch Control */
      uint32_t P2         :  1;  /**< Control of P2 Switch. Set Will Close P2, Unset Open */
      uint32_t P3         :  1;  /**< Control of P3 Switch. Set Will Close P3, Unset Open */
      uint32_t P4         :  1;  /**< Control of P4 Switch. Set Will Close P4, Unset Open */
      uint32_t P5         :  1;  /**< Control of P5 Switch. Set Will Close P5, Unset Open */
      uint32_t P6         :  1;  /**< Control of P6 Switch. Set Will Close P6, Unset Open */
      uint32_t P7         :  1;  /**< Control of P7 Switch. Set Will Close P7, Unset Open */
      uint32_t P8         :  1;  /**< Control of P8 Switch. Set Will Close P8, Unset Open */
      uint32_t P9         :  1;  /**< Control of P9 Switch. Set Will Close P9, Unset Open */
      uint32_t P10        :  1;  /**< P10 Switch Control */
      uint32_t P11        :  1;  /**< Control of P11 Switch. Set Will Close P11, Unset Open */
      uint32_t P12        :  1;  /**< Control of P12 Switch. Set Will Close P12, Unset Open */
      uint32_t reserved12 :  1;
      uint32_t PL         :  1;  /**< PL Switch Control */
      uint32_t PL2        :  1;  /**< PL2 Switch Control */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_PSWFULLCON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_PSWFULLCON_t__ */

/*@}*/

/** @defgroup TSWFULLCON Switch Matrix Full Configuration (T) (TSWFULLCON) Register
 *  Switch Matrix Full Configuration (T) (TSWFULLCON) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_TSWFULLCON_Struct
 *! \brief  Switch Matrix Full Configuration (T) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_TSWFULLCON_t__
typedef struct _ADI_AFE_TSWFULLCON_t {
  union {
    struct {
      uint32_t T1         :  1;  /**< Control of T1 Switch. Set Will Close T1, Unset Open */
      uint32_t T2         :  1;  /**< Control of T2 Switch. Set Will Close T2, Unset Open */
      uint32_t T3         :  1;  /**< Control of T3 Switch. Set Will Close T3, Unset Open */
      uint32_t T4         :  1;  /**< Control of T4 Switch. Set Will Close T4, Unset Open */
      uint32_t T5         :  1;  /**< Control of T5 Switch. Set Will Close T5, Unset Open */
      uint32_t reserved5  :  1;
      uint32_t T7         :  1;  /**< Control of T7 Switch. Set Will Close T7, Unset Open */
      uint32_t reserved7  :  1;
      uint32_t T9         :  1;  /**< Control of T9 Switch. Set Will Close T9, Unset Open */
      uint32_t T10        :  1;  /**< Control of T10 Switch. Set Will Close T10, Unset Open */
      uint32_t T11        :  1;  /**< Control of T11 Switch. Set Will Close T11, Unset Open */
      uint32_t TR1        :  1;  /**< Control of Tr1 Switch. Set Will Close Tr1, Unset Open */
      uint32_t reserved12 : 20;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_TSWFULLCON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_TSWFULLCON_t__ */

/*@}*/

/** @defgroup TEMPCON0 Temp Sensor Configuration (TEMPCON0) Register
 *  Temp Sensor Configuration (TEMPCON0) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_AFE_TEMPCON0_CHOPCON
 *! \brief  Temp Sensor Chop Mode (CHOPCON) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_TEMPCON0_DIS = 0,  /**< Disable chop */
  AFE_TEMPCON0_EN  = 1   /**< Enable chop  */
} ADI_AFE_TEMPCON0_CHOPCON;


/* ==========================================================================
 *! \struct ADI_AFE_TEMPCON0_Struct
 *! \brief  Temp Sensor Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_TEMPCON0_t__
typedef struct _ADI_AFE_TEMPCON0_t {
  union {
    struct {
      uint32_t ENABLE     :  1;  /**< Unused */
      uint32_t CHOPCON    :  1;  /**< Temp Sensor Chop Mode */
      uint32_t CHOPFRESEL :  2;  /**< Chop Mode Frequency Setting */
      uint32_t reserved4  : 28;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_TEMPCON0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_TEMPCON0_t__ */

/*@}*/

/** @defgroup BUFSENCON HP and LP Buffer Control (BUFSENCON) Register
 *  HP and LP Buffer Control (BUFSENCON) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_AFE_BUFSENCON_V1P8HPADCEN
 *! \brief  HP 1.8V Reference Buffer (V1P8HPADCEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_BUFSENCON_HPBUF_DIS = 0,  /**< Disable 1.8V HP ADC Reference Buffer */
  AFE_BUFSENCON_HPBUF_EN  = 1   /**< Enable 1.8V HP ADC Reference Buffer  */
} ADI_AFE_BUFSENCON_V1P8HPADCEN;


/*  =========================================================================
 *! \enum   ADI_AFE_BUFSENCON_V1P8HPADCILIMITEN
 *! \brief  HP ADC Input Current Limit (V1P8HPADCILIMITEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_BUFSENCON_LIMIT_DIS = 0,  /**< Disable buffer Current Limit */
  AFE_BUFSENCON_LIMIT_EN  = 1   /**< Enable buffer Current Limit  */
} ADI_AFE_BUFSENCON_V1P8HPADCILIMITEN;


/*  =========================================================================
 *! \enum   ADI_AFE_BUFSENCON_V1P8LPADCEN
 *! \brief  ADC 1.8V LP Reference Buffer (V1P8LPADCEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_BUFSENCON_LPADCREF_DIS = 0,  /**< Disable LP 1.8V Reference Buffer */
  AFE_BUFSENCON_LPADCREF_EN  = 1   /**< Enable LP 1.8V Reference Buffer  */
} ADI_AFE_BUFSENCON_V1P8LPADCEN;


/*  =========================================================================
 *! \enum   ADI_AFE_BUFSENCON_V1P8HPADCCHGDIS
 *! \brief  Controls Decoupling Cap Discharge Switch (V1P8HPADCCHGDIS) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_BUFSENCON_OPEN   = 0,  /**< Open switch  */
  AFE_BUFSENCON_CLOSED = 1   /**< Close Switch */
} ADI_AFE_BUFSENCON_V1P8HPADCCHGDIS;


/*  =========================================================================
 *! \enum   ADI_AFE_BUFSENCON_V1P1HPADCEN
 *! \brief  Enable 1.1V HP CM Buffer (V1P1HPADCEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_BUFSENCON_OFF = 0,  /**< Disable 1.1V HP Common Mode Buffer */
  AFE_BUFSENCON_ON  = 1   /**< Enable 1.1V HP Common Mode Buffer  */
} ADI_AFE_BUFSENCON_V1P1HPADCEN;


/*  =========================================================================
 *! \enum   ADI_AFE_BUFSENCON_V1P1LPADCEN
 *! \brief  ADC 1.1V LP Buffer (V1P1LPADCEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_BUFSENCON_DISABLE = 0,  /**< Disable ADC 1.8V LP Reference Buffer */
  AFE_BUFSENCON_ENABLE  = 1   /**< Enable ADC 1.8V LP Reference Buffer  */
} ADI_AFE_BUFSENCON_V1P1LPADCEN;


/*  =========================================================================
 *! \enum   ADI_AFE_BUFSENCON_V1P1LPADCCHGDIS
 *! \brief  Controls Decoupling Cap Discharge Switch (V1P1LPADCCHGDIS) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_BUFSENCON_ENCHRG  = 0,  /**< Open switch  */
  AFE_BUFSENCON_DISCHRG = 1   /**< Close Switch */
} ADI_AFE_BUFSENCON_V1P1LPADCCHGDIS;


/*  =========================================================================
 *! \enum   ADI_AFE_BUFSENCON_V1P8THERMSTEN
 *! \brief  Buffered Reference Output (V1P8THERMSTEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_BUFSENCON_DIS = 0,  /**< Disable 1.8V Buffered Reference output */
  AFE_BUFSENCON_EN  = 1   /**< Enable 1.8V Buffered Reference output  */
} ADI_AFE_BUFSENCON_V1P8THERMSTEN;


/* ==========================================================================
 *! \struct ADI_AFE_BUFSENCON_Struct
 *! \brief  HP and LP Buffer Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_BUFSENCON_t__
typedef struct _ADI_AFE_BUFSENCON_t {
  union {
    struct {
      uint32_t V1P8HPADCEN :  1;  /**< HP 1.8V Reference Buffer */
      uint32_t V1P8HPADCILIMITEN :  1;  /**< HP ADC Input Current Limit */
      uint32_t V1P8LPADCEN       :  1;  /**< ADC 1.8V LP Reference Buffer */
      uint32_t V1P8HPADCCHGDIS   :  1;  /**< Controls Decoupling Cap Discharge Switch */
      uint32_t V1P1HPADCEN       :  1;  /**< Enable 1.1V HP CM Buffer */
      uint32_t V1P1LPADCEN       :  1;  /**< ADC 1.1V LP Buffer */
      uint32_t V1P1LPADCCHGDIS   :  1;  /**< Controls Decoupling Cap Discharge Switch */
      uint32_t reserved7         :  1;
      uint32_t V1P8THERMSTEN     :  1;  /**< Buffered Reference Output */
      uint32_t reserved9         : 23;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_BUFSENCON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_BUFSENCON_t__ */

/*@}*/

/** @defgroup ADCCON ADC Configuration (ADCCON) Register
 *  ADC Configuration (ADCCON) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_AFE_ADCCON_MUXSELP
 *! \brief  Select Positive Input (MUXSELP) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_ADCCON_RESERVED = 17   /**< Reserved */
} ADI_AFE_ADCCON_MUXSELP;


/* ==========================================================================
 *! \struct ADI_AFE_ADCCON_Struct
 *! \brief  ADC Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCCON_t__
typedef struct _ADI_AFE_ADCCON_t {
  union {
    struct {
      uint32_t MUXSELP    :  6;  /**< Select Positive Input */
      uint32_t reserved6  :  2;
      uint32_t MUXSELN    :  5;  /**< Select Negative Input */
      uint32_t GNOFFSEL   :  2;  /**< Obsolete */
      uint32_t GNOFSELPGA :  1;  /**< Internal Offset/Gain Cancellation */
      uint32_t GNPGA      :  3;  /**< PGA Gain Setup */
      uint32_t reserved19 : 13;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCCON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCCON_t__ */

/*@}*/

/** @defgroup DSWSTA Switch Matrix Status (D) (DSWSTA) Register
 *  Switch Matrix Status (D) (DSWSTA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_DSWSTA_Struct
 *! \brief  Switch Matrix Status (D) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_DSWSTA_t__
typedef struct _ADI_AFE_DSWSTA_t {
  union {
    struct {
      uint32_t D1STA      :  1;  /**< Status of Dr0 Switch. */
      uint32_t D2STA      :  1;  /**< Status of D2 Switch. */
      uint32_t D3STA      :  1;  /**< Status of D3 Switch. */
      uint32_t D4STA      :  1;  /**< Status of D4 Switch. */
      uint32_t D5STA      :  1;  /**< Status of D5 Switch. */
      uint32_t D6STA      :  1;  /**< Status of D6 Switch. */
      uint32_t D7STA      :  1;  /**< Status of D7 Switch. */
      uint32_t D8STA      :  1;  /**< Status of D8 Switch. */
      uint32_t reserved8  : 24;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_DSWSTA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_DSWSTA_t__ */

/*@}*/

/** @defgroup PSWSTA Switch Matrix Status (P) (PSWSTA) Register
 *  Switch Matrix Status (P) (PSWSTA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_PSWSTA_Struct
 *! \brief  Switch Matrix Status (P) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_PSWSTA_t__
typedef struct _ADI_AFE_PSWSTA_t {
  union {
    struct {
      uint32_t PR0STA     :  1;  /**< PR0 Switch Control */
      uint32_t P2STA      :  1;  /**< Status of P2 Switch. */
      uint32_t P3STA      :  1;  /**< Status of P3 Switch. */
      uint32_t P4STA      :  1;  /**< Status of P4 Switch. */
      uint32_t P5STA      :  1;  /**< Status of P5 Switch. */
      uint32_t P6STA      :  1;  /**< Status of P6 Switch. */
      uint32_t P7STA      :  1;  /**< Status of P7 Switch. */
      uint32_t P8STA      :  1;  /**< Status of P8 Switch. */
      uint32_t P9STA      :  1;  /**< Status of P9 Switch. */
      uint32_t P10STA     :  1;  /**< Status of P10 Switch. */
      uint32_t P11STA     :  1;  /**< Status of P11 Switch. */
      uint32_t P12STA     :  1;  /**< Status of P12 Switch. */
      uint32_t P13STA     :  1;  /**< Status of P13 Switch. */
      uint32_t PLSTA      :  1;  /**< PL Switch Control */
      uint32_t PL2STA     :  1;  /**< PL Switch Control */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_PSWSTA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_PSWSTA_t__ */

/*@}*/

/** @defgroup NSWSTA Switch Matrix Status (N) (NSWSTA) Register
 *  Switch Matrix Status (N) (NSWSTA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_NSWSTA_Struct
 *! \brief  Switch Matrix Status (N) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_NSWSTA_t__
typedef struct _ADI_AFE_NSWSTA_t {
  union {
    struct {
      uint32_t N1STA      :  1;  /**< Status of N1 Switch. */
      uint32_t N2STA      :  1;  /**< Status of N2 Switch. */
      uint32_t N3STA      :  1;  /**< Status of N3 Switch. */
      uint32_t N4STA      :  1;  /**< Status of N4 Switch. */
      uint32_t N5STA      :  1;  /**< Status of N5 Switch. */
      uint32_t N6STA      :  1;  /**< Status of N6 Switch. */
      uint32_t N7STA      :  1;  /**< Status of N7 Switch. */
      uint32_t N8STA      :  1;  /**< Status of N8 Switch. */
      uint32_t N9STA      :  1;  /**< Status of N9 Switch. */
      uint32_t NR1STA     :  1;  /**< Status of NR1 Switch. */
      uint32_t NLSTA      :  1;  /**< Status of NL Switch. */
      uint32_t NL2STA     :  1;  /**< Status of NL2 Switch. */
      uint32_t reserved12 : 20;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_NSWSTA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_NSWSTA_t__ */

/*@}*/

/** @defgroup TSWSTA Switch Matrix Status (T) (TSWSTA) Register
 *  Switch Matrix Status (T) (TSWSTA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_TSWSTA_Struct
 *! \brief  Switch Matrix Status (T) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_TSWSTA_t__
typedef struct _ADI_AFE_TSWSTA_t {
  union {
    struct {
      uint32_t T1STA      :  1;  /**< Status of T1 Switch. */
      uint32_t T2STA      :  1;  /**< Status of T2 Switch. */
      uint32_t T3STA      :  1;  /**< Status of T3 Switch. */
      uint32_t T4STA      :  1;  /**< Status of T4 Switch. */
      uint32_t T5STA      :  1;  /**< Status of T5 Switch. */
      uint32_t T6STA      :  1;  /**< Status of T6 Switch. */
      uint32_t T7STA      :  1;  /**< Status of T7 Switch. */
      uint32_t T8STA      :  1;  /**< Status of T8 Switch. */
      uint32_t T9STA      :  1;  /**< Status of T9 Switch. */
      uint32_t T10STA     :  1;  /**< Status of T10 Switch. */
      uint32_t T11STA     :  1;  /**< Status of T11 Switch. */
      uint32_t TR1STA     :  1;  /**< Status of TR1 Switch. */
      uint32_t reserved12 : 20;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_TSWSTA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_TSWSTA_t__ */

/*@}*/

/** @defgroup STATSVAR Variance Output (STATSVAR) Register
 *  Variance Output (STATSVAR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_STATSVAR_Struct
 *! \brief  Variance Output Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_STATSVAR_t__
typedef struct _ADI_AFE_STATSVAR_t {
  union {
    struct {
      uint32_t VARIANCE   : 31;  /**< Statistical Variance Value */
      uint32_t reserved31 :  1;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_STATSVAR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_STATSVAR_t__ */

/*@}*/

/** @defgroup STATSCON Statistics Control (STATSCON) Register
 *  Statistics Control (STATSCON) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_AFE_STATSCON_STATSEN
 *! \brief  Statistics Enable (STATSEN) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_STATSCON_DIS = 0,  /**< Disable Statistics */
  AFE_STATSCON_EN  = 1   /**< Enable Statistics  */
} ADI_AFE_STATSCON_STATSEN;


/* ==========================================================================
 *! \struct ADI_AFE_STATSCON_Struct
 *! \brief  Statistics Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_STATSCON_t__
typedef struct _ADI_AFE_STATSCON_t {
  union {
    struct {
      uint32_t STATSEN    :  1;  /**< Statistics Enable */
      uint32_t RESRVED    :  3;  /**< Reserved */
      uint32_t SAMPLENUM  :  3;  /**< Sample Size */
      uint32_t STDDEV     :  5;  /**< Standard Deviation Configuration */
      uint32_t reserved12 : 20;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_STATSCON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_STATSCON_t__ */

/*@}*/

/** @defgroup STATSMEAN Statistics Mean Output (STATSMEAN) Register
 *  Statistics Mean Output (STATSMEAN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_STATSMEAN_Struct
 *! \brief  Statistics Mean Output Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_STATSMEAN_t__
typedef struct _ADI_AFE_STATSMEAN_t {
  union {
    struct {
      uint32_t MEAN       : 16;  /**< Mean Output */
      uint32_t reserved16 : 16;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_STATSMEAN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_STATSMEAN_t__ */

/*@}*/

/** @defgroup REPEATADCCNV REPEAT ADC Conversions (REPEATADCCNV) Register
 *  REPEAT ADC Conversions (REPEATADCCNV) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_AFE_REPEATADCCNV_EN
 *! \brief  Enable Repeat ADC Conversions (EN) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_REPEATADCCNV_DIS = 0,  /**< Disable Repeat ADC Conversions */
  AFE_REPEATADCCNV_EN  = 1   /**< Enable Repeat ADC Conversions  */
} ADI_AFE_REPEATADCCNV_EN;


/* ==========================================================================
 *! \struct ADI_AFE_REPEATADCCNV_Struct
 *! \brief  REPEAT ADC Conversions Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_REPEATADCCNV_t__
typedef struct _ADI_AFE_REPEATADCCNV_t {
  union {
    struct {
      uint32_t EN         :  1;  /**< Enable Repeat ADC Conversions */
      uint32_t reserved1  :  3;
      uint32_t NUM        :  8;  /**< Repeat Value */
      uint32_t reserved12 : 20;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_REPEATADCCNV_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_REPEATADCCNV_t__ */

/*@}*/

/** @defgroup CALDATLOCK Calibration Data Lock (CALDATLOCK) Register
 *  Calibration Data Lock (CALDATLOCK) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_CALDATLOCK_Struct
 *! \brief  Calibration Data Lock Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_CALDATLOCK_t__
typedef struct _ADI_AFE_CALDATLOCK_t {
  union {
    struct {
      uint32_t KEY        : 32;  /**< Password for Calibration Data Registers */
    };
    uint32_t VALUE32;
  };
} ADI_AFE_CALDATLOCK_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_CALDATLOCK_t__ */

/*@}*/

/** @defgroup ADCOFFSETHSTIA ADC Offset Calibration High Speed TIA Channel (ADCOFFSETHSTIA) Register
 *  ADC Offset Calibration High Speed TIA Channel (ADCOFFSETHSTIA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCOFFSETHSTIA_Struct
 *! \brief  ADC Offset Calibration High Speed TIA Channel Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCOFFSETHSTIA_t__
typedef struct _ADI_AFE_ADCOFFSETHSTIA_t {
  union {
    struct {
      uint32_t VALUE      : 15;  /**< HPTIA Offset Calibration */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCOFFSETHSTIA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCOFFSETHSTIA_t__ */

/*@}*/

/** @defgroup ADCGAINTEMPSENS0 ADC Gain Calibration Temp Sensor Channel (ADCGAINTEMPSENS0) Register
 *  ADC Gain Calibration Temp Sensor Channel (ADCGAINTEMPSENS0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCGAINTEMPSENS0_Struct
 *! \brief  ADC Gain Calibration Temp Sensor Channel Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCGAINTEMPSENS0_t__
typedef struct _ADI_AFE_ADCGAINTEMPSENS0_t {
  union {
    struct {
      uint32_t VALUE      : 15;  /**< Gain Calibration Temp Sensor Channel */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCGAINTEMPSENS0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCGAINTEMPSENS0_t__ */

/*@}*/

/** @defgroup ADCOFFSETTEMPSENS0 ADC Offset Calibration Temp Sensor Channel 0 (ADCOFFSETTEMPSENS0) Register
 *  ADC Offset Calibration Temp Sensor Channel 0 (ADCOFFSETTEMPSENS0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCOFFSETTEMPSENS0_Struct
 *! \brief  ADC Offset Calibration Temp Sensor Channel 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCOFFSETTEMPSENS0_t__
typedef struct _ADI_AFE_ADCOFFSETTEMPSENS0_t {
  union {
    struct {
      uint32_t VALUE      : 15;  /**< Offset Calibration Temp Sensor */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCOFFSETTEMPSENS0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCOFFSETTEMPSENS0_t__ */

/*@}*/

/** @defgroup ADCGAINGN1 ADCPGAGN1: ADC Gain Calibration Auxiliary Input Channel (ADCGAINGN1) Register
 *  ADCPGAGN1: ADC Gain Calibration Auxiliary Input Channel (ADCGAINGN1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCGAINGN1_Struct
 *! \brief  ADCPGAGN1: ADC Gain Calibration Auxiliary Input Channel Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCGAINGN1_t__
typedef struct _ADI_AFE_ADCGAINGN1_t {
  union {
    struct {
      uint32_t VALUE      : 15;  /**< Gain Calibration PGA Gain 1x */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCGAINGN1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCGAINGN1_t__ */

/*@}*/

/** @defgroup ADCOFFSETGN1 ADC Offset Calibration Auxiliary Channel (PGA Gain=1) (ADCOFFSETGN1) Register
 *  ADC Offset Calibration Auxiliary Channel (PGA Gain=1) (ADCOFFSETGN1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCOFFSETGN1_Struct
 *! \brief  ADC Offset Calibration Auxiliary Channel (PGA Gain=1) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCOFFSETGN1_t__
typedef struct _ADI_AFE_ADCOFFSETGN1_t {
  union {
    struct {
      uint32_t VALUE      : 15;  /**< Offset Calibration Gain1 */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCOFFSETGN1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCOFFSETGN1_t__ */

/*@}*/

/** @defgroup DACGAIN DACGAIN (DACGAIN) Register
 *  DACGAIN (DACGAIN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_DACGAIN_Struct
 *! \brief  DACGAIN Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_DACGAIN_t__
typedef struct _ADI_AFE_DACGAIN_t {
  union {
    struct {
      uint32_t VALUE      : 12;  /**< HS DAC Gain Correction Factor */
      uint32_t reserved12 : 20;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_DACGAIN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_DACGAIN_t__ */

/*@}*/

/** @defgroup DACOFFSETATTEN DAC Offset with Attenuator Enabled (LP Mode) (DACOFFSETATTEN) Register
 *  DAC Offset with Attenuator Enabled (LP Mode) (DACOFFSETATTEN) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_DACOFFSETATTEN_Struct
 *! \brief  DAC Offset with Attenuator Enabled (LP Mode) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_DACOFFSETATTEN_t__
typedef struct _ADI_AFE_DACOFFSETATTEN_t {
  union {
    struct {
      uint32_t VALUE      : 12;  /**< DAC Offset Correction Factor */
      uint32_t reserved12 : 20;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_DACOFFSETATTEN_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_DACOFFSETATTEN_t__ */

/*@}*/

/** @defgroup DACOFFSET DAC Offset with Attenuator Disabled (LP Mode) (DACOFFSET) Register
 *  DAC Offset with Attenuator Disabled (LP Mode) (DACOFFSET) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_DACOFFSET_Struct
 *! \brief  DAC Offset with Attenuator Disabled (LP Mode) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_DACOFFSET_t__
typedef struct _ADI_AFE_DACOFFSET_t {
  union {
    struct {
      uint32_t VALUE      : 12;  /**< DAC Offset Correction Factor */
      uint32_t reserved12 : 20;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_DACOFFSET_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_DACOFFSET_t__ */

/*@}*/

/** @defgroup ADCGAINGN1P5 ADC Gain Calibration Auxiliary Input Channel (PGA Gain=1.5) (ADCGAINGN1P5) Register
 *  ADC Gain Calibration Auxiliary Input Channel (PGA Gain=1.5) (ADCGAINGN1P5) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCGAINGN1P5_Struct
 *! \brief  ADC Gain Calibration Auxiliary Input Channel (PGA Gain=1.5) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCGAINGN1P5_t__
typedef struct _ADI_AFE_ADCGAINGN1P5_t {
  union {
    struct {
      uint32_t VALUE      : 15;  /**< Gain Calibration PGA Gain 1.5x */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCGAINGN1P5_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCGAINGN1P5_t__ */

/*@}*/

/** @defgroup ADCGAINGN2 ADC Gain Calibration Auxiliary Input Channel (PGA Gain=2) (ADCGAINGN2) Register
 *  ADC Gain Calibration Auxiliary Input Channel (PGA Gain=2) (ADCGAINGN2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCGAINGN2_Struct
 *! \brief  ADC Gain Calibration Auxiliary Input Channel (PGA Gain=2) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCGAINGN2_t__
typedef struct _ADI_AFE_ADCGAINGN2_t {
  union {
    struct {
      uint32_t VALUE      : 15;  /**< Gain Calibration PGA Gain 2x */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCGAINGN2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCGAINGN2_t__ */

/*@}*/

/** @defgroup ADCGAINGN4 ADC Gain Calibration Auxiliary Input Channel (PGA Gain=4) (ADCGAINGN4) Register
 *  ADC Gain Calibration Auxiliary Input Channel (PGA Gain=4) (ADCGAINGN4) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCGAINGN4_Struct
 *! \brief  ADC Gain Calibration Auxiliary Input Channel (PGA Gain=4) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCGAINGN4_t__
typedef struct _ADI_AFE_ADCGAINGN4_t {
  union {
    struct {
      uint32_t VALUE      : 15;  /**< Gain Calibration PGA Gain 4x */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCGAINGN4_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCGAINGN4_t__ */

/*@}*/

/** @defgroup ADCPGAOFFSETCANCEL ADC Offset Cancellation (Optional) (ADCPGAOFFSETCANCEL) Register
 *  ADC Offset Cancellation (Optional) (ADCPGAOFFSETCANCEL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCPGAOFFSETCANCEL_Struct
 *! \brief  ADC Offset Cancellation (Optional) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCPGAOFFSETCANCEL_t__
typedef struct _ADI_AFE_ADCPGAOFFSETCANCEL_t {
  union {
    struct {
      uint32_t OFFSETCANCEL : 15;  /**< Offset Cancellation */
      uint32_t reserved15   : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCPGAOFFSETCANCEL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCPGAOFFSETCANCEL_t__ */

/*@}*/

/** @defgroup ADCGNHSTIA ADC Gain Calibration for HS TIA Channel (ADCGNHSTIA) Register
 *  ADC Gain Calibration for HS TIA Channel (ADCGNHSTIA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCGNHSTIA_Struct
 *! \brief  ADC Gain Calibration for HS TIA Channel Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCGNHSTIA_t__
typedef struct _ADI_AFE_ADCGNHSTIA_t {
  union {
    struct {
      uint32_t VALUE      : 15;  /**< Gain Error Calibration HS TIA Channel */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCGNHSTIA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCGNHSTIA_t__ */

/*@}*/

/** @defgroup ADCOFFSETLPTIA0 ADC Offset Calibration ULP-TIA0 Channel (ADCOFFSETLPTIA0) Register
 *  ADC Offset Calibration ULP-TIA0 Channel (ADCOFFSETLPTIA0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCOFFSETLPTIA0_Struct
 *! \brief  ADC Offset Calibration ULP-TIA0 Channel Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCOFFSETLPTIA0_t__
typedef struct _ADI_AFE_ADCOFFSETLPTIA0_t {
  union {
    struct {
      uint32_t VALUE      : 15;  /**< Offset Calibration for ULP-TIA0 */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCOFFSETLPTIA0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCOFFSETLPTIA0_t__ */

/*@}*/

/** @defgroup ADCGNLPTIA0 ADC GAIN Calibration for LP TIA0 Channel (ADCGNLPTIA0) Register
 *  ADC GAIN Calibration for LP TIA0 Channel (ADCGNLPTIA0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCGNLPTIA0_Struct
 *! \brief  ADC GAIN Calibration for LP TIA0 Channel Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCGNLPTIA0_t__
typedef struct _ADI_AFE_ADCGNLPTIA0_t {
  union {
    struct {
      uint32_t VALUE      : 15;  /**< Gain Error Calibration ULPTIA0 */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCGNLPTIA0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCGNLPTIA0_t__ */

/*@}*/

/** @defgroup ADCPGAGN4OFCAL ADC Gain Calibration with DC Cancellation(PGA G=4) (ADCPGAGN4OFCAL) Register
 *  ADC Gain Calibration with DC Cancellation(PGA G=4) (ADCPGAGN4OFCAL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCPGAGN4OFCAL_Struct
 *! \brief  ADC Gain Calibration with DC Cancellation(PGA G=4) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCPGAGN4OFCAL_t__
typedef struct _ADI_AFE_ADCPGAGN4OFCAL_t {
  union {
    struct {
      uint32_t ADCGAINAUX : 15;  /**< DC Calibration Gain=4 */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCPGAGN4OFCAL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCPGAGN4OFCAL_t__ */

/*@}*/

/** @defgroup ADCGAINGN9 ADC Gain Calibration Auxiliary Input Channel (PGA Gain=9) (ADCGAINGN9) Register
 *  ADC Gain Calibration Auxiliary Input Channel (PGA Gain=9) (ADCGAINGN9) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCGAINGN9_Struct
 *! \brief  ADC Gain Calibration Auxiliary Input Channel (PGA Gain=9) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCGAINGN9_t__
typedef struct _ADI_AFE_ADCGAINGN9_t {
  union {
    struct {
      uint32_t VALUE      : 15;  /**< Gain Calibration PGA Gain 9x */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCGAINGN9_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCGAINGN9_t__ */

/*@}*/

/** @defgroup ADCOFFSETEMPSENS1 ADC Offset Calibration  Temp Sensor Channel 1 (ADCOFFSETEMPSENS1) Register
 *  ADC Offset Calibration  Temp Sensor Channel 1 (ADCOFFSETEMPSENS1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCOFFSETEMPSENS1_Struct
 *! \brief  ADC Offset Calibration  Temp Sensor Channel 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCOFFSETEMPSENS1_t__
typedef struct _ADI_AFE_ADCOFFSETEMPSENS1_t {
  union {
    struct {
      uint32_t VALUE      : 15;  /**< Offset Calibration Temp Sensor */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCOFFSETEMPSENS1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCOFFSETEMPSENS1_t__ */

/*@}*/

/** @defgroup ADCGAINTEMPSENS1 ADC Gain Calibration Temperature Sensor Channel (ADCGAINTEMPSENS1) Register
 *  ADC Gain Calibration Temperature Sensor Channel (ADCGAINTEMPSENS1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCGAINTEMPSENS1_Struct
 *! \brief  ADC Gain Calibration Temperature Sensor Channel Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCGAINTEMPSENS1_t__
typedef struct _ADI_AFE_ADCGAINTEMPSENS1_t {
  union {
    struct {
      uint32_t VALUE      : 15;  /**< Gain Calibration for Diode Temp Sensor */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCGAINTEMPSENS1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCGAINTEMPSENS1_t__ */

/*@}*/

/** @defgroup DACOFFSETATTENHP DAC Offset with Attenuator Enabled (HP Mode) (DACOFFSETATTENHP) Register
 *  DAC Offset with Attenuator Enabled (HP Mode) (DACOFFSETATTENHP) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_DACOFFSETATTENHP_Struct
 *! \brief  DAC Offset with Attenuator Enabled (HP Mode) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_DACOFFSETATTENHP_t__
typedef struct _ADI_AFE_DACOFFSETATTENHP_t {
  union {
    struct {
      uint32_t VALUE      : 12;  /**< DAC Offset Correction Factor */
      uint32_t reserved12 : 20;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_DACOFFSETATTENHP_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_DACOFFSETATTENHP_t__ */

/*@}*/

/** @defgroup DACOFFSETHP DAC Offset with Attenuator Disabled (HP Mode) (DACOFFSETHP) Register
 *  DAC Offset with Attenuator Disabled (HP Mode) (DACOFFSETHP) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_DACOFFSETHP_Struct
 *! \brief  DAC Offset with Attenuator Disabled (HP Mode) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_DACOFFSETHP_t__
typedef struct _ADI_AFE_DACOFFSETHP_t {
  union {
    struct {
      uint32_t VALUE      : 12;  /**< DAC Offset Correction Factor */
      uint32_t reserved12 : 20;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_DACOFFSETHP_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_DACOFFSETHP_t__ */

/*@}*/

/** @defgroup ADCOFFSETLPTIA1 ADC Offset Calibration LP TIA1 Channel (ADCOFFSETLPTIA1) Register
 *  ADC Offset Calibration LP TIA1 Channel (ADCOFFSETLPTIA1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCOFFSETLPTIA1_Struct
 *! \brief  ADC Offset Calibration LP TIA1 Channel Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCOFFSETLPTIA1_t__
typedef struct _ADI_AFE_ADCOFFSETLPTIA1_t {
  union {
    struct {
      uint32_t VALUE      : 15;  /**< Offset Calibration for ULP-TIA1 */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCOFFSETLPTIA1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCOFFSETLPTIA1_t__ */

/*@}*/

/** @defgroup ADCGNLPTIA1 ADC GAIN Calibration for LP TIA1 Channel (ADCGNLPTIA1) Register
 *  ADC GAIN Calibration for LP TIA1 Channel (ADCGNLPTIA1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCGNLPTIA1_Struct
 *! \brief  ADC GAIN Calibration for LP TIA1 Channel Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCGNLPTIA1_t__
typedef struct _ADI_AFE_ADCGNLPTIA1_t {
  union {
    struct {
      uint32_t ULPTIA1GN  : 15;  /**< Gain Calibration ULP-TIA1 */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCGNLPTIA1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCGNLPTIA1_t__ */

/*@}*/

/** @defgroup ADCOFFSETGN2 Offset Calibration Auxiliary Channel (PGA Gain =2) (ADCOFFSETGN2) Register
 *  Offset Calibration Auxiliary Channel (PGA Gain =2) (ADCOFFSETGN2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCOFFSETGN2_Struct
 *! \brief  Offset Calibration Auxiliary Channel (PGA Gain =2) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCOFFSETGN2_t__
typedef struct _ADI_AFE_ADCOFFSETGN2_t {
  union {
    struct {
      uint32_t VALUE      : 15;  /**< Offset Calibration Auxiliary Channel (PGA Gain =2) */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCOFFSETGN2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCOFFSETGN2_t__ */

/*@}*/

/** @defgroup ADCOFFSETGN1P5 Offset Calibration Auxiliary Channel (PGA Gain =1.5) (ADCOFFSETGN1P5) Register
 *  Offset Calibration Auxiliary Channel (PGA Gain =1.5) (ADCOFFSETGN1P5) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCOFFSETGN1P5_Struct
 *! \brief  Offset Calibration Auxiliary Channel (PGA Gain =1.5) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCOFFSETGN1P5_t__
typedef struct _ADI_AFE_ADCOFFSETGN1P5_t {
  union {
    struct {
      uint32_t VALUE      : 15;  /**< Offset Calibration Gain1.5 */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCOFFSETGN1P5_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCOFFSETGN1P5_t__ */

/*@}*/

/** @defgroup ADCOFFSETGN9 Offset Calibration Auxiliary Channel (PGA Gain =9) (ADCOFFSETGN9) Register
 *  Offset Calibration Auxiliary Channel (PGA Gain =9) (ADCOFFSETGN9) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCOFFSETGN9_Struct
 *! \brief  Offset Calibration Auxiliary Channel (PGA Gain =9) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCOFFSETGN9_t__
typedef struct _ADI_AFE_ADCOFFSETGN9_t {
  union {
    struct {
      uint32_t VALUE      : 15;  /**< Offset Calibration Gain9 */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCOFFSETGN9_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCOFFSETGN9_t__ */

/*@}*/

/** @defgroup ADCOFFSETGN4 Offset Calibration Auxiliary Channel (PGA Gain =4) (ADCOFFSETGN4) Register
 *  Offset Calibration Auxiliary Channel (PGA Gain =4) (ADCOFFSETGN4) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCOFFSETGN4_Struct
 *! \brief  Offset Calibration Auxiliary Channel (PGA Gain =4) Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCOFFSETGN4_t__
typedef struct _ADI_AFE_ADCOFFSETGN4_t {
  union {
    struct {
      uint32_t VALUE      : 15;  /**< Offset Calibration Gain4 */
      uint32_t reserved15 : 17;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCOFFSETGN4_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCOFFSETGN4_t__ */

/*@}*/

/** @defgroup PMBW Power Mode Configuration (PMBW) Register
 *  Power Mode Configuration (PMBW) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_AFE_PMBW_SYSHP
 *! \brief  Set High Speed DAC and ADC in High Power Mode (SYSHP) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_PMBW_LP = 0,  /**< LP mode */
  AFE_PMBW_HP = 1   /**< HP mode */
} ADI_AFE_PMBW_SYSHP;


/*  =========================================================================
 *! \enum   ADI_AFE_PMBW_SYSBW
 *! \brief  Configure System Bandwidth (SYSBW) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_PMBW_BWNA  = 0,  /**< no action for system configuration */
  AFE_PMBW_BW50  = 1,  /**< 50kHz -3dB bandwidth               */
  AFE_PMBW_BW100 = 2,  /**< 100kHz -3dB bandwidth              */
  AFE_PMBW_BW250 = 3   /**< 250kHz -3dB bandwidth              */
} ADI_AFE_PMBW_SYSBW;


/* ==========================================================================
 *! \struct ADI_AFE_PMBW_Struct
 *! \brief  Power Mode Configuration Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_PMBW_t__
typedef struct _ADI_AFE_PMBW_t {
  union {
    struct {
      uint32_t SYSHP      :  1;  /**< Set High Speed DAC and ADC in High Power Mode */
      uint32_t reserved1  :  1;
      uint32_t SYSBW      :  2;  /**< Configure System Bandwidth */
      uint32_t reserved4  : 28;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_PMBW_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_PMBW_t__ */

/*@}*/

/** @defgroup SWMUX Switch Mux for ECG (SWMUX) Register
 *  Switch Mux for ECG (SWMUX) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_SWMUX_Struct
 *! \brief  Switch Mux for ECG Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_SWMUX_t__
typedef struct _ADI_AFE_SWMUX_t {
  union {
    struct {
      uint32_t SWMUX      :  3;  /**< ECG Swmux Control */
      uint32_t CMMUX      :  1;  /**< CM Resistor Select for Ain2, Ain3 */
      uint32_t reserved4  : 28;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_SWMUX_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_SWMUX_t__ */

/*@}*/

/** @defgroup TEMPCON1 AFE_TEMPSEN_DIO (TEMPCON1) Register
 *  AFE_TEMPSEN_DIO (TEMPCON1) Register.
 *  @{
 */

/*  =========================================================================
 *! \enum   ADI_AFE_TEMPCON1_EN
 *! \brief  Test Signal Enable (EN) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_TEMPCON1_ON  = 0,  /**< Turn On  */
  AFE_TEMPCON1_OFF = 1   /**< Turn Off */
} ADI_AFE_TEMPCON1_EN;


/*  =========================================================================
 *! \enum   ADI_AFE_TEMPCON1_PWD
 *! \brief  Power Down Control (PWD) Enumerations
 *  ========================================================================= */
typedef enum
{
  AFE_TEMPCON1_ACTIVE    = 0,  /**<  */
  AFE_TEMPCON1_POWERDOWN = 1   /**<  */
} ADI_AFE_TEMPCON1_PWD;


/* ==========================================================================
 *! \struct ADI_AFE_TEMPCON1_Struct
 *! \brief  AFE_TEMPSEN_DIO Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_TEMPCON1_t__
typedef struct _ADI_AFE_TEMPCON1_t {
  union {
    struct {
      uint32_t ISWCON     : 16;  /**< Bias Current Selection */
      uint32_t EN         :  1;  /**< Test Signal Enable */
      uint32_t PWD        :  1;  /**< Power Down Control */
      uint32_t reserved18 : 14;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_TEMPCON1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_TEMPCON1_t__ */

/*@}*/

/** @defgroup TESTDAC DAC Test (TESTDAC) Register
 *  DAC Test (TESTDAC) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_TESTDAC_Struct
 *! \brief  DAC Test Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_TESTDAC_t__
typedef struct _ADI_AFE_TESTDAC_t {
  union {
    struct {
      uint32_t reserved0  :  2;
      uint32_t LPFBYPEN   :  1;  /**< Bypass Low Pass Filter Between Dac and Buffer */
      uint32_t reserved3  : 29;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_TESTDAC_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_TESTDAC_t__ */

/*@}*/

/** @defgroup ADCBUFCON Configure ADC Input Buffer (ADCBUFCON) Register
 *  Configure ADC Input Buffer (ADCBUFCON) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_AFE_ADCBUFCON_Struct
 *! \brief  Configure ADC Input Buffer Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_ADCBUFCON_t__
typedef struct _ADI_AFE_ADCBUFCON_t {
  union {
    struct {
      uint32_t CHOPDIS    :  4;  /**< Disable Chop */
      uint32_t AMPDIS     :  5;  /**< Disable OpAmp. */
      uint32_t reserved9  : 23;
    };
    uint32_t VALUE32;
  };
} ADI_AFE_ADCBUFCON_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_ADCBUFCON_t__ */

/*@}*/

/** @defgroup INTNUM Interrupt Control Type (INTNUM) Register
 *  Interrupt Control Type (INTNUM) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTNUM_Struct
 *! \brief  Interrupt Control Type Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTNUM_t__
typedef struct _ADI_NVIC_INTNUM_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Interrupt Control Type */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTNUM_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTNUM_t__ */

/*@}*/

/** @defgroup STKSTA Systick Control and Status (STKSTA) Register
 *  Systick Control and Status (STKSTA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_STKSTA_Struct
 *! \brief  Systick Control and Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_STKSTA_t__
typedef struct _ADI_NVIC_STKSTA_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Systick Control and Status */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_STKSTA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_STKSTA_t__ */

/*@}*/

/** @defgroup STKLD Systick Reload Value (STKLD) Register
 *  Systick Reload Value (STKLD) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_STKLD_Struct
 *! \brief  Systick Reload Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_STKLD_t__
typedef struct _ADI_NVIC_STKLD_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Systick Reload Value */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_STKLD_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_STKLD_t__ */

/*@}*/

/** @defgroup STKVAL Systick Current Value (STKVAL) Register
 *  Systick Current Value (STKVAL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_STKVAL_Struct
 *! \brief  Systick Current Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_STKVAL_t__
typedef struct _ADI_NVIC_STKVAL_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Systick Current Value */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_STKVAL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_STKVAL_t__ */

/*@}*/

/** @defgroup STKCAL Systick Calibration Value (STKCAL) Register
 *  Systick Calibration Value (STKCAL) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_STKCAL_Struct
 *! \brief  Systick Calibration Value Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_STKCAL_t__
typedef struct _ADI_NVIC_STKCAL_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Systick Calibration Value */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_STKCAL_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_STKCAL_t__ */

/*@}*/

/** @defgroup INTSETE0 IRQ0..31 Set_Enable (INTSETE0) Register
 *  IRQ0..31 Set_Enable (INTSETE0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTSETE0_Struct
 *! \brief  IRQ0..31 Set_Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTSETE0_t__
typedef struct _ADI_NVIC_INTSETE0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ0..31 Set_Enable */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTSETE0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTSETE0_t__ */

/*@}*/

/** @defgroup INTSETE1 IRQ32..63 Set_Enable (INTSETE1) Register
 *  IRQ32..63 Set_Enable (INTSETE1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTSETE1_Struct
 *! \brief  IRQ32..63 Set_Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTSETE1_t__
typedef struct _ADI_NVIC_INTSETE1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ32..63 Set_Enable */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTSETE1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTSETE1_t__ */

/*@}*/

/** @defgroup INTCLRE0 IRQ0..31 Clear_Enable (INTCLRE0) Register
 *  IRQ0..31 Clear_Enable (INTCLRE0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCLRE0_Struct
 *! \brief  IRQ0..31 Clear_Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCLRE0_t__
typedef struct _ADI_NVIC_INTCLRE0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ0..31 Clear_Enable */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCLRE0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCLRE0_t__ */

/*@}*/

/** @defgroup INTCLRE1 IRQ32..63 Clear_Enable (INTCLRE1) Register
 *  IRQ32..63 Clear_Enable (INTCLRE1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCLRE1_Struct
 *! \brief  IRQ32..63 Clear_Enable Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCLRE1_t__
typedef struct _ADI_NVIC_INTCLRE1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ32..63 Clear_Enable */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCLRE1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCLRE1_t__ */

/*@}*/

/** @defgroup INTSETP0 IRQ0..31 Set_Pending (INTSETP0) Register
 *  IRQ0..31 Set_Pending (INTSETP0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTSETP0_Struct
 *! \brief  IRQ0..31 Set_Pending Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTSETP0_t__
typedef struct _ADI_NVIC_INTSETP0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ0..31 Set_Pending */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTSETP0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTSETP0_t__ */

/*@}*/

/** @defgroup INTSETP1 IRQ32..63 Set_Pending (INTSETP1) Register
 *  IRQ32..63 Set_Pending (INTSETP1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTSETP1_Struct
 *! \brief  IRQ32..63 Set_Pending Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTSETP1_t__
typedef struct _ADI_NVIC_INTSETP1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ32..63 Set_Pending */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTSETP1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTSETP1_t__ */

/*@}*/

/** @defgroup INTCLRP0 IRQ0..31 Clear_Pending (INTCLRP0) Register
 *  IRQ0..31 Clear_Pending (INTCLRP0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCLRP0_Struct
 *! \brief  IRQ0..31 Clear_Pending Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCLRP0_t__
typedef struct _ADI_NVIC_INTCLRP0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ0..31 Clear_Pending */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCLRP0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCLRP0_t__ */

/*@}*/

/** @defgroup INTCLRP1 IRQ32..63 Clear_Pending (INTCLRP1) Register
 *  IRQ32..63 Clear_Pending (INTCLRP1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCLRP1_Struct
 *! \brief  IRQ32..63 Clear_Pending Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCLRP1_t__
typedef struct _ADI_NVIC_INTCLRP1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ32..63 Clear_Pending */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCLRP1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCLRP1_t__ */

/*@}*/

/** @defgroup INTACT0 IRQ0..31 Active Bit (INTACT0) Register
 *  IRQ0..31 Active Bit (INTACT0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTACT0_Struct
 *! \brief  IRQ0..31 Active Bit Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTACT0_t__
typedef struct _ADI_NVIC_INTACT0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ0..31 Active Bit */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTACT0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTACT0_t__ */

/*@}*/

/** @defgroup INTACT1 IRQ32..63 Active Bit (INTACT1) Register
 *  IRQ32..63 Active Bit (INTACT1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTACT1_Struct
 *! \brief  IRQ32..63 Active Bit Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTACT1_t__
typedef struct _ADI_NVIC_INTACT1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ32..63 Active Bit */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTACT1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTACT1_t__ */

/*@}*/

/** @defgroup INTPRI0 IRQ0..3 Priority (INTPRI0) Register
 *  IRQ0..3 Priority (INTPRI0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI0_Struct
 *! \brief  IRQ0..3 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI0_t__
typedef struct _ADI_NVIC_INTPRI0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ0..3 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI0_t__ */

/*@}*/

/** @defgroup INTPRI1 IRQ4..7 Priority (INTPRI1) Register
 *  IRQ4..7 Priority (INTPRI1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI1_Struct
 *! \brief  IRQ4..7 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI1_t__
typedef struct _ADI_NVIC_INTPRI1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ4..7 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI1_t__ */

/*@}*/

/** @defgroup INTPRI2 IRQ8..11 Priority (INTPRI2) Register
 *  IRQ8..11 Priority (INTPRI2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI2_Struct
 *! \brief  IRQ8..11 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI2_t__
typedef struct _ADI_NVIC_INTPRI2_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ8..11 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI2_t__ */

/*@}*/

/** @defgroup INTPRI3 IRQ12..15 Priority (INTPRI3) Register
 *  IRQ12..15 Priority (INTPRI3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI3_Struct
 *! \brief  IRQ12..15 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI3_t__
typedef struct _ADI_NVIC_INTPRI3_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ12..15 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI3_t__ */

/*@}*/

/** @defgroup INTPRI4 IRQ16..19 Priority (INTPRI4) Register
 *  IRQ16..19 Priority (INTPRI4) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI4_Struct
 *! \brief  IRQ16..19 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI4_t__
typedef struct _ADI_NVIC_INTPRI4_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ16..19 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI4_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI4_t__ */

/*@}*/

/** @defgroup INTPRI5 IRQ20..23 Priority (INTPRI5) Register
 *  IRQ20..23 Priority (INTPRI5) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI5_Struct
 *! \brief  IRQ20..23 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI5_t__
typedef struct _ADI_NVIC_INTPRI5_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ20..23 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI5_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI5_t__ */

/*@}*/

/** @defgroup INTPRI6 IRQ24..27 Priority (INTPRI6) Register
 *  IRQ24..27 Priority (INTPRI6) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI6_Struct
 *! \brief  IRQ24..27 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI6_t__
typedef struct _ADI_NVIC_INTPRI6_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ24..27 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI6_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI6_t__ */

/*@}*/

/** @defgroup INTPRI7 IRQ28..31 Priority (INTPRI7) Register
 *  IRQ28..31 Priority (INTPRI7) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI7_Struct
 *! \brief  IRQ28..31 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI7_t__
typedef struct _ADI_NVIC_INTPRI7_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ28..31 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI7_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI7_t__ */

/*@}*/

/** @defgroup INTPRI8 IRQ32..35 Priority (INTPRI8) Register
 *  IRQ32..35 Priority (INTPRI8) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI8_Struct
 *! \brief  IRQ32..35 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI8_t__
typedef struct _ADI_NVIC_INTPRI8_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ32..35 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI8_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI8_t__ */

/*@}*/

/** @defgroup INTPRI9 IRQ36..39 Priority (INTPRI9) Register
 *  IRQ36..39 Priority (INTPRI9) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI9_Struct
 *! \brief  IRQ36..39 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI9_t__
typedef struct _ADI_NVIC_INTPRI9_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ36..39 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI9_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI9_t__ */

/*@}*/

/** @defgroup INTPRI10 IRQ40..43 Priority (INTPRI10) Register
 *  IRQ40..43 Priority (INTPRI10) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPRI10_Struct
 *! \brief  IRQ40..43 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI10_t__
typedef struct _ADI_NVIC_INTPRI10_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< IRQ40..43 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPRI10_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPRI10_t__ */

/*@}*/

/** @defgroup INTCPID CPUID Base (INTCPID) Register
 *  CPUID Base (INTCPID) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCPID_Struct
 *! \brief  CPUID Base Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCPID_t__
typedef struct _ADI_NVIC_INTCPID_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< CPUID Base */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCPID_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCPID_t__ */

/*@}*/

/** @defgroup INTSTA Interrupt Control State (INTSTA) Register
 *  Interrupt Control State (INTSTA) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTSTA_Struct
 *! \brief  Interrupt Control State Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTSTA_t__
typedef struct _ADI_NVIC_INTSTA_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Interrupt Control State */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTSTA_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTSTA_t__ */

/*@}*/

/** @defgroup INTVEC Vector Table Offset (INTVEC) Register
 *  Vector Table Offset (INTVEC) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTVEC_Struct
 *! \brief  Vector Table Offset Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTVEC_t__
typedef struct _ADI_NVIC_INTVEC_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Vector Table Offset */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTVEC_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTVEC_t__ */

/*@}*/

/** @defgroup INTAIRC Application Interrupt/Reset Control (INTAIRC) Register
 *  Application Interrupt/Reset Control (INTAIRC) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTAIRC_Struct
 *! \brief  Application Interrupt/Reset Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTAIRC_t__
typedef struct _ADI_NVIC_INTAIRC_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Application Interrupt/Reset Control */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTAIRC_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTAIRC_t__ */

/*@}*/

/** @defgroup INTCON0 System Control (INTCON0) Register
 *  System Control (INTCON0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCON0_Struct
 *! \brief  System Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCON0_t__
typedef struct _ADI_NVIC_INTCON0_t {
  union {
    struct {
      uint16_t reserved0   :  1;
      uint16_t SLEEPONEXIT :  1;  /**< Sleeps the core on exit from an ISR */
      uint16_t SLEEPDEEP   :  1;  /**< deep sleep flag for HIBERNATE mode */
      uint16_t reserved3   : 13;
    };
    uint16_t VALUE16;
  };
} ADI_NVIC_INTCON0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCON0_t__ */

/*@}*/

/** @defgroup INTCON1 Configuration Control (INTCON1) Register
 *  Configuration Control (INTCON1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCON1_Struct
 *! \brief  Configuration Control Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCON1_t__
typedef struct _ADI_NVIC_INTCON1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Configuration Control */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCON1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCON1_t__ */

/*@}*/

/** @defgroup INTSHPRIO0 System Handlers 4-7 Priority (INTSHPRIO0) Register
 *  System Handlers 4-7 Priority (INTSHPRIO0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTSHPRIO0_Struct
 *! \brief  System Handlers 4-7 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTSHPRIO0_t__
typedef struct _ADI_NVIC_INTSHPRIO0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< System Handlers 4-7 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTSHPRIO0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTSHPRIO0_t__ */

/*@}*/

/** @defgroup INTSHPRIO1 System Handlers 8-11 Priority (INTSHPRIO1) Register
 *  System Handlers 8-11 Priority (INTSHPRIO1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTSHPRIO1_Struct
 *! \brief  System Handlers 8-11 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTSHPRIO1_t__
typedef struct _ADI_NVIC_INTSHPRIO1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< System Handlers 8-11 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTSHPRIO1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTSHPRIO1_t__ */

/*@}*/

/** @defgroup INTSHPRIO3 System Handlers 12-15 Priority (INTSHPRIO3) Register
 *  System Handlers 12-15 Priority (INTSHPRIO3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTSHPRIO3_Struct
 *! \brief  System Handlers 12-15 Priority Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTSHPRIO3_t__
typedef struct _ADI_NVIC_INTSHPRIO3_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< System Handlers 12-15 Priority */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTSHPRIO3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTSHPRIO3_t__ */

/*@}*/

/** @defgroup INTSHCSR System Handler Control and State (INTSHCSR) Register
 *  System Handler Control and State (INTSHCSR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTSHCSR_Struct
 *! \brief  System Handler Control and State Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTSHCSR_t__
typedef struct _ADI_NVIC_INTSHCSR_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< System Handler Control and State */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTSHCSR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTSHCSR_t__ */

/*@}*/

/** @defgroup INTCFSR Configurable Fault Status (INTCFSR) Register
 *  Configurable Fault Status (INTCFSR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCFSR_Struct
 *! \brief  Configurable Fault Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCFSR_t__
typedef struct _ADI_NVIC_INTCFSR_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Configurable Fault Status */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCFSR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCFSR_t__ */

/*@}*/

/** @defgroup INTHFSR Hard Fault Status (INTHFSR) Register
 *  Hard Fault Status (INTHFSR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTHFSR_Struct
 *! \brief  Hard Fault Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTHFSR_t__
typedef struct _ADI_NVIC_INTHFSR_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Hard Fault Status */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTHFSR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTHFSR_t__ */

/*@}*/

/** @defgroup INTDFSR Debug Fault Status (INTDFSR) Register
 *  Debug Fault Status (INTDFSR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTDFSR_Struct
 *! \brief  Debug Fault Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTDFSR_t__
typedef struct _ADI_NVIC_INTDFSR_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Debug Fault Status */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTDFSR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTDFSR_t__ */

/*@}*/

/** @defgroup INTMMAR Mem Manage Address (INTMMAR) Register
 *  Mem Manage Address (INTMMAR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTMMAR_Struct
 *! \brief  Mem Manage Address Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTMMAR_t__
typedef struct _ADI_NVIC_INTMMAR_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Mem Manage Address */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTMMAR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTMMAR_t__ */

/*@}*/

/** @defgroup INTBFAR Bus Fault Address (INTBFAR) Register
 *  Bus Fault Address (INTBFAR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTBFAR_Struct
 *! \brief  Bus Fault Address Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTBFAR_t__
typedef struct _ADI_NVIC_INTBFAR_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Bus Fault Address */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTBFAR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTBFAR_t__ */

/*@}*/

/** @defgroup INTAFSR Auxiliary Fault Status (INTAFSR) Register
 *  Auxiliary Fault Status (INTAFSR) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTAFSR_Struct
 *! \brief  Auxiliary Fault Status Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTAFSR_t__
typedef struct _ADI_NVIC_INTAFSR_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Auxiliary Fault Status */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTAFSR_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTAFSR_t__ */

/*@}*/

/** @defgroup INTPFR0 Processor Feature Register 0 (INTPFR0) Register
 *  Processor Feature Register 0 (INTPFR0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPFR0_Struct
 *! \brief  Processor Feature Register 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPFR0_t__
typedef struct _ADI_NVIC_INTPFR0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Processor Feature Register 0 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPFR0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPFR0_t__ */

/*@}*/

/** @defgroup INTPFR1 Processor Feature Register 1 (INTPFR1) Register
 *  Processor Feature Register 1 (INTPFR1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPFR1_Struct
 *! \brief  Processor Feature Register 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPFR1_t__
typedef struct _ADI_NVIC_INTPFR1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Processor Feature Register 1 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPFR1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPFR1_t__ */

/*@}*/

/** @defgroup INTDFR0 Debug Feature Register 0 (INTDFR0) Register
 *  Debug Feature Register 0 (INTDFR0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTDFR0_Struct
 *! \brief  Debug Feature Register 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTDFR0_t__
typedef struct _ADI_NVIC_INTDFR0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Debug Feature Register 0 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTDFR0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTDFR0_t__ */

/*@}*/

/** @defgroup INTAFR0 Auxiliary Feature Register 0 (INTAFR0) Register
 *  Auxiliary Feature Register 0 (INTAFR0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTAFR0_Struct
 *! \brief  Auxiliary Feature Register 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTAFR0_t__
typedef struct _ADI_NVIC_INTAFR0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Auxiliary Feature Register 0 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTAFR0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTAFR0_t__ */

/*@}*/

/** @defgroup INTMMFR0 Memory Model Feature Register 0 (INTMMFR0) Register
 *  Memory Model Feature Register 0 (INTMMFR0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTMMFR0_Struct
 *! \brief  Memory Model Feature Register 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTMMFR0_t__
typedef struct _ADI_NVIC_INTMMFR0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Memory Model Feature Register 0 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTMMFR0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTMMFR0_t__ */

/*@}*/

/** @defgroup INTMMFR1 Memory Model Feature Register 1 (INTMMFR1) Register
 *  Memory Model Feature Register 1 (INTMMFR1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTMMFR1_Struct
 *! \brief  Memory Model Feature Register 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTMMFR1_t__
typedef struct _ADI_NVIC_INTMMFR1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Memory Model Feature Register 1 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTMMFR1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTMMFR1_t__ */

/*@}*/

/** @defgroup INTMMFR2 Memory Model Feature Register 2 (INTMMFR2) Register
 *  Memory Model Feature Register 2 (INTMMFR2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTMMFR2_Struct
 *! \brief  Memory Model Feature Register 2 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTMMFR2_t__
typedef struct _ADI_NVIC_INTMMFR2_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Memory Model Feature Register 2 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTMMFR2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTMMFR2_t__ */

/*@}*/

/** @defgroup INTMMFR3 Memory Model Feature Register 3 (INTMMFR3) Register
 *  Memory Model Feature Register 3 (INTMMFR3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTMMFR3_Struct
 *! \brief  Memory Model Feature Register 3 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTMMFR3_t__
typedef struct _ADI_NVIC_INTMMFR3_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Memory Model Feature Register 3 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTMMFR3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTMMFR3_t__ */

/*@}*/

/** @defgroup INTISAR0 ISA Feature Register 0 (INTISAR0) Register
 *  ISA Feature Register 0 (INTISAR0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTISAR0_Struct
 *! \brief  ISA Feature Register 0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTISAR0_t__
typedef struct _ADI_NVIC_INTISAR0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< ISA Feature Register 0 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTISAR0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTISAR0_t__ */

/*@}*/

/** @defgroup INTISAR1 ISA Feature Register 1 (INTISAR1) Register
 *  ISA Feature Register 1 (INTISAR1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTISAR1_Struct
 *! \brief  ISA Feature Register 1 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTISAR1_t__
typedef struct _ADI_NVIC_INTISAR1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< ISA Feature Register 1 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTISAR1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTISAR1_t__ */

/*@}*/

/** @defgroup INTISAR2 ISA Feature Register 2 (INTISAR2) Register
 *  ISA Feature Register 2 (INTISAR2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTISAR2_Struct
 *! \brief  ISA Feature Register 2 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTISAR2_t__
typedef struct _ADI_NVIC_INTISAR2_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< ISA Feature Register 2 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTISAR2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTISAR2_t__ */

/*@}*/

/** @defgroup INTISAR3 ISA Feature Register 3 (INTISAR3) Register
 *  ISA Feature Register 3 (INTISAR3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTISAR3_Struct
 *! \brief  ISA Feature Register 3 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTISAR3_t__
typedef struct _ADI_NVIC_INTISAR3_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< ISA Feature Register 3 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTISAR3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTISAR3_t__ */

/*@}*/

/** @defgroup INTISAR4 ISA Feature Register 4 (INTISAR4) Register
 *  ISA Feature Register 4 (INTISAR4) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTISAR4_Struct
 *! \brief  ISA Feature Register 4 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTISAR4_t__
typedef struct _ADI_NVIC_INTISAR4_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< ISA Feature Register 4 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTISAR4_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTISAR4_t__ */

/*@}*/

/** @defgroup INTTRGI Software Trigger Interrupt Register (INTTRGI) Register
 *  Software Trigger Interrupt Register (INTTRGI) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTTRGI_Struct
 *! \brief  Software Trigger Interrupt Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTTRGI_t__
typedef struct _ADI_NVIC_INTTRGI_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Software Trigger Interrupt Register */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTTRGI_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTTRGI_t__ */

/*@}*/

/** @defgroup INTPID4 Peripheral Identification Register 4 (INTPID4) Register
 *  Peripheral Identification Register 4 (INTPID4) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPID4_Struct
 *! \brief  Peripheral Identification Register 4 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID4_t__
typedef struct _ADI_NVIC_INTPID4_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Peripheral Identification Register 4 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPID4_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID4_t__ */

/*@}*/

/** @defgroup INTPID5 Peripheral Identification Register 5 (INTPID5) Register
 *  Peripheral Identification Register 5 (INTPID5) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPID5_Struct
 *! \brief  Peripheral Identification Register 5 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID5_t__
typedef struct _ADI_NVIC_INTPID5_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Peripheral Identification Register 5 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPID5_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID5_t__ */

/*@}*/

/** @defgroup INTPID6 Peripheral Identification Register 6 (INTPID6) Register
 *  Peripheral Identification Register 6 (INTPID6) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPID6_Struct
 *! \brief  Peripheral Identification Register 6 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID6_t__
typedef struct _ADI_NVIC_INTPID6_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Peripheral Identification Register 6 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPID6_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID6_t__ */

/*@}*/

/** @defgroup INTPID7 Peripheral Identification Register 7 (INTPID7) Register
 *  Peripheral Identification Register 7 (INTPID7) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPID7_Struct
 *! \brief  Peripheral Identification Register 7 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID7_t__
typedef struct _ADI_NVIC_INTPID7_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Peripheral Identification Register 7 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPID7_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID7_t__ */

/*@}*/

/** @defgroup INTPID0 Peripheral Identification Bits7:0 (INTPID0) Register
 *  Peripheral Identification Bits7:0 (INTPID0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPID0_Struct
 *! \brief  Peripheral Identification Bits7:0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID0_t__
typedef struct _ADI_NVIC_INTPID0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Peripheral Identification Bits7:0 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPID0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID0_t__ */

/*@}*/

/** @defgroup INTPID1 Peripheral Identification Bits15:8 (INTPID1) Register
 *  Peripheral Identification Bits15:8 (INTPID1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPID1_Struct
 *! \brief  Peripheral Identification Bits15:8 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID1_t__
typedef struct _ADI_NVIC_INTPID1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Peripheral Identification Bits15:8 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPID1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID1_t__ */

/*@}*/

/** @defgroup INTPID2 Peripheral Identification Bits16:23 (INTPID2) Register
 *  Peripheral Identification Bits16:23 (INTPID2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPID2_Struct
 *! \brief  Peripheral Identification Bits16:23 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID2_t__
typedef struct _ADI_NVIC_INTPID2_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Peripheral Identification Bits16:23 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPID2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID2_t__ */

/*@}*/

/** @defgroup INTPID3 Peripheral Identification Bits24:31 (INTPID3) Register
 *  Peripheral Identification Bits24:31 (INTPID3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTPID3_Struct
 *! \brief  Peripheral Identification Bits24:31 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID3_t__
typedef struct _ADI_NVIC_INTPID3_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Peripheral Identification Bits24:31 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTPID3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTPID3_t__ */

/*@}*/

/** @defgroup INTCID0 Component Identification Bits7:0 (INTCID0) Register
 *  Component Identification Bits7:0 (INTCID0) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCID0_Struct
 *! \brief  Component Identification Bits7:0 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCID0_t__
typedef struct _ADI_NVIC_INTCID0_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Component Identification Bits7:0 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCID0_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCID0_t__ */

/*@}*/

/** @defgroup INTCID1 Component Identification Bits15:8 (INTCID1) Register
 *  Component Identification Bits15:8 (INTCID1) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCID1_Struct
 *! \brief  Component Identification Bits15:8 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCID1_t__
typedef struct _ADI_NVIC_INTCID1_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Component Identification Bits15:8 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCID1_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCID1_t__ */

/*@}*/

/** @defgroup INTCID2 Component Identification Bits16:23 (INTCID2) Register
 *  Component Identification Bits16:23 (INTCID2) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCID2_Struct
 *! \brief  Component Identification Bits16:23 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCID2_t__
typedef struct _ADI_NVIC_INTCID2_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Component Identification Bits16:23 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCID2_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCID2_t__ */

/*@}*/

/** @defgroup INTCID3 Component Identification Bits24:31 (INTCID3) Register
 *  Component Identification Bits24:31 (INTCID3) Register.
 *  @{
 */

/* ==========================================================================
 *! \struct ADI_NVIC_INTCID3_Struct
 *! \brief  Component Identification Bits24:31 Register bit field structure
 * ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_INTCID3_t__
typedef struct _ADI_NVIC_INTCID3_t {
  union {
    struct {
      uint32_t VALUE      : 32;  /**< Component Identification Bits24:31 */
    };
    uint32_t VALUE32;
  };
} ADI_NVIC_INTCID3_t;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_INTCID3_t__ */

/*@}*/


#if defined (_MISRA_RULES)
#pragma diag(pop)
#endif /* _MISRA_RULES */


#if defined (__CC_ARM)
#pragma pop
#endif 

#endif
