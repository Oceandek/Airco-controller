#include <arduino.h>

#include "actuator.h"
#include "sensor.h"

#include <iostream>
#include <string>
using namespace std;


void setup() {
    
    temperatuursensor (26.0);
    drukknopstatus = (HIGH);

    leds.uit();
    leds.RoodAan();

    if (temperatuursensor.gettemperatuursensor() >= 25.0 && getdrukknopstatus() digitalRead(pin) == HIGH;)
    {
        cout << "De airco is actief." << endl;
        (groenAan());
    }

    else {
        (RoodAan());
    }


    if (temperatuursensor.gettemperatuursensor() >= 25.0 AND getdrukknopstatus() digitalRead(pin) == LOW;)
    {
        cout << "De airco stuurt een waarschuwing." << endl;
        (BlauwAan());
    }

    else {
        (RoodAan());
    }

    return 0;
}
