#include "GuiPresenter.h"
#include "GuiViewModel.h"
#include "GuiView.h"

#include <sstream>

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

void GuiPresenter::updateTemperature(const TemperatureUpdate& temperature)
{
    std::stringstream ss;
    ss << temperature.value();
    m_viewModel->temperature = ss.str();
    m_view->updateView(*m_viewModel);
}

void GuiPresenter::updateTap(const TapUpdate& tap)
{
    std::stringstream ss;
    if (tap.side() == TAP_LEFT) {
        BeerUpdate beer = tap.beer();
        m_viewModel->leftTapBeerName = beer.name();
        m_viewModel->leftTapBrewerName = beer.brewerName();
        m_viewModel->leftTapAbv = beer.abv();
        m_viewModel->leftTapIbu = beer.ibu();
        m_viewModel->leftTapBrewDate = beer.brewDate();
        m_viewModel->leftTapTapDate = beer.tapDate();
        m_viewModel->leftTapFg = beer.finalGravity();
    }
    else if (tap.side() == TAP_RIGHT) {
        BeerUpdate beer = tap.beer();
        m_viewModel->rightTapBeerName = beer.name();
        m_viewModel->rightTapBrewerName = beer.brewerName();
        m_viewModel->rightTapAbv = beer.abv();
        m_viewModel->rightTapIbu = beer.ibu();
        m_viewModel->rightTapBrewDate = beer.brewDate();
        m_viewModel->rightTapTapDate = beer.tapDate();
        m_viewModel->rightTapFg = beer.finalGravity();
    }
    m_view->updateView(*m_viewModel);
}

}
