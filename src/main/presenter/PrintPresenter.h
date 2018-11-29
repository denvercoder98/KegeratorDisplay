#ifndef SRC_MAIN_PRESENTER_PRINTPRESENTER_H
#define SRC_MAIN_PRESENTER_PRINTPRESENTER_H

#include "interactors/Presenter.h"
#include "interactors/TapSide.h"

namespace KegeratorDisplay {

class PrintView;
class PrintViewModel;

class PrintPresenter : public Presenter
{
public:
    PrintPresenter(PrintView* view, PrintViewModel* viewModel);
    virtual ~PrintPresenter();

    void updateTemperature(const TemperatureUpdateResponse& temperature);
    void updateTap(const TapUpdateResponse& tap);
    void clearTap(const TapClearResponse& tap) {};

private:
    void formatTapHeader(std::stringstream& ss, const TapSide beer);
    void formatTapInformation(std::stringstream& ss, const BeerUpdateResponse& beer);
    void setTapInformation(const TapUpdateResponse& tap, const std::stringstream& ss);
    void updateViewModel();

    PrintView* m_view;
    PrintViewModel* m_viewModel;
};

}

#endif
