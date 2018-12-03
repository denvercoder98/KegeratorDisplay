#include <GuiKegerator.h>
#include "presenter/GuiPresenter.h"
#include "devices/QtQmlInputDevice.h"

namespace KegeratorDisplay {

GuiKegerator::GuiKegerator() :
    Kegerator(),
    m_view(NULL),
    m_qApplication(NULL),
    m_qEngine(NULL),
    m_qmlInputDevice(NULL)
{
}

GuiKegerator::~GuiKegerator()
{
    delete m_view;
    delete m_qEngine;
    delete m_qApplication;
}

void GuiKegerator::createViewAndPresenter(int &argc, char** argv)
{
    m_qApplication = new QApplication(argc, argv);
    m_qEngine = new QQmlApplicationEngine();
    m_view = new QtGuiView(m_qApplication, m_qEngine);
    GuiViewModel* viewModel = new GuiViewModel();
    Presenter* presenter = new GuiPresenter(m_view, viewModel);
    setPresenter(presenter);
}

void GuiKegerator::createDevices()
{
    UserInputController* userInputController = getUserInputController();
    m_qmlInputDevice = new QtQmlInputDevice(m_qEngine, userInputController); //TODO turn controller into interface?
}

void GuiKegerator::run(int argc, char** argv)
{
    m_view->run(argc, argv);
}

}
