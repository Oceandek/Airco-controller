#include "sensor.h"
#include <Arduino.h>
// Constructor voor Temperatuursensor
Temperatuursensor::Temperatuursensor() {
    initialized = false;
    temperatuur = 0.0;
}

// Initialiseer de AHT20-sensor
bool Temperatuursensor::begin() {
    Wire.begin(21, 22);  // ESP32 I2C pins (SDA=21, SCL=22)
    if (!aht.begin()) {
        // Sensor is niet gevonden of reageert niet
        Serial.println("AHT20 niet gevonden!");
        return false;
    } else {
        // Sensor is correct gestart
        Serial.println("AHT20 gevonden!");
        initialized = true;
        return true;
    }
}
// Haal de temperatuur op van de AHT20-sensor
float Temperatuursensor::gettemperatuursensor() {
    if (!initialized) {
        Serial.println("AHT20 niet geïnitialiseerd!");
        return -999;  // Foutwaarde
    }
    sensors_event_t humidity, temp;     // Structs voor het opslaan van metingen
    aht.getEvent(&humidity, &temp);     // Meet temperatuur en luchtvochtigheid
    temperatuur = temp.temperature;     // Bewaar temperatuur
    return temperatuur;                 // Geef gemeten temperatuur terug
}


// Constructor voor Drukknop – configureer pin als input met interne pull-upweerstand
Drukknop::Drukknop(int pinNum) {
    pin = pinNum;
    pinMode(pin, INPUT_PULLUP);  
}

// Lees de status van de knop
bool Drukknop::getdrukknopstatus() {
    return digitalRead(pin) == LOW;  // true als ingedrukt
}
