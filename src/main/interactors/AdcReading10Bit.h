#ifndef SRC_MAIN_INTERACTORS_ADCREADING10BIT_H_
#define SRC_MAIN_INTERACTORS_ADCREADING10BIT_H_

#include <ostream>

namespace KegeratorDisplay {

class AdcReading10Bit
{
public:
    AdcReading10Bit(unsigned int value);
    virtual ~AdcReading10Bit();

    bool operator==(const AdcReading10Bit& other) const;
    friend std::ostream& operator<<(std::ostream& stream, AdcReading10Bit const& update)
    {
        return stream << "[value: '" << update.m_value << "']";
    }

    unsigned int value() const;

private:
    unsigned int m_value;
};

}

#endif
