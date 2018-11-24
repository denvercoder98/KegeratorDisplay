#include "BlackholeStorage.h"
#include "monitor/Temperature.h"
#include "monitor/Tap.h"

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

Tap* BlackholeStorage::readLeftTap()
{
    return NULL;
}

Tap* BlackholeStorage::readRightTap()
{
    return NULL;
}


}
