The 'M355_SqrWaveVoltammetry' project demonstrates how to perform square wave
voltammetry (SWV) measurement using the ADuCM355 microcontroller and the
Analog Devices EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Generates square-wave pulses superimposed on a staircase potential sweep
Measures forward and reverse pulse currents for each potential step
Computes differential current (forward - reverse) for SWV analysis
Outputs voltammetry data via the serial port (UART)
UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
