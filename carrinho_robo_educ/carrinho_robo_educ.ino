#include "Car.hpp"
#include "Bluetooth.hpp"

Car car;
Bluetooth bt;
void increment1() { car.increment1(); }
void increment2() { car.increment2(); }

void setup() {
  Serial.begin(9600);
  bt.begin();
  car.begin(increment1, increment2);
}

void loop() {
  car.update();
  delay(20);

  while (bt.available()) {
    char c = bt.read();
    bt.write(c);

    if (c == 'S') {
      car.setState(CarState::FollowLine);
    }
    else if (c == 'P') {
      car.setState(CarState::Stop);
    }
    else if (c == 'F') {
      car.setState(CarState::Forward);
    }
    else if (c == 'L') { 
      car.setState(CarState::Left);
    }
    else if (c == 'R') {
      car.setState(CarState::Right);
    }
  }

  while (Serial.available()) {
    char c = Serial.read();
    Serial.print("ECHO CARRINHO: "); Serial.println(c);
  }
}
