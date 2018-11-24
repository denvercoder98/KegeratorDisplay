#ifndef SRC_MAIN_MONITOR_BEERUPDATE_H
#define SRC_MAIN_MONITOR_BEERUPDATE_H

#include <string>

namespace KegeratorDisplay {

class BeerUpdate
{
public:
    BeerUpdate(const std::string& name,
               const std::string& brewerName,
               const std::string& abv,
               const unsigned int ibu,
               const std::string& brewDate,
               const std::string& tapDate,
               const std::string& finalGravity) :
        m_name(name),
        m_brewerName(brewerName),
        m_abv(abv),
        m_ibu(ibu),
        m_brewDate(brewDate),
        m_tapDate(tapDate),
        m_finalGravity(finalGravity)
    {
    }

    std::string name() const
    {
        return m_name;
    }

    std::string brewerName() const
    {
        return m_brewerName;
    }

    std::string abv() const
    {
        return m_abv;
    }

    unsigned int ibu() const
    {
        return m_ibu;
    }

    std::string brewDate() const
    {
        return m_brewDate;
    }

    std::string tapDate() const
    {
        return m_tapDate;
    }

    std::string finalGravity() const
    {
        return m_finalGravity;
    }

    bool operator==(const BeerUpdate& update) const
    {
        return m_name == update.m_name &&
        m_brewerName == update.m_brewerName &&
        m_abv == update.m_abv &&
        m_ibu == update.m_ibu &&
        m_brewDate == update.m_brewDate &&
        m_tapDate == update.m_tapDate &&
        m_finalGravity == update.m_finalGravity;
    }

private:
    const std::string m_name;
    const std::string m_brewerName;
    const std::string m_abv;
    const unsigned int m_ibu;
    const std::string m_brewDate;
    const std::string m_tapDate;
    const std::string m_finalGravity;
};

}

#endif
