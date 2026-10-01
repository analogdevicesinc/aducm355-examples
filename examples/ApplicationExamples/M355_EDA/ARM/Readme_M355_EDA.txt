The 'M355_EDA' project demonstrates how to perform a low power impedance
measurement below 200 Hz using the ADuCM355 microcontroller and the Analog
Devices EVAL-ADuCM355QSPZ evaluation board. This is suitable for
Electrodermal Activity (EDA) / Galvanic Skin Response (GSR) measurements.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Configures the AFE for low power impedance measurement (< 200 Hz)
Uses the low power DAC and TIA for minimal power consumption
Impedance magnitude and phase results output via the serial port (UART)
UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
