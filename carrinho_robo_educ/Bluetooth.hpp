#ifndef BLUETOOTH_HPP
#define BLUETOOTH_HPP

enum class Command {
  Forward = 8,
  Left = 4,
  Right = 6,
};

class Bluetooth {
public:
  char packet[15];
  void begin() {
    Serial1.begin(9600);
  }
  bool available() {
    return Serial1.available();
  }
  int read() {
    return Serial1.read();
  }
  void write_packet() {
    Serial1.write(packet, 15);
    Serial1.flush();
  }
};

#endif
