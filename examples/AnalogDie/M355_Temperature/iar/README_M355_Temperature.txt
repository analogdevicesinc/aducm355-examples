The 'M355_Temperature' project demonstrates how to use the internal temperature
sensor on the ADuCM355 microcontroller using the Analog Devices
EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Reads and reports the internal die temperature sensor
Temperature readings are output continuously via the serial port (UART)
	 UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
Uses the AD5940 library for AFE peripheral initialization and control
