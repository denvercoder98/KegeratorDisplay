#ifndef SRC_MAIN_INTERACTORS_TEMPERATUREUPDATE_H
#define SRC_MAIN_INTERACTORS_TEMPERATUREUPDATE_H

namespace KegeratorDisplay {

class TemperatureUpdateResponse
{
public:
    TemperatureUpdateResponse(int value) :
        m_value(value)
    {
    }

    int value() const
    {
        return m_value;
    }

    bool operator==(const TemperatureUpdateResponse& update) const
    {
        return m_value == update.value();
    }

private:
    int m_value;
};

}

#endif
