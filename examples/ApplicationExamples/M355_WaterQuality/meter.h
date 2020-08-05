#ifndef _meter_H_
#define _meter_H_
#include "ad5940.h"
#include <stdio.h>

#define PI 3.14159265f
/* Default LPDAC resolution(2.5V internal reference). */
#define DAC12BITVOLT_1LSB   (2200.0f/4095)          //mV
#define DAC6BITVOLT_1LSB    (DAC12BITVOLT_1LSB*64)  //mV
/* Rcal value: Rcal0(Rcal0_Rcal1), Rcal1(AIN3_DE0) */
#define AFE_RCAL_0  1000u   // Rcal0&Rcal1
#define AFE_RCAL_1  100000u // AIN3&DE0
/* External LPLOOP0 Rtia value */
#define LPTIA_EXT_RTIA 1e6f

/*
converte 18bit sign DFT result to 32bit signed value.
*/
#define convertDftToInt(x) ((x)&0x20000)?((int32_t)(0xFFFC0000|x)) : ((int32_t)(0x0003FFFF&x));


/* state of meter*/
typedef enum _state
{
	TEM=1,
	EC,
	PH,
	DO,
	PHIMP,
}state;

/* meter mode enable flag*/
typedef struct
{
	state state;
	uint8_t TEMenable;
	uint8_t ECenable;
	uint8_t PHenable;
	uint8_t DOenable;
	uint8_t PHIMPenable;
}Store;

typedef struct
{
  int32_t DFT_result[4];
}ImpResult_t;

typedef struct
{
	float Freq;
	float Mag_result;
  float Pha_result;
}Result_Imp;


/* PH test parameter configuration*/
typedef struct
{
	float Vzero;         // Voltage of Vzero pin
	uint32_t ADCPgaGain; // ADC PGA gain
	float PH_gain;       // conversion equation: gain
	float PH_offset;     // conversion equation: conversion
}PHcfg_Type;


/* PH_IMP test parameter configuration*/
typedef struct
{
  SoftSweepCfg_Type SweepCfg; // Sweep Function Control */	
  float SweepCurrFreq;        // Current frequency
  float SweepNextFreq;        // Next frequency
  float FreqofData;      //The frequency of latest data sampled
	float Sinfreq;         // Frequency of default excitation signal
	float SinVolt;         // Vp voltage of excitation signal
	float RtiaVal;         // External Rtia value
	uint32_t AdcPgaGain;   // PGA Gain, We must ensure signal is in range of +-1.5V which is limited by ADC input stage */   

}PHIMPcfg_Type;
  
/* DO test parameter configuration*/
typedef struct
{
	float Vzero;         // Voltage of Vzero pin
	float Vbias;         // Voltage of Vbias pin
	uint32_t HstiaRtiaSel; // Use internal RTIA
	uint32_t ADCPgaGain; // ADC PGA gain
	float DO_gain;       // conversion equation: gain
	float DO_offset;     // conversion equation: conversion
}DOcfg_Type;
	
/* TEM test parameter configuration*/
typedef struct
{
	float Sinfreq;         // Frequency of excitation signal
  float DACVoltPP;       // DAC output voltage in mV peak to peak. Maximum value is 800mVpp. Peak to peak voltage
	uint32_t ExcitBufGain; // Select from  EXCTBUFGAIN_2, EXCTBUFGAIN_0P25     
  uint32_t HsDacGain;    // Select from  HSDACGAIN_1, HSDACGAIN_0P2 
  uint32_t AdcPgaGain;   // PGA Gain select from GNPGA_1, GNPGA_1_5, GNPGA_2, GNPGA_4, GNPGA_9 !!! We must ensure signal is in range of +-1.5V which is limited by ADC input stage */   
	uint32_t HstiaRtiaSel; // Use internal RTIA, select from RTIA_INT_200, RTIA_INT_1K, RTIA_INT_5K, RTIA_INT_10K, RTIA_INT_20K, RTIA_INT_40K, RTIA_INT_80K, RTIA_INT_160K */
  float RcalVal;         // Rcal value in Ohm */
}TEMcfg_Type;

/* EC test parameter configuration*/
typedef struct
{
	float Sinfreq;         // Frequency of excitation signal
  float DACVoltPP;       // DAC output voltage in mV peak to peak. Maximum value is 800mVpp. Peak to peak voltage
	uint32_t ExcitBufGain; // Select from  EXCTBUFGAIN_2, EXCTBUFGAIN_0P25     
  uint32_t HsDacGain;    // Select from  HSDACGAIN_1, HSDACGAIN_0P2 
  uint32_t AdcPgaGain;   // PGA Gain select from GNPGA_1, GNPGA_1_5, GNPGA_2, GNPGA_4, GNPGA_9 !!! We must ensure signal is in range of +-1.5V which is limited by ADC input stage */   
	uint32_t HstiaRtiaSel; // Use internal RTIA, select from RTIA_INT_200, RTIA_INT_1K, RTIA_INT_5K, RTIA_INT_10K, RTIA_INT_20K, RTIA_INT_40K, RTIA_INT_80K, RTIA_INT_160K */
  float RcalVal;         // Rcal value in Ohm */
	float EC_gain;         // conversion equation: gain
}ECcfg_Type;

/* TEM test function*/
float Meter_TEM(void);
void TEM_Test(void);
Result_Imp TEM_Res_Cal(fImpCar_Type *Rcal, fImpCar_Type *Rz);
float TEM_Calculation(float Res);
AD5940Err TEM_Init(void);
AD5940Err TEM_Terminate(void);
AD5940Err TEM_ISR(void);

/* EC test function*/
float Meter_EC(void);
void EC_Test(int Rtia, int Rcal);
float EC_RTIACho(fImpCar_Type *Rcal, fImpCar_Type *Rz,float Rcal_i);
float EC_RCALCho(fImpCar_Type *Rcal, fImpCar_Type *Rz);
Result_Imp EC_Res_Cal(fImpCar_Type *Rcal, fImpCar_Type *Rz, float Rcal_i);
float EC_Calculation(float EC_Res, float EC_gain);
AD5940Err EC_Init(void);
AD5940Err EC_Terminate(void);
AD5940Err EC_ISR(void);


/* PH test function*/
float Meter_PH(void);
float PH_Test(void);
float PH_Calculate(float PH_volt, float PH_gain, float PH_offset);
AD5940Err PH_Init(void);
AD5940Err PH_Terminate(void);
AD5940Err PH_ISR(void);


/* DO test function*/
float Meter_DO(void);
float DO_Test(void);
float DO_Calculate(float PH_volt, float PH_gain, float PH_offset);
AD5940Err DO_Init(void);
AD5940Err DO_Terminate(void);
AD5940Err DO_ISR(void);


/* PHIMP test function*/
void Meter_PHIMP(void);
void PHIMP_Test(void);
Result_Imp PHIMP_Calculate(fImpCar_Type *Rvol, fImpCar_Type *Rcur);
AD5940Err PHIMP_Init(void);
AD5940Err PHIMP_Terminate(void);
AD5940Err PHIMP_ISR(void);
AD5940Err SnsACSigChainCfg(float freq);

void meter_process(void);
void UARTCmd_cmd_sent(char *cmd, uint32_t para1, uint32_t para2, float para3, float para4, float para5, float para6);


#endif
