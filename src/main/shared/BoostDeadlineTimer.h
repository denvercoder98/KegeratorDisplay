#ifndef SRC_MAIN_SHARED_BOOSTDEADLINETIMER_H_
#define SRC_MAIN_SHARED_BOOSTDEADLINETIMER_H_

#include "DeadlineTimer.h"
#include <boost/asio.hpp>

namespace KegeratorDisplay {

class BoostDeadlineTimer : public DeadlineTimer
{
public:
    BoostDeadlineTimer(boost::asio::deadline_timer* t);
    virtual ~BoostDeadlineTimer();

    virtual void asyncWaitSeconds(boost::posix_time::seconds seconds,
                                  boost::function<void(const boost::system::error_code&)> callback);

private:
    boost::asio::deadline_timer* m_timer;
};

}

#endif
