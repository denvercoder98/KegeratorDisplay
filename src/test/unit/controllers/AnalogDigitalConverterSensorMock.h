#ifndef SRC_TEST_UNIT_CONTROLLER_ANALOGDIGITALCONVERTERSENSORMOCK_H_
#define SRC_TEST_UNIT_CONTROLLER_ANALOGDIGITALCONVERTERSENSORMOCK_H_

#include "controllers/AnalogDigitalConverterSensor.h"

#include <gmock/gmock.h>

namespace KegeratorDisplay {

class AnalogDigitalConverterSensorMock : public AnalogDigitalConverterSensor
{
public:
    MOCK_METHOD1(readChannel, unsigned int(unsigned int));
};

}

#endif
