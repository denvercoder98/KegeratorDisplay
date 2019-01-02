#include "TapViewModelTest.h"
#include "presenter/TapViewModel.h"

namespace KegeratorDisplay {

TapViewModelTest::TapViewModelTest()
{
}

TapViewModelTest::~TapViewModelTest()
{
}

TEST_F(TapViewModelTest, Equal)
{
    TapViewModel m;
    m.leftTap.abv = "1";
    m.leftTap.beerName = "abc";
    m.leftTap.brewDate = "2";
    m.leftTap.brewerName = "123";
    m.leftTap.empty = false;
    m.leftTap.fg = "3";
    m.leftTap.ibu = "4";
    m.leftTap.side = "left";
    m.leftTap.tapDate = "5";

    m.rightTap.abv = "12";
    m.rightTap.beerName = "abc2";
    m.rightTap.brewDate = "22";
    m.rightTap.brewerName = "1232";
    m.rightTap.empty = false;
    m.rightTap.fg = "32";
    m.rightTap.ibu = "42";
    m.rightTap.side = "right";
    m.rightTap.tapDate = "52";

    TapViewModel expected;
    expected.leftTap.abv = "1";
    expected.leftTap.beerName = "abc";
    expected.leftTap.brewDate = "2";
    expected.leftTap.brewerName = "123";
    expected.leftTap.empty = false;
    expected.leftTap.fg = "3";
    expected.leftTap.ibu = "4";
    expected.leftTap.side = "left";
    expected.leftTap.tapDate = "5";

    expected.rightTap.abv = "12";
    expected.rightTap.beerName = "abc2";
    expected.rightTap.brewDate = "22";
    expected.rightTap.brewerName = "1232";
    expected.rightTap.empty = false;
    expected.rightTap.fg = "32";
    expected.rightTap.ibu = "42";
    expected.rightTap.side = "right";
    expected.rightTap.tapDate = "52";

    EXPECT_TRUE(expected == m);
}

TEST_F(TapViewModelTest, NotEqual)
{
    TapViewModel m;
    m.leftTap.abv = "1";
    m.leftTap.beerName = "abc";
    m.leftTap.brewDate = "2";
    m.leftTap.brewerName = "123";
    m.leftTap.empty = false;
    m.leftTap.fg = "3";
    m.leftTap.ibu = "4";
    m.leftTap.side = "left";
    m.leftTap.tapDate = "51";

    m.rightTap.abv = "12";
    m.rightTap.beerName = "abc2";
    m.rightTap.brewDate = "22";
    m.rightTap.brewerName = "1232";
    m.rightTap.empty = false;
    m.rightTap.fg = "32";
    m.rightTap.ibu = "42";
    m.rightTap.side = "right";
    m.rightTap.tapDate = "52";

    TapViewModel expected;
    expected.leftTap.abv = "1";
    expected.leftTap.beerName = "abc";
    expected.leftTap.brewDate = "2";
    expected.leftTap.brewerName = "123";
    expected.leftTap.empty = false;
    expected.leftTap.fg = "3";
    expected.leftTap.ibu = "4";
    expected.leftTap.side = "left";
    expected.leftTap.tapDate = "5";

    expected.rightTap.abv = "12";
    expected.rightTap.beerName = "abc2";
    expected.rightTap.brewDate = "22";
    expected.rightTap.brewerName = "1232";
    expected.rightTap.empty = false;
    expected.rightTap.fg = "32";
    expected.rightTap.ibu = "42";
    expected.rightTap.side = "right";
    expected.rightTap.tapDate = "52";

    EXPECT_FALSE(expected == m);
}

TEST_F(TapViewModelTest, Stream)
{
    TapViewModel m;
    m.leftTap.abv = "1";
    m.leftTap.beerName = "abc";
    m.leftTap.brewDate = "2";
    m.leftTap.brewerName = "123";
    m.leftTap.empty = false;
    m.leftTap.fg = "3";
    m.leftTap.ibu = "4";
    m.leftTap.side = "left";
    m.leftTap.tapDate = "5";

    m.rightTap.abv = "12";
    m.rightTap.beerName = "abc2";
    m.rightTap.brewDate = "22";
    m.rightTap.brewerName = "1232";
    m.rightTap.empty = false;
    m.rightTap.fg = "32";
    m.rightTap.ibu = "42";
    m.rightTap.side = "right";
    m.rightTap.tapDate = "52";

    std::ostringstream str;
    str << m;
    std::string expected = "[leftTap: [empty: 0, side: left, name: 'abc', brewerName: '123', abv: '1', ibu: '4', brewDate: '2', tapDate: '5', fg: '3'], rightTap: [empty: 0, side: right, name: 'abc2', brewerName: '1232', abv: '12', ibu: '42', brewDate: '22', tapDate: '52', fg: '32']]";
    EXPECT_EQ(expected, str.str());
}

}
