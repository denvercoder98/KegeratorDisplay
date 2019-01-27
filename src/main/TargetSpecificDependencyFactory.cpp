#include "TargetSpecificDependencyFactory.h"
#include "devices/DS18B20SensorReaderStaticValue.h"
#include "devices/DS18B20SensorReaderImpl.h"
#include "storage/FileReaderImpl.h"

namespace KegeratorDisplay {

TargetSpecificDependencyFactory::TargetSpecificDependencyFactory(Type type) :
    m_type(type)
{
}

TargetSpecificDependencyFactory::~TargetSpecificDependencyFactory()
{
}

DS18B20SensorReader* TargetSpecificDependencyFactory::createDS18B20SensorReader(const std::string& device) const
{
    if (m_type == DEVELOP) {
        return new DS18B20SensorReaderStaticValue();
    }

    FileReader* fileReader = new FileReaderImpl();
    return new DS18B20SensorReaderImpl(device, fileReader);
}

}
