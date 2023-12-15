#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int sensorPin = A0;

unsigned long debounceDelay = 1000;
unsigned long lastDebounceTime = 0; 

void setup() {
  lcd.begin(16, 2);
  
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal/1024.0)*5.0;
  float temp = (voltage-0.5)*100;

  if ((millis() - lastDebounceTime) > debounceDelay) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperature:");
    lcd.setCursor(0, 1);
    lcd.print(temp);

    lastDebounceTime = millis();
  }

  //TBD: Add potentionmeter to choose what to displat between the following three values.
  
  // lcd.setCursor(0, 0);
  // lcd.print("Sensor Value:");
  // lcd.setCursor(0, 1);
  // lcd.print(sensorVal);

  // lcd.setCursor(0,0);
  // lcd.print("Voltage: ");
  // lcd.setCursor(0,1);
  // lcd.print(voltage);

  // lcd.setCursor(0,0);
  // lcd.print("Temperature: ");
  // lcd.setCursor(0,1);
  // lcd.print(temperature);
}

