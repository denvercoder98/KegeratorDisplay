#include "DeviceTapDataTest.h"
#include "controllers/DeviceTapData.h"

namespace KegeratorDisplay {

DeviceTapDataTest::DeviceTapDataTest()
{
}

DeviceTapDataTest::~DeviceTapDataTest()
{
}

TEST_F(DeviceTapDataTest, Equals)
{
    DeviceTapData data1("1", "2", "3", "4", "5", "6", "7", "8");
    DeviceTapData data2("1", "2", "3", "4", "5", "6", "7", "8");
    EXPECT_EQ(data1, data2);
}

TEST_F(DeviceTapDataTest, NotEquals)
{
    DeviceTapData data1("1", "2", "3", "4", "5", "6", "7", "8");
    DeviceTapData data2("1", "2", "3", "4", "5", "6", "7", "81");
    EXPECT_NE(data1, data2);
}

TEST_F(DeviceTapDataTest, Stream)
{
    DeviceTapData data1("1", "2", "3", "4", "5", "6", "7", "8");
    std::ostringstream stream;
    stream << data1;
    std::string expected = "[name: '1', estVolume: '2', brewer: '3', abv: '4', ibu: '5', brewDate: '6', tapDate: '7', finalGravity: '8']";
    EXPECT_EQ(expected, stream.str());
}

}
