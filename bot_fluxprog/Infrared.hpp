#ifndef INFRARED_HPP
#define INFRARED_HPP

#include <Arduino.h>
#include "Config.hpp"

class Infrared {
  static const int pin_ir[Sensores::n_infrared];
  static int error_table[16];
  int last_value;
  int value;
public:
  void begin();
  void update();
  inline int read() { return value; }
  inline int read_error() { return error_table[value]; }
  inline bool passed_intersection() {
    const bool was_last = last_value & 0b1001 == 0b1001;
    const bool is_now = value & 0b1001 != 0b0000;
    return was_last && !is_now;
  }
  inline int read(int mask) { return value & mask; }
  inline int rising(int mask) {
    const bool last_down = !(last_value & mask);
    const bool now_up = value & mask;
    return last_down && now_up;
  }
  inline int falling(int mask) {
    const bool last_up = last_value & mask;
    const bool now_down = !(value & mask);
    return last_up && now_down;
  }
};

#endif
