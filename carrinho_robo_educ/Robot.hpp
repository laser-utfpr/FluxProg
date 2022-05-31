#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "MotorController.hpp"
#include "Infrared.hpp"

class Robot {
  MotorController m1{1};
  MotorController m2{2};
  Infrared ir;
  unsigned long last_update = 0;
  int last_err = 0;

  static constexpr float kp = 8;
  static constexpr float kd = 0;
public:
  void begin(void (*increment1)(), void (*increment2)());
  void update();

  void increment1() { m1.increment(); }
  void increment2() { m2.increment(); }

  void run(float s1, float s2);
  void inverse_kinematics(float vx, float omega);
};

#endif
