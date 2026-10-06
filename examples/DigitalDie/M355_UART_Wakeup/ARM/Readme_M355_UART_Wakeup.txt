The 'M355_UART_Wakeup' project demonstrates how to use UART RX activity to
wake the ADuCM355 from hibernate mode using the Analog Devices
EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Send ASCII character '1' (0x31) or byte 0x01 via UART to wake MCU from hibernate
Send ASCII character '2' (0x32) or byte 0x02 via UART to enter hibernate mode
AFE die enters hibernate mode together with the digital die
UART RX wakeup interrupt enabled before entering hibernate mode
On wake-up, prints "MCU is in active mode" to UART
UART settings: 57600 baud, 8 data bits, no parity, 1 stop bit
