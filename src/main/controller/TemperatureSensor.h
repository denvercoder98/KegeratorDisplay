#ifndef SRC_MAIN_CONTROLLER_TEMPERATURESENSOR_H_
#define SRC_MAIN_CONTROLLER_TEMPERATURESENSOR_H_

namespace KegeratorDisplay {

class TemperatureSensor
{
public:
    virtual ~TemperatureSensor() {};

    virtual int read() = 0;
};

}

#endif
