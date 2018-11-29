#ifndef SRC_MAIN_INTERACTORS_PRESENTER_H
#define SRC_MAIN_INTERACTORS_PRESENTER_H

#include "TapUpdateResponse.h"
#include "TapClearResponse.h"
#include "TemperatureUpdateResponse.h"

namespace KegeratorDisplay {

class Presenter {
public:
    virtual ~Presenter() {};

    virtual void updateTap(const TapUpdateResponse& response) = 0;
    virtual void clearTap(const TapClearResponse& response) = 0;

    virtual void updateTemperature(const TemperatureUpdateResponse& response) = 0;
};

}

#endif
