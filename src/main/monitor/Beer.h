#ifndef SRC_MAIN_MONITOR_BEER_H
#define SRC_MAIN_MONITOR_BEER_H

#include "AlcoholByVolume.h"
#include "InternationalBitternessUnits.h"
#include "Date.h"
#include "SpecificGravity.h"
#include <string>

namespace KegeratorDisplay {

class Beer
{
public:
    Beer();
    Beer(const std::string& name,
         const std::string& brewerName,
         const AlcoholByVolume& abv,
         const InternationalBitternessUnits& ibu,
         const Date& brewDate,
         const Date& tapDate,
         const SpecificGravity& finalGravity);

    Beer& operator=(const Beer& other);
    bool operator==(const Beer& other) const;

    const std::string name() const;
    void setName(const std::string& name);

    const std::string brewerName() const;
    void setBrewerName(const std::string& brewerName);

    const AlcoholByVolume alcoholByVolume() const;
    void setAlcoholByVolume(const AlcoholByVolume& abv);

    const InternationalBitternessUnits internationalBitternessUnits() const;
    void setInternationalBitternessUnits(const InternationalBitternessUnits& ibu);

    const Date brewDate() const;
    void setBrewDate(const Date& date);

    const Date tapDate() const;
    void setTapDate(const Date& date);

    const SpecificGravity finalGravity() const;
    void setFinalGravity(const SpecificGravity& fg);

private:
    std::string m_name;
    std::string m_brewerName;
    AlcoholByVolume m_abv;
    InternationalBitternessUnits m_ibu;
    Date m_brewDate;
    Date m_tapDate;
    SpecificGravity m_finalGravity;
};

}

#endif
