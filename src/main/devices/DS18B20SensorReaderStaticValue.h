#ifndef SRC_MAIN_CONTROLLER_DS18B20SENSORREADERSTATICVALUE_H_
#define SRC_MAIN_CONTROLLER_DS18B20SENSORREADERSTATICVALUE_H_

#include "DS18B20SensorReader.h"

namespace KegeratorDisplay {

class DS18B20SensorReaderStaticValue : public DS18B20SensorReader
{
public:
    DS18B20SensorReaderStaticValue();
    virtual ~DS18B20SensorReaderStaticValue();

    virtual std::string read();

private:
    int m_cnt;
};

}

#endif
