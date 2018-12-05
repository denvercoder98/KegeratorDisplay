#include "QtGuiView.h"
#include <QtQuick/qquickview.h>
#include <QtQml/qqmlcontext.h>
#include <QtQuickControls2/qquickstyle.h>
#include <iostream>

namespace KegeratorDisplay {

QtGuiView::QtGuiView(QApplication* qApplication, QQmlApplicationEngine* qQmlApplicationEngine) :
    m_qApplication(qApplication),
    m_qEngine(qQmlApplicationEngine),
    m_temperature(),
    m_pressure(),
    m_leftTap(),
    m_rightTap()
{
}

QtGuiView::~QtGuiView()
{
}

void QtGuiView::updatePressure()
{
    m_pressure.setPressure("0,8");
    m_pressure.setUnit("bar");
}

void QtGuiView::updateTemperature(const GuiViewModel& view)
{
    std::string t = view.temperature;
    m_temperature.setTemperature(QString(t.c_str()));
    m_temperature.setUnit("C"); //TODO
}

void QtGuiView::updateTap(const GuiViewModel& view)
{
    m_leftTap.setName(QString(view.leftTapBeerName.c_str()));
    m_leftTap.setEstVolume(QString("12"));
    m_leftTap.setBrewer(QString(view.leftTapBrewerName.c_str()));
    m_leftTap.setAbv(QString(view.leftTapAbv.c_str()));
    m_leftTap.setIbu(QString(view.leftTapIbu.c_str()));
    m_leftTap.setBrewDate(QString(view.leftTapBrewDate.c_str()));
    m_leftTap.setTapDate(QString(view.leftTapTapDate.c_str()));
    m_leftTap.setFinalGravity(QString(view.leftTapFg.c_str()));

    m_rightTap.setName(QString(view.rightTapBeerName.c_str()));
    m_rightTap.setEstVolume(QString("12"));
    m_rightTap.setBrewer(QString(view.rightTapBrewerName.c_str()));
    m_rightTap.setAbv(QString(view.rightTapAbv.c_str()));
    m_rightTap.setIbu(QString(view.rightTapIbu.c_str()));
    m_rightTap.setBrewDate(QString(view.rightTapBrewDate.c_str()));
    m_rightTap.setTapDate(QString(view.rightTapTapDate.c_str()));
    m_rightTap.setFinalGravity(QString(view.rightTapFg.c_str()));
}

void QtGuiView::updateView(const GuiViewModel& view)
{
    updateTemperature(view);
    updatePressure();
    updateTap(view);
}

void QtGuiView::run()
{
    m_qEngine->rootContext()->setContextProperty("temperature", &m_temperature);
    m_qEngine->rootContext()->setContextProperty("pressure", &m_pressure);
    m_qEngine->rootContext()->setContextProperty("leftTap", &m_leftTap);
    m_qEngine->rootContext()->setContextProperty("rightTap", &m_rightTap);
    m_qEngine->load(QUrl(QStringLiteral("qrc:main.qml")));
    m_qApplication->exec();
}

}
