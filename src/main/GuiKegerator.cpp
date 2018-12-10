#include <GuiKegerator.h>
#include "view/QtGuiView.h"

namespace KegeratorDisplay {

GuiKegerator::GuiKegerator(GuiView& view,
                           SensorSampler*
                           sensorSampler,
                           boost::asio::io_service& ioService,
                           boost::thread& thread) :
    Kegerator(sensorSampler, ioService, thread),
    m_view(view)
{
}

GuiKegerator::~GuiKegerator()
{
}

void GuiKegerator::run()
{
    m_view.run();
}

}
