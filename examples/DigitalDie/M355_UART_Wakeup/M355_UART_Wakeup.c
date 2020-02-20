/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

/*

Description:
- UART0
- UART baudrate: 57600
- Send 0x01 or '1' to wake up MCU from hibernate.
- Send 0x02 or '2' to enter hibernate mode.


**/

#include <ADuCM355.h>
#include "ad5940.h"
#include "ClkLib.h"
#include "IntLib.h"
#include "UrtLib.h"
#include "DioLib.h"
#include "PwrLib.h"
#include "AfeWdtLib.h"
#include "stdio.h"
#include "string.h"

/*flag indicates MCU is wake up*/
#define MCU_STATUS_ACTIVE   0
#define MCU_STATUS_SLEPT   1
#define MCU_STATUS_WAKEUP   2
#define MCU_SLEEP_UART   3
#define MCU_WAKEUP_UART   4  //wake up source is UART
volatile uint8_t wakeup = MCU_STATUS_ACTIVE;

#define  UART_INBUFFER_LEN 64
volatile uint8_t szInSring[UART_INBUFFER_LEN];
volatile uint8_t  ucInCnt;
volatile uint32_t ucCOMIID0;
volatile uint32_t iNumBytesInFifo;

void ClockInit(void);
void UartInit(void);

int main(void)
{
  ClockInit();
  UartInit();
  
  printf("send '1' to wake up MCU\r\n");
  printf("send '2' to sleep\r\n");
  while(1)
  {
    if(wakeup==MCU_WAKEUP_UART)    //wake up
    {
      wakeup = MCU_STATUS_ACTIVE;
      AfePwrCfg(AFE_ACTIVE);  //set AFE power mode to active
      
      printf("MCU is in active mode\r\n");
    }
    else if(wakeup==MCU_SLEEP_UART)   //enter sleep mode
    {
      wakeup = MCU_STATUS_SLEPT;
      printf("MCU Entering hibernate mode\r\n");
      /*Enable UART_RX wakeup interrupt before entering hiberante mode*/
      EiCfg(EXTUARTRX,INT_EN,INT_FALL);
      /*AFE die enter hibernate mode*/
      AfePwrCfg(AFE_HIBERNATE);
      /*Digital die Enter hibernater mode, no battery monitor, 24K SRAM*/
      PwrCfg(ENUM_PMG_PWRMOD_HIBERNATE,BITM_PMG_PWRMOD_MONVBATN,BITM_PMG_SRAMRET_BNK2EN);
      /*Following instruction should not be executed before user sent 1 to wakeup MCU*/
      printf("MCU wake up\r\n");
    }
    /* Check if interrupt occurred */
    if(AD5940_GetMCUIntFlag())
    {
        AD5940_ClrMCUIntFlag();
        /*Enable UART interrupt since it's not retained in hibernate mode*/
        pADI_UART0->COMIEN |= (BITM_UART_COMIEN_ERBFI | BITM_UART_COMIEN_ELSI);
        /*clear UARTRX intterrupt status*/
        pADI_XINT0->CLR = BITM_XINT_CLR_UART_RX_CLR;
        /*Disable UART_RX wakeup interrupt while MCU is active*/
        pADI_XINT0->CFG0 &= (~EXTUARTRX);
        /*update MCU status*/
        wakeup = MCU_STATUS_WAKEUP;
    }
  }
}

void ClockInit(void)
{
  DigClkSel(DIGCLK_SOURCE_HFOSC);
  ClkDivCfg(1,1);
}

/**
@brief void UartInit(void)
======== UART initialization for UART wake up and communication
@return none.
*/
void UartInit(void)
{
  DioCfgPin(pADI_GPIO0,PIN10,1);               // Setup P0.10 as UART pin
  DioCfgPin(pADI_GPIO0,PIN11,1);               // Setup P0.11 as UART pin
  pADI_UART0->COMLCR2 = 0x3;                  // Set PCLk oversampling rate 32. (PCLK to UART baudrate generator is /32)
  UrtCfg(pADI_UART0,B57600,
         (BITM_UART_COMLCR_WLS|3),0);         // Configure UART for 57600 baud rate
  UrtFifoCfg(pADI_UART0, RX_FIFO_1BYTE,      // Configure the UART FIFOs for 1 bytes deep
             BITM_UART_COMFCR_FIFOEN);
  UrtFifoClr(pADI_UART0, BITM_UART_COMFCR_RFCLR// Clear the Rx/TX FIFOs
             |BITM_UART_COMFCR_TFCLR);
  //pADI_UART0->COMFCR |=0x2; // test to clear the RX FIFO
  /* Enable Rx and Rx buffer full Interrupts*/
  UrtIntCfg(pADI_UART0,BITM_UART_COMIEN_ERBFI|BITM_UART_COMIEN_ELSI);
  NVIC_EnableIRQ(UART_EVT_IRQn);              // Enable UART interrupt source in NVIC
  
  /*Enable UART wakeup intterupt*/
  NVIC_EnableIRQ(AFE_EVT3_IRQn);    //UART_RX connected to EXT Int3
}

void UART_Int_Handler(void)
{
  uint8_t  ucComRx;
  UrtLinSta(pADI_UART0);
  ucCOMIID0 = UrtIntSta(pADI_UART0);
  if ((ucCOMIID0 & 0xE) == 0x4)	          // Receive byte
  {
    iNumBytesInFifo = pADI_UART0->COMRFC;    // read the Num of bytes in FIFO
    for (uint8_t i=0; i<iNumBytesInFifo;i++)
    {
      ucComRx = UrtRx(pADI_UART0);
      if((ucComRx==0x32)|(ucComRx==0x02))    //sleep
      {
        wakeup = MCU_SLEEP_UART;
      }
      else if((ucComRx==0x31)|(ucComRx==0x01))   //wake up
      {
        if(wakeup == MCU_STATUS_WAKEUP)
          wakeup = MCU_WAKEUP_UART;
      }
      szInSring[ucInCnt++]= ucComRx;
      if(ucInCnt>=UART_INBUFFER_LEN)
        ucInCnt = 0;
    }
  }
  if ((ucCOMIID0 & 0xE) == 0xC)	          // UART Time-out condition
  {
    iNumBytesInFifo = pADI_UART0->COMRFC;    // read the Num of bytes in FIFO
    for (uint8_t i=0; i<iNumBytesInFifo;i++)
    {
      ucComRx = UrtRx(pADI_UART0);
      if(ucInCnt>=UART_INBUFFER_LEN)
      {
        ucInCnt = 0;
      }
      szInSring[ucInCnt++]= ucComRx;
    }
  }
}



