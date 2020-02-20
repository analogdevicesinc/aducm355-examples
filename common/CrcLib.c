/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#include "CrcLib.h"

/**
   @brief uint32_t CrcCfg(uint32_t swap,uint32_t dir, uint32_t poly, uint32_t enable)
          ======config CRC peripheral
   @param swap :{BITM_CRC_CTL_W16SWP,BITM_CRC_CTL_BYTMIRR,BITM_CRC_CTL_BITMIRR,0}
      - BITM_CRC_CTL_W16SWP, swap 16-bit half-words within a 32-bit word
      - BITM_CRC_CTL_BYTMIRR, swap 8-bit bytes within each 16-bit word
      - BITM_CRC_CTL_BITMIRR, swap bits within each byte
      - 0 or CRC_CTL_NOSWAP, no swap
   @param dir : {BITM_CRC_CTL_LSBFIRST,0}
      - BITM_CRC_CTL_LSBFIRST, LSB first calculation order
      - 0 or CRC_CTL_MSBFIRST, MSB fist calculation order
   @param poly: {}
      - poly used for CRC
   @param enable :{0,1}
      - 0 or DISABLE, disable peripheral
      - 1 or ENABLE, enable peripheral
   @return value of CTL register.
*/
uint32_t CrcCfg(uint32_t swap,uint32_t dir,uint32_t poly, uint32_t enable)
{
   pADI_CRC0->CTL = swap|dir|enable;
   pADI_CRC0->POLY = poly;
   return pADI_CRC0->CTL;
}

/**
   @brief uint32_t CrcGen(uint32_t inputData)
          ======generate CRC result based on specified poly and seed
   @param inputData : {}
      - 32 bit CRC input
   @return CRC result.
*/
uint32_t CrcGen(uint32_t inputData)
{
   pADI_CRC0->IPDATA = inputData;
   return pADI_CRC0->RESULT;
}

/**
   @brief uint32_t CrcSetSeed(uint32_t seed);
          ======set seed for CRC0
   @param seed :{}
   @return 1.
*/
uint32_t CrcSetSeed(uint32_t seed)
{
   pADI_CRC0->RESULT = seed;
   return pADI_CRC0->RESULT;
}

/**
   @brief uint32_t Crc0GetSeed(void);
          ======get seed of CRC0
   @return seed of CRC.
   @note CRC result act as seed for next CRC calculation
*/
uint32_t CrcGetSeed(void)
{
   return pADI_CRC0->RESULT;
}

/**
   @brief uint32_t SoftwareCrc(uint32_t inputData,uint32_t poly, uint32_t seed)
          ======software implementation of the CRC computaion
   @param inputData : {}
      - 32 bit CRC input
   @param poly : {}
      - polynomial of the CRC computation
   @return CRC result.
   @note MSB first
*/
uint32_t SoftwareCrc(uint32_t inputData,uint32_t poly,uint32_t seed)
{
   uint8_t i;
   uint32_t crc=seed;
   uint32_t data = inputData;

   for (i = 0; i < 32; i++)
   {
      if ((data & 0x80000000) ^ (crc & 0x80000000))
      {
         crc = crc << 1;
         crc = crc ^ poly;
      }
      else
      {
         crc = crc << 1;
      }
      data = data << 1;
   }
   return crc;
}









