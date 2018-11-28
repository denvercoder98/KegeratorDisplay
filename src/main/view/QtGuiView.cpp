#include "QtGuiView.h"
#include <QtQuick/qquickview.h>
#include <QtQml/qqmlcontext.h>
#include <QtQuickControls2/qquickstyle.h>
#include <iostream>

namespace KegeratorDisplay {

QtGuiView::QtGuiView(int argc, char** argv) :
    m_qApplication(NULL),
    m_qEngine(NULL),
    m_temperature(),
    m_pressure(),
    m_leftTap(),
    m_rightTap()
{
}

QtGuiView::~QtGuiView()
{
    if (m_qEngine) {
        delete m_qEngine;
    }

    if (m_qApplication) {
        delete m_qApplication;
    }
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

void QtGuiView::updateTap(QTap* tap, const GuiViewModel& view)
{
    tap->setName(QString(view.leftTapBeerName.c_str()));
    tap->setBrewer(QString(view.leftTapBrewerName.c_str()));
    tap->setAbv(QString(view.leftTapAbv.c_str()));
    tap->setIbu(QString(view.leftTapIbu.c_str()));
    tap->setBrewDate(QString(view.leftTapBrewDate.c_str()));
    tap->setTapDate(QString(view.leftTapTapDate.c_str()));
    tap->setFinalGravity(QString(view.leftTapFg.c_str()));
}

void QtGuiView::updateView(const GuiViewModel& view)
{
    updateTemperature(view);
    updatePressure();
    updateTap(&m_leftTap, view);
    updateTap(&m_rightTap, view);
}

void QtGuiView::run(int argc, char** argv)
{
    m_qApplication = new QApplication(argc, argv);
    QQuickStyle::setStyle("Material");
    m_qEngine = new QQmlApplicationEngine();
    m_qEngine->rootContext()->setContextProperty("temperature", &m_temperature);
    m_qEngine->rootContext()->setContextProperty("pressure", &m_pressure);
    m_qEngine->rootContext()->setContextProperty("leftTap", &m_leftTap);
    m_qEngine->rootContext()->setContextProperty("rightTap", &m_rightTap);
    m_qEngine->load(QUrl(QStringLiteral("qrc:main.qml")));
    m_qApplication->exec();
}

}
