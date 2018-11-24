#include <thread/BoostDeadlineTimer.h>

namespace KegeratorDisplay {

BoostDeadlineTimer::BoostDeadlineTimer(boost::asio::deadline_timer* timer) :
    m_timer(timer)
{
}

BoostDeadlineTimer::~BoostDeadlineTimer()
{
    delete m_timer;
}

void BoostDeadlineTimer::asyncWaitSeconds(boost::posix_time::seconds seconds,
                                          boost::function<void(const boost::system::error_code&)> callback)
{
    m_timer->expires_from_now(seconds);
    m_timer->async_wait(callback);
}

}
