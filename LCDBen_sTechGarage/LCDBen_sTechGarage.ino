#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x3F
#define BACKLIGHT_PIN     3
#define LCD_PIN 13

LiquidCrystal_I2C  lcd(I2C_ADDR, LCD_PIN, LCD_PIN, LCD_PIN, LCD_PIN, LCD_PIN, LCD_PIN, LCD_PIN);

void setup() {
  lcd.begin (16, 2);
  lcd.home();
  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.print("YouTube.com/c/");
  lcd.setCursor(0, 1);
  lcd.print("BensTechGarage");


}

void loop() {







}
