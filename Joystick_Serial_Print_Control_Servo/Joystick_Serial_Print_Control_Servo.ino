
#include <Servo.h>
int x = 0;
int y = 0;
int z = 0;
Servo servoX;
Servo servoY;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

servoX.attach(8);
servoY.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
y = analogRead(A0);
x = analogRead(A1);
z =digitalRead(22);
Serial.print(x);
Serial.print(" ");
Serial.print(y);
Serial.print(" ");
Serial.println(z);
servoX.write(map(ping, 0, 1023, 0, 255));
servoY.write(map(ping, 0, 1023, 0, 255));
delay(100);
}
