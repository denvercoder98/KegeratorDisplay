#ifndef SRC_MAIN_DEVICES_QMLINPUTDEVICE_H_
#define SRC_MAIN_DEVICES_QMLINPUTDEVICE_H_

#include <devices/QmlButtonHandler.h>
#include <QtQml/qqmlapplicationengine.h>

namespace KegeratorDisplay {

class QmlContextPropertyRegistrator;
class UserInputController;

class QmlInputDevice
{
public:
    QmlInputDevice(QmlContextPropertyRegistrator& qmlContextPropertyRegistrator,
                     UserInputController& UserInputController);
    virtual ~QmlInputDevice();

private:
    QmlButtonHandler m_buttonHandler;
    UserInputController& m_userInputController;
};

}

#endif
