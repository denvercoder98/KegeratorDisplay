#ifndef SRC_MAIN_VIEW_QBUTTONHANDLER_H_
#define SRC_MAIN_VIEW_QBUTTONHANDLER_H_

#include "controllers/UserInputController.h"
#include "view/qobjects/QTap.h"
#include <QtCore/qobject.h>
#include <iostream>

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
        m_userInputController(userInputController),
        m_leftTap(leftTap),
        m_rightTap(rightTap)
    {
    }

public slots:
    void clearTap(const QString &side)
    {
        m_userInputController.clearTap(side.toStdString());
    }

    void saveTap(const QString &side)
    {
        QTap* qTap;
        if (side == "left") {
            qTap = &m_leftTap;
        }
        else if (side == "right") {
            qTap = &m_rightTap;
        }
        else {
            return;
        }

        DeviceTapData tapData(
            qTap->name().toStdString(),
            qTap->estVolume().toStdString(),
            qTap->brewer().toStdString(),
            qTap->abv().toStdString(),
            qTap->ibu().toStdString(),
            qTap->brewDate().toStdString(),
            qTap->tapDate().toStdString(),
            qTap->finalGravity().toStdString());
        m_userInputController.saveTap(side.toStdString(), tapData);
    }

    void screenTouched()
    {
        m_userInputController.screenTouched();
    }

private:
    UserInputController& m_userInputController;
    QTap& m_leftTap;
    QTap& m_rightTap;

};

}

#endif
