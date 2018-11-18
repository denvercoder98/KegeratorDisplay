#ifndef SRC_MAIN_MONITOR_TEMPERATUREREADINGOBSERVER_H
#define SRC_MAIN_MONITOR_TEMPERATUREREADINGOBSERVER_H

#include "TemperatureReading.h"

namespace KegeratorDisplay {

class TemperatureReadingObserver
{
public:
    virtual ~TemperatureReadingObserver() {};

    virtual void receiveTemperatureReading(const TemperatureReading& reading) = 0;
};

}

#endif
