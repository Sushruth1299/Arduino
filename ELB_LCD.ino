// LCD Library
#include <LiquidCrystal.h>

// Variable Declarization
int temp_pin = A0;
LiquidCrystal LCD(2, 3 ,4, 5, 6, 7);

void setup() {
  Serial.begin(9600);
  pinMode(temp_pin, INPUT);
  LCD.begin(16, 2);
}

void loop() {
  int analogvalue = analogRead(temp_pin);
  float voltage = (analogvalue / 1023.0) * 5;
  float TemperatureC = voltage * 100;
  float TemperatureF = TemperatureC * 9/5 + 32;

  Serial.print("Temperature: ");
  Serial.print(TemperatureF);

  LCD.setCursor(0, 0);
  LCD.print(TemperatureF);

  Serial.println(" °F");

  LCD.setCursor(6, 0);
  LCD.print("F");

  delay(500);
}