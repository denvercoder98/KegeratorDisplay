#include "GuiViewTemperatureModelTest.h"
#include "presenter/GuiViewTemperatureModel.h"

namespace KegeratorDisplay {

GuiViewTemperatureModelTest::GuiViewTemperatureModelTest()
{
}

GuiViewTemperatureModelTest::~GuiViewTemperatureModelTest()
{
}

TEST_F(GuiViewTemperatureModelTest, Stream)
{
    GuiViewTemperatureModel m;
    m.temperature = "10";
    m.temperatureTag = "Temp: ";
    m.temperatureUnit = "C";

    std::ostringstream str;
    str << m;
    EXPECT_EQ("[temperature: '10', temperatureTag: 'Temp: ', temperatureUnit: 'C']", str.str());
}

TEST_F(GuiViewTemperatureModelTest, Equal)
{
    GuiViewTemperatureModel first;
    first.temperature = "10";
    first.temperatureTag = "Temp: ";

    GuiViewTemperatureModel second;
    second.temperature = "10";
    second.temperatureTag = "Temp: ";

    EXPECT_TRUE(first == second);
}

TEST_F(GuiViewTemperatureModelTest, TempNotEqual)
{
    GuiViewTemperatureModel first;
    first.temperature = "10";
    first.temperatureTag = "Temp: ";

    GuiViewTemperatureModel second;
    second.temperature = "11";
    second.temperatureTag = "Temp: ";

    EXPECT_FALSE(first == second);
}

TEST_F(GuiViewTemperatureModelTest, UnitNotEqual)
{
    GuiViewTemperatureModel first;
    first.temperature = "10";
    first.temperatureTag = "Temp: ";
    first.temperatureUnit = "C";

    GuiViewTemperatureModel second;
    second.temperature = "11";
    second.temperatureTag = "Temp: ";
    second.temperatureUnit = "F";

    EXPECT_FALSE(first == second);
}

}
