# ADuCM355 Examples
The [ADuCM355](https://www.analog.com/en/products/aducm355.html) is Analog Devices latest high precision impedance and electrochemical SiP (System in Package) 

This repository provides a comprehensive selection of block level and application level examples which can be used directly in new project. 

# Useful links
* [ADuCM355 Product Page](https://www.analog.com/en/products/aducm355.html)
* [ADuCM355 Datasheet](https://www.analog.com/media/en/technical-documentation/data-sheets/ADuCM355.pdf)
* [ADuCM355 FAQ](https://ez.analog.com/analog-microcontrollers/precision-microcontrollers/w/documents/14004/aducm355-faq)
* [ADuCM355 Hardware Reference Manual](https://www.analog.com/media/en/technical-documentation/user-guides/ADuCM355-Hardware-Reference-Manual-UG-1262.pdf)
* [EVAL-ADuCM355](https://www.analog.com/en/design-center/evaluation-hardware-and-software/evaluation-boards-kits/EVAL-ADuCM355.html)


# How to Use it
Firstly, checkout the repository using below command. Make sure you have cloned the [ad5940lib](https://github.com/analogdevicesinc/ad5940lib) submodule which these examples are based on.

> git clone --recursive https://github.com/analogdevicesinc/aducm355-examples.git

If you are downloading code from web browser, it won't automatically download folder examples/ad5940lib, please download it manually from [ad5940lib](https://github.com/analogdevicesinc/ad5940lib) and extract it to examples/ad5940lib. The AD5940Lib is shared between the AD5940, AD5941 and ADuCM355 which all have the same AFE.

The final file structure should be:

```
aducm355-examples\common\ad5940lib\ad5940.c
aducm355-examples\common\ad5940lib\ad5940.h
aducm355-examples\common\ARM
aducm355-examples\common\IAR
aducm355-examples\examples\AnalogDie
aducm355-examples\examples\ApplicationExamples
aducm355-examples\examples\DigitalDie
aducm355-examples\inc\
aducm355-examples\LICENSE...
aducm355-examples\README.md...
```

To run the example code, you need the ADuCM355 evaluation board, and the software development IDE like IAR or [Keil](http://www.keil.com).

**Both Keil and IAR are verified on all examples**


## Hardware
[EVAL-ADuCM355](https://www.analog.com/en/design-center/evaluation-hardware-and-software/evaluation-boards-kits/EVAL-ADuCM355.html) is the support evaluation board for the ADuCM355 
![pic](https://www.analog.com/-/media/analog/en/evaluation-board-images/images/eval-aducm355qspzangle-web.gif?h=270&thn=1&hash=972EEA9E63C2CE4220CED0C30F635B2D53F7CBBE)


# License
Copyright (c) 2017-2019 Analog Devices, Inc. All Rights Reserved.
