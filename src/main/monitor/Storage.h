#ifndef SRC_MAIN_MONITOR_STORAGE_H
#define SRC_MAIN_MONITOR_STORAGE_H

#include "Temperature.h"
#include "Tap.h"

namespace KegeratorDisplay {

class Storage {
public:
    virtual ~Storage() {};

    virtual Temperature* readTemperature() = 0;
    virtual Tap* readTap() = 0;
};

}

#endif
