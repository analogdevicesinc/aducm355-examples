/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#include "FeeLib.h"

/**
   @brief uint8_t FeeMErs(void);
   ========== erase all of flash user space if the flash controller is not busy.

   @return 1 if the command was issued, 0 if the the flash controller was busy.
**/
uint8_t FeeMErs(void)
{
   if((pADI_FLCC0->STAT&BITM_FLCC_STAT_CMDBUSY)!=0)
   {
      return 0;
   }
   pADI_FLCC0->KEY = ENUM_FLCC_KEY_USERKEY;
   pADI_FLCC0->CMD = ENUM_FLCC_CMD_MASSERASE;
   return 1;
}

/**
   @brief uint8_t FeePErs(uint32_t lAddr);
      ========== Performs a page erase if the flash controller is not busy.

   @param lAddr :{0-0x3FFFF}
      - Specifies an address in the page to be erased

   @return 1 if the command was issued, 0 if the the flash controller was busy.
**/
uint8_t FeePErs(uint32_t lAddr)
{
   while((pADI_FLCC0->STAT&BITM_FLCC_STAT_CMDBUSY)!=0);

   pADI_FLCC0->KEY = ENUM_FLCC_KEY_USERKEY;
   pADI_FLCC0->PAGE_ADDR0 = lAddr;
	pADI_FLCC0->CMD = ENUM_FLCC_CMD_ERASEPAGE;
   return 1;
}

/**
   @brief uint8_t FeeMultPageErs(uint32_t StartAddr,uint32_t EndAddr);
      ========== Erase multiple pages

   @param StartAddr :{0-0x3FFFF}
      -  address from which page to start erase
   @param EndAddr :{0-0x3FFFF}
      -  address until which page to erase
   @return 1
**/
uint8_t FeeMultPageErs(uint32_t StartAddr,uint32_t EndAddr)
{
   uint32_t addr;
   addr = StartAddr;
   for (addr=StartAddr;addr<EndAddr;)
   {
      FeePErs(addr);
      addr += 2048;
   }
   FeePErs(EndAddr);
   return 1;
}

/**
   @brief uint8_t FeeWr(uint32_t lAddr, uint64_t udData);
      ========== Performs a 64 bit write to specified address if the flash controller is not busy.

   @param lAddr :{0-0x3FFFF}
      - Specifies the address to be written.
   @param udData :{0-0xFFFFFFFFFFFFFFFF}
      - Specifies the 64 bit data to be written.

   @return 1 if the command was issued, 0 if the the flash controller was busy.
**/

uint8_t FeeWr(uint32_t lAddr, uint64_t udData)
{
   if((pADI_FLCC0->STAT&BITM_FLCC_STAT_CMDBUSY)!=0)
   {
      return 0;
   }
   //FeeWriteKey(ENUM_FLCC_KEY_USERKEY); /* No key is required */
   pADI_FLCC0->KH_ADDR = lAddr;
   pADI_FLCC0->KH_DATA0 = (uint32_t)udData;
   pADI_FLCC0->KH_DATA1 = udData>>32;
	pADI_FLCC0->CMD = ENUM_FLCC_CMD_WRITE;
   return 1;
}

/**
   @brief uint32_t FeeSta(void);
      ========== Returns the status of the flash controller.

   @return value of STAT
      See User guide for bit descriptions.
**/
uint32_t FeeSta(void)
{
   return pADI_FLCC0->STAT;
}

/**
   @brief uint8_t FeeSign(uint32_t ulStartAddr, uint32_t ulEndAddr);
   ========== Perform flash signature check.

   @param ulStartAddr :{0-0x3FFFF}
      - An address in the first page to be checked;
   @param ulEndAddr :{0-0x3FFFF}
      - An address in the last page to be checked;

   @return 1 if the command was issued, 0 if the the flash controller was busy.
**/

