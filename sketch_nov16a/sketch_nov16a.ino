int DelaySeconds = 100;
int brightness = 0;
int fadeAmount = 5;
int FadeDelaySeconds = 300;


void setup() {

Serial.begin(9600);

pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);
pinMode(8, OUTPUT);
pinMode(7, OUTPUT);
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
pinMode(4, OUTPUT);
pinMode(3, OUTPUT);
pinMode(2, OUTPUT);
pinMode(1, OUTPUT);


}

void loop() {

 brightness = brightness + fadeAmount;

 if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount;
  }

  Serial.println(brightness);

 analogWrite(13, brightness);
 delay(FadeDelaySeconds);
  analogWrite(12, brightness);
 delay(FadeDelaySeconds);
  analogWrite(11, brightness);
 delay(FadeDelaySeconds);
  analogWrite(10, brightness);
 delay(FadeDelaySeconds);
  analogWrite(9, brightness);
 delay(FadeDelaySeconds);
  analogWrite(8, brightness);
 delay(FadeDelaySeconds);
  analogWrite(7, brightness);
 delay(FadeDelaySeconds);
  analogWrite(6, brightness);
 delay(FadeDelaySeconds);
  analogWrite(5, brightness);
 delay(FadeDelaySeconds);
  analogWrite(4, brightness);
 delay(FadeDelaySeconds);
  analogWrite(3, brightness);
 delay(FadeDelaySeconds);
  analogWrite(2, brightness);
 delay(FadeDelaySeconds);
 analogWrite(1, brightness);
 delay(FadeDelaySeconds);
 
  
 digitalWrite(13,HIGH);
 delay(DelaySeconds);
 digitalWrite(13, LOW);
 delay(DelaySeconds);
 digitalWrite(12, HIGH);
 delay(DelaySeconds);
digitalWrite(12, LOW);
 delay(DelaySeconds);
 digitalWrite(11, HIGH);
 delay(DelaySeconds);
 digitalWrite(11, LOW);
 delay(DelaySeconds);
 digitalWrite(10,HIGH);
 delay(DelaySeconds);
digitalWrite(10, LOW);
 delay(DelaySeconds);
 digitalWrite(9, HIGH);
delay(DelaySeconds);
digitalWrite(9, LOW);
delay(DelaySeconds);
digitalWrite(5, HIGH);
delay(DelaySeconds);
digitalWrite(5, LOW);
delay(DelaySeconds);
digitalWrite(4, HIGH);
delay(DelaySeconds);
digitalWrite(4, LOW);
delay(DelaySeconds);
digitalWrite(3, HIGH);
delay(DelaySeconds);
digitalWrite(3, LOW);
delay(DelaySeconds);
digitalWrite(2, HIGH);
delay(DelaySeconds);
digitalWrite(2, LOW);
delay(DelaySeconds);
digitalWrite(1, HIGH);
delay(DelaySeconds);
digitalWrite(1, LOW);
delay(DelaySeconds);
digitalWrite(6, HIGH);
delay(DelaySeconds);
digitalWrite(6, LOW);
delay(DelaySeconds);
digitalWrite(7, HIGH);
delay(DelaySeconds);
digitalWrite(7, LOW);
delay(DelaySeconds);
digitalWrite(8, HIGH);
delay(DelaySeconds);
digitalWrite(8, LOW);
delay(DelaySeconds);
}
