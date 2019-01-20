#ifndef SRC_MAIN_ENTITIES_BAR_H_
#define SRC_MAIN_ENTITIES_BAR_H_

#include <ostream>
#include <iomanip>

namespace KegeratorDisplay {

class Bar
{
public:
    Bar(float value);
    virtual ~Bar();

    bool operator==(const Bar& other) const;

    friend std::ostream& operator<<(std::ostream& stream, Bar const& pressure)
    {
        return stream << "["
                      << std::setprecision(1) << std::fixed
                      << "value: " << pressure.m_value
                      << "]";
    }

    std::string value() const;
    std::string unit() const;

private:
    float m_value;
};

}

#endif
