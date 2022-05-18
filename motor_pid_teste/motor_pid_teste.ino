#include <AFMotor.h>

struct MotorController {
  static constexpr int resolucao = 20; // lacunas por volta
  static constexpr float circunferencia = 22; // 7pi cm, a roda tem D = 7cm
  static constexpr float kp = 0.5;
  static constexpr float ki = 0;
  static constexpr float kd = 0;

  AF_DCMotor motor;
  int motor_power = 0;

  int counter = 0;
  int last_counter = 0;
  unsigned long last_time = 0;
  unsigned long now = 0;
  float dt;

  int err = 0;
  int last_err = 0;
  float speed;
  float target = 0;

  MotorController(int id): motor(id) {}

  float get_cm_s (int counter, float dt) {
    return (1000 * circunferencia / resolucao) * (counter / dt);
  }

  float get_rad_s (int counter, float dt) {
    return (500 / resolucao) * (counter / dt);
  }

  float get_rpm (int counter, float dt) {
    return 60 * (1000 / resolucao) * (counter / dt);
  }

  void run(int dir) { motor.run(dir); }
  void setSpeed(float speed) { target = speed; }

  float get_speed() {
    now = millis();
    dt = now - last_time;
    last_time = now;

    last_counter = counter;
    counter = 0;
    return get_rad_s(last_counter, dt);
  }

  void pid() {
    speed = get_speed();
    err = target - speed;

    motor_power += err*kp + kd*(err-last_err);
    motor_power = min(255, max(motor_power, 0));
    motor.setSpeed(motor_power);
    last_err = err;
  }
};

MotorController m1(1);
void increment1() { ++m1.counter; }

MotorController m2(2);
void increment2() { ++m2.counter; }

void init_encoders() {
  attachInterrupt(digitalPinToInterrupt(20), increment1, FALLING);
  attachInterrupt(digitalPinToInterrupt(21), increment2, FALLING);
}

void setup() {
  Serial.begin(115200);
  init_encoders();

  m1.setSpeed(6);
  m2.setSpeed(6);
  m1.run(FORWARD);
  m2.run(FORWARD);
}

void loop() {
  Serial.print(m1.speed);
  Serial.print(" - ");
  Serial.println(m2.speed);

  m1.pid();
  m2.pid();
  delay(20);
}
