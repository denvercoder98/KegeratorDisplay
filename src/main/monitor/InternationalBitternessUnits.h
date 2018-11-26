#ifndef SRC_MAIN_MONITOR_INTERNATIONALBITTERNESSUNITS_H
#define SRC_MAIN_MONITOR_INTERNATIONALBITTERNESSUNITS_H

namespace KegeratorDisplay {

class InternationalBitternessUnits 
{
public:
    InternationalBitternessUnits();
    InternationalBitternessUnits(const unsigned int value);
    virtual ~InternationalBitternessUnits();

    const unsigned int value() const;
    bool operator==(const InternationalBitternessUnits& other) const;

    void setIbu(const unsigned int value);

private:
    void validateArgument(const unsigned int value) const;
    void setValue(const unsigned int value);

    unsigned int m_value;
};

}

#endif
