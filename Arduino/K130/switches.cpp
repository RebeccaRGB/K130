#include <Arduino.h>
#include "switches.h"

void switches_init() {
  pinMode(SWITCH_1, INPUT_PULLUP);
  pinMode(SWITCH_2, INPUT_PULLUP);
  pinMode(SWITCH_3, INPUT_PULLUP);
  pinMode(SWITCH_4, INPUT_PULLUP);
  pinMode(SWITCH_5, INPUT_PULLUP);
  pinMode(SWITCH_6, INPUT_PULLUP);
}

unsigned char switches_read() {
  unsigned char i = 0;
  if (digitalRead(SWITCH_1)) i |= 0x01;
  if (digitalRead(SWITCH_2)) i |= 0x02;
  if (digitalRead(SWITCH_3)) i |= 0x04;
  if (digitalRead(SWITCH_4)) i |= 0x08;
  if (digitalRead(SWITCH_5)) i |= 0x10;
  if (digitalRead(SWITCH_6)) i |= 0x20;
  return i;
}
