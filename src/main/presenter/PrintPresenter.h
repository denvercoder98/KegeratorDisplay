#ifndef SRC_MAIN_PRESENTER_PRINTPRESENTER_H
#define SRC_MAIN_PRESENTER_PRINTPRESENTER_H

#include "monitor/KegeratorObserver.h"

namespace KegeratorDisplay {

class PrintView;
class PrintViewModel;

class PrintPresenter : public KegeratorObserver
{
public:
    PrintPresenter(PrintView* view, PrintViewModel* viewModel);
    virtual ~PrintPresenter();

    virtual void updateTemperature(const TemperatureUpdate& temperature);
    virtual void updateTap(const TapUpdate& tap);

private:
    void formatTapHeader(std::stringstream& ss, const TapSide beer);
    void formatTapInformation(std::stringstream& ss, const BeerUpdate& beer);
    void setTapInformation(const TapUpdate& tap, const std::stringstream& ss);
    void updateViewModel();

    PrintView* m_view;
    PrintViewModel* m_viewModel;
};

}

#endif
