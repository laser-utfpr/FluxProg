#include "Car.hpp"
#include "Config.hpp"
#include <Arduino.h>

void Car::send_sensors() {
  int i = 0;
  packet[i++] = '<';

  for (int j = 1 << (Sensores::n_infrared-1); j > 0; j >>= 1) {
    const int has_tape = ir.read(j) != 0;
    packet[i++] = has_tape;
  }

  const char has_obstacle = ultrasonic.convert(ultrasonic.timing(), Ultrasonic::CM) < 21;
  packet[i++] = has_obstacle;

  packet[i++] = cs1.isGreen();
  packet[i++] = cs2.isGreen();
  packet[i++] = '>';

  fluxprog.write(packet, i);
  fluxprog.flush();
}

void Car::update() {
  stime += 1;

  m1.update();
  m2.update();
  ir.update();

  switch (state) {
  case CarState::FollowLine: {
    if (ir.passed_intersection()) {
      setState(CarState::Stop);
    }
    else {
      int err = ir.read_error();
      float s = err*kp + (err-last_err)*kd;
      inverse_kinematics(5, -s);
      last_err = err;
    }
    break;
  }
  case CarState::Stop:
    run(0, 0);
    if (stime == 80) {
      send_sensors();
    }
    break;
  case CarState::Left:
    run(-5, 5);
    if (ir.falling(0b1000)) {
      setState(CarState::Stop);
    }
    break;
  case CarState::Right:
    run(5, -5);
    if (ir.falling(0b0001)) {
      setState(CarState::Stop);
    }
    break;
  }
}

void Car::run(float s1, float s2) {
  const float eps = 0.0001;
  if (s1 > eps) {
    m1.run(FORWARD);
    m1.setSpeed(s1);
  }
  else if (s1 < -eps) {
    m1.run(BACKWARD);
    m1.setSpeed(-s1);
  }
  else {
    m1.run(RELEASE);
    m1.setSpeed(0);
  }

  if (s2 > eps) {
    m2.run(FORWARD);
    m2.setSpeed(s2);
  }
  else if (s2 < -eps) {
    m2.run(BACKWARD);
    m2.setSpeed(-s2);
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
