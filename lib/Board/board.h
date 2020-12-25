#ifndef BOARD_h
#define BOARD_h

#include "Arduino.h"
#include "Wire.h"

#include "settings.h"
#include <DS3231.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <pwmDevice.h>

class Board
{
  public:

    DS3231 clock;
    RTCDateTime dt;

		OneWire oneWire = OneWire(17);
		DallasTemperature tempSensor = DallasTemperature(&oneWire);

    Board()
    {
      _light.off();
      _pump.off();
			_heater.off();
      _statusLED.on();
      clock.begin();
			tempSensor.begin();
      // uncomment to automatically set clock, you need to comment, recompile and flash again after the clock is set and running, otherwise the clock will be set to this date everytime the device is started
     // clock.setDateTime(__DATE__, __TIME__);
    };

    void updatePush(void);

    void update();

  private:

		inline void updateTemperature()
		{
			tempSensor.requestTemperatures();
			float temp = tempSensor.getTempCByIndex(0);
			if(temp != DEVICE_DISCONNECTED_C) {
				temperature = temp;
  		} 
		};

    inline void updateTime()
    {
      dt = clock.getDateTime();
    };

    PWMDevice _light = PWMDevice(5);

    PWMDevice _pump = PWMDevice(2);

		PWMDevice _heater = PWMDevice(6);

    PWMDevice _statusLED = PWMDevice(4);

		float temperature = 0.0F;

    uint8_t _status = 1;

};
#endif