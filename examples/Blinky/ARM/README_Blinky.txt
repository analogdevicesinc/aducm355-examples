The 'Blinky' project is a simple program for the ADuCM355 microcontroller
using the Analog Devices EVAL-ADuCM355QSPZ board, compliant with
CMSIS-Pack/CMSIS-Core flow.

Example functionality:
 - Device: ADuCM355
 - Board: EVAL-ADuCM355QSPZ
 - LED control:
	 - Uses GPIO2.4 as output (configured in LED_Init)
	 - LED is turned ON and OFF continuously
	 - Delay is implemented using a simple software loop (delay function)
 - Console output:
	 - Prints "Hello World" repeatedly using printf
	 - Output is routed through the retarget UART component
