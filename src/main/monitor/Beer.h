#ifndef SRC_MAIN_MONITOR_BEER_H
#define SRC_MAIN_MONITOR_BEER_H

#include "AlcoholByVolume.h"
#include "InternationalBitternessUnits.h"
#include "BrewDate.h"
#include "VolumeLiters.h"
#include <string>

class Beer
{
public:
    Beer(
        const std::string& name,
        const AlcoholByVolume& abv,
        const InternationalBitternessUnits& ibu,
        const BrewDate& brewDate,
	VolumeLiters* volume);

private:
    const std::string m_name; 
    const AlcoholByVolume m_abv;
    const InternationalBitternessUnits m_ibu;
    const BrewDate m_brewDate;
    VolumeLiters* m_volumeLiters;
};

#endif
