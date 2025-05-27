#include <Arduino.h>
#include "JSONAPI.h"
#include "actuator.h"
#include "sensor.h"

// JsonbinSender instellen met je gegevens
JsonbinSender sender("VTI-Guest", "Wifi0104", "6835ae4e8561e97a501c1c7d", "$2a$10$w30Ri0Qr84FdWX3uwwquC..Cp0OVIlTiHCSedLYFv6aYUkF2GQS2e");

// Sensor- en actuatorobjecten
Temperatuursensor tempSensor;
Drukknop knop(15); // Pas pin aan voor de drukknop
LEDS leds(2, 3, 4); // Pas aan naar je echte LED-pinnen
Actuator airco(5);  // Pas aan naar je motorPin

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

    // Bepaal logica
    bool aircoAan = false;
    if (temperatuur >= 25.0 && knopstatus) {
        Serial.println("De airco is actief.");
        leds.groenaan();
        airco.aanzetten(true);
        aircoAan = true;

    } 

    else if (temperatuur >= 25.0 && !knopstatus) {
        Serial.println("De airco stuurt een waarschuwing.");
        leds.blauwknipperen();
        airco.aanzetten(false);

    } 

    else {
        leds.roodaan();
        airco.aanzetten(false);
    }

    // Simuleer raamstatus (drukknop = raam open/dicht)
    bool raamOpen = !knopstatus;

    // Stuur data naar Jsonbin
    sender.sendData(temperatuur, knopstatus, groen, blauw, rood, raamOpen, aircoAan);

    delay(60000); // Wacht 1 minuut
}
