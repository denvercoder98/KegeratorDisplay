#include <monitor/TemperatureUpdateRequest.h>
#include <monitor/TemperatureUpdateRequestObserver.h>
#include "TemperatureSensorController.h"
#include "TemperatureSensor.h"

namespace KegeratorDisplay {

TemperatureSensorController::TemperatureSensorController(TemperatureSensor* const sensor,
                                                         TemperatureUpdateRequestObserver* const observer) :
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
    m_observer->receiveTemperatureReading(TemperatureUpdateRequest(temperature));
}

}
