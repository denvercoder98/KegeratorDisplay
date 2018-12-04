#ifndef SRC_TEST_CONTROLLER_TEMPERATURESENSORMOCK_H_
#define SRC_TEST_CONTROLLER_TEMPERATURESENSORMOCK_H_

#include "controller/TemperatureSensor.h"
#include "gmock/gmock.h"

namespace KegeratorDisplay {

class TemperatureSensorMock : public TemperatureSensor
{
public:
    virtual ~TemperatureSensorMock() {};

    MOCK_METHOD0(read, int(void));
};

}

#endif
