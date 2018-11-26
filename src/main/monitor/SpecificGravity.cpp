#include "SpecificGravity.h"
#include "InvalidSpecificGravityException.h"

#include <sstream>

namespace KegeratorDisplay {

SpecificGravity::SpecificGravity() :
    m_value("")
{
    setSG(0);
}

SpecificGravity::SpecificGravity(const float gravity) :
    m_value("")
{
    setSG(gravity);
}

SpecificGravity::~SpecificGravity()
{
}

void SpecificGravity::setSG(const float gravity)
{
    validateArgument(gravity);
    setValue(gravity);
}

const std::string SpecificGravity::value() const
{
    return m_value;
}

const bool SpecificGravity::operator==(const SpecificGravity& other) const
{
    return m_value == other.m_value;
}

void SpecificGravity::validateArgument(const float gravity)
{
    if (gravity < 0) {
        throw InvalidSpecificGravityException("Negative SG");
    }

    if (gravity >= 2) {
        throw InvalidSpecificGravityException("Unreasonably high SG");
    }
}

void SpecificGravity::setValue(const float gravity)
{
    int scaledIntValue = (gravity * 1000);
    if (scaledIntValue > 0) {
        std::ostringstream stream;
        stream << scaledIntValue;
        std::string temp = stream.str();
        m_value = stream.str();
    }
    else {
        m_value = "0000";
    }
    m_value.insert(1, ".");
}

}
