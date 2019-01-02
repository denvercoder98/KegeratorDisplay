#ifndef SRC_MAIN_PRESENTER_GUIPRESENTER_H_
#define SRC_MAIN_PRESENTER_GUIPRESENTER_H_

#include "interactors/Presenter.h"
#include "GuiViewModel.h"

namespace KegeratorDisplay {

class GuiView;
class GuiViewTemperatureModel;

class GuiPresenter : public Presenter
{
public:
    GuiPresenter(GuiView& view,
                 GuiViewModel* viewModel,
                 GuiViewTemperatureModel* temperatureModel);
    virtual ~GuiPresenter();

    void updateTemperature(const TemperatureUpdateResponse& response);
    void updateTap(const TapUpdateResponse& response);
    void clearTap(const TapClearResponse& response);
    void screenTouched(const ScreenTouchedResponse& response);

private:
    GuiViewModel::TapViewModel* getTapViewModelForSide(const TapSide tap);
    void clearTapData(GuiViewModel::TapViewModel* tapModel);

    GuiView& m_view;
    GuiViewModel* m_viewModel;
    GuiViewTemperatureModel* m_temperatureModel;
};

}

#endif
