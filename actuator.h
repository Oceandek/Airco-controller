#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <Arduino.h>

class Actuator {
  private:
    int motorPin;

  public:
    Actuator(int motorpin);
    void begin();
    void aanzetten(bool aan);
};

class LEDS {
  private:
    int groenPin;
    int roodPin;
    int blauwPin;

  public:
    StatusLEDs(int groenPin, int roodPin);
    void begin();
    void groenAan();
    void roodAan();
    void blauwPin();
    void uit();
};

#endif

