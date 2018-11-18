#include "AlcoholByVolumeTest.h"
#include "src/main/monitor/AlcoholByVolume.h"
#include "src/main/monitor/InvalidAlcoholByVolumeException.h"

namespace KegeratorDisplay {

AlcoholByVolumeTest::AlcoholByVolumeTest()
{
}

AlcoholByVolumeTest::~AlcoholByVolumeTest()
{
}

TEST_F(AlcoholByVolumeTest, Create)
{
	AlcoholByVolume abv(1);
}

TEST_F(AlcoholByVolumeTest, CreateWithReasonableValue)
{
	AlcoholByVolume abv(5.2);
}

TEST_F(AlcoholByVolumeTest, NegativeValueThrows)
{
	EXPECT_THROW(AlcoholByVolume abv(-1), InvalidAlcoholByVolumeException);
}

TEST_F(AlcoholByVolumeTest, GreaterThen100Throws)
{
	EXPECT_THROW(AlcoholByVolume abv(101), InvalidAlcoholByVolumeException);
}

TEST_F(AlcoholByVolumeTest, MinimumABV)
{
	AlcoholByVolume abv(0);
}

TEST_F(AlcoholByVolumeTest, MaximumABV)
{
	AlcoholByVolume abv(100);
}

TEST_F(AlcoholByVolumeTest, MaximumABVStringValue)
{
	AlcoholByVolume abv(100);
	EXPECT_EQ("100,0", abv.value());
}

TEST_F(AlcoholByVolumeTest, MinimumABVStringValue)
{
	AlcoholByVolume abv(0);
	EXPECT_EQ("0,0", abv.value());
}

TEST_F(AlcoholByVolumeTest, ABVWithLotsOfDecimalsTruncatedStringValue)
{
	AlcoholByVolume abv(5.3333333);
	EXPECT_EQ("5,3", abv.value());
}

TEST_F(AlcoholByVolumeTest, HighABVWithLotsOfDecimalsTruncatedStringValue)
{
	AlcoholByVolume abv(10.3333333);
	EXPECT_EQ("10,3", abv.value());
}

}
