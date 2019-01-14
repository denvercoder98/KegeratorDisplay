#ifndef SRC_MAIN_THREAD_BOOSTDEADLINETIMER_H_
#define SRC_MAIN_THREAD_BOOSTDEADLINETIMER_H_

#include "DeadlineTimer.h"
#include <boost/asio.hpp>

namespace KegeratorDisplay {

class BoostDeadlineTimer : public DeadlineTimer
{
public:
    BoostDeadlineTimer(boost::asio::deadline_timer* t);
    virtual ~BoostDeadlineTimer();

    void asyncWaitSeconds(boost::posix_time::seconds seconds,
                          boost::function<void(const boost::system::error_code&)> callback);
    void cancel();

private:
    boost::asio::deadline_timer* m_timer;
};

}

#endif
