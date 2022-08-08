#ifndef COLOUR_SENSOR
#define COLOUR_SENSOR

#include "ColorData.hpp"

class ColorSensor {
public:
  ColorSensor(int s0, int s1, int s2, int s3, int oe, int out)
  : s0{s0}, s1{s1}, s2{s2}, s3{s3}, oe{oe}, out{out} { }
  inline void intPin() { counter += 4; }
  inline void intTimer() {
    selColor(sel);
    value[sel] = counter;
    counter = 0;
    sel = next(sel);
  }

  inline const int out_pin() { return out; }

  void begin() {
    pinMode(s0, OUTPUT);
    pinMode(s1, OUTPUT);
    pinMode(s2, OUTPUT);
    pinMode(s3, OUTPUT);
    pinMode(oe, OUTPUT);
    pinMode(out, INPUT);

    // Select freq
    digitalWrite(s0, HIGH);
    digitalWrite(s1, LOW);
  }

  const Color& getColor() {
    int d_black = euc_dist(value, black);
    int d_white = euc_dist(value, white);
    int d_green = euc_dist(value, green);

    int m = min(d_black, min(d_white, d_green));
    if (m == d_black) return black;
    if (m == d_white) return white;
    return green;
  }

  bool isGreen() { return getColor() == green; }

  Color getRawColor() { return value; }

private:
  Color black{20, 50, 10, 20};
  Color white{72, 220, 75, 85};
  Color green{40, 130, 40, 50};
  Color value;

  const int s0, s1, s2, s3;
  const int oe;
  const int out;

  int counter = 0;
  ColorSelector sel = ColorSelector::R;
  void selColor(ColorSelector sel) {
    digitalWrite(s2, msb(sel));
    digitalWrite(s3, lsb(sel));
  }
};

#endif
