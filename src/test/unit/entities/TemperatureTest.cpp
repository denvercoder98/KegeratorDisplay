#include "TemperatureTest.h"
#include "entities/Temperature.h"

namespace KegeratorDisplay {

TemperatureTest::TemperatureTest()
{
}

TemperatureTest::~TemperatureTest()
{
}

TEST_F(TemperatureTest, Create)
{
    Temperature t;
}

TEST_F(TemperatureTest, Equals)
{
    Temperature t1;
    t1.addReading(1);
    t1.setUnit("F");

    Temperature t2;
    t2.addReading(1);
    t2.setUnit("F");

    EXPECT_EQ(t1, t2);
}

TEST_F(TemperatureTest, NotEqualReading)
{
    Temperature t1;
    t1.addReading(1);
    t1.setUnit("F");

    Temperature t2;
    t2.setUnit("F");

    EXPECT_FALSE(t1 == t2);
}

TEST_F(TemperatureTest, NotEqualUnit)
{
    Temperature t1;
    t1.addReading(1);
    t1.setUnit("F");

    Temperature t2;
    t2.addReading(1);
    t2.setUnit("C");

    EXPECT_FALSE(t1 == t2);
}

TEST_F(TemperatureTest, SetUnit)
{
    Temperature t;
    t.setUnit("K");
}

TEST_F(TemperatureTest, GetUnit)
{
    Temperature t;
    t.setUnit("F");
    EXPECT_EQ("F", t.unit());
}

TEST_F(TemperatureTest, Stream)
{
    Temperature t;
    t.addReading(1);
    t.addReading(2);
    t.addReading(3);
    t.setUnit("F");

    std::ostringstream str;
    str << t;
    EXPECT_EQ("[lastReadings: 1, 2, 3, unit: 'F']", str.str());
}

}
