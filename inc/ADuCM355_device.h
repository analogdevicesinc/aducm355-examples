/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#ifndef _ADUCM355_DEVICE_H
#define _ADUCM355_DEVICE_H

/* pickup integer types */
#if defined(_LANGUAGE_C) || (defined(__GNUC__) && !defined(__ASSEMBLER__))
#include <stdint.h>
#endif /* _LANGUAGE_C */

/* pickup register bitfield and bit masks */
#include "ADuCM355_typedefs.h"

#if defined ( __CC_ARM   )
#pragma push
#pragma anon_unions
#endif


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

/** @defgroup TMR General Purpose Timer (TMR) Module
 *  General Purpose Timer
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_TMR_TypeDef
 *  \brief  General Purpose Timer
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_TMR_TypeDef__
typedef struct _ADI_TMR_TypeDef
{
    __IO     int16_t    LOAD;                          /*!< 16-bit load value */
    __I      uint8_t  RESERVED0[2];
    __I      int16_t    CURCNT;                        /*!< 16-bit timer value */
    __I      uint8_t  RESERVED1[2];
    __IO     uint16_t   CTL;                           /*!< Control */
    __I      uint8_t  RESERVED2[2];
    __O      uint16_t   CLRINT;                        /*!< Clear Interrupt */
    __I      uint8_t  RESERVED3[2];
    __I      int16_t    CAPTURE;                       /*!< Capture */
    __I      uint8_t  RESERVED4[2];
    __IO     int16_t    ALOAD;                         /*!< 16-bit load value, asynchronous */
    __I      uint8_t  RESERVED5[2];
    __I      int16_t    ACURCNT;                       /*!< 16-bit timer value, asynchronous */
    __I      uint8_t  RESERVED6[2];
    __I      uint16_t   STAT;                          /*!< Status */
    __I      uint8_t  RESERVED7[2];
    __IO     uint16_t   PWMCTL;                        /*!< PWM Control Register */
    __I      uint8_t  RESERVED8[2];
    __IO     int16_t    PWMMATCH;                      /*!< PWM Match Value */
} ADI_TMR_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_TMR_TypeDef__ */

/*!@}*/

/** @defgroup RTC Real-Time Clock (RTC) Module
 *  Real-Time Clock
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_RTC_TypeDef
 *  \brief  Real-Time Clock
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RTC_TypeDef__
typedef struct _ADI_RTC_TypeDef
{
    __IO     uint16_t   CR0;                           /*!< RTC Control 0 */
    __I      uint8_t  RESERVED0[2];
    __IO     uint16_t   SR0;                           /*!< RTC Status 0 */
    __I      uint8_t  RESERVED1[2];
    __I      uint16_t   SR1;                           /*!< RTC Status 1 */
    __I      uint8_t  RESERVED2[2];
    __IO     uint16_t   CNT0;                          /*!< RTC Count 0 */
    __I      uint8_t  RESERVED3[2];
    __IO     uint16_t   CNT1;                          /*!< RTC Count 1 */
    __I      uint8_t  RESERVED4[2];
    __IO     uint16_t   ALM0;                          /*!< RTC Alarm 0 */
    __I      uint8_t  RESERVED5[2];
    __IO     uint16_t   ALM1;                          /*!< RTC Alarm 1 */
    __I      uint8_t  RESERVED6[2];
    __IO     uint16_t   TRM;                           /*!< RTC Trim */
    __I      uint8_t  RESERVED7[2];
    __O      uint16_t   GWY;                           /*!< RTC Gateway */
    __I      uint8_t  RESERVED8[6];
    __IO     uint16_t   CR1;                           /*!< RTC Control 1 */
    __I      uint8_t  RESERVED9[2];
    __IO     uint16_t   SR2;                           /*!< RTC Status 2 */
    __I      uint8_t  RESERVED10[2];
    __I      uint16_t   SNAP0;                         /*!< RTC Snapshot 0 */
    __I      uint8_t  RESERVED11[2];
    __I      uint16_t   SNAP1;                         /*!< RTC Snapshot 1 */
    __I      uint8_t  RESERVED12[2];
    __I      uint16_t   SNAP2;                         /*!< RTC Snapshot 2 */
    __I      uint8_t  RESERVED13[2];
    __I      uint16_t   MOD;                           /*!< RTC Modulo */
    __I      uint8_t  RESERVED14[2];
    __I      uint16_t   CNT2;                          /*!< RTC Count 2 */
    __I      uint8_t  RESERVED15[2];
    __IO     uint16_t   ALM2;                          /*!< RTC Alarm 2 */
    __I      uint8_t  RESERVED16[2];
    __IO     uint16_t   SR3;                           /*!< RTC Status 3 */
    __I      uint8_t  RESERVED17[2];
    __IO     uint16_t   CR2IC;                         /*!< RTC Control 2 for Configuring Input Capture Channels */
    __I      uint8_t  RESERVED18[2];
    __IO     uint16_t   CR3OC;                         /*!< RTC Control 3 for Configuring Output Compare Channel */
    __I      uint8_t  RESERVED19[2];
    __IO     uint16_t   CR4OC;                         /*!< RTC Control 4 for Configuring Output Compare Channel */
    __I      uint8_t  RESERVED20[2];
    __IO     uint16_t   OCMSK;                         /*!< RTC Masks for Output Compare Channel */
    __I      uint8_t  RESERVED21[2];
    __IO     uint16_t   OC1ARL;                        /*!< RTC Auto-Reload for Output Compare Channel 1 */
    __I      uint8_t  RESERVED22[6];
    __I      uint16_t   IC2;                           /*!< RTC Input Capture Channel 2 */
    __I      uint8_t  RESERVED23[2];
    __I      uint16_t   IC3;                           /*!< RTC Input Capture Channel 3 */
    __I      uint8_t  RESERVED24[2];
    __I      uint16_t   IC4;                           /*!< RTC Input Capture Channel 4 */
    __I      uint8_t  RESERVED25[2];
    __IO     uint16_t   OC1;                           /*!< RTC Output Compare Channel 1 */
    __I      uint8_t  RESERVED26[14];
    __I      uint16_t   SR4;                           /*!< RTC Status 4 */
    __I      uint8_t  RESERVED27[2];
    __I      uint16_t   SR5;                           /*!< RTC Status 5 */
    __I      uint8_t  RESERVED28[2];
    __I      uint16_t   SR6;                           /*!< RTC Status 6 */
    __I      uint8_t  RESERVED29[2];
    __I      uint16_t   OC1TGT;                        /*!< RTC Output Compare Channel 1 Target */
    __I      uint8_t  RESERVED30[2];
    __I      uint16_t   FRZCNT;                        /*!< RTC Freeze Count */
} ADI_RTC_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RTC_TypeDef__ */

/*!@}*/

/** @defgroup SYS System Identification and Debug Enable (SYS) Module
 *  System Identification and Debug Enable
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_SYS_TypeDef
 *  \brief  System Identification and Debug Enable
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SYS_TypeDef__
typedef struct _ADI_SYS_TypeDef
{
    __I      uint8_t  RESERVED0[32];
    __I      uint16_t   ADIID;                         /*!< ADI Identification */
    __I      uint8_t  RESERVED1[2];
    __I      uint16_t   CHIPID;                        /*!< Chip Identifier */
    __I      uint8_t  RESERVED2[26];
    __O      uint16_t   SWDEN;                         /*!< Serial Wire Debug Enable */
} ADI_SYS_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SYS_TypeDef__ */

/*!@}*/

/** @defgroup WDT Watchdog Timer (WDT) Module
 *  Watchdog Timer
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_WDT_TypeDef
 *  \brief  Watchdog Timer
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_WDT_TypeDef__
typedef struct _ADI_WDT_TypeDef
{
    __IO     int16_t    LOAD;                          /*!< Load value */
    __I      uint8_t  RESERVED0[2];
    __I      int16_t    CCNT;                          /*!< Current count value */
    __I      uint8_t  RESERVED1[2];
    __IO     uint16_t   CTL;                           /*!< Control */
    __I      uint8_t  RESERVED2[2];
    __O      int16_t    RESTART;                       /*!< Clear interrupt */
    __I      uint8_t  RESERVED3[10];
    __I      uint16_t   STAT;                          /*!< Status */
} ADI_WDT_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_WDT_TypeDef__ */

/*!@}*/

/** @defgroup I2C I2C Master/Slave (I2C) Module
 *  I2C Master/Slave
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_I2C_TypeDef
 *  \brief  I2C Master/Slave
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_I2C_TypeDef__
typedef struct _ADI_I2C_TypeDef
{
    __IO     uint16_t   MCTL;                          /*!< Master control */
    __I      uint8_t  RESERVED0[2];
    __IO     uint16_t   MSTAT;                         /*!< Master status */
    __I      uint8_t  RESERVED1[2];
    __I      uint16_t   MRX;                           /*!< Master receive data */
    __I      uint8_t  RESERVED2[2];
    __IO     uint16_t   MTX;                           /*!< Master transmit data */
    __I      uint8_t  RESERVED3[2];
    __IO     uint16_t   MRXCNT;                        /*!< Master receive data count */
    __I      uint8_t  RESERVED4[2];
    __I      uint16_t   MCRXCNT;                       /*!< Master current receive data count */
    __I      uint8_t  RESERVED5[2];
    __IO     uint16_t   ADDR1;                         /*!< 1st master address byte */
    __I      uint8_t  RESERVED6[2];
    __IO     uint16_t   ADDR2;                         /*!< 2nd master address byte */
    __I      uint8_t  RESERVED7[2];
    __IO     uint16_t   BYT;                           /*!< Start byte */
    __I      uint8_t  RESERVED8[2];
    __IO     uint16_t   DIV;                           /*!< Serial clock period divisor */
    __I      uint8_t  RESERVED9[2];
    __IO     uint16_t   SCTL;                          /*!< Slave control */
    __I      uint8_t  RESERVED10[2];
    __IO     uint16_t   SSTAT;                         /*!< Slave I2C Status/Error/IRQ */
    __I      uint8_t  RESERVED11[2];
    __I      uint16_t   SRX;                           /*!< Slave receive */
    __I      uint8_t  RESERVED12[2];
    __IO     uint16_t   STX;                           /*!< Slave transmit */
    __I      uint8_t  RESERVED13[2];
    __IO     uint16_t   ALT;                           /*!< Hardware general call ID */
    __I      uint8_t  RESERVED14[2];
    __IO     uint16_t   ID0;                           /*!< 1st slave address device ID */
    __I      uint8_t  RESERVED15[2];
    __IO     uint16_t   ID1;                           /*!< 2nd slave address device ID */
    __I      uint8_t  RESERVED16[2];
    __IO     uint16_t   ID2;                           /*!< 3rd slave address device ID */
    __I      uint8_t  RESERVED17[2];
    __IO     uint16_t   ID3;                           /*!< 4th slave address device ID */
    __I      uint8_t  RESERVED18[2];
    __IO     uint16_t   STAT;                          /*!< Master and slave FIFO status */
    __I      uint8_t  RESERVED19[2];
    __O      uint16_t   SHCTL;                         /*!< Shared control */
    __I      uint8_t  RESERVED20[2];
    __IO     uint16_t   TCTL;                          /*!< Timing Control Register */
    __I      uint8_t  RESERVED21[2];
    __IO     uint16_t   ASTRETCH_SCL;                  /*!< Automatic stretch SCL register */
} ADI_I2C_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_I2C_TypeDef__ */

