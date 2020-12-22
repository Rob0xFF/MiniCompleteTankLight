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
#include <ILD6070.h>

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
			clock.begin();
			clock.setDateTime(__DATE__, __TIME__);
		};

    void update();

    /*!
     * @brief update time
     */
    inline void updateTime()
    {
      dt = clock.getDateTime();
    };

  private:

    ILD6070 _myLED = ILD6070(5);

};
#endif