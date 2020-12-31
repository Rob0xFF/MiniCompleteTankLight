/*!
* @brief course of day schedule, declare each node, brightness will be interpolated in between to allow smooth ramping
* @syntax {hour[0 .. 23], minute[0 .. 59], brightness[0 .. 100]},
*/

const static uint8_t timeTable[][3] = {

  {11, 00, 0},
  {12, 00, 75},
  {18, 30, 75},
  {19, 30, 0}

};

/*!
* @brief Temperature setPoint
* @syntax temperature[-55.0 .. 125.0] in Celsius
*/

const static float tempSetpoint = 23.0F;