/*!@}*/

/** @defgroup SPI Serial Peripheral Interface (SPI) Module
 *  Serial Peripheral Interface
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_SPI_TypeDef
 *  \brief  Serial Peripheral Interface
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_SPI_TypeDef__
typedef struct _ADI_SPI_TypeDef
{
    __IO     uint16_t   STAT;                          /*!< Status */
    __I      uint8_t  RESERVED0[2];
    __I      uint16_t   RX;                            /*!< Receive */
    __I      uint8_t  RESERVED1[2];
    __O      uint16_t   TX;                            /*!< Transmit */
    __I      uint8_t  RESERVED2[2];
    __IO     uint16_t   DIV;                           /*!< SPI baud rate selection */
    __I      uint8_t  RESERVED3[2];
    __IO     uint16_t   CTL;                           /*!< SPI configuration 1 */
    __I      uint8_t  RESERVED4[2];
    __IO     uint16_t   IEN;                           /*!< SPI configuration 2 */
    __I      uint8_t  RESERVED5[2];
    __IO     uint16_t   CNT;                           /*!< Transfer byte count */
    __I      uint8_t  RESERVED6[2];
    __IO     uint16_t   DMA;                           /*!< SPI DMA enable */
    __I      uint8_t  RESERVED7[2];
    __I      uint16_t   FIFO_STAT;                     /*!< FIFO Status */
    __I      uint8_t  RESERVED8[2];
    __IO     uint16_t   RD_CTL;                        /*!< Read Control */
    __I      uint8_t  RESERVED9[2];
    __IO     uint16_t   FLOW_CTL;                      /*!< Flow Control */
    __I      uint8_t  RESERVED10[2];
    __IO     uint16_t   WAIT_TMR;                      /*!< Wait timer for flow control */
    __I      uint8_t  RESERVED11[2];
    __IO     uint16_t   CS_CTL;                        /*!< Chip-Select control for multi-slave connections */
    __I      uint8_t  RESERVED12[2];
    __IO     uint16_t   CS_OVERRIDE;                   /*!< Chip-Select Override */
    __I      uint8_t  RESERVED13[4];
} ADI_SPI_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_SPI_TypeDef__ */

/*!@}*/

/** @defgroup UART  (UART) Module
 *  
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_UART_TypeDef
 *  \brief  
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_UART_TypeDef__
typedef struct _ADI_UART_TypeDef
{
    union {
    __I      uint16_t   COMRX;                         /*!< Receive Buffer Register */
    __O      uint16_t   COMTX;                         /*!< Transmit Holding Register */
    };
    __I      uint8_t  RESERVED0[2];
    __IO     uint16_t   COMIEN;                        /*!< Interrupt Enable */
    __I      uint8_t  RESERVED1[2];
    __I      uint16_t   COMIIR;                        /*!< Interrupt ID */
    __I      uint8_t  RESERVED2[2];
    __IO     uint16_t   COMLCR;                        /*!< Line Control */
    __I      uint8_t  RESERVED3[2];
    __IO     uint16_t   COMMCR;                        /*!< Modem Control */
    __I      uint8_t  RESERVED4[2];
    __I      uint16_t   COMLSR;                        /*!< Line Status */
    __I      uint8_t  RESERVED5[2];
    __I      uint16_t   COMMSR;                        /*!< Modem Status */
    __I      uint8_t  RESERVED6[2];
    __IO     uint16_t   COMSCR;                        /*!< Scratch buffer */
    __I      uint8_t  RESERVED7[2];
    __IO     uint16_t   COMFCR;                        /*!< FIFO Control */
    __I      uint8_t  RESERVED8[2];
    __IO     uint16_t   COMFBR;                        /*!< Fractional Baud Rate */
    __I      uint8_t  RESERVED9[2];
    __IO     int16_t    COMDIV;                        /*!< Baudrate divider */
    __I      uint8_t  RESERVED10[2];
    __IO     uint16_t   COMLCR2;                       /*!< second Line Control */
    __I      uint8_t  RESERVED11[2];
    __IO     uint16_t   COMCTL;                        /*!< UART control register */
    __I      uint8_t  RESERVED12[2];
    __I      uint16_t   COMRFC;                        /*!< RX FIFO byte count */
    __I      uint8_t  RESERVED13[2];
    __I      uint16_t   COMTFC;                        /*!< TX FIFO byte count */
    __I      uint8_t  RESERVED14[2];
    __IO     uint16_t   COMRSC;                        /*!< RS485 half-duplex Control */
    __I      uint8_t  RESERVED15[2];
    __IO     uint16_t   COMACR;                        /*!< Auto Baud Control */
    __I      uint8_t  RESERVED16[2];
    __I      uint16_t   COMASRL;                       /*!< Auto Baud Status (Low) */
    __I      uint8_t  RESERVED17[2];
    __I      uint16_t   COMASRH;                       /*!< Auto Baud Status (High) */
} ADI_UART_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_UART_TypeDef__ */

/*!@}*/

/** @defgroup DMA DMA (DMA) Module
 *  DMA
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_DMA_TypeDef
 *  \brief  DMA
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_DMA_TypeDef__
typedef struct _ADI_DMA_TypeDef
{
    __I      uint32_t   STAT;                          /*!< DMA Status */
    __O      uint32_t   CFG;                           /*!< DMA Configuration */
    __IO     int32_t    PDBPTR;                        /*!< DMA channel primary control data base pointer */
    __I      int32_t    ADBPTR;                        /*!< DMA channel alternate control data base pointer */
    __I      uint8_t  RESERVED0[4];
    __O      uint32_t   SWREQ;                         /*!< DMA channel software request */
    __I      uint8_t  RESERVED1[8];
    __IO     uint32_t   RMSK_SET;                      /*!< DMA channel request mask set */
    __O      uint32_t   RMSK_CLR;                      /*!< DMA channel request mask clear */
    __IO     uint32_t   EN_SET;                        /*!< DMA channel enable set */
    __O      uint32_t   EN_CLR;                        /*!< DMA channel enable clear */
    __IO     uint32_t   ALT_SET;                       /*!< DMA channel primary-alternate set */
    __O      uint32_t   ALT_CLR;                       /*!< DMA channel primary-alternate clear */
    __O      uint32_t   PRI_SET;                       /*!< DMA channel priority set */
    __O      uint32_t   PRI_CLR;                       /*!< DMA channel priority clear */
    __I      uint8_t  RESERVED2[8];
    __IO     uint32_t   ERRCHNL_CLR;                   /*!< DMA Per Channel Error Clear */
    __IO     uint32_t   ERR_CLR;                       /*!< DMA bus error clear */
    __IO     uint32_t   INVALIDDESC_CLR;               /*!< DMA Per Channel Invalid Descriptor Clear */
    __I      uint8_t  RESERVED3[1964];
    __IO     uint32_t   BS_SET;                        /*!< DMA channel bytes swap enable set */
    __O      uint32_t   BS_CLR;                        /*!< DMA channel bytes swap enable clear */
    __I      uint8_t  RESERVED4[8];
    __IO     uint32_t   SRCADDR_SET;                   /*!< DMA channel source address decrement enable set */
    __O      uint32_t   SRCADDR_CLR;                   /*!< DMA channel source address decrement enable clear */
    __IO     uint32_t   DSTADDR_SET;                   /*!< DMA channel destination address decrement enable set */
    __O      uint32_t   DSTADDR_CLR;                   /*!< DMA channel destination address decrement enable clear */
    __I      uint8_t  RESERVED5[1984];
    __I      uint32_t   REVID;                         /*!< DMA Controller Revision ID */
} ADI_DMA_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_DMA_TypeDef__ */

/*!@}*/

