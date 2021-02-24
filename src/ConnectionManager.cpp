//
// Created by Michel Vielmetter on 23.02.21.
//

#include <variant.h>
#include <SPI.h>
#include <WiFi101.h>
#include "ConnectionManager.h"


ConnectionManager::ConnectionManager(Scheduler taskScheduler) : taskScheduler(taskScheduler) {
    Serial.begin(9600);
    while (!Serial);

    this->wifiTask(1000, TASK_FOREVER, &establishWifiIfNeeded);
    this->establishWifiIfNeeded();
}

// Will fail if Wifi cannot be connected
[[noreturn]] void ConnectionManager::establishWifiIfNeeded() {
    if (WiFi.status() == WL_NO_SHIELD) {
        Serial.println("WiFi shield not present");
        while (true);
    }

    Task connectTask(WIFI_WAIT, )

    this->scheduler.add
}
