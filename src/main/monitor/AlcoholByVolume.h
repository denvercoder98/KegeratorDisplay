#ifndef SRC_MAIN_MONITOR_ALCOHOLBYVOLUME_H
#define SRC_MAIN_MONITOR_ALCOHOLBYVOLUME_H

#include <string>

namespace KegeratorDisplay {

class AlcoholByVolume
{
public:
    AlcoholByVolume();
    AlcoholByVolume(const float value);
    virtual ~AlcoholByVolume();

    std::string value() const;
    bool operator==(const AlcoholByVolume& other) const;

    void setAbv(const float value);

private:
    void validateArgument(const float value);
    void setStringValueFromFloat(const float value);

    std::string m_value;
};

}

#endif
