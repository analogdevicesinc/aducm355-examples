The 'M355_ECSns_CycloVoltammetry' project demonstrates how to perform a cyclic
voltammetry measurement using the ADuCM355 microcontroller and the Analog
Devices EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Configures the AFE waveform generator to produce a triangular voltage sweep
Measures the resulting current response at each voltage step
Typical cyclic voltammetry scan rate and voltage range configurable in code
Results are output via the serial port (UART) for plotting
UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
