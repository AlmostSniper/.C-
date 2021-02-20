int EN1 = 5;
int EN2 = 6;
int IN1 = 4;
int IN2 = 7;
int LED = 8;
int L = 10;  
int C = 11; 
int R = 12; 

void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
}

void loop() {
  char val1, val2, val3;
  val1 = digitalRead(L);
  val2 = digitalRead(C);
  val3 = digitalRead(R);
  if (val1 == 1 && val2 == 1 && val3 == 1) {
    Motor1(160, false);
    Motor2(160, false);
    digitalWrite(LED, LOW);
  }
  else if (val1 == 1 && val2 == 0 && val3 == 1) {
    Motor1(160, false);
    Motor2(160, false);
    digitalWrite(LED, HIGH);
  }
  else if (val1 == 1 && val2 == 1 && val3 == 0) {
    Motor1(160, false);
    Motor2(0, true);
    digitalWrite(LED, HIGH);
  } 
 else if (val1 == 1 && val2 == 0 && val3 == 0) { 
    Motor1(150, false);
    Motor2(150, true);
    digitalWrite(LED, HIGH);
  }
  else if (val1 == 0 && val2 == 1 && val3 == 1) {
    Motor1(0, true);
    Motor2(160, false);
    digitalWrite(LED, HIGH);
  }
  else if (val1 == 0 && val2 == 0 && val3 == 1) {
    Motor1(150, true);
    Motor2(150, false);
    digitalWrite(LED, HIGH);
  }
  else if (val1 == 0 && val2 == 1 && val3 == 0) {
    Motor1(50, false);
    Motor2(50, false);
    digitalWrite(LED, LOW);
  }
  else if (val1 == 0 && val2 == 0 && val3 == 0) {
    Motor1(100, false);
    Motor2(100, false);
    digitalWrite(LED, LOW);
  }
}

void Motor1(int pwm, boolean reverse) {
  analogWrite(EN1, pwm);
  if (reverse) {
    digitalWrite(IN1, HIGH);
  }
  else {
    digitalWrite(IN1, LOW);
  }
}

void Motor2(int pwm, boolean reverse) {
  analogWrite(EN2, pwm);
  if (reverse) {
    digitalWrite(IN2, HIGH);
  }
  else {
    digitalWrite(IN2, LOW);
  }
}
