#ifndef SENSOR_H
#define SENSOR_H

#include <Adafruit_AHTX0.h>
#include <Wire.h>

class Temperatuursensor {
private:
    Adafruit_AHTX0 aht;
    float temperatuur;
    bool initialized;

public:
    Temperatuursensor();
    bool begin(); 
    float gettemperatuursensor();  
    float getvochtigheid();  
};

class Drukknop {
private:
    int pin;

public:
    Drukknop(int pinNum);
    bool getdrukknopstatus();  
};

#endif
