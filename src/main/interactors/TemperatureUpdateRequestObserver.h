#ifndef SRC_MAIN_INTERACTORS_TEMPERATUREREADINGOBSERVER_H
#define SRC_MAIN_INTERACTORS_TEMPERATUREREADINGOBSERVER_H

#include "TemperatureUpdateRequest.h"

namespace KegeratorDisplay {

class TemperatureUpdateRequestObserver
{
public:
    virtual ~TemperatureUpdateRequestObserver() {};

    virtual void receiveTemperatureReading(const TemperatureUpdateRequest& reading) = 0;
};

}

#endif
