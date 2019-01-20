#ifndef SRC_TEST_UNIT_ENTITIES_BARTEST_H_
#define SRC_TEST_UNIT_ENTITIES_BARTEST_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class BarTest : public testing::Test
{
public:
    BarTest();
    virtual ~BarTest();
};

}

#endif
