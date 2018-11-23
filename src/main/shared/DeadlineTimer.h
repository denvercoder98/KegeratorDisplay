#ifndef SRC_MAIN_SHARED_DEADLINETIMER_H_
#define SRC_MAIN_SHARED_DEADLINETIMER_H_

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/asio.hpp>
#include <boost/function.hpp>

namespace KegeratorDisplay {

class DeadlineTimer
{
public:
    virtual ~DeadlineTimer() {};

    virtual void asyncWaitSeconds(boost::posix_time::seconds seconds,
                                  boost::function<void(const boost::system::error_code&)> callback) = 0;
};

}

#endif
