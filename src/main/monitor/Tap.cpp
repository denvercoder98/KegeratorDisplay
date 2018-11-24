#include "Tap.h"
#include "Beer.h"

namespace KegeratorDisplay {

Tap::Tap(Beer* beer) :
    m_beer(beer)
{
}

Tap::~Tap()
{
    delete m_beer;
}

Beer* Tap::beer() const
{
    return m_beer;
}

}
