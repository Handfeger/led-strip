//
// Created by Michel Vielmetter on 23.02.21.
//
#include <TaskScheduler.h>

#ifndef LED_STRIP_CONNECTIONMANAGER_H
#define LED_STRIP_CONNECTIONMANAGER_H

#define WIFI_WAIT   1000;

class ConnectionManager {
private:
    Scheduler taskScheduler;
    Task wifiTask;
public:
    ConnectionManager(Scheduler taskScheduler);

    [[noreturn]] void establishWifiIfNeeded();
};


#endif //LED_STRIP_CONNECTIONMANAGER_H
