# MiniCompleteTankLight

This is a replacement PCB for the [Mini Complete Tank](https://minicompletetank.com) aquarium light. It fits right into the original housing, the original LED PCB is maintained. Please do not put fish in this tiny tank!

![Foto](https://raw.githubusercontent.com/Rob0xFF/MiniTankLight/main/5400F30C-6FEE-497C-8EF1-8330CC151183.jpeg?token=AGGZRCXBJ7CXHUGPIYD3CDS74SI64)

## Features

* schedule any lighting profile with smooth sunrise and sunset, hardcoded at compile time
* support for chinese external 5W usb heater (use only 5V DC / 5W heater) and Sparkfun DS18B20 water-proof temperature sensor
* temperature setpoint, hardcoded at compile time
* toggle between 3 states using the built-in push button:
  1. idle -> light off, external heater/pump off
  2. profile run -> light profile on, external heater/pump on
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

# PCB

## Manufacturing

The PCB might be manufactured by means of the photo-positive-method, this is the way I do it. Alternativly, there are several commercial PCB services out there.

While soldering, the CHR bridge must be left open, if a non rechargable CR2032 battery is used. It should be closed to allow charging if the LIR2032 accumulator is used. Charging is then controlled via U5.

The Atmega microcontroller should be preloaded with the Arduino bootloader before soldering. Nevertheless, in system programming is possible via a pogo pin ISP adaptor and a programmer.

## BOM

No	Name	Value	Package	Comment

1	BAT1	CR 2032 / LIR2032	---	EAN: 2050000478314

2	C1	100n	0603

3	C2	100n	0805	

4	C3	100n	0805	

5	C4	100n	0805	

6	C5	100n	0805	

7	C6	22p	0402	

8	C7	100n	0805	

9	C8	100n	0805	

10	C9	100n	0603	

11	C10	22p	0402	

12	C11	100n	0603	

13	C12	4.7µ	1206	

14	C13	4.7µ	1206	

15	C14	4.7µ	---	

16	D1		---	CD0603-B0240R

17	J1		---	609-5379-1-ND

18	J2		---	

19	J3		---	

20	L1	1H	0805	

21	L2	6.8µ	---	

22	LED1	rt	0603	

23	R1	10k	0805	

24	R2	4.7k	0603	

25	R3	4.7k	0603	

26	R4		0603	

27	R5	180m	---	

28	R6	56k	0603	

29	R7	10k	0603	

30	R8	330	0603	

31	R9	10k	0603	

32	R10	390	0805	

33	U1	FT232RL	---	

34	U2	Atmega328P-AU	TQFP-32 (7x7)	

35	U3	ILD6070	---	

36	U4	DS3231H	---	

37	U5	MCP73832T-2ACI/OTCT-ND	---	

38	U6	4N33	---	

39	X1	16MHz	---	Q 16,0-JXS21-12-10/15-T1-WA-LF
