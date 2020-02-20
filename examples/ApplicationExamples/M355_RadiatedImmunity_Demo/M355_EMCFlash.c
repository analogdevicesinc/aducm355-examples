/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#include "M355_EMCFlash.h"
#include <stdio.h>
#include <string.h>
#include "DioLib.h"
#include "M355_EMCFlash.h"

extern uint8_t ucUseArray1;
extern uint16_t szSamplesinSRAM1[128];
extern uint16_t szSamplesinSRAM0[128];
extern int16_t ucPage;
extern unsigned char ucTxBufferEmpty;	           // Used to indicate that the UART Tx buffer is empty
extern unsigned char szTemp[64];		             // Used to build string before printing to UART
uint32_t uiReadAddr;
void InitFlash(void)
{
  // if (FLASH_LOG_CHECK !=0xFFFFFFFF)
  FeePErs(0x10000);
  FeePErs(0x10800);
  FeePErs(0x11000);
  FeePErs(0x11800);
  FeePErs(0x12000);
  FeePErs(0x12800);
  FeePErs(0x13000);
  FeePErs(0x13800);
  FeePErs(0x14000);
  FeePErs(0x14800);
  FeePErs(0x15000);
  FeePErs(0x15800);
  FeePErs(0x16000);
  FeePErs(0x16800);
  FeePErs(0x17000);
  FeePErs(0x17800);
  FeePErs(0x18000);
  FeePErs(0x18800);
  FeePErs(0x19000);
  FeePErs(0x19800);
  FeePErs(0x1A000);
  FeePErs(0x1A800);
  FeePErs(0x1B000);
  FeePErs(0x1B800);
  FeePErs(0x1C000);
  FeePErs(0x1C800);
  FeePErs(0x1D000);
  FeePErs(0x1D800);
  FeePErs(0x1E000);
  FeePErs(0x1E800);
}

void BackUpToFlash(void)
{
  uint64_t i1 = 0;
  uint32_t uiAddress = 0;
  uint16_t x =0;
  uint16_t uiSramArrayIndex =0;
  uint16_t *pSramArray;
  
  uiAddress = BACKUP_FLASH_BASE + (ucPage*128); // Set offset to 0 in header file if running from SRAM
  if (uiAddress >= BACKUP_FLASH_BASE + 0xF000)
  {
    while (1)    // Loop forever doing nothing - flash is full
    {}
  }
  uiSramArrayIndex = 0;
  for (x=0;x<128;x=x+8)
  {
    if ((ucUseArray1 %2) == 1)
    {
      i1 = 0;
      pSramArray = &szSamplesinSRAM0[x];
      i1 = *(pSramArray+3);
      i1 = (i1<<16);
      i1 |= *(pSramArray+2);
      i1 = (i1<<16);
      i1 |= *(pSramArray+1);
      i1 = (i1<<16);
      i1 |= *(pSramArray);
    }
    else
    {
      i1 = 0;
      pSramArray = &szSamplesinSRAM1[x];
      i1 = *(pSramArray+3);
      i1 = (i1<<16);
      i1 |= *(pSramArray+2);
      i1 = (i1<<16);
      i1 |= *(pSramArray+1);
      i1 = (i1<<16);
      i1 |= *(pSramArray);
    }
    uiSramArrayIndex = uiSramArrayIndex +4;
    FeeWr((uiAddress+x),i1);
    while(FeeSta()&1);
  }
  ucPage++;
}
void StartDebugText(void)
{
  uint16_t uiConfigPin = 0;
  
  DioPulPin(pADI_GPIO1,PIN3,1);               // Enable P1.3 pull-up resistor
  AD5940_Delay10us(10); 
  DioIenPin(pADI_GPIO1,PIN3,1);               // Configure P1.3 as an Input
  
  uiConfigPin = (pADI_GPIO1->IN);
  uiConfigPin &= 0x8;
  uiConfigPin = (uiConfigPin >>3);
  printf ("Reset Occurred.... :%u \r\n",uiConfigPin );
  if (uiConfigPin == 1)
  {
    printf ("Config Pin is high - start logging to Flash soon \r\n" );
  }
  else
  {
    printf ("Config Pin is Low - Read Flash Contents \r\n" );
    FlashToUART();
  }
}
void FlashToUART(void)
{
  uint16_t iFlashVal = 0;
  int16_t x = 0;
  
  uiReadAddr = BACKUP_FLASH_BASE;
  iFlashVal = FLASH_LOG_CHECK;
  if ((iFlashVal & 0xFFFF) == 0xFFFF)
    SendEndOfLog();
  for (x=0;x<16000;x++)
  {
    printf ("%u \r\n",iFlashVal&0xFFFF );
    uiReadAddr = BACKUP_FLASH_BASE+(2*x);
    iFlashVal = (FLASH_LOG_CHECK);
    if ((iFlashVal & 0xFFFF) == 0xFFFF)
      SendEndOfLog();
  }
}
void SendEndOfLog(void)
{
  printf ("End of Log - Erase location Detected \r\n" );
  while (1)
  {}
}
