#include "Presenter.h"
#include "Storage.h"
#include "TemperatureUpdateInteractor.h"
#include "TemperatureUpdateResponse.h"
#include "entities/Temperature.h"

namespace KegeratorDisplay {

TemperatureUpdateInteractor::TemperatureUpdateInteractor(Presenter& presenter, Storage& storage) :
    m_temperature(storage.readTemperature()),
    m_presenter(presenter),
    m_storage(storage)
{
    updatePresenter();
}

TemperatureUpdateInteractor::~TemperatureUpdateInteractor()
{
    delete m_temperature;
}

void TemperatureUpdateInteractor::receiveTemperatureReading(const TemperatureUpdateRequest& request)
{
    addTemperatureReading(request);
    updatePresenter();
    updateStorage();
}

void TemperatureUpdateInteractor::updatePresenter()
{
    int updatedValue = m_temperature->value();
    TemperatureUpdateResponse temperatureUpdate(updatedValue);
    m_presenter.updateTemperature(temperatureUpdate);
}

void TemperatureUpdateInteractor::updateStorage()
{
    m_storage.writeTemperature(m_temperature);
}

void TemperatureUpdateInteractor::addTemperatureReading(const TemperatureUpdateRequest& request)
{
    int value = request.value();
    m_temperature->addReading(value);
}

}
