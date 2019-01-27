#ifndef SRC_MAIN_INTERACTORS_TAPUPDATEREQUEST_H_
#define SRC_MAIN_INTERACTORS_TAPUPDATEREQUEST_H_

#include "TapSide.h"
#include <string>
#include <ostream>

namespace KegeratorDisplay {

class TapUpdateRequest
{
public:
    TapUpdateRequest(const TapSide side,
                     const std::string& name,
                     const std::string& estVolume,
                     const std::string& brewer,
                     const std::string& abv,
                     const std::string& ibu,
                     const std::string& brewDate,
                     const std::string& tapDate,
                     const std::string& finalGravity);
    virtual ~TapUpdateRequest();

    bool operator==(const TapUpdateRequest& other) const;

    friend std::ostream& operator<<(std::ostream& stream, const TapUpdateRequest& request)
    {
        return stream << "["
            << "side: '" << (request.m_side == TapSide::TAP_LEFT ? "left" : "right")
            << "', name: '" << request.m_name
            << "', estVolume: '" << request.m_estVolume
            << "', brewer: '" << request.m_brewer
            << "', abv: '" << request.m_abv
            << "', ibu: '" << request.m_ibu
            << "', brewDate: '" << request.m_brewDate
            << "', tapDate: '" << request.m_tapDate
            << "', finalGravity: '" << request.m_finalGravity
            << "]";
    }

private:
    const TapSide m_side;
    std::string m_name;
    std::string m_estVolume;
    std::string m_brewer;
    std::string m_abv;
    std::string m_ibu;
    std::string m_brewDate;
    std::string m_tapDate;
    std::string m_finalGravity;
};

}

#endif
