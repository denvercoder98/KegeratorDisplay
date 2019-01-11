#ifndef SRC_MAIN_CONTROLLER_INVALIDANALOGDIGITALCONVERTERSENSORCONTROLLERARGUMENTEXCEPTION_H_
#define SRC_MAIN_CONTROLLER_INVALIDANALOGDIGITALCONVERTERSENSORCONTROLLERARGUMENTEXCEPTION_H_

#include <controller/ControllerException.h>

namespace KegeratorDisplay {

class InvalidAnalogDigitalConverterSensorControllerArgumentException: public ControllerException
{
public:
    InvalidAnalogDigitalConverterSensorControllerArgumentException(const std::string& message) :
        ControllerException(message) {};
    virtual ~InvalidAnalogDigitalConverterSensorControllerArgumentException() throw() {};
};

}

#endif
