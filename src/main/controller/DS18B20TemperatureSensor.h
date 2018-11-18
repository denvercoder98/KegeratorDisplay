#ifndef SRC_MAIN_CONTROLLER_DS18B20TEMPERATURESENSOR_H_
#define SRC_MAIN_CONTROLLER_DS18B20TEMPERATURESENSOR_H_

#include <string>

namespace KegeratorDisplay {

class DS18B20TemperatureSensor
{
public:
    virtual ~DS18B20TemperatureSensor() {};

    virtual std::string read() = 0;
};

}

#endif
