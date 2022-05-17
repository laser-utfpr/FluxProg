#include <AFMotor.h>

//Variavies global-------------------------------------------------
const int trig = 44;
const int echo = 46;
const int pin_ir[4] = { 45, 47, 49, 51 };
int error_table[16];
//*****************************************************************


AF_DCMotor m1(1);
AF_DCMotor m2(2);

//Funções----------------------------------------------------------
// motor
void run(int s1, int s2) {
  if (s1 >= 0) {
    m1.run(FORWARD);
    m1.setSpeed(min(s1, 255));
  }
  else {
    m1.run(BACKWARD);
    m1.setSpeed(min(-s1, 255));
  }

  if (s2 >= 0) {
    m2.run(FORWARD);
    m2.setSpeed(min(s2, 255));
  }
  else {
    m2.run(BACKWARD);
    m2.setSpeed(min(-s2, 255));
  }
}

// infravermelho
void init_ir() { 
  error_table[0b1110] = -7;
  error_table[0b1000] = -3;
  error_table[0b1100] = -5;
  error_table[0b0100] = -2;
  error_table[0b0110] = 0;
  error_table[0b0000] = 0;
  error_table[0b0010] = 2;
  error_table[0b0011] = 5;
  error_table[0b0001] = 3;
  error_table[0b0111] = 7;
  for (int i = 0; i < 4; ++i) {
    pinMode(pin_ir[i], INPUT_PULLUP);
  }  
}

int read_ir() {
  int j = 0;
  for (int i = 0; i < 4; ++i) {
    j <<= 1;
    j |= digitalRead(pin_ir[i]);
  }
  // j = ir0 ir1 ir2 ir3
  return error_table[j];
}
//*****************************************************************
//*****************************************************************
void follow_line() {
  static const int base = 160;
  static const float kp = 50;
  static const float ki = 0.010;
  static const float kd = 1;
  static int last_err = 0;
  static float p = 0, i = 0, d = 0;
  
  int err = read_ir();

  p = err;
  i = i + err;
  d = err - last_err;
  last_err = err;

  int s = p*kp + i*ki + d*kd;

  run(base+s, base-s);
  delay(10);
}

//Main-------------------------------------------------------------

void setup() {
  // Serial.begin(9600);
  init_ir();
}


void loop() {
  follow_line();
}
