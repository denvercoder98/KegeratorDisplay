#include <controller/UserInputControllerImpl.h>
#include "thread/ApplicationThread.h"
#include "interactors/TapClearRequestObserver.h"
#include "interactors/ScreenTouchedRequestObserver.h"
#include <boost/bind.hpp>

namespace KegeratorDisplay {

UserInputControllerImpl::UserInputControllerImpl(
    ApplicationThread& appThread,
    TapClearRequestObserver& tapClearObserver,
    ScreenTouchedRequestObserver& screenTouchedObserver) :
        m_appThread(appThread),
        m_tapClearObserver(tapClearObserver),
        m_screenTouchedObserver(screenTouchedObserver)
{
}

UserInputControllerImpl::~UserInputControllerImpl()
{
}

void UserInputControllerImpl::clearTap(const std::string& side)
{
    TapSide tapSide;
    if (side == "left") {
        TapClearRequest request(TAP_LEFT);
        notifyTapClearRequestObserver(request);
    }
    else if (side == "right") {
        TapClearRequest request(TAP_RIGHT);
        notifyTapClearRequestObserver(request);
   }
}

void UserInputControllerImpl::notifyTapClearRequestObserver(const TapClearRequest& request)
{
    m_appThread.post(boost::bind(&TapClearRequestObserver::handleRequest, &m_tapClearObserver, request));
}

void UserInputControllerImpl::screenTouched()
{
    ScreenTouchedRequest request;
    notifyScreenTouchedRequestObserver(request);
}

void UserInputControllerImpl::notifyScreenTouchedRequestObserver(const ScreenTouchedRequest& request)
{
    m_appThread.post(boost::bind(&ScreenTouchedRequestObserver::handleRequest, &m_screenTouchedObserver, request));
}

}
