#ifndef SRC_MAIN_GUIKEGERATOR_H_
#define SRC_MAIN_GUIKEGERATOR_H_

#include <Kegerator.h>
#include <QtWidgets/qapplication.h>
#include <QtQml/qqmlapplicationengine.h>
#include "view/QtGuiView.h"

namespace KegeratorDisplay {

class Presenter;
class QmlInputDevice;

class GuiKegerator : public Kegerator
{
public:
    GuiKegerator();
    virtual ~GuiKegerator();

protected:
    void doCreateView(int &argc, char** argv);
    void doCreateDevices();

    void run();

private:
    QApplication* m_qApplication;
    QQmlApplicationEngine* m_qEngine;
    QmlInputDevice* m_qmlInputDevice;

};

}

#endif
