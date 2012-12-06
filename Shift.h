#include <Arduino.h>

class Shift {
  public:
    Shift(int dataPin, int latchPin, int clockPin);
    void begin();
    void end();
    void write(byte val);
    void clear();
    void setDigit(int val);

  private:
    int _dataPin;
    int _latchPin;
    int _clockPin;
    byte _digits[12];
};


