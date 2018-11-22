#ifndef SRC_TEST_CONTROLLER_DS18B20SENSORTEST_H_
#define SRC_TEST_CONTROLLER_DS18B20SENSORTEST_H_

#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace KegeratorDisplay {

class DS18B20SensorReaderMock;
class DS18B20Sensor;

class DS18B20SensorTest : public testing::Test
{
public:
    DS18B20SensorTest();
    virtual ~DS18B20SensorTest();

protected:
    void SetUp();
    void TearDown();

    DS18B20SensorReaderMock* m_sensorReader;
    DS18B20Sensor* m_sensor;
};

}

#endif
