#include <controller/UserInputControllerImpl.h>
#include "devices/AcceptanceTestInputDevice.h"

namespace KegeratorDisplay {

AcceptanceTestInputDevice::AcceptanceTestInputDevice(UserInputController* userInputController) :
    m_userInputController(userInputController)
{
}

AcceptanceTestInputDevice::~AcceptanceTestInputDevice()
{
}

void AcceptanceTestInputDevice::clearLeftTapPressed()
{
    m_userInputController->clearTap("left");
}

}
