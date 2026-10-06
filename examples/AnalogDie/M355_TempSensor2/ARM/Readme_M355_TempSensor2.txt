The 'M355_TempSensor2' project demonstrates how to use the second internal
temperature sensor available on the ADuCM355 microcontroller using the Analog
Devices EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Reads and reports the second on-chip temperature sensor
Temperature readings are output continuously via the serial port (UART)
	 UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
"Hello ADuCM355" startup message sent on reset
Uses the AD5940 library for AFE peripheral initialization and control
