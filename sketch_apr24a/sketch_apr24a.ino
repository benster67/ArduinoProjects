int redPin = 6;
int greenPin = 5;
int bluePin = 4;

void setup() {
const int winningPin = 10;
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
pinMode(winningPin,OUTPUT);
pinMode(9,OUTPUT);
pinMode(8,OUTPUT);
pinMode(7,OUTPUT);
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT); 
}

void loop() {
const int winningPin = 10;
const int delaySeconds = 80;
digitalWrite(7,HIGH);
delay(delaySeconds);
digitalWrite(7,LOW);
delay(delaySeconds);
digitalWrite(8,HIGH);
delay(delaySeconds);
digitalWrite(8,LOW);
delay(delaySeconds);
digitalWrite(9,HIGH);
delay(delaySeconds);
digitalWrite(9,LOW);
delay(delaySeconds);
digitalWrite(winningPin,HIGH);
delay(delaySeconds);
digitalWrite(winningPin,LOW);
delay(delaySeconds);
digitalWrite(11,HIGH);
delay(delaySeconds);
digitalWrite(11,LOW);
delay(delaySeconds);
digitalWrite(12,HIGH);
delay(delaySeconds);
digitalWrite(12,LOW);
delay(delaySeconds);
digitalWrite(13,HIGH);
delay(delaySeconds);
digitalWrite(13,LOW);
delay(delaySeconds);
setColor(0,0,255);
delay(delaySeconds);
digitalWrite(12,HIGH);
delay(delaySeconds);
digitalWrite(12,LOW);
delay(delaySeconds);
digitalWrite(11,HIGH);
delay(delaySeconds);
digitalWrite(11,LOW);
delay(delaySeconds);
digitalWrite(10,HIGH);
delay(delaySeconds);
digitalWrite(10,LOW);
delay(delaySeconds);
digitalWrite(9,HIGH);
delay(delaySeconds);
digitalWrite(9,LOW);
delay(delaySeconds);
digitalWrite(8,HIGH);
delay(delaySeconds);
digitalWrite(8,LOW);
delay(delaySeconds);
digitalWrite(7,HIGH);
delay(delaySeconds);
digitalWrite(7,LOW);
delay(delaySeconds);
setColor(255, 0, 0);  // red
  delay(500);
  setColor(0, 255, 0);  // green
  delay(500);
  setColor(0, 0, 255);  // blue
  delay(500);
  setColor(255, 255, 0);  // yellow
  delay(500);  
  setColor(80, 0, 80);  // purple
  delay(500);
  setColor(0, 255, 255);  // aqua
  delay(500);
}



void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

