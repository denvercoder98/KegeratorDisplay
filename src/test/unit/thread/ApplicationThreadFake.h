#ifndef SRC_TEST_UNIT_THREAD_APPLICATIONTHREADFAKE_H_
#define SRC_TEST_UNIT_THREAD_APPLICATIONTHREADFAKE_H_

#include "thread/ApplicationThread.h"
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class ApplicationThreadFake : public ApplicationThread
{
public:
    void post(boost::function<void()> f)
    {
        f();
    }
};

}

#endif
