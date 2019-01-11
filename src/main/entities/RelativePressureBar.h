#ifndef SRC_MAIN_ENTITIES_RELATIVEPRESSUREBAR_H_
#define SRC_MAIN_ENTITIES_RELATIVEPRESSUREBAR_H_

#include <ostream>

namespace KegeratorDisplay {

class RelativePressureBar
{
public:
    RelativePressureBar(unsigned int value);
    virtual ~RelativePressureBar();

    bool operator==(const RelativePressureBar& other) const;

    friend std::ostream& operator<<(std::ostream& stream, RelativePressureBar const& pressure)
    {
        return stream << "["
                      << "value: " << pressure.m_value
                      << "]";
    }

private:
    unsigned int m_value;
};

}

#endif
