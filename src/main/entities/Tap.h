#ifndef SRC_MAIN_ENTITIES_TAP_H
#define SRC_MAIN_ENTITIES_TAP_H

#include "Beer.h"
#include <ostream>

namespace KegeratorDisplay {

class Tap
{
public:
    Tap();
    Tap(Beer& beer);
    virtual ~Tap();

    bool operator==(const Tap& other) const;
    friend std::ostream& operator<<(std::ostream& stream, const Tap& tap)
    {
        return stream << "["
            << "empty: " << tap.m_empty << ", "
            << "beer: " << tap.m_beer
            << "]";
    }

    Beer beer() const;
    void setBeer(Beer beer);
    bool isEmpty() const;
    void setEmpty(bool empty);

private:
    bool m_empty;
    Beer m_beer;
};

}

#endif
