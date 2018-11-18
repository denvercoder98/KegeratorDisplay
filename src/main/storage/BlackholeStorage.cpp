#include "BlackholeStorage.h"
#include "src/main/monitor/Temperature.h"

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

