#ifndef SRC_MAIN_CONTROLLERS_INVALIDSENSORSAMPLERARGUMENTEXCEPTION_H_
#define SRC_MAIN_CONTROLLERS_INVALIDSENSORSAMPLERARGUMENTEXCEPTION_H_

#include "ControllerException.h"

namespace KegeratorDisplay {

class InvalidSensorSamplerArgumentException: public ControllerException
{
public:
    InvalidSensorSamplerArgumentException(const std::string& message) :
        ControllerException(message) {};
    virtual ~InvalidSensorSamplerArgumentException() throw() {};
};

}

#endif
