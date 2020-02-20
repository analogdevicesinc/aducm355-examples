/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#include "RtcLib.h"

/**
   @brief uint8_t RtcWaitPendSR1(uint16_t mask)
         ========== check and wait pending status of writting SR1
   @param mask: {BITM_RTC_SR1_WPNDTRM|BITM_RTC_SR1_WPNDALM1|BITM_RTC_SR1_WPNDALM0|
                  BITM_RTC_SR1_WPNDCNT1|BITM_RTC_SR1_WPNDCNT0|BITM_RTC_SR1_WPNDSR0|
                  BITM_RTC_SR1_WPNDCR0}
      - BITM_RTC_SR1_WPNDTRM, pending status of posted writes to RTC Trim register
      - BITM_RTC_SR1_WPNDALM1, pending of posted writes to RTC ALARM 1
      - BITM_RTC_SR1_WPNDALM0, pending of posted writes to RTC ALARM 0
      - BITM_RTC_SR1_WPNDCNT1, pending of posted writes to RTC count 1
      - BITM_RTC_SR1_WPNDCNT0, pending of posted writes to RTC count 0
      - BITM_RTC_SR1_WPNDSR0, pending of posted clearances of interrupt sources in SR0
      - BITM_RTC_SR1_WPNDCR0, pending of posted register writes to RTC CR0
   @return 1.
   @note: posted write MMR: CR0,CNT0,CNT1,ALM0,ALM1,ALM2,TRM,CR1.
**/
uint8_t RtcWaitPendSR1(uint16_t mask)
{
    while((pADI_RTC1->SR1)&mask); /* 1 indicates no room for more post writting */
    return 1;
}

/**
   @brief uint8_t RtcWaitSyncSR0(uint16_t mask);
         ========== check and wait Synchronization status of writting SR0
    @param mask: {BITM_RTC_SR0_WSYNCTRM,BITM_RTC_SR0_WSYNCALM1,BITM_RTC_SR0_WSYNCALM0
                  BITM_RTC_SR0_WSYNCCNT1,BITM_RTC_SR0_WSYNCCNT0,BITM_RTC_SR0_WSYNCSR0,
                  BITM_RTC_SR0_WSYNCCR0}
      - BITM_RTC_SR0_WSYNCTRM, Synchronization of posted writes to RTC Trim Register
      - BITM_RTC_SR0_WSYNCALM1, Synchronization of posted writes to RTC Alarm 1 register
      - BITM_RTC_SR0_WSYNCALM0, Synchronization of posted writes to RTC Alarm 0 register
      - BITM_RTC_SR0_WSYNCCNT1, Synchronization of posted writes to RTC Count 1 register
      - BITM_RTC_SR0_WSYNCCNT0, Synchronization of posted writes to RTC Count 0 register
      - BITM_RTC_SR0_WSYNCSR0, Synchronization of posted clearances to interrupt sources in SR0
      - BITM_RTC_SR0_WSYNCCR0, synchronization of posted writes to CR0
   @return 1.
**/
uint8_t RtcWaitSyncSR0(uint16_t mask)
{
    while( ! ((pADI_RTC1->SR0)&mask)); /* 1 indicates results of a posted write are visible to CPU */
    return 1;
}

