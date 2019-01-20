#include <entities/Bar.h>
#include <math.h>
#include <sstream>

namespace KegeratorDisplay {

Bar::Bar(float value)
{
    m_value = round(value * 10) / 10.0;
}

Bar::~Bar()
{
}

bool Bar::operator==(const Bar& other) const
{
    if (m_value == other.m_value) {
        return true;
    }

    return false;
}

std::string Bar::value() const
{
    std::ostringstream stream;
    stream << std::setprecision(1) << std::fixed;
    stream << m_value;
    return stream.str();
}

std::string Bar::unit() const
{
    return "bar";
}

}
