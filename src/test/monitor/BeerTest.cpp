#include "BeerTest.h"
#include "monitor/Beer.h"
#include "monitor/AlcoholByVolume.h"
#include "monitor/InternationalBitternessUnits.h"

namespace KegeratorDisplay {

BeerTest::BeerTest() :
        m_beer(NULL)
{
}

BeerTest::~BeerTest()
{
}

void BeerTest::SetUp()
{
    m_beer = new Beer("abc",
            "Kalle Karlsson",
            AlcoholByVolume(5.2),
            InternationalBitternessUnits(40),
            Date(2018, 9, 1),
            Date(2018, 10, 1),
            SpecificGravity(1.050));
}

void BeerTest::TearDown()
{
    delete m_beer;
}

TEST_F(BeerTest, Create)
{
}

TEST_F(BeerTest, GetName)
{
    EXPECT_EQ("abc", m_beer->name());
}

TEST_F(BeerTest, GetBrewer)
{
    EXPECT_EQ("Kalle Karlsson", m_beer->brewerName());
}

TEST_F(BeerTest, GetABV)
{
    EXPECT_EQ(AlcoholByVolume(5.2), m_beer->alcoholByVolume());
}

TEST_F(BeerTest, GetIBU)
{
    EXPECT_EQ(InternationalBitternessUnits(40), m_beer->internationalBitternessUnits());
}

TEST_F(BeerTest, GetBrewDate)
{
    EXPECT_EQ(Date(2018, 9, 1), m_beer->brewDate());
}

TEST_F(BeerTest, GetTapDate)
{
    EXPECT_EQ(Date(2018, 10, 1), m_beer->tapDate());
}

TEST_F(BeerTest, GetFinalGravity)
{
    EXPECT_EQ(SpecificGravity(1.050), m_beer->finalGravity());
}

}
