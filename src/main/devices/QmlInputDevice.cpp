#include <devices/QmlInputDevice.h>
#include "controller/UserInputController.h"

namespace KegeratorDisplay {

QmlInputDevice::QmlInputDevice(QQmlApplicationEngine& qQmlApplicationEngine,
                                   UserInputController& userInputController) :
    m_buttonHandler(userInputController),
    m_userInputController(userInputController)
{
    qQmlApplicationEngine.rootContext()->setContextProperty("buttonHandler", &m_buttonHandler);
}

QmlInputDevice::~QmlInputDevice()
{
}

}
