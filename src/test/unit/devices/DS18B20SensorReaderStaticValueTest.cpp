#include "DS18B20SensorReaderStaticValueTest.h"

namespace KegeratorDisplay {

DS18B20SensorReaderStaticValueTest::DS18B20SensorReaderStaticValueTest()
{
}

DS18B20SensorReaderStaticValueTest::~DS18B20SensorReaderStaticValueTest()
{
}

TEST_F(DS18B20SensorReaderStaticValueTest, Create)
{
    DS18B20SensorReaderStaticValue sensor;
}

TEST_F(DS18B20SensorReaderStaticValueTest, GetStaticValue)
{
    std::string expected = "7f 01 4b 46 7f ff 0c 10 ba : crc=ba YES\n7f 01 4b 46 7f ff 0c 10 ba t=10000\n";
    DS18B20SensorReaderStaticValue sensor;
    EXPECT_EQ(sensor.read(), expected);
}

}
