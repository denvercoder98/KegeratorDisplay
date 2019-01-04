#ifndef SRC_MAIN_INTERACTORS_TEMPERATUREUPDATE_H
#define SRC_MAIN_INTERACTORS_TEMPERATUREUPDATE_H

namespace KegeratorDisplay {

class TemperatureUpdateResponse
{
public:
    TemperatureUpdateResponse(int value, const std::string& unit) :
        m_value(value),
        m_unit(unit)
    {
    }

    int value() const
    {
        return m_value;
    }

    std::string unit() const
    {
        return m_unit;
    }

    bool operator==(const TemperatureUpdateResponse& update) const
    {
        return m_value == update.m_value &&
            m_unit == update.m_unit;
    }

    friend std::ostream& operator<<(std::ostream& stream, TemperatureUpdateResponse const& update)
    {
        return stream << "["
                      << "value: " << update.m_value << ", "
                      << "unit: '" << update.m_unit << "'"
                      << "]";
    }

private:
    int m_value;
    std::string m_unit;
};

}

#endif
