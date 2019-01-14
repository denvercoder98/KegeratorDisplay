#ifndef SRC_MAIN_DEVICES_ADCSENSORMCP3008_H_
#define SRC_MAIN_DEVICES_ADCSENSORMCP3008_H_

#include "controllers/AnalogDigitalConverterSensor.h"

namespace KegeratorDisplay {

class SpiReader;

class AdcSensorMCP3008 : public AnalogDigitalConverterSensor
{
public:
    AdcSensorMCP3008(SpiReader* reader);
    virtual ~AdcSensorMCP3008();

    unsigned int readChannel(unsigned int channel);

private:
    unsigned int convertReadingToUnsignedInt(unsigned char* buffer, unsigned int bufferLength);

    SpiReader* m_reader;
};

}

#endif
