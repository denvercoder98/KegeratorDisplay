#include <devices/QmlContextPropertyRegistrator.h>
#include "QmlInputDevice.h"
#include "controller/UserInputController.h"

namespace KegeratorDisplay {

QmlInputDevice::QmlInputDevice(QmlContextPropertyRegistrator& qmlContextPropertyRegistrator,
                                   UserInputController& userInputController) :
    m_buttonHandler(userInputController),
    m_userInputController(userInputController)
{
    qmlContextPropertyRegistrator.setContextProperty("buttonHandler", &m_buttonHandler);
}

QmlInputDevice::~QmlInputDevice()
{
}

}
