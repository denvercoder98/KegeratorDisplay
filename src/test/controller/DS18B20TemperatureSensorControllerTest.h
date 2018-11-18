#ifndef SRC_TEST_CONTROLLER_DS18B20TEMPERATURESENSORCONTROLLERTEST_H_
#define SRC_TEST_CONTROLLER_DS18B20TEMPERATURESENSORCONTROLLERTEST_H_

#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace KegeratorDisplay {

class DS18B20TemperatureSensorMock;
class TemperatureReadingObserverMock;
class DS18B20TemperatureSensorController;

class DS18B20TemperatureSensorControllerTest : public testing::Test
{
public:
    DS18B20TemperatureSensorControllerTest();
    virtual ~DS18B20TemperatureSensorControllerTest();

protected:
    void SetUp();
    void TearDown();

    DS18B20TemperatureSensorMock* m_sensor;
    TemperatureReadingObserverMock* m_observer;
    DS18B20TemperatureSensorController* m_controller;
};

}

#endif
