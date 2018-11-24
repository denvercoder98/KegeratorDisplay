#ifndef SRC_MAIN_THREAD_MUTEX_H_
#define SRC_MAIN_THREAD_MUTEX_H_

namespace KegeratorDisplay {

class Mutex
{
public:
    virtual ~Mutex() {};

    virtual void lock() = 0;
    virtual void unlock() = 0;
};

}

#endif
