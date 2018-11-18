#ifndef SRC_MAIN_MONITOR_TEMPERATUREUPDATE_H
#define SRC_MAIN_MONITOR_TEMPERATUREUPDATE_H

namespace KegeratorDisplay {

class TemperatureUpdate
{
public:
    TemperatureUpdate(int value) :
        m_value(value)
    {
    }

    int value() const
    {
        return m_value;
    }

    bool operator==(const TemperatureUpdate& update) const
    {
        return m_value == update.value();
    }

private:
    int m_value;
};

}

#endif
