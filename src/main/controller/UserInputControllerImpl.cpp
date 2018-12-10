#include <controller/UserInputControllerImpl.h>
#include "interactors/TapClearRequestObserver.h"
#include "interactors/ScreenTouchedRequestObserver.h"

namespace KegeratorDisplay {

UserInputControllerImpl::UserInputControllerImpl(
    TapClearRequestObserver& tapClearObserver,
    ScreenTouchedRequestObserver& screenTouchedObserver) :
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
        m_tapClearObserver.handleRequest(request);
    }
    else if (side == "right") {
        TapClearRequest request(TAP_RIGHT);
        m_tapClearObserver.handleRequest(request);
    }
}

void UserInputControllerImpl::screenTouched()
{
    ScreenTouchedRequest request;
    m_screenTouchedObserver.handleRequest(request);
}

}
