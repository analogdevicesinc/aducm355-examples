The 'M355_ECSns_CapaTest' project demonstrates how to perform a
chrono-amperometric measurement using the ADuCM355 microcontroller and the
Analog Devices EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Configures the AFE for chrono-amperometric (capacitance/charge) measurement
Applies a potential step and measures the resulting transient current response
Useful for capacitor testing and electrochemical characterization
Results are output via the serial port (UART)
UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
