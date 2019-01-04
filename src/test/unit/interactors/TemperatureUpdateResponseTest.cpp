#include "TemperatureUpdateResponseTest.h"
#include "interactors/TemperatureUpdateResponse.h"

namespace KegeratorDisplay {

TemperatureUpdateResponseTest::TemperatureUpdateResponseTest()
{
}

TemperatureUpdateResponseTest::~TemperatureUpdateResponseTest()
{
}

TEST_F(TemperatureUpdateResponseTest, Equals)
{
    TemperatureUpdateResponse a(1, "A");
    TemperatureUpdateResponse b(1, "A");
    EXPECT_EQ(a, b);
}

TEST_F(TemperatureUpdateResponseTest, NotEqualsTemp)
{
    TemperatureUpdateResponse a(1, "A");
    TemperatureUpdateResponse b(2, "A");
    EXPECT_FALSE(a == b);
}

TEST_F(TemperatureUpdateResponseTest, NotEqualsUnit)
{
    TemperatureUpdateResponse a(1, "A");
    TemperatureUpdateResponse b(1, "B");
    EXPECT_FALSE(a == b);
}

TEST_F(TemperatureUpdateResponseTest, Stream)
{
    TemperatureUpdateResponse b(1, "B");
    std::ostringstream str;
    str << b;
    EXPECT_EQ("[value: 1, unit: 'B']", str.str());
}

}
