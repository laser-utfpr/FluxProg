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
  delay(20);
  car.update(bt);

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
  }
}
