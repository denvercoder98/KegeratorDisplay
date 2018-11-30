#include <devices/QtQmlInputDevice.h>
#include "controller/UserInputController.h"

namespace KegeratorDisplay {

QtQmlInputDevice::QtQmlInputDevice(QQmlApplicationEngine* qQmlApplicationEngine,
                                   UserInputController* userInputController) :
    m_buttonHandler(userInputController),
    m_userInputController(userInputController)
{
    qQmlApplicationEngine->rootContext()->setContextProperty("buttonHandler", &m_buttonHandler);
}

QtQmlInputDevice::~QtQmlInputDevice()
{
}

}
