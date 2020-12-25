# MiniCompleteTankLight

This is a replacement PCB for the [Mini Complete Tank](https://minicompletetank.com) aquarium light. It fits right into the original housing, the original LED PCB is maintained. Please do not put fish in this tiny tank!

![Foto](https://raw.githubusercontent.com/Rob0xFF/MiniTankLight/main/5400F30C-6FEE-497C-8EF1-8330CC151183.jpeg?token=AGGZRCXBJ7CXHUGPIYD3CDS74SI64)

## Features

* schedule any lighting profile with smooth sunrise and sunset, hardcoded at compile time
* support for chinese external 5W usb heater (use only 5V DC / 5W heater) and Sparkfun DS18B20 water-proof temperature sensor
* temperature setpoint, hardcoded at compile time
* toggle between 3 states using the built-in push button:
  1. idle -> light off, external heater/pump off
  2. profile run -> light profile on, external heater/pump on (device boots to this state)
  3. maintenance -> full light on, external heater/pump off
* CR2032 battery / LIR2032 accumulator buffered real time clock
* Arduino compatible flashing using USB

## Configuration

* edid lib/Board/settings.h in order to fit your needs
* each node of the lighting profile must be defined seperatly
* define the temperature setpoint

## Build

The build environment originates from the Bare-Arduino-Project by ladislas and the awesome makefile templates provided by sudar.

In order to build, follow the steps provided here:

https://github.com/ladislas/Bare-Arduino-Project

https://github.com/sudar/Arduino-Makefile

Individual Makefile is located besides the main.cpp file. This might be edited to fit your environment.

You might also manually add the libraries to your Arduino installation and compile/flash using the Arduino IDE.

# PCB

## Manufacturing

The PCB might be manufactured by means of the photo-positive-method, this is the way I do it. Alternativly, there are several commercial PCB services out there.

While soldering, the CHR bridge must be left open, if a non rechargable CR2032 battery is used. It should be closed to allow charging if the LIR2032 accumulator is used. Charging is then controlled via U5.

The Atmega microcontroller should be preloaded with the Arduino bootloader before soldering. Nevertheless, in system programming is possible via a pogo pin ISP adaptor and a programmer.
