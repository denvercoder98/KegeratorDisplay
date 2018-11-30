#include "UserInputController.h"
#include "InvalidUserInputControllerArgumentException.h"

namespace KegeratorDisplay {

UserInputController::UserInputController(TapClearRequestObserver* observer) :
    m_tapClearObserver(observer)
{
    if (observer == NULL)
    {
        throw InvalidUserInputControllerArgumentException("Missing TapClearRequestObserver dependency");
    }
}

UserInputController::~UserInputController()
{
}

void UserInputController::clearTap(const std::string& side)
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
