#include "Tap.h"
#include "Beer.h"

namespace KegeratorDisplay {

Tap::Tap() :
    m_empty(true),
    m_beer()
{
}

Tap::Tap(Beer& beer) :
    m_empty(false),
    m_beer(beer)
{
}

Tap::~Tap()
{
}

bool Tap::operator==(const Tap& other) const
{
    return m_beer == other.m_beer &&
        m_empty == other.m_empty;
}

Beer Tap::beer() const
{
    return m_beer;
}

void Tap::setBeer(Beer beer)
{
    m_beer = beer;
}

bool Tap::isEmpty() const
{
    return m_empty;
}

void Tap::setEmpty(bool empty)
{
    m_empty = empty;
}

}