/**
   @brief uint8_t RtcCfgCR0(uint16_t uEnMask,uint8_t enable)
      ========== Configure CR0 register which contains most enable/disable bits
   @param uEnMask:{BITM_RTC_CR0_WPNDINTEN|BITM_RTC_CR0_WSYNCINTEN|BITM_RTC_CR0_WPNDERRINTEN
      |BITM_RTC_CR0_ISOINTEN|BITM_RTC_CR0_MOD60ALMINTEN|BITM_RTC_CR0_ALMINTEN
      |BITM_RTC_CR0_MOD60ALMEN|BITM_RTC_CR0_TRMEN|BITM_RTC_CR0_ALMEN|BITM_RTC_CR0_CNTEN}
      - BITM_RTC_CR0_WPNDINTEN, Enable WPENDINT-sourced interrupts to the CPU
      - BITM_RTC_CR0_WSYNCINTEN, Enable WSYNCINT-sourced interrupts to the CPU
      - BITM_RTC_CR0_WPNDERRINTEN, WPENDERRINT-sourced interrupts
      - BITM_RTC_CR0_ISOINTEN, ISOINT-sourced interrupts, only exist in RTC 1.
      - BITM_RTC_CR0_MOD60ALMINTEN, periodic MOD60ALMINT-sourced interrupts, only exist in RTC 1.
      - BITM_RTC_CR0_ALMINTEN, ALMINT-sourced alarm interrupts.
      - BITM_RTC_CR0_MOD60ALMEN, Enable RTC modulo-60 counting of time past a modulo-60 boundary
      - BITM_RTC_CR0_TRMEN, Enable RTC digital trimming
      - BITM_RTC_CR0_ALMEN, Enable the RTC alarm operation
      - BITM_RTC_CR0_CNTEN, Globle enable for the RTC
   @param enable: {0,1}
      -1, enable interrupt
      -0, disable interrupt
   @return 1
**/
uint8_t RtcCfgCR0(uint16_t uEnMask,uint8_t enable)
{
#ifndef RTC_WAIT_SYNC_ONLY
   /*wait untill there is room in RTC to accept new posted write*/
   RtcWaitPendSR1(BITM_RTC_SR1_WPNDCR0);
#endif
   if(enable>=1)
   {
      pADI_RTC1->CR0 |= uEnMask;
   }
   else
   {
      pADI_RTC1->CR0 &= (~uEnMask);
   }
   /*wait for complete of execution, transaction visible to the processor*/
   RtcWaitSyncSR0(BITM_RTC_SR0_WSYNCCR0);
   return 1;
}

/**
   @brief uint8_t RtcSetMod60Alarm(uint8_t Units)
      ========== Periodic, modulo-60 alarm time in prescaled RTC time units beyond
                 a modulo-60 boundary
   @param Units:{0-59}
   @return 1

**/
uint8_t RtcSetMod60Alarm(uint8_t Units)
{
   uint16_t reg_temp;
   reg_temp = pADI_RTC1->CR0;
   reg_temp = (reg_temp&(~BITM_RTC_CR0_MOD60ALM));
   reg_temp |= (((uint16_t)Units)<<BITP_RTC_CR0_MOD60ALM);
#ifndef RTC_WAIT_SYNC_ONLY
   RtcWaitPendSR1(BITM_RTC_SR1_WPNDCR0);
#endif
   pADI_RTC1->CR0 = reg_temp;
   RtcWaitSyncSR0(BITM_RTC_SR0_WSYNCCR0);
   return 1;
}

/**
   @brief uint8_t RtcIntClrSR0(uint16_t uIntMask)
      ========== clear interrupt status of SR0
   @param uIntMask:{BITM_RTC_SR0_WPNDINT|BITM_RTC_SR0_WSYNCINT|BITM_RTC_SR0_WPNDERRINT
                     |BITM_RTC_SR0_ISOINT|BITM_RTC_SR0_MOD60ALMINT|BITM_RTC_SR0_ALMINT}
      - BITM_RTC_SR0_WPNDINT, write pending interrupt
      - BITM_RTC_SR0_WSYNCINT, writ syschronization interrupt
      - BITM_RTC_SR0_WPNDERRINT, write pending error interrupt source
      - ITM_RTC_SR0_ISOINT, power-domain isolation interrupt source, only exist in RTC1
      - BITM_RTC_SR0_MOD60ALMINT, modulo-60 RTC alarm interrupt source
      - BITM_RTC_SR0_ALMINT, Alarm interrupt source
   @return 1
**/
uint8_t RtcIntClrSR0(uint16_t uIntMask)
{
#ifndef RTC_WAIT_SYNC_ONLY
   RtcWaitPendSR1(BITM_RTC_SR1_WPNDSR0);
#endif
   pADI_RTC1->SR0 |= uIntMask;
   RtcWaitSyncSR0(BITM_RTC_SR0_WSYNCSR0);
   return 1;
}

