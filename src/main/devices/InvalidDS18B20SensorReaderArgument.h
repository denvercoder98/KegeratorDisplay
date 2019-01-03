#ifndef SRC_MAIN_DEVICES_INVALIDDS18B20SENSORREADERARGUMENT_H_
#define SRC_MAIN_DEVICES_INVALIDDS18B20SENSORREADERARGUMENT_H_

#include "devices/DeviceException.h"

namespace KegeratorDisplay {

class InvalidDS18B20SensorReaderArgument: public DeviceException
{
public:
    InvalidDS18B20SensorReaderArgument(const std::string& message) :
        DeviceException(message) {};
    virtual ~InvalidDS18B20SensorReaderArgument() throw() {};
};

}

#endif
