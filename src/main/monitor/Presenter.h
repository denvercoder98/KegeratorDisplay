#ifndef SRC_MAIN_MONITOR_PRESENTER_H
#define SRC_MAIN_MONITOR_PRESENTER_H

#include <monitor/TapUpdateResponse.h>
#include <monitor/TemperatureUpdateResponse.h>

namespace KegeratorDisplay {

class Presenter {
public:
    virtual ~Presenter() {};

    virtual void updateTemperature(const TemperatureUpdateResponse& temperature) = 0;
    virtual void updateTap(const TapUpdateResponse& temperature) = 0;
};

}

#endif
