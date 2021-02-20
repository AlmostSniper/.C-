#include <IRremote.h>
int EN1 = 5;
int EN2 = 6;
int IN1 = 4;
int IN2 = 7;
int L = 3;  
int R = 8; 

long ir_item;
IRrecv irrecv_3(3);
decode_results results_3;

void motor(int id,int speed){
int pin_s,pin_d;
 switch(id){
case 1:pin_d=4;pin_s=5;break;
case 2:pin_d=7;pin_s=6;break;
default:break;}
if(speed==0){digitalWrite(pin_d,0);digitalWrite(pin_s,0);}
if(speed>0){digitalWrite(pin_d,0);analogWrite(pin_s,speed);}
       else{digitalWrite(pin_d,1);analogWrite(pin_s,speed);}
}

void setup(){
  Serial.begin(9600);
  irrecv_3.enableIRIn();
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(3, INPUT);
  pinMode(8, INPUT);
}
void loop(){
  if (irrecv_3.decode(&results_3)) {
    ir_item=results_3.value;
    String type="UNKNOWN";
    String typelist[14]={"UNKNOWN", "NEC", "SONY", "RC5", "RC6", "DISH", "SHARP", "PANASONIC", "JVC", "SANYO", "MITSUBISHI", "SAMSUNG", "LG", "WHYNTER"};
    if(results_3.decode_type>=1&&results_3.decode_type<=13){
      type=typelist[results_3.decode_type];
    }
    Serial.print("IR TYPE:"+type+"  ");
    Serial.println(ir_item,HEX);
    irrecv_3.resume();
  } else {
  }
  if (ir_item == 0xFF02FD) {
    motor(1,160);
    motor(2,160);
    delay(500);
  }
  if (ir_item == 0xFF9867) {
    motor(1,-80);
    motor(2,-80);
    delay(500);

  }
  if (ir_item == 0xFFE01F) {
    motor(1,-180);
    motor(2,180);
    delay(80);
    motor(1,150);
    motor(2,150);

  }
  if (ir_item == 0xFF906F) {
    motor(1,180);
    motor(2,-180);
    delay(80);
    motor(1,150);
    motor(2,150);
  }
  if (ir_item == 0xFFA857) {
    motor(1,0);
    motor(2,0);

  }
   char val1, val3;
  val1 = digitalRead(L);
  val3 = digitalRead(R);
  if (val1 == 1 && val3 == 1) {
    Motor1(160, true);
    Motor2(160, true);
  }
  else if (val1 == 0 && val3 == 0) {
    Motor1(160, false);
    Motor2(160, true);

  }
  else if (val1 == 1 && val3 == 0) {
    Motor1(160, false);
    Motor2(80, true);
  } 
 else if (val1 == 0 && val3 == 1) { 
    Motor1(80, true);
    Motor2(160, false);
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


volatile int d1;

float checkdistance_11_10() {
  digitalWrite(11, LOW);
  delayMicroseconds(2);
  digitalWrite(11, HIGH);
  delayMicroseconds(10);
  digitalWrite(11, LOW);
  float distance = pulseIn(10, HIGH) / 58.00;
  delay(10);
  return distance;
}
