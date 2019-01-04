#include "Temperature.h"

namespace KegeratorDisplay {

Temperature::Temperature() :
    m_lastReadings(m_numberOfReadings),
    m_unit("")
{
    for (int i=0; i<m_numberOfReadings; i++) {
        m_lastReadings.push_back(0);
    }
}

int Temperature::value() const
{
    int sum = 0;
    for (int i=0; i<m_numberOfReadings; ++i) {
        sum += m_lastReadings[i];
    }
    int average = sum / m_numberOfReadings;
    return average;
}

void Temperature::addReading(const int value)
{
    for (int i=0; i<m_numberOfReadings - 1; ++i) {
        m_lastReadings[i] = m_lastReadings[i + 1];
    }
    m_lastReadings[m_numberOfReadings - 1] = value;
}

void Temperature::setUnit(const std::string& unit)
{
    m_unit = unit;
}

std::string Temperature::unit() const
{
    return m_unit;
}

bool Temperature::operator==(const Temperature& other) const
{
    return m_lastReadings == other.m_lastReadings &&
        m_unit == other.m_unit;
}

std::vector<int> Temperature::getReadings() const
{
    return m_lastReadings;
}

void Temperature::setReadings(const std::vector<int> readings)
{
    m_lastReadings = readings;
}

}
