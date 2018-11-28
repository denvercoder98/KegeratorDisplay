#include "InternationalBitternessUnits.h"
#include "InvalidInternationalBitternessUnitsException.h"

namespace KegeratorDisplay {

#define MAX_IBU 999

InternationalBitternessUnits::InternationalBitternessUnits() :
    m_value(0)
{
}

InternationalBitternessUnits::InternationalBitternessUnits(const unsigned int value) :
    m_value(0)
{
    setIbu(value);
}

InternationalBitternessUnits::~InternationalBitternessUnits()
{
}

void InternationalBitternessUnits::setIbu(const unsigned int value)
{
    validateArgument(value);
    setValue(value);
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
