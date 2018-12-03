#ifndef SRC_MAIN_GUIKEGERATOR_H_
#define SRC_MAIN_GUIKEGERATOR_H_

#include <Kegerator.h>
#include <QtWidgets/qapplication.h>
#include <QtQml/qqmlapplicationengine.h>
#include "view/QtGuiView.h"

namespace KegeratorDisplay {

class Presenter;
class QtQmlInputDevice;

class GuiKegerator : public Kegerator
{
public:
    GuiKegerator();
    virtual ~GuiKegerator();

    QtGuiView* m_view;
    QApplication* m_qApplication;
    QQmlApplicationEngine* m_qEngine;
    QtQmlInputDevice* m_qmlInputDevice;

protected:
    void createViewAndPresenter(int &argc, char** argv);
    void createDevices();

    void run(int argc, char** argv);
};

}

#endif
