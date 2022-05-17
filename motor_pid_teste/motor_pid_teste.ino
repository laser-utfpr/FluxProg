#include <AFMotor.h>

int target = 40; // cm/s
unsigned long now;
float dt;

const int resolucao = 20; // lacunas por volta
const float circunferencia = 21.9911; // 7pi cm, a roda tem D = 7cm
const float kp = 0.8;
const float ki = 0;
const float kd = 0.1;

float get_cm_s (int counter, float dt) {
  return (1000 * circunferencia / resolucao) * (counter / dt);
}

float get_rpm (int counter, float dt) {
  return 60 * (1000 / resolucao) * (counter / dt);
}

// Motor 1
AF_DCMotor m1(1);
int counter1 = 0;
void increment1() { ++counter1; }

int last_counter1;
unsigned int last_time1;
float get_speed1 () {
  now = millis();
  dt = now - last_time1;
  last_time1 = now;

  last_counter1 = counter1;
  counter1 = 0;
  return get_cm_s(last_counter1, dt);
}

int motor1_power = 100;
int err1 = 0;
int last_err1 = 0;
float speed1;
void pid1 () {
  speed1 = get_speed1();
  err1 = target - speed1;
  
  motor1_power += err1*kp + kd*(err1-last_err1);
  motor1_power = min(255, max(motor1_power, 0));
  m1.setSpeed(motor1_power);
  last_err1 = err1;
}

// Motor 2
AF_DCMotor m2(2);
int counter2 = 0;
void increment2() { ++counter2; }

int last_counter2;
unsigned int last_time2;
float get_speed2 () {
  now = millis();
  dt = now - last_time2;
  last_time2 = now;

  last_counter2 = counter2;
  counter2 = 0;
  return get_cm_s(last_counter2, dt);
}

int motor2_power = 100;
int err2 = 0;
int last_err2 = 0;
float speed2;
void pid2 () {
  speed2 = get_speed2();
  err2 = target - speed2;
  
  motor2_power += err2*kp + kd*(err2-last_err2);
  motor2_power = min(255, max(motor2_power, 0));
  m2.setSpeed(motor2_power);
  last_err2 = err2;
}

void init_encoders() {
  attachInterrupt(digitalPinToInterrupt(20), increment1, FALLING);
  attachInterrupt(digitalPinToInterrupt(21), increment2, FALLING);
}

void setup() {
  Serial.begin(115200);
  init_encoders();
  m1.run(FORWARD);
  m2.run(FORWARD);
}

void loop() {
  pid1();
  pid2();

  Serial.println(speed1);
  delay(200);
}
