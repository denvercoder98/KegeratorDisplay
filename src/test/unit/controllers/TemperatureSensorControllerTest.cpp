#include "TemperatureSensorControllerTest.h"
#include "TemperatureSensorMock.h"
#include "controllers/TemperatureSensorController.h"
#include "unit/interactors/TemperatureReadingObserverMock.h"

using ::testing::Return;
using ::testing::_;
using ::testing::NiceMock;

namespace KegeratorDisplay {

TemperatureSensorControllerTest::TemperatureSensorControllerTest() :
    m_sensor(NULL),
    m_observer(NULL),
    m_controller(NULL)
{
}

TemperatureSensorControllerTest::~TemperatureSensorControllerTest()
{
}

void TemperatureSensorControllerTest::SetUp()
{
    m_sensor = new NiceMock<TemperatureSensorMock>();
    m_observer = new NiceMock<TemperatureReadingObserverMock>();
    m_controller = new TemperatureSensorController(m_sensor, *m_observer, "C");
}

void TemperatureSensorControllerTest::TearDown()
{
    delete m_controller;
    delete m_observer;
}

TEST_F(TemperatureSensorControllerTest, Create)
{
}

TEST_F(TemperatureSensorControllerTest, ProcessReadsSensor)
{
    EXPECT_CALL(*m_sensor, read())
        .Times(1)
        .WillRepeatedly(Return(10));
    m_controller->process();
}

TEST_F(TemperatureSensorControllerTest, ProcessUpdatesTemperatureSensorObserver)
{
    ON_CALL(*m_sensor, read())
        .WillByDefault(Return(5));

    EXPECT_CALL(*m_observer, receiveTemperatureReading(_))
        .Times(1);

    m_controller->process();
}

TEST_F(TemperatureSensorControllerTest, ProcessUpdatesTemperatureSensorObserverWithCorrectValue10C)
{
    ON_CALL(*m_sensor, read())
        .WillByDefault(Return(10));

    EXPECT_CALL(*m_observer, receiveTemperatureReading(TemperatureUpdateRequest(10, "C")))
        .Times(1);

    m_controller->process();
}

TEST_F(TemperatureSensorControllerTest, ProcessUpdatesTemperatureSensorObserverWithCorrectValue11C)
{
    ON_CALL(*m_sensor, read())
        .WillByDefault(Return(11));

    EXPECT_CALL(*m_observer, receiveTemperatureReading(TemperatureUpdateRequest(11, "C")))
        .Times(1);

    m_controller->process();
}

TEST_F(TemperatureSensorControllerTest, ProcessUpdatesTemperatureSensorObserverWithCorrectUnit)
{
    ON_CALL(*m_sensor, read())
        .WillByDefault(Return(11));

    EXPECT_CALL(*m_observer, receiveTemperatureReading(TemperatureUpdateRequest(11, "C")))
        .Times(1);

    m_controller->process();
}

}
