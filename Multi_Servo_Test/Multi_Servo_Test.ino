#include <Servo.h>

Servo myservo;
Servo myservo2;

int potpin = A0;
int val;   
int potpin2 = A1;
int val2;

void setup() {
  myservo.attach(9);
  myservo2.attach(5);
}

void loop() {
  val = analogRead(potpin);
  val2 = analogRead(potpin2);
  val = map(val, 0, 1023, 0, 180);
  val2 = map(val2, 0, 1023, 0, 180);  
  myservo.write(val);                  
  myservo2.write(val2);                  
  
}

