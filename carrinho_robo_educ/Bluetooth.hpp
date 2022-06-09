#ifndef BLUETOOTH_HPP
#define BLUETOOTH_HPP

enum class Command {
  Forward = 8,
  Left = 4,
  Right = 6,
};

class Bluetooth {
public:
  void begin() {
    Serial1.begin(9600);
  }
  bool available() {
    return Serial1.available();
  }
  int read() {
    return Serial1.read();
  }
  void write(char c) {
    Serial1.write(c);
  }
  void print(String s) {
    Serial1.print(s); 
  }
};

#endif
