The 'M355_I2C_Master' project demonstrates how to configure the ADuCM355 as
an I2C Master using the Analog Devices EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

I2C pins: P0.4 (SCL), P0.5 (SDA)
Press button S2 to write 12 bytes ("Hello Slave") to an I2C slave device
Press button S3 to read 14 bytes from the I2C slave device
Received data is forwarded to the UART output
UART settings: 57600 baud, 8 data bits, no parity, 1 stop bit
Requires an I2C Slave device (e.g. ADuCM355 running M355_I2C_Slave)
