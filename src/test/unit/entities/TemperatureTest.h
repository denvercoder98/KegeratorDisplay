#ifndef SRC_TEST_UNIT_ENTITIES_TEMPERATURETEST_H_
#define SRC_TEST_UNIT_ENTITIES_TEMPERATURETEST_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class TemperatureTest : public testing::Test
{
public:
    TemperatureTest();
    virtual ~TemperatureTest();
};

}

#endif
