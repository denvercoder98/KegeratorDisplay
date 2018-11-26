#include "Tap.h"
#include "Beer.h"

namespace KegeratorDisplay {

Tap::Tap() :
    m_beer()
{
}

Tap::Tap(Beer& beer) :
    m_beer(beer)
{
}

Tap::~Tap()
{
}

bool Tap::operator==(const Tap& other) const
{
    return m_beer == other.m_beer;
}

Beer Tap::beer() const
{
    return m_beer;
}

void Tap::setBeer(Beer beer)
{
    m_beer = beer;
}

}