/** @defgroup FLCC Flash Controller (FLCC) Module
 *  Flash Controller
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_FLCC_TypeDef
 *  \brief  Flash Controller
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_TypeDef__
typedef struct _ADI_FLCC_TypeDef
{
    __IO     uint32_t   STAT;                          /*!< Status */
    __IO     uint32_t   IEN;                           /*!< Interrupt Enable */
    __IO     uint32_t   CMD;                           /*!< Command */
    __IO     uint32_t   KH_ADDR;                       /*!< WRITE Address */
    __IO     int32_t    KH_DATA0;                      /*!< WRITE Lower Data */
    __IO     int32_t    KH_DATA1;                      /*!< WRITE Upper Data */
    __IO     uint32_t   PAGE_ADDR0;                    /*!< Lower Page Address */
    __IO     uint32_t   PAGE_ADDR1;                    /*!< Upper Page Address */
    __O      int32_t    KEY;                           /*!< Key */
    __I      int32_t    WR_ABORT_ADDR;                 /*!< Write Abort Address */
    __IO     int32_t    WRPROT;                        /*!< Write Protection */
    __I      int32_t    SIGNATURE;                     /*!< Signature */
    __IO     uint32_t   UCFG;                          /*!< User Configuration */
    __IO     uint32_t   TIME_PARAM0;                   /*!< Time Parameter 0 */
    __IO     uint32_t   TIME_PARAM1;                   /*!< Time parameter 1 */
    __IO     uint32_t   ABORT_EN_LO;                   /*!< IRQ Abort Enable (lower bits) */
    __IO     uint32_t   ABORT_EN_HI;                   /*!< IRQ Abort Enable (upper bits) */
    __IO     uint32_t   ECC_CFG;                       /*!< ECC Config */
    __I      uint32_t   ECC_ADDR;                      /*!< ECC Status (Address) */
    __I      uint8_t  RESERVED0[4];
    __IO     uint32_t   ADI_POR_SEC;                   /*!< ADI flash security */
    __I      uint8_t  RESERVED1[4];
} ADI_FLCC_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_TypeDef__ */

/*!@}*/

/** @defgroup FLCC_CACHE Cache Controller (FLCC_CACHE) Module
 *  Cache Controller
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_FLCC_CACHE_TypeDef
 *  \brief  Cache Controller
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_FLCC_CACHE_TypeDef__
typedef struct _ADI_FLCC_CACHE_TypeDef
{
    __I      uint32_t   STAT;                          /*!< Cache Status register */
    __IO     uint32_t   SETUP;                         /*!< Cache Setup register */
    __O      int32_t    KEY;                           /*!< Cache Key register */
    __I      uint8_t  RESERVED0[40];
} ADI_FLCC_CACHE_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_FLCC_CACHE_TypeDef__ */

/*!@}*/

/** @defgroup GPIO  (GPIO) Module
 *  
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_GPIO_TypeDef
 *  \brief  
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_GPIO_TypeDef__
typedef struct _ADI_GPIO_TypeDef
{
    __IO     uint32_t   CFG;                           /*!< Port  Configuration */
    __IO     uint16_t   OEN;                           /*!< Port output enable */
    __I      uint8_t  RESERVED0[2];
    __IO     uint16_t   PE;                            /*!< Port output pullup/pulldown enable */
    __I      uint8_t  RESERVED1[2];
    __IO     uint16_t   IEN;                           /*!< Port  Input Path Enable */
    __I      uint8_t  RESERVED2[2];
    __I      uint16_t   IN;                            /*!< Port  registered data input */
    __I      uint8_t  RESERVED3[2];
    __IO     uint16_t   OUT;                           /*!< Port data output */
    __I      uint8_t  RESERVED4[2];
    __O      uint16_t   SET;                           /*!< Port data out set */
    __I      uint8_t  RESERVED5[2];
    __O      uint16_t   CLR;                           /*!< Port Data Out Clear */
    __I      uint8_t  RESERVED6[2];
    __O      uint16_t   TGL;                           /*!< Port Pin Toggle */
    __I      uint8_t  RESERVED7[2];
    __IO     uint16_t   POL;                           /*!< Port Interrupt Polarity */
    __I      uint8_t  RESERVED8[2];
    __IO     uint16_t   IENA;                          /*!< Port Interrupt A Enable */
    __I      uint8_t  RESERVED9[2];
    __IO     uint16_t   IENB;                          /*!< Port Interrupt B Enable */
    __I      uint8_t  RESERVED10[2];
    __IO     uint16_t   INT;                           /*!< Port Interrupt Status */
    __I      uint8_t  RESERVED11[2];
    __IO     uint16_t   DS;                            /*!< Port Drive Strength Select */
} ADI_GPIO_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_GPIO_TypeDef__ */

/*!@}*/

/** @defgroup CRC CRC Accelerator (CRC) Module
 *  CRC Accelerator
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_CRC_TypeDef
 *  \brief  CRC Accelerator
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRC_TypeDef__
typedef struct _ADI_CRC_TypeDef
{
    __IO     uint32_t   CTL;                           /*!< CRC Control Register */
    __O      int32_t    IPDATA;                        /*!< Input Data Word Register */
    __IO     int32_t    RESULT;                        /*!< CRC Result Register */
    __IO     uint32_t   POLY;                          /*!< Programmable CRC Polynomial */
    union {
    __O      uint8_t    IPBITS[8];                     /*!< Input Data Bits */
    __O      uint8_t    IPBYTE;                        /*!< Input Data Byte */
    };
} ADI_CRC_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRC_TypeDef__ */

/*!@}*/

/** @defgroup RNG Random Number Generator (RNG) Module
 *  Random Number Generator
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_RNG_TypeDef
 *  \brief  Random Number Generator
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_RNG_TypeDef__
typedef struct _ADI_RNG_TypeDef
{
    __IO     uint16_t   CTL;                           /*!< RNG Control Register */
    __I      uint8_t  RESERVED0[2];
    __IO     uint16_t   LEN;                           /*!< RNG Sample Length Register */
    __I      uint8_t  RESERVED1[2];
    __IO     uint16_t   STAT;                          /*!< RNG Status Register */
    __I      uint8_t  RESERVED2[2];
    __I      uint32_t   DATA;                          /*!< RNG Data Register */
    __I      uint32_t   OSCCNT;                        /*!< Oscillator Count */
    __I      int8_t     OSCDIFF[4];                    /*!< Oscillator Difference */
} ADI_RNG_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_RNG_TypeDef__ */

/*!@}*/

/** @defgroup CRYPT Cryptogaphic (CRYPT) Module
 *  Cryptogaphic
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_CRYPT_TypeDef
 *  \brief  Cryptogaphic
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CRYPT_TypeDef__
typedef struct _ADI_CRYPT_TypeDef
{
    __IO     uint32_t   CFG;                           /*!< Configuration Register */
    __IO     uint32_t   DATALEN;                       /*!< Payload Data Length */
    __IO     uint32_t   PREFIXLEN;                     /*!< Authentication Data Length */
    __IO     uint32_t   INTEN;                         /*!< Interrupt Enable Register */
    __IO     uint32_t   STAT;                          /*!< Status Register */
    __O      int32_t    INBUF;                         /*!< Input Buffer */
    __I      int32_t    OUTBUF;                        /*!< Output Buffer */
    __IO     uint32_t   NONCE0;                        /*!< Nonce Bits [31:0] */
    __IO     uint32_t   NONCE1;                        /*!< Nonce Bits [63:32] */
    __IO     uint32_t   NONCE2;                        /*!< Nonce Bits [95:64] */
    __IO     uint32_t   NONCE3;                        /*!< Nonce Bits [127:96] */
    __O      uint32_t   AESKEY0;                       /*!< Key Bits[ 31:0 ] */
    __O      uint32_t   AESKEY1;                       /*!< Key Bits [ 63:32 ] */
    __O      uint32_t   AESKEY2;                       /*!< Key Bits [ 95:64 ] */
    __O      uint32_t   AESKEY3;                       /*!< Key Bits [ 127:96 ] */
    __O      uint32_t   AESKEY4;                       /*!< Key Bits [ 159:128 ] */
    __O      uint32_t   AESKEY5;                       /*!< Key Bits [ 191:160 ] */
    __O      uint32_t   AESKEY6;                       /*!< Key Bits [ 223:192 ] */
    __O      uint32_t   AESKEY7;                       /*!< Key Bits [ 255:224 ] */
    __IO     uint32_t   CNTRINIT;                      /*!< Counter Initialization Vector */
    __IO     uint32_t   SHAH0;                         /*!< SHA Bits [ 31:0 ] */
    __IO     uint32_t   SHAH1;                         /*!< SHA Bits [ 63:32 ] */
    __IO     uint32_t   SHAH2;                         /*!< SHA Bits [ 95:64 ] */
    __IO     uint32_t   SHAH3;                         /*!< SHA Bits [ 127:96 ] */
    __IO     uint32_t   SHAH4;                         /*!< SHA Bits [ 159:128 ] */
    __IO     uint32_t   SHAH5;                         /*!< SHA Bits [ 191:160 ] */
    __IO     uint32_t   SHAH6;                         /*!< SHA Bits [ 223:192] */
    __IO     uint32_t   SHAH7;                         /*!< SHA Bits [ 255:224 ] */
    __IO     uint32_t   SHA_LAST_WORD;                 /*!< SHA Last Word and Valid Bits Information */
    __IO     uint32_t   CCM_NUM_VALID_BYTES;           /*!< NUM_VALID_BYTES */
} ADI_CRYPT_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CRYPT_TypeDef__ */

/*!@}*/

/** @defgroup PMG Power Management  (PMG) Module
 *  Power Management 
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_PMG_TypeDef
 *  \brief  Power Management 
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_TypeDef__
typedef struct _ADI_PMG_TypeDef
{
    __IO     uint32_t   IEN;                           /*!< Power Supply Monitor Interrupt Enable */
    __IO     uint32_t   PSM_STAT;                      /*!< Power supply monitor status */
    __IO     uint32_t   PWRMOD;                        /*!< Power Mode Register */
    __O      uint32_t   PWRKEY;                        /*!< Key protection for PWRMOD and  SRAMRET */
    __I      uint32_t   SHDN_STAT;                     /*!< SHUTDOWN Status Register */
    __IO     uint32_t   SRAMRET;                       /*!< Control for Retention SRAM during HIBERNATE Mode */
    __I      uint8_t  RESERVED0[40];
    __IO     uint32_t   RST_STAT;                      /*!< Reset status */
    __IO     uint32_t   CTL1;                          /*!< HPBUCK control */
    __I      uint8_t  RESERVED1[20];
} ADI_PMG_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_TypeDef__ */

/*!@}*/

