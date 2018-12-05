#include <view/AcceptanceTestGuiView.h>

namespace KegeratorDisplay {

AcceptanceTestGuiView::AcceptanceTestGuiView()
{
}

AcceptanceTestGuiView::~AcceptanceTestGuiView()
{
}

void AcceptanceTestGuiView::updateView(const GuiViewModel& view)
{
    m_currentView = view;
}

GuiViewModel AcceptanceTestGuiView::getCurrentView()
{
    return m_currentView;
}

void AcceptanceTestGuiView::run()
{
}

}
