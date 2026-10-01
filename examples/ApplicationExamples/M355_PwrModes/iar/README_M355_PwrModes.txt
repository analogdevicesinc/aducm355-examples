The 'M355_PwrModes' project demonstrates the various power modes available on
the ADuCM355 microcontroller using the Analog Devices EVAL-ADuCM355QSPZ
evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Demonstrates transitioning between Active, Flexi, and Hibernate power modes
Shows how to configure wake-up sources for each power mode
Current consumption can be measured at IOVDD/DVDD pins of evaluation board
Power mode transitions and wake-up events reported via UART
UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
