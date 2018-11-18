#include "BeerTest.h"
#include "src/main/monitor/Beer.h"
#include "src/main/monitor/AlcoholByVolume.h"
#include "src/main/monitor/InternationalBitternessUnits.h"
#include "src/main/monitor/VolumeLiters.h"

BeerTest::BeerTest()
{
}

BeerTest::~BeerTest()
{
}

TEST_F(BeerTest, Create)
{
    VolumeLiters* volume = new VolumeLiters(18);
    Beer beer(
	"abc",
	AlcoholByVolume(5.2),
	InternationalBitternessUnits(40),
	BrewDate(2018, 9, 1),
	volume);

    delete volume;
}
