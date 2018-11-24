#include "Beer.h"

namespace KegeratorDisplay {

Beer::Beer(const std::string& name,
           const std::string& brewerName,
           const AlcoholByVolume& abv,
           const InternationalBitternessUnits& ibu,
           const Date& brewDate,
           const Date& tapDate,
           const SpecificGravity& finalGravity) :
    m_name(name),
    m_brewerName(brewerName),
    m_abv(abv),
    m_ibu(ibu),
    m_brewDate(brewDate),
    m_tapDate(tapDate),
    m_finalGravity(finalGravity)
{
}

const std::string Beer::name() const
{
    return m_name;
}

const std::string Beer::brewerName() const
{
    return m_brewerName;
}

const AlcoholByVolume Beer::alcoholByVolume() const
{
    return m_abv;
}

const InternationalBitternessUnits Beer::internationalBitternessUnits() const
{
    return m_ibu;
}

const Date Beer::brewDate() const
{
    return m_brewDate;
}

const Date Beer::tapDate() const
{
    return m_tapDate;
}

const SpecificGravity Beer::finalGravity() const
{
    return m_finalGravity;
}

}
