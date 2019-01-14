#ifndef SRC_MAIN_CONTROLLER_INVALIDDS18B20SENSORREADINGEXCEPTION_H_
#define SRC_MAIN_CONTROLLER_INVALIDDS18B20SENSORREADINGEXCEPTION_H_

#include "DeviceException.h"

namespace KegeratorDisplay {

class InvalidDS18B20SensorReadingException : public DeviceException
{
public:
    InvalidDS18B20SensorReadingException(const std::string& message) :
        DeviceException(message) {};
    virtual ~InvalidDS18B20SensorReadingException() throw() {};
};

}

#endif
