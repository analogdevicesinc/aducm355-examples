The 'M355_4WireZ' project demonstrates how to perform a 4-wire impedance
measurement using the ADuCM355 microcontroller and the Analog Devices
EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Configures the AFE for 4-wire impedance measurement
Applies an AC excitation signal and measures the resulting current
Computes impedance magnitude and phase from voltage and current measurements
Measurement results (impedance in Ohms, phase in degrees) output via UART
UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
