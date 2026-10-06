The 'M355_AfeWdt' project demonstrates how to configure and use the AFE
Watchdog Timer (WDT) on the ADuCM355 microcontroller using the Analog Devices
EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

AFE Watchdog Timer configured with a 16-second timeout period
Watchdog Window feature enabled with a 4-second window (WDTLD - WDTMINLD)
WDT can be configured to either:
Generate an interrupt on timeout (WDT_INTERRUPT_EN = 1)
Trigger a system reset on timeout (WDT_INTERRUPT_EN = 0)
Send ASCII character '1' from UART host to feed (kick) the watchdog timer
UART settings: 230400 baud, 8 data bits, no parity, 1 stop bit
GPIO P0.0 and P0.1 configured as outputs for status indication
