#include "actuator.h"
#include <Arduino.h>

Actuator::Actuator(int pin) {
    motorPin = pin;
}

void Actuator::begin() {
    pinMode(motorPin, OUTPUT);
    digitalWrite(motorPin, LOW);
}

void Actuator::aanzetten(bool aan) {
    digitalWrite(motorPin, HIGH);
}


LEDs::LEDs(int g, int r, int b) {
    groenPin = g;
    roodPin = r;
    blauwPin = b;
}

void LEDs::begin() {
    pinMode(groenPin, OUTPUT);
    pinMode(roodPin, OUTPUT);
    pinMode(blauwPin, OUTPUT);
    allesuit();
}

void LEDs::groenaan() {
    digitalWrite(groenPin, HIGH);
    digitalWrite(roodPin, LOW);
    digitalWrite(blauwPin, LOW);
}

void LEDs::roodaan() {
    digitalWrite(groenPin, LOW);
    digitalWrite(roodPin, HIGH);
    digitalWrite(blauwPin, LOW);
}

void LEDs::blauwPin() {
    for (int i = 0; i < 5; i++) {
        digitalWrite(blauwPin, HIGH);
        delay(200);
        digitalWrite(blauwPin, LOW);
        delay(200);
    }
}

void LEDs::allesuit() {
    digitalWrite(groenPin, LOW);
    digitalWrite(roodPin, LOW);
    digitalWrite(blauwPin, LOW);
}

