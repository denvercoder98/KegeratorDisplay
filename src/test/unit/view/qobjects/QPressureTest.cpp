#include "QPressureTest.h"
#include "view/qobjects/QPressure.h"

namespace KegeratorDisplay {

QPressureTest::QPressureTest()
{
}

QPressureTest::~QPressureTest()
{
}

TEST_F(QPressureTest, Create)
{
    QPressure pressure;
}

TEST_F(QPressureTest, DefaultTagEmpty)
{
    QPressure pressure;
    EXPECT_EQ("", pressure.tag());
}

TEST_F(QPressureTest, SetTag)
{
    QPressure pressure;
    pressure.setTag("abc123");
}

TEST_F(QPressureTest, GetTag)
{
    QPressure pressure;
    pressure.setTag("abc123");
    EXPECT_EQ("abc123", pressure.tag());
}

TEST_F(QPressureTest, DefaultPressureEmpty)
{
    QPressure pressure;
    EXPECT_EQ("", pressure.pressure());
}


TEST_F(QPressureTest, SetPressure)
{
    QPressure pressure;
    pressure.setPressure("123");
}

TEST_F(QPressureTest, GetPressure)
{
    QPressure pressure;
    pressure.setPressure("123");
    EXPECT_EQ("123", pressure.pressure());
}

TEST_F(QPressureTest, DefaultUnitEmpty)
{
    QPressure pressure;
    EXPECT_EQ("", pressure.unit());
}

TEST_F(QPressureTest, SetUnit)
{
    QPressure pressure;
    pressure.setUnit("bar");
}

TEST_F(QPressureTest, GetUnit)
{
    QPressure pressure;
    pressure.setUnit("bar");
    EXPECT_EQ("bar", pressure.unit());
}

}
