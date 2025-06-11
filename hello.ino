#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Hello");
}

void loop() {
  // put your main code here, to run repeatedly:

}
