#include "sensor.h"
#include <Arduino.h>

Temperatuursensor::Temperatuursensor() {
    initialized = false;
    temperatuur = 0.0;
}

bool Temperatuursensor::begin() {
    Wire.begin(21, 22);  // ESP32 I2C pins (SDA=21, SCL=22)
    if (!aht.begin()) {
        Serial.println("AHT20 niet gevonden!");
        return false;
    } else {
        Serial.println("AHT20 gevonden!");
        initialized = true;
        return true;
    }
}

float Temperatuursensor::gettemperatuursensor() {
    if (!initialized) {
        Serial.println("AHT20 niet geïnitialiseerd!");
        return -999;  // Foutwaarde
    }
    sensors_event_t humidity, temp;
    aht.getEvent(&humidity, &temp);
    temperatuur = temp.temperature;
    return temperatuur;
}



Drukknop::Drukknop(int pinNum) {
    pin = pinNum;
    pinMode(pin, INPUT_PULLUP);  
}

bool Drukknop::getdrukknopstatus() {
    return digitalRead(pin) == LOW;  // true als ingedrukt
}
