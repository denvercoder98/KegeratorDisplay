#ifndef SRC_MAIN_MONITOR_KEGERATOROBSERVER_H
#define SRC_MAIN_MONITOR_KEGERATOROBSERVER_H

#include "TemperatureUpdate.h"
#include "TapUpdate.h"

namespace KegeratorDisplay {

class KegeratorObserver {
public:
    virtual ~KegeratorObserver() {};

    virtual void updateTemperature(const TemperatureUpdate& temperature) = 0;
    virtual void updateTap(const TapUpdate& temperature) = 0;
};

}

#endif
