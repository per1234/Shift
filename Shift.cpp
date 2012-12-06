#include <Shift.h>

Shift::Shift(int dataPin, int latchPin, int clockPin) {
  _dataPin = dataPin;
  _latchPin = latchPin;
  _clockPin = clockPin;

  _digits = {
    0b11011110,
    0b00000110,
    0b11101010,
    0b01101110,
    0b00110110,
    0b01111100,
    0b11111100,
    0b00001110,
    0b11111110,
    0b01111110,
    0b00000001,
    0b00000000
  };

  pinMode(_dataPin, OUTPUT);
  pinMode(_latchPin, OUTPUT);
  pinMode(_clockPin, OUTPUT);
}

void Shift::begin() {
  digitalWrite(_latchPin, LOW);
}
void Shift::end() {
  digitalWrite(_latchPin, HIGH);
}
void Shift::write(byte val) {
  shiftOut(_dataPin, _clockPin, MSBFIRST, val);
}
void Shift::setDigit(int val) {
  write(_digits[val]);
}
void Shift::clear() {
  begin();
  write(_digits[11]);
  end();
}
