#ifndef SRC_MAIN_CONTROLLER_ANALOGDIGITALCONVERTERSENSOR_H_
#define SRC_MAIN_CONTROLLER_ANALOGDIGITALCONVERTERSENSOR_H_

#include <string>

namespace KegeratorDisplay {

class AnalogDigitalConverterSensor
{
public:
    virtual ~AnalogDigitalConverterSensor() {};

    virtual unsigned int readChannel(unsigned int channel) = 0;
};

}

#endif
