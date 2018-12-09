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
    m_leftTap.setName(QString(view.leftTap.beerName.c_str()));
    m_leftTap.setEstVolume(QString("12"));
    m_leftTap.setBrewer(QString(view.leftTap.brewerName.c_str()));
    m_leftTap.setAbv(QString(view.leftTap.abv.c_str()));
    m_leftTap.setIbu(QString(view.leftTap.ibu.c_str()));
    m_leftTap.setBrewDate(QString(view.leftTap.brewDate.c_str()));
    m_leftTap.setTapDate(QString(view.leftTap.tapDate.c_str()));
    m_leftTap.setFinalGravity(QString(view.leftTap.fg.c_str()));

    m_rightTap.setName(QString(view.rightTap.beerName.c_str()));
    m_rightTap.setEstVolume(QString("12"));
    m_rightTap.setBrewer(QString(view.rightTap.brewerName.c_str()));
    m_rightTap.setAbv(QString(view.rightTap.abv.c_str()));
    m_rightTap.setIbu(QString(view.rightTap.ibu.c_str()));
    m_rightTap.setBrewDate(QString(view.rightTap.brewDate.c_str()));
    m_rightTap.setTapDate(QString(view.rightTap.tapDate.c_str()));
    m_rightTap.setFinalGravity(QString(view.rightTap.fg.c_str()));
}

void QtGuiView::updateButtons(const GuiViewModel& view)
{
    m_leftTap.setButtonsVisible(view.buttonsVisible);
    m_rightTap.setButtonsVisible(view.buttonsVisible);
}

void QtGuiView::updateView(const GuiViewModel& view)
{
    updateTemperature(view);
    updatePressure();
    updateTap(view);
    updateButtons(view);
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
