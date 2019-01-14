#ifndef SRC_TEST_CONTROLLER_DS18B20SENSORTEST_H_
#define SRC_TEST_CONTROLLER_DS18B20SENSORTEST_H_

#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace KegeratorDisplay {

class TemperatureSensorMock;
class TemperatureReadingObserverMock;
class TemperatureSensorController;

class TemperatureSensorControllerTest : public testing::Test
{
public:
    TemperatureSensorControllerTest();
    virtual ~TemperatureSensorControllerTest();

protected:
    void SetUp();
    void TearDown();

    TemperatureSensorMock* m_sensor;
    TemperatureReadingObserverMock* m_observer;
    TemperatureSensorController* m_controller;
};

}

#endif
