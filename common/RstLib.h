/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#ifndef RSTLIB_H
#define RSTLIB_H

#ifdef __cplusplus
extern "C" {
#endif 

#include "ADuCM355.h"
#include "DioLib.h"

#define ALLON_RSTCON_KEY (0x12EA)
#define AFEDIESTA   (*((uint32_t *)(0x40007008)))

#define BITM_ALLON_RSTCON_BYPMMRRST	(0x01)
#define BITM_ALLON_RSTCON_BYPWDTRST	(0x02)
#define BITM_ALLON_RSTCON_BYPPINRST	(0x04)
#define ALLCON_RSTSTA_CLEAR_ALL		(0xFF)


extern int ReadRstSta(void);
extern int ClearRstSta(int iStaClr );
extern uint8_t AfeRstSta(void);
extern uint32_t AfeDieSta(void);


//Reset status.
#define RST_NONE	0	


#ifdef __cplusplus
}
#endif 

#endif // #define RSTLIB_H
