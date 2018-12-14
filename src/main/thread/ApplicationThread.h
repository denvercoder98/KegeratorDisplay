#ifndef SRC_MAIN_THREAD_APPLICATIONTHREAD_H_
#define SRC_MAIN_THREAD_APPLICATIONTHREAD_H_

#include <boost/function.hpp>

namespace KegeratorDisplay {

class ApplicationThread
{
public:
    virtual ~ApplicationThread() {};

    virtual void post(boost::function<void()> f) = 0;
};

}

#endif
