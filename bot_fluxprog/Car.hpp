#ifndef CAR_HPP
#define CAR_HPP

#include <Ultrasonic.h>
#include "MotorController.hpp"
#include "Infrared.hpp"
#include "Bluetooth.hpp"
#include "ColorSensor.hpp"

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
  
  MotorController& m1;
  MotorController& m2;
  Infrared& ir;
  Ultrasonic& ultrasonic;
  ColorSensor& cs1;
  ColorSensor& cs2;
  
  unsigned long last_update = 0;
  int last_err = 0;

  static constexpr float kp = 2;
  static constexpr float kd = 0;
public:
  Car(MotorController& m1, MotorController& m2, Infrared& ir, Ultrasonic& ultrasonic, ColorSensor& cs1, ColorSensor& cs2)
  :m1(m1), m2(m2), ir(ir), ultrasonic(ultrasonic), cs1(cs1), cs2(cs2) { }
  void update();

  void read_sensors(char packet[15]);
  void setState(CarState st) { state = st; stime = 0; }
  
  void run(float s1, float s2);
  void inverse_kinematics(float vx, float omega);
};

#endif
