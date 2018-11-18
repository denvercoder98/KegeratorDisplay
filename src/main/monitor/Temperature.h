#ifndef SRC_MAIN_MONITOR_TEMPERATURE_H
#define SRC_MAIN_MONITOR_TEMPERATURE_H

#include <vector>
#include "TemperatureReading.h"

namespace KegeratorDisplay {

class Temperature
{
public:
    Temperature();

    int value() const;
    void addReading(int value);

private:
    std::vector<int> m_lastReadings;
};

}

#endif
