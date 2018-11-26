#include "BlackholeStorage.h"
#include "monitor/Temperature.h"
#include "monitor/Tap.h"
#include "monitor/Beer.h"

#include <cstddef>

namespace KegeratorDisplay {

BlackholeStorage::BlackholeStorage()
{
}

BlackholeStorage::~BlackholeStorage()
{
}

Temperature* BlackholeStorage::readTemperature()
{
	Temperature* temperature = new Temperature();
	temperature->addReading(5);
	temperature->addReading(5);
	temperature->addReading(5);
	return temperature;
}

void BlackholeStorage::writeTemperature(Temperature*)
{

}

Tap* BlackholeStorage::readLeftTap()
{
    Beer beer("Beer A",
        "Kalle Karlsson",
        AlcoholByVolume(5.2),
        InternationalBitternessUnits(40),
        Date(2018, 10, 1),
        Date(2018, 11, 1),
        SpecificGravity(1.015));
    return new Tap(beer);
}

Tap* BlackholeStorage::readRightTap()
{
    Beer beer("Beer B",
        "Sven Svensson",
        AlcoholByVolume(3.5),
        InternationalBitternessUnits(20),
        Date(2018, 10, 1),
        Date(2018, 11, 1),
        SpecificGravity(1.012));
    return new Tap(beer);
}

void BlackholeStorage::writeLeftTap(Tap*)
{

}

void BlackholeStorage::writeRightTap(Tap*)
{

}


}
