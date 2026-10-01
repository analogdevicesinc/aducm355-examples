The 'M355_ECSns_EIS' project demonstrates how to perform Electrochemical
Impedance Spectroscopy (EIS) on an electrochemical sensor using the ADuCM355
microcontroller and the Analog Devices EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Configures the AFE to sweep AC excitation frequency across a defined range
Measures impedance magnitude and phase at each frequency point
Produces a Bode plot dataset (frequency, magnitude, phase) via UART
UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
