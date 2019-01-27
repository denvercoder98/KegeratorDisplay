#ifndef SRC_TEST_UNIT_THREAD_APPLICATIONTHREADFAKE_H_
#define SRC_TEST_UNIT_THREAD_APPLICATIONTHREADFAKE_H_

#include "thread/ApplicationThread.h"
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class ApplicationThreadFake : public ApplicationThread
{
public:
    ApplicationThreadFake() : m_posted(false)
    {
    }

    void post(boost::function<void()> f)
    {
        m_posted = true;
        f();
    }

    bool isPosted() const
    {
        return m_posted;
    }

private:
    bool m_posted;
};

}

#endif
