#include <Arduino.h>
#include <util/delay.h>
#include "matrix.h"

void pinModeJ3(unsigned char mode) {
  pinMode(J3_1, mode);
  pinMode(J3_2, mode);
  pinMode(J3_3, mode);
  pinMode(J3_4, mode);
  pinMode(J3_5, mode);
  pinMode(J3_6, mode);
  pinMode(J3_7, mode);
  pinMode(J3_8, mode);
  pinMode(J3_9, mode);
  pinMode(J3_10, mode);
  pinMode(J3_11, mode);
}

void pinModeJ4(unsigned char mode) {
  pinMode(J4_1, mode);
  pinMode(J4_2, mode);
  pinMode(J4_3, mode);
  pinMode(J4_4, mode);
  pinMode(J4_5, mode);
  pinMode(J4_6, mode);
  pinMode(J4_7, mode);
  pinMode(J4_8, mode);
  pinMode(J4_9, mode);
  pinMode(J4_10, mode);
  pinMode(J4_11, mode);
  pinMode(J4_12, mode);
}

unsigned int digitalReadJ3() {
  unsigned int i = 0;
  if (digitalRead(J3_1 )) i |= 0x0001;
  if (digitalRead(J3_2 )) i |= 0x0002;
  if (digitalRead(J3_3 )) i |= 0x0004;
  if (digitalRead(J3_4 )) i |= 0x0008;
  if (digitalRead(J3_5 )) i |= 0x0010;
  if (digitalRead(J3_6 )) i |= 0x0020;
  if (digitalRead(J3_7 )) i |= 0x0040;
  if (digitalRead(J3_8 )) i |= 0x0080;
  if (digitalRead(J3_9 )) i |= 0x0100;
  if (digitalRead(J3_10)) i |= 0x0200;
  if (digitalRead(J3_11)) i |= 0x0400;
  return i;
}

unsigned int digitalReadJ4() {
  unsigned int i = 0;
  if (digitalRead(J4_1 )) i |= 0x0001;
  if (digitalRead(J4_2 )) i |= 0x0002;
  if (digitalRead(J4_3 )) i |= 0x0004;
  if (digitalRead(J4_4 )) i |= 0x0008;
  if (digitalRead(J4_5 )) i |= 0x0010;
  if (digitalRead(J4_6 )) i |= 0x0020;
  if (digitalRead(J4_7 )) i |= 0x0040;
  if (digitalRead(J4_8 )) i |= 0x0080;
  if (digitalRead(J4_9 )) i |= 0x0100;
  if (digitalRead(J4_10)) i |= 0x0200;
  if (digitalRead(J4_11)) i |= 0x0400;
  if (digitalRead(J4_12)) i |= 0x0800;
  return i;
}

void digitalWriteJ3(unsigned int i) {
  digitalWrite(J3_1,  (i & 0x0001) ? HIGH : LOW);
  digitalWrite(J3_2,  (i & 0x0002) ? HIGH : LOW);
  digitalWrite(J3_3,  (i & 0x0004) ? HIGH : LOW);
  digitalWrite(J3_4,  (i & 0x0008) ? HIGH : LOW);
  digitalWrite(J3_5,  (i & 0x0010) ? HIGH : LOW);
  digitalWrite(J3_6,  (i & 0x0020) ? HIGH : LOW);
  digitalWrite(J3_7,  (i & 0x0040) ? HIGH : LOW);
  digitalWrite(J3_8,  (i & 0x0080) ? HIGH : LOW);
  digitalWrite(J3_9,  (i & 0x0100) ? HIGH : LOW);
  digitalWrite(J3_10, (i & 0x0200) ? HIGH : LOW);
  digitalWrite(J3_11, (i & 0x0400) ? HIGH : LOW);
}

