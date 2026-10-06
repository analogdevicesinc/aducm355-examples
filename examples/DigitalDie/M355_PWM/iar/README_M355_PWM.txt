The 'M355_PWM' project demonstrates how to use the AFE PWM feature on the
ADuCM355 microcontroller using the Analog Devices EVAL-ADuCM355QSPZ
evaluation board.

Example functionality:

Clock Settings:

CPU     = 26.00 MHz (HFOSC)
HCLK    = PCLK = 26 MHz

PWM0 (AGPIO2 Pin0): Toggle mode, 50% duty cycle, 2ms period
PWM1 (AGPIO2 Pin1): Match mode, 20% duty cycle, 1ms period
AFE Timer0 interrupt handler toggles P1.4 on timeout
AFE Timer1 interrupt handler toggles P1.5 on timeout
Monitor Pin17 (PWM0) and Pin18 (PWM1) of P2 on EVAL-ADuCM355QSPZ
