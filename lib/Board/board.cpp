#include <board.h>

void Board::updatePush(void)
{
  if (_status == 0) {
    _status = 1;
  } else if (_status == 1) {
    _status = 2;
  } else if (_status == 2) {
    _status = 0;
  }
  update();
}

void Board::update(void)
{
  if (_status == 0) {
    _light.off();
    _pump.off();
		_heater.off();
  } else if (_status == 1) {
    updateTime();
    updateTemperature();
		Serial.println(temperature);
    uint8_t length = sizeof(timeTable) / sizeof(timeTable[0]);
    int16_t elapsedMinutes = 60 * dt.hour + dt.minute;
    int16_t lastTime = -1;
    int16_t lastPoint = 0;
    int16_t nextTime = -1;
    int16_t nextPoint = 0;
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
    float segmentProgress = 0.0;
    if (nextTime >= lastTime) { // no midnight in interval
      segmentProgress = (float) (elapsedMinutes - lastTime) / (nextTime - lastTime);
    } else {	// interval contains midnight
      if (elapsedMinutes >= lastTime) { // before midnight
        segmentProgress = (float) (elapsedMinutes - lastTime) / (nextTime + 24 * 60 - lastTime);
      } else {	// after midnight
        segmentProgress = (float) (elapsedMinutes + 24 * 60 - lastTime) / (nextTime + 24 * 60 - lastTime);
      }
    }
    uint8_t newBrightness = (uint8_t) ( lastPoint + (nextPoint - lastPoint) * segmentProgress);
    _light.setPercent(newBrightness);
    _pump.on();
		if(temperature > tempSetpoint + 0.5F) {
			_heater.off();
		} 
		else if(temperature < tempSetpoint - 0.5F) {
			_heater.on();
		}
  } else if (_status == 2) {
    _light.on();
    _pump.off();
		_heater.off();
  }
}