#ifndef SRC_TEST_THREAD_DEADLINETIMERMOCK_H_
#define SRC_TEST_THREAD_DEADLINETIMERMOCK_H_

#include <thread/DeadlineTimer.h>

#include "gmock/gmock.h"

namespace KegeratorDisplay {

class DeadlineTimerMock: public DeadlineTimer
{
public:
    MOCK_METHOD2(asyncWaitSeconds, void(boost::posix_time::seconds seconds, boost::function<void(const boost::system::error_code&)>));
};

}

#endif