/** @defgroup XINT External interrupt configuration (XINT) Module
 *  External interrupt configuration
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_XINT_TypeDef
 *  \brief  External interrupt configuration
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_XINT_TypeDef__
typedef struct _ADI_XINT_TypeDef
{
    __IO     uint32_t   CFG0;                          /*!< External Interrupt Configuration */
    __I      uint32_t   EXT_STAT;                      /*!< External Wakeup Interrupt Status */
    __I      uint8_t  RESERVED0[8];
    __IO     uint32_t   CLR;                           /*!< External Interrupt Clear */
    __IO     uint32_t   NMICLR;                        /*!< Non-Maskable Interrupt Clear */
} ADI_XINT_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_XINT_TypeDef__ */

/*!@}*/

/** @defgroup CLKG_OSC Clocking  (CLKG_OSC) Module
 *  Clocking 
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_CLKG_OSC_TypeDef
 *  \brief  Clocking 
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CLKG_OSC_TypeDef__
typedef struct _ADI_CLKG_OSC_TypeDef
{
    __I      uint8_t  RESERVED0[12];
    __O      uint32_t   KEY;                           /*!< Key Protection for OSCCTRL */
    __IO     uint32_t   CTL;                           /*!< Oscillator Control */
    __I      uint8_t  RESERVED1[8];
} ADI_CLKG_OSC_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CLKG_OSC_TypeDef__ */

/*!@}*/

/** @defgroup PMG_TST Power Management  (PMG_TST) Module
 *  Power Management 
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_PMG_TST_TypeDef
 *  \brief  Power Management 
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_PMG_TST_TypeDef__
typedef struct _ADI_PMG_TST_TypeDef
{
    __I      uint8_t  RESERVED0[96];
    __IO     uint32_t   SRAM_CTL;                      /*!< Control for SRAM parity and instruction SRAM */
    __IO     uint32_t   SRAM_INITSTAT;                 /*!< Initialization Status Register */
    __O      uint16_t   CLR_LATCH_GPIOS;               /*!< CLEAR GPIO AFTER SHUTDOWN MODE */
    __I      uint8_t  RESERVED1[2];
    __IO     uint32_t   SCRPAD_IMG;                    /*!< SCRATCH PAD IMAGE */
    __I      uint32_t   SCRPAD_3V_RD;                  /*!< SCRATCH PAD SAVED IN BATTERY DOMAIN */
} ADI_PMG_TST_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_PMG_TST_TypeDef__ */

/*!@}*/

/** @defgroup CLKG_CLK Clocking  (CLKG_CLK) Module
 *  Clocking 
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_CLKG_CLK_TypeDef
 *  \brief  Clocking 
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_TypeDef__
typedef struct _ADI_CLKG_CLK_TypeDef
{
    __IO     uint32_t   CTL0;                          /*!< Misc clock settings */
    __IO     uint32_t   CTL1;                          /*!< Clock dividers */
    __I      uint8_t  RESERVED0[4];
    __IO     uint32_t   CTL3;                          /*!< System PLL */
    __I      uint8_t  RESERVED1[4];
    __IO     uint32_t   CTL5;                          /*!< User clock gating control */
    __IO     uint32_t   STAT0;                         /*!< Clocking status */
    __I      uint8_t  RESERVED2[20];
} ADI_CLKG_CLK_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_CLKG_CLK_TypeDef__ */

/*!@}*/

/** @defgroup BUSM Bus matrix (BUSM) Module
 *  Bus matrix
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_BUSM_TypeDef
 *  \brief  Bus matrix
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_BUSM_TypeDef__
typedef struct _ADI_BUSM_TypeDef
{
    __IO     uint32_t   ARBIT0;                        /*!< Arbitration Priority Configuration for FLASH and SRAM0 */
    __IO     uint32_t   ARBIT1;                        /*!< Arbitration Priority Configuration for SRAM1 and SIP */
    __IO     uint32_t   ARBIT2;                        /*!< Arbitration Priority Configuration for APB32 and APB16 */
    __IO     uint32_t   ARBIT3;                        /*!< Arbitration Priority Configuration for APB16 priority for core and for DMA1 */
    __I      uint8_t  RESERVED0[4];
} ADI_BUSM_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_BUSM_TypeDef__ */

/*!@}*/

/** @defgroup AGPIO  (AGPIO) Module
 *  
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_AGPIO_TypeDef
 *  \brief  
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPIO_TypeDef__
typedef struct _ADI_AGPIO_TypeDef
{
    __IO     uint32_t   CON;                           /*!< GPIO Port Configuration */
    __IO     uint16_t   OEN;                           /*!< GPIO Port Output Enable */
    __I      uint8_t  RESERVED0[2];
    __IO     uint16_t   PE;                            /*!< GPIO Port Pullup/Pulldown Enable */
    __I      uint8_t  RESERVED1[2];
    __IO     uint16_t   IEN;                           /*!< GPIO Port Input Path Enable */
    __I      uint8_t  RESERVED2[2];
    __I      uint16_t   IN;                            /*!< GPIO Port Registered Data Input */
    __I      uint8_t  RESERVED3[2];
    __IO     uint16_t   OUT;                           /*!< GPIO Port Data Output */
    __I      uint8_t  RESERVED4[2];
    __O      uint16_t   SET;                           /*!< GPIO Port Data Out Set */
    __I      uint8_t  RESERVED5[2];
    __O      uint16_t   CLR;                           /*!< GPIO Port Data Out Clear */
    __I      uint8_t  RESERVED6[2];
    __O      uint16_t   TGL;                           /*!< GPIO Port Pin Toggle */
} ADI_AGPIO_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPIO_TypeDef__ */

/*!@}*/

/** @defgroup AFECON  (AFECON) Module
 *  
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_AFECON_TypeDef
 *  \brief  
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFECON_TypeDef__
typedef struct _ADI_AFECON_TypeDef
{
    __I      uint16_t   ADIID;                         /*!< ADI Identification */
    __I      uint8_t  RESERVED0[2];
    __I      uint16_t   CHIPID;                        /*!< Chip Identification */
    __I      uint8_t  RESERVED1[2];
    __IO     uint16_t   CLKCON0;                       /*!< Clock Divider Configuration */
    __I      uint8_t  RESERVED2[6];
    __IO     uint16_t   CLKEN1;                        /*!< Clock Gate Enable */
    __I      uint8_t  RESERVED3[2];
    __IO     uint16_t   CLKSEL;                        /*!< Clock Select */
    __I      uint8_t  RESERVED4[6];
    __IO     uint16_t   GPIOCLKMUXSEL;                 /*!< GPIO Clock MUX Select */
    __I      uint8_t  RESERVED5[2];
    __IO     uint16_t   CLKCON0KEY;                    /*!< Enable Clock Division to 8Mhz,4Mhz and 2Mhz */
    __I      uint8_t  RESERVED6[18];
    __O      uint16_t   MKEY;                          /*!< MKEY */
    __I      uint8_t  RESERVED7[2];
    __IO     uint16_t   DSPUPDATEEN;                   /*!< DSP Update Enable */
    __I      uint8_t  RESERVED8[4];
} ADI_AFECON_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFECON_TypeDef__ */

/*!@}*/

/** @defgroup AFEWDT  (AFEWDT) Module
 *  
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_AFEWDT_TypeDef
 *  \brief  
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFEWDT_TypeDef__
typedef struct _ADI_AFEWDT_TypeDef
{
    __IO     int16_t    WDTLD;                         /*!< Watchdog Timer Load Value */
    __I      uint8_t  RESERVED0[2];
    __I      int16_t    WDTVALS;                       /*!< Current Count Value */
    __I      uint8_t  RESERVED1[2];
    __IO     uint16_t   WDTCON;                        /*!< Watchdog Timer Control Register */
    __I      uint8_t  RESERVED2[2];
    __O      int16_t    WDTCLRI;                       /*!< Refresh Watchdog Register */
    __I      uint8_t  RESERVED3[10];
    __IO     uint16_t   WDTSTA;                        /*!< Timer Status */
    __I      uint8_t  RESERVED4[2];
    __IO     int16_t    WDTMINLD;                      /*!< Minimum Load Value */
} ADI_AFEWDT_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFEWDT_TypeDef__ */

/*!@}*/

/** @defgroup ALLON Always On Register (ALLON) Module
 *  Always On Register
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_ALLON_TypeDef
 *  \brief  Always On Register
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_ALLON_TypeDef__
typedef struct _ADI_ALLON_TypeDef
{
    __IO     uint16_t   PWRMOD;                        /*!< Power Modes */
    __I      uint8_t  RESERVED0[2];
    __IO     int16_t    PWRKEY;                        /*!< Key Protection for PWRMOD */
    __I      uint8_t  RESERVED1[6];
    __IO     int16_t    OSCKEY;                        /*!< Key Protection for OSCCON */
    __I      uint8_t  RESERVED2[2];
    __IO     uint16_t   OSCCON;                        /*!< Oscillator Control */
    __I      uint8_t  RESERVED3[22];
    __IO     uint16_t   EI2CON;                        /*!< External Interrupt Configuration 2 */
    __I      uint8_t  RESERVED4[6];
    __IO     uint16_t   EICLR;                         /*!< External Interrupt Clear */
    __I      uint8_t  RESERVED5[14];
    __IO     uint16_t   RSTSTA;                        /*!< Reset Status */
    __I      uint8_t  RESERVED6[2];
    __I      uint16_t   PMUSTA;                        /*!< PMU Status */
    __I      uint8_t  RESERVED7[42];
    __IO     uint16_t   CLKEN0;                        /*!< 32KHz Peripheral Clock Enable */
    __I      uint8_t  RESERVED8[12];
} ADI_ALLON_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_ALLON_TypeDef__ */

/*!@}*/

