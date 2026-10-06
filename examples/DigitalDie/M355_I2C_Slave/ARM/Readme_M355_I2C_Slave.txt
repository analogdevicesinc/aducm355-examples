The 'M355_I2C_Slave' project demonstrates how to configure the ADuCM355 as
an I2C Slave using the Analog Devices EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

I2C pins: P0.4 (SCL), P0.5 (SDA)
Slave responds to I2C addresses 0xA0, 0xA6, 0xA8
Receives data bytes from I2C Master into a 16-byte receive buffer
Transmits "Hello Master" (14 bytes) to the I2C Master on request
Automatic clock stretching enabled for reliable high-speed communication
Designed to work in conjunction with the M355_I2C_Master example