uint8_t FeeSign(uint32_t ulStartAddr, uint32_t ulEndAddr)
{
   if((pADI_FLCC0->STAT&BITM_FLCC_STAT_CMDBUSY)!=0)
   {
      return 0;
   }

   pADI_FLCC0->PAGE_ADDR0 = ulStartAddr;
   pADI_FLCC0->PAGE_ADDR1 = ulEndAddr;
   pADI_FLCC0->KEY = ENUM_FLCC_KEY_USERKEY;
	pADI_FLCC0->CMD = ENUM_FLCC_CMD_SIGN;
   return 1;
}

/**
   @brief uint32_t FeeSig();
      ========== Return the flash signature calculated by the controller.

   @return FEESIG
**/

uint32_t FeeSig(void)
{
   return	pADI_FLCC0->SIGNATURE;
}

/**
   @brief uint8_t FeeProTmp(uint32_t BlockNum);
      ========== Temporarily enables write and/or read protection on the part.
            Write protection is disabled after a reset

   @param BlockNum :
   Each bit of this 32 bit word represents a 32nd of the total
   available user space. For 256kB parts consisting of 2kB pages (128 pages) each
   bit represents the write protection state of a group of 4 pages.
   @return 1

**/

uint8_t FeeProTmp(uint32_t BlockNum)
{
	pADI_FLCC0->WRPROT = BlockNum;
   return 1;
}

/**
   @brief uint8_t FeeIntCfg(uint8_t iIrq);
      ========== Enables/Disables Flash Interrupt sources.

   @param iIrq :
		- BITM_FLCC_IEN_CMDCMPLT|BITM_FLCC_IEN_WRALCMPLT|BITM_FLCC_IEN_CMDFAIL
		- ENUM_FLCC_IEN_NONE_ERR, ENUM_FLCC_IEN_BUS_ERR_ERR, ENUM_FLCC_IEN_IRQ_ERR
		- ENUM_FLCC_IEN_NONE_COR, ENUM_FLCC_IEN_BUS_ERR_COR, ENUM_FLCC_IEN_IRQ_COR
   @return 1

**/

uint8_t FeeIntCfg(uint8_t iIrq)
{
   pADI_FLCC0->IEN = iIrq;
   return 1;
}

/**
   @brief uint8_t FeeIntAbt(uint64_t IntNum);
         ========== Choose which interrupts can abort flash commands.

   @param IntNum : bit corresponding with the desired system IRQ number.
   @return 1

**/
uint8_t FeeIntAbt(uint64_t IntNum)
{
   pADI_FLCC0->ABORT_EN_LO = (uint32_t)IntNum;
   pADI_FLCC0->ABORT_EN_HI = IntNum>>32;
   return 1;
}

/**
   @brief uint32_t FeeAbtAdr();
         ========== Return the address of the location written when the write was aborted.

   @return pADI_FLCC0->WR_ABORT_ADDR

**/
uint32_t FeeAbtAdr(void)
{
   return pADI_FLCC0->WR_ABORT_ADDR;
}

/**
   @brief uint32_t FeeCrc(int iLen, int *aiData);
      ===== Calculate the CRC of iLen words from the location aiData point to.

   @param iLen : { }
      The number of words to process.
         This should be a multiple of 512 minus 1.
   @param aiData : { }
      The pointer to the first word to be processed.
      This should point to an address that is a multiple of 512.
   @return The 24 bit CRC of the specified block.
   @warning Do not include pages from both flash blocks.
**/
uint32_t FeeCrc(int iLen,int *aiData)
{
   int i1,i2,iCrc;

   iCrc = 0xffffffff;            //Seed value.
   for(i1=0; i1<iLen; i1++)      //Starting at lowest address.
   {
      for(i2=31; i2>=0; i2--)    //MSB first.
      {
         iCrc <<= 1;             //Left shift.
         if((*(aiData+i1))&(1<<i2)) iCrc ^= 0x00800063;  //^= Polynomial.
         if(iCrc&(1<<24))           iCrc ^= 0x00800063;
      }
   }
   return(iCrc&0x00ffffff);      //Return 24 bits.
}

/**@}*/
