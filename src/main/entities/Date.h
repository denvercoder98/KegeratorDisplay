#ifndef SRC_MAIN_ENTITIES_DATE_H
#define SRC_MAIN_ENTITIES_DATE_H

#include <string>

namespace KegeratorDisplay {

class Date
{
public:
    Date();
    Date(unsigned int year, unsigned int month, unsigned int day);
    virtual ~Date();

    const std::string value() const;
    const bool operator==(const Date& other) const;

    void setDate(unsigned int year, unsigned int month, unsigned int day);

    unsigned int year() const;
    unsigned int month() const;
    unsigned int day() const;

private:
    void validateArguments(unsigned int year, unsigned int month, unsigned int day);
    void setValue(unsigned int year, unsigned int month, unsigned int day);

    std::string m_value;
    unsigned int m_year;
    unsigned int m_month;
    unsigned int m_day;
};

}

#endif
