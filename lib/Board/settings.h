/*!
* @brief course of day schedule, declare each node, brightness will be interpolated in between to allow smooth ramping
* @syntax {hour[0 .. 23], minute[0 .. 59], brightness[0 .. 100]},
*/

const static uint8_t timeTable[][3] = {

  {9, 0, 0},
  {11, 0, 100},
  {18, 0, 100},	
  {20, 0, 0}

};

/*!
* @brief Temperature setPoint
* @syntax temperature[-55.0F .. 125.0F] in Celsius
*/
#ifdef WITH_TEMP
	const static float tempSetpoint = 23.5F;
#endif