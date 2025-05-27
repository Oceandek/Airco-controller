#include <Arduino.h>
#include "JsonbinSender.h"
#include "actuator.h"
#include "sensor.h"

// JsonbinSender instellen met je gegevens
JsonbinSender sender("VTI-Guest", "Wifi0104", "6835ae4e8561e97a501c1c7d", "$2a$10$w30Ri0Qr84FdWX3uwwquC..Cp0OVIlTiHCSedLYFv6aYUkF2GQS2e");

// Sensor- en actuatorobjecten
Temperatuursensor tempSensor;
Drukknop knop(15); // Gebruik de juiste pin voor de knop

void setup() {
    Serial.begin(115200);
    sender.connectWiFi();

    if (tempSensor.begin()) {
        Serial.println("AHT sensor geïnitialiseerd!");
    } else {
        Serial.println("AHT sensor NIET geïnitialiseerd!");
    }

    leds.uit();
    leds.RoodAan();
}

void loop() {
    float temperatuur = tempSensor.gettemperatuursensor();
    bool knopstatus = knop.getdrukknopstatus();

    // Stuur gegevens naar Jsonbin.io
    sender.stuurData(temperatuur, knopstatus, leds.isAan(), raam.isOpen(), airco.isAan());

    // Actuatorlogica
    if (temperatuur >= 25.0 && knopstatus) {
        Serial.println("De airco is actief.");
        leds.groenAan();
    } else if (temperatuur >= 25.0 && !knopstatus) {
        Serial.println("De airco stuurt een waarschuwing.");
        leds.blauwAan();
    } else {
        leds.roodAan();
    }

    delay(60000); // Wacht 1 minuut voordat je opnieuw meet en verstuurt
}
