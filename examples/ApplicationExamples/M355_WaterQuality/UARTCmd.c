/*!
 *****************************************************************************
 @file:    UARTCmd.c
 @author:  $Author: nxu2 $
 @brief:   UART Command process
 @version: $Revision: 766 $
 @date:    $Date: 2017-08-21 14:09:35 +0100 (Mon, 21 Aug 2017) $
 -----------------------------------------------------------------------------

Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.
 
*****************************************************************************/
#include "stdint.h"
#include "string.h"
#include "stdio.h"
#include <stdlib.h>
#include <UrtLib.h>

#define LINEBUFF_SIZE 128
#define CMDTABLE_SIZE 8

uint32_t help(uint32_t para1, uint32_t para2, float para3, float para4);
uint32_t say_hello(uint32_t para1, uint32_t para2, float para3, float para4);
uint32_t meter_mode(uint32_t para1, uint32_t para2, float para3, float para4);
uint32_t stop(uint32_t para1, uint32_t para2, float para3, float para4);
uint32_t start(uint32_t para1, uint32_t para2, float para3, float para4);

uint8_t ucTxBufferEmpty =0;
unsigned char szTemp[64] = "";		       // Used to build string before printing to UART


struct __uartcmd_table
{
  void *pObj;
  const char *cmd_name;
  const char *pDesc;
}uart_cmd_table[CMDTABLE_SIZE]=
{
  {(void*)help, "Help", "print supported commands"},
  {(void*)say_hello, "Hello", "print parameteres and say hello"},
  {(void*)meter_mode, "Meas", "set meter mode with para1:\nbit[0] 1:TEM_enable,\nbit[1] 1:EC_enable,\nbit[2] 1:PH_enable,\nbit[3] 1:DO_enable,\nbit[4] 1:PHIMP_enable,\n"},
  {(void*)stop, "Stop", "Stop meter"},
	{(void*)start, "Start", "Start meter"},
};


uint32_t help(uint32_t para1, uint32_t para2, float para3, float para4)
{
  int i = 0;
  printf("*****help menu*****\nbelow are supported commands:\n");
  for(;i<CMDTABLE_SIZE;i++)
  {
    if(uart_cmd_table[i].pObj)
      printf("%-8s --\t%s\n", uart_cmd_table[i].cmd_name, uart_cmd_table[i].pDesc);
  }
  printf("***table end***\n");
  return 0x87654321;
}

uint32_t say_hello(uint32_t para1, uint32_t para2, float para3, float para4)
{
  printf("para1:%d, para2:%d, para3:%f, para4:%f\n", para1, para2, para3, para4);
  printf("Hello\n");
  return 0x12345678;
}

char line_buffer[LINEBUFF_SIZE];
uint32_t line_buffer_index = 0;
uint32_t token_count = 0;
void *pObjFound = 0;
uint32_t parameter1, parameter2;
float parameter3, parameter4;

void UARTCmd_RemoveSpaces(void)
{
  int i = 0;
  token_count = 0;
  char flag_found_token = 0;
  while(i<line_buffer_index)
  {
    if(line_buffer[i] == ' ') line_buffer[i] = '\0';
    else break;
    i++;
  }
  if(i == line_buffer_index) return;  /* All spaces... */
  while(i<line_buffer_index)
  {
    if(line_buffer[i] == ' ')
    {
      line_buffer[i] = '\0';
      flag_found_token = 0;
    }
    else
    { 
      if(flag_found_token == 0)
        token_count ++;
      flag_found_token = 1;
    }
    i++;
  }
}

void UARTCmd_MatchCommand(void)
{
  char *pcmd;
  int i = 0;
  pObjFound = 0;
  while(i<line_buffer_index)
  {
    if(line_buffer[i] != '\0')
    {
      pcmd = &line_buffer[i];
      break;
    }
    i++;
  }
  for(i=0;i<CMDTABLE_SIZE;i++)
  {
    if(strcmp(uart_cmd_table[i].cmd_name, pcmd) == 0)
    {
      /* Found you! */
      pObjFound = uart_cmd_table[i].pObj;
      break;
    }
  }
}

/* Translate string 'p' to number, store results in 'Res', return error code */
static uint32_t Str2Num(char *s, uint32_t *Res)
{
  char *p;
  unsigned int base=10;
  *Res = strtoul( s, &p, base );
  return 0;
}
/* Translate string 'p' to float, store results in 'Res', return error code */
static uint32_t Str2NumFloat(char *s, float *Res)
{
  char *p; 
  *Res = strtod( s, &p);
  return 0;
}