/**
   @brief uint8_t RtcSetAlarm(uint32_t uAlm1_0,uint16_t uAlm2)
      ========== Set alarm value [RTC_ALM1,RTC_ALM0].[RTC_ALM2]
   @param uAlm1_0:{0-4294967295}
      - RTC_ALM1<<16+RTC_ALM0
   @param uAlm2: {0-65536}
      - RTC_ALM2
   @return 1
**/
uint8_t RtcSetAlarm(uint32_t uAlm1_0,uint16_t uAlm2)
{
   uint16_t alm0_temp,alm1_temp;
   alm0_temp = (uint16_t)uAlm1_0;
   alm1_temp = (uint16_t)(uAlm1_0>>16);
#ifndef RTC_WAIT_SYNC_ONLY
   RtcWaitPendSR1(BITM_RTC_SR1_WPNDALM1);
#endif
   pADI_RTC1->ALM1 = alm1_temp;
#ifndef RTC_WAIT_SYNC_ONLY
   RtcWaitPendSR1(BITM_RTC_SR1_WPNDALM0);
#endif
   pADI_RTC1->ALM0 = alm0_temp;
#ifndef RTC_WAIT_SYNC_ONLY
   RtcWaitPendSR2(BITM_RTC_SR2_WPNDALM2MIR);
#endif
   pADI_RTC1->ALM2 = uAlm2;
   RtcWaitSyncSR0(BITM_RTC_SR0_WSYNCALM1);
   RtcWaitSyncSR0(BITM_RTC_SR0_WSYNCALM0);
   RtcWaitSyncSR2(BITM_RTC_SR2_WSYNCALM2MIR);
   return 1;
}

/**
   @brief uint8_t RtcSetCnt(uint32_t uCnt1_0)
      ========== Set RTC count
   @param uCnt1_0:{0-4294967295}
      - RTC_CNT1<<16+RTC_CNT0
   @param uCnt2: {0-65536}
      - RTC_CNT2
   @return 1
**/
uint8_t RtcSetCnt(uint32_t uCnt1_0)
{
   uint16_t cnt0_temp,cnt1_temp;
   cnt0_temp = (uint16_t)uCnt1_0;
   cnt1_temp = (uint16_t)(uCnt1_0>>16);
#ifndef RTC_WAIT_SYNC_ONLY
   RtcWaitPendSR1(BITM_RTC_SR1_WPNDCNT1);
#endif
   pADI_RTC1->CNT1 = cnt1_temp;
#ifndef RTC_WAIT_SYNC_ONLY
   RtcWaitPendSR1(BITM_RTC_SR1_WPNDCNT0);
#endif
   pADI_RTC1->CNT0 = cnt0_temp;
   RtcWaitSyncSR0(BITM_RTC_SR0_WSYNCCNT1);
   RtcWaitSyncSR0(BITM_RTC_SR0_WSYNCCNT0);
   return 1;
}

/**
   @brief uint8_t RtcWaitPendSR2(uint16_t mask)
         ========== check and wait pending status of SR2
   @param mask: {BITM_RTC_SR2_WPNDALM2MIR|BITM_RTC_SR2_WPNDCR1MIR}
      - BITM_RTC_SR2_WPNDALM2MIR, pending status of posted writes to RTC Alarm2 register
      - BITM_RTC_SR2_WPNDCR1MIR, pending of posted writes fo RTC CR1
   @return 1.
   @note: posted write MMR: CR0,CNT0,CNT1,ALM0,ALM1,ALM2,TRM,CR1.
**/
uint8_t RtcWaitPendSR2(uint16_t mask)
{
   if(mask==BITM_RTC_SR2_WPNDALM2MIR)
   {
      while((pADI_RTC1->SR2)&mask); /* 0 indicates RTC can accept new posted write */
   }
   else if(mask==BITM_RTC_SR2_WPNDCR1MIR)
   {
      while((pADI_RTC1->SR2)&mask); /* 0 indicates RTC can accept new posted write */
   }
   return 1;
}

