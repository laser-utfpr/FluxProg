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

bool andando = false;
void loop() {
  if (andando) {
    car.update();
  }
  delay(20);

  while (bt.available()) {
    char c = bt.read();
    bt.write(c);

    if (c == 'S') { 
      bt.print("Segue linha");
      andando = true;
    }
    else if (c == 'P') { 
      bt.print("Parado");
      car.stop();
      andando = false; 
    }
  }

  while (Serial.available()) {
    char c = Serial.read();
    Serial.print("ECHO CARRINHO: "); Serial.println(c);
  }
}
