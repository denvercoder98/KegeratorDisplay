#ifndef SRC_MAIN_VIEW_ACCEPTANCETESTGUIVIEW_H_
#define SRC_MAIN_VIEW_ACCEPTANCETESTGUIVIEW_H_

#include "presenter/GuiView.h"

namespace KegeratorDisplay {

class AcceptanceTestGuiView : public GuiView
{
public:
    AcceptanceTestGuiView();
    virtual ~AcceptanceTestGuiView();

    void updateView(const GuiViewModel& view);
    GuiViewModel getCurrentView();
    void run();

private:
    GuiViewModel m_currentView;
};

}

#endif
