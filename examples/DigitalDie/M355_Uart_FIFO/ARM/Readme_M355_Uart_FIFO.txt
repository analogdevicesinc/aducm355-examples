The 'M355_Uart_FIFO' project demonstrates how to use the UART with FIFO
buffering on the ADuCM355 microcontroller using the Analog Devices
EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

UART Rx FIFO configured for 14-byte depth
Press button S2 to send a string to the UART
Received string stored in szInSring[] array via Rx FIFO interrupt
Demonstrates Rx FIFO and associated interrupt handler
Press count tracked and sent to UART on each button press
UART settings: 57600 baud, 8 data bits, no parity, 1 stop bit
