#include "DS18B20SensorReaderStaticValue.h"

#define RAW_SENSOR_READING_OK_10C "7f 01 4b 46 7f ff 0c 10 ba : crc=ba YES\n7f 01 4b 46 7f ff 0c 10 ba t=10000\n"

namespace KegeratorDisplay {

DS18B20SensorReaderStaticValue::DS18B20SensorReaderStaticValue()
{
}

DS18B20SensorReaderStaticValue::~DS18B20SensorReaderStaticValue()
{
}

std::string DS18B20SensorReaderStaticValue::read()
{
    return RAW_SENSOR_READING_OK_10C;
}

}
