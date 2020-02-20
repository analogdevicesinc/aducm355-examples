/******************************************************************************
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.
By using this software you agree to the terms of the associated
Analog Devices Software License Agreement.

*****************************************************************************/

#include "UrtLib.h"

/**
	@brief int UrtCfg(ADI_UART_TypeDef *pPort, int iBaud, int iBits, int iFormat)
			==========Configure the UART.
	@param pPort :{pADI_UART,}	\n
		Set to pADI_UART. Only one channel available.
	@param iBaud :{B1200,B2200,B2400,B4800,B9600,B19200,B38400,B57600,B115200,B230400,B430800}	\n
		Set iBaud to the baudrate required:
		Values usually: 1200, 2200 (for HART), 2400, 4800, 9600,
		        19200, 38400, 57600, 115200, 230400, 430800, or type in baud-rate directly
	@param iBits :{COMLCR_WLS_FIVEBITS,COMLCR_WLS_SIXBITS,COMLCR_WLS_SEVENBITS,COMLCR_WLS_EIGHTBITS}	\n
			- 0 = COMLCR_WLS_FIVEBITS for data length 5bits.
			- 1 = COMLCR_WLS_SIXBITS for data length 6bits.
			- 2 = COMLCR_WLS_SEVENBITS for data length 7bits.
			- 3 = COMLCR_WLS_EIGHTBITS for data length 8bits.
	@param iFormat :{0|COMLCR_STOP_EN|COMLCR_PEN_EN|COMLCR_EPS_EVEN|COMLCR_SP_EN}	\n
		The bitwise or of the data format required:
			- 0 = URT_STP1 -> 1 stop bits, no parity.
			- 0x4 = COMLCR_STOP_EN  -> Set for 2 stop bits.
			- 0x8 = COMLCR_PEN_EN -> Set for Parity enabled
			- 0x10 = COMLCR_EPS_EVEN -> Even parity.
			- 0x20 = COMLCR_SP_EN -> Sticky parity.
	@return Value of COMLSR: See UrtLinSta() function for bit details.
	@note
		- Powers up UART if not powered up.
		- Standard baudrates are accurate to better than 0.1% plus clock error.\n
		- Non standard baudrates are accurate to better than 1% plus clock error.
   @warning - If an external clock is used for the system the ullRtClk must be modified with \n
         the speed of the clock used.
**/

int UrtCfg(ADI_UART_TypeDef *pPort, int iBaud, int iBits, int iFormat)
{
   int i1;
   int iDiv;
   int iRtC;
   int iOSR;
   int iPllMulValue;
   unsigned long long ullRtClk = 16000000;                // The root clock speed


   iDiv = (pADI_CLKG0_CLK->CTL1& BITM_CLKG_CLK_CTL1_PCLKDIVCNT);                 // Read UART clock as set by CLKCON1[10:8]
   iDiv = iDiv>>8;
   if (iDiv == 0)
      iDiv = 1;
   //  iDiv = 1 << iDiv;                                  // 2^iDiv

   iRtC = (pADI_CLKG0_CLK->CTL0& BITM_CLKG_CLK_CTL0_CLKMUX); // Check what is the root clock

   switch (iRtC)
   {
   case 0:                                               // HFOSC selected
      ullRtClk = 26000000;
      break;

   case 1:                                               // HFXTAL selected
      if ((pADI_CLKG0_CLK->CTL0 & 0x200)==0x200)           // 26Mhz XTAL used
         ullRtClk = 26000000;
      else
         ullRtClk = 16000000;                              // Assume 16MHz XTAL
      break;

   case 2:                                               // SPLL output
      iPllMulValue = (pADI_CLKG0_CLK->CTL3 &             // Check muliplication factor in PLL settings
                      BITM_CLKG_CLK_CTL3_SPLLNSEL);      // bits[4:0]. Assume div value of 0xD in bits [14:11]
      ullRtClk = (iPllMulValue *1000000);                // Assume straight multiplication by pADI_CLKG0_CLK->CTL3[4:0]
      break;

   case 3:
      ullRtClk = 16000000;                                //External clock is assumed to be 26MhZ, if different
      break;                                             //clock speed is used, this should be changed

   default:
      break;
   }
   //   iOSR = (pPort->COMLCR2 & 0x3);
   //   iOSR = 2^(2+iOSR);
   pPort->COMLCR2 = 0x3;
   iOSR = 32;
   //i1 = (ullRtClk/(iOSR*iDiv))/iBaud;	              // UART baud rate clock source is PCLK divided by OSR
   i1 = (ullRtClk/(iOSR*iDiv))/iBaud-1;   //for bigger M and N value
   pPort->COMDIV = i1;

   pPort->COMFBR = 0x8800|(((((2048/(iOSR*iDiv))*ullRtClk)/i1)/iBaud)-2048);
   pPort->COMIEN = 0;
   pPort->COMLCR = (iFormat&0x3c)|(iBits&3);

   return pPort->COMLSR;
}
/**
	@brief int UrtFifoCfg(ADI_UART_TypeDef *pPort, int iFifoSize, int iFIFOEn)
			==========Configure the UART FIFO.
	@param pPort :{pADI_UART,}	\n
		Set to pADI_UART. Only one channel available.
	@param iFifoSize :{0,1,2,3}	\n
			- 0 = RX_FIFO_1BYTE -> Rx Trigger interrupt after 1 byte received
			- 0x40 = RX_FIFO_4BYTE -> Rx Trigger interrupt after 4 bytes received
			- 0x80 = RX_FIFO_8BYTE -> Rx Trigger interrupt after 8 bytes received
			- 0xC0 = RX_FIFO_14BYTE -> Rx Trigger interrupt after 14 bytes received
	@param iFIFOEn :{0,BITM_UART_COMFCR_FIFOEN}	\n
		The bitwise or of the data format required:
			- 0 = disable UART FIFO
			- 0x1 = BITM_UART_COMFCR_FIFOEN  ->enable FIFOs
	@return Value of COMFCR
**/
int UrtFifoCfg(ADI_UART_TypeDef *pPort, int iFifoSize, int iFIFOEn)
{
   pPort->COMFCR = (BITM_UART_COMFCR_RFTRIG & iFifoSize ) |
      iFIFOEn;
   return  pPort->COMFCR;
}

