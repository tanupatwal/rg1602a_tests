#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

// Define the LCD address (commonly 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  static int x = 0;
  static int y = 0;
  lcd.setCursor(x++, y ^ 1);
  lcd.print("Shakura");
  y = y ^ 1;

  if (x >= 16) {
    x = 0;
    lcd.clear();
  }

  

  delay(2000);
  lcd.clear();
}

