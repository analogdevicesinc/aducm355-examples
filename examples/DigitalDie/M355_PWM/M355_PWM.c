/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

/*
   Decription:
		- Test PWM function of ADuCM355
		- PWM0 in toggle mode, which provides a 50% duty cycle output with 2ms period,
		- PWM1 in match mode, with 1ms period and 20% duty cycle

		- AFE timer0 time-out interrupt handler toggle P1.4
		- AFE timer1 time-out interrupt handler toggle P1.5

		- monitor pin17(PWM0) of P2 on EVAL-ADuCM355QSPZ
		- monitor pin18(PWM1) of P2 on EVAL-ADuCM355QSPZ


**/
#include "ad5940.h"
#include "GptLib.h"
#include "DioLib.h"
void PWM0Init(void);
void PWM1Init(void);
void AGPTIntTest(void);


int main()
{
   AD5940_Initialize();
   PWM0Init();
   PWM1Init();

   /*Enable time out interrupt*/
   pADI_AGPT0->CLRI0 = 0xFF;  //clear time-out interrupt
   AfeGptIntEn(pADI_AGPT0,1);
   NVIC_EnableIRQ(AFE_GPT0_IRQn);
   DioCfgPin(pADI_GPIO1, PIN4, 0);  //set p1.4 for monitoring
   DioOenPin(pADI_GPIO1, PIN4, 1);

   AfeGptIntEn(pADI_AGPT1,1);
   NVIC_EnableIRQ(AFE_GPT1_IRQn);
   DioCfgPin(pADI_GPIO1, PIN5, 0); //set p1.5 for monitoring
   DioOenPin(pADI_GPIO1, PIN5, 1);
   DioSetPin(pADI_GPIO1, 0x30);

   while(1)
   {

   }
}

/**
   @brief void PWM0Init(void)
          set AFE General purpose timer0 in Toggle mode, 50 duty cycle
   @return none.
*/
void PWM0Init()
{
   AfeDioCfgPin(pADI_AGPIO2 , PIN0, 1);   //config gpio in pwm mode
   /*1MHz GPT clock, count up, periodic */
   AfeGptCfg(pADI_AGPT0, TCTL_CLK_PCLK, TCTL_PRE_DIV16, BITM_TMR_CTL_UP|BITM_TMR_CTL_MODE);
   /*count 1000, 1ms for each level.*/
   AfeGptLd(pADI_AGPT0,64535);
   /*Idel state is high, 50% duty cycle*/
   AfePwmCfg(pADI_AGPT0, PWM_IDLEHI, PWM_TOGGLE_MODE);

   /*start timer, output PWM*/
   pADI_AGPT0->CON0 |= BITM_TMR_CTL_EN;
}

/**
   @brief void PWM1Init(void)
          set AFE General purpose timer1 in Match mode, 20% duty cycle
   @return none.
*/
void PWM1Init()
{
   AfeDioCfgPin(pADI_AGPIO2, PIN1, 1);
   /*1MHz GPT clock, count up, periodic */
   AfeGptCfg(pADI_AGPT1, TCTL_CLK_PCLK, TCTL_PRE_DIV16, BITM_TMR_CTL_UP|BITM_TMR_CTL_MODE);
   /*count 1000, 1ms period*/
   AfeGptLd(pADI_AGPT1,64535);
   /*Idel state is high, 20% duty cycle*/
   AfePwmCfg(pADI_AGPT1, PWM_IDLEHI, PWM_MATCH_MODE);
   AfePwmMatch(pADI_AGPT1, 64535+200);

   /*start timer, output PWM*/
   pADI_AGPT1->CON1 |= BITM_TMR_CTL_EN;
}

void AfeGpTimer0_Int_Handler()
{
   pADI_AGPT0->CLRI0 = 0xFF;  //clear time-out interrupt
   DioTglPin(pADI_GPIO1, PIN4);  //toggle P1.4
}

void AfeGpTimer1_Int_Handler()
{
   pADI_AGPT1->CLRI1 = 0xFF;  //clear time-out interrupt
   DioTglPin(pADI_GPIO1, PIN5);  //toggle P1.5
}

