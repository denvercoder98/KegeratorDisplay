#include "QTemperatureTest.h"
#include "view/qobjects/QTemperature.h"

namespace KegeratorDisplay {

QTemperatureTest::QTemperatureTest()
{
}

QTemperatureTest::~QTemperatureTest()
{
}

TEST_F(QTemperatureTest, Create)
{
    QTemperature temperature;
}

TEST_F(QTemperatureTest, DefaultTagEmpty)
{
    QTemperature temperature;
    EXPECT_EQ("", temperature.tag());
}

TEST_F(QTemperatureTest, SetTag)
{
    QTemperature temperature;
    temperature.setTag("abc123");
}

TEST_F(QTemperatureTest, GetTag)
{
    QTemperature temperature;
    temperature.setTag("abc123");
    EXPECT_EQ("abc123", temperature.tag());
}

TEST_F(QTemperatureTest, DefaultTemperatureEmpty)
{
    QTemperature temperature;
    EXPECT_EQ("", temperature.temperature());
}

TEST_F(QTemperatureTest, SetTemperature)
{
    QTemperature temperature;
    temperature.setTemperature("10");
}

TEST_F(QTemperatureTest, GetTemperature)
{
    QTemperature temperature;
    temperature.setTemperature("abc123");
    EXPECT_EQ("abc123", temperature.temperature());
}

TEST_F(QTemperatureTest, DefaultUnitEmpty)
{
    QTemperature temperature;
    EXPECT_EQ("", temperature.unit());
}

TEST_F(QTemperatureTest, SetUnit)
{
    QTemperature temperature;
    temperature.setUnit("bar");
}

TEST_F(QTemperatureTest, GetUnit)
{
    QTemperature temperature;
    temperature.setUnit("bar");
    EXPECT_EQ("bar", temperature.unit());
}

}
