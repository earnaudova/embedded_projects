#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int sensorPin = A0;
const int potPin = A1;

unsigned long debounceDelay = 1000;
unsigned long lastDebounceTime = 0; 

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  int potentionmeter = analogRead(potPin);
  int potValue = map(potentionmeter, 0, 1023, 0, 100);

  float voltage = (sensorVal/1024.0)*5.0;
  float temp = (voltage-0.5)*100;

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if(potValue <= 30){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Sensor Value:");
      lcd.setCursor(0, 1);
      lcd.print(sensorVal);
    } else if(potValue > 30 && potValue <= 60){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temperature:");
      lcd.setCursor(0, 1);
      lcd.print(temp);
    } else {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Voltage: ");
      lcd.setCursor(0,1);
      lcd.print(voltage);
    }

    lastDebounceTime = millis();
  }
}

