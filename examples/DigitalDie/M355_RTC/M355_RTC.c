/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/
/*
			Demonstrate using Real Time Clock to wake up the core.
            RTC is driven by Internal Oscillator.
            Use the macro RTC_MOD60ALARM_WAKEUP_EN to choose wake-up
            interrupt source, when this macro is set to '1', RTC modulo-60
            alarm is used, when set to '0', RTC alarm is used.
            The wake-up period is determined by WAKEUP_PERIOD, when
            RTC_MOD60ALARM_WAKEUP_EN is set, the period varies with the
            prescaler setting, only a set of values can be selected; when set
            to '0', the period is defined by WAKEUP_PERIOD in seconds from 0.5mS
            to 1.517 hours.

            After RTC is configured, in the main loop, MCU will send string through
            UART to annouce it will enter sleep mode after MCU enter hibernate mode.
            when RTC interrupt occurs, MCU wake up to send string to show it's active.
            UART: 57600 bps

            The interrupt service routine clears the interrupt sources. When using
            RTC alarm instead of Mod60 alarm, next alarm time also updated.

**/
#include <ADuCM355.h>
#include <stdio.h>
#include "ad5940.h"
#include "DioLib.h"
#include "RtcLib.h"
#include "PwrLib.h"
#include "ClkLib.h"
#include "UrtLib.h"
/* User defined macros */
/*select RTC interrupt source to wake up MCU from hibernate/flexi mode*/
//#define RTC_MOD60ALARM_WAKEUP_EN   0    //RTC alarm
#define RTC_MOD60ALARM_WAKEUP_EN   1      //modulo-60 alarm

/*wake up period, in seconds,
When using Modulo-60 RTC alarm, the period varies with prescaler value, in
this example, prescaler is set to 64, so the period is 60/(32768Hz/64) = 117.2mS.

When using RTC alarm, the minimum period is approximate 0.5mS(Need time to wake
up CPU, to service ISR...)and the maximum period is 131072s(2^32/32768Hz=131072s
equals to 1.517 hours).
*/
#if RTC_MOD60ALARM_WAKEUP_EN //using Modulo-60 alarm
//#define WAKEUP_PERIOD   RTC1_PRESCALE_1       // 60/(32768Hz/1) = 1.831mS
//#define WAKEUP_PERIOD   RTC1_PRESCALE_2       // 60/(32768Hz/2) = 3.662mS
//#define WAKEUP_PERIOD   RTC1_PRESCALE_4       // 60/(32768Hz/4) = 7.324mS
//#define WAKEUP_PERIOD   RTC1_PRESCALE_8       // 60/(32768Hz/8) = 14.65mS
//#define WAKEUP_PERIOD   RTC1_PRESCALE_16      // 60/(32768Hz/16) = 29.30mS
//#define WAKEUP_PERIOD   RTC1_PRESCALE_32      // 60/(32768Hz/32) = 58.59mS
//#define WAKEUP_PERIOD   RTC1_PRESCALE_64      // 60/(32768Hz/64) = 117.2mS
//#define WAKEUP_PERIOD   RTC1_PRESCALE_128     // 60/(32768Hz/128) = 234.4mS
//#define WAKEUP_PERIOD   RTC1_PRESCALE_256     // 60/(32768Hz/256) = 468.8mS
//#define WAKEUP_PERIOD   RTC1_PRESCALE_512     // 60/(32768Hz/512) = 937.5mS
//#define WAKEUP_PERIOD   RTC1_PRESCALE_1024    // 60/(32768Hz/1024) = 1.875S
//#define WAKEUP_PERIOD   RTC1_PRESCALE_2048    // 60/(32768Hz/2048) = 3.75S
#define WAKEUP_PERIOD   RTC1_PRESCALE_4096    // 60/(32768Hz/4096) = 7.5S
//#define WAKEUP_PERIOD   RTC1_PRESCALE_8192    // 60/(32768Hz/8192) = 15S
//#define WAKEUP_PERIOD   RTC1_PRESCALE_16384   // 60/(32768Hz/16384) = 30S
//#define WAKEUP_PERIOD   RTC1_PRESCALE_32768   // 60/(32768Hz/32768) = 60S
#else //using RTC alarm
#define WAKEUP_PERIOD 0.100f       //100ms
#endif   //end RTC_MOD60ALARM_WAKEUP_EN

