#ifndef SRC_TEST_UNIT_DEVICES_ADCSENSORMCP3008TEST_H_
#define SRC_TEST_UNIT_DEVICES_ADCSENSORMCP3008TEST_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class AdcSensorMCP3008Test : public testing::Test
{
public:
    AdcSensorMCP3008Test();
    virtual ~AdcSensorMCP3008Test();
};

}

#endif
