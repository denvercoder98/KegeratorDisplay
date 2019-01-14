#include "Mutex.h"
#include "ScopedMutex.h"

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
