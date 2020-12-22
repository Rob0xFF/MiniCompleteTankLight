#include <ILD6070.h>


ILD6070::ILD6070(uint8_t ctlPin) : _controlPin(ctlPin)
{
	pinMode(_controlPin, OUTPUT);
  off();
}

void ILD6070::setBrightness(uint8_t setPoint)
{
  _brightness = map(setPoint, 0, 100, 0, 255);
	analogWrite(_controlPin, _brightness);
}

void ILD6070::off(void)
{
	_brightness = 0;
  digitalWrite(_controlPin, LOW);
}