/** @defgroup AGPT0 General Purpose Timer (AGPT0) Module
 *  General Purpose Timer
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_AGPT0_TypeDef
 *  \brief  General Purpose Timer
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT0_TypeDef__
typedef struct _ADI_AGPT0_TypeDef
{
    __IO     int16_t    LD0;                           /*!< 16-bit Load Value Register. */
    __I      uint8_t  RESERVED0[2];
    __I      int16_t    VAL0;                          /*!< 16-Bit Timer Value Register. */
    __I      uint8_t  RESERVED1[2];
    __IO     uint16_t   CON0;                          /*!< Control Register. */
    __I      uint8_t  RESERVED2[2];
    __O      uint16_t   CLRI0;                         /*!< Clear Interrupt Register. */
    __I      uint8_t  RESERVED3[2];
    __I      int16_t    CAP0;                          /*!< Capture Register. */
    __I      uint8_t  RESERVED4[2];
    __IO     int16_t    ALD0;                          /*!< 16-Bit Load Value, Asynchronous. */
    __I      uint8_t  RESERVED5[2];
    __I      int16_t    AVAL0;                         /*!< 16-Bit Timer Value, Asynchronous Register. */
    __I      uint8_t  RESERVED6[2];
    __I      uint16_t   STA0;                          /*!< Status Register. */
    __I      uint8_t  RESERVED7[2];
    __IO     uint16_t   PWMCON0;                       /*!< PWM Control Register. */
    __I      uint8_t  RESERVED8[2];
    __IO     int16_t    PWMMAT0;                       /*!< PWM Match Value Register. */
    __I      uint8_t  RESERVED9[2];
    __IO     uint16_t   INTEN;                         /*!< Interrupt Enable */
} ADI_AGPT0_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT0_TypeDef__ */

/*!@}*/

/** @defgroup AGPT1 General Purpose Timer (AGPT1) Module
 *  General Purpose Timer
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_AGPT1_TypeDef
 *  \brief  General Purpose Timer
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AGPT1_TypeDef__
typedef struct _ADI_AGPT1_TypeDef
{
    __IO     int16_t    LD1;                           /*!< 16-bit Load Value Register */
    __I      uint8_t  RESERVED0[2];
    __I      int16_t    VAL1;                          /*!< 16-bit Timer Value Register */
    __I      uint8_t  RESERVED1[2];
    __IO     uint16_t   CON1;                          /*!< Control Register */
    __I      uint8_t  RESERVED2[2];
    __O      uint16_t   CLRI1;                         /*!< Clear Interrupt Register */
    __I      uint8_t  RESERVED3[2];
    __I      int16_t    CAP1;                          /*!< Capture Register */
    __I      uint8_t  RESERVED4[2];
    __IO     int16_t    ALD1;                          /*!< 16-bit Load Value, Asynchronous Register */
    __I      uint8_t  RESERVED5[2];
    __I      int16_t    AVAL1;                         /*!< 16-bit Timer Value, Asynchronous Register */
    __I      uint8_t  RESERVED6[2];
    __I      uint16_t   STA1;                          /*!< Status Register */
    __I      uint8_t  RESERVED7[2];
    __IO     uint16_t   PWMCON1;                       /*!< PWM Control Register */
    __I      uint8_t  RESERVED8[2];
    __IO     int16_t    PWMMAT1;                       /*!< PWM Match Value Register */
    __I      uint8_t  RESERVED9[2];
    __IO     uint16_t   INTEN1;                        /*!< Interrupt Enable */
} ADI_AGPT1_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AGPT1_TypeDef__ */

/*!@}*/

/** @defgroup AFECRC CRC Accelerator (AFECRC) Module
 *  CRC Accelerator
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_AFECRC_TypeDef
 *  \brief  CRC Accelerator
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFECRC_TypeDef__
typedef struct _ADI_AFECRC_TypeDef
{
    __IO     uint32_t   CTL;                           /*!< CRC Control Register */
    __O      int32_t    IPDATA;                        /*!< Data Input. */
    __IO     int32_t    RESULT;                        /*!< CRC Residue */
    __IO     uint32_t   POLY;                          /*!< CRC Reduction Polynomial */
    __O      uint8_t    IPBITS;                        /*!< Input Data Bits */
    __I      uint8_t  RESERVED0[3];
    __O      uint8_t    IPBYTE;                        /*!< Input Data Byte */
    __I      uint8_t  RESERVED1[11];
    __IO     uint32_t   CRC_SIG_COMP;                  /*!< CRC Signature Compare Data Input. */
    __IO     uint32_t   CRCINTEN;                      /*!< CRC Error Interrupt Enable Bit */
    __IO     uint32_t   INTSTA;                        /*!< CRC Error Interrupt Status Bit */
} ADI_AFECRC_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFECRC_TypeDef__ */

/*!@}*/

/** @defgroup AFE  (AFE) Module
 *  
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_AFE_TypeDef
 *  \brief  
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_AFE_TypeDef__
typedef struct _ADI_AFE_TypeDef
{
    __IO     uint32_t   AFECON;                        /*!< AFE Configuration */
    __I      uint8_t  RESERVED0[8];
    __IO     uint32_t   SWCON;                         /*!< Switch Matrix Configuration */
    __IO     uint32_t   HSDACCON;                      /*!< High Speed DAC Configuration */
    __IO     uint32_t   WGCON;                         /*!< Waveform Generator Configuration */
    __I      uint8_t  RESERVED1[24];
    __IO     uint32_t   WGFCW;                         /*!< Waveform Generator - Sinusoid Frequency Control Word */
    __IO     uint32_t   WGPHASE;                       /*!< Waveform Generator - Sinusoid Phase Offset */
    __IO     uint32_t   WGOFFSET;                      /*!< Waveform Generator - Sinusoid Offset */
    __IO     uint32_t   WGAMPLITUDE;                   /*!< Waveform Generator - Sinusoid Amplitude */
    __I      uint8_t  RESERVED2[4];
    __IO     uint32_t   ADCFILTERCON;                  /*!< ADC Output Filters Configuration */
    __IO     uint32_t   HSDACDAT;                      /*!< HS DAC Code */
    __I      uint8_t  RESERVED3[4];
    __IO     uint32_t   LPREFBUFCON;                   /*!< LPREF_BUF_CON */
    __I      uint8_t  RESERVED4[32];
    __IO     uint32_t   ADCDAT;                        /*!< ADC Raw Result */
    __IO     uint32_t   DFTREAL;                       /*!< DFT Result, Real Part */
    __IO     uint32_t   DFTIMAG;                       /*!< DFT Result, Imaginary Part */
    __IO     uint32_t   SINC2DAT;                      /*!< Supply Rejection Filter Result */
    __IO     uint32_t   TEMPSENSDAT;                   /*!< Temperature Sensor Result */
    __IO     uint32_t   ADCINTIEN;                     /*!< ADC Interrupt Enable Register */
    __I      uint8_t  RESERVED5[12];
    __IO     uint32_t   ADCINTSTA;                     /*!< ADC Interrupt Status */
    __IO     uint32_t   AFEGENINTSTA;                  /*!< Analog Generation Interrupt */
    __I      uint8_t  RESERVED6[8];
    __IO     uint32_t   ADCMIN;                        /*!< ADC Minimum Value Check */
    __IO     uint32_t   ADCMINSM;                      /*!< ADCMIN Hysteresis Value */
    __IO     uint32_t   ADCMAX;                        /*!< ADC Maximum Value Check */
    __IO     uint32_t   ADCMAXSMEN;                    /*!< ADCMAX Hysteresis Value */
    __IO     uint32_t   ADCDELTA;                      /*!< ADC Delta Value */
    __IO     uint32_t   HPOSCCON;                      /*!< HPOSC Configuration */
    __I      uint8_t  RESERVED7[16];
    __IO     uint32_t   DFTCON;                        /*!< AFE DSP Configuration */
    __I      uint8_t  RESERVED8[12];
    __IO     uint32_t   LPTIASW1;                      /*!< ULPTIA Switch Configuration for Channel 1 */
    __IO     uint32_t   LPTIASW0;                      /*!< ULPTIA Switch Configuration for Channel 0 */
    __IO     uint32_t   LPTIACON1;                     /*!< ULPTIA Control Bits Channel 1 */
    __IO     uint32_t   LPTIACON0;                     /*!< ULPTIA Control Bits Channel 0 */
    __IO     uint32_t   HSRTIACON;                     /*!< High Power RTIA Configuration */
    __IO     uint32_t   DE1RESCON;                     /*!< DE1 HSTIA Resistors Configuration */
    __IO     uint32_t   DE0RESCON;                     /*!< DE0 HSTIA Resistors Configuration */
    __IO     uint32_t   HSTIACON;                      /*!< HSTIA Amplifier Configuration */
    __I      uint8_t  RESERVED9[4];
    __IO     uint32_t   DACDCBUFCON;                   /*!< DAC DC Buffer Configuration */
    __I      uint8_t  RESERVED10[24];
    __IO     uint32_t   LPDACDAT0;                     /*!< LPDAC Data-out */
    __IO     uint32_t   LPDACSW0;                      /*!< LPDAC0 Switch Control */
    __IO     uint32_t   LPDACCON0;                     /*!< LPDAC Control Bits */
    __IO     uint32_t   LPDACDAT1;                     /*!< Low Power DAC1 data register */
    __IO     uint32_t   LPDACSW1;                      /*!< Control register for switches to LPDAC1 */
    __IO     uint32_t   LPDACCON1;                     /*!< ULP_DACCON1 */
    __I      uint8_t  RESERVED11[24];
    __IO     uint32_t   DSWFULLCON;                    /*!< Switch Matrix Full Configuration (D) */
    __IO     uint32_t   NSWFULLCON;                    /*!< Switch Matrix Full Configuration (N) */
    __IO     uint32_t   PSWFULLCON;                    /*!< Switch Matrix Full Configuration (P) */
    __IO     uint32_t   TSWFULLCON;                    /*!< Switch Matrix Full Configuration (T) */
    __I      uint8_t  RESERVED12[20];
    __IO     uint32_t   TEMPCON0;                      /*!< Temp Sensor Configuration */
    __I      uint8_t  RESERVED13[8];
    __IO     uint32_t   BUFSENCON;                     /*!< HP and LP Buffer Control */
    __I      uint8_t  RESERVED14[36];
    __IO     uint32_t   ADCCON;                        /*!< ADC Configuration */
    __I      uint8_t  RESERVED15[4];
    __I      uint32_t   DSWSTA;                        /*!< Switch Matrix Status (D) */
    __I      uint32_t   PSWSTA;                        /*!< Switch Matrix Status (P) */
    __I      uint32_t   NSWSTA;                        /*!< Switch Matrix Status (N) */
    __I      uint32_t   TSWSTA;                        /*!< Switch Matrix Status (T) */
    __I      uint32_t   STATSVAR;                      /*!< Variance Output */
    __IO     uint32_t   STATSCON;                      /*!< Statistics Control */
    __I      uint32_t   STATSMEAN;                     /*!< Statistics Mean Output */
    __I      uint8_t  RESERVED16[36];
    __IO     uint32_t   REPEATADCCNV;                  /*!< REPEAT ADC Conversions */
    __I      uint8_t  RESERVED17[60];
    __IO     uint32_t   CALDATLOCK;                    /*!< Calibration Data Lock */
    __IO     uint32_t   ADCOFFSETHSTIA;                /*!< ADC Offset Calibration High Speed TIA Channel */
    __IO     uint32_t   ADCGAINTEMPSENS0;              /*!< ADC Gain Calibration Temp Sensor Channel */
    __IO     uint32_t   ADCOFFSETTEMPSENS0;            /*!< ADC Offset Calibration Temp Sensor Channel 0 */
    __IO     uint32_t   ADCGAINGN1;                    /*!< ADCPGAGN1: ADC Gain Calibration Auxiliary Input Channel */
    __IO     uint32_t   ADCOFFSETGN1;                  /*!< ADC Offset Calibration Auxiliary Channel (PGA Gain=1) */
    __I      uint8_t  RESERVED18[24];
    __IO     uint32_t   DACGAIN;                       /*!< DACGAIN */
    __IO     uint32_t   DACOFFSETATTEN;                /*!< DAC Offset with Attenuator Enabled (LP Mode) */
    __IO     uint32_t   DACOFFSET;                     /*!< DAC Offset with Attenuator Disabled (LP Mode) */
    __I      uint8_t  RESERVED19[4];
    __IO     uint32_t   ADCGAINGN1P5;                  /*!< ADC Gain Calibration Auxiliary Input Channel (PGA Gain=1.5) */
    __IO     uint32_t   ADCGAINGN2;                    /*!< ADC Gain Calibration Auxiliary Input Channel (PGA Gain=2) */
    __IO     uint32_t   ADCGAINGN4;                    /*!< ADC Gain Calibration Auxiliary Input Channel (PGA Gain=4) */
    __I      uint8_t  RESERVED20[4];
    __IO     uint32_t   ADCPGAOFFSETCANCEL;            /*!< ADC Offset Cancellation (Optional) */
    __IO     uint32_t   ADCGNHSTIA;                    /*!< ADC Gain Calibration for HS TIA Channel */
    __IO     uint32_t   ADCOFFSETLPTIA0;               /*!< ADC Offset Calibration ULP-TIA0 Channel */
    __IO     uint32_t   ADCGNLPTIA0;                   /*!< ADC GAIN Calibration for LP TIA0 Channel */
    __I      uint8_t  RESERVED21[4];
    __IO     uint32_t   ADCPGAGN4OFCAL;                /*!< ADC Gain Calibration with DC Cancellation(PGA G=4) */
    __IO     uint32_t   ADCGAINGN9;                    /*!< ADC Gain Calibration Auxiliary Input Channel (PGA Gain=9) */
    __I      uint8_t  RESERVED22[12];
    __IO     uint32_t   ADCOFFSETEMPSENS1;             /*!< ADC Offset Calibration  Temp Sensor Channel 1 */
    __IO     uint32_t   ADCGAINTEMPSENS1;              /*!< ADC Gain Calibration Temperature Sensor Channel */
    __I      uint8_t  RESERVED23[8];
    __IO     uint32_t   DACOFFSETATTENHP;              /*!< DAC Offset with Attenuator Enabled (HP Mode) */
    __IO     uint32_t   DACOFFSETHP;                   /*!< DAC Offset with Attenuator Disabled (HP Mode) */
    __IO     uint32_t   ADCOFFSETLPTIA1;               /*!< ADC Offset Calibration LP TIA1 Channel */
    __IO     uint32_t   ADCGNLPTIA1;                   /*!< ADC GAIN Calibration for LP TIA1 Channel */
    __IO     uint32_t   ADCOFFSETGN2;                  /*!< Offset Calibration Auxiliary Channel (PGA Gain =2) */
    __IO     uint32_t   ADCOFFSETGN1P5;                /*!< Offset Calibration Auxiliary Channel (PGA Gain =1.5) */
    __IO     uint32_t   ADCOFFSETGN9;                  /*!< Offset Calibration Auxiliary Channel (PGA Gain =9) */
    __IO     uint32_t   ADCOFFSETGN4;                  /*!< Offset Calibration Auxiliary Channel (PGA Gain =4) */
    __I      uint8_t  RESERVED24[24];
    __IO     uint32_t   PMBW;                          /*!< Power Mode Configuration */
    __I      uint8_t  RESERVED25[104];
    __IO     uint32_t   SWMUX;                         /*!< Switch Mux for ECG */
    __I      uint8_t  RESERVED26[20];
    __IO     uint32_t   TEMPCON1;                      /*!< AFE_TEMPSEN_DIO */
    __I      uint8_t  RESERVED27[16];
    __IO     uint32_t   TESTDAC;                       /*!< DAC Test */
    __IO     uint32_t   ADCBUFCON;                     /*!< Configure ADC Input Buffer */
    __I      uint8_t  RESERVED28[112];
} ADI_AFE_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_AFE_TypeDef__ */

