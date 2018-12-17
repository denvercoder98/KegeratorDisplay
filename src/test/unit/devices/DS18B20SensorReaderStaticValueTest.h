#ifndef SRC_TEST_UNIT_DEVICES_DS18B20SENSORREADERSTATICVALUETEST_H_
#define SRC_TEST_UNIT_DEVICES_DS18B20SENSORREADERSTATICVALUETEST_H_

#include "devices/DS18B20SensorReaderStaticValue.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class DS18B20SensorReaderStaticValueTest : public testing::Test
{
public:
    DS18B20SensorReaderStaticValueTest();
    virtual ~DS18B20SensorReaderStaticValueTest();
};

}

#endif
