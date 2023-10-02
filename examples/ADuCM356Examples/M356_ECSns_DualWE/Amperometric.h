/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#ifndef _AMPEROMETRIC_H_
#define _AMPEROMETRIC_H_
#include "AD5940.H"
#include "stdio.h"
#include "string.h"
#include "math.h"

#define DAC12BITVOLT_1LSB   (2200.0f/4095)  //mV
#define DAC6BITVOLT_1LSB    (DAC12BITVOLT_1LSB*64)  //mV
/* 
  Note: this example will use SEQID_0 as measurment sequence, and use SEQID_1 as init sequence. 
  SEQID_3 is used for calibration.
*/
#define BUFFER_SIZE     4
#define M355_CHAN0      0
#define M355_CHAN1      1
/* Structure to configure each sensor */
typedef struct
{
   float Vzero;                 /* Vzero voltage sets voltage on Working electrode */
   uint32_t LpTiaRl;            /* SE0 Rload select */
   uint32_t LptiaRtiaSel;       /* LPTIA Gain resistor select from RTIA_INT_200, RTIA_INT_1K, RTIA_INT_5K, RTIA_INT_10K, RTIA_INT_20K, RTIA_INT_40K, RTIA_INT_80K, RTIA_INT_160K  */
   uint32_t LpTiaRf;            /* LPTIA filter resistor */
   float SensorBias;            /* Configure sensor Bias voltage (Vre0 - Vse0) */  
   fImpPol_Type RtiaCalValue;   /* Calibrated RTIA value */
   float ResultBuffer[BUFFER_SIZE];
}AppECSnsCfg_Type;

typedef struct
{
/* FIFO, Sequencer and ODR */
  BoolFlag bParaChanged;        /* Indicate to generate sequence again. It's auto cleared by AppAMPInit */
  uint32_t SeqStartAddr;        /* Initialaztion sequence start address in SRAM of AD5940  */
  uint32_t MaxSeqLen;           /* Limit the maximum sequence.   */
  uint32_t SeqStartAddrCal;     /* Measurment sequence start address in SRAM of AD5940 */
  uint32_t MaxSeqLenCal;
  uint32_t M355FifoThresh;           
  float AmpODR;                 /* in Hz. ODR decides the period of WakeupTimer who will trigger sequencer periodically.*/
  int32_t NumOfData;            /* By default it's '-1'. If you want the engine stops after get NumofData, then set the value here. Otherwise, set it to '-1' which means never stop. */
  uint32_t DataFifoSrc;         /* DataFIFO source. FIFOSRC_SINC3, FIFOSRC_DFT, FIFOSRC_SINC2NOTCH, FIFOSRC_VAR, FIFOSRC_MEAN*/
  uint32_t FifoDataCount;       /* Count how many times impedance have been measured */
  
/* Application related parameters */ 
  float RcalVal;                /* Rcal value in Ohms */
  
  /* Clocks */
  float SysClkFreq;             /* The real frequency of system clock */
  float WuptClkFreq;            /* The clock frequency of Wakeup Timer in Hz. Typically it's 32kHz. Leave it here in case we calibrate clock in software method */
  float AdcClkFreq;             /* The real frequency of ADC clock */
  
  /* ADC Configuration */
  float ADCRefVolt;             /* Measured 1.82 V reference*/
  uint32_t PwrMod;              /* Control Chip power mode(LP/HP) */
  uint32_t ADCPgaGain;          /* PGA Gain select from GNPGA_1, GNPGA_1_5, GNPGA_2, GNPGA_4, GNPGA_9 !!! We must ensure signal is in range of +-1.5V which is limited by ADC input stage */   
  uint8_t ADCSinc3Osr;          /* SINC3 OSR selection. ADCSINC3OSR_2, ADCSINC3OSR_4 */
  uint8_t ADCSinc2Osr;          /* SINC2 OSR selection. ADCSINC2OSR_22...ADCSINC2OSR_1333 */
  
  /* EC Sensor Configurations */
  AppECSnsCfg_Type SensorCh0;   /* EC Sensor connected to channel 0 */
  AppECSnsCfg_Type SensorCh1;   /* EC Sensor connected to channel 1 */
  
  uint8_t NumSamplesAvg;        /* The number of sample to take and average */
   
  BoolFlag AMPInited;           /* If the program run firstly, generated sequence commands */
  SEQInfo_Type AD5940SeqInfo;
  SEQInfo_Type M355SeqInfo;
  
  BoolFlag StopRequired;          /* After FIFO is ready, stop the measurment sequence */
  
/* End */
}AppAMPCfg_Type;

/**
 * int32_t type Impedance result in Cartesian coordinate 
*/
typedef struct
{
  float Current;
  float Voltage;
}fAmpRes_Type;



#define AMPCTRL_START          0
#define AMPCTRL_STOPNOW        1
#define AMPCTRL_STOPSYNC       2
#define AMPCTRL_SHUTDOWN       4   /* Note: shutdown here means turn off everything and put AFE into lowest power state*/

AD5940Err AppAMPGetCfg(void *pCfg);
AD5940Err AppAMPInit(uint32_t *pBuffer, uint32_t BufferSize);
AD5940Err AppAMPISR(void *pBuff, uint32_t *pCount);
AD5940Err AppAMPCtrl(int32_t AmpCtrl, void *pPara);
float AppAMPCalcVoltage(uint32_t ADCcode);
float AppAMPCalcCurrent(uint32_t ADCcode, float RtiaVal);

AD5940Err AppECSnrInit(AppECSnsCfg_Type *SnsCfg, uint8_t SnsSel);
AD5940Err AppADCInit(void);
AD5940Err AppAD5940SeqMeasureGen(void);
AD5940Err AppM355SeqMeasureGen(void);

#endif
