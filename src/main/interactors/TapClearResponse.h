#ifndef SRC_MAIN_INTERACTORS_TAPCLEARRESPONSE_H_
#define SRC_MAIN_INTERACTORS_TAPCLEARRESPONSE_H_

#include "TapSide.h"

namespace KegeratorDisplay {

class TapClearResponse
{
public:
    TapClearResponse(const TapSide side) :
        m_side(side)
    {
    }

    virtual ~TapClearResponse()
    {
    }

    const TapSide side() const
    {
        return m_side;
    }

    bool operator==(const TapClearResponse& other) const
    {
        return m_side == other.m_side;
    }

private:
    TapSide m_side;
};

}

#endif
