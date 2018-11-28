#ifndef SRC_MAIN_INTERACTORS_TAPUPDATE_H
#define SRC_MAIN_INTERACTORS_TAPUPDATE_H

#include <interactors/BeerUpdateResponse.h>

namespace KegeratorDisplay {

typedef enum {TAP_LEFT, TAP_RIGHT} TapSide;

class TapUpdateResponse
{
public:
    TapUpdateResponse(TapSide side, BeerUpdateResponse value) :
        m_side(side),
        m_value(value)
    {
    }

    TapSide side() const
    {
        return m_side;
    }

    BeerUpdateResponse beer() const
    {
        return m_value;
    }

    bool operator==(const TapUpdateResponse& update) const
    {
        return m_side == update.m_side && m_value == update.m_value;
    }

private:
    TapSide m_side;
    BeerUpdateResponse m_value;
};

}

#endif