#ifndef SRC_MAIN_SHARED_THREAD_H_
#define SRC_MAIN_SHARED_THREAD_H_

namespace KegeratorDisplay {

class Thread
{
public:
    virtual ~Thread() {};

    void run();
};

}

#endif
