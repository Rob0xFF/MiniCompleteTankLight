#include <board.h>

void Board::updatePush(void)
{
  _status = (_status + 1) % 3;
  update();
}

void Board::update(void)
{
  switch (_status) {
    case 0:
      _light.off();
      _pump.off();
      _heater.off();
			_heaterLED.off();
      break;
    case 1:
      updateTime();
      updateTemperature();
      elapsedMinutes = 60 * _dt.hour + _dt.minute;
      lastTime = -1;
      lastPoint = 0;
      nextTime = -1;
      nextPoint = 0;
      for (uint8_t i = 0; i < length; i++) {
        if (elapsedMinutes >= 60 * timeTable[i][0] + timeTable[i][1]) {
          lastTime = 60 * timeTable[i][0] + timeTable[i][1];
          lastPoint = timeTable[i][2];
        }
      }
      if (lastTime == -1) {
        lastTime = 60 * timeTable[length - 1][0] + timeTable[length - 1][1];
        lastPoint = timeTable[length - 1][2];
      }
      for (int8_t i = length - 1; i >= 0; i--) {
        if (elapsedMinutes < 60 * timeTable[i][0] + timeTable[i][1]) {
          nextTime = 60 * timeTable[i][0] + timeTable[i][1];
          nextPoint = timeTable[i][2];
        }
      }
      if (nextTime == -1) {
        nextTime = 60 * timeTable[0][0] + timeTable[0][1];
        nextPoint = timeTable[0][2];
      }
      segmentProgress = 0.0;
      if (nextTime >= lastTime) { // no midnight in interval
        segmentProgress = (float) (elapsedMinutes - lastTime) / (nextTime - lastTime);
      } else {	// interval contains midnight
        if (elapsedMinutes >= lastTime) { // before midnight
          segmentProgress = (float) (elapsedMinutes - lastTime) / (nextTime + 24 * 60 - lastTime);
        } else {	// after midnight
          segmentProgress = (float) (elapsedMinutes + 24 * 60 - lastTime) / (nextTime + 24 * 60 - lastTime);
        }
      }
      newBrightness = (uint8_t) ( lastPoint + (nextPoint - lastPoint) * segmentProgress);
      _light.setPercent(newBrightness);
      _pump.on();
      if (_temperature > tempSetpoint + 0.5F || _temperature == DEVICE_DISCONNECTED_C) {
        _heater.off();
				_heaterLED.off();
      } else if (_temperature < tempSetpoint - 0.5F && _temperature != DEVICE_DISCONNECTED_C) {
        _heater.on();
				_heaterLED.on();
      }
      break;
    case 2:
      _light.on();
      _pump.off();
      _heater.off();
			_heaterLED.off();
      break;
  }
}