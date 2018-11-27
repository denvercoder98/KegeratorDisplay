#ifndef SRC_MAIN_PRESENTER_GUIPRESENTER_H_
#define SRC_MAIN_PRESENTER_GUIPRESENTER_H_

#include <monitor/KegeratorObserver.h>

namespace KegeratorDisplay {

class GuiView;
class GuiViewModel;

class GuiPresenter: public KegeratorObserver
{
public:
    GuiPresenter(GuiView* view, GuiViewModel* viewModel);
    virtual ~GuiPresenter();

    void updateTemperature(const TemperatureUpdate& temperature);
    void updateTap(const TapUpdate& tap);

private:
    GuiView* m_view;
    GuiViewModel* m_viewModel;
};

}

#endif
