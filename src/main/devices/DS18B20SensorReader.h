#ifndef SRC_MAIN_CONTROLLER_DS18B20SENSORREADER_H_
#define SRC_MAIN_CONTROLLER_DS18B20SENSORREADER_H_

#include <string>

namespace KegeratorDisplay {

class DS18B20SensorReader
{
public:
    virtual ~DS18B20SensorReader() {};

    virtual std::string read() = 0;
};

}

#endif
