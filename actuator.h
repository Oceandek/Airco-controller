#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <Arduino.h>

class AircoActuator {
  private:
    int motorPin;

  public:
    AircoActuator(int motorpin);
    void begin();
    void Aan(bool aan);
};

class Buzzer {
  private:
    int pin;

  public:
    Buzzer(int pin);
    void begin();
    void Aan(bool aan);
};

class LEDS {
  private:
    int groenPin;
    int roodPin;

  public:
    StatusLEDs(int groenPin, int roodPin);
    void begin();
    void groenAan();
    void roodAan();
    void allesUit();
};

#endif

