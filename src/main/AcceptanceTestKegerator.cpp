#include "AcceptanceTestKegerator.h"
#include "devices/AcceptanceTestInputDevice.h"
#include "view/AcceptanceTestGuiView.h"

namespace KegeratorDisplay {

AcceptanceTestKegerator::AcceptanceTestKegerator() :
    Kegerator(),
    m_view(NULL),
    m_inputDevice(NULL)
{
    std::cout << "AcceptanceTestKegerator" << std::endl;
}

AcceptanceTestKegerator::~AcceptanceTestKegerator()
{
    if (m_inputDevice) {
        delete m_inputDevice;
    }
}

void AcceptanceTestKegerator::updateView(const GuiViewModel& view)
{
    m_currentViewModel = view;
}

GuiViewModel AcceptanceTestKegerator::getViewModel() const
{
    return m_view->getCurrentView();
}

void AcceptanceTestKegerator::clearLeftTap()
{
    m_inputDevice->clearLeftTapPressed();
}

void AcceptanceTestKegerator::createView(int &argc, char** argv)
{
    m_view = new AcceptanceTestGuiView();
    p_view = m_view;
}

void AcceptanceTestKegerator::createDevices()
{
    UserInputController* userInputController = getUserInputController();
    m_inputDevice = new AcceptanceTestInputDevice(userInputController);
}

void AcceptanceTestKegerator::run()
{
}

}
