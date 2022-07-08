#include "Car.hpp"
#include "Config.hpp"
#include <Arduino.h>

void Car::read_sensors(char packet[64]) {
  int i = 0;
  packet[i++] = '<';

  for (int j = 0; j < Sensores::n_infrared; ++j) {
    const int has_tape = ir.read(j) != 0;
    packet[i++] = has_tape;
  }

  const char has_obstacle = ultrasonic.convert(ultrasonic.timing(), Ultrasonic::CM) < 21;
  packet[i++] = has_obstacle;

  packet[i++] = '>';
  Serial3.write(packet, i);
  Serial3.flush();
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
      char p[64]; read_sensors(p);

      setState(CarState::Stop);
    }
    break;
  case CarState::Left:
    inverse_kinematics(0, 10);
    if (stime > 17) {
      char p[64]; read_sensors(p);

      setState(CarState::Stop);
    }
    break;
  case CarState::Right:
    inverse_kinematics(0, -10);
    if (stime > 17) {
      char p[64]; read_sensors(p);

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
