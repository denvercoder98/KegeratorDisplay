#ifndef SRC_MAIN_MONITOR_TAPUPDATE_H
#define SRC_MAIN_MONITOR_TAPUPDATE_H

#include "BeerUpdate.h"

namespace KegeratorDisplay {

typedef enum {TAP_LEFT, TAP_RIGHT} TapSide;

class TapUpdate
{
public:
    TapUpdate(TapSide side, BeerUpdate value) :
        m_side(side),
        m_value(value)
    {
    }

    TapSide side() const
    {
        return m_side;
    }

    BeerUpdate beer() const
    {
        return m_value;
    }

    bool operator==(const TapUpdate& update) const
    {
        return m_side == update.m_side && m_value == update.m_value;
    }

private:
    TapSide m_side;
    BeerUpdate m_value;
};

}

#endif
