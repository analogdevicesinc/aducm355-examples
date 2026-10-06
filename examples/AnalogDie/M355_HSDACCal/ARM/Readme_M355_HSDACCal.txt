The 'M355_HSDACCal' project demonstrates how to calibrate the High Speed DAC
(HSDAC) on the ADuCM355 microcontroller using the Analog Devices
EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Performs HSDAC offset and gain calibration using the AD5940 library
Calibration results are output via the serial port (UART)
	 UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
Uses the AD5940 library for AFE peripheral initialization and control
