#include "AdcReading10BitTest.h"
#include "interactors/AdcReading10Bit.h"
#include "interactors/InvalidAdcReadingValueException.h"

namespace KegeratorDisplay {

AdcReading10BitTest::AdcReading10BitTest()
{
}

AdcReading10BitTest::~AdcReading10BitTest()
{
}

TEST_F(AdcReading10BitTest, Equals)
{
    AdcReading10Bit a(10);
    AdcReading10Bit b(10);
    EXPECT_EQ(a, b);
}

TEST_F(AdcReading10BitTest, NotEquals)
{
    AdcReading10Bit a(10);
    AdcReading10Bit b(11);
    EXPECT_FALSE(a == b);
}

TEST_F(AdcReading10BitTest, ThrowsIfValueGreaterThan10Bit)
{
    EXPECT_THROW(AdcReading10Bit(1024), InvalidAdcReadingValueException);
}

TEST_F(AdcReading10BitTest, Stream)
{
    AdcReading10Bit a(10);
    std::ostringstream stream;
    stream << a;
    EXPECT_EQ("[value: '10']", stream.str());
}

}
