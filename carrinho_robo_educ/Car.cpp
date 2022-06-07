#include "Car.hpp"
#include <Arduino.h>

void Car::begin(void (*increment1)(), void (*increment2)()) {
  attachInterrupt(digitalPinToInterrupt(20), increment1, FALLING);
  attachInterrupt(digitalPinToInterrupt(21), increment2, FALLING);
  ir.begin();
}

void Car::update() {
  m1.update();
  m2.update();

  int err = ir.read_error();
  int s = err*kp + (err-last_err)*kd;
  inverse_kinematics(40, s);
  last_err = err;
}

void Car::stop() {
  m1.run(RELEASE);
  m2.run(RELEASE);
}

void Car::run(float s1, float s2) {
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

void Car::inverse_kinematics (float vx, float omega) {
  float forward = vx / 3.5;
  float angular = omega * 13. / 7;
  run(forward + angular, forward - angular);
}
