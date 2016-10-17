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

LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
int ping = 0;
int ping2 = 0;
NewPing sonar(4,3,50);
void setup() {
  lcd.begin (16,2);
lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
lcd.setBacklight(HIGH);
lcd.home();
 
}

void loop() {
 ping2 = sonar.ping_in();
ping= sonar.ping_in();
if (ping == 0) {
 
}
else {
    lcd.print(ping);
  }
delay(100);

}
