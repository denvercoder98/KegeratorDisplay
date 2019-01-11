#include "AdcSensorMCP3008Test.h"

#include "controllers/AnalogDigitalConverterSensorController.h"
#include "devices/AdcSensorMCP3008.h"
#include "devices/InvalidAdcSensorMCP3008ArgumentException.h"
#include "devices/InvalidAdcSensorReadingException.h"
#include "unit/interactors/AnalogDigitalConverterUpdateRequestObserverMock.h"
#include "unit/devices/SpiReaderMock.h"

using testing::NiceMock;
using testing::Return;
using testing::Invoke;
using testing::_;

namespace KegeratorDisplay {

AdcSensorMCP3008Test::AdcSensorMCP3008Test()
{
}

AdcSensorMCP3008Test::~AdcSensorMCP3008Test()
{
}

TEST_F(AdcSensorMCP3008Test, Create)
{
    NiceMock<SpiReaderMock> *spiReader = new NiceMock<SpiReaderMock>();
    AdcSensorMCP3008 adc(spiReader);
}

TEST_F(AdcSensorMCP3008Test, MissingSpiReaderThrows)
{
    EXPECT_THROW(AdcSensorMCP3008(NULL), InvalidAdcSensorMCP3008ArgumentException);
}

TEST_F(AdcSensorMCP3008Test, InitializeSpi)
{
    NiceMock<SpiReaderMock> *spiReader = new NiceMock<SpiReaderMock>();
    EXPECT_CALL(*spiReader, initialize())
        .Times(1);
    AdcSensorMCP3008 adc(spiReader);
}

TEST_F(AdcSensorMCP3008Test, CanBeUsedByController)
{
    NiceMock<SpiReaderMock> *spiReader = new NiceMock<SpiReaderMock>();
    AdcSensorMCP3008* sensor = new AdcSensorMCP3008(spiReader);
    NiceMock<AnalogDigitalConverterUpdateRequestObserverMock>* observer = new NiceMock<AnalogDigitalConverterUpdateRequestObserverMock>();
    AnalogDigitalConverterSensorController controller(
        AnalogDigitalConverterSensorController::ADC_10BITS,
        AnalogDigitalConverterSensorController::ADC_CHANNEL0,
        sensor,
        observer);
}

void copyExpectedValue(unsigned char* buffer, unsigned int bufferLength)
{
    unsigned char source[4] = "512";
    memcpy(buffer, source, 4);
}

TEST_F(AdcSensorMCP3008Test, ReadChannelReadsSpi)
{
    NiceMock<SpiReaderMock> *spiReader = new NiceMock<SpiReaderMock>();
    AdcSensorMCP3008 sensor(spiReader);
    EXPECT_CALL(*spiReader, read(_, _))
        .WillOnce( Invoke(copyExpectedValue) );
    sensor.readChannel(AnalogDigitalConverterSensorController::ADC_CHANNEL0);
}

TEST_F(AdcSensorMCP3008Test, ReadChannelReadsSpiValue)
{
    NiceMock<SpiReaderMock> *spiReader = new NiceMock<SpiReaderMock>();
    AdcSensorMCP3008 sensor(spiReader);

    ON_CALL(*spiReader, read(_, _))
        .WillByDefault( Invoke(copyExpectedValue) );

    unsigned int expected = 512;
    unsigned int value = sensor.readChannel(AnalogDigitalConverterSensorController::ADC_CHANNEL0);

    EXPECT_EQ(expected, value);
}

TEST_F(AdcSensorMCP3008Test, EmptyReadThrowsException)
{
    NiceMock<SpiReaderMock> *spiReader = new NiceMock<SpiReaderMock>();
    AdcSensorMCP3008 sensor(spiReader);

    EXPECT_THROW(sensor.readChannel(AnalogDigitalConverterSensorController::ADC_CHANNEL0), InvalidAdcSensorReadingException);
}

}
