#include "ScreenTouchedInteractor.h"
#include "ScreenTouchedResponse.h"
#include "Presenter.h"
#include "InvalidScreenTouchedInteractorArgumentException.h"
#include "thread/DeadlineTimer.h"
#include <boost/bind.hpp>

namespace KegeratorDisplay {

ScreenTouchedInteractor::ScreenTouchedInteractor(unsigned int doubleTapWindowSeconds,
                                                 DeadlineTimer* timer,
                                                 Presenter& presenter) :
    m_timer(timer),
    m_tappedOnce(false),
    m_presenter(presenter)
{
    if (m_timer == NULL) {
        throw InvalidScreenTouchedInteractorArgumentException("Missing timer dependency");
    }
}

ScreenTouchedInteractor::~ScreenTouchedInteractor()
{
    delete m_timer;
}

void ScreenTouchedInteractor::handleRequest(const ScreenTouchedRequest& request)
{
    if (m_tappedOnce) {
        m_timer->cancel();
        m_tappedOnce = false;
        ScreenTouchedResponse response(true);
        m_presenter.screenTouched(response);
    }
    else {
        m_tappedOnce = true;
        m_timer->asyncWaitSeconds(boost::posix_time::seconds(1),
                                  boost::bind(&ScreenTouchedInteractor::stuffHappened, this, boost::asio::placeholders::error));
    }
}

void ScreenTouchedInteractor::stuffHappened(const boost::system::error_code& error)
{
    m_tappedOnce = false;
}

}
