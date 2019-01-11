#ifndef SRC_MAIN_INTERACTORS_PRESSUREUPDATERESPONSE_H_
#define SRC_MAIN_INTERACTORS_PRESSUREUPDATERESPONSE_H_

#include "entities/RelativePressureBar.h"

namespace KegeratorDisplay {

class PressureUpdateResponse
{
public:
    PressureUpdateResponse(RelativePressureBar pressure) :
        m_pressure(pressure)
    {
    }

    virtual ~PressureUpdateResponse()
    {
    }

    RelativePressureBar pressure() const
    {
        return m_pressure;
    }

    bool operator==(const PressureUpdateResponse& other) const
    {
        return m_pressure == other.m_pressure;
    }

    friend std::ostream& operator<<(std::ostream& stream, PressureUpdateResponse const& update)
    {
        return stream << "["
                      << "m_pressure: " << update.m_pressure
                      << "]";
    }

private:
    RelativePressureBar m_pressure;
};

}

#endif
