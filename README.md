# Slimme Airco Controller met Webvisualisatie 🌡️💨💡

Dit Arduino-project stuurt een airco aan op basis van temperatuur en gebruikersinput via een drukknop. Daarnaast worden de status van de airco, het raam, en de LEDs doorgestuurd naar **JsonBin.io** en visueel weergegeven op een eenvoudige website.

## 📦 Inhoud

- `actuator.h / actuator.cpp` – stuurt een airco/motor aan en 3 status-LEDs (groen, rood, blauw)
- `sensor.h / sensor.cpp` – leest een temperatuursensor en een drukknop uit
- `JSONAPI.h / JSONAPI.cpp` – stuurt data naar JsonBin.io via WiFi
- `index.html / styles.css` – toont de data van de airco, temperatuur, drukknop en LED-status op een overzichtelijke webpagina

---

## 🔧 Hardwarebenodigdheden

| Onderdeel           | Aantal | Beschrijving                       |
|---------------------|--------|------------------------------------|
| Arduino (ESP32/ESP8266) | 1      | Voor WiFi-connectiviteit          |
| Temperatuursensor   | 1      | b.v. TMP36 of analoog thermistor  |
| Drukknop            | 1      | Simuleert 'raam open'             |
| LEDs                | 3      | Groen (aan), Rood (uit), Blauw (waarschuwing) |
| Weerstanden         | 3      | Voor de LEDs                      |
| Motor of Airco-actor| 1      | Wordt gestuurd op basis van temperatuur |
| WiFi-netwerk        | 1      | Om data te versturen naar JsonBin.io |

---

## ⚙️ Software Setup

1. **Libraries**:
   - Arduino standaardbibliotheek
   - WiFi (ESP32 of ESP8266 afhankelijk van je board)
   - ArduinoJSON (indien gewenst voor betere JSON-opbouw)

2. **JsonBin.io setup**:
   - Maak een account op [jsonbin.io](https://jsonbin.io)
   - Maak een nieuwe bin aan
   - Noteer jouw **bin ID** en **X-Master-Key**

3. **Code aanpassen**:
   In `main.cpp`:
   ```cpp
   JsonbinSender sender("SSID", "Wachtwoord", "binId", "X-Master-Key");
   ```

---

## 📡 Functionaliteit

| Sensor/Actuator | Functie |
|-----------------|---------|
| Temperatuursensor | Meet omgevingstemperatuur |
| Drukknop         | Simuleert of raam open/dicht is |
| LEDs             | Groen = airco aan, Rood = uit, Blauw = waarschuwing |
| Motor/Airco      | Wordt ingeschakeld als temperatuur ≥ 25 °C en raam is gesloten |
| WiFi             | Stuurt live gegevens naar JsonBin |
| Webpagina        | Toont temperatuur, knopstatus, raamstatus, aircostatus en LED-status |

---

## 🌐 Website (Frontend)

Bestand: `index.html`

Toont live status van het systeem via data die van JsonBin wordt opgehaald met JavaScript. De website vernieuwt elke 60 seconden automatisch. Je ziet onder andere:

- 🌡️ Temperatuur
- 🔘 Knopstatus
- 💡 LED-statussen (groen, rood, blauw)
- 🪟 Raamstatus
- ❄️ Airco aan/uit

---

## 💡 Uitbreidingen

- Gebruik een grafiekbibliotheek zoals Chart.js om historische temperaturen te visualiseren
- Voeg een timer toe om te loggen wanneer de airco hoelang actief is geweest
- Voeg ESPAsyncWebServer toe voor lokale hosting zonder JsonBin

---

## 📷 Screenshot (voorbeeld)

> (Hier kan je een screenshot toevoegen van je website of breadboardopstelling)

---

## 👨‍💻 Gemaakt door

Ocean Dekeyser – VTI Brugge, richting Applicatie- en Databeheer  
Schoolproject 2025
