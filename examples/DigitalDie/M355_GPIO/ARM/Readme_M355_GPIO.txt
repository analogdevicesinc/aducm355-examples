The 'M355_GPIO' project demonstrates how to configure the GPIO peripheral on
the ADuCM355 microcontroller using the Analog Devices EVAL-ADuCM355QSPZ
evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Push button S2 (P1.0) and S3 (P1.1) configured as GPIO inputs with interrupts
LED DS2 (P2.4) configured as GPIO output and toggled on button press
Pressing S2 sends "Button 1 pressed" to UART
Pressing S3 sends "Button 2 pressed" to UART
Chip's unique 16-byte ID number is printed to UART on each button press
UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
