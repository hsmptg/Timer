#include "Timer.h"
#include "Arduino.h"

Timer::Timer(callbackType timeout) {
  _delay = 0;
  _timeout = timeout;
}

void Timer::repeat(unsigned long msDelay) {
  _delay = msDelay;
  _repeat = true;
  _last = millis();
}

void Timer::timeout(unsigned long msDelay) {
  _delay = msDelay;
  _repeat = false;
  _last = millis();
}

void Timer::update() {
  if (_delay && (millis() - _last > _delay)) {
    _last += _delay;
    _timeout();
    if (!_repeat)
      _delay = 0;
  }
}

unsigned long Timer::ms() {
  return millis() - _last;
}
