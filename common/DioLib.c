/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#include "DioLib.h"

/**
   @brief uint32_t DioCfgPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Mode)
         ========== Configures the mode of 1 GPIO of the specified port.
   @param pPort :{pADI_GPIO0,pADI_GPIO1,pADI_GPIO2}
      - pADI_GPIO0 for GP0.
      - pADI_GPIO1 for GP1.
      - pADI_GPIO2 for GP2.
   @param PinMsk :{PIN0|PIN1|PIN2|PIN3|PIN4|PIN5|PIN6|PIN7|
              PIN8|PIN9|PIN10|PIN11|PIN12|PIN13|PIN14|PIN15}
      - PIN0 to configure Px.0.
      - PIN1 to configure Px.1.
      - PIN2 to configure Px.2.
      - PIN3 to configure Px.3.
      - PIN4 to configure Px.4.
      - PIN5 to configure Px.5.
      - PIN6 to configure Px.6.
      - PIN7 to configure Px.7
      - PIN8 to configure Px.8.
      - PIN9 to configure Px.9.
      - PIN10 to configure Px.10.
      - PIN11 to configure Px.11.
      - PIN12 to configure Px.12.
      - PIN13 to configure Px.13.
      - PIN14 to configure Px.14.
      - PIN15 to configure Px.15.
        use combination of above pins
   @param Mode :{0, 1, 2, 3}
      - Set the mode accoring to the multiplex options required.
   @return 1.
**/
uint32_t DioCfgPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Mode)
{
   uint32_t reg;
   uint32_t bitPos = 0;
   uint32_t checkMsk = 1;
   reg = pPort->CFG;
   for(bitPos=0; bitPos<16; bitPos++)
   {
      if(PinMsk&checkMsk)
      {
         reg &= ~(3u<<(bitPos<<1));  //two bits of CFG register for each pin
         reg |= (Mode<<(bitPos<<1));
      }
      checkMsk = checkMsk<<1;
   }
   pPort->CFG = reg;
   return 1;
}

/**
   @brief uint32_t DioOenPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Oen)
         ========== Enables the output drive of 1 GPIO of the specified port.
   @param pPort :{pADI_GPIO0,pADI_GPIO1,pADI_GPIO2,}
      - pADI_GPIO0 for GP0.
      - pADI_GPIO1 for GP1.
      - pADI_GPIO2 for GP2.
   @param PinMsk :{PIN0|PIN1|PIN2|PIN3|PIN4|PIN5|PIN6|PIN7|
              PIN8|PIN9|PIN10|PIN11|PIN12|PIN13|PIN14|PIN15}
   @param Oen :{0, 1}
      - 0 to disable the output drive
      - 1 to enable the output drive
   @return 1.
**/

uint32_t DioOenPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Oen)
{
   unsigned short reg = pPort->OEN;
   reg &= ~PinMsk;
   if(Oen)
      reg |= PinMsk;
   pPort->OEN = reg;
   return 1;
}

/**
   @brief uint32_t DioPulPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Pul)
         ========== Configures the pull-up of 1 GPIO of the specified port.
   @param pPort :{pADI_GPIO0,pADI_GPIO1,pADI_GPIO2,}
      - pADI_GPIO0 for GP0.
      - pADI_GPIO1 for GP1.
      - pADI_GPIO2 for GP2.
   @param PinMsk :{PIN0|PIN1|PIN2|PIN3|PIN4|PIN5|PIN6|PIN7|
              PIN8|PIN9|PIN10|PIN11|PIN12|PIN13|PIN14|PIN15}
   @param Pul :{0, 1}
      - 0 or DISABLE to disable the pull-up
      - 1 or ENABLE to enable the pull-up
   @return 1.
**/
uint32_t DioPulPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Pul)
{
   unsigned short reg = pPort->PE;
   reg &= ~PinMsk;
   if(Pul)
      reg |= PinMsk;
   pPort->PE = reg;
   return 1;
}

