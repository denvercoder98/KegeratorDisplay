#include <interactors/TemperatureUpdateRequest.h>
#include <interactors/TemperatureUpdateRequestObserver.h>
#include "TemperatureSensorController.h"
#include "TemperatureSensor.h"

namespace KegeratorDisplay {

TemperatureSensorController::TemperatureSensorController(TemperatureSensor* const sensor,
                                                         TemperatureUpdateRequestObserver& observer) :
    m_sensor(sensor),
    m_observer(observer)
{
    //TODO throw if missing sensor
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
    m_observer.receiveTemperatureReading(TemperatureUpdateRequest(temperature));
}

}
