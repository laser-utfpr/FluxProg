#ifndef INFRARED_HPP
#define INFRARED_HPP

class Infrared {
  static const int pin_ir[4];
  static int error_table[16];
public:
  void begin();
  int read_error();
};

#endif
