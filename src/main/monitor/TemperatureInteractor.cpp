#include "TemperatureInteractor.h"
#include "TemperatureUpdate.h"
#include "KegeratorObserver.h"
#include "Storage.h"

TemperatureInteractor::TemperatureInteractor(KegeratorObserver* observer, Storage* storage) :
    m_temperature(storage->readTemperature()),
    m_kegeratorObserver(observer),
    m_storage(storage)
{
    int updatedValue = m_temperature->value();
    TemperatureUpdate temperatureUpdate(updatedValue);
    m_kegeratorObserver->update(temperatureUpdate);
}

TemperatureInteractor::~TemperatureInteractor()
{
    delete m_temperature;
}

void TemperatureInteractor::receiveTemperatureReading(const TemperatureReading& reading)
{
    int value = reading.value();
    m_temperature->addReading(value);

    int updatedValue = m_temperature->value();
    TemperatureUpdate temperatureUpdate(updatedValue);
    m_kegeratorObserver->update(temperatureUpdate);
}
