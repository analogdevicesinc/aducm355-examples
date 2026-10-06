The 'M355_ADC' project demonstrates how to configure the ADC on the ADuCM355
microcontroller using Analog Devices EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Demonstrates ADC configuration in two modes:
Polling mode (AD5940_ADCPolling.c)
FIFO mode with mean calculation (AD5940_ADCMeanFIFO.c)
Results are output to the serial port (UART)
	 UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
"Hello ADuCM355" startup message sent on reset
