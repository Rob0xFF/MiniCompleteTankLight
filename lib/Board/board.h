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
    /*!
     * @brief Board class constructor
     */
    Board() {};

    /*!
     * @brief update time
     */
    inline void updateTime()  {now = _myRTC.now();};

    void update();

    DateTime now;
    // create instances for the clock
    DS3231 _myClock;
    RTClib _myRTC; // now

  private:

		ILD6070 _myLED = ILD6070(5);

};
#endif