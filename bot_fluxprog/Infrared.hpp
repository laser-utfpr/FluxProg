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
  int read();
  int read_error();
  bool passed_intersection();
  int read(int i);
};

#endif
