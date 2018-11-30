#ifndef SRC_MAIN_DEVICES_QTQMLINPUTDEVICE_H_
#define SRC_MAIN_DEVICES_QTQMLINPUTDEVICE_H_

#include <QtQml/qqmlapplicationengine.h>
#include "view/QButtonHandler.h" //TODO move
#include <QtQml/qqmlcontext.h>

namespace KegeratorDisplay {

class UserInputController;

class QtQmlInputDevice
{
public:
    QtQmlInputDevice(QQmlApplicationEngine* qQmlApplicationEngine,
                     UserInputController* UserInputController);
    virtual ~QtQmlInputDevice();

private:
    QButtonHandler m_buttonHandler;
    UserInputController* m_userInputController;
};

}

#endif
