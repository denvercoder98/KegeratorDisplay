#include "DS18B20SensorReaderImpl.h"
#include "InvalidDS18B20SensorReaderArgument.h"
#include "storage/FileReader.h"

//TODO verify that device exists and is readable

namespace KegeratorDisplay {

DS18B20SensorReaderImpl::DS18B20SensorReaderImpl(const std::string& device, FileReader* fileReader) :
    m_device(device),
    m_reader(fileReader)
{
    if (fileReader == NULL) {
        throw InvalidDS18B20SensorReaderArgument("Missing FileReader dependency");
    }
}

DS18B20SensorReaderImpl::~DS18B20SensorReaderImpl()
{
    delete m_reader;
}

std::string DS18B20SensorReaderImpl::read()
{
    return m_reader->read(m_device);
}

}
