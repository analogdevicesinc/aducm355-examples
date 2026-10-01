The 'M355_CRC' project demonstrates how to use the hardware CRC accelerator on
the ADuCM355 microcontroller using the Analog Devices EVAL-ADuCM355QSPZ
evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Computes a CRC using the hardware CRC accelerator
Computes the same CRC in software for verification
Compares hardware and software CRC results
Prints "CRC0 TEST SUCCESS" if results match, "CRC0 TEST FAILED" otherwise
Test runs once; press Reset to run again
UART settings: 57600 baud, 8 data bits, no parity, 1 stop bit
