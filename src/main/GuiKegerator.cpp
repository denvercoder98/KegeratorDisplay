#include <GuiKegerator.h>
#include "view/QtGuiView.h"

namespace KegeratorDisplay {

GuiKegerator::GuiKegerator(GuiView* view, SensorSampler* sensorSampler, boost::asio::io_service* ioService) :
    Kegerator(sensorSampler, ioService),
    m_view(view)
{
}

GuiKegerator::~GuiKegerator()
{
    delete m_view;
}

void GuiKegerator::run()
{
    m_view->run();
}

}
