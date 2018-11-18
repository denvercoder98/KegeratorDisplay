#ifndef SRC_MAIN_CONTROLLER_DS18B20TEMPERATURESENSORCONTROLLER_H_
#define SRC_MAIN_CONTROLLER_DS18B20TEMPERATURESENSORCONTROLLER_H_

#include "SensorController.h"
#include "src/main/monitor/TemperatureReadingObserver.h"
#include <string>

namespace KegeratorDisplay {

class DS18B20TemperatureSensor;

class DS18B20TemperatureSensorController : public SensorController
{
public:
    DS18B20TemperatureSensorController(
        TemperatureReadingObserver* const observer,
        DS18B20TemperatureSensor* const sensor);
    virtual ~DS18B20TemperatureSensorController();

    virtual void process();

private:
    std::string readSensor();
    std::string parseRawReadingToString(std::string& rawReading);
    int convertToRoundedInteger(std::string rawTemperature);
    void notifyObserver(int temperatureInteger);
    bool isPositiveInteger(const std::string& s) const;

    TemperatureReadingObserver* const m_observer;
    DS18B20TemperatureSensor* const m_sensor;
};

}

#endif
