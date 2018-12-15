#ifndef SRC_MAIN_THREAD_APPLICATIONTHREADIMPL_H_
#define SRC_MAIN_THREAD_APPLICATIONTHREADIMPL_H_

#include "ApplicationThread.h"
#include <boost/asio/io_service.hpp>

namespace KegeratorDisplay {

class ApplicationThreadImpl: public ApplicationThread
{
public:
    ApplicationThreadImpl(boost::asio::io_service& ioService);
    virtual ~ApplicationThreadImpl();

    void post(boost::function<void()> f);

private:
    boost::asio::io_service& m_ioService;
};

}

#endif
