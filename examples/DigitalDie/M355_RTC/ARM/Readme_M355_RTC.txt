The 'M355_RTC' project demonstrates how to use the Real Time Clock (RTC) to
periodically wake the ADuCM355 from hibernate mode using the Analog Devices
EVAL-ADuCM355QSPZ evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
RTC     = 32.768 kHz (internal LFOSC)

RTC configured for periodic wake-up from hibernate mode
Two wake-up sources selectable via macro RTC_MOD60ALARM_WAKEUP_EN:
Modulo-60 alarm (default): ~7.5 second wake-up period (prescaler = 4096)
RTC alarm: programmable period from ~0.5ms to 1.517 hours
MCU announces "Entering sleep" then hibernates; wakes and reports "active"
UART settings: 57600 baud, 8 data bits, no parity, 1 stop bit
