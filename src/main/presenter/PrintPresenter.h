#ifndef SRC_MAIN_PRESENTER_PRINTPRESENTER_H
#define SRC_MAIN_PRESENTER_PRINTPRESENTER_H

#include <interactors/Presenter.h>

namespace KegeratorDisplay {

class PrintView;
class PrintViewModel;

class PrintPresenter : public Presenter
{
public:
    PrintPresenter(PrintView* view, PrintViewModel* viewModel);
    virtual ~PrintPresenter();

    virtual void updateTemperature(const TemperatureUpdateResponse& temperature);
    virtual void updateTap(const TapUpdateResponse& tap);

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
