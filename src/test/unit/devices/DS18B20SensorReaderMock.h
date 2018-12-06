#ifndef SRC_TEST_CONTROLLER_DS18B20SENSORREADERMOCK_H_
#define SRC_TEST_CONTROLLER_DS18B20SENSORREADERMOCK_H_

#include "devices/DS18B20SensorReader.h"
#include "gmock/gmock.h"

namespace KegeratorDisplay {

class DS18B20SensorReaderMock : public DS18B20SensorReader
{
public:
    MOCK_METHOD0(read, std::string(void));
};

}

#endif
