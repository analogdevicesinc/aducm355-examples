The 'M355_Timers' project demonstrates how to configure the General Purpose
Timers on the ADuCM355 microcontroller using the Analog Devices
EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

Timer 0: 645ms timeout, captures button S2 press time, reports to UART
Timer 1: 244ms timeout, toggles AFEDIE_GPIO0 (Pin 17 of P2 on EVAL board)
Timer 2: 1 second timeout, toggles AFEDIE_GPIO1 (Pin 18 of P2 on EVAL board)
Pressing S2 sends the captured timer value and press count to UART
UART settings: 57600 baud, 8 data bits, no parity, 1 stop bit
