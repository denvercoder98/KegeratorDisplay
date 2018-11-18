#include "InternationalBitternessUnits.h"
#include "InvalidInternationalBitternessUnitsException.h"

namespace KegeratorDisplay {

#define MAX_IBU 999

InternationalBitternessUnits::InternationalBitternessUnits(const unsigned int value) :
    m_value(0)
{
    validateArgument(value);
    setValue(value);
}

InternationalBitternessUnits::~InternationalBitternessUnits()
{
}

const unsigned int InternationalBitternessUnits::value() const
{
    return m_value;
}

void InternationalBitternessUnits::validateArgument(const unsigned int value) const
{
    if (value > MAX_IBU) {
        throw InvalidInternationalBitternessUnitsException("Unreasonably high IBU");
    }
}

void InternationalBitternessUnits::setValue(const unsigned int value)
{
    m_value = value;
}

bool InternationalBitternessUnits::operator==(const InternationalBitternessUnits& other) const
{
    return m_value == other.m_value;
}

}
