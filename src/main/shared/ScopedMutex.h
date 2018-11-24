#ifndef SRC_MAIN_SHARED_SCOPEDMUTEX_H_
#define SRC_MAIN_SHARED_SCOPEDMUTEX_H_

namespace KegeratorDisplay {

class Mutex;

class ScopedMutex
{
public:
    ScopedMutex(Mutex* const mutex);
    ScopedMutex(const ScopedMutex&) = delete;
    virtual ~ScopedMutex();

private:
    Mutex* const m_mutex;
};

}

#endif