/*!@}*/

/** @defgroup NVIC Cortex-M3 Interrupt Controller (NVIC) Module
 *  Cortex-M3 Interrupt Controller
 *  @{
 */

/*! ==========================================================================
 *  \struct ADI_NVIC_TypeDef
 *  \brief  Cortex-M3 Interrupt Controller
 *  ========================================================================== */
#ifndef __ADI_NO_DECL_STRUCT_ADI_NVIC_TypeDef__
typedef struct _ADI_NVIC_TypeDef
{
    __I      uint8_t  RESERVED0[4];
    __IO     uint32_t   INTNUM;                        /*!< Interrupt Control Type */
    __I      uint8_t  RESERVED1[8];
    __IO     uint32_t   STKSTA;                        /*!< Systick Control and Status */
    __IO     uint32_t   STKLD;                         /*!< Systick Reload Value */
    __IO     uint32_t   STKVAL;                        /*!< Systick Current Value */
    __IO     uint32_t   STKCAL;                        /*!< Systick Calibration Value */
    __I      uint8_t  RESERVED2[224];
    __IO     uint32_t   INTSETE0;                      /*!< IRQ0..31 Set_Enable */
    __IO     uint32_t   INTSETE1;                      /*!< IRQ32..63 Set_Enable */
    __I      uint8_t  RESERVED3[120];
    __IO     uint32_t   INTCLRE0;                      /*!< IRQ0..31 Clear_Enable */
    __IO     uint32_t   INTCLRE1;                      /*!< IRQ32..63 Clear_Enable */
    __I      uint8_t  RESERVED4[120];
    __IO     uint32_t   INTSETP0;                      /*!< IRQ0..31 Set_Pending */
    __IO     uint32_t   INTSETP1;                      /*!< IRQ32..63 Set_Pending */
    __I      uint8_t  RESERVED5[120];
    __IO     uint32_t   INTCLRP0;                      /*!< IRQ0..31 Clear_Pending */
    __IO     uint32_t   INTCLRP1;                      /*!< IRQ32..63 Clear_Pending */
    __I      uint8_t  RESERVED6[120];
    __IO     uint32_t   INTACT0;                       /*!< IRQ0..31 Active Bit */
    __IO     uint32_t   INTACT1;                       /*!< IRQ32..63 Active Bit */
    __I      uint8_t  RESERVED7[248];
    __IO     uint32_t   INTPRI0;                       /*!< IRQ0..3 Priority */
    __IO     uint32_t   INTPRI1;                       /*!< IRQ4..7 Priority */
    __IO     uint32_t   INTPRI2;                       /*!< IRQ8..11 Priority */
    __IO     uint32_t   INTPRI3;                       /*!< IRQ12..15 Priority */
    __IO     uint32_t   INTPRI4;                       /*!< IRQ16..19 Priority */
    __IO     uint32_t   INTPRI5;                       /*!< IRQ20..23 Priority */
    __IO     uint32_t   INTPRI6;                       /*!< IRQ24..27 Priority */
    __IO     uint32_t   INTPRI7;                       /*!< IRQ28..31 Priority */
    __IO     uint32_t   INTPRI8;                       /*!< IRQ32..35 Priority */
    __IO     uint32_t   INTPRI9;                       /*!< IRQ36..39 Priority */
    __IO     uint32_t   INTPRI10;                      /*!< IRQ40..43 Priority */
    __I      uint8_t  RESERVED8[2260];
    __IO     uint32_t   INTCPID;                       /*!< CPUID Base */
    __IO     uint32_t   INTSTA;                        /*!< Interrupt Control State */
    __IO     uint32_t   INTVEC;                        /*!< Vector Table Offset */
    __IO     uint32_t   INTAIRC;                       /*!< Application Interrupt/Reset Control */
    __IO     uint16_t   INTCON0;                       /*!< System Control */
    __I      uint8_t  RESERVED9[2];
    __IO     uint32_t   INTCON1;                       /*!< Configuration Control */
    __IO     uint32_t   INTSHPRIO0;                    /*!< System Handlers 4-7 Priority */
    __IO     uint32_t   INTSHPRIO1;                    /*!< System Handlers 8-11 Priority */
    __IO     uint32_t   INTSHPRIO3;                    /*!< System Handlers 12-15 Priority */
    __IO     uint32_t   INTSHCSR;                      /*!< System Handler Control and State */
    __IO     uint32_t   INTCFSR;                       /*!< Configurable Fault Status */
    __IO     uint32_t   INTHFSR;                       /*!< Hard Fault Status */
    __IO     uint32_t   INTDFSR;                       /*!< Debug Fault Status */
    __IO     uint32_t   INTMMAR;                       /*!< Mem Manage Address */
    __IO     uint32_t   INTBFAR;                       /*!< Bus Fault Address */
    __IO     uint32_t   INTAFSR;                       /*!< Auxiliary Fault Status */
    __IO     uint32_t   INTPFR0;                       /*!< Processor Feature Register 0 */
    __IO     uint32_t   INTPFR1;                       /*!< Processor Feature Register 1 */
    __IO     uint32_t   INTDFR0;                       /*!< Debug Feature Register 0 */
    __IO     uint32_t   INTAFR0;                       /*!< Auxiliary Feature Register 0 */
    __IO     uint32_t   INTMMFR0;                      /*!< Memory Model Feature Register 0 */
    __IO     uint32_t   INTMMFR1;                      /*!< Memory Model Feature Register 1 */
    __IO     uint32_t   INTMMFR2;                      /*!< Memory Model Feature Register 2 */
    __IO     uint32_t   INTMMFR3;                      /*!< Memory Model Feature Register 3 */
    __IO     uint32_t   INTISAR0;                      /*!< ISA Feature Register 0 */
    __IO     uint32_t   INTISAR1;                      /*!< ISA Feature Register 1 */
    __IO     uint32_t   INTISAR2;                      /*!< ISA Feature Register 2 */
    __IO     uint32_t   INTISAR3;                      /*!< ISA Feature Register 3 */
    __IO     uint32_t   INTISAR4;                      /*!< ISA Feature Register 4 */
    __I      uint8_t  RESERVED10[396];
    __IO     uint32_t   INTTRGI;                       /*!< Software Trigger Interrupt Register */
    __I      uint8_t  RESERVED11[204];
    __IO     uint32_t   INTPID4;                       /*!< Peripheral Identification Register 4 */
    __IO     uint32_t   INTPID5;                       /*!< Peripheral Identification Register 5 */
    __IO     uint32_t   INTPID6;                       /*!< Peripheral Identification Register 6 */
    __IO     uint32_t   INTPID7;                       /*!< Peripheral Identification Register 7 */
    __IO     uint32_t   INTPID0;                       /*!< Peripheral Identification Bits7:0 */
    __IO     uint32_t   INTPID1;                       /*!< Peripheral Identification Bits15:8 */
    __IO     uint32_t   INTPID2;                       /*!< Peripheral Identification Bits16:23 */
    __IO     uint32_t   INTPID3;                       /*!< Peripheral Identification Bits24:31 */
    __IO     uint32_t   INTCID0;                       /*!< Component Identification Bits7:0 */
    __IO     uint32_t   INTCID1;                       /*!< Component Identification Bits15:8 */
    __IO     uint32_t   INTCID2;                       /*!< Component Identification Bits16:23 */
    __IO     uint32_t   INTCID3;                       /*!< Component Identification Bits24:31 */
} ADI_NVIC_TypeDef;
#endif /* !__ADI_NO_DECL_STRUCT_ADI_NVIC_TypeDef__ */

