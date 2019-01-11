#ifndef SRC_MAIN_DEVICES_INVALIDADCSENSORMCP3008ARGUMENTEXCEPTION_H_
#define SRC_MAIN_DEVICES_INVALIDADCSENSORMCP3008ARGUMENTEXCEPTION_H_

#include "devices/DeviceException.h"

namespace KegeratorDisplay {

class InvalidAdcSensorMCP3008ArgumentException : public DeviceException
{
public:
    InvalidAdcSensorMCP3008ArgumentException(const std::string& message) :
        DeviceException(message) {};
    virtual ~InvalidAdcSensorMCP3008ArgumentException() throw() {};
};

}

#endif
