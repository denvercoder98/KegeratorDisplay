#ifndef SRC_MAIN_CONTROLLER_INVALIDDS18B20SENSORREADINGEXCEPTION_H_
#define SRC_MAIN_CONTROLLER_INVALIDDS18B20SENSORREADINGEXCEPTION_H_

#include "ControllerException.h"

namespace KegeratorDisplay {

class InvalidDS18B20SensorReadingException : public ControllerException
{
public:
    InvalidDS18B20SensorReadingException(const std::string& message) :
        ControllerException(message) {};
    virtual ~InvalidDS18B20SensorReadingException() throw() {};
};

}

#endif
