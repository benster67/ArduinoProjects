//#include <NewPing.h> NO LONGER NEEDED 
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <dht.h>

#define I2C_ADDR    0x27
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

//NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
//NO LONGER USED I MADE MY OWN FUCNTION
dht DHT; //INIT HUMIDITY SENSOR

//const int pingValue = sonar.ping_in();
//const int previousPingValue = 0;

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
//POWER LED AND PIN 13 LED //CHANGED TO RGB LED
const int photocellPin = A1;

const int GREEN = 46;
const int BLUE = 47;
const int RED = 48;

const int delayTime = 2;

int redVal = 0;
int blueVal = 0;
int greenVal = 0;

const int speakerPin = 49;

const int Pi = 3.14159265358979;

int xPin = A5;
int yPin = A4;
int joyStickButton;

int xAxis = 0;
int yAxis = 0;

int joyStickDirection = 0;
int lastJoyStickDirection = 0;

int photocellReading = 0;

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

  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);

  pinMode(speakerPin, OUTPUT);

  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(joyStickButton, INPUT);

  pinMode(photocellPin, INPUT);

  Serial.begin(9600);
  lcd.begin (20,4);
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
    lcd.print("TOO FAR/CLOSE");
  }

  if (inches == 0 || cm == 0) {}

  if (inches == 0 && cm == 0) {}

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
  else if (digitalRead(num2 == HIGH)) {
    tempNum1 = 2;
  }
  else if (digitalRead(num3 == HIGH)) {
    tempNum1 = 3;
  }
  else if (digitalRead(num4 == HIGH)) {
    tempNum1 = 4;
  }
  else if (digitalRead(num5 == HIGH)) {
    tempNum1 = 5;
  }
  else if (digitalRead(num6 == HIGH)) {
    tempNum1 = 6;
  }
  else if (digitalRead(num7 == HIGH)) {
    tempNum1 = 7;
  }
  else if (digitalRead(num8 == HIGH)) {
    tempNum1 = 8;
  }
  else if (digitalRead(num9 == HIGH)) {
    tempNum1 = 9;
  }
  else if (digitalRead(num0 == HIGH)) {
    tempNum1 = 0;
  }
  else if (digitalRead(piButton == HIGH)) {
    tempNum1 = Pi; //Make it only show up to 5 chars
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
  lcd.setCursor(0, 1);
  lcd.print("Calc1Ping2EV3LX4"); //Modify for Joystick

  if (funcPin2 == HIGH) {
    lcd.home();
    lcd.clear();
    checkPing();
  }
  if (funcPin3 == HIGH) {
    lcd.home();
    lcd.clear();
    checkEnviroment();
  }
  if (funcPin4 == HIGH) {
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
  photocellReading = analogRead(photocellPin); //CHANGE TO LCD PRINT
  Serial.print("Lux: ");
  Serial.println(photocellReading);
  if (photocellReading < 10) {
    Serial.println(" - Dark");
  } else if (photocellReading < 200) {
    Serial.println(" - Dim");
  } else if (photocellReading < 500) {
    Serial.println(" - Light");
  } else if (photocellReading < 800) {
    Serial.println(" - Bright");
  } else {
    Serial.println(" - Very bright");
  }
  delay(1000);
}

void setLEDRGB() {

  int redVal = 255;
  int blueVal = 0;
  int greenVal = 0;
  for ( int i = 0 ; i < 255 ; i += 1 ) {
    greenVal += 1;
    redVal -= 1;
    analogWrite( GREEN, 255 - greenVal );
    analogWrite( RED, 255 - redVal );

    delay( delayTime );
  }

  redVal = 0;
  blueVal = 0;
  greenVal = 255;
  for ( int i = 0 ; i < 255 ; i += 1 ) {
    blueVal += 1;
    greenVal -= 1;
    analogWrite( BLUE, 255 - blueVal );
    analogWrite( GREEN, 255 - greenVal );

    delay( delayTime );
  }

  redVal = 0;
  blueVal = 255;
  greenVal = 0;
  for ( int i = 0 ; i < 255 ; i += 1 ) {
    redVal += 1;
    blueVal -= 1;
    analogWrite( RED, 255 - redVal );
    analogWrite( BLUE, 255 - blueVal );

    delay( delayTime );
  }
}
void showBootInfo() {
  //LCD Print in Notes
}

void setLEDBlue() {
  digitalWrite(GREEN, HIGH); //RED AND GREEN MAKE BLUE
  digitalWrite(RED, HIGH);
}
void setLEDGreen() {
  digitalWrite(BLUE, HIGH); //RED AND BLUE MAKE GREEN
  digitalWrite(RED, HIGH);
}
void setLEDRed() {
  digitalWrite(GREEN, HIGH);//GREEN AND BLUE MAKE RED
  digitalWrite(BLUE, HIGH);
}
void buttonPressed() {
  setLEDBlue();
  playButtonTone();
}

void playButtonTone() {
  tone(speakerPin, 600, 50); //FIND BETTER VALUES
}

void showResult() {
  setLEDGreen();
  //SHOW THE RESULT ON THE LCD
}
void checkJoyStickDirection() {
  xAxis = analogRead(xPin);
  yAxis = analogRead(yPin);

  if (yAxis > 550 & yAxis < 1050) {
    joyStickDirection = 1;//UP
  }
  if (yAxis < 450) {
    joyStickDirection = 2;//DOWN
  }
  if (xAxis > 550 & xAxis < 1050) {
    joyStickDirection = 3;//RIGHT
  }
  if (xAxis < 450) {
    joyStickDirection = 4;//LEFT
  }
  Serial.println(joyStickDirection);
  delay(100);
}
void loop() {//Maybe in setup bc loop? //CHECK
  showBootInfo(); //Beginning About Screen
  askStartFunc(); //MAKE WORK
  //ADD JOYSTICK
}


