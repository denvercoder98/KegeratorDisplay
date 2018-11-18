#ifndef SRC_TEST_CONTROLLER_DS18B20TEMPERATURESENSORMOCK_H_
#define SRC_TEST_CONTROLLER_DS18B20TEMPERATURESENSORMOCK_H_

#include "src/main/controller/DS18B20TemperatureSensor.h"
#include "gmock/gmock.h"

namespace KegeratorDisplay {

class DS18B20TemperatureSensorMock : public DS18B20TemperatureSensor
{
public:
    MOCK_METHOD0(read, std::string(void));
};

}

#endif
