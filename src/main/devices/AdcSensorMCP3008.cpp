#include "AdcSensorMCP3008.h"
#include "SpiReader.h"
#include "InvalidAdcSensorMCP3008ArgumentException.h"
#include "InvalidAdcSensorReadingException.h"
#include <sstream>
#include <string>
#include <iostream>

namespace KegeratorDisplay {

AdcSensorMCP3008::AdcSensorMCP3008(SpiReader* reader) :
    m_reader(reader)
{
    if (m_reader == NULL) {
        throw InvalidAdcSensorMCP3008ArgumentException("Missing SPI reader dependency");
    }

    m_reader->initialize();
}

AdcSensorMCP3008::~AdcSensorMCP3008()
{
    delete m_reader;
}

unsigned int AdcSensorMCP3008::readChannel(unsigned int channel)
{
    //TODO buffer size
    unsigned char buffer[512];
    m_reader->read(buffer, 512);

    try {
        return convertReadingToUnsignedInt(buffer, 512);
    }
    catch (std::exception& ex) {
        throw InvalidAdcSensorReadingException("Unable to convert adc reading to unsigned integer");
    }
}

unsigned int AdcSensorMCP3008::convertReadingToUnsignedInt(unsigned char* buffer, unsigned int bufferLength)
{
    std::ostringstream ss;
    ss << buffer;
    unsigned int value = std::stoi(ss.str());
    return value;
}

}
