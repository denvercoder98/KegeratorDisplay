#include "DS18B20TemperatureSensorControllerTest.h"
#include "DS18B20TemperatureSensorMock.h"
#include "src/test/monitor/TemperatureReadingObserverMock.h"
#include "src/main/controller/DS18B20TemperatureSensorController.h"
#include "src/main/controller/InvalidDS18B20SensorReadingException.h"

using ::testing::Return;
using ::testing::_;
using ::testing::NiceMock;

#define RAW_SENSOR_READING_OK_10C "7f 01 4b 46 7f ff 0c 10 ba : crc=ba YES\n7f 01 4b 46 7f ff 0c 10 ba t=10000\n"
#define RAW_SENSOR_READING_OK_11C "7f 01 4b 46 7f ff 0c 10 ba : crc=ba YES\n7f 01 4b 46 7f ff 0c 10 ba t=11000\n"
#define RAW_SENSOR_READING_MISSING_TEMPERATURE "7f 01 4b 46 7f ff 0c 10 ba : crc=ba YES\n7f 01 4b 46 7f ff 0c 10 ba\n"
#define RAW_SENSOR_READING_INVALID_TEMPERATURE_TOO_LONG "7f 01 4b 46 7f ff 0c 10 ba : crc=ba YES\n7f 01 4b 46 7f ff 0c 10 ba t=110001\n"
#define RAW_SENSOR_READING_INVALID_TEMPERATURE_NOT_INTEGER "7f 01 4b 46 7f ff 0c 10 ba : crc=ba YES\n7f 01 4b 46 7f ff 0c 10 ba t=110a0\n"

namespace KegeratorDisplay {

DS18B20TemperatureSensorControllerTest::DS18B20TemperatureSensorControllerTest() :
    m_sensor(NULL),
    m_observer(NULL),
    m_controller(NULL)
{
}

DS18B20TemperatureSensorControllerTest::~DS18B20TemperatureSensorControllerTest()
{
}

void DS18B20TemperatureSensorControllerTest::SetUp()
{
    m_sensor = new NiceMock<DS18B20TemperatureSensorMock>();
    m_observer = new NiceMock<TemperatureReadingObserverMock>();
    m_controller = new DS18B20TemperatureSensorController(m_observer, m_sensor);
}

void DS18B20TemperatureSensorControllerTest::TearDown()
{
    delete m_observer;
    delete m_controller;
}

TEST_F(DS18B20TemperatureSensorControllerTest, Create)
{
}

TEST_F(DS18B20TemperatureSensorControllerTest, ProcessReadsSensor)
{
    EXPECT_CALL(*m_sensor, read())
        .Times(1)
        .WillRepeatedly(Return(RAW_SENSOR_READING_OK_10C));
    m_controller->process();
}

TEST_F(DS18B20TemperatureSensorControllerTest, ProcessUpdatesTemperatureSensorObserver)
{
    ON_CALL(*m_sensor, read())
        .WillByDefault(Return(RAW_SENSOR_READING_OK_10C));

    EXPECT_CALL(*m_observer, receiveTemperatureReading(_))
        .Times(1);

    m_controller->process();
}

TEST_F(DS18B20TemperatureSensorControllerTest, ProcessUpdatesTemperatureSensorObserverWithCorrectValue10C)
{
    ON_CALL(*m_sensor, read())
        .WillByDefault(Return(RAW_SENSOR_READING_OK_10C));

    EXPECT_CALL(*m_observer, receiveTemperatureReading(TemperatureReading(10)))
        .Times(1);

    m_controller->process();
}

TEST_F(DS18B20TemperatureSensorControllerTest, ProcessUpdatesTemperatureSensorObserverWithCorrectValue11C)
{
    ON_CALL(*m_sensor, read())
        .WillByDefault(Return(RAW_SENSOR_READING_OK_11C));

    EXPECT_CALL(*m_observer, receiveTemperatureReading(TemperatureReading(11)))
        .Times(1);

    m_controller->process();
}

TEST_F(DS18B20TemperatureSensorControllerTest, MissingSensorTemperatureThrows)
{
    ON_CALL(*m_sensor, read())
        .WillByDefault(Return(RAW_SENSOR_READING_MISSING_TEMPERATURE));

    EXPECT_THROW(m_controller->process(), InvalidDS18B20SensorReadingException);
}

TEST_F(DS18B20TemperatureSensorControllerTest, TooLongSensorTemperatureThrows)
{
    ON_CALL(*m_sensor, read())
        .WillByDefault(Return(RAW_SENSOR_READING_INVALID_TEMPERATURE_TOO_LONG));

    EXPECT_THROW(m_controller->process(), InvalidDS18B20SensorReadingException);
}

TEST_F(DS18B20TemperatureSensorControllerTest, InvalidIntegerSensorTemperatureThrows)
{
    ON_CALL(*m_sensor, read())
        .WillByDefault(Return(RAW_SENSOR_READING_INVALID_TEMPERATURE_NOT_INTEGER));

    EXPECT_THROW(m_controller->process(), InvalidDS18B20SensorReadingException);
}


}
