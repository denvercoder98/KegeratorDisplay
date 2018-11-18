#ifndef SRC_MAIN_MONITOR_ALCOHOLBYVOLUME_H
#define SRC_MAIN_MONITOR_ALCOHOLBYVOLUME_H

#include <string>

namespace KegeratorDisplay {

class AlcoholByVolume
{
public:
    AlcoholByVolume(const float value);
    virtual ~AlcoholByVolume();

    std::string value() const;
    bool operator==(const AlcoholByVolume& other) const;

private:
    void validateArgument(const float value);
    void setStringValueFromFloat(const float value);

    std::string m_value;
};

}

#endif
