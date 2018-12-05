#ifndef SRC_MAIN_DEVICES_QMLINPUTDEVICE_H_
#define SRC_MAIN_DEVICES_QMLINPUTDEVICE_H_

#include <devices/QmlButtonHandler.h>
#include <QtQml/qqmlapplicationengine.h>
#include <QtQml/qqmlcontext.h>

namespace KegeratorDisplay {

class UserInputController;

class QmlInputDevice
{
public:
    QmlInputDevice(QQmlApplicationEngine* qQmlApplicationEngine,
                     UserInputController* UserInputController);
    virtual ~QmlInputDevice();

private:
    QmlButtonHandler m_buttonHandler;
    UserInputController* m_userInputController;
};

}

#endif
