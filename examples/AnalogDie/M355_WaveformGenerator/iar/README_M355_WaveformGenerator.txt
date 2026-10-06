The 'M355_WaveformGenerator' project demonstrates how to configure the
Waveform Generator (WGEN) on the ADuCM355 microcontroller using the Analog
Devices EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Configures the AFE waveform generator to produce sinusoidal, trapezoidal,
	 or custom waveforms
Waveform output is available on the AFE output pins
Status and configuration information output via the serial port (UART)
	 UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
Uses the AD5940 library for AFE peripheral initialization and control
