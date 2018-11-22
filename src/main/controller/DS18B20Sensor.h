#ifndef SRC_MAIN_CONTROLLER_DS18B20SENSOR_H_
#define SRC_MAIN_CONTROLLER_DS18B20SENSOR_H_

#include "SensorController.h"
#include "TemperatureSensor.h"
#include "src/main/monitor/TemperatureReadingObserver.h"
#include <string>

namespace KegeratorDisplay {

class DS18B20SensorReader;

class DS18B20Sensor : public TemperatureSensor
{
public:
    DS18B20Sensor(DS18B20SensorReader* const sensor);
    virtual ~DS18B20Sensor();

    int read();

private:
    std::string readSensor();
    std::string parseRawReadingToString(std::string& rawReading);
    int convertToRoundedInteger(std::string rawTemperature);
    void notifyObserver(int temperatureInteger);
    bool isPositiveInteger(const std::string& s) const;

    DS18B20SensorReader* const m_sensorReader;
};

}

#endif
