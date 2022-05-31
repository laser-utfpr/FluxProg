#include "Infrared.hpp"
#include <Arduino.h>

int Infrared::error_table[16];
const int Infrared::pin_ir[4] = { 45, 47, 49, 51 };

void Infrared::begin() {
  error_table[0b1110] = -7;
  error_table[0b1000] = -3;
  error_table[0b1100] = -5;
  error_table[0b0100] = -2;
  error_table[0b0110] = 0;
  error_table[0b0000] = 0;
  error_table[0b0010] = 2;
  error_table[0b0011] = 5;
  error_table[0b0001] = 3;
  error_table[0b0111] = 7;
  for (int i = 0; i < 4; ++i) {
    pinMode(pin_ir[i], INPUT_PULLUP);
  }
}

int Infrared::read_error() {
  int j = 0;
  for (int i = 0; i < 4; ++i) {
    j <<= 1;
    j |= digitalRead(pin_ir[i]);
  }
  // j = ir0 ir1 ir2 ir3
  return error_table[j];
}
