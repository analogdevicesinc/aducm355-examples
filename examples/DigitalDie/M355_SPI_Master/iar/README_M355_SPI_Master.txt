The 'M355_SPI_Master' project demonstrates how to configure the ADuCM355 as
an SPI Master using the Analog Devices EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

SPI pins: P0.0 (SCLK), P0.1 (MOSI), P0.2 (MISO), P0.3 (CS0)
Press button S2 to write 14 bytes ("Hello Slave") to an SPI slave device
Press button S3 to read 14 bytes back from the SPI slave
Received data is forwarded to the UART output
UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
Requires an SPI slave device (e.g. ADuCM355 running M355_SPI_Slave)
