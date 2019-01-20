#ifndef SRC_MAIN_VIEW_QTGUIVIEW_H_
#define SRC_MAIN_VIEW_QTGUIVIEW_H_

#include "presenter/GuiView.h"
#include "qobjects/QKegerator.h"
#include "qobjects/QTapTags.h"
#include "qobjects/QTap.h"
#include "qobjects/QTemperature.h"
#include "qobjects/QPressure.h"
#include <QtWidgets/qapplication.h>
#include <QtQml/qqmlapplicationengine.h>

namespace KegeratorDisplay {

class QtGuiView : public GuiView
{
public:
    QtGuiView(QApplication& qApplication,
              QQmlApplicationEngine& qQmlApplicationEngine,
              QTap& leftTap,
              QTap& rightTap,
              QTapTags& tapTags);
    virtual ~QtGuiView();

    void updateView(const GuiViewModel& view);
    void updateTemperature(const GuiViewTemperatureModel& view);
    void updateTap(const TapViewModel& view);
    void updatePressure(const PressureViewModel& view);
    void run();

private:
    void runApplication();
    void updateKegerator(const GuiViewModel& view);
    void updatePressure(const GuiViewModel& view);
    void updateTapTags(const GuiViewModel& view);
    void updateButtons(const GuiViewModel& view);

    QApplication& m_qApplication;
    QQmlApplicationEngine& m_qEngine;
    QKegerator m_kegerator;
    QTemperature m_temperature;
    QPressure m_pressure;
    QTapTags& m_tapTags;
    QTap& m_leftTap;
    QTap& m_rightTap;
};

}

#endif
