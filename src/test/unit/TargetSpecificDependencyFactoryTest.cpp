#include "TargetSpecificDependencyFactoryTest.h"
#include "TargetSpecificDependencyFactory.h"
#include "devices/DS18B20SensorReaderStaticValue.h"
#include "devices/DS18B20SensorReaderImpl.h"

namespace KegeratorDisplay {

TargetSpecificDependencyFactoryTest::TargetSpecificDependencyFactoryTest()
{
}

TargetSpecificDependencyFactoryTest::~TargetSpecificDependencyFactoryTest()
{
}

TEST_F(TargetSpecificDependencyFactoryTest, Create)
{
    TargetSpecificDependencyFactory factory(TargetSpecificDependencyFactory::DEVELOP);
}

TEST_F(TargetSpecificDependencyFactoryTest, DevelopCreatesFakeTemperatureReader)
{
    TargetSpecificDependencyFactory factory(TargetSpecificDependencyFactory::DEVELOP);
    DS18B20SensorReader* reader = factory.createDS18B20SensorReader();
    DS18B20SensorReaderStaticValue* impl = dynamic_cast<DS18B20SensorReaderStaticValue*>(reader);
    EXPECT_FALSE(NULL == impl);
    delete reader;
}

TEST_F(TargetSpecificDependencyFactoryTest, DefaultCreatesRealTemperatureReader)
{
    TargetSpecificDependencyFactory factory(TargetSpecificDependencyFactory::TARGET);
    DS18B20SensorReader* reader = factory.createDS18B20SensorReader("device");
    DS18B20SensorReaderImpl* impl = dynamic_cast<DS18B20SensorReaderImpl*>(reader);
    EXPECT_FALSE(NULL == impl);
    delete reader;
}

TEST_F(TargetSpecificDependencyFactoryTest, DefaultCreatesRealTemperatureReaderWithDeviceName)
{
    TargetSpecificDependencyFactory factory(TargetSpecificDependencyFactory::TARGET);
    DS18B20SensorReader* reader = factory.createDS18B20SensorReader("device");
    DS18B20SensorReaderImpl* impl = dynamic_cast<DS18B20SensorReaderImpl*>(reader);
    EXPECT_EQ("device", impl->getDeviceName());
    delete reader;
}

}
