/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#ifndef DIOLIB_H
#define DIOLIB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ADuCM355.h>

#ifndef ENABLE
   #define ENABLE 1
#endif
#ifdef DISABLE
   #define DISABLE 0
#endif

#define PIN0   (1u<<0)
#define PIN1   (1u<<1)
#define PIN2   (1u<<2)
#define PIN3   (1u<<3)
#define PIN4   (1u<<4)
#define PIN5   (1u<<5)
#define PIN6   (1u<<6)
#define PIN7   (1u<<7)
#define PIN8   (1u<<8)
#define PIN9   (1u<<9)
#define PIN10  (1u<<10)
#define PIN11  (1u<<11)
#define PIN12  (1u<<12)
#define PIN13  (1u<<13)
#define PIN14  (1u<<14)
#define PIN15  (1u<<15)

#define INTA 0x0
#define INTB 0x1

// port configuration
extern uint32_t DioCfgPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Mode);
extern uint32_t DioOenPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Oen);
extern uint32_t DioPulPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Pul);
extern uint32_t DioIenPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Ien);
extern uint32_t DioRd(ADI_GPIO_TypeDef *pPort);
extern uint32_t DioWr(ADI_GPIO_TypeDef *pPort, uint32_t Val);
extern uint32_t DioSetPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk);
extern uint32_t DioClrPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk);
extern uint32_t DioTglPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk);
extern uint32_t DioDsPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Ds);
extern uint32_t DioIntPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t IntAorB, uint32_t EnOrDis);
extern uint32_t DioIntPolPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Pol);
extern uint32_t DioIntSta(ADI_GPIO_TypeDef *pPort);
extern uint32_t DioIntClrPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk);

extern uint32_t AfeDioCfgPin(ADI_AGPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Mode);
extern uint32_t AfeDioOenPin(ADI_AGPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Oen);
extern uint32_t AfeDioPulPin(ADI_AGPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Pul);
extern uint32_t AfeDioIenPin(ADI_AGPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Ien);
extern uint32_t AfeDioRd(ADI_AGPIO_TypeDef *pPort);
extern uint32_t AfeDioWr(ADI_AGPIO_TypeDef *pPort, uint32_t Val);
extern uint32_t AfeDioSetPin(ADI_AGPIO_TypeDef *pPort, uint32_t PinMsk);
extern uint32_t AfeDioClrPin(ADI_AGPIO_TypeDef *pPort, uint32_t PinMsk);
extern uint32_t AfeDioTglPin(ADI_AGPIO_TypeDef *pPort, uint32_t PinMsk);

#ifdef __cplusplus
}
#endif

#endif // #define URTLIB_H