/**
   @brief uint32_t DioIenPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Ien)
         ========== Enables the input path of 1 GPIO of the specified port.
   @param pPort :{pADI_GPIO0,pADI_GPIO1,pADI_GPIO2}
      - pADI_GPIO0 for GP0.
      - pADI_GPIO1 for GP1.
      - pADI_GPIO2 for GP2.
   @param PinMsk :{PIN0|PIN1|PIN2|PIN3|PIN4|PIN5|PIN6|PIN7|
              PIN8|PIN9|PIN10|PIN11|PIN12|PIN13|PIN14|PIN15}
   @param Ien :{0, 1}
      - 0 or DISABLE to disable the input path
      - 1 or ENABLE to enable the input path
   @return 1.
**/

uint32_t DioIenPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Ien)
{
   unsigned short reg = pPort->IEN;
   reg &= ~PinMsk;
   if(Ien)
      reg |= PinMsk;
   pPort->IEN = reg;
   return 1;
}

/**
   @brief uint32_t DioRd(ADI_GPIO_TypeDef *pPort)
         ========== Reads values of port pins.
   @param pPort :{pADI_GPIO0,pADI_GPIO1,pADI_GPIO2,}
      - pADI_GPIO0 for GP0.
      - pADI_GPIO1 for GP1.
      - pADI_GPIO2 for GP2.
   @return value on port pins.
**/
uint32_t DioRd(ADI_GPIO_TypeDef *pPort)
{
   return (pPort->IN);
}

/**
   @brief uint32_t DioWr(ADI_GPIO_TypeDef *pPort, uint32_t Val)
         ========== Writes values to outputs.
   @param pPort :{pADI_GPIO0,pADI_GPIO1,pADI_GPIO2,}
      - pADI_GPIO0 for GP0.
      - pADI_GPIO1 for GP1.
      - pADI_GPIO2 for GP2.
   @param Val :{0-0xFFFF}
   @return value on port pins.
**/
uint32_t DioWr(ADI_GPIO_TypeDef *pPort, uint32_t Val)
{
   pPort->OUT = Val;
   return (pPort->OUT);
}

/**
   @brief uint32_t DioSetPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk)
         ========== Sets individual outputs.
   @param pPort :{pADI_GPIO0,pADI_GPIO1,pADI_GPIO2}
      - pADI_GPIO0 for GP0.
      - pADI_GPIO1 for GP1.
      - pADI_GPIO2 for GP2.
   @param PinMsk :{PIN0|PIN1|PIN2|PIN3|PIN4|PIN5|PIN6|PIN7|
              PIN8|PIN9|PIN10|PIN11|PIN12|PIN13|PIN14|PIN15}
   @return value on port pins.
**/
uint32_t DioSetPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk)
{
   pPort->SET = PinMsk;
   return 1;
}

/**
   @brief uint32_t DioClrPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk)
         ========== Clears individual outputs.
   @param pPort :{pADI_GPIO0,pADI_GPIO1,pADI_GPIO2}
      - pADI_GPIO0 for GP0.
      - pADI_GPIO1 for GP1.
      - pADI_GPIO2 for GP2.
   @param PinMsk :{PIN0|PIN1|PIN2|PIN3|PIN4|PIN5|PIN6|PIN7|
              PIN8|PIN9|PIN10|PIN11|PIN12|PIN13|PIN14|PIN15}
   @return 1.
**/

uint32_t DioClrPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk)
{
   pPort->CLR = PinMsk;
   return 1;
}

/**
   @brief uint32_t DioTglPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk)
         ========== Toggles individual outputs.
   @param pPort :{pADI_GPIO0,pADI_GPIO1,pADI_GPIO2}
      - pADI_GPIO0 for GP0.
      - pADI_GPIO1 for GP1.
      - pADI_GPIO2 for GP2.
   @param PinMsk :{PIN0|PIN1|PIN2|PIN3|PIN4|PIN5|PIN6|PIN7|
              PIN8|PIN9|PIN10|PIN11|PIN12|PIN13|PIN14|PIN15}
   @return 1.
**/
uint32_t DioTglPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk)
{
   pPort->TGL = PinMsk;
   return 1;
}

