#ifndef SRC_MAIN_PRESENTER_GUIPRESENTER_H_
#define SRC_MAIN_PRESENTER_GUIPRESENTER_H_

#include "interactors/Presenter.h"
#include "GuiViewModel.h"

namespace KegeratorDisplay {

class GuiView;

class GuiPresenter : public Presenter
{
public:
    GuiPresenter(GuiView* view, GuiViewModel* viewModel);
    virtual ~GuiPresenter();

    void updateTemperature(const TemperatureUpdateResponse& temperature);
    void updateTap(const TapUpdateResponse& tap);
    void clearTap(const TapClearResponse& tap);

private:
    GuiViewModel::TapViewModel* getTapViewModelForSide(const TapSide tap);
    void clearTapData(GuiViewModel::TapViewModel* tapModel);

    GuiView* m_view;
    GuiViewModel* m_viewModel;
};

}

#endif
