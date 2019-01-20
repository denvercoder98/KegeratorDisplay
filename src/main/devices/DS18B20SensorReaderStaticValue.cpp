#include "DS18B20SensorReaderStaticValue.h"

#define RAW_SENSOR_READING_OK_10C "7f 01 4b 46 7f ff 0c 10 ba : crc=ba YES\n7f 01 4b 46 7f ff 0c 10 ba t=10000\n"
#define RAW_SENSOR_READING_OK_9C "7f 01 4b 46 7f ff 0c 10 ba : crc=ba YES\n7f 01 4b 46 7f ff 0c 10 ba t=09000\n"

namespace KegeratorDisplay {

DS18B20SensorReaderStaticValue::DS18B20SensorReaderStaticValue() :
    m_cnt(0)
{
}

DS18B20SensorReaderStaticValue::~DS18B20SensorReaderStaticValue()
{
}

std::string DS18B20SensorReaderStaticValue::read()
{
    std::string rv;
    if (m_cnt < 4) {
        rv = RAW_SENSOR_READING_OK_10C;
    }
    else {
        rv = RAW_SENSOR_READING_OK_9C;
    }

    m_cnt = (++m_cnt) % 8;

    return rv;
}

}
