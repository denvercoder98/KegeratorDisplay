#ifndef SRC_MAIN_CONTROLLERS_SENSORCONTROLLER_H_
#define SRC_MAIN_CONTROLLERS_SENSORCONTROLLER_H_

namespace KegeratorDisplay {

class SensorController
{
public:
    virtual ~SensorController() {};

    virtual void process() = 0;
};

}

#endif
