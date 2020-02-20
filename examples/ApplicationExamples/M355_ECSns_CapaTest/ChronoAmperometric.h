/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#ifndef _CHRONOAMPEROMETRIC_H_
#define _CHRONOAMPEROMETRIC_H_
#include "ad5940.h"
#include "stdio.h"
#include "string.h"
#include "math.h"

#define DAC12BITVOLT_1LSB   (2200.0f/4095)  //mV
#define DAC6BITVOLT_1LSB    (DAC12BITVOLT_1LSB*64)  //mV

/*
  OPTION: OPT_RAMP_MEAS : what to measure
  OPT_RAMP_MEAS=0 current only
  OPT_RAMP_MEAS>0 current, all potentials as outlined below, then current again
*/

#define OPT_CHRONOAMP_MEAS 1

typedef enum {
  OPT_CHRONOAMP_MEAS_I      = 0, /* HPTIA_P-HPTIA_N (current) */
  OPT_CHRONOAMP_MEAS_VSE0   = 1, /* VDE0-1.1V */
  OPT_CHRONOAMP_MEAS_VRE0   = 2, /* VRE0-1.1V */
  NUM_OPT_CHRONOAMP_MEAS    = 3
} OPT_CHRONOAMP_MEAS_Type;

#define MAXDATANUM 8000

#if (OPT_CHRONOAMP_MEAS)
static int num_chronoamp_meas = NUM_OPT_CHRONOAMP_MEAS;
#else
static int num_chronoamp_meas = 1;
#endif

static int imeas = 0; // the measurement type we are doing from OPT_RAMP_MEAS_Type
static char *opt_chronoamp_meas[NUM_OPT_CHRONOAMP_MEAS] = {"I", "VSE0", "VRE0"};


/* 
  Note: this example will use SEQID_0 as measurment sequence, and use SEQID_1 as init sequence. 
  SEQID_3 is used for calibration.
*/
/* Structure to configure each sensor */
typedef struct
{
   float Vzero;                 /* Vzero voltage sets voltage on Working electrode */
   uint32_t LpTiaRl;            /* SE0 Rload select */
   uint32_t LptiaRtiaSel;       /* LPTIA Gain resistor select from RTIA_INT_200, RTIA_INT_1K, RTIA_INT_5K, RTIA_INT_10K, RTIA_INT_20K, RTIA_INT_40K, RTIA_INT_80K, RTIA_INT_160K  */
   uint32_t LpTiaRf;            /* LPTIA filter resistor */
   float SensorBias;            /* Configure sensor Bias voltage (Vre0 - Vse0) */  
   fImpPol_Type RtiaCalValue;   /* Calibrated RTIA value */
}AppECSnsCfg_Type;


typedef struct
{
/* Common configurations for all kinds of Application. */
  BoolFlag bParaChanged;        /* Indicate to generate sequence again. It's auto cleared by AppCHRONOAMPInit */
  uint32_t SeqStartAddr;        /* Initialaztion sequence start address in SRAM of AD5940  */
  uint32_t MaxSeqLen;           /* Limit the maximum sequence.   */
  uint32_t SeqStartAddrCal;     /* Measurment sequence start address in SRAM of AD5940 */
  uint32_t MaxSeqLenCal;
  
/* Application related parameters */ 
  BoolFlag ReDoRtiaCal;         /* Set this flag to bTRUE when there is need to do calibration. */
  float SysClkFreq;             /* The real frequency of system clock */
  float WuptClkFreq;            /* The clock frequency of Wakeup Timer in Hz. Typically it's 32kHz. Leave it here in case we calibrate clock in software method */
  float AdcClkFreq;             /* The real frequency of ADC clock */
  uint32_t FifoThresh;           /* FIFO threshold. Should be N*4 */   
  float AmpODR;                 /* in Hz. ODR decides the period of WakeupTimer who will trigger sequencer periodically. DFT number and sample frequency decides the maxim ODR. */
  int32_t NumOfData;            /* By default it's '-1'. If you want the engine stops after get NumofData, then set the value here. Otherwise, set it to '-1' which means never stop. */
  float RcalVal;                /* Rcal value in Ohm */
  uint32_t PwrMod;              /* Control Chip power mode(LP/HP) */
  
/* Receive path configuration */ 
  uint32_t ADCPgaGain;          /* PGA Gain select from GNPGA_1, GNPGA_1_5, GNPGA_2, GNPGA_4, GNPGA_9 !!! We must ensure signal is in range of +-1.5V which is limited by ADC input stage */   
  uint8_t ADCSinc3Osr;          /* SINC3 OSR selection. ADCSINC3OSR_2, ADCSINC3OSR_4 */
  uint8_t ADCSinc2Osr;          /* SINC2 OSR selection. ADCSINC2OSR_22...ADCSINC2OSR_1333 */
  uint32_t DataFifoSrc;         /* DataFIFO source. DATATYPE_ADCRAW, DATATYPE_SINC3 or DATATYPE_SINC2*/

  BoolFlag ExtRtia;             /* Use internal or external Rtia */

  uint32_t ADCMuxP;               /* Configure ADC input MUX Positive Terminal */
  uint32_t ADCMuxN;               /* Configure ADC input MUX Negative Terminal */
  
  float pulseAmplitude;          /* High voltage level */
  uint32_t pulseLength;          /* length of transient measure */
  
  float ADCRefVolt;               /*VVoltage on VREF_1V82 pin.*/

  AppECSnsCfg_Type SensorCh0;
  
  BoolFlag EndSeq;
	
  BoolFlag bMeasureTransient;
  BoolFlag CHRONOAMPInited;       /* If the program run firstly, generated sequence commands */
  SEQInfo_Type InitSeqInfo;
  SEQInfo_Type MeasureSeqInfo;
  SEQInfo_Type TransientSeqInfo;
  BoolFlag StopRequired;          /* After FIFO is ready, stop the measurment sequence */
  uint32_t FifoDataCount;         /* Count how many times impedance have been measured */
  
  char *TestType;
/* End */
}AppCHRONOAMPCfg_Type;

/**
 * int32_t type Impedance result in Cartesian coordinate 
*/
typedef struct
{
  float Current;
  float Voltage;
}fAmpRes_Type;



#define CHRONOAMPCTRL_START          0
#define CHRONOAMPCTRL_STOPNOW        1
#define CHRONOAMPCTRL_STOPSYNC       2
#define CHRONOAMPCTRL_SHUTDOWN       4   /* Note: shutdown here means turn off everything and put AFE to hibernate mode. The word 'SHUT DOWN' is only used here. */
#define CHRONOAMPCTRL_PULSETEST      5

AD5940Err AppCHRONOAMPGetCfg(void *pCfg);
AD5940Err AppCHRONOAMPInit(uint32_t *pBuffer, uint32_t BufferSize);
AD5940Err AppCHRONOAMPISR(void *pBuff, uint32_t *pCount);
AD5940Err AppCHRONOAMPCtrl(int32_t AmpCtrl, void *pPara);
AD5940Err AppCHRONOAMPCalcDataNum(uint32_t time);
float AppCHRONOAMPCalcCurrent(uint32_t ADCcode);

#endif
