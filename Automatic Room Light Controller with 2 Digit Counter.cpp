#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int entrySensorPin = 8;
const int exitSensorPin = 9;
const int ledPin = 10;

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
  if (digitalRead(entrySensorPin) == HIGH) {
    delay(10);

    if (digitalRead(exitSensorPin) == HIGH) {
      counter++;
      digitalWrite(ledPin, HIGH);
      updateLCD();
      delay(1000);
    }
  }

  if (digitalRead(exitSensorPin) == HIGH) {
    delay(10);

    if (digitalRead(entrySensorPin) == HIGH && counter > 0) {
      counter--;
      digitalWrite(ledPin, counter > 0 ? HIGH : LOW);
      updateLCD();
      delay(1000);
    }
  }
}

void updateLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);

  if (counter > 0) {
    lcd.print("Count: ");
    lcd.print(counter);
  } else {
    lcd.print("No student");
  }
}
