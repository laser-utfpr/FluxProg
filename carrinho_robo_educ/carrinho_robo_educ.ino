#include "Robot.hpp"

Robot robot;
void increment1() { robot.increment1(); }
void increment2() { robot.increment1(); }

void setup() {
  Serial.begin(9600);
  robot.begin(increment1, increment2);
}

void loop() {
  robot.update();
  delay(20);
}
