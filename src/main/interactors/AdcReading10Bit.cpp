#include "AdcReading10Bit.h"
#include "InvalidAdcReadingValueException.h"
#include <sstream>

namespace KegeratorDisplay {

AdcReading10Bit::AdcReading10Bit(unsigned int value) :
    m_value(value)
{
    if (value >= 1024) {
        std::ostringstream stream;
        stream << value << " does not fit 10 bit";
        throw InvalidAdcReadingValueException(stream.str());
    }
}

AdcReading10Bit::~AdcReading10Bit()
{
}

bool AdcReading10Bit::operator==(const AdcReading10Bit& other) const
{
    return m_value == other.m_value;
}

}
