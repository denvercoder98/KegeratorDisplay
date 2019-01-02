#include "ScreenTouchedResponseTest.h"
#include "interactors/ScreenTouchedResponse.h"

namespace KegeratorDisplay {

ScreenTouchedResponseTest::ScreenTouchedResponseTest()
{
}

ScreenTouchedResponseTest::~ScreenTouchedResponseTest()
{
}

TEST_F(ScreenTouchedResponseTest, ToString)
{
    std::string expected = "[buttonsEnabled: 1]";
    ScreenTouchedResponse response(true);
    std::ostringstream ostr;
    ostr << response;
    EXPECT_EQ(expected, ostr.str());
}

}
