/*! *****************************************************************************
 * \brief: Implements user bootloader
 * @version  V0.1
 * @author   Analog Devices
 * @date     August 2018

   Copyright (c) 2018 Analog Devices, Inc.  All Rights Reserved.
   This software is proprietary and confidential to Analog Devices, Inc. and its
   licensors

*****************************************************************************/


/* Ported from bootloader.s */
void    Send_Info          (void);
void    __noreturn StartDownloadPacket(void);
void    Send_Info          (void);

/* Exported from user-bootloader.c */
uint8_t CRC_Check        (void);
uint8_t Blank_Check      (void);