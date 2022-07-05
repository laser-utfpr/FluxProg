#include <TimerOne.h>

#include "Car.hpp"
#include "Bluetooth.hpp"
#include "ColorSensor.hpp"

MotorController m1(1);
MotorController m2(2);
Infrared ir;
Ultrasonic us(33, 31);
ColorSensor cs1(40, 38, 36, 34, 42, 18);
ColorSensor cs2(50, 48, 46, 44, 52, 19);

Car car(m1, m2, ir, us, cs1, cs1);
Bluetooth bt(Serial3);

void inc_m1() { m1.increment(); }
void inc_m2() { m2.increment(); }
void inc_cs1() { cs1.intPin(); }
void inc_cs2() { cs2.intPin(); }
void int_timer() { cs1.intTimer(); cs2.intTimer(); };

void setup() {
  Serial.begin(9600);

  // Encoders
  attachInterrupt(digitalPinToInterrupt(20), inc_m1, FALLING);
  attachInterrupt(digitalPinToInterrupt(21), inc_m2, FALLING);

  ir.begin();

  cs1.begin();
  attachInterrupt(digitalPinToInterrupt(cs1.out_pin()), inc_cs1, CHANGE);
  cs2.begin();
  attachInterrupt(digitalPinToInterrupt(cs2.out_pin()), inc_cs2, CHANGE);
  
  //Timer1.setPeriod(int(0.25e6));
  Timer1.attachInterrupt(int_timer);
  
  bt.begin();
}

void loop() {
  delay(20);
  car.update();

  while (bt.available()) {
    char c = bt.read();

    if (c == 'S' || c == 's') {
      car.setState(CarState::FollowLine);
    }
    else if (c == 'P' || c == 'p') {
      car.setState(CarState::Stop);
    }
    else if (c == 'f' || c == 8) {
      car.setState(CarState::Forward);
    }
    else if (c == 4) {
      car.setState(CarState::Left);
    }
    else if (c == 6) {
      car.setState(CarState::Right);
    }
    else if (c == 'c') {
      cs1.getRawColor().print(Serial3);
      Serial3.println();
    }
  }
}
