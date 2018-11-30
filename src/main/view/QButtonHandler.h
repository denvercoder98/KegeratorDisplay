#ifndef SRC_MAIN_VIEW_QBUTTONHANDLER_H_
#define SRC_MAIN_VIEW_QBUTTONHANDLER_H_

#include <QtCore/qobject.h>
#include <iostream>
#include "controller/UserInputController.h"

namespace KegeratorDisplay {

class QButtonHandler : public QObject
{
    Q_OBJECT
public:
    explicit QButtonHandler(UserInputController* userInputController, QObject *parent = 0) :
        QObject(parent),
        m_userInputController(userInputController)
    {
    }

public slots:
    void clearTap(const QString &msg)
    {
        m_userInputController->clearTap(msg.toStdString());
    }

private:
    UserInputController* m_userInputController;

};

}

#endif
