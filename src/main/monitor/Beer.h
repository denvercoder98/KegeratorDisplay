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
    Beer(const std::string& name,
         const std::string& brewerName,
         const AlcoholByVolume& abv,
         const InternationalBitternessUnits& ibu,
         const Date& brewDate,
         const Date& tapDate,
         const SpecificGravity& finalGravity);

    const std::string name() const;
    const std::string brewerName() const;
    const AlcoholByVolume alcoholByVolume() const;
    const InternationalBitternessUnits internationalBitternessUnits() const;
    const Date brewDate() const;
    const Date tapDate() const;
    const SpecificGravity finalGravity() const;

private:
    const std::string m_name;
    const std::string m_brewerName;
    const AlcoholByVolume m_abv;
    const InternationalBitternessUnits m_ibu;
    const Date m_brewDate;
    const Date m_tapDate;
    const SpecificGravity m_finalGravity;
};

}

#endif
