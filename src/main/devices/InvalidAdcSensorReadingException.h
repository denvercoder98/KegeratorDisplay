#ifndef SRC_MAIN_DEVICES_INVALIDADCSENSORREADINGEXCEPTION_H_
#define SRC_MAIN_DEVICES_INVALIDADCSENSORREADINGEXCEPTION_H_

#include "DeviceException.h"

namespace KegeratorDisplay {

class InvalidAdcSensorReadingException : public DeviceException
{
public:
    InvalidAdcSensorReadingException(const std::string& message) :
        DeviceException(message) {};
    virtual ~InvalidAdcSensorReadingException() throw() {};
};

}

#endif
