#include "Temperature.h"

namespace KegeratorDisplay {

#define NUMBER_OF_READINGS 3

Temperature::Temperature() :
    m_lastReadings(NUMBER_OF_READINGS)
{
    for (int i=0; i<NUMBER_OF_READINGS; i++) {
        m_lastReadings.push_back(0);
    }
}

int Temperature::value() const
{
    int sum = 0;
    for (int i=0; i<NUMBER_OF_READINGS; ++i) {
        sum += m_lastReadings[i];
    }
    int average = sum / NUMBER_OF_READINGS;
    return average;
}

void Temperature::addReading(const int value)
{
    for (int i=0; i<NUMBER_OF_READINGS - 1; ++i) {
        m_lastReadings[i] = m_lastReadings[i + 1];
    }
    m_lastReadings[NUMBER_OF_READINGS - 1] = value;
}

bool Temperature::operator==(const Temperature& other) const
{
    return m_lastReadings == other.m_lastReadings;
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
