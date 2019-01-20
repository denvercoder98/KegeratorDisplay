#include "SpiReaderStaticValueTest.h"
#include "devices/SpiReaderStaticValue.h"

namespace KegeratorDisplay {

SpiReaderStaticValueTest::SpiReaderStaticValueTest()
{
}

SpiReaderStaticValueTest::~SpiReaderStaticValueTest()
{
}

TEST_F(SpiReaderStaticValueTest, Create)
{
    SpiReaderStaticValue spi;
}

TEST_F(SpiReaderStaticValueTest, IsSpiReader)
{
    SpiReaderStaticValue spi;
    SpiReader* base = dynamic_cast<SpiReader*>(&spi);
    EXPECT_FALSE(base == NULL);
}

TEST_F(SpiReaderStaticValueTest, ReadStaticValue512)
{
    SpiReaderStaticValue spi;
    const unsigned int bufferLength = 4;
    unsigned char expected[bufferLength] = "210";
    unsigned char buffer[bufferLength];
    spi.read(buffer, bufferLength);
    EXPECT_EQ(*expected, *buffer);
}

}
