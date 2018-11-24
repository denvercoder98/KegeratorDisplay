#include "Temperature.h"
#include "TemperatureInteractor.h"
#include "TemperatureUpdate.h"
#include "KegeratorObserver.h"
#include "Storage.h"

namespace KegeratorDisplay {

TemperatureInteractor::TemperatureInteractor(KegeratorObserver* observer, Storage* storage) :
    m_temperature(storage->readTemperature()),
    m_kegeratorObserver(observer),
    m_storage(storage)
{
    updateObserver();
}

TemperatureInteractor::~TemperatureInteractor()
{
    delete m_temperature;
}

void TemperatureInteractor::receiveTemperatureReading(const TemperatureReading& reading)
{
    addTemperatureReading(reading);
    updateObserver();
}

void TemperatureInteractor::updateObserver()
{
    int updatedValue = m_temperature->value();
    TemperatureUpdate temperatureUpdate(updatedValue);
    m_kegeratorObserver->updateTemperature(temperatureUpdate);
}

void TemperatureInteractor::addTemperatureReading(const TemperatureReading& reading)
{
    int value = reading.value();
    m_temperature->addReading(value);
}

}