/**
   @brief uint8_t RtcWaitSyncSR2(uint16_t mask);
         ========== check and wait Synchronization status of writting SR2
   @param mask: {BITM_RTC_SR2_WSYNCALM2MIR|BITM_RTC_SR2_WSYNCCR1MIR}
      - BITM_RTC_SR2_WSYNCALM2MIR, Synchronization status of posted writes to RTC Alarm2 Register
      - BITM_RTC_SR2_WSYNCCR1MIR, Synchronization of posted writes to CR1 register
   @return 1.
**/
uint8_t RtcWaitSyncSR2(uint16_t mask)
{
   if(mask==BITM_RTC_SR2_WSYNCALM2MIR)
   {
      while(!((pADI_RTC1->SR2)&mask)); /* 1 indicates results of a posted write are visible to CPU */
   }
   else if(mask==BITM_RTC_SR2_WSYNCCR1MIR)
   {
      while(!(pADI_RTC1->SR2)&mask);/* 1 indicates results of a posted write are visible to CPU */
   }
   return 1;
}

/**
   @brief uint8_t RtcSetPre(RTC1_PRE_t Pre)
      ========== Prescale power of 2 division factor for the RTC base clock
   @param Pre: {0-15}
      - 0 or RTC1_PRESCALE_1 for prescale clock by 1
      - 1 or RTC1_PRESCALE_2 for prescale clock by 2
      - 2 or RTC1_PRESCALE_4 for prescale clock by 4
      - 3 or RTC1_PRESCALE_8 for prescale clock by 8
      - 4 or RTC1_PRESCALE_16 for prescale clock by 16
      - 5 or RTC1_PRESCALE_32 for prescale clock by 32
      - 6 or RTC1_PRESCALE_64 for prescale clock by 64
      - 7 or RTC1_PRESCALE_128 for prescale clock by 128
      - 8 or RTC1_PRESCALE_256 for prescale clock by 256
      - 9 or RTC1_PRESCALE_512 for prescale clock by 512
      - 10 or RTC1_PRESCALE_1024 for prescale clock by 1024
      - 11 or RTC1_PRESCALE_2048 for prescale clock by 2048
      - 12 or RTC1_PRESCALE_4096 for prescale clock by 4096
      - 12 or RTC1_PRESCALE_8192 for prescale clock by 8192
      - 13 or RTC1_PRESCALE_16384 for prescale clock by 16384
      - 14 or RTC1_PRESCALE_32768 for prescale clock by 32768
   @return 1
**/
uint8_t RtcSetPre(RTC1_PRE_t Pre)
{
   uint16_t reg_temp;
   reg_temp = pADI_RTC1->CR1;
   //clear bit8:5 then set pre
   reg_temp = (reg_temp&0xFE1F);                   // Clear Bits [8:5] of CR1 register
   reg_temp|=  (((uint16_t)Pre)<<BITP_RTC_CR1_PRESCALE2EXP);
#ifndef RTC_WAIT_SYNC_ONLY
   RtcWaitPendSR2(BITM_RTC_SR2_WPNDCR1MIR);
#endif
   pADI_RTC1->CR1 = reg_temp;
   RtcWaitSyncSR2(BITM_RTC_SR2_WSYNCCR1MIR);

   return 1;
}

/**
   @brief uint8_t RtcCfgCR1(uint16_t uEnMask,uint8_t enable)
      ========== enable/disable interrupts and functions of RTC1
   @param uEnMask:{BITM_RTC_CR1_CNTMOD60ROLLINTEN|BITM_RTC_CR1_CNTROLLINTEN|
                  BITM_RTC_CR1_RTCTRMINTEN|BITM_RTC_CR1_PSINTEN|BITM_RTC_CR1_CNTINTEN}
      - BITM_RTC_CR1_CNTMOD60ROLLINTEN, Enable for the RTC modulo-60 count roll-over interrupt
      - BITM_RTC_CR1_CNTROLLINTEN, enable for RTC count roll-over interrupt source
      - BITM_RTC_CR1_RTCTRMINTEN, enable for the RTC Trim interrupt source
      - BITM_RTC_CR1_PSINTEN, enable for the prescaled, modulo-1 interrupt source
      - BITM_RTC_CR1_CNTINTEN, enable for the RTC count interrupt source
   @param enable: {0,1}
      -1, enable interrupt
      -0, disable interrupt
   @return 1
**/
uint8_t RtcCfgCR1(uint16_t uEnMask,uint8_t enable)
{
#ifndef RTC_WAIT_SYNC_ONLY
   RtcWaitPendSR2(BITM_RTC_SR2_WPNDCR1MIR);
#endif
   if(enable>=1)
   {
      pADI_RTC1->CR1 |= uEnMask;
   }
   else
   {
      pADI_RTC1->CR1 &= (~uEnMask);
   }
   RtcWaitSyncSR2(BITM_RTC_SR2_WSYNCCR1MIR);
   return 1;
}

