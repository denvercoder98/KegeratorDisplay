#ifndef SRC_MAIN_MONITOR_STORAGE_H
#define SRC_MAIN_MONITOR_STORAGE_H

#include "Temperature.h"
#include "Tap.h"

namespace KegeratorDisplay {

class Storage {
public:
    virtual ~Storage() {};

    virtual Temperature* readTemperature() = 0;
    virtual void writeTemperature(Temperature* temperature) = 0;

    virtual Tap* readLeftTap() = 0;
    virtual void writeLeftTap(Tap*) = 0;

    virtual Tap* readRightTap() = 0;
    virtual void writeRightTap(Tap*) = 0;
};

}

#endif
