#ifndef SRC_MAIN_MONITOR_TEMPERATUREREADING_H
#define SRC_MAIN_MONITOR_TEMPERATUREREADING_H

class TemperatureReading {
public:
    TemperatureReading(int value);

    int value() const;

private:
    int m_value;
};

#endif

