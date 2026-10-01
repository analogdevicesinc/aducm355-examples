The 'M355_ECSns_2Sensors' project demonstrates how to measure two
electrochemical (EC) sensors simultaneously using the ADuCM355 microcontroller
and the Analog Devices EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Configures the AFE to control and measure two independent EC sensors
Alternates measurements between the two sensor channels
Outputs amperometric current readings for each sensor via UART
UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
