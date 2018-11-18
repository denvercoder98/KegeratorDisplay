#include "TemperatureReading.h"

namespace KegeratorDisplay {

TemperatureReading::TemperatureReading(int value) :
    m_value(value)
{
}

int TemperatureReading::value() const
{
    return m_value;
}

bool TemperatureReading::operator==(const TemperatureReading& other) const
{
    return m_value == other.m_value;
}

}
