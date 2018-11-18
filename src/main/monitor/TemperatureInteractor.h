#ifndef SRC_MAIN_MONITOR_TEMPERATUREINTERACTOR_H
#define SRC_MAIN_MONITOR_TEMPERATUREINTERACTOR_H

#include "TemperatureReadingObserver.h"
#include "Temperature.h"

class KegeratorObserver;
class Storage;

class TemperatureInteractor :
    public TemperatureReadingObserver
{
public:
    TemperatureInteractor(KegeratorObserver* observer, Storage* storage);
    virtual ~TemperatureInteractor();

    virtual void receiveTemperatureReading(const TemperatureReading& reading);

private:
    Temperature* m_temperature;
    KegeratorObserver* m_kegeratorObserver;
    Storage* m_storage;
};

#endif
