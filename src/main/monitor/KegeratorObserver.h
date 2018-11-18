#ifndef SRC_MAIN_MONITOR_KEGERATOROBSERVER_H
#define SRC_MAIN_MONITOR_KEGERATOROBSERVER_H

#include "TemperatureUpdate.h"

namespace KegeratorDisplay {

class KegeratorObserver {
public:
    virtual ~KegeratorObserver() {};

    virtual void update(const TemperatureUpdate& temperature) = 0;
};

}

#endif
