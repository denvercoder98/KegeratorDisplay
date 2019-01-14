#include "RelativePressureBar.h"

namespace KegeratorDisplay {

RelativePressureBar::RelativePressureBar(unsigned int value) :
    m_value(value)
{
}

RelativePressureBar::~RelativePressureBar()
{
}

bool RelativePressureBar::operator==(const RelativePressureBar& other) const
{
    if (m_value == other.m_value) {
        return true;
    }

    return false;
}

}
