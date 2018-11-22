#include "Kegerator.h"
#include "Tap.h"

namespace KegeratorDisplay {

Kegerator::Kegerator(Tap* leftTap, Tap* rightTap) :
    m_leftTap(leftTap),
    m_rightTap(rightTap)
{
}

Kegerator::~Kegerator()
{
    delete m_leftTap;
    delete m_rightTap;
}

}
