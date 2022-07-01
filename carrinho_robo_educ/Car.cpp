#include "Car.hpp"
#include "Config.hpp"
#include <Arduino.h>

void Car::begin(void (*increment1)(), void (*increment2)()) {
  attachInterrupt(digitalPinToInterrupt(20), increment1, FALLING);
  attachInterrupt(digitalPinToInterrupt(21), increment2, FALLING);
  ir.begin();
}

void Car::read_sensors(char packet[15]) {
  int i = 0;
  char has_obstacle = ultrasonic.convert(ultrasonic.timing(), Ultrasonic::CM) < 20? 0: 0xFF;
  while (i++ < 5) {
    packet[i] = ir.read(i);
  }
  while (i++ < 15) {
    packet[i] = 0;
  }
  packet[9] = has_obstacle;
  packet[10] = has_obstacle;
}


void Car::update() {
  stime += 1;

  m1.update();
  m2.update();

  switch (state) {
  case CarState::FollowLine: {
    int err = ir.read_error();
    int s = err*kp + (err-last_err)*kd;
    inverse_kinematics(20, -s);
    last_err = err;
    break;
  }
  case CarState::Stop:
    run(0, 0);
    break;
  case CarState::Forward:
    inverse_kinematics(20, 0);
    if (stime > 100) {
      setState(CarState::Stop);
    }
    break;
  case CarState::Left:
    inverse_kinematics(0, 10);
    if (stime > 17) {
      setState(CarState::Stop);
    }
    break;
  case CarState::Right:
    inverse_kinematics(0, -10);
    if (stime > 17) {
      setState(CarState::Stop);
    }
    break;
  }
}

void Car::run(float s1, float s2) {
  if (s1 > 0) {
    m1.run(FORWARD);
    m1.setSpeed(min(s1, 255));
  }
  else if (s1 < 0) {
    m1.run(BACKWARD);
    m1.setSpeed(min(-s1, 255));
  }
  else {
    m1.run(RELEASE);
    m1.setSpeed(0);
  }

  if (s2 > 0) {
    m2.run(FORWARD);
    m2.setSpeed(min(s2, 255));
  }
  else if (s2 < 0) {
    m2.run(BACKWARD);
    m2.setSpeed(min(-s2, 255));
  }
  else {
    m2.run(RELEASE);
    m2.setSpeed(0);
  }
}

void Car::inverse_kinematics (float vx, float omega) {
  float forward = vx / Rodas::r;
  float angular = omega * Rodas::L / Rodas::r;
  run(forward - angular, forward + angular);
}
