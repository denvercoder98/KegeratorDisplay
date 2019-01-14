#include "BoostMutex.h"

namespace KegeratorDisplay {

BoostMutex::BoostMutex()
{
}

BoostMutex::~BoostMutex()
{
}

void BoostMutex::lock()
{
    m_mutex.lock();
}

void BoostMutex::unlock()
{
    m_mutex.unlock();
}

}
