#include <Arduino.h>
#include <new.h>
#include <stdint.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/io.h>
#include <Wire.h>
#include <TimerOne.h>

#include "board.h"

Board * board;

const uint32_t maxPushDuration = 25000;
volatile uint32_t pushDuration = 0;
volatile uint32_t pushStart = 0;
volatile uint32_t counter = 0;
volatile uint8_t pushed = false;


#define IS_RELEASED false;
void btPushed()
{
//   if (counter == 0) {
//     pushStart = micros();
//     pushed = true;
//   } else {
//     pushDuration = micros() - pushStart;
//     if (pushDuration > maxPushDuration) {
//       pushed = true;
//       counter = 0;
//       return;
//     }
//   }
//   counter ++;
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
  Serial.begin(115200);
  board = new Board();
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3), btPushed, FALLING);
  Timer1.initialize(10000000);
  Timer1.attachInterrupt(tickTock);
  for (;;) {
    if (tick) {
      board -> update();
      tick = TOCK;
    }
    if (pushed) {
      board -> updatePush();
      pushed = IS_RELEASED;
    }
  }
  return 0;
}