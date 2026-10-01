The 'M355_Impedance' project demonstrates how to perform a standard 2-wire
impedance measurement using the ADuCM355 microcontroller and the Analog
Devices EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Configures the AFE for 2-wire impedance measurement using the high speed DAC
	 and programmable TIA
Applies an AC excitation signal at a fixed frequency
Computes impedance magnitude and phase from DFT results
Measurement results output via the serial port (UART)
UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
