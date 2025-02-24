#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>



// LCD address (commonly 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Custom character definitions (5x8 pixels each)
byte customChar1[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111
};

byte customChar2[8] = {
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b11111
};

byte customChar3[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

// Function declaration
void demoCustomChars();

void setup() {
  Serial.begin(115200);
  
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  // Create custom characters in CGRAM
  lcd.createChar(0, customChar1);  // Bottom line
  lcd.createChar(1, customChar2);  // Box outline
  lcd.createChar(2, customChar3);  // Full block
  
  // Show custom character demo
  demoCustomChars();
}

void loop() {
  // Create a scrolling pattern using custom characters
  static int pos = 0;
  
  lcd.clear();
  for(int i = 0; i < 16; i++) {
    lcd.setCursor(i, 0);
    lcd.write((i + pos) % 3);
    lcd.setCursor(i, 1);
    lcd.write((i + pos + 1) % 3);
  }
  
  pos = (pos + 1) % 3;
  delay(300);
}

// Function definition
void demoCustomChars() {
  // Display all custom characters
  lcd.setCursor(0, 0);
  lcd.print("Custom chars:");
  
  lcd.setCursor(0, 1);
  lcd.write(0);  // Write custom char 0
  lcd.write(1);  // Write custom char 1
  lcd.write(2);  // Write custom char 2
  
  delay(2000);
  
  // Animate a pixel pattern
  for(int i = 0; i < 3; i++) {
    lcd.clear();
    for(int col = 0; col < 16; col++) {
      for(int row = 0; row < 2; row++) {
        lcd.setCursor(col, row);
        lcd.write(random(0, 3));  // Random custom character
      }
      delay(100);
    }
    delay(500);
  }
}