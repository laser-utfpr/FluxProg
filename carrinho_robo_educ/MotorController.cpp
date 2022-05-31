#include "MotorController.hpp"
#include <Arduino.h>

float MotorController::get_cm_s (int counter, float dt) { return (1000 * circunferencia / resolucao) * (counter / dt); }
float MotorController::get_rad_s (int counter, float dt) { return (1000 / resolucao) * (counter / dt); }
float MotorController::get_rpm (int counter, float dt) { return 60 * (1000 / resolucao) * (counter / dt); }

void MotorController::run(int dir) { 
  motor.run(dir); 
}

void MotorController::setSpeed(float speed) {
  target = speed; 
}

float MotorController::get_speed() {
  now = millis();
  dt = now - last_time;
  last_time = now;
  
  last_counter = counter;
  counter = 0;
  return get_rad_s(last_counter, dt);
}

void MotorController::pid() {
  speed = get_speed();
  err = target - speed;

  motor_power += err*kp + kd*(err-last_err);
  motor_power = min(255, max(motor_power, 0));
  motor.setSpeed(motor_power);
  last_err = err;
}
