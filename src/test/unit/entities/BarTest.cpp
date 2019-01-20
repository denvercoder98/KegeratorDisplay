#include "BarTest.h"
#include <entities/Bar.h>

namespace KegeratorDisplay {

BarTest::BarTest()
{
}

BarTest::~BarTest()
{
}

TEST_F(BarTest, Create)
{
    Bar pressure(2);
}

TEST_F(BarTest, Equal)
{
    Bar pressure1(1);
    Bar pressure2(1);
    EXPECT_TRUE(pressure1 == pressure2);
}

TEST_F(BarTest, NotEqual)
{
    Bar pressure1(1);
    Bar pressure2(2);
    EXPECT_FALSE(pressure1 == pressure2);
}

TEST_F(BarTest, Stream)
{
    Bar pressure(1);
    std::ostringstream stream;
    stream << pressure;
    EXPECT_EQ("[value: 1.0]", stream.str());
}


}