/**
   @brief uint32_t DioDsPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Ds)
         ========== Controls the drive strength of 1 GPIO of the specified port.
    @param pPort :{pADI_GPIO0,pADI_GPIO1,pADI_GPIO2}
      - pADI_GPIO0 for GP0.
      - pADI_GPIO1 for GP1.
      - pADI_GPIO2 for GP2.
   @param PinMsk :{PIN0|PIN1|PIN2|PIN3|PIN4|PIN5|PIN6|PIN7|
              PIN8|PIN9|PIN10|PIN11|PIN12|PIN13|PIN14|PIN15}
   @param Ds :{0, 1}
      - 0 or DISABLE to select normal drive strength
      - 1 to ENABLE select full drive strength
   @return  1
**/
uint32_t DioDsPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Ds)
{
   unsigned short reg = pPort->DS;
   reg &= ~PinMsk;
   if(Ds)
      reg |= PinMsk;
   pPort->DS = reg;
   return 1;
}

/**
   @brief uint32_t DioIntPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t IntAorB, uint32_t EnOrDis)
         ========== Enables/Disables GPIO pin interrupt on selected pin  ==========
   @param pPort :{pADI_GPIO0,pADI_GPIO1,pADI_GPIO2}
      - pADI_GPIO0 for GP0.
      - pADI_GPIO1 for GP1.
      - pADI_GPIO2 for GP2.
   @param PinMsk :{PIN0|PIN1|PIN2|PIN3|PIN4|PIN5|PIN6|PIN7|
              PIN8|PIN9|PIN10|PIN11|PIN12|PIN13|PIN14|PIN15}
   @param iIntAorB :{0, 1}
      - INTA = 0 to select interrupt source A
      - INTB = 1 to select interrupt source B
   @param iEnOrDis :{0, 1}
      - 0 or DISABLE to disable the interrupt source
      - 1 or ENABLE to enable the interrupt source
   @return pADI_GPIOx->IENA or pADI_GPIOx->IENB.
**/
uint32_t DioIntPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t IntAorB, uint32_t EnOrDis)
{
   unsigned short reg;

   if (IntAorB == 0)                    //INT A
   {
      reg = pPort->IENA;
      reg &= ~PinMsk;
      if(EnOrDis)
         reg |= PinMsk;
      pPort->IENA = reg;
   }
   else                                  //INT B
   {
      reg= pPort->IENB;
      reg &= ~PinMsk;
      if(EnOrDis)
         reg |= PinMsk;
      pPort->IENB = reg;
   }
   return 1;
}

/**
   @brief uint32_t DioIntPolPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Pol)
         ========== Set polarity of GPIO pin interrupt on selected pin  ==========
   @param pPort :{pADI_GPIO0,pADI_GPIO1,pADI_GPIO2}
      - pADI_GPIO0 for GP0.
      - pADI_GPIO1 for GP1.
      - pADI_GPIO2 for GP2.
   @param PinMsk :{PIN0|PIN1|PIN2|PIN3|PIN4|PIN5|PIN6|PIN7|
              PIN8|PIN9|PIN10|PIN11|PIN12|PIN13|PIN14|PIN15}
   @param Pol :{0, 1}
      - 0 to configure trigger on high-to-low transition
      - 1 to configure trigger on low-to-high transition
   @return pADI_GPIOx->POL
**/
uint32_t DioIntPolPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Pol)
{
   unsigned short reg;

   reg = pPort->POL;
      reg &= ~PinMsk;
      if(Pol)
         reg |= PinMsk;
      pPort->POL = reg;

   return 1;
}