/**
	@brief int UrtFifoClr(ADI_UART_TypeDef *pPort, int iClrEn)
			==========Clear the UART FIFOs.
	@param pPort :{pADI_UART,}	\n
		Set to pADI_UART. Only one channel available.
	@param iClrEn :{0,BITM_UART_COMFCR_TFCLR|BITM_UART_COMFCR_RFCLR}	\n
		The bitwise or of the data format required:
			- 0 = normal FIFO operation
			- 0x2 = BITM_UART_COMFCR_RFCLR -> clear Rx FIFO
                        - 0x4 = BITM_UART_COMFCR_TFCLR -> clear Tx FIFO
	@return Value of COMFCR
**/
int UrtFifoClr(ADI_UART_TypeDef *pPort, int iClrEn)
{
   pPort->COMFCR |= iClrEn;                                   // Clear the UART FIFOs
   pPort->COMFCR &= ~(iClrEn);                                // Disable clearing mechanism
   return pPort->COMFCR;
}
/**
	@brief int UrtBrk(ADI_UART_TypeDef *pPort, int iBrk)
			==========Force SOUT pin to 0
	@param pPort :{pADI_UART,}	\n
		Set to pADI_UART. Only one channel available.
	@param iBrk :{COMLCR_BRK_DIS, COMLCR_BRK_EN}	\n
		- 0 = COMLCR_BRK_DIS to disable SOUT break condition (SOUT behaves as normal)
		- 1 = COMLCR_BRK_EN to force SOUT break condition - SOUT remains low until this bit is cleared
	@return Value of COMLSR: See UrtLinSta() function for bit details.


**/
int UrtBrk(ADI_UART_TypeDef *pPort, int iBrk)
{
	if(iBrk == 0)
		pPort->COMLCR &= 0x3F;		//Disable break condition on SOUT pin.
	else
		pPort->COMLCR |= 0x40;		//Force break condition on SOUT pin.
	return	pPort->COMLSR;
}
/**
	@brief int UrtLinSta(ADI_UART_TypeDef *pPort)
			==========Read the status byte of the UART.
	@param pPort :{pADI_UART,}	\n
		Set to pADI_UART. Only one channel available.
	@return value of COMLSR:
		- COMLSR_DR = Data ready.
		- COMLSR_OE = Overrun error.
		- COMLSR_PE = Parity error.
		- COMLSR_FE = Framing error.
		- COMLSR_BI = Break indicator.
		- COMLSR_THRE = COMTX empty status bit.
		- COMLSR_TEMT = COMTX and shift register empty status bit.
	@warning	UART must be configured before checking status
**/

int UrtLinSta(ADI_UART_TypeDef *pPort)
{
	return	pPort->COMLSR;
}

/**
	@brief int UrtTx(ADI_UART_TypeDef *pPort, int iTx)
			==========Write 8 bits of iTx to the UART.
	@param pPort :{pADI_UART0,}	\n
		Set to pADI_UART0. Only one channel available.
	@param iTx :{0-255}	\n
		Byte to transmit.
	@return 1 if successful or 0 if TX buffer full already:
	@warning
		UART must be configured before writing data.\n
		Character is lost if TX buffer already full.
**/

int UrtTx(ADI_UART_TypeDef *pPort, int iTx)
{

   if(pPort->COMLSR & BITM_UART_COMLSR_THRE)
   {
		pPort->COMTX = iTx;
		return 1;
   }

	return 0;
}

/**
	@brief int UrtRx(ADI_UART_TypeDef *pPort)
			==========Read the UART data.
	@param pPort :{pADI_UART,}	\n
		Set to pADI_UART. Only one channel available.
	@return The byte in the Rx buffer (COMRX).
	@note
		- Does not wait if no new character available.
**/

