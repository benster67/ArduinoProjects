#include <NewPing.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <dht.h>

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

#define DHT11_PIN 10

LiquidCrystal_I2C  lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

dht DHT;

const int pingValue = sonar.ping_in();
const int previousPingValue = 0;

int celcius = 0;
int farenheit = 0;
int humidity = 0;

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
const int funcPin1 = 41; //Calc
const int funcPin2 = 42; //Ping
const int funcPin3 = 43; //EV
const int funcPin4 = 44; //LUX
const int piButton = 45;

const int Pi = 3.14159265358979

int numEntered = 0;
int tempNum1 = 0;

void setup() {
  pinMode(num1, INPUT);
  pinMode(num2, INPUT);
  pinMode(num3, INPUT);
  pinMode(num4, INPUT);
  pinMode(num5, INPUT);
  pinMode(num6, INPUT);
  pinMode(num7, INPUT);
  pinMode(num8, INPUT);
  pinMode(num9, INPUT);
  pinMode(num0, INPUT);
  pinMode(plus, INPUT);
  pinMode(minus, INPUT);
  pinMode(divide, INPUT);
  pinMode(multiply, INPUT);
  pinMode(up, INPUT);
  pinMode(down, INPUT);
  pinMode(left, INPUT);
  pinMode(right, INPUT);
  pinMode(equalEnter, INPUT);
  pinMode(funcPin1, INPUT);
  pinMode(funcPin2, INPUT);
  pinMode(funcPin3, INPUT);
  pinMode(funcPin4, INPUT);
  pinMode(piButton, INPUT);
  //LUX INPUT
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
    lcd.setCursor(0, 1);
    lcd.print(cm);
    lcd.print("cm");
    lcd.print("       ");
    delay(100);
  }

}

void Calculate() {
  lcd.clear();
  lcd.home();
if (digitalRead(num1 == HIGH)) {
  tempNum1 = 1;
}
if else (digitalRead(num2 == HIGH)) {
  tempNum1 = 2;
}
if else (digitalRead(num3 == HIGH)) {
  tempNum1 = 3;
}
if else(digitalRead(num4 == HIGH)) {
  tempNum1 = 4;
}
if else(digitalRead(num5 == HIGH)) {
  tempNum1 = 5;
}
if else(digitalRead(num6 == HIGH)) {
  tempNum1 = 6;
}
if else(digitalRead(num7 == HIGH)) {
  tempNum1 = 7;
}
if else(digitalRead(num8 == HIGH)) {
  tempNum1 = 8;
}
if else(digitalRead(num9 == HIGH)) {
  tempNum1 = 9;
}
if else(digitalRead(num0 == HIGH)) {
  tempNum1 = 0;
}
else(digitalRead(piButton == HIGH)) {
  tempNum1 = Pi;
}
}

void showTempNum1() {
  lcd.setCursor(0, 1);
  lcd.print(tempNum1);
}

void checkEnviroment() {
  int chk = DHT.read11(DHT11_PIN);
  celcius = DHT.temperature;
  farenheit = (celcius * 1.800000) + 32;
  humidity =  DHT.humidity;
  printEnviromentStatus();
}

void printEnviromentStatus() {
    lcd.print("Temp = ");
    lcd.print(farenheit);
    lcd.print(" Deg F ");
    lcd.print(celcius);
    lcd.println(" Deg C ");
    lcd.print("Humidity = ");
    lcd.print(humidity);
    lcd.println("%");
    //delay(1000);
}

void askStartFunc() {

  lcd.print("Choose Function:");
  lcd.setCursor(0,1);
  lcd.print("Calc1Ping2EV3LX4");
   
  if (funcPin2 == HIGH) {
    lcd.home();
    lcd.clear();
    checkPing();
  }
  if(funcPin3 == HIGH) {
    lcd.home();
    lcd.clear();
    checkEnviroment();
  }
  if(funcPin4 == HIGH) {
    lcd.home();
    lcd.clear();
    luxCheck();
  }
  else {
    lcd.home();
    lcd.clear();
    Calculate();
  } 
}

void luxCheck() {
  
}

void showInfo() {
  //LCD Print in Notes
}

void loop() {
  showInfo(); //Beginning About Screen
  askStartFunc();
}


