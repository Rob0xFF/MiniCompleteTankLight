#include <board.h>

void Board::update()
{
  uint8_t length = sizeof(timeTable) / sizeof(timeTable[0]);
  updateTime();
  int16_t thisTime = 60 * now.hour() + now.minute();
  int16_t lastTime = 3000;
  int16_t lastPoint = 0;
  int16_t nextTime = 3000;
  int16_t nextPoint = 0;
  for (uint8_t i = 0; i < length; i++) {
    if (thisTime >= 60 * timeTable[i][0] + timeTable[i][1]) {
      lastTime = 60 * timeTable[i][0] + timeTable[i][1];
      lastPoint = timeTable[i][2];
    }
  }
  if (lastTime == 3000) {
    lastTime = 60 * timeTable[length - 1][0] + timeTable[length - 1][1];
    lastPoint = timeTable[length - 1][2];
  }
  for (int8_t i = length - 1; i >= 0; i--) {
    if (thisTime < 60 * timeTable[i][0] + timeTable[i][1]) {
      nextTime = 60 * timeTable[i][0] + timeTable[i][1];
      nextPoint = timeTable[i][2];
    }
  }
  if (nextTime == 3000) {
    nextTime = 60 * timeTable[0][0] + timeTable[0][1];
    nextPoint = timeTable[0][2];
  }
  float factor = 0.0;
  if (nextTime >= lastTime) { // no midnight in interval
    factor = (float) (thisTime - lastTime) / (nextTime - lastTime);
  } else {	// interval contains midnight
    if (thisTime >= lastTime) { // before midnight
      factor = (float) (thisTime - lastTime) / (nextTime + 24 * 60 - lastTime);
    } else {	// after midnight
      factor = (float) (thisTime + 24 * 60 - lastTime) / (nextTime + 24 * 60 - lastTime);
    }
  }
  uint8_t newBrightness = (uint8_t) ( lastPoint + (nextPoint - lastPoint) * factor);
  _myLED.setBrightness(newBrightness);
//  	Serial.print("Time: ");Serial.print(thisTime);
// 	Serial.print("  lastTime: ");Serial.print(lastTime);
// 	Serial.print("  lastPoint: ");Serial.print(lastPoint);
// 	Serial.print("  nextTime: ");Serial.print(nextTime);
// 	Serial.print("  nextPoint: ");Serial.print(nextPoint);
// 	Serial.print("  factor: ");Serial.print(factor);
// 	Serial.print("  newBrightness: ");Serial.println(newBrightness);
}