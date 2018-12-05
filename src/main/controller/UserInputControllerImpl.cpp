#include <controller/UserInputControllerImpl.h>
#include "InvalidUserInputControllerArgumentException.h"

namespace KegeratorDisplay {

UserInputControllerImpl::UserInputControllerImpl(TapClearRequestObserver* observer) :
    m_tapClearObserver(observer)
{
    if (observer == NULL)
    {
        throw InvalidUserInputControllerArgumentException("Missing TapClearRequestObserver dependency");
    }
}

UserInputControllerImpl::~UserInputControllerImpl()
{
}

void UserInputControllerImpl::clearTap(const std::string& side)
{
    TapSide tapSide;
    if (side == "left") {
        TapClearRequest request(TAP_LEFT);
        m_tapClearObserver->handleRequest(request);
    }
    else if (side == "right") {
        TapClearRequest request(TAP_RIGHT);
        m_tapClearObserver->handleRequest(request);
    }
}

}
