#ifndef SRC_MAIN_VIEW_QBUTTONHANDLER_H_
#define SRC_MAIN_VIEW_QBUTTONHANDLER_H_

#include <controller/UserInputControllerImpl.h>
#include <QtCore/qobject.h>
#include <iostream>

namespace KegeratorDisplay {

class QmlButtonHandler : public QObject
{
    Q_OBJECT
public:
    explicit QmlButtonHandler(UserInputController& userInputController, QObject *parent = 0) :
        QObject(parent),
        m_userInputController(userInputController)
    {
    }

public slots:
    void clearTap(const QString &msg)
    {
        m_userInputController.clearTap(msg.toStdString());
    }

    void editTap(const QString &msg)
    {
    }

    void screenTouched()
    {
        m_userInputController.screenTouched();
    }

private:
    UserInputController& m_userInputController;

};

}

#endif
