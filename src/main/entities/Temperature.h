#ifndef SRC_MAIN_ENTITIES_TEMPERATURE_H
#define SRC_MAIN_ENTITIES_TEMPERATURE_H

#include <vector>

namespace KegeratorDisplay {

class Temperature
{
public:
    Temperature();

    int value() const;
    void addReading(int value);

    bool operator==(const Temperature& other) const;

    std::vector<int> getReadings() const;
    void setReadings(const std::vector<int> readings);

private:
    std::vector<int> m_lastReadings;
};

}

#endif
