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

void PrintPresenter::updateTemperature(const TemperatureUpdate& temperature)
{
    int value = temperature.value();
    std::stringstream ss;
    ss << "Temperature is: ";
    ss << value;
    m_viewModel->setTemperature(ss.str());
    PrintViewModel view(*m_viewModel);
    m_view->updateView(view);
}

void PrintPresenter::updateTap(const TapUpdate& tap)
{
    BeerUpdate beer = tap.beer();

    if (tap.side() == TAP_LEFT) {
        std::stringstream ss;
        ss << "Left tap beer name: " << beer.name();
        m_viewModel->setLeftTapName(ss.str());
        ss.str(std::string());
        ss.clear();
        ss << "Left tap brewer name: " << beer.brewerName();
        m_viewModel->setLeftTapBrewerName(beer.brewerName());
    }
    else {
        std::stringstream ss;
        ss << "Right tap beer name: " << beer.name();
        m_viewModel->setRightTapName(ss.str());
        ss.str(std::string());
        ss.clear();
        ss << "Right tap brewer name: " << beer.brewerName();
        m_viewModel->setRightTapBrewerName(beer.brewerName());    }
    PrintViewModel view(*m_viewModel);
    m_view->updateView(view);
}

}
