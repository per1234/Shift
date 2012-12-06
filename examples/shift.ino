#include <Shift.h>

int dataPin = 1;
int latchPin = 2;
int clockPin = 3;

Shift shift(dataPin, latchPin, clockPin);

void setup() {
  shift.clear();
}

void loop() {
  for(int i=0; i<11; i++) {
    shift.begin();
    shift.setDigit(i);
    shift.end();
    delay(250);
  }
}
