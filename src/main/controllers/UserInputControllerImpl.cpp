#include "UserInputControllerImpl.h"
#include "thread/ApplicationThread.h"
#include "interactors/TapClearRequestObserver.h"
#include "interactors/ScreenTouchedRequestObserver.h"
#include "interactors/TapUpdateRequestObserver.h"
#include <boost/bind.hpp>

namespace KegeratorDisplay {

UserInputControllerImpl::UserInputControllerImpl(
    ApplicationThread& appThread,
    TapClearRequestObserver& tapClearObserver,
    ScreenTouchedRequestObserver& screenTouchedObserver,
    TapUpdateRequestObserver& updateObserver) :
        m_appThread(appThread),
        m_tapClearObserver(tapClearObserver),
        m_screenTouchedObserver(screenTouchedObserver),
        m_updateObserver(updateObserver)
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

void UserInputControllerImpl::saveTap(const std::string& side, DeviceTapData data)
{
    TapSide tapSide;
    if (side == "left") {
        tapSide = TapSide::TAP_LEFT;
    }
    else {
        tapSide = TapSide::TAP_RIGHT;
    }
    TapUpdateRequest request(tapSide,
                             data.name,
                             data.estVolume,
                             data.brewer,
                             data.abv,
                             data.ibu,
                             data.brewDate,
                             data.tapDate,
                             data.finalGravity);
    m_appThread.post(boost::bind(&TapUpdateRequestObserver::updateTap, &m_updateObserver, request));
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
