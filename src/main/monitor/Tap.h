#ifndef SRC_MAIN_MONITOR_TAP_H
#define SRC_MAIN_MONITOR_TAP_H

#include "Beer.h"

namespace KegeratorDisplay {

class Tap
{
public:
    Tap();
    Tap(Beer& beer);
    virtual ~Tap();

    bool operator==(const Tap& other) const;

    Beer beer() const;

    void setBeer(Beer beer);

private:
    Beer m_beer;
};

}

#endif
