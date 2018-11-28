#include "GuiPresenter.h"
#include "GuiViewModel.h"
#include "GuiView.h"

#include <sstream>
#include <string>

namespace KegeratorDisplay {

GuiPresenter::GuiPresenter(GuiView* view, GuiViewModel* viewModel) :
    m_view(view),
    m_viewModel(viewModel)
{
}

GuiPresenter::~GuiPresenter()
{
    delete m_viewModel;
}

void GuiPresenter::updateTemperature(const TemperatureUpdateResponse& temperature)
{
    std::stringstream ss;
    ss << temperature.value();
    m_viewModel->temperature = ss.str();
    m_view->updateView(*m_viewModel);
}

void GuiPresenter::updateTap(const TapUpdateResponse& tap)
{
    BeerUpdateResponse beer = tap.beer();
    if (tap.side() == TAP_LEFT) {
        m_viewModel->leftTapBeerName = beer.name();
        m_viewModel->leftTapBrewerName = beer.brewerName();
        m_viewModel->leftTapAbv = beer.abv();
        m_viewModel->leftTapIbu = std::to_string(beer.ibu());
        m_viewModel->leftTapBrewDate = beer.brewDate();
        m_viewModel->leftTapTapDate = beer.tapDate();
        m_viewModel->leftTapFg = beer.finalGravity();
    }
    else if (tap.side() == TAP_RIGHT) {
        m_viewModel->rightTapBeerName = beer.name();
        m_viewModel->rightTapBrewerName = beer.brewerName();
        m_viewModel->rightTapAbv = beer.abv();
        m_viewModel->rightTapIbu = std::to_string(beer.ibu());
        m_viewModel->rightTapBrewDate = beer.brewDate();
        m_viewModel->rightTapTapDate = beer.tapDate();
        m_viewModel->rightTapFg = beer.finalGravity();
    }
    m_view->updateView(*m_viewModel);
}

}
