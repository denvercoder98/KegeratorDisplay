#include "SpecificGravityTest.h"
#include "monitor/SpecificGravity.h"
#include "monitor/InvalidSpecificGravityException.h"

namespace KegeratorDisplay {

SpecificGravityTest::SpecificGravityTest()
{
}

SpecificGravityTest::~SpecificGravityTest()
{
}

TEST_F(SpecificGravityTest, Create)
{
    SpecificGravity sg(1.010);
}

TEST_F(SpecificGravityTest, NegativeValueThrows)
{
    EXPECT_THROW(SpecificGravity sg(-1.010), InvalidSpecificGravityException);
}

TEST_F(SpecificGravityTest, ValueAboveTwoThrows)
{
    EXPECT_THROW(SpecificGravity sg(2.0), InvalidSpecificGravityException);
}

TEST_F(SpecificGravityTest, GetNormalValue)
{
    EXPECT_EQ("1.010", SpecificGravity(1.010).value());
}

TEST_F(SpecificGravityTest, GetZeroValue)
{
    EXPECT_EQ("0.000", SpecificGravity(0).value());
}

}
