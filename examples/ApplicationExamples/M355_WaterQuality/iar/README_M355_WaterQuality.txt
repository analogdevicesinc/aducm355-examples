The 'M355_WaterQuality' project demonstrates a water quality sensing
application using the ADuCM355 microcontroller and the Analog Devices
EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Implements electrochemical sensing flow for water quality parameters
Uses AFE blocks for sensor excitation and current/voltage measurement
Processes and outputs sensor readings via UART for host-side analysis
UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
