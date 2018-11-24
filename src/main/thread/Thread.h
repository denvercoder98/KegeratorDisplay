#ifndef SRC_MAIN_THREAD_THREAD_H_
#define SRC_MAIN_THREAD_THREAD_H_

namespace KegeratorDisplay {

class Thread
{
public:
    virtual ~Thread() {};

    void run();
};

}

#endif