/**
   @brief uint8_t RtcIntClrSR2(uint16_t uIntMask)
      ========== clear interrupt status of SR2
   @param uIntMask:{BITM_RTC_SR2_CNTMOD60ROLLINT|BITM_RTC_SR2_CNTROLLINT|BITM_RTC_SR2_TRMINT
                     |BITM_RTC_SR2_PSINT|BITM_RTC_SR2_CNTINT}
      - BITM_RTC_SR2_CNTMOD60ROLLINT, RTC modulo-60 count roll-over interrupt source
      - BITM_RTC_SR2_CNTROLLINT, RTC count roll-over interrupt source
      - BITM_RTC_SR2_TRMINT, RTC Trim interrupt source
      - BITM_RTC_SR2_PSINT, RTC prescaled, modulo-1 boundary interrupt source
      - BITM_RTC_SR2_CNTINT, RTC count interrupt source
   @return 1
**/
uint8_t RtcIntClrSR2(uint16_t uIntMask)
{
   pADI_RTC1->SR2 |= uIntMask;
   return 1;
}

/**
   @brief uint8_t RtcGetSnap(uint32_t *uCnt1_0, uint16_t *uCnt2);
      ====== get snapshot of RTC count: CNT1,CNT0,CNT2
   @param *uCnt1_0:
      - pointer to variable that will store SNAP1<<16+ SNAP0
   @param *uCnt2:
      - pointer to variable that will store SNAP2
   @return 1
**/
uint8_t RtcGetSnap(uint32_t *uCnt1_0, uint16_t *uCnt2)
{
   uint32_t snap1,snap2,snap0;
   pADI_RTC1->GWY = RTC_SNAPSHORT_SW_KEY;
   snap1 = pADI_RTC1->SNAP1;
   snap0 = pADI_RTC1->SNAP0;
   snap2 = pADI_RTC1->SNAP2;
   *uCnt1_0 = (snap1<<16) + snap0;
   *uCnt2 = (uint16_t)snap2;
   return 1;
}

/**
   @brief uint8_t RtcFlushWrite()
      ====== Flush all posted write transaction and immediately stop any transaction
            that is currently executing
   @return 1
**/
uint8_t RtcFlushWrite()
{
   pADI_RTC1->GWY = RTC_FLUSH_SW_KEY;
   return 1;
}

/**
   @brief uint16_t RtcReadModulo()
      ====== return MOD register of RTC
   @return
**/
uint16_t RtcReadModulo()
{
   return pADI_RTC1->MOD;
}

/**
   @brief uint8_t RtcSetTrim(uint8_t Interval2Exp,uint8_t AddInterval,uint8_t polarity,uint8_t TrimVal)
      ====== Set trim interval and trim value for RTC
   @param Interval2Exp: {2-14}
      - Interval2Exp, Power-of-two interval of prescaled RTC time units
   @param AddInterval: {0-3}
      - AddInterval, additional value added to adjust trim interval
        total Interval = 1<<Interval2Exp + AddInterval
   @param polarity: {0,1}
      - 0, Add Trim value when trim interval reach
      - 1, subtract trim value when trim interval reach
   @param TrimVal: {0-7}
      - TrimiVal, trim value used to be add/subtract to RTC count at trim interval boundary
   @return 1
**/
uint8_t RtcSetTrim(uint8_t Interval2Exp,uint8_t AddInterval,uint8_t polarity,uint8_t TrimVal)
{
   uint16_t reg;
   reg = ((uint16_t)Interval2Exp<<BITP_RTC_TRM_IVL2EXPMIN)|
            ((uint16_t)AddInterval<<BITP_RTC_TRM_IVL)|
               ((uint16_t)polarity<<BITP_RTC_TRM_ADD)|
                  (TrimVal);
   pADI_RTC1->TRM = reg;
   return 1;
}