void UARTCmd_TranslateParas(void)
{
  char *p = line_buffer;
  parameter1 = 0;
  parameter2 = 0;
  parameter3 = 0.0f;
  parameter4 = 0.0f;	
	
  while(*p == '\0') p++;    /* goto command */
  while(*p != '\0') p++;    /* skip command. */
  while(*p == '\0') p++;    /* goto first parameter */
  if(Str2Num(p, &parameter1) != 0) return;
  if(token_count == 2) return;           /* Only one parameter */
  while(*p != '\0') p++;    /* skip first command. */
  while(*p == '\0') p++;    /* goto second parameter */
  Str2Num(p, &parameter2);
  if(token_count == 3) return;           /* Only two parameter */
  while(*p != '\0') p++;    /* skip first command. */
  while(*p == '\0') p++;    /* goto second parameter */
  Str2NumFloat(p, &parameter3);
  if(token_count == 4) return;           /* Only three parameter */
  while(*p != '\0') p++;    /* skip first command. */
  while(*p == '\0') p++;    /* goto second parameter */
  Str2NumFloat(p, &parameter4);
}
	
/**
 * @brief Process uart comand
**/
void UARTCmd_Process(char c)
{
  if(line_buffer_index >= LINEBUFF_SIZE-1)
    line_buffer_index = 0;  /* Error: buffer overflow */
  if( (c == '\r') || (c == '\n'))
  {
    line_buffer[line_buffer_index] = '\0';
    /* Start to process command */
    if(line_buffer_index == 0) 
    {
      line_buffer_index = 0; /* Reset buffer */
      return;  /* No command inputs, return */
    }
    /* Step1, remove space */
    UARTCmd_RemoveSpaces();
    if(token_count == 0)
    {
      line_buffer_index = 0; /* Reset buffer */
      return; /* No valid input */
    }
    /* Step2, match commands */
    UARTCmd_MatchCommand();
    if(pObjFound == 0)
    {
      line_buffer_index = 0; /* Reset buffer */
      return;   /* Command not support */
    }
    if(token_count > 1)           /* There is parameters */
    {
      UARTCmd_TranslateParas();
    }
    /* Step3, call function */
   ((uint32_t (*)(uint32_t, uint32_t,float,float))(pObjFound))(parameter1, parameter2,parameter3,parameter4);

    line_buffer_index = 0;  /* Reset buffer */
  }
  else
  {
    line_buffer[line_buffer_index++] = c;
  }
}


/**
 * @brief Uart interrupt handler
**/
void UART_Int_Handler(void)
{
  void UARTCmd_Process(char);
  uint32_t flag;
  flag = pADI_UART0->COMLSR;
  flag = pADI_UART0->COMIIR;
  if ((flag & 0xE) == 0x2)	          // Transmit buffer empty
  {
     ucTxBufferEmpty = 1;
  }
  if((flag & 0x0e) == 0x04)  /* Receive Byte */
  {
    uint32_t count;
    count = pADI_UART0->COMRFC;  /* Receive FIFO count */
    for(int i=0;i < count; i++)
    {
      char c;
      c = pADI_UART0->COMRX&0xff;
      UARTCmd_Process(c);
    }
  }
  if((flag & 0x0e) == 0xc)  /* Time-out */
  {
    uint32_t count;
    count = pADI_UART0->COMRFC;  /* Receive FIFO count */
    for(int i=0;i < count; i++)
    {
      char c;
      c = pADI_UART0->COMRX&0xff;
      UARTCmd_Process(c);
    }
  }
}

/**
 * @brief sent uart comand
**/
void UARTCmd_cmd_sent(char *cmd, uint32_t para1, uint32_t para2, float para3, float para4, float para5, float para6)
{
	unsigned char i = 0;
   unsigned char nLen = 0;
   sprintf ( (char*)szTemp, "%s %d %d %.3f %.3f %.3f %.3f\n",cmd,para1,para2,para3,para4,para5,para6);// Scan string
   nLen = strlen((char*)szTemp);                  // Call function to calcualte the length of scanned string
   if (nLen <200)
   {
      for ( i = 0 ; i < nLen ; i++ )	          // loop to send String to UART
      {
         ucTxBufferEmpty = 0;	                  // Clear flag
         UrtTx(pADI_UART0,szTemp[i]);             // Load UART Tx register.
         while (ucTxBufferEmpty == 0)            // Wait for UART Tx interrupt
         {
         }
      }
   }
	
}

