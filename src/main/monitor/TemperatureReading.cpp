#include "TemperatureReading.h"

TemperatureReading::TemperatureReading(int value) :
    m_value(value)
{
}

int TemperatureReading::value() const
{
    return m_value;
}
