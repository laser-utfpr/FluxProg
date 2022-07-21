#include "Infrared.hpp"
#include <Arduino.h>

int Infrared::error_table[16];
const int Infrared::pin_ir[] = { 45, 47, 49, 51 };

void Infrared::begin() {
  error_table[0b0110] = 0;
  error_table[0b0000] = 0;
  error_table[0b0100] = -(error_table[0b0010] = 1);
  error_table[0b1100] = -(error_table[0b0011] = 2);
  error_table[0b1000] = -(error_table[0b0001] = 3);
  error_table[0b1110] = -(error_table[0b0111] = 3);
  for (int i = 0; i < 4; ++i) {
    pinMode(pin_ir[i], INPUT_PULLUP);
  }
}

void Infrared::update() {
  last_value = value;
  value = 0;
  for (int i = 0; i < Sensores::n_infrared; ++i) {
    value <<= 1;
    value |= digitalRead(pin_ir[i]);
  }
}

int Infrared::read() {
  return value;
}

int Infrared::read_error() {
  return error_table[value];
}

bool Infrared::passed_intersection() {
  const bool was_last = last_value & 0b1001 == 0b1001;
  const bool is_now = value & 0b1001 != 0b0000;
  return was_last && !is_now;
}

int Infrared::read(int i) {
  if (i >= Sensores::n_infrared || i < 0) { return 0; }
  return digitalRead(pin_ir[i]);
}
