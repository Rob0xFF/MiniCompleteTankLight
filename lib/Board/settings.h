/*!
* @brief course of day schedule, declare each node, brightness will be interpolated in between to allow smooth ramping
* @syntax {hour[0-23], minute[0-59], brightness[0-100]},
*/

const static uint8_t timeTable[][3] = {

  {11, 00, 0},
  {12, 00, 75},
  {18, 00, 75},
  {19, 00, 0}

};

/*!
* @brief Temperature setPoint
* @syntax temperature[x.xF]
*/

const static float tempSetpoint = 24.0F;