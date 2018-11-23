#ifndef SRC_MAIN_SHARED_BOOSTMUTEX_H_
#define SRC_MAIN_SHARED_BOOSTMUTEX_H_

#include "Mutex.h"
#include <boost/thread/mutex.hpp>

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