int UrtRx(ADI_UART_TypeDef *pPort)
{
	return pPort->COMRX&0xff;
}

/**
	@brief int UrtMod(ADI_UART_TypeDef *pPort, int iMcr, int iWr)
			==========Write iMcr to UART Modem Control Register
	@param pPort :{pADI_UART,}	\n
		Set to pADI_UART. Only one channel available.
	@param iMcr :{0|COMMCR_DTR|COMMCR_RTS|COMMCR_LOOPBACK}	\n
		Set to the modem control combination required (COMMCR):
		- 0 to not use DTR, RTS ot LOOPBACK.
		Or a combination of the following.
		- COMMCR_DTR to use Data terminal ready.
		- COMMCR_RTS_to use Request to send.
		- COMMCR_LOOPBACK for Loop back mode.

	@param iWr :{0,1}
		- 0 to read mode only (ignores iMcr).
		- 1 to write and read mode.
	@return value of COMMSR:	\n
		- COMMSR.0 = DCTS -> CTS changed.
		- COMMSR.1 = DDSR -> DSR changed.
		- COMMSR.2 = TERI -> RI Trailing edge.
		- COMMSR.3 = DDCD -> DCD changed.
		- COMMSR.4 = CTS -> Clear to send.
		- COMMSR.5 = DSR -> Data set ready.
		- COMMSR.6 = RI -> Ring indicator.
		- COMMSR.7 = DCD -> Data carrier detect.
	@note	This function does not change the Port Multiplexers.
**/

int UrtMod(ADI_UART_TypeDef *pPort, int iMcr, int iWr)
{
	if(iWr)	pPort->COMMCR = iMcr;
	return pPort->COMMSR&0x0ff;
}
/**
	@brief int UrtModSta(ADI_UART_TypeDef *pPort)
			==========Read the Modem status register byte of the UART.
	@param pPort :{pADI_UART,}	\n
		Set to pADI_UART. Only one channel available.
	@return value of COMMSR:
		- COMMSR_DCD = Data carrier detect level
		- COMMSR_RI = Ring indicator level
		- COMMSR_DSR = Data set ready status
		- COMMSR_CTS = Clear to Send input level
		- COMMSR_DDCD = Delta DCD status
		- COMMSR_TERI = trailing edge Ring indicator status
		- COMMSR_DDSR = Delta DSR status
		- COMMSR_DCTS = Delta CTS status
	@warning	UART must be configured before checking status
**/

int UrtModSta(ADI_UART_TypeDef *pPort)
{
   return	pPort->COMMSR;
}

/**
	@brief int UrtDma(ADI_UART_TypeDef *pPort, int iDmaSel)
			==========Enables/Disables DMA channel.
	@param pPort :{pADI_UART,}	\n
		Set to pADI_UART. Only one channel available.
	@param iDmaSel :{0|COMIEN_EDMAT| COMIEN_EDMAR}
		- 0 to select neither Tx or Rx DMA.
		Or set to the bitwise or combination of
		- COMIEN_EDMAT enable UART DMA Tx IRQ.
		- COMIEN_EDMAR enable UART DMA Rx IRQ.
	@return 1.
**/

int UrtDma(ADI_UART_TypeDef *pPort, int iDmaSel)
{
   // int	i1;
   /*
   i1 = pPort->COMIEN & ~COMIEN_EDMAT & ~COMIEN_EDMAR;
   i1 |= iDmaSel;
   pPort->COMIEN = i1;
   */
   return 1;
}


/**
	@brief int UrtIntCfg(ADI_UART_TypeDef *pPort, int iIrq)
			==========Enables/Disables UART Interrupt sources.

	@param pPort :{pADI_UART,}	\n
		Set to pADI_UART. Only one channel available.
	@param iIrq :{COMIEN_ERBFI| COMIEN_ETBEI| COMIEN_ELSI| COMIEN_EDSSI| COMIEN_EDMAT| COMIEN_EDMAR}
		- 0 to select none of the options.
		Or set to the bitwise or combination of
		- COMIEN_ERBFI to enable UART RX IRQ.
		- COMIEN_ETBEI to enable UART TX IRQ.
		- COMIEN_ELSI to enable UART Status IRQ.
		- COMIEN_EDSSI to enable UART Modem status IRQ.
		- COMIEN_EDMAT to enable UART DMA Tx IRQ.
		- COMIEN_EDMAR to enable UART DMA Rx IRQ.
	@return 1.
**/
int UrtIntCfg(ADI_UART_TypeDef *pPort, int iIrq)
{
	pPort->COMIEN = iIrq;
	return 1;
}

/**
	@brief int UrtIntSta(ADI_UART_TypeDef *pPort)
			==========return UART interrupt status.
	@param pPort :{pADI_UART,}	\n
		Set to pADI_UART. Only one channel available.

	@return COMIIR.
**/

int UrtIntSta(ADI_UART_TypeDef *pPort)
{
	return pPort->COMIIR;
}

   /**@}*/
