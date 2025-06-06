#include <Arduino.h>
#include "JSONAPI.h"
#include "actuator.h"
#include "sensor.h"

// JsonbinSender instellen met je gegevens
JsonbinSender sender("VTI-Guest", "Wifi0104", "6835ae4e8561e97a501c1c7d", "$2a$10$w30Ri0Qr84FdWX3uwwquC..Cp0OVIlTiHCSedLYFv6aYUkF2GQS2e");

// Sensor- en actuatorobjecten
Temperatuursensor tempSensor;
Drukknop knop(15); 
LEDs leds(2, 4, 5); 
Actuator airco(18);  

// LED-statusen bijhouden
bool groen = false;
bool blauw = false;
bool rood = false;

void setup() {
    Serial.begin(115200);
    sender.connectWiFi();

    tempSensor.begin();
    leds.begin();
    airco.begin();
}

void loop() {
    float temperatuur = tempSensor.gettemperatuursensor();
    bool knopstatus = knop.getdrukknopstatus();

    groen = false;
    blauw = false;
    rood = false;

    bool aircoAan = false;

    if (temperatuur >= 20.0 && knopstatus) {
        Serial.println("De airco is actief.");
        leds.groenaan();
        groen = true;
        airco.aanzetten(true);
        aircoAan = true;

    } else if (temperatuur >= 20.0 && !knopstatus) {
        Serial.println("De airco stuurt een waarschuwing.");
        leds.blauwKnipperen();
        leds.roodaan();

        blauw = true;  
        rood = true;
        airco.aanzetten(false);
        aircoAan = false;

    } else {
        Serial.println("De airco is uit.");

        leds.roodaan();
        rood = true;
        airco.aanzetten(false);
        aircoAan = false;

    }

    bool raamOpen = !knopstatus;

    // Stuur data naar Jsonbin
    sender.sendData(temperatuur, knopstatus, groen, blauw, rood, raamOpen, aircoAan);

    delay(20000); // Wacht 20 seconden
}
