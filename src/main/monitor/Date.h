#ifndef SRC_MAIN_MONITOR_DATE_H
#define SRC_MAIN_MONITOR_DATE_H

#include <string>

namespace KegeratorDisplay {

class Date
{
public:
    Date(unsigned int year, unsigned int month, unsigned int day);
    virtual ~Date();

    const std::string value() const;
    const bool operator==(const Date& other) const;

private:
    void validateArguments(unsigned int year, unsigned int month, unsigned int day);
    void setValue(unsigned int year, unsigned int month, unsigned int day);

    std::string m_value;
};

}

#endif
