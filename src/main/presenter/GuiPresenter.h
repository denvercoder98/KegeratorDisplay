#ifndef SRC_MAIN_PRESENTER_GUIPRESENTER_H_
#define SRC_MAIN_PRESENTER_GUIPRESENTER_H_

#include <monitor/Presenter.h>

namespace KegeratorDisplay {

class GuiView;
class GuiViewModel;

class GuiPresenter: public Presenter
{
public:
    GuiPresenter(GuiView* view, GuiViewModel* viewModel);
    virtual ~GuiPresenter();

    void updateTemperature(const TemperatureUpdateResponse& temperature);
    void updateTap(const TapUpdateResponse& tap);

private:
    GuiView* m_view;
    GuiViewModel* m_viewModel;
};

}

#endif
