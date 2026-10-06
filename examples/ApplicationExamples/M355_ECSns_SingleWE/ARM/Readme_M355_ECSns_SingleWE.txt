The 'M355_ECSns_SingleWE' project demonstrates how to measure a standard
3-lead electrochemical sensor (Working Electrode, Reference Electrode, Counter
Electrode) using the ADuCM355 microcontroller and the Analog Devices
EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Configures the AFE potentiostat with a single working electrode
Applies a bias voltage between the working and reference electrodes
Measures the amperometric current response
Results output via the serial port (UART)
UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
