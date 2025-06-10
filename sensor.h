#ifndef SENSOR_H
#define SENSOR_H

#include <Adafruit_AHTX0.h>
#include <Wire.h>

// Klasse voor de AHT20-sensor
class Temperatuursensor {
private:
    Adafruit_AHTX0 aht;       // AHT20 sensorobject
    float temperatuur;        // temperatuurwaarde
    bool initialized;         // Status of de sensor correct is geïnitialiseerd

public:
    Temperatuursensor();      // Constructor
    bool begin();             // Initialiseer de sensor 
    float gettemperatuursensor();  // Haal de temperatuur op 
};

// Klasse voor de drukknop
class Drukknop {
private:
    int pin;                  // GPIO-pin waarop de knop is aangesloten

public:
    Drukknop(int pinNum);     // Constructor met pinnummer als parameter
    bool getdrukknopstatus(); // Geeft true terug als de knop is ingedrukt
};

#endif
