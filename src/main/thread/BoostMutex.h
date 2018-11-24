#ifndef SRC_MAIN_THREAD_BOOSTMUTEX_H_
#define SRC_MAIN_THREAD_BOOSTMUTEX_H_

#include <boost/thread/mutex.hpp>
#include <thread/Mutex.h>

namespace KegeratorDisplay {

class BoostMutex : public Mutex
{
public:
    BoostMutex();
    virtual ~BoostMutex();

    virtual void lock();
    virtual void unlock();

private:
    boost::mutex m_mutex;
};

}

#endif
