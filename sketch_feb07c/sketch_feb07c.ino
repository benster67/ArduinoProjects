int x = 0;
int y = 0;
int z = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
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
delay(500);
}
