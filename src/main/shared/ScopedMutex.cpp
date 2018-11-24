#include "shared/ScopedMutex.h"
#include "shared/Mutex.h"

namespace KegeratorDisplay {

ScopedMutex::ScopedMutex(Mutex* const mutex) :
    m_mutex(mutex)
{
    m_mutex->lock();
}

ScopedMutex::~ScopedMutex()
{
    m_mutex->unlock();
}

}
