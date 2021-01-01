#ifndef BOARD_h
#define BOARD_h

#include "Arduino.h"
#include "Wire.h"

#include "settings.h"
#include <DS3231.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <pwmDevice.h>
#include <digitalDevice.h>

class Board
{
  public:

    Board()
    {
			_light.off();
      _pump.off();
      _heater.off();
      _powerLED.on();
      _clock.begin();
      _tempSensor.begin();
      // uncomment to automatically set clock, you need to comment, recompile and flash again after the clock is set and running, otherwise the clock will be set to this date everytime the device is started
      //_clock.setDateTime(__DATE__, __TIME__);
    };

    void updatePush(void);

    void update();

  private:

    OneWire _oneWire = OneWire(17);
    DallasTemperature _tempSensor = DallasTemperature(&_oneWire);

    inline void updateTemperature()
    {
      _tempSensor.requestTemperatures();
      _temperature = _tempSensor.getTempCByIndex(0);
    };

    DS3231 _clock;
    RTCDateTime _dt;

    inline void updateTime()
    {
      _dt = _clock.getDateTime();
    };

    PWMDevice _light = PWMDevice(5);

    DigitalDevice _pump = DigitalDevice(2);

    DigitalDevice _heater = DigitalDevice(9);

    DigitalDevice _powerLED = DigitalDevice(6);

    DigitalDevice _heaterLED = DigitalDevice(4);

    float _temperature = DEVICE_DISCONNECTED_C;

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