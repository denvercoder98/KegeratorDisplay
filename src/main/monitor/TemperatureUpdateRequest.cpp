#include "TemperatureUpdateRequest.h"

namespace KegeratorDisplay {

TemperatureUpdateRequest::TemperatureUpdateRequest(int value) :
    m_value(value)
{
}

int TemperatureUpdateRequest::value() const
{
    return m_value;
}

bool TemperatureUpdateRequest::operator==(const TemperatureUpdateRequest& other) const
{
    return m_value == other.m_value;
}

}
