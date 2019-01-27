#include "TapUpdateRequest.h"

namespace KegeratorDisplay {

TapUpdateRequest::TapUpdateRequest(const TapSide side,
                                   const std::string& name,
                                   const std::string& estVolume,
                                   const std::string& brewer,
                                   const std::string& abv,
                                   const std::string& ibu,
                                   const std::string& brewDate,
                                   const std::string& tapDate,
                                   const std::string& finalGravity) :
                                       m_side(side),
                                       m_name(name),
                                       m_estVolume(estVolume),
                                       m_brewer(brewer),
                                       m_abv(abv),
                                       m_ibu(ibu),
                                       m_brewDate(brewDate),
                                       m_tapDate(tapDate),
                                       m_finalGravity(finalGravity)
{
}

TapUpdateRequest::~TapUpdateRequest()
{
}

bool TapUpdateRequest::operator==(const TapUpdateRequest& other) const
{
    return m_side == other.m_side &&
        m_name == other.m_name &&
        m_estVolume == other.m_estVolume &&
        m_abv == other.m_abv &&
        m_ibu == other.m_ibu &&
        m_brewDate == other.m_brewDate &&
        m_tapDate == other.m_tapDate &&
        m_finalGravity == other.m_finalGravity;
}

}
