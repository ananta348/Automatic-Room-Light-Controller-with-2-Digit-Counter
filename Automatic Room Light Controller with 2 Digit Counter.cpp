#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust the address based on your LCD's address

// Pin configurations
const int entrySensorPin = 8;
const int exitSensorPin = 9;
const int ledPin = 10;

// Initialize variables
int counter = 0;

void setup() {
  pinMode(entrySensorPin, INPUT);
  pinMode(exitSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);

  lcd.init();
  lcd.backlight();
  updateLCD();
}

void loop() {
  // Check for student entry
  if (digitalRead(entrySensorPin) == HIGH) {
    delay(10); // Wait for stable reading
    if (digitalRead(exitSensorPin) == HIGH) {
      // Both sensors triggered, increment count
      counter++;
      digitalWrite(ledPin, HIGH); // Turn on LED
      updateLCD();
      delay(1000); // Wait to avoid multiple counts
    }
  }

  // Check for student exit
  if (digitalRead(exitSensorPin) == HIGH) {
    delay(10); // Wait for stable reading
    if (digitalRead(entrySensorPin) == HIGH && counter > 0) {
      // Both sensors triggered, decrement count
      counter--;
      digitalWrite(ledPin, counter > 0 ? HIGH : LOW); // Turn off LED if counter is 0
      updateLCD();
      delay(1000); // Wait to avoid multiple counts
    }
  }
}

void updateLCD() {
  lcd.clear(); // Clear the LCD before updating
  lcd.setCursor(0, 0); // Set cursor to the beginning of the first line

  if (counter > 0) {
    // If there are students in class, display count
    lcd.print("Count: ");
    lcd.print(counter);
  } else {
    // If no student is in class, display "No student"
    lcd.print("No student");
  }
}