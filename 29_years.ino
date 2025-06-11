#include <SevSeg.h>
SevSeg sevseg;

void setup() {
  byte digits = 4;
  byte DigitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  sevseg.begin(COMMON_CATHODE, digits, DigitPins, segmentPins);
  sevseg.setBrightness(10);
}

void loop() {
  static long timer = millis();
  static long decimals = 0;
  if(millis() - timer >= 100) {
    timer += 7;
    decimals++;
    if(decimals > 2900) {
      decimals = 2900;
    }
    sevseg.setNumber(decimals, 2);
  }
  sevseg.refreshDisplay();
}