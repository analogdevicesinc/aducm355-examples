The 'M355_LPLoop' project demonstrates how to configure the Low Power
Potentiostat Loop (LP Loop) on the ADuCM355 microcontroller using the Analog
Devices EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Configures the low power potentiostat loop for electrochemical sensing
Demonstrates the low power AFE configuration for minimal power consumption
Results are output via the serial port (UART)
	 UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
Uses the AD5940 library for AFE peripheral initialization and control
