#include "RelativePressureBarTest.h"
#include "entities/RelativePressureBar.h"

namespace KegeratorDisplay {

RelativePressureBarTest::RelativePressureBarTest()
{
}

RelativePressureBarTest::~RelativePressureBarTest()
{
}

TEST_F(RelativePressureBarTest, Create)
{
    RelativePressureBar pressure(2);
}

TEST_F(RelativePressureBarTest, Equal)
{
    RelativePressureBar pressure1(1);
    RelativePressureBar pressure2(1);
    EXPECT_TRUE(pressure1 == pressure2);
}

TEST_F(RelativePressureBarTest, NotEqual)
{
    RelativePressureBar pressure1(1);
    RelativePressureBar pressure2(2);
    EXPECT_FALSE(pressure1 == pressure2);
}

TEST_F(RelativePressureBarTest, Stream)
{
    RelativePressureBar pressure(1);
    std::ostringstream stream;
    stream << pressure;
    EXPECT_EQ("[value: 1]", stream.str());
}


}
