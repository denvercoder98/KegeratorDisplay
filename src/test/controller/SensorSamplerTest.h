#ifndef SRC_TEST_CONTROLLER_SENSORSAMPLERTEST_H_
#define SRC_TEST_CONTROLLER_SENSORSAMPLERTEST_H_

#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace KegeratorDisplay {

class SensorSampler;
class SensorControllerMock;

class SensorSamplerTest: public testing::Test
{
public:
    SensorSamplerTest();
    virtual ~SensorSamplerTest();

protected:
    void SetUp();
    void TearDown();

    SensorControllerMock* m_sensorController;
    SensorSampler* m_sampler;
};

}

#endif
