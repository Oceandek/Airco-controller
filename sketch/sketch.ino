#include "sensor.h"

Temperatuursensor temperatuursensor;
Drukknop drukknop(15);  // Bijvoorbeeld GPIO15 voor de knop

void setup() {
    Serial.begin(115200);
    Serial.println("Start Temperatuursensor + Drukknop test");

    if (!temperatuursensor.begin()) {
        Serial.println("AHT20 sensor niet gevonden, stop programma");
        while (1) delay(10);
    }
}

void loop() {
    float temp = temperatuursensor.gettemperatuursensor();
    bool knop = drukknop.getdrukknopstatus();

    Serial.print("Temperatuur: ");
    Serial.print(temp);
    Serial.println(" °C");

    Serial.print("Vochtigheid: ");
    Serial.println(" %");

    Serial.print("Knopstatus: ");
    Serial.println(knop ? "INGEDRUKT" : "NIET INGEDRUKT");

    delay(1000);
}
