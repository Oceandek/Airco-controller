#ifndef JSONAPI_H
#define JSONAPI_H

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

class JsonbinSender {
private:
    const char* ssid;
    const char* password;
    const char* binID;
    const char* apiKey;
    String url;

public:
    JsonbinSender(const char* wifiSSID, const char* wifiPassword, const char* bin, const char* key)
        : ssid(wifiSSID), password(wifiPassword), binID(bin), apiKey(key), url(String("https://api.jsonbin.io/v3/b/") + bin) {}

    void connectWiFi() {
        WiFi.begin(ssid, password);
        Serial.print("Verbinden met WiFi...");
        while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.print(".");
        }
        Serial.println("verbonden!");
    }

    void sendData(float temperatuur, bool knopwaarde, bool leds, bool raam, bool airco) {
        if (WiFi.status() == WL_CONNECTED) {
            HTTPClient http;

            // JSON payload opbouwen
            StaticJsonDocument<200> doc;
            doc["temperatuur"] = temperatuur;
            doc["knopwaarde"] = knopwaarde;
            doc["leds"] = leds;
            doc["raam"] = raam;
            doc["airco"] = airco;

            String jsonStr;
            serializeJson(doc, jsonStr);

            http.begin(url);
            http.addHeader("Content-Type", "application/json");
            http.addHeader("X-Master-Key", apiKey);

            int httpCode = http.PUT(jsonStr);

            if (httpCode > 0) {
                Serial.printf("Response code: %d\n", httpCode);
                String payload = http.getString();
                Serial.println(payload);
            } else {
                Serial.printf("Error bij versturen: %s\n", http.errorToString(httpCode).c_str());
            }

            http.end();
        } else {
            Serial.println("WiFi niet verbonden!");
        }
    }
};

#endif
