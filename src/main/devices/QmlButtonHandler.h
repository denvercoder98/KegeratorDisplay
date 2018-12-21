#ifndef SRC_MAIN_VIEW_QBUTTONHANDLER_H_
#define SRC_MAIN_VIEW_QBUTTONHANDLER_H_

#include <controller/UserInputControllerImpl.h>
#include <QtCore/qobject.h>
#include "view/qobjects/QTap.h"

namespace KegeratorDisplay {

class QmlButtonHandler : public QObject
{
    Q_OBJECT
public:
    explicit QmlButtonHandler(UserInputController& userInputController,
                              QTap& leftTap,
                              QTap& rightTap,
                              QObject *parent = 0) :
        QObject(parent),
        m_userInputController(userInputController)
    {
    }

public slots:
    void clearTap(const QString &side)
    {
        m_userInputController.clearTap(side.toStdString());
    }

    void saveTap(const QString &side)
    {
        m_userInputController.saveTap(side.toStdString());
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
