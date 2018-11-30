#ifndef SRC_MAIN_VIEW_QTGUIVIEW_H_
#define SRC_MAIN_VIEW_QTGUIVIEW_H_

#include "presenter/GuiView.h"
#include "View.h"
#include "QTap.h"
#include "QTemperature.h"
#include "QPressure.h"
#include "QButtonHandler.h"
#include <QtWidgets/qapplication.h>
#include <QtQml/qqmlapplicationengine.h>

namespace KegeratorDisplay {

class QtGuiView : public GuiView, public View
{
public:
    QtGuiView(QApplication* qApplication, QQmlApplicationEngine* qQmlApplicationEngine);
    virtual ~QtGuiView();

    void updateView(const GuiViewModel& view);
    void run(int argc, char** argv);

private:
    void runApplication();
    void updatePressure();
    void updateTemperature(const GuiViewModel& view);
    void updateTap(const GuiViewModel& view);

    QApplication* m_qApplication;
    QQmlApplicationEngine* m_qEngine;
    QTemperature m_temperature;
    QPressure m_pressure;
    QTap m_leftTap;
    QTap m_rightTap;
};

}

#endif
