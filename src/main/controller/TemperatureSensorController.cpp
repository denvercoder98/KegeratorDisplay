#include <interactors/TemperatureUpdateRequest.h>
#include <interactors/TemperatureUpdateRequestObserver.h>
#include "TemperatureSensorController.h"
#include "TemperatureSensor.h"

namespace KegeratorDisplay {

TemperatureSensorController::TemperatureSensorController(TemperatureSensor* const sensor,
                                                         TemperatureUpdateRequestObserver& observer,
                                                         const std::string& unit) :
    m_sensor(sensor),
    m_observer(observer),
    m_unit(unit)
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
    notifyObserver(temperatureInteger, m_unit);
}

int TemperatureSensorController::readSensor()
{
    return m_sensor->read();
}

void TemperatureSensorController::notifyObserver(int temperature, const std::string& unit)
{
    m_observer.receiveTemperatureReading(TemperatureUpdateRequest(temperature, unit));
}

}
