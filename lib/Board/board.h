#ifndef BOARD_h
#define BOARD_h

#include <stdint.h>
#include <new.h>
#include <util/delay.h>
#include <avr/io.h>
#include "Arduino.h"
#include "Wire.h"

#include "timetable.h"
#include <DS3231.h>
#include <Timezone.h>
#include <pwmDevice.h>

/*!
 * @brief Board main class, manages the mainboard of the OLED testing device
 */
class Board
{
  public:

    DS3231 clock;
    RTCDateTime dt;

    /*!
     * @brief Board class constructor
     */
    Board()
    {
      _light.off();
      _usbOutput.off();
      _statusLED.on();
      clock.begin();
			// uncomment for first time use
      clock.setDateTime(__DATE__, __TIME__);
    };

    void updatePush(void);

    void update();

    /*!
     * @brief update time
     */
    inline void updateTime()
    {
      dt = clock.getDateTime();
    };

  private:

    PWMDevice _light = PWMDevice(5);

    PWMDevice _usbOutput = PWMDevice(2);

    PWMDevice _statusLED = PWMDevice(4);

    uint8_t _status = 0;

};
#endif