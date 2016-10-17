/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */
int led = 11;           // the pin that the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;

// the setup function runs once when you press reset or power the board
void setup() {
  
  Serial.begin(9600);
  
  pinMode(11, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  analogWrite(11, brightness);   // turn the LED on (HIGH is the voltage level)
  brightness = brightness + fadeAmount;
Serial.println(brightness);

   if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }

  delay(15);
}
