//
// Created by Michel Vielmetter on 20.02.21.
//

#include <WiFi101.h>
#include <wifi.h>

// Connect to the WiFi
#include <secrets.h>

char ssid[] = SECRET_SSID;       // your network SSID (name)
char pass[] = SECRET_PASS;       // your network password (use for WPA, or use as key for WEP)
int status = WL_IDLE_STATUS;     // the WiFi radio's status



void establish_wifi() {
    if (WiFi.status() == WL_NO_SHIELD) {
        Serial.println("WiFi shield not present");
        while (true);
    }

    while (status != WL_CONNECTED) {
        Serial.print("Attempting to connect to WPA SSID: ");
        byte mac[6];

        WiFi.macAddress(mac);

        Serial.println("MAC address: ");

        printMacAddress(mac);
        Serial.println(ssid);
        status = WiFi.begin(ssid, pass);
        delay(10000);
    }
}

void printMacAddress(byte *mac) {
    for (int i = 5; i >= 0; i--) {
        if (mac[i] < 16) {
            Serial.print("0");
        }
        Serial.print(mac[i], HEX);
        if (i > 0) {
            Serial.print(":");
        }
    }
    Serial.println();
}
