#include <GuiKegerator.h>
#include "devices/QtQmlInputDevice.h"

namespace KegeratorDisplay {

GuiKegerator::GuiKegerator() :
    Kegerator(),
    m_qApplication(NULL),
    m_qEngine(NULL),
    m_qmlInputDevice(NULL)
{
}

GuiKegerator::~GuiKegerator()
{
    if (m_qEngine) {
        delete m_qEngine;
    }
    if (m_qApplication) {
        delete m_qApplication;
    }
    if (m_qmlInputDevice) {
        delete m_qmlInputDevice;
    }
}

void GuiKegerator::createView(int &argc, char** argv)
{
    m_qApplication = new QApplication(argc, argv);
    m_qEngine = new QQmlApplicationEngine();
    p_view = new QtGuiView(m_qApplication, m_qEngine);
}

void GuiKegerator::createDevices()
{
    UserInputController* userInputController = getUserInputController();
    m_qmlInputDevice = new QtQmlInputDevice(m_qEngine, userInputController); //TODO turn controller into interface?
}

void GuiKegerator::run()
{
    p_view->run();
}

}