#if RTC_MOD60ALARM_WAKEUP_EN == 0
   /*wake up by RTC Alarm interrupt, prescaler is set to 1*/
#define TIME_STEP ((unsigned long)(WAKEUP_PERIOD*32768.0f/1.0))
#endif //end RTC_ALARM_WAKEUP_EN

void ClockInit(void);
void UartInit(void);
void RtcPeriodicallyWakeUpInit(void);
void EnterHibernateMode(void);                 // Function to enter Hibernate mode
void delay(long int);
int main(void)
{
   AD5940_Initialize();
   ClockInit();
   UartInit();
   /*
      Delay for seconds, for debug purpose.
      just in case that User can't debug MCU anymore if MCU enter sleep too early and
      there is no well programed interrupt to wake up MCU.
      The reason is that IAR cannot debug when MCU in Hibernate mode, SWD interface
      is disabled in Hibernate.
      Notice that when running MCU in debug mode, the MCU
      is not actually in deep sleep(hibernate). A power cycle or reset is required to
      exit debug mode so that MCU can enter hiberante entirely.
      If MCU in Hibernate mode and never wake up in some situation, for example,
      inappropriate program. User can press down Boot button to make BM pin low and reset
      MCU, then ADI kernel will control MCU and stop executing user code, after that user
      have the chance to erase Flash(remove inappropriate program) by IAR erase memory function
      or using ADI's tool.
   */
   delay_10us(50000);
   delay_10us(50000);
	delay_10us(50000);
   delay_10us(50000);

   AfeDioCfgPin(pADI_AGPIO2,PIN0,2);   //set as GPIO
   AfeDioOenPin(pADI_AGPIO2,PIN0,1);
   AfeDioSetPin(pADI_AGPIO2,PIN0|PIN1);   //set high

   RtcPeriodicallyWakeUpInit();
   delay_10us(5000);
   while(1)
   {
      printf("MCU Going to sleep\r\n");
    //  PwrCfg(ENUM_PMG_PWRMOD_HIBERNATE,BITM_PMG_PWRMOD_MONVBATN,BITM_PMG_SRAMRET_BNK2EN);
      EnterHibernateMode();
      /*
         following code executing after MCU wake up, PC can see following string after
         RTC peroid time about 3.75s in this case.
      */
      printf("MCU is active\r\n");
   }
}

void RtcPeriodicallyWakeUpInit(void)
{
   RtcCfgCR0(BITM_RTC_CR0_CNTEN,0);//disable RTC
   /*set initial count value*/
   RtcSetCnt(0);
#if RTC_MOD60ALARM_WAKEUP_EN
   /*set prescaler*/
   RtcSetPre(WAKEUP_PERIOD);
   /*Modulo-60 RTC alarm configure*/
   RtcIntClrSR0(BITM_RTC_SR0_MOD60ALMINT); //clear interrupt source
   RtcCfgCR0(BITM_RTC_CR0_MOD60ALMEN|BITM_RTC_CR0_MOD60ALMINTEN,1);//enable mod60 module, enable mod60 alarm
   RtcSetMod60Alarm(0);//set mod60 alarm time
   RtcCfgCR1(BITM_RTC_CR1_CNTMOD60ROLLINTEN,1);
#else
   /*set prescaler*/
   RtcSetPre(RTC1_PRESCALE_1);
   /*RTC alarm set up*/
   RtcSetAlarm(TIME_STEP,0);
   RtcIntClrSR0(BITM_RTC_SR0_ALMINT);//clear interrupt source
   RtcCfgCR0(BITM_RTC_CR0_ALMEN|BITM_RTC_CR0_ALMINTEN,1);
#endif   // #if RTC_MOD60ALARM_WAKEUP_EN

   /*Enable RTC interrupt in NVIC*/
   NVIC_EnableIRQ(RTC1_EVT_IRQn);
   //Globle enable for the RTC1
   RtcCfgCR0(BITM_RTC_CR0_CNTEN,1);
}
void EnterHibernateMode(void)
{
   pADI_AFE->PSWFULLCON =0x6000;              // Close PL2, PL, , switches to tie Excitation Amplifiers N and D terminals to 1.8V LDO
   pADI_AFE->NSWFULLCON =0xC00;               // Close Nl and NL2.

   pADI_AFE->TSWFULLCON =0x0000;              // open all T switches
   pADI_AFE->DSWFULLCON =0x0000;              // open all D switches
   pADI_AFE->SWCON =0x10000;                  // Use xFULLSWCON registers
   pADI_AFE->HSRTIACON=0xF;                   // open switch at HPTIA near RTIA
   pADI_AFE->DE1RESCON=0xFF;                  // open switch at HPTIA near RTIA05
   pADI_AFE->DE0RESCON=0xFF;                  // open switch at HPTIA near RTIA03  
      
   delay(10000);
   DioSetPin(pADI_GPIO0,0x4);                 // Set P0.2
   AfePwrCfg(AFE_HIBERNATE);
   delay(1000);                                // Wait for AFE to enter Hibernate mode

  PwrCfg(ENUM_PMG_PWRMOD_HIBERNATE,            // Place digital die in Hibernate
         BITM_PMG_PWRMOD_MONVBATN,
         BITM_PMG_SRAMRET_BNK2EN);

}

