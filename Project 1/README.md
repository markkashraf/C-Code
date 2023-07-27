# High Pressure Sensor with LED Alarm

This project is a high pressure sensor that has an LED alarm that turns on for 60 seconds when it senses high pressure. The project is written in C for STM32F103C6.


## Instructions
### If you have an STM32F103C6 development board
1. Connect the high pressure sensor to the STM32F103C6 development board in PortA0->PortA7.
2. Connect the LED to the STM32F103C6 development board in PortA13 with a 100Ohm Resistor.
3. Build the project using the `make` command.
4. Burn the code to the STM32F103C6 development board.
5. When the high pressure sensor senses high pressure, the LED will turn on for 60 seconds.

### If you don't have an STM32F103C6 development board
1. Open the included circuit in protous
2. double click on the STM32F103C6 board and choose the .elf file found under `Code/bin/`.
3. click on the start simulation icon on the bottom left corner to start simulation

## Code

The code for this project is written in C. The code can be found in the `Code/` directory.

## Makefile

The `Makefile` can be used to build the project. To build the project, run the following command inside `Code/` folder:

	make

## Protous Circuit
A dummy circuit to test the project can be found in `Protous Project/`.

## Authors
Protous project and drivers were written by Eng. Kerolos Shenoda, everything else was written by me.
This project was created under supervision of Eng. Kerolos Shenoda.
