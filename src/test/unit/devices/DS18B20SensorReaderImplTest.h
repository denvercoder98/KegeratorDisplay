#ifndef SRC_TEST_UNIT_DEVICES_DS18B20SENSORREADERIMPLTEST_H_
#define SRC_TEST_UNIT_DEVICES_DS18B20SENSORREADERIMPLTEST_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class DS18B20SensorReaderImplTest : public testing::Test
{
public:
    DS18B20SensorReaderImplTest();
    virtual ~DS18B20SensorReaderImplTest();
};

}

#endif
