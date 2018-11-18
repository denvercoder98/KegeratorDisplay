#ifndef SRC_MAIN_MONITOR_TEMPERATUREINTERACTOR_H
#define SRC_MAIN_MONITOR_TEMPERATUREINTERACTOR_H

#include "TemperatureReadingObserver.h"

namespace KegeratorDisplay {

class KegeratorObserver;
class Storage;
class Temperature;

class TemperatureInteractor : public TemperatureReadingObserver
{
public:
    TemperatureInteractor(KegeratorObserver* observer, Storage* storage);
    virtual ~TemperatureInteractor();

    virtual void receiveTemperatureReading(const TemperatureReading& reading);

private:
    void addTemperatureReading(const TemperatureReading& reading);
    void updateObserver();

    Temperature* m_temperature;
    KegeratorObserver* m_kegeratorObserver;
    Storage* m_storage;
};

}

#endif
