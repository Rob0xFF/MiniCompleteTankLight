#ifndef ILD6070_h
#define ILD6070_h

#include <stdint.h>
#include <new.h>
#include <util/delay.h>
#include <avr/io.h>
#include "Arduino.h"

/*!
 * @brief Board main class, manages the mainboard of the OLED testing device
 */
class ILD6070
{
  public:
    /*!
     * @brief ILD6070 class constructor
     */
    ILD6070(uint8_t ctlPin);

    void setBrightness(uint8_t setPoint);

    void off(void);

  private:

    uint8_t _brightness = 0;

    const uint8_t _controlPin;

};
#endif