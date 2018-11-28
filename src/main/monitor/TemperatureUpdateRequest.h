#ifndef SRC_MAIN_MONITOR_TEMPERATUREUPDATEREQUEST_H
#define SRC_MAIN_MONITOR_TEMPERATUREUPDATEREQUEST_H

namespace KegeratorDisplay {

class TemperatureUpdateRequest
{
public:
    TemperatureUpdateRequest(int value);

    int value() const;
    bool operator==(const TemperatureUpdateRequest& other) const;

private:
    int m_value;
};

}

#endif