/*!@}*/

/* ******************************************************************************
 *    Peripheral Memory Map Declarations
 * *****************************************************************************/
/*!    @defgroup PMEMMAPDEC Peripheral Memory Map Declarations
 *     \addtogroup PMEMMAPDEC
 *     @{ */
#define ADI_TMR0_BASE                  0x40000000    /*!<  Base address of TMR0 */
#define ADI_TMR1_BASE                  0x40000400    /*!<  Base address of TMR1 */
#define ADI_TMR2_BASE                  0x40000800    /*!<  Base address of TMR2 */
#define ADI_RTC0_BASE                  0x40001000    /*!<  Base address of RTC0 */
#define ADI_RTC1_BASE                  0x40001400    /*!<  Base address of RTC1 */
#define ADI_SYS_BASE                   0x40002000    /*!<  Base address of SYS */
#define ADI_WDT0_BASE                  0x40002c00    /*!<  Base address of WDT0 */
#define ADI_I2C0_BASE                  0x40003000    /*!<  Base address of I2C0 */
#define ADI_SPI0_BASE                  0x40004000    /*!<  Base address of SPI0 */
#define ADI_SPI1_BASE                  0x40024000    /*!<  Base address of SPI1 */
#define ADI_UART0_BASE                 0x40005000    /*!<  Base address of UART0 */
#define ADI_DMA0_BASE                  0x40010000    /*!<  Base address of DMA0 */
#define ADI_FLCC0_BASE                 0x40018000    /*!<  Base address of FLCC0 */
#define ADI_FLCC0_CACHE_BASE           0x40018058    /*!<  Base address of FLCC0_CACHE */
#define ADI_GPIO0_BASE                 0x40020000    /*!<  Base address of GPIO0 */
#define ADI_GPIO1_BASE                 0x40020040    /*!<  Base address of GPIO1 */
#define ADI_GPIO2_BASE                 0x40020080    /*!<  Base address of GPIO2 */
#define ADI_CRC0_BASE                  0x40040000    /*!<  Base address of CRC0 */
#define ADI_RNG0_BASE                  0x40040400    /*!<  Base address of RNG0 */
#define ADI_CRYPT0_BASE                0x40044000    /*!<  Base address of CRYPT0 */
#define ADI_PMG0_BASE                  0x4004c000    /*!<  Base address of PMG0 */
#define ADI_XINT0_BASE                 0x4004c080    /*!<  Base address of XINT0 */
#define ADI_CLKG0_OSC_BASE             0x4004c100    /*!<  Base address of CLKG0_OSC */
#define ADI_PMG0_TST_BASE              0x4004c200    /*!<  Base address of PMG0_TST */
#define ADI_CLKG0_CLK_BASE             0x4004c300    /*!<  Base address of CLKG0_CLK */
#define ADI_BUSM0_BASE                 0x4004c800    /*!<  Base address of BUSM0 */
#define ADI_AGPIO2_BASE                0x400c0080    /*!<  Base address of AGPIO2 */
#define ADI_AFECON_BASE                0x400c0400    /*!<  Base address of AFECON */
#define ADI_AFEWDT_BASE                0x400c0900    /*!<  Base address of AFEWDT */
#define ADI_ALLON_BASE                 0x400c0a00    /*!<  Base address of ALLON */
#define ADI_AGPT0_BASE                 0x400c0d00    /*!<  Base address of AGPT0 */
#define ADI_AGPT1_BASE                 0x400c0e00    /*!<  Base address of AGPT1 */
#define ADI_AFECRC_BASE                0x400c1000    /*!<  Base address of AFECRC */
#define ADI_AFE_BASE                   0x400c2000    /*!<  Base address of AFE */
#define ADI_NVIC0_BASE                 0xe000e000    /*!<  Base address of NVIC0 */

/*!    @} */

/* ******************************************************************************
 *    Peripheral Pointer Declarations
 * *****************************************************************************/
/*!    @Defgroup Pptrdec Peripheral Pointer Declarations
 *     \Addtogroup Pptrdec
 *     @{ */
