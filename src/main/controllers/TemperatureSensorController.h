#ifndef SRC_MAIN_CONTROLLERS_TEMPERATURESENSORCONTROLLER_H_
#define SRC_MAIN_CONTROLLERS_TEMPERATURESENSORCONTROLLER_H_

#include "controllers/SensorController.h"
#include <string>

namespace KegeratorDisplay {

class TemperatureSensor;
class TemperatureUpdateRequestObserver;

class TemperatureSensorController: public SensorController
{
public:
    TemperatureSensorController(TemperatureSensor* const sensor,
                                TemperatureUpdateRequestObserver& observer,
                                const std::string& unit);
    virtual ~TemperatureSensorController();

    virtual void process();

private:
    int readSensor();
    void notifyObserver(int temperatureInteger, const std::string& unit);

    TemperatureSensor* const m_sensor;
    TemperatureUpdateRequestObserver& m_observer;
    const std::string m_unit;
};

}

#endif
