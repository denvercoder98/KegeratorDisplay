#include "PrintPresenter.h"
#include "PrintView.h"
#include "PrintViewModel.h"

#include <sstream>

namespace KegeratorDisplay {

PrintPresenter::PrintPresenter(PrintView* view, PrintViewModel* viewModel) :
    m_view(view),
    m_viewModel(viewModel)
{
}

PrintPresenter::~PrintPresenter()
{
    delete m_view;
    delete m_viewModel;
}

void PrintPresenter::updateTemperature(const TemperatureUpdateResponse& temperature)
{
    int value = temperature.value();
    std::stringstream ss;
    ss << "Temperature is: ";
    ss << value;
    m_viewModel->setTemperature(ss.str());
    updateViewModel();
}

void PrintPresenter::setTapInformation(const TapUpdateResponse& tap,
                                       const std::stringstream& ss)
{
    if (tap.side() == TAP_LEFT)
    {
        m_viewModel->setLeftTapBeerInfo(ss.str());
    } else
    {
        m_viewModel->setRightTapBeerInfo(ss.str());
    }
}

void PrintPresenter::updateTap(const TapUpdateResponse& tap)
{
    BeerUpdateResponse beer = tap.beer();

    std::stringstream ss;
    formatTapHeader(ss, tap.side());
    formatTapInformation(ss, beer);
    setTapInformation(tap, ss);
    updateViewModel();
}

void PrintPresenter::formatTapHeader(std::stringstream& ss, const TapSide side)
{
    if (side == TAP_LEFT) {
        ss << "Left tap:" << std::endl;
    }
    else if(side == TAP_RIGHT) {
        ss << "Right tap:" << std::endl;
    }
}

void PrintPresenter::formatTapInformation(std::stringstream& ss, const BeerUpdateResponse& beer)
{
    ss << "\tName: " << beer.name() << std::endl;
    ss << "\tBrewer name: " << beer.brewerName() << std::endl;
}

void PrintPresenter::updateViewModel()
{
    PrintViewModel view(*m_viewModel);
    m_view->updateView(view);
}

}
