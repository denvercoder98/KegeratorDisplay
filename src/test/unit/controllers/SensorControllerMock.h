#ifndef SRC_TEST_CONTROLLER_SENSORCONTROLLERMOCK_H_
#define SRC_TEST_CONTROLLER_SENSORCONTROLLERMOCK_H_

#include "controllers/SensorController.h"

#include "gmock/gmock.h"

namespace KegeratorDisplay {

class SensorControllerMock : public SensorController
{
public:
    MOCK_METHOD0(process, void(void));
};

}

#endif
