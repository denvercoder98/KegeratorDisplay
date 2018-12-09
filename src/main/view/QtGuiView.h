#ifndef SRC_MAIN_VIEW_QTGUIVIEW_H_
#define SRC_MAIN_VIEW_QTGUIVIEW_H_

#include "presenter/GuiView.h"
#include "QTap.h"
#include "QTemperature.h"
#include "QPressure.h"
#include <QtWidgets/qapplication.h>
#include <QtQml/qqmlapplicationengine.h>

namespace KegeratorDisplay {

class QtGuiView : public GuiView
{
public:
    QtGuiView(QApplication* qApplication, QQmlApplicationEngine* qQmlApplicationEngine);
    virtual ~QtGuiView();

    void updateView(const GuiViewModel& view);
    void run();

private:
    void runApplication();
    void updatePressure();
    void updateTemperature(const GuiViewModel& view);
    void updateTap(const GuiViewModel& view);
    void updateButtons(const GuiViewModel& view);

    QApplication* m_qApplication;
    QQmlApplicationEngine* m_qEngine;
    QTemperature m_temperature;
    QPressure m_pressure;
    QTap m_leftTap;
    QTap m_rightTap;
};

}

#endif