void digitalWriteJ4(unsigned int i) {
  digitalWrite(J4_1,  (i & 0x0001) ? HIGH : LOW);
  digitalWrite(J4_2,  (i & 0x0002) ? HIGH : LOW);
  digitalWrite(J4_3,  (i & 0x0004) ? HIGH : LOW);
  digitalWrite(J4_4,  (i & 0x0008) ? HIGH : LOW);
  digitalWrite(J4_5,  (i & 0x0010) ? HIGH : LOW);
  digitalWrite(J4_6,  (i & 0x0020) ? HIGH : LOW);
  digitalWrite(J4_7,  (i & 0x0040) ? HIGH : LOW);
  digitalWrite(J4_8,  (i & 0x0080) ? HIGH : LOW);
  digitalWrite(J4_9,  (i & 0x0100) ? HIGH : LOW);
  digitalWrite(J4_10, (i & 0x0200) ? HIGH : LOW);
  digitalWrite(J4_11, (i & 0x0400) ? HIGH : LOW);
  digitalWrite(J4_12, (i & 0x0800) ? HIGH : LOW);
}

void matrix_init() {
  pinModeJ3(OUTPUT);
  pinModeJ4(INPUT_PULLUP);
}

static void matrix_read_raw(unsigned char * state) {
  unsigned int i, j3m, p, j4m;
  unsigned char mask;

  for (i = 0; i < MTX_STATE_SIZE; i++) state[i] = 0;

  digitalWriteJ3(-1);
  _delay_us(MTX_PROP_DELAY);

  for (i = 0, mask = 1, j3m = 0x0400; j3m; j3m >>= 1) {
    digitalWriteJ3(~j3m);
    _delay_us(MTX_PROP_DELAY);
    p = ~digitalReadJ4();
    for (j4m = 0x0800; j4m; j4m >>= 1) {
      if (p & j4m) state[i] |= mask;
      if ((mask <<= 1)) continue;
      i++; mask = 1;
    }
  }

  digitalWriteJ3(-1);
  _delay_us(MTX_PROP_DELAY);
}

static unsigned char matrix_xor(unsigned char * state1, unsigned char * state2) {
  unsigned char m = 0;
  for (unsigned int i = 0; i < MTX_STATE_SIZE; i++) {
    m |= state1[i] ^ state2[i];
  }
  return m;
}

void matrix_read(unsigned char * state) {
  unsigned char state1[MTX_STATE_SIZE];
  unsigned char state2[MTX_STATE_SIZE];
  matrix_read_raw(state1);
  matrix_read_raw(state2);
  while (matrix_xor(state1, state2)) {
    matrix_read_raw(state1);
    matrix_read_raw(state2);
  }
  for (unsigned int i = 0; i < MTX_STATE_SIZE; i++) {
    state[i] = state1[i];
  }
}

static unsigned char lastState[MTX_STATE_SIZE] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
static unsigned int packetBuffer[MTX_BUFFER_SIZE];
static unsigned int packetBufStart = 0;
static unsigned int packetBufEnd = 0;

static void matrix_write_packet(unsigned int packet) {
  packetBuffer[packetBufEnd] = packet;
  packetBufEnd++;
  packetBufEnd &= (MTX_BUFFER_SIZE-1);
  if (packetBufEnd == packetBufStart) {
    // Buffer overflow. Ignore input.
    packetBufEnd--;
    packetBufEnd &= (MTX_BUFFER_SIZE-1);
  }
}

unsigned int matrix_read_packet() {
  unsigned char nextState[MTX_STATE_SIZE];
  unsigned char released[MTX_STATE_SIZE];
  unsigned char pressed[MTX_STATE_SIZE];
  unsigned char changed = 0;
  unsigned int packet;
  unsigned int i;
  unsigned char m;

  matrix_read(nextState);
  for (i = 0; i < MTX_STATE_SIZE; i++) {
    released[i] = lastState[i] &~ nextState[i];
    pressed[i] = nextState[i] &~ lastState[i];
    changed |= released[i] | pressed[i];
    lastState[i] = nextState[i];
  }

  for (packet = 0, i = 0; i < MTX_STATE_SIZE; i++) {
    for (m = 1; m != 0; m <<= 1, packet++) {
      if (released[i] & m) matrix_write_packet(MTX_RELEASED | packet);
      if (pressed[i] & m) matrix_write_packet(MTX_PRESSED | packet);
    }
  }

  if (changed) delay(MTX_DEBOUNCE_TIME);

  if (packetBufStart == packetBufEnd) return 0;
  packet = packetBuffer[packetBufStart];
  packetBufStart++;
  packetBufStart &= (MTX_BUFFER_SIZE-1);
  return packet;
}
