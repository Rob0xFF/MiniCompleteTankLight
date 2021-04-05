#include <Arduino.h>
#include <avr/wdt.h>
#include <Wire.h>
#include <TimerOne.h>

#include "board.h"

Board * board;

volatile uint8_t pushed = false;
#define IS_RELEASED false;
void btPushed()
{
	pushed = true;
}

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
  board = new Board();
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3), btPushed, FALLING);
  Timer1.initialize(5000000);
  Timer1.attachInterrupt(tickTock);
	wdt_enable(WDTO_8S);
	wdt_reset();
  for (;;) {
   	if (tick) {
      board -> update();
			wdt_reset();
      tick = TOCK;
   	}
    if (pushed) {
      board -> updatePush();
      pushed = IS_RELEASED;
    }
  }
  return 0;
}