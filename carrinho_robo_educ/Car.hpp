#ifndef CAR_HPP
#define CAR_HPP

#include "MotorController.hpp"
#include "Infrared.hpp"

enum class CarState {
  Stop,
  FollowLine,
  Forward,
  Left,
  Right,
};

class Car {
  CarState state;
  unsigned long stime;
  
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

  void setState(CarState st) { state = st; stime = 0; }
  
  void run(float s1, float s2);
  void inverse_kinematics(float vx, float omega);
};

#endif
