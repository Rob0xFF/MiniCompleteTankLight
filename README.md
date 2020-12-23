# MiniTankLight

This is a replacement PCB for the [Mini Complete Tank](https://minicompletetank.com) aquarium light. It fits right into the original housing, the original LED PCB is maintained.

## Features

* schedule any lighting profile with smooth sunrise and sunset, this is hardcoded at compile time
* toggle between 3 states using the built-in push button:
  1. idle -> light off, external USB off
  2. profile run -> light profile on, external USB on
  3. maintenance -> full light on, external USB off
* CR2032 battery / LIR2032 accumulator buffered real time clock
* Arduino compatible flashing using USB

## Configuration

* edid lib/Board/timetable.h in order to fit your needs
* each node must be defined seperatly

## Build

The build environment originates from the Bare-Arduino-Project by ladislas and the awesome makefile templates provided by sudar.

In order to build, follow the steps provided here:

https://github.com/ladislas/Bare-Arduino-Project

https://github.com/sudar/Arduino-Makefile

Individual Makefiles are located besides the main.cpp files. In order to use all pins of the Atmega2560, not only those broken out on Arduino Boards, we rely on the Core files provided by MCUDude:

https://github.com/MCUdude/MegaCore

Additionally, we will need to manually add placement new to the core files, because for some reason this is not included in the original distribution.
