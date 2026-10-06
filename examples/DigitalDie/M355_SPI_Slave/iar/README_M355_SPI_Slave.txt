The 'M355_SPI_Slave' project demonstrates how to configure the ADuCM355 as
an SPI Slave using the Analog Devices EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

SPI0 configured in slave mode
Expects to receive 14 bytes from the SPI Master
Transmits "Hello Master" (14 bytes) back to the SPI Master
Received SPI data is forwarded to UART output for monitoring
UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
Designed to work in conjunction with the M355_SPI_Master example
Assumes EVAL-ADuCM355QSPZ evaluation board
