The 'M355_Flash' project demonstrates how to write and erase data in Flash
memory on the ADuCM355 microcontroller using the Analog Devices
EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Writes 256 bytes of data to Flash starting at address 0x12000
Erases the flash page at address 0x12000
Use IAR debugger View->Memory->0x12000 to observe flash contents during
	 step execution
Test runs once; press Reset to run again
