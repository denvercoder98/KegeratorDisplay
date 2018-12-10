#ifndef SRC_MAIN_INTERACTORS_TEMPERATUREINTERACTOR_H
#define SRC_MAIN_INTERACTORS_TEMPERATUREINTERACTOR_H

#include "TemperatureUpdateRequestObserver.h"

namespace KegeratorDisplay {

class Presenter;
class Storage;
class Temperature;

class TemperatureUpdateInteractor : public TemperatureUpdateRequestObserver
{
public:
    TemperatureUpdateInteractor(Presenter& observer, Storage& storage);
    virtual ~TemperatureUpdateInteractor();

    virtual void receiveTemperatureReading(const TemperatureUpdateRequest& request);

private:
    void addTemperatureReading(const TemperatureUpdateRequest& request);
    void updatePresenter();
    void updateStorage();

    Temperature* m_temperature;
    Presenter& m_presenter;
    Storage& m_storage;
};

}

#endif
