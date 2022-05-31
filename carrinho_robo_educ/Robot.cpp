#include "Robot.hpp"
#include <Arduino.h>

void Robot::begin(void (*increment1)(), void (*increment2)()) {
  attachInterrupt(digitalPinToInterrupt(20), increment1, FALLING);
  attachInterrupt(digitalPinToInterrupt(21), increment2, FALLING);
  ir.begin();
}

void Robot::update() {
  unsigned long now = millis();
  if (now - last_update >= 200) {
    last_update = now;
    m1.pid();
    m2.pid();
  }

  static const float kp = 8;
  static const float ki = 0;
  static const float kd = 0;
  static int last_err = 0;
  static float p = 0, i = 0, d = 0;
  
  int err = ir.read_error();

  p = err;
  i = i + err;
  d = err - last_err;
  last_err = err;

  int s = p*kp + i*ki + d*kd;

  inverse_kinematics(40, s);
}

void Robot::run(float s1, float s2) {
  if (s1 >= 0) {
    m1.run(FORWARD);
    m1.setSpeed(min(s1, 255));
  }
  else {
    m1.run(BACKWARD);
    m1.setSpeed(min(-s1, 255));
  }

  if (s2 >= 0) {
    m2.run(FORWARD);
    m2.setSpeed(min(s2, 255));
  }
  else {
    m2.run(BACKWARD);
    m2.setSpeed(min(-s2, 255));
  }
}

void Robot::inverse_kinematics (float vx, float omega) {
  float forward = vx / 3.5;
  float angular = omega * 13. / 7;
  run(forward + angular, forward - angular);
}
