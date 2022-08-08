#ifndef MOTORCONTROLLER_HPP
#define MOTORCONTROLLER_HPP

#include <AFMotor.h>

class MotorController {
  static constexpr float kp = 6;
  static constexpr float kd = 0.2;

  AF_DCMotor motor;
  int motor_power = 0;

  int counter = 0;
  unsigned long last_update = 0;

  int err = 0;
  int last_err = 0;
  float speed;
  float target = 0;

  float get_cm_s (int counter, float dt);
  float get_rad_s (int counter, float dt);
  float get_rpm (int counter, float dt);
  float get_speed();

public:
  MotorController(int id): motor(id) {}

  inline void increment() { ++counter; }

  void run(int dir);
  void setSpeed(float speed);
  inline float getSpeed() { return speed; }
  void update();
};

#endif
