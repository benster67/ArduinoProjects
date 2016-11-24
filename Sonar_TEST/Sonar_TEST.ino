#include <NewPing.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x3F
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

#define TRIGGER_PIN  9
#define ECHO_PIN     8
#define MAX_DISTANCE 1000

LiquidCrystal_I2C  lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

const int pingValue = sonar.ping_in();
const int previousPingValue = 0;

const int num1 = 22;
const int num2 = 23;
const int num3 = 24;
const int num4 = 25;
const int num5 = 26;
const int num6 = 27;
const int num7 = 28;
const int num8 = 29;
const int num9 = 30;
const int num0 = 31;
const int plus = 32;
const int minus = 33;
const int divide = 34;
const int multiply = 35;
const int up = 36;
const int down = 37;
const int left = 38;
const int right = 39;
const int equalEnter = 40; 
const int funcPin = 41;

void setup() {
  Serial.begin(9600);
  lcd.begin (16, 2);
  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home();

}


void checkPing() {
  long duration, inches, cm;
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  pinMode(ECHO_PIN, INPUT);



  printPing();
  delay(1000);
  lcd.setCursor(0, 0);

}


long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
void printPing() {


  long duration = pulseIn(ECHO_PIN, HIGH);
  long inches = microsecondsToInches(duration);
  long cm = microsecondsToCentimeters(duration);

  if (inches >> 1500 && cm >> 3500)
  {
    //lcd.print("TOO FAR OR TOO CLOSE");
  }

  if (inches == 0) {}

  else {
    Serial.println(inches);
    lcd.print(inches);
    lcd.print("in");
    lcd.setCursor(0,1);
    lcd.print(cm);
    lcd.print("cm");
    lcd.print("       ");
    delay(100);
  }

}

void Calculate() {
  lcd.clear();
  lcd.home();
  //Start Calc Function and see if Jim can get buttons to work!!
}

void loop() {
  checkPing();

  if(funcPin == HIGH) {
    checkPing();
  }
  else {
    Calculate();
  }
}


