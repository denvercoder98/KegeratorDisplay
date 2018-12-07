#ifndef SRC_MAIN_INTERACTORS_TAPUPDATE_H
#define SRC_MAIN_INTERACTORS_TAPUPDATE_H

#include "BeerUpdateResponse.h"
#include "TapSide.h"

#include <ostream>

namespace KegeratorDisplay {

class TapUpdateResponse
{
public:
    TapUpdateResponse(TapSide side, BeerUpdateResponse value) :
        m_side(side),
        m_value(value),
        m_empty(false)
    {
    }

    TapUpdateResponse(TapSide side, BeerUpdateResponse value, bool empty) :
        m_side(side),
        m_value(value),
        m_empty(empty)
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

    bool empty() const {
        return m_empty;
    }

    bool operator==(const TapUpdateResponse& update) const
    {
        return m_side == update.m_side &&
            m_value == update.m_value &&
            m_empty == update.m_empty;
    }

    friend std::ostream& operator<<(std::ostream& stream, TapUpdateResponse const& update)
    {
        return stream << "["
                      << "side: '" << (update.m_side == TAP_LEFT ? "TAP_LEFT" : "TAP_RIGHT") << "', "
                      << "beer: " << update.m_value << ", "
                      << "empty: " << update.m_empty
                      << "]";
    }

private:
    TapSide m_side;
    BeerUpdateResponse m_value;
    bool m_empty;
};

}

#endif
