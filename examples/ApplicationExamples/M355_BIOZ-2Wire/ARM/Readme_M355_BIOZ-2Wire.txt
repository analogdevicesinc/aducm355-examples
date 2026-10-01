The 'M355_BIOZ_2Wire' project demonstrates how to perform a 2-wire Bio-Impedance
(BIOZ) measurement using the ADuCM355 microcontroller and the Analog Devices
EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Configures the AFE for 2-wire bio-impedance spectroscopy measurement
Applies an AC excitation current and measures the resulting voltage
Computes impedance magnitude and phase across a frequency sweep
Measurement results output via UART
UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
