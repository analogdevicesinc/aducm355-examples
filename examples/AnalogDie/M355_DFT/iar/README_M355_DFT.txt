The 'M355_DFT' project demonstrates how to configure the Discrete Fourier
Transform (DFT) engine on the ADuCM355 microcontroller using the Analog
Devices EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Configures the AFE DFT engine to perform frequency domain analysis
DFT results are output via the serial port (UART)
	 UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
Uses the AD5940 library for AFE peripheral initialization and control
