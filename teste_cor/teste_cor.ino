#include <TimerOne.h>

/* SensorCor
 *  - Cores de ref (4 cores)
 *  - Valor atual
 *  - contador e seletor
 *  - Pinos (5 entrada + 1 saida)
 *  - selCor(): seleciona filtro de cor
 *  + intPin(): para ser chamado na interrupcao do pino
 *  + intTimer(): para ser chamado na interrupcao do timer
 *  + begin(): inicializa timer e interrupcoes
 *  + getCor(): retorna codigo da cor de ref mais prox
 *
 * Cor
 *  + Leituras, rgbw, codigo
 *  + distancia euclidiana
 */

const int s[] = { 52, 50, 48, 46 };
const int oe = 44;
const int out = 21;

struct Cor {
  union {
    struct { int r, b, w, g; };
    int a[4];
  };
  void print() {
    Serial.print('{');
    Serial.print(a[0]);
    for (int i = 1; i < 4; ++i) {
      Serial.print(", ");
      Serial.print(a[i]); 
    }
    Serial.print('}');
  };
};

unsigned long long d2(Cor a, Cor b) {
  unsigned long  dr = a.r - b.r;
  unsigned long  dg = a.g - b.g;
  unsigned long  db = a.b - b.b;
  unsigned long  dw = a.w - b.w;
  return dr*dr + dg*dg + db*db * dw*dw;
}

Cor black;
Cor white;
Cor wgreen;
Cor bgreen;
Cor cor;

const char R = 0x00;
const char B = 0x01;
const char W = 0x02;
const char G = 0x03;
void setCor(char c) {
  digitalWrite(s[2], (c >> 1) & 0x01);
  digitalWrite(s[3], c & 0x01);
}

char i = R;
unsigned count = 0;
void inc() { count += 4; }
void ler() {
  setCor(i);
  cor.a[i] = count;
  count = 0;
  i = (i+1) % 4;
}

void calibra() {
  Serial.println("Calibracao preto...");
  while (!Serial.available()) { delay(300); }
  while (Serial.available()) { Serial.read(); }
  memcpy(&black, &cor, sizeof(cor));
  Serial.println("Calibracao branco...");
  while (!Serial.available()) { delay(300); }
  while (Serial.available()) { Serial.read(); }
  memcpy(&white, &cor, sizeof(cor));
  Serial.println("Calibracao verde no branco...");
  while (!Serial.available()) { delay(300); }
  while (Serial.available()) { Serial.read(); }
  memcpy(&wgreen, &cor, sizeof(cor));
  Serial.println("Calibracao verde no preto...");
  while (!Serial.available()) { delay(300); }
  while (Serial.available()) { Serial.read(); }
  memcpy(&bgreen, &cor, sizeof(cor));
  Serial.println("calibrado");
}

void setup() {
  for (int i = 0; i < 4; ++i) pinMode(s[i], OUTPUT);
  pinMode(oe, OUTPUT);
  pinMode(out, INPUT);

  digitalWrite(s[0], LOW);
  digitalWrite(s[1], HIGH);

  Timer1.initialize(int(0.25e6));
  Timer1.attachInterrupt(ler);
  attachInterrupt(digitalPinToInterrupt(out), inc, CHANGE);

  Serial.begin(9600);
  calibra();
}

void loop() {
  delay(1000);
  unsigned long long dw = d2(cor, white);
  unsigned long long dwg = d2(cor, wgreen);
  unsigned long long dbg = d2(cor, bgreen);
  unsigned long long db = d2(cor, black);

  cor.print();
  if (dw < dbg && dw < dwg && dw < db) Serial.println("White");
  if (dbg < dw && dbg < dwg && dbg < db) Serial.println("Green");
  if (db < dwg && db < dbg && db < dw) Serial.println("Black");
  if (dwg < dw && dwg < dbg && dwg < db) Serial.println("Green");
  
}
