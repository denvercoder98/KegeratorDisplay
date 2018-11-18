#include "Beer.h"

Beer::Beer(
    const std::string& name,
    const AlcoholByVolume& abv,
    const InternationalBitternessUnits& ibu,
    const BrewDate& brewDate,
    VolumeLiters* volume) :
        m_name(name),
        m_abv(abv),
        m_ibu(ibu),
	m_brewDate(brewDate),
        m_volumeLiters(volume)
{
}
