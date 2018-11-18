#include "Date.h"
#include "InvalidDateException.h"
#include "boost/date_time/gregorian/gregorian.hpp"

namespace KegeratorDisplay {

Date::Date(unsigned int year, unsigned int month, unsigned int day)
{
    validateArguments(year, month, day);
    setValue(year, month, day);
}

Date::~Date()
{
}

const std::string Date::value() const
{
    return m_value;
}

const bool Date::operator==(const Date& other) const
{
    return m_value == other.m_value;
}

void Date::validateArguments(unsigned int year, unsigned int month, unsigned int day)
{
    try {
        boost::gregorian::date date(year, month, day);
    }
    catch (...) {
        throw InvalidDateException("Invalid date");
    }
}

void Date::setValue(unsigned int year, unsigned int month, unsigned int day)
{
    boost::gregorian::date date(year, month, day);
    m_value = boost::gregorian::to_iso_extended_string(date);
}


}
