#ifndef SRC_MAIN_PRESENTER_GUIPRESENTER_H_
#define SRC_MAIN_PRESENTER_GUIPRESENTER_H_

#include "interactors/Presenter.h"
#include "GuiViewModel.h"
#include "TapViewModel.h"
#include "PressureViewModel.h"

namespace KegeratorDisplay {

class GuiView;
class GuiViewTemperatureModel;

class GuiPresenter : public Presenter
{
public:
    GuiPresenter(GuiView& view,
                 GuiViewModel* viewModel,
                 GuiViewTemperatureModel* temperatureModel,
                 TapViewModel* tapViewModel,
                 PressureViewModel* pressureViewModel);
    virtual ~GuiPresenter();

    void updateTemperature(const TemperatureUpdateResponse& response);
    void updateTap(const TapUpdateResponse& response);
    void updatePressure(const PressureUpdateResponse& response);
    void clearTap(const TapClearResponse& response);
    void screenTouched(const ScreenTouchedResponse& response);

private:
    TapViewModel::Tap* getTapViewModelForSide(const TapSide tap);
    void clearTapData(TapViewModel::Tap* tapModel);

    GuiView& m_view;
    GuiViewModel* m_viewModel;
    GuiViewTemperatureModel* m_temperatureModel;
    TapViewModel* m_tapModel;
    PressureViewModel* m_pressureModel;
};

}

#endif
