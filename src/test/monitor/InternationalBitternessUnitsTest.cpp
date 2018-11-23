#include "InternationalBitternessUnitsTest.h"
#include "monitor/InternationalBitternessUnits.h"
#include "monitor/InvalidInternationalBitternessUnitsException.h"

namespace KegeratorDisplay {

InternationalBitternessUnitsTest::InternationalBitternessUnitsTest()
{
}

InternationalBitternessUnitsTest::~InternationalBitternessUnitsTest()
{
}

TEST_F(InternationalBitternessUnitsTest, Create)
{
    InternationalBitternessUnits ibu(40);
}

TEST_F(InternationalBitternessUnitsTest, TooHighThrowsException)
{
    EXPECT_THROW(InternationalBitternessUnits(1000), InvalidInternationalBitternessUnitsException);
}

TEST_F(InternationalBitternessUnitsTest, GetValue)
{
    EXPECT_EQ(40, InternationalBitternessUnits(40).value());
}

}
