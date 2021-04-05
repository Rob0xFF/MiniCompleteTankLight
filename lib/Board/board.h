#ifndef BOARD_h
#define BOARD_h

//#define WITH_TEMP

#include "Arduino.h"
#include "Wire.h"

#include "settings.h"
#include <DS3231.h>
#ifdef WITH_TEMP
#include <OneWire.h>
#include <DallasTemperature.h>
#endif
#include <pwmDevice.h>
#include <digitalDevice.h>

class Board
{
  public:

    Board()
    {
      _light.off();
      _pump.off();
      _valve.off();
      _powerLED.on();
      _clock.begin();
#ifdef WITH_TEMP
      _tempSensor.begin();
#endif
      // uncomment to automatically set clock, you need to comment, recompile and flash again after the clock is set and running, otherwise the clock will be set to this date everytime the device is started
      //_clock.setDateTime(__DATE__, __TIME__);
    };

    void updatePush(void);

    void update();

  private:

#ifdef WITH_TEMP
    OneWire _oneWire = OneWire(17);
    DallasTemperature _tempSensor = DallasTemperature(&_oneWire);

    inline void updateTemperature()
    {
      _tempSensor.requestTemperatures();
      _temperature = _tempSensor.getTempCByIndex(0);
    };
#endif

    DS3231 _clock;
    RTCDateTime _dt;

    // check if RTC was set while summer or winter time
    uint8_t clockAtDST = 1;

    uint8_t DST = 0;

    void updateTime(void);

    PWMDevice _light = PWMDevice(5);

    DigitalDevice _pump = DigitalDevice(2);

    DigitalDevice _valve = DigitalDevice(9);

    DigitalDevice _powerLED = DigitalDevice(4);

    DigitalDevice _statusLED = DigitalDevice(8);

#ifdef WITH_TEMP
    float _temperature = DEVICE_DISCONNECTED_C;

    DigitalDevice _heater = DigitalDevice(6);
#endif

    uint8_t _status = 1;

    uint8_t length = sizeof(timeTable) / sizeof(timeTable[0]);

    int16_t elapsedMinutes;
    int16_t lastTime;
    int16_t lastPoint;
    int16_t nextTime;
    int16_t nextPoint;

    float segmentProgress;
    uint8_t newBrightness;

};
#endif