/**
   @brief uint32_t DioIntSta(ADI_GPIO_TypeDef *pPort)
			==========return GPIO interrupt status.
   @param pPort :{pADI_GPIO0,pADI_GPIO1,pADI_GPIO2}
      - pADI_GPIO0 for GP0.
      - pADI_GPIO1 for GP1.
      - pADI_GPIO2 for GP2.
	@return pADI_GPIOx->INT
**/
uint32_t DioIntSta(ADI_GPIO_TypeDef *pPort)
{
   return (pPort->INT);
}

/**
   @brief uint32_t DioIntClrPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk)
			==========return GPIO interrupt status.
   @param pPort :{pADI_GPIO0,pADI_GPIO1,pADI_GPIO2}
      - pADI_GPIO0 for GP0.
      - pADI_GPIO1 for GP1.
      - pADI_GPIO2 for GP2.
   @param PinMsk :{PIN0|PIN1|PIN2|PIN3|PIN4|PIN5|PIN6|PIN7|
              PIN8|PIN9|PIN10|PIN11|PIN12|PIN13|PIN14|PIN15}
	@return 1
**/
uint32_t DioIntClrPin(ADI_GPIO_TypeDef *pPort, uint32_t PinMsk)
{
   pPort->INT = PinMsk;
   return (pPort->INT);
}

/*======================================================================*/
/*                              AFE GPIO                                */
/*                Two pins available:                                    */
/*                                  AGPIO2.0(AGPIO0)                    */
/*                                  AGPIO2.1(AGPIO1)                    */
/*======================================================================*/

/**
   @brief uint32_t AfeDioCfgPin(ADI_GPIO_TypeDef *pPort, uint32_t iPin, uint32_t iMode)
         ========== Configures the mode of 1 of AFE GPIO of the specified port.
   @param pPort :{pADI_AGPIO2}
      - pADI_AGPIO2 for AFE die GP2.
   @param iPin :{PIN0|PIN1}
      - PIN0 to configure Px.0.
      - PIN1 to configure Px.1.
   @param iMode :{0, 1, 2, 3}
      - Set the mode accoring to the multiplex options required.
   @return 1.
**/

uint32_t AfeDioCfgPin(ADI_AGPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Mode)
{
   uint32_t reg;
   uint32_t bitPos = 0;
   uint32_t checkMsk = 1;
   reg = pPort->CON;
   for(bitPos=0; bitPos<16; bitPos++)
   {
      if(PinMsk&checkMsk)
      {
         reg &= ~(3u<<(bitPos<<1));  //two bit of CFG register for each pin
         reg |= (Mode<<(bitPos<<1));
      }
      checkMsk = checkMsk<<1;
   }
   pPort->CON = reg;
   return 1;
}

/**
   @brief uint32_t AfeDioOenPin(ADI_AGPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Oen)
         ========== Enables the output drive of 1 AFE GPIO of the specified port.
   @param pPort :{pADI_AGPIO2}
      - pADI_AGPIO2 for AFE die GP2.
    @param PinMsk :{PIN0|PIN1}
      - PIN0 to configure Px.0.
      - PIN1 to configure Px.1.
   @param Oen :{0, 1}
      - 0 to disable the output drive
      - 1 to enable the output drive
   @return 1.
**/
uint32_t AfeDioOenPin(ADI_AGPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Oen)
{
   unsigned short reg = pPort->OEN;
   reg &= ~PinMsk;
   if(Oen)
      reg |= PinMsk;
   pPort->OEN = reg;
   return 1;
}

/**
   @brief uint32_t AfeDioPulPin(ADI_AGPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Pul)
         ========== Configures the pull-up of 1 GPIO of the specified port.
    @param pPort :{pADI_AGPIO2}
      - pADI_AGPIO2 for AFE die GP2.
    @param PinMsk :{PIN0|PIN1}
      - PIN0 to configure Px.0.
      - PIN1 to configure Px.1.
   @param Pul :{0, 1}
      - 0 or DISABLE to disable the pull-up
      - 1 or ENABLE to enable the pull-up
   @return 1.
**/
uint32_t AfeDioPulPin(ADI_AGPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Pul)
{
   unsigned short reg = pPort->PE;
   reg &= ~PinMsk;
   if(Pul)
      reg |= PinMsk;
   pPort->PE = reg;
   return 1;
}

