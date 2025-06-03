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

class LEDs {
  private:
    int groenPin;
    int roodPin;
    int blauwPin;

  public:
    LEDs(int groenPin, int roodPin, int blauwPin);
    void begin();
    void groenaan();
    void roodaan();
    void blauwKnipperen();
    void allesuit();
};

#endif

