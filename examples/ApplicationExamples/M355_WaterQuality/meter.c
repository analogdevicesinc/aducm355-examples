#include "meter.h"


uint8_t meter_enable = 1;  //process enable flag

Store store = {TEM,0,0,0,0,1};


uint32_t stop(uint32_t para1, uint32_t para2, float para3, float para4)
{
  meter_enable = 0;                  //Disable process once meter is set
  return 0;
}

uint32_t start(uint32_t para1, uint32_t para2, float para3, float para4)
{
  meter_enable = 1;                  //Enable process once meter is set
  return 0;
}

/**
* @brief meter mode received 
**/
uint32_t meter_mode(uint32_t para1, uint32_t para2, float para3, float para4)
{
  if ((0x01&para1) == 1)  //if para1 bit[0]=1, enable TEM mode  
  {
    store.TEMenable = 1;
  }
  else
  {
    store.TEMenable = 0;  
  }
  if ((0x02&para1) == 2)	//if para1 bit[1]=1, enable EC mode
  {
    store.ECenable = 1;
  }
  else
  {
    store.ECenable = 0;
  }
  if ((0x04&para1) == 4)	//if para1 bit[2]=1, enable PH mode
  {
    store.PHenable = 1;
  }
  else
  {
    store.PHenable = 0;
  }
  if ((0x08&para1) == 8)	//if para1 bit[3]=1, enable DO mode
  {
    store.DOenable = 1;
  }
  else
  {
    store.DOenable = 0;
  }
  if (para1 == 16)	     //if para1=16, enable PH IMPEDANCE mode
  {
    store.PHIMPenable = 1;
  }
  else
  {
    store.PHIMPenable = 0;
  }
  
  meter_enable = 1;     //enable process once meter is set
  return 0;
}

/**
* @brief meter mode process
**/
void meter_process(void)
{
  if (meter_enable == 1)
  {
    float Result_meter = 0.0f;
    
    switch(store.state)
    {		
    case TEM:
      if (store.TEMenable == 1)
      {
        TEM_Init();
        Result_meter = Meter_TEM();
        TEM_Terminate();
        UARTCmd_cmd_sent("Meas",store.state,1,Result_meter,0,0,0);	
      }
      store.state = EC;
      break;
    case EC:
      if (store.ECenable == 1)
      {
        EC_Init();
        Result_meter = Meter_EC();
        EC_Terminate();
        UARTCmd_cmd_sent("Meas",store.state,1,Result_meter,0,0,0);	
      }
      store.state = PH;
      break;
    case PH:
      if (store.PHenable == 1)
      {
        PH_Init();
        Result_meter = Meter_PH();
        PH_Terminate();
        UARTCmd_cmd_sent("Meas",store.state,1,Result_meter,0,0,0);	
      }
      store.state = DO;
      break;
    case DO:
      if (store.DOenable == 1)
      {
        DO_Init();
        Result_meter = Meter_DO();
        DO_Terminate();
        UARTCmd_cmd_sent("Meas",store.state,1,Result_meter,0,0,0);	
      }
      store.state = PHIMP;	
      break;
    case PHIMP:  
      if (store.PHIMPenable ==1)
      {
        PHIMP_Init();	
        Meter_PHIMP();
        PHIMP_Terminate();	
        printf("end");					
      }	
      store.state = TEM;	
      break;
    default:
      break;
    }
    AD5940_Delay10us(50000);  /* Delay 200us */
  }
}


