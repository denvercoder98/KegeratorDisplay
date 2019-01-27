#ifndef SRC_MAIN_TARGETSPECIFICDEPENDENCYFACTORY_H_
#define SRC_MAIN_TARGETSPECIFICDEPENDENCYFACTORY_H_

#include <string>

namespace KegeratorDisplay {

class DS18B20SensorReader;

class TargetSpecificDependencyFactory
{
public:
    enum Type {TARGET, DEVELOP};

    TargetSpecificDependencyFactory(Type type);
    virtual ~TargetSpecificDependencyFactory();

    DS18B20SensorReader* createDS18B20SensorReader(const std::string& deviceName = "") const;

private:
    Type m_type;
};

}

#endif
