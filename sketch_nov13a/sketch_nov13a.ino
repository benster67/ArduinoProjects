#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
int pot1 = 1;
int pot2 = 2;
int pot3 = 3;
int pot4 = 4;
int pot5 = 0;//Its's a PWM pin for Servo
int val1;
int val2;
int val3;
int val4;
int val5;

void setup() {
  //pins 11,10,9,6,5 are PWM
 servo1.attach(5);
 servo2.attach(6);
 servo3.attach(9);
 servo4.attach(10);
 servo5.attach(11);
}

void loop() {
  val1 = analogRead(pot1);
  val1 = map(val1, 0, 1023, 0, 180);
  servo1.write(val1);
  
  val2 = analogRead(pot2);
  val2 = map(val2, 0, 1023, 0, 180);
  servo2.write(val2);
  
  val3 = analogRead(pot3);
  val3 = map(val3, 0, 1023, 0, 180);
  servo3.write(val3);
  
  val4 = analogRead(pot4);
  val4 = map(val4, 0, 1023, 0, 180);
  servo4.write(val4);

  val5 = analogRead(pot5);
  val5 = map(val5, 0, 1023, 0, 180);
  servo5.write(val5);
  
}
