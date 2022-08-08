#ifndef CAR_HPP
#define CAR_HPP

#include <Ultrasonic.h>
#include "MotorController.hpp"
#include "Infrared.hpp"
#include "ColorSensor.hpp"

enum class CarState {
  Stop,
  FollowLine,
  Left,
  Right,
};

class Car {
  CarState state;
  unsigned long stime;
  unsigned long substate;

  Stream& fluxprog;
  char packet[64];
  
  MotorController& m1;
  MotorController& m2;
  Infrared& ir;
  Ultrasonic& ultrasonic;
  ColorSensor& cs1;
  ColorSensor& cs2;
  
  unsigned long last_update = 0;
  int last_err = 0;

  static constexpr float kp = .7;
  static constexpr float kd = 0;
public:
  Car(MotorController& m1, MotorController& m2, Infrared& ir, Ultrasonic& u, ColorSensor& cs1, ColorSensor& cs2, Stream& s)
  :m1(m1), m2(m2), ir(ir), ultrasonic(u), cs1(cs1), cs2(cs2), fluxprog(s) { }
  void update();

  void send_sensors();
  void setState(CarState st) { state = st; stime = 0; substate = 0; }
  
  void run(float s1, float s2);
  void inverse_kinematics(float vx, float omega);
};

#endif
