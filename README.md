# MiniTankLight

This is a replacement PCB for the [Mini Complete Tank](https://minicompletetank.com) aquarium light. It fits right into the original housing, the original LED PCB is maintained.

![PCB](https://github.com/Rob0xFF/MiniTankLight/raw/main/pcb.jpg)

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
