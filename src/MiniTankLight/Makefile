PROJECT_DIR       = $(HOME)/MyArduinoProject/MiniTankLight

ARDMK_DIR         = $(PROJECT_DIR)/Makefile

ARDUINO_DIR       = /Applications/Arduino.app/Contents/Java

USER_LIB_PATH    :=  $(PROJECT_DIR)/lib

BOARD_TAG   = nano

BOARD_SUB   = atmega328

#ARDUINO_LIB_PATH = $(HOME)/Documents/Arduino/libraries

ARDUINO_LIBS = 3rdParty/TimerOne 3rdparty/DS3231 ILD6070 Wire Board

OPTIMIZATION_LEVEL = s

MONITOR_PORT      = /dev/cu.usbserial*

#MONITOR_PORT      = /dev/cu.wchusbserial1430

MONITOR_BAUDRATE  = 115200

AVR_TOOLS_DIR     = /usr/local

AVRDUDE           = /usr/local/bin/avrdude

AVRDUDE_OPTS      = -v -v

CFLAGS_STD        = -std=gnu11

CXXFLAGS_STD      = -std=gnu++17

CXXFLAGS         += -pedantic -Wall -Wextra 

LDFLAGS          += -fdiagnostics-color -Wl,-u,vfprintf -lprintf_flt -lm

CURRENT_DIR       = $(shell basename $(CURDIR))

OBJDIR            = $(PROJECT_DIR)/build/$(CURRENT_DIR)/$(BOARD_TAG)

include $(ARDMK_DIR)/Arduino.mk