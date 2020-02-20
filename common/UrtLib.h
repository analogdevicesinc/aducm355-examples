/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#ifndef URTLIB_H
#define URTLIB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ADuCM355.h>

#ifndef EOL
#define EOL "\r\n"
#endif

extern int UrtCfg(ADI_UART_TypeDef *pPort, int iBaud, int iBits, int iFormat);
extern int UrtFifoCfg(ADI_UART_TypeDef *pPort, int iFifoSize, int iFIFOEn);
extern int UrtFifoClr(ADI_UART_TypeDef *pPort, int iClrEn);
extern int UrtBrk(ADI_UART_TypeDef *pPort, int iBrk);
extern int UrtLinSta(ADI_UART_TypeDef *pPort);
extern int UrtTx(ADI_UART_TypeDef *pPort, int iTx);
extern int UrtRx(ADI_UART_TypeDef *pPort);
extern int UrtMod(ADI_UART_TypeDef *pPort, int iMcr, int iWr);
extern int UrtModSta(ADI_UART_TypeDef *pPort);
extern int UrtDma(ADI_UART_TypeDef *pPort, int iDmaSel);
extern int UrtIntCfg(ADI_UART_TypeDef *pPort, int iIrq);
extern int UrtIntSta(ADI_UART_TypeDef *pPort);


// baud rate settings
#define B1200	1200
#define B2200	2200
#define B2400	2400
#define B4800	4800
#define B9600	9600
#define B19200	19300
#define B38400	38400
#define B57600	57600
#define B115200	115200
#define B230400	230400
#define B430800	430800

#define RX_FIFO_1BYTE	0
#define RX_FIFO_4BYTE	0x40
#define RX_FIFO_8BYTE	0x80
#define RX_FIFO_14BYTE	0xC0

#ifdef __cplusplus
}
#endif

#endif // #define URTLIB_H
