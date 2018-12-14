#include <thread/ApplicationThreadImpl.h>

namespace KegeratorDisplay {

ApplicationThreadImpl::ApplicationThreadImpl(boost::asio::io_service* ioService) :
    m_ioService(ioService)
{
}

ApplicationThreadImpl::~ApplicationThreadImpl()
{
}

void ApplicationThreadImpl::post(boost::function<void()> f)
{
    m_ioService->post(f);
}

}
