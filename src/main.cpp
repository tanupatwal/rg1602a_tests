#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

// Define the LCD address (commonly 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define custom heart character
byte customChar[] = {
  B00000,
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000
};

void setup() {
  // Initialize serial for debugging
  Serial.begin(115200);
  
  // Initialize LCD
  Wire.begin();  // Initialize I2C
  lcd.begin(16, 2);
  
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  // Create and display custom character
  lcd.createChar(0, customChar);
  lcd.home();
  lcd.write(0);  // Display the custom character
  
  // Add some text to confirm LCD is working
  lcd.setCursor(2, 0);
  lcd.print("Hello!");
  
  Serial.println("Setup complete!");
}

void loop() {
  // Optional: Add simple animation
  static bool isVisible = true;
  static unsigned long lastToggle = 0;
  
  if (millis() - lastToggle >= 1000) {  // Toggle every second
    lastToggle = millis();
    
    if (isVisible) {
      lcd.clear();
      isVisible = false;
    } else {
      lcd.home();
      lcd.write(0);
      lcd.setCursor(2, 0);
      lcd.print("Hello!");
      isVisible = true;
    }
  }
}