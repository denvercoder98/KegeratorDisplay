#include "AlcoholByVolume.h"
#include "InvalidAlcoholByVolumeException.h"

#include <sstream>

namespace KegeratorDisplay {

AlcoholByVolume::AlcoholByVolume(const float value)
{
    validateArgument(value);
    setStringValueFromFloat(value);
}

AlcoholByVolume::~AlcoholByVolume()
{
}

void AlcoholByVolume::validateArgument(const float value)
{
    if (value < 0) {
        throw InvalidAlcoholByVolumeException("Negative ABV");
    }

    if (value > 100) {
        throw InvalidAlcoholByVolumeException("Unreasonably high ABV");
    }
}

void AlcoholByVolume::setStringValueFromFloat(const float value)
{
    int scaledIntValue = (value * 10);
    if (scaledIntValue > 0) {
        std::ostringstream stream;
        stream << scaledIntValue;
        std::string temp = stream.str();
        m_value = stream.str();
    }
    else {
        m_value = "00";
    }
    m_value.insert(m_value.length() - 1, ",");
}

std::string AlcoholByVolume::value() const
{
    return m_value;
}

bool AlcoholByVolume::operator==(const AlcoholByVolume& other) const
{
    return m_value == other.m_value;
}

}
