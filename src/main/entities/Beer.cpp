#include "Beer.h"

namespace KegeratorDisplay {

Beer::Beer() :
    m_name(""),
    m_brewerName(""),
    m_abv(0),
    m_ibu(0),
    m_brewDate(1970, 1, 1),
    m_tapDate(1970, 1, 1),
    m_finalGravity(0.000)
{
}

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

Beer& Beer::operator=(const Beer& other)
{
    if (this != &other) {
        m_name = other.m_name;
        m_brewerName = other.m_brewerName;
        m_abv = other.m_abv;
        m_ibu = other.m_ibu;
        m_brewDate = other.m_brewDate;
        m_tapDate = other.m_tapDate;
        m_finalGravity = other.m_finalGravity;
    }
    return *this;
}

bool Beer::operator==(const Beer& other) const
{
    return m_name == other.m_name &&
        m_brewerName == other.m_brewerName &&
        m_abv == other.m_abv &&
        m_ibu == other.m_ibu &&
        m_brewDate == other.m_brewDate &&
        m_tapDate == other.m_tapDate &&
        m_finalGravity == other.m_finalGravity;
}

const std::string Beer::name() const
{
    return m_name;
}

void Beer::setName(const std::string& name)
{
    m_name = name;
}

const std::string Beer::brewerName() const
{
    return m_brewerName;
}

void Beer::setBrewerName(const std::string& brewerName)
{
    m_brewerName = brewerName;
}

const AlcoholByVolume Beer::alcoholByVolume() const
{
    return m_abv;
}

void Beer::setAlcoholByVolume(const AlcoholByVolume& abv)
{
    m_abv = abv;
}

const InternationalBitternessUnits Beer::internationalBitternessUnits() const
{
    return m_ibu;
}

void Beer::setInternationalBitternessUnits(const InternationalBitternessUnits& ibu)
{
    m_ibu = ibu;
}

const Date Beer::brewDate() const
{
    return m_brewDate;
}

void Beer::setBrewDate(const Date& date)
{
    m_brewDate = date;
}

const Date Beer::tapDate() const
{
    return m_tapDate;
}

void Beer::setTapDate(const Date& date)
{
    m_tapDate = date;
}

const SpecificGravity Beer::finalGravity() const
{
    return m_finalGravity;
}

void Beer::setFinalGravity(const SpecificGravity& fg)
{
    m_finalGravity = fg;
}

}