void ClockInit(void)
{
   DigClkSel(DIGCLK_SOURCE_HFOSC);
   ClkDivCfg(1,1);
}

void UartInit(void)
{
   // DioCfg(pADI_GPIO0,0x500000);                // Setup P0[11:10] as UART pins
   DioCfgPin(pADI_GPIO0,PIN10,1);               // Setup P0.10 as UART pin
   DioCfgPin(pADI_GPIO0,PIN11,1);               // Setup P0.11 as UART pin
   UrtCfg(pADI_UART0,57600,
          (BITM_UART_COMLCR_WLS|3),0);         // Configure UART for 57600 baud rate
   UrtFifoCfg(pADI_UART0, RX_FIFO_1BYTE,      // Configure the UART FIFOs for 8 bytes deep
              BITM_UART_COMFCR_FIFOEN);
   UrtFifoClr(pADI_UART0, BITM_UART_COMFCR_RFCLR// Clear the Rx/TX FIFOs
              |BITM_UART_COMFCR_TFCLR);
}

void RTC1_Int_Handler(void)
{
   AfeDioTglPin(pADI_AGPIO2, PIN0);                 // Toggle  AGPIO0
   if(pADI_RTC1->SR0 & BITM_RTC_SR0_ALMINT) // alarm interrupt
   {
#if RTC_MOD60ALARM_WAKEUP_EN == 0
      static unsigned long alarm_time = TIME_STEP;//alarm_time: 32bit varible
      alarm_time += TIME_STEP;
      RtcSetAlarm(alarm_time,0);
#endif
      RtcIntClrSR0(BITM_RTC_SR0_ALMINT); //clear interrupt source
   }
   if(pADI_RTC1->SR2 & BITM_RTC_SR2_PSINT) // prescaled, modulo-1 interrupt
   {
      RtcIntClrSR2(BITM_RTC_SR2_PSINT); //clear interrupt source
   }
   if(pADI_RTC1->SR2 & BITM_RTC_SR2_CNTINT)
   {
      RtcIntClrSR2(BITM_RTC_SR2_CNTINT); //clear interrupt
   }
   if(pADI_RTC1->SR0 & BITM_RTC_SR0_MOD60ALMINT) // mod60 alarm interrupt
   {
      RtcIntClrSR0(BITM_RTC_SR0_MOD60ALMINT); //clear interrupt
   }
   if(pADI_RTC1->SR2 & BITM_RTC_SR2_CNTMOD60ROLLINT)
   {
      RtcIntClrSR2(BITM_RTC_SR2_CNTMOD60ROLLINT); //clear interrupt
   }
   AfeDioTglPin(pADI_AGPIO2, PIN0);                 // Toggle  AGPIO0
}


void delay (long int length)
{
	while (length >0)
    	length--;
}
