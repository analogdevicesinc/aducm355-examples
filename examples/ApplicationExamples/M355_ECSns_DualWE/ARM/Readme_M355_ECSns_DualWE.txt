The 'M355_ECSns_DualWE' project demonstrates how to measure a dual working
electrode (WE) electrochemical sensor using the ADuCM355 microcontroller and
the Analog Devices EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Configures the AFE for amperometric measurement with two working electrodes
Both WE channels biased and measured independently
Results for both WE channels output via the serial port (UART)
UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
