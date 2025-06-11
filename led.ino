#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

long msec = millis() / 7; 
int sec = 0;
int min = 0;
int hrs = 0;

int button_start = 8;
int button_stop  = 9;
int button_reset = 10;

bool Timer = false;

void setup() {
  pinMode(button_start, INPUT_PULLUP);
  pinMode(button_stop, INPUT_PULLUP);
  pinMode(button_reset, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.print("    ARDUINO    ");
  delay(1000);
  lcd.clear();
}

void loop() {
  if (digitalRead(button_start) == 0) {
    // hold to start
    Timer = true; // start timer
    delay(100);
  }

  if (digitalRead(button_stop) == 0) {
    // hold to stop
    Timer = false;
    delay(100);
  }

  if (digitalRead(button_reset) == 0) {
    // hold to reset
    sec = 0; min = 0; hrs = 0; // Reset Timer
    delay(100);
  }

  lcd.setCursor(4, 0);
  lcd.print((hrs/10)%10);
  lcd.print(hrs%10);
  lcd.print(":");
  lcd.print((min/10)%10);
  lcd.print(min%10);
  lcd.print(":");
  lcd.print((sec/10)%10);
  lcd.print(sec%10);

  if (Timer == true) {
    msec++;
    if(msec > 350) {
      msec = 0;
      sec++;
    }
    if(sec == 60) {
      sec = 0;
      min++;
    }

    if(min == 60) {
      min = 0;
      hrs++;
    }
  }
}