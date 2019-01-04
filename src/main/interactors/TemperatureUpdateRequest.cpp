#include "interactors/TemperatureUpdateRequest.h"

namespace KegeratorDisplay {

TemperatureUpdateRequest::TemperatureUpdateRequest(int value, const std::string& unit) :
    m_value(value),
    m_unit(unit)
{
}

int TemperatureUpdateRequest::value() const
{
    return m_value;
}

std::string TemperatureUpdateRequest::unit() const
{
    return m_unit;
}

bool TemperatureUpdateRequest::operator==(const TemperatureUpdateRequest& other) const
{
    return m_value == other.m_value &&
        m_unit == other.m_unit;
}

}
