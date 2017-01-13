int xPin = A5;
int yPin = A4;
int joyStickButton;

int xAxis = 0;
int yAxis = 0;

int joyStickDirection = 0;
int lastJoyStickDirection = 0;

void setup() {
pinMode(xPin, INPUT);
pinMode(yPin, INPUT);
pinMode(joyStickButton, INPUT);
Serial.begin(9600);

}

void loop() {
  xAxis = analogRead(xPin);
  yAxis = analogRead(yPin);

  if(yAxis > 550 & yAxis < 1050) {
    joyStickDirection = 1;//UP
  }
  if(yAxis < 450) {
    joyStickDirection = 2;//DOWN
  }
  if(xAxis > 550 & xAxis < 1050) {
    joyStickDirection = 3;//RIGHT
  }
  if(xAxis < 450) {
    joyStickDirection = 4;//LEFT
  }
  Serial.println(joyStickDirection);
  delay(100);
}
