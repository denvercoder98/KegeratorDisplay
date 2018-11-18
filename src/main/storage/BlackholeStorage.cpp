#include "BlackholeStorage.h"
#include "src/main/monitor/Temperature.h"

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

}
