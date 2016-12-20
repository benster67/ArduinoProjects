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

#define TRIGGER_PIN  7  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     6  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 1000 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

LiquidCrystal_I2C  lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

int pingValue = sonar.ping_in();
int previousPingValue = 0;

void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
  lcd.begin (16, 2);
  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home();

}

void printPing() {
  lcd.print("Ping: ");
  lcd.print(pingValue);
  lcd.print("in");
  lcd.print("     ");
}
void checkPing() {
  if (pingValue == 0) {}

  if (pingValue == previousPingValue) {}

  else {
   // printPing();
    Serial.println(pingValue);
   delay(1000);
    
    //lcd.print("Ping: ");
    //lcd.print(pingValue);
    //lcd.print("in");
    printPing();
    delay(1000);
    lcd.setCursor(0,1);
    printPing();
    lcd.setCursor(0,1);
    printPing();
    lcd.setCursor(0,0);
    
  }

}

void loop() {
  checkPing();
}





