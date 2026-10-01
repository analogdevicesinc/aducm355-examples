The 'M355_Flash_DMA' project demonstrates how to use the DMA controller to
transfer data from RAM to Flash on the ADuCM355 microcontroller using the
Analog Devices EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Software DMA test: copies 64-word block from source RAM to destination RAM
Flash DMA test: copies 64-word block from RAM to Flash at address 0x10000
Prints "Software DMA test success/fail" to UART
Prints "Flash DMA test success/fail" to UART
Test runs once; press Reset to run again
UART settings: 57600 baud, 8 data bits, no parity, 1 stop bit
