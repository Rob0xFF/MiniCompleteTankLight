#include <Arduino.h>
#include <new.h>
#include <stdint.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/io.h>
#include <Wire.h>
#include <TimerOne.h>

#include "board.h"

volatile uint8_t tick = true;
#define TOCK false;
void tickTock()
{
  tick = true;
}

int atexit(void ( * /*func*/ )())
{
  return 0;
}

void initVariant() __attribute__((weak));
void initVariant() { }

int main(void)
{
  init();
  initVariant();
  Serial.begin(115200);
	Board * board;
	board = new Board();
  Timer1.initialize(10000000);
  Timer1.attachInterrupt(tickTock);
  for (;;) {
    if (tick) {
      board -> update();
      tick = TOCK;
    }
  }
  return 0;
}