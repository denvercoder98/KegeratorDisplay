#ifndef SRC_MAIN_ENTITIES_TEMPERATURE_H
#define SRC_MAIN_ENTITIES_TEMPERATURE_H

#include <vector>
#include <string>
#include <ostream>

namespace KegeratorDisplay {

class Temperature
{
public:
    Temperature();

    int value() const;
    std::string unit() const;
    void addReading(int value);

    bool operator==(const Temperature& other) const;
    friend std::ostream& operator<<(std::ostream& stream, Temperature const& update)
    {
        stream << "["
               << "lastReadings: ";
        for (int i=0; i<m_numberOfReadings; ++i) {
            stream << update.m_lastReadings[i] << ", ";
        }
        stream << "unit: '" << update.m_unit << "'"
               << "]";
        return stream;
    }

    std::vector<int> getReadings() const;
    void setReadings(const std::vector<int> readings);
    void setUnit(const std::string& unit);

private:
    std::vector<int> m_lastReadings;
    std::string m_unit;
    static const int m_numberOfReadings = 3;
};

}

#endif
