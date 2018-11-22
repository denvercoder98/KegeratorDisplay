#include "InvalidDS18B20SensorReadingException.h"

#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include "DS18B20SensorReader.h"
#include "DS18B20Sensor.h"

#define TEMPERATURE_READING_KEY "t="
#define TEMPERATURE_READING_STRING_LENGTH 5
#define WHITESPACES " \n\r\t"

namespace KegeratorDisplay {

DS18B20Sensor::DS18B20Sensor(DS18B20SensorReader* const sensorReader) :
    m_sensorReader(sensorReader)
{
}

DS18B20Sensor::~DS18B20Sensor()
{
    delete m_sensorReader;
}

int DS18B20Sensor::read()
{
    std::string rawReading = readSensor();
    std::string rawTemperature = parseRawReadingToString(rawReading);
    int temperatureInteger = convertToRoundedInteger(rawTemperature);
    return temperatureInteger;
}

std::string DS18B20Sensor::readSensor()
{
    return m_sensorReader->read();
}

std::string DS18B20Sensor::parseRawReadingToString(std::string& rawReading)
{
    size_t pos = rawReading.find(TEMPERATURE_READING_KEY);
    if (pos == std::string::npos) {
        throw InvalidDS18B20SensorReadingException("Missing temperature in raw data");
    }

    rawReading.erase(rawReading.find_last_not_of(WHITESPACES)+1);
    std::string rawTemperature = rawReading.substr(pos + 2, rawReading.length());
    if (rawTemperature.length() != TEMPERATURE_READING_STRING_LENGTH || !isPositiveInteger(rawTemperature)) {
        throw InvalidDS18B20SensorReadingException("Invalid temperature in raw data");
    }

    return rawTemperature;
}

bool DS18B20Sensor::isPositiveInteger(const std::string& s) const
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int DS18B20Sensor::convertToRoundedInteger(std::string rawTemperature)
{
    rawTemperature.insert(2, ".");
    double temperature = ::atof(rawTemperature.c_str());
    double temperatureRounded = round(temperature);
    int temperatureInteger = temperatureRounded;
    return temperatureInteger;
}

}
