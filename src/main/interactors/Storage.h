#ifndef SRC_MAIN_INTERACTORS_STORAGE_H
#define SRC_MAIN_INTERACTORS_STORAGE_H

#include "entities/Temperature.h"
#include "entities/Tap.h"

namespace KegeratorDisplay {

class Storage {
public:
    virtual ~Storage() {};

    virtual Temperature* readTemperature() = 0;
    virtual void writeTemperature(Temperature* temperature) = 0;

    virtual Tap* readLeftTap() = 0;
    virtual void writeLeftTap(Tap*) = 0;
    virtual void clearLeftTap() = 0;

    virtual Tap* readRightTap() = 0;
    virtual void writeRightTap(Tap*) = 0;
    virtual void clearRightTap() = 0;
};

}

#endif
