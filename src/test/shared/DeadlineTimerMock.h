#ifndef SRC_TEST_SHARED_DEADLINETIMERMOCK_H_
#define SRC_TEST_SHARED_DEADLINETIMERMOCK_H_

#include "src/main/shared/DeadlineTimer.h"
#include "gmock/gmock.h"

namespace KegeratorDisplay {

class DeadlineTimerMock: public DeadlineTimer
{
public:
    MOCK_METHOD2(asyncWaitSeconds, void(boost::posix_time::seconds seconds, boost::function<void(const boost::system::error_code&)>));
};

}

#endif
