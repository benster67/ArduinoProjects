#include <Servo.h>

  Servo servo1;
  Servo servo2;


void setup() {
  
  servo1.attach(A1);
  servo2.attach(A2);
}

void loop() {
  servo1.write(100);
  delay(15);

}