#define pADI_TMR0                      ((ADI_TMR_TypeDef      *) ADI_TMR0_BASE       ) /*!<  Pointer to General Purpose Timer (TMR0) */
#define pADI_TMR1                      ((ADI_TMR_TypeDef      *) ADI_TMR1_BASE       ) /*!<  Pointer to General Purpose Timer (TMR1) */
#define pADI_TMR2                      ((ADI_TMR_TypeDef      *) ADI_TMR2_BASE       ) /*!<  Pointer to General Purpose Timer (TMR2) */
#define pADI_RTC0                      ((ADI_RTC_TypeDef      *) ADI_RTC0_BASE       ) /*!<  Pointer to Real-Time Clock (RTC0) */
#define pADI_RTC1                      ((ADI_RTC_TypeDef      *) ADI_RTC1_BASE       ) /*!<  Pointer to Real-Time Clock (RTC1) */
#define pADI_SYS                       ((ADI_SYS_TypeDef      *) ADI_SYS_BASE        ) /*!<  Pointer to System Identification and Debug Enable (SYS) */
#define pADI_WDT0                      ((ADI_WDT_TypeDef      *) ADI_WDT0_BASE       ) /*!<  Pointer to Watchdog Timer (WDT0) */
#define pADI_I2C0                      ((ADI_I2C_TypeDef      *) ADI_I2C0_BASE       ) /*!<  Pointer to I2C Master/Slave (I2C0) */
#define pADI_SPI0                      ((ADI_SPI_TypeDef      *) ADI_SPI0_BASE       ) /*!<  Pointer to Serial Peripheral Interface (SPI0) */
#define pADI_SPI1                      ((ADI_SPI_TypeDef      *) ADI_SPI1_BASE       ) /*!<  Pointer to Serial Peripheral Interface (SPI1) */
#define pADI_UART0                     ((ADI_UART_TypeDef     *) ADI_UART0_BASE      ) /*!<  Pointer to  (UART0) */
#define pADI_DMA0                      ((ADI_DMA_TypeDef      *) ADI_DMA0_BASE       ) /*!<  Pointer to DMA (DMA0) */
#define pADI_FLCC0                     ((ADI_FLCC_TypeDef     *) ADI_FLCC0_BASE      ) /*!<  Pointer to Flash Controller (FLCC0) */
#define pADI_FLCC0_CACHE               ((ADI_FLCC_CACHE_TypeDef *) ADI_FLCC0_CACHE_BASE) /*!<  Pointer to Cache Controller (FLCC0_CACHE) */
#define pADI_GPIO0                     ((ADI_GPIO_TypeDef     *) ADI_GPIO0_BASE      ) /*!<  Pointer to  (GPIO0) */
#define pADI_GPIO1                     ((ADI_GPIO_TypeDef     *) ADI_GPIO1_BASE      ) /*!<  Pointer to  (GPIO1) */
#define pADI_GPIO2                     ((ADI_GPIO_TypeDef     *) ADI_GPIO2_BASE      ) /*!<  Pointer to  (GPIO2) */
#define pADI_CRC0                      ((ADI_CRC_TypeDef      *) ADI_CRC0_BASE       ) /*!<  Pointer to CRC Accelerator (CRC0) */
#define pADI_RNG0                      ((ADI_RNG_TypeDef      *) ADI_RNG0_BASE       ) /*!<  Pointer to Random Number Generator (RNG0) */
#define pADI_CRYPT0                    ((ADI_CRYPT_TypeDef    *) ADI_CRYPT0_BASE     ) /*!<  Pointer to Cryptogaphic (CRYPT0) */
#define pADI_PMG0                      ((ADI_PMG_TypeDef      *) ADI_PMG0_BASE       ) /*!<  Pointer to Power Management  (PMG0) */
#define pADI_XINT0                     ((ADI_XINT_TypeDef     *) ADI_XINT0_BASE      ) /*!<  Pointer to External interrupt configuration (XINT0) */
#define pADI_CLKG0_OSC                 ((ADI_CLKG_OSC_TypeDef *) ADI_CLKG0_OSC_BASE  ) /*!<  Pointer to Clocking  (CLKG0_OSC) */
#define pADI_PMG0_TST                  ((ADI_PMG_TST_TypeDef  *) ADI_PMG0_TST_BASE   ) /*!<  Pointer to Power Management  (PMG0_TST) */
#define pADI_CLKG0_CLK                 ((ADI_CLKG_CLK_TypeDef *) ADI_CLKG0_CLK_BASE  ) /*!<  Pointer to Clocking  (CLKG0_CLK) */
#define pADI_BUSM0                     ((ADI_BUSM_TypeDef     *) ADI_BUSM0_BASE      ) /*!<  Pointer to Bus matrix (BUSM0) */
#define pADI_AGPIO2                    ((ADI_AGPIO_TypeDef    *) ADI_AGPIO2_BASE     ) /*!<  Pointer to  (AGPIO2) */
#define pADI_AFECON                    ((ADI_AFECON_TypeDef   *) ADI_AFECON_BASE     ) /*!<  Pointer to  (AFECON) */
#define pADI_AFEWDT                    ((ADI_AFEWDT_TypeDef   *) ADI_AFEWDT_BASE     ) /*!<  Pointer to  (AFEWDT) */
#define pADI_ALLON                     ((ADI_ALLON_TypeDef    *) ADI_ALLON_BASE      ) /*!<  Pointer to Always On Register (ALLON) */
#define pADI_AGPT0                     ((ADI_AGPT0_TypeDef    *) ADI_AGPT0_BASE      ) /*!<  Pointer to General Purpose Timer (AGPT0) */
#define pADI_AGPT1                     ((ADI_AGPT1_TypeDef    *) ADI_AGPT1_BASE      ) /*!<  Pointer to General Purpose Timer (AGPT1) */
#define pADI_AFECRC                    ((ADI_AFECRC_TypeDef   *) ADI_AFECRC_BASE     ) /*!<  Pointer to CRC Accelerator (AFECRC) */
#define pADI_AFE                       ((ADI_AFE_TypeDef      *) ADI_AFE_BASE        ) /*!<  Pointer to  (AFE) */
#define pADI_NVIC0                     ((ADI_NVIC_TypeDef     *) ADI_NVIC0_BASE      ) /*!<  Pointer to Cortex-M3 Interrupt Controller (NVIC0) */

/*!    @} */


/*  =========================================================================
 *! \enum   IRQn_Type
 *! \brief  Interrupt Number Assignments
 *  ========================================================================= */
#ifndef __ADI_NO_DECL_ENUM_IRQn_Type__

typedef enum
{
  RESET_IRQn                     =   -15,    /*!< Cortex-M3 Reset */
  NonMaskableInt_IRQn            =   -14,    /*!< Cortex-M3 Non-maskable Interrupt */
  HardFault_IRQn                 =   -13,    /*!< Cortex-M3 Hardware Fault */
  MemoryManagement_IRQn          =   -12,    /*!< Cortex-M3 Memory Management Interrupt */
  BusFault_IRQn                  =   -11,    /*!< Cortex-M3 Bus Fault */
  UsageFault_IRQn                =   -10,    /*!< Cortex-M3 Usage Fault */
  SVCall_IRQn                    =    -5,    /*!< Cortex-M3 SVCall Interrupt */
  DebugMonitor_IRQn              =    -4,    /*!< Cortex-M3 Debug Monitor */
  PendSV_IRQn                    =    -2,    /*!< Cortex-M3 PendSV Interrupt */
  SysTick_IRQn                   =    -1,    /*!< Cortex-M3 SysTick Interrupt */
  RTC1_EVT_IRQn                  =     0,    /*!< Event */
  XINT_EVT1_IRQn                 =     2,    /*!< External Wakeup Interrupt n */
  AFE_EVT3_IRQn                  =     4,    /*!< AFE Interrupt */
  WDT_EXP_IRQn                   =     5,    /*!< Digital Die Watchdog */
  PMG0_VREG_OVR_IRQn             =     6,    /*!< Voltage Regulator (VREG) Overvoltage */
  PMG0_BATT_RANGE_IRQn           =     7,    /*!< Battery Voltage (VBAT) Out of Range */
  RTC0_EVT_IRQn                  =     8,    /*!< RTC0 Event */
  SYS_GPIO_INTA_IRQn             =     9,    /*!< GPIO Interrupt A */
  SYS_GPIO_INTB_IRQn             =    10,    /*!< GPIO Interrupt B */
  TMR0_EVT_IRQn                  =    11,    /*!< Event */
  TMR1_EVT_IRQn                  =    12,    /*!< Event */
  FLCC_EVT_IRQn                  =    13,    /*!< Event */
  UART_EVT_IRQn                  =    14,    /*!< Event */
  SPI0_EVT_IRQn                  =    15,    /*!< Event */
  SPI1_EVT_IRQn                  =    16,    /*!< SPI1 interrupt */
  I2C_SLV_EVT_IRQn               =    17,    /*!< Slave Event */
  I2C_MST_EVT_IRQn               =    18,    /*!< Master Event */
  DMA_CHAN_ERR_IRQn              =    19,    /*!< DMA Error */
  DMA0_CH0_DONE_IRQn             =    20,    /*!< Channel SPI1_TX Done */
  DMA0_CH1_DONE_IRQn             =    21,    /*!< Channel SPI1_RX Done */
  DMA0_CH2_DONE_IRQn             =    22,    /*!< Channel 2 Done */
  DMA0_CH3_DONE_IRQn             =    23,    /*!< Channel 3 Done */
  DMA0_CH4_DONE_IRQn             =    24,    /*!< Channel SPI0_TX Done */
  DMA0_CH5_DONE_IRQn             =    25,    /*!< Channel SPI0_RX Done */
  DMA0_CH6_DONE_IRQn             =    26,    /*!< Channel 6 Done */
  DMA0_CH7_DONE_IRQn             =    27,    /*!< Channel 7 Done */
  DMA0_CH8_DONE_IRQn             =    28,    /*!< Channel UART_TX Done */
  DMA0_CH9_DONE_IRQn             =    29,    /*!< Channel UART_RX Done */
  DMA0_CH10_DONE_IRQn            =    30,    /*!< Channel I2C0_STX Done */
  DMA0_CH11_DONE_IRQn            =    31,    /*!< Channel I2C0_SRX Done */
  DMA0_CH12_DONE_IRQn            =    32,    /*!< Channel I2C0_MX Done */
  DMA0_CH13_DONE_IRQn            =    33,    /*!< Channel AES_IN_Done */
  DMA0_CH14_DONE_IRQn            =    34,    /*!< Channel AES_OUT_Done */
  DMA0_CH15_DONE_IRQn            =    35,    /*!< Channel FLASH0_Done */
  CRYPT_EVT_IRQn                 =    38,    /*!< Event */
  TMR2_EVT_IRQn                  =    40,    /*!< Event */
  CLKG_PLL_EVT_IRQn              =    43,    /*!< PLL Event */
  RNG0_EVT_IRQn                  =    44,    /*!< RNG0_EVT */
  AFE_ERROR_IRQn                 =    47,    /*!< AFE_ERROR */
  AFE_ADC_IRQn                   =    48,    /*!< AFE_ADC */
  AFE_GEN_IRQn                   =    49,    /*!< AFE_GEN */
  AFE_CMDFIFO_IRQn               =    50,    /*!< AFE_CMDFIFO */
  AFE_DATAFIFO_IRQn              =    51,    /*!< AFE_DATAFIFO */
  AFE_Watchdog_IRQn              =    52,    /*!< AFE_Watchdog */
  AFE_CRC_IRQn                   =    53,    /*!< AFE_CRC */
  AFE_GPT0_IRQn                  =    54,    /*!< AFE_GPT0 */
  AFE_GPT1_IRQn                  =    55,    /*!< AFE_GPT1 */
  DMA0_CH16_DONE_IRQn            =    56,    /*!< AFE_DMA_CMDFIFO */
  DMA0_CH17_DONE_IRQn            =    57,    /*!< AFE_DMA_DATAFIFO */
  DMA0_CH18_DONE_IRQn            =    58,    /*!< Channel 18 Done */
  DMA0_CH19_DONE_IRQn            =    59,    /*!< Channel 19 Done */
  DMA0_CH20_DONE_IRQn            =    60,    /*!< Channel 20 Done */
  DMA0_CH21_DONE_IRQn            =    61,    /*!< Channel 21 Done */
  DMA0_CH22_DONE_IRQn            =    62,    /*!< Channel 22 Done */
  DMA0_CH23_DONE_IRQn            =    63,    /*!< Channel 23 Done */
  AGPT0_EVT_IRQn                 =    64,    /*!< AGPT0_EVT */
  AGPT1_EVT_IRQn                 =    65,    /*!< AGPT1_EVT */
} IRQn_Type;  /* typedef name for fixed interrupt numbers */
#endif /* !__ADI_NO_DECL_ENUM_IRQn_Type__ */



#if defined (_MISRA_RULES)
#pragma diag(pop)
#endif /* _MISRA_RULES */


#if defined (__CC_ARM)
#pragma pop
#endif 

#endif
