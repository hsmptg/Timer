#ifndef Timer_h
#define Timer_h

typedef void (*callbackType)();

class Timer {
private:
  callbackType _timeout;
  unsigned long _delay;
  unsigned long _last;
  bool _repeat;
public:
  Timer(callbackType timeout);
  void repeat(unsigned long msDelay);
  void timeout(unsigned long msDelay);
  void update();
  unsigned long ms();
};

#endif
