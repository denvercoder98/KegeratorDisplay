#include "TemperatureSensorController.h"
#include "TemperatureSensor.h"
#include "monitor/TemperatureReading.h"
#include "monitor/TemperatureReadingObserver.h"

namespace KegeratorDisplay {

TemperatureSensorController::TemperatureSensorController(TemperatureSensor* const sensor,
                                                         TemperatureReadingObserver* const observer) :
    m_sensor(sensor),
    m_observer(observer)
{
}

TemperatureSensorController::~TemperatureSensorController()
{
    delete m_sensor;
}

void TemperatureSensorController::process()
{
    int temperatureInteger = readSensor();
    notifyObserver(temperatureInteger);
}

int TemperatureSensorController::readSensor()
{
    return m_sensor->read();
}

void TemperatureSensorController::notifyObserver(int temperature)
{
    m_observer->receiveTemperatureReading(TemperatureReading(temperature));
}

}
