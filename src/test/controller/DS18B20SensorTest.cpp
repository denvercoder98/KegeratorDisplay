#include "src/main/controller/DS18B20Sensor.h"
#include "DS18B20SensorReaderMock.h"
#include "DS18B20SensorTest.h"
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

DS18B20SensorTest::DS18B20SensorTest() :
    m_sensorReader(NULL),
    m_sensor(NULL)
{
}

DS18B20SensorTest::~DS18B20SensorTest()
{
}

void DS18B20SensorTest::SetUp()
{
    m_sensorReader = new NiceMock<DS18B20SensorReaderMock>();
    m_sensor = new DS18B20Sensor(m_sensorReader);
}

void DS18B20SensorTest::TearDown()
{
    delete m_sensor;
}

TEST_F(DS18B20SensorTest, Create)
{
}

TEST_F(DS18B20SensorTest, ControllerReadReadsSensor)
{
    EXPECT_CALL(*m_sensorReader, read())
        .Times(1)
        .WillRepeatedly(Return(RAW_SENSOR_READING_OK_10C));
    m_sensor->read();
}

TEST_F(DS18B20SensorTest, ProcessUpdatesTemperatureSensorObserverValidRead10C)
{
    ON_CALL(*m_sensorReader, read())
        .WillByDefault(Return(RAW_SENSOR_READING_OK_10C));

    EXPECT_EQ(10, m_sensor->read());
}

TEST_F(DS18B20SensorTest, ProcessUpdatesTemperatureSensorObserverWithCorrectValue11C)
{
    ON_CALL(*m_sensorReader, read())
        .WillByDefault(Return(RAW_SENSOR_READING_OK_11C));

    EXPECT_EQ(11, m_sensor->read());
}

TEST_F(DS18B20SensorTest, MissingSensorTemperatureThrows)
{
    ON_CALL(*m_sensorReader, read())
        .WillByDefault(Return(RAW_SENSOR_READING_MISSING_TEMPERATURE));

    EXPECT_THROW(m_sensor->read(), InvalidDS18B20SensorReadingException);
}

TEST_F(DS18B20SensorTest, TooLongSensorTemperatureThrows)
{
    ON_CALL(*m_sensorReader, read())
        .WillByDefault(Return(RAW_SENSOR_READING_INVALID_TEMPERATURE_TOO_LONG));

    EXPECT_THROW(m_sensor->read(), InvalidDS18B20SensorReadingException);
}

TEST_F(DS18B20SensorTest, InvalidIntegerSensorTemperatureThrows)
{
    ON_CALL(*m_sensorReader, read())
        .WillByDefault(Return(RAW_SENSOR_READING_INVALID_TEMPERATURE_NOT_INTEGER));

    EXPECT_THROW(m_sensor->read(), InvalidDS18B20SensorReadingException);
}


}
