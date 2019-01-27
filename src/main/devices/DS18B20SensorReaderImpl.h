#ifndef SRC_MAIN_DEVICES_DS18B20SENSORREADERIMPL_H_
#define SRC_MAIN_DEVICES_DS18B20SENSORREADERIMPL_H_

#include "DS18B20SensorReader.h"

namespace KegeratorDisplay {

class FileReader;

class DS18B20SensorReaderImpl : public DS18B20SensorReader
{
public:
    DS18B20SensorReaderImpl(const std::string& device, FileReader* reader);
    virtual ~DS18B20SensorReaderImpl();

    std::string read();
    std::string getDeviceName() const;

private:
    const std::string m_device;
    FileReader* m_reader;
};

}

#endif
