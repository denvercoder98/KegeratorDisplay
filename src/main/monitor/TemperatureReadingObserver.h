#ifndef SRC_MAIN_MONITOR_TEMPERATUREREADINGOBSERVER_H
#define SRC_MAIN_MONITOR_TEMPERATUREREADINGOBSERVER_H

#include "TemperatureReading.h"

class TemperatureReadingObserver {
public:
    virtual void receiveTemperatureReading(const TemperatureReading& reading) = 0;
};

#endif

