#ifndef SRC_MAIN_MONITOR_STORAGE_H
#define SRC_MAIN_MONITOR_STORAGE_H

#include "Temperature.h"

namespace KegeratorDisplay {

class Storage {
public:
    virtual ~Storage() {};

    virtual Temperature* readTemperature() = 0;
};

}

#endif
