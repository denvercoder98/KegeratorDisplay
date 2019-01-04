#ifndef SRC_MAIN_INTERACTORS_TEMPERATUREUPDATEREQUEST_H
#define SRC_MAIN_INTERACTORS_TEMPERATUREUPDATEREQUEST_H

#include <string>

namespace KegeratorDisplay {

class TemperatureUpdateRequest
{
public:
    TemperatureUpdateRequest(int value, const std::string& unit);

    int value() const;
    std::string unit() const;
    bool operator==(const TemperatureUpdateRequest& other) const;

private:
    int m_value;
    std::string m_unit;
};

}

#endif