/**
   @brief uint32_t AfeDioIenPin(ADI_AGPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Ien)
         ========== Enables the input path of 1 AFE GPIO of the specified port.
   @param pPort :{pADI_AGPIO2}
      - pADI_AGPIO2 for AFE die GP2.
    @param PinMsk :{PIN0|PIN1}
      - PIN0 to configure Px.0.
      - PIN1 to configure Px.1.
   @param Ien :{0, 1}
      - 0 or DISABLE to disable the input path
      - 1 or ENABLE to enable the input path
   @return 1.
**/

uint32_t AfeDioIenPin(ADI_AGPIO_TypeDef *pPort, uint32_t PinMsk, uint32_t Ien)
{
   unsigned short reg = pPort->IEN;
   reg &= ~PinMsk;
   if(Ien)
      reg |= PinMsk;
   pPort->IEN = reg;
   return 1;
}

/**
   @brief uint32_t AfeDioRd(ADI_AGPIO_TypeDef *pPort)
         ========== Reads values of port pins.
   @param pPort :{pADI_AGPIO2}
      - pADI_AGPIO2 for AFE die GP2.
   @return value on port pins.
**/
uint32_t AfeDioRd(ADI_AGPIO_TypeDef *pPort)
{
   return (pPort->IN);
}

/**
   @brief uint32_t AfeDioWr(ADI_AGPIO_TypeDef *pPort, uint32_t iVal)
         ========== Writes values to AFE GPIO outputs.
   @param pPort :{pADI_AGPIO2}
      - pADI_AGPIO2 for AFE die GP2.
   @param Val :{0-0xFFFF}
   @return value on port pins.
**/
uint32_t AfeDioWr(ADI_AGPIO_TypeDef *pPort, uint32_t Val)
{
   pPort->OUT = Val;
   return (pPort->OUT);
}

/**
   @brief uint32_t AfeDioSetPin(ADI_AGPIO_TypeDef *pPort, uint32_t PinMsk)
         ========== Sets individual AFE outputs.
   @param pPort :{pADI_AGPIO2}
      - pADI_AGPIO2 for AFE die GP2.
   @param PinMsk :{PIN0|PIN1}
      - PIN0 to configure Px.0.
      - PIN1 to configure Px.1.
   @return value on port pins.
**/
uint32_t AfeDioSetPin(ADI_AGPIO_TypeDef *pPort, uint32_t PinMsk)
{
   pPort->SET = PinMsk;
   return 1;
}

/**
   @brief uint32_t AfeDioClrPin(ADI_AGPIO_TypeDef *pPort, uint32_t PinMsk)
         ========== Clears individual AFE GPIO outputs.
   @param pPort :{pADI_AGPIO2}
      - pADI_AGPIO2 for AFE die GP2.
   @param PinMsk :{PIN0|PIN1}
      - PIN0 to configure Px.0.
      - PIN1 to configure Px.1.
   @return value on port pins.
**/

uint32_t AfeDioClrPin(ADI_AGPIO_TypeDef *pPort, uint32_t PinMsk)
{
   pPort->CLR = PinMsk;
   return 1;
}

/**
   @brief uint32_t AfeDioTglPin(ADI_AGPIO_TypeDef *pPort, uint32_t PinMsk)
         ========== Toggles individual AFE outputs.
   @param pPort :{pADI_AGPIO2}
      - pADI_AGPIO2 for AFE die GP2.
   @param PinMsk :{PIN0|PIN1}
      - PIN0 to configure Px.0.
      - PIN1 to configure Px.1.
   @return value on port pins.
**/
uint32_t AfeDioTglPin(ADI_AGPIO_TypeDef *pPort, uint32_t PinMsk)
{
   pPort->TGL = PinMsk;
   return 1;
}



/**@}*/
