#include "QtGuiView.h"
#include <QtQuick/qquickview.h>
#include <QtQml/qqmlcontext.h>
#include <QtQuickControls2/qquickstyle.h>
#include <iostream>

namespace KegeratorDisplay {

QtGuiView::QtGuiView(QApplication& qApplication,
                     QQmlApplicationEngine& qQmlApplicationEngine,
                     QTap& leftTap,
                     QTap& rightTap,
                     QTapTags& tapTags) :
    m_qApplication(qApplication),
    m_qEngine(qQmlApplicationEngine),
    m_temperature(),
    m_pressure(),
    m_tapTags(tapTags),
    m_leftTap(leftTap),
    m_rightTap(rightTap)
{
}

QtGuiView::~QtGuiView()
{
}

void QtGuiView::updateKegerator(const GuiViewModel& view)
{
    m_kegerator.setHeading(QString(view.heading.c_str()));
}

void QtGuiView::updatePressure(const PressureViewModel& view)
{
    m_pressure.setTag(QString(view.tag.c_str()));
    m_pressure.setPressure(QString(view.pressure.c_str()));
    m_pressure.setUnit(QString(view.unit.c_str()));
}

void QtGuiView::updateTemperature(const GuiViewTemperatureModel& view)
{
    m_temperature.setTag(QString(view.temperatureTag.c_str()));
    m_temperature.setTemperature(QString(view.temperature.c_str()));
    m_temperature.setUnit(view.temperatureUnit.c_str());
}

void QtGuiView::updateTapTags(const GuiViewModel& view)
{
    m_tapTags.setNameTag(QString(view.beerNameTag.c_str()));
    m_tapTags.setEstVolumeTag(QString(view.estVolumeTag.c_str()));
    m_tapTags.setBrewerTag(QString(view.brewerNameTag.c_str()));
    m_tapTags.setAbvTag(QString(view.abvTag.c_str()));
    m_tapTags.setIbuTag(QString(view.ibuTag.c_str()));
    m_tapTags.setBrewDateTag(QString(view.brewDateTag.c_str()));
    m_tapTags.setTapDateTag(QString(view.tapDateTag.c_str()));
    m_tapTags.setFinalGravityTag(QString(view.fgTag.c_str()));
    m_tapTags.setClearButtonTag(QString(view.clearButtonTag.c_str()));
    m_tapTags.setSaveButtonTag(QString(view.saveButtonTag.c_str()));
}

void QtGuiView::updateTap(const TapViewModel& view)
{
    m_leftTap.setSideName(QString(view.leftTap.sideName.c_str()));
    m_leftTap.setSide(QString(view.leftTap.side.c_str()));
    m_leftTap.setName(QString(view.leftTap.beerName.c_str()));
    m_leftTap.setEstVolume(QString("12"));
    m_leftTap.setBrewer(QString(view.leftTap.brewerName.c_str()));
    m_leftTap.setAbv(QString(view.leftTap.abv.c_str()));
    m_leftTap.setIbu(QString(view.leftTap.ibu.c_str()));
    m_leftTap.setBrewDate(QString(view.leftTap.brewDate.c_str()));
    m_leftTap.setTapDate(QString(view.leftTap.tapDate.c_str()));
    m_leftTap.setFinalGravity(QString(view.leftTap.fg.c_str()));

    m_rightTap.setSideName(QString(view.rightTap.sideName.c_str()));
    m_rightTap.setSide(QString(view.rightTap.side.c_str()));
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
    updateKegerator(view);
    updateTapTags(view);
    updateButtons(view);
}

void QtGuiView::run()
{
    m_qEngine.rootContext()->setContextProperty("kegerator", &m_kegerator);
    m_qEngine.rootContext()->setContextProperty("temperature", &m_temperature);
    m_qEngine.rootContext()->setContextProperty("pressure", &m_pressure);
    m_qEngine.rootContext()->setContextProperty("tapTags", &m_tapTags);
    m_qEngine.rootContext()->setContextProperty("leftTap", &m_leftTap);
    m_qEngine.rootContext()->setContextProperty("rightTap", &m_rightTap);

    qmlRegisterType<QTap>("se.kj.CppInterface", 1, 0, "QTap");
    qmlRegisterType<QTapTags>("se.kj.CppInterface", 1, 0, "QTapTags");

    m_qEngine.load(QUrl(QStringLiteral("qrc:/Tap.qml")));
    m_qEngine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    m_qApplication.exec();
}

}
