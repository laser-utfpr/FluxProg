#ifndef BLUETOOTH_HPP
#define BLUETOOTH_HPP

enum class Command {
  Forward = 8,
  Left = 4,
  Right = 6,
};

class Bluetooth {
  HardwareSerial& serial;
public:
  Bluetooth(HardwareSerial& ser): serial(ser) {}
  char packet[15];
  inline void begin() {
    serial.begin(9600);
  }
  inline bool available() {
    return serial.available();
  }
  inline int read() {
    return serial.read();
  }
  inline void write_packet() {
    serial.write(packet, 15);
    serial.flush();
  }
};

#endif
