#include <Servo.h>
int x = 0;
int y = 0;
int z = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
y = analogRead(A4);
x = analogRead(A5);
z =digitalRead(4);//ADD RESISTOR
if(y > 550 & y < 1050) {
  Serial.println(" UP");
} //MAKE RANGES NARROWER
if(x > 550 & x < 1050) {
  Serial.println(" RIGHT");
}
if(x < 450) {
  Serial.println("LEFT");
}
if(y < 450) {
  Serial.println("DOWN");
}
//LEFT CHECK VALUES
/*Serial.print(x);
Serial.print(" ");
Serial.print(y);
Serial.print(" ");
Serial.println(z);
*/
delay(100);
}
