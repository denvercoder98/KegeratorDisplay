#include "QTapTest.h"
#include "view/qobjects/QTap.h"

namespace KegeratorDisplay {

QTapTest::QTapTest()
{
}

QTapTest::~QTapTest()
{
}

TEST_F(QTapTest, Create)
{
    QTap tap;
}

TEST_F(QTapTest, NameDefaultEmpty)
{
    QTap tap;
    EXPECT_EQ("", tap.name());
}

TEST_F(QTapTest, SetName)
{
    QTap tap;
    tap.setName("abc123");
}

TEST_F(QTapTest, GetName)
{
    QTap tap;
    tap.setName("abc123");
    EXPECT_EQ("abc123", tap.name());
}

TEST_F(QTapTest, EstVolumeDefaultEmpty)
{
    QTap tap;
    EXPECT_EQ("", tap.estVolume());
}

TEST_F(QTapTest, SetEstVolume)
{
    QTap tap;
    tap.setEstVolume("Vol:");
}

TEST_F(QTapTest, GetEstVolume)
{
    QTap tap;
    tap.setEstVolume("Vol:");
    EXPECT_EQ("Vol:", tap.estVolume());
}

TEST_F(QTapTest, BrewerDefaultEmpty)
{
    QTap tap;
    EXPECT_EQ("", tap.brewer());
}

TEST_F(QTapTest, SetBrewer)
{
    QTap tap;
    tap.setBrewer("abc123");
}

TEST_F(QTapTest, GetBrewer)
{
    QTap tap;
    tap.setBrewer("brewer:");
    EXPECT_EQ("brewer:", tap.brewer());
}

TEST_F(QTapTest, AbvDefaultEmpty)
{
    QTap tap;
    EXPECT_EQ("", tap.abv());
}

TEST_F(QTapTest, SetAbv)
{
    QTap tap;
    tap.setAbv("ABV");
}

TEST_F(QTapTest, GetAbv)
{
    QTap tap;
    tap.setAbv("abv");
    EXPECT_EQ("abv", tap.abv());
}

TEST_F(QTapTest, IbuDefaultEmpty)
{
    QTap tap;
    EXPECT_EQ("", tap.ibu());
}

TEST_F(QTapTest, SetIbu)
{
    QTap tap;
    tap.setIbu("ibu");
}

TEST_F(QTapTest, GetIbu)
{
    QTap tap;
    tap.setIbu("ibu");
    EXPECT_EQ("ibu", tap.ibu());
}

TEST_F(QTapTest, BrewDateDefaultEmpty)
{
    QTap tap;
    EXPECT_EQ("", tap.brewDate());
}

TEST_F(QTapTest, SetBrewDate)
{
    QTap tap;
    tap.setBrewDate("abc123");
}

TEST_F(QTapTest, GetBrewDate)
{
    QTap tap;
    tap.setBrewDate("abc123");
    EXPECT_EQ("abc123", tap.brewDate());
}

TEST_F(QTapTest, TapDateDefaultEmpty)
{
    QTap tap;
    EXPECT_EQ("", tap.tapDate());
}

TEST_F(QTapTest, SetTapDate)
{
    QTap tap;
    tap.setTapDate("abc123");
}

TEST_F(QTapTest, GetTapDate)
{
    QTap tap;
    tap.setTapDate("abc123");
    EXPECT_EQ("abc123", tap.tapDate());
}

TEST_F(QTapTest, FinalGravityDefaultEmpty)
{
    QTap tap;
    EXPECT_EQ("", tap.finalGravity());
}

TEST_F(QTapTest, SetFinalGravity)
{
    QTap tap;
    tap.setFinalGravity("abc123");
}

TEST_F(QTapTest, GetFinalGravity)
{
    QTap tap;
    tap.setFinalGravity("abc123");
    EXPECT_EQ("abc123", tap.finalGravity());
}

TEST_F(QTapTest, ButtonsDefaultVisibleFalse)
{
    QTap tap;
    EXPECT_FALSE(tap.buttonsVisible());
}

TEST_F(QTapTest, SetButtonsVisible)
{
    QTap tap;
    tap.setButtonsVisible(true);
}

TEST_F(QTapTest, GetButtonsVisible)
{
    QTap tap;
    tap.setButtonsVisible(true);
    EXPECT_TRUE(tap.buttonsVisible());
}
}
