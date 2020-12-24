#ifndef BOARD_h
#define BOARD_h

#include "Arduino.h"
#include "Wire.h"

#include "timetable.h"
#include <DS3231.h>
#include <pwmDevice.h>

class Board
{
  public:

    DS3231 clock;
    RTCDateTime dt;

    Board()
    {
      _light.off();
      _usbOutput.off();
      _statusLED.on();
      clock.begin();
      // uncomment to automatically set clock, you need to comment, recompile and flash again after the clock is set and running, otherwise the clock will be set to this date everytime the device is started
      // clock.setDateTime(__DATE__, __TIME__);
    };

    void updatePush(void);

    void update();

  private:

    inline void updateTime()
    {
      dt = clock.getDateTime();
    };

    PWMDevice _light = PWMDevice(5);

    PWMDevice _usbOutput = PWMDevice(2);

    PWMDevice _statusLED = PWMDevice(4);

    uint8_t _status = 0;

};
#endif