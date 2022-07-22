#include "MotorController.hpp"
#include "Config.hpp"
#include <Arduino.h>

float MotorController::get_cm_s (int counter, float dt) {
  return (1000 * Rodas::C / Encoder::k) * (counter / dt);
}

float MotorController::get_rad_s (int counter, float dt) {
  return (1000 / Encoder::k) * (counter / dt);
}

float MotorController::get_rpm (int counter, float dt) {
  return 60 * (1000 / Encoder::k) * (counter / dt);
}

void MotorController::run(int dir) {
  motor.run(dir);
}

void MotorController::setSpeed(float speed) {
  target = speed;
}

float MotorController::get_speed() {
  unsigned long now = millis();
  float dt = now - last_update;
  int last_counter = counter;
  counter = 0;
  return get_rad_s(last_counter, dt);
}

void MotorController::update() {
  unsigned long now = millis();
  if (now - last_update < 200) {
    return;
  }

  speed = get_speed();
  err = target - speed;

  motor_power += err * kp + kd * (err - last_err);
  motor_power = min(255, max(motor_power, 180));
  motor.setSpeed(motor_power);
  last_err = err;

  last_update += 200;
}
