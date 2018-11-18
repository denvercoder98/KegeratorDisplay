#ifndef SRC_MAIN_MONITOR_TEMPERATUREREADING_H
#define SRC_MAIN_MONITOR_TEMPERATUREREADING_H

namespace KegeratorDisplay {

class TemperatureReading
{
public:
    TemperatureReading(int value);

    int value() const;
    bool operator==(const TemperatureReading& other) const;

private:
    int m_value;
};

}

#endif
