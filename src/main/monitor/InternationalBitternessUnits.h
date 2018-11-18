#ifndef SRC_MAIN_MONITOR_INTERNATIONALBITTERNESSUNITS_H
#define SRC_MAIN_MONITOR_INTERNATIONALBITTERNESSUNITS_H

namespace KegeratorDisplay {

class InternationalBitternessUnits 
{
public:
    InternationalBitternessUnits(const unsigned int value);
    virtual ~InternationalBitternessUnits();

    const unsigned int value() const;
    bool operator==(const InternationalBitternessUnits& other) const;

private:
    void validateArgument(const unsigned int value) const;
    void setValue(const unsigned int value);

    unsigned int m_value;
};

}

#endif
