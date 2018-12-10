#ifndef SRC_MAIN_CONTROLLER_TEMPERATURESENSORCONTROLLER_H_
#define SRC_MAIN_CONTROLLER_TEMPERATURESENSORCONTROLLER_H_

#include "SensorController.h"

namespace KegeratorDisplay {

class TemperatureSensor;
class TemperatureUpdateRequestObserver;

class TemperatureSensorController: public SensorController
{
public:
    TemperatureSensorController(TemperatureSensor* const sensor, TemperatureUpdateRequestObserver& observer);
    virtual ~TemperatureSensorController();

    virtual void process();

private:
    int readSensor();
    void notifyObserver(int temperatureInteger);

    TemperatureSensor* const m_sensor;
    TemperatureUpdateRequestObserver& m_observer;
};

}

#endif
