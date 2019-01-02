#include "GuiPresenter.h"
#include "GuiView.h"
#include "GuiViewTemperatureModel.h"

#include <sstream>
#include <string>

namespace KegeratorDisplay {

GuiPresenter::GuiPresenter(GuiView& view, GuiViewModel* viewModel, GuiViewTemperatureModel* temperatureModel) :
    m_view(view),
    m_viewModel(viewModel),
    m_temperatureModel(temperatureModel)
{
    m_viewModel->leftTap.side = "Left tap";
    m_viewModel->rightTap.side = "Right tap";
    m_view.updateView(*m_viewModel);
}

GuiPresenter::~GuiPresenter()
{
    delete m_viewModel;
}

void GuiPresenter::updateTemperature(const TemperatureUpdateResponse& temperature)
{
    std::stringstream ss;
    ss << temperature.value();
    m_temperatureModel->temperature = ss.str();
    m_view.updateTemperature(*m_temperatureModel);
}

void GuiPresenter::updateTap(const TapUpdateResponse& tap)
{
    BeerUpdateResponse beer = tap.beer();
    GuiViewModel::TapViewModel* tapViewModel = getTapViewModelForSide(tap.side());

    if (tap.empty()) {
        clearTapData(tapViewModel);
    }
    else {
        tapViewModel->beerName = beer.name();
        tapViewModel->brewerName = beer.brewerName();
        tapViewModel->abv = beer.abv();
        tapViewModel->ibu = std::to_string(beer.ibu());
        tapViewModel->brewDate = beer.brewDate();
        tapViewModel->tapDate = beer.tapDate();
        tapViewModel->fg = beer.finalGravity();
    }

    m_view.updateView(*m_viewModel);
}

void GuiPresenter::clearTap(const TapClearResponse& tap) {
    GuiViewModel::TapViewModel* tapViewModel = getTapViewModelForSide(tap.side());
    clearTapData(tapViewModel);
    m_view.updateView(*m_viewModel);
}

void GuiPresenter::clearTapData(GuiViewModel::TapViewModel* tapViewModel)
{
    tapViewModel->empty = true;
    tapViewModel->beerName = "";
    tapViewModel->brewerName = "";
    tapViewModel->abv = "";
    tapViewModel->ibu = "";
    tapViewModel->brewDate =  "";
    tapViewModel->tapDate =  "";
    tapViewModel->fg =  "";
}

GuiViewModel::TapViewModel* GuiPresenter::getTapViewModelForSide(const TapSide side)
{
    GuiViewModel::TapViewModel* tapViewModel;
    if (side == TAP_LEFT)
    {
        tapViewModel = &m_viewModel->leftTap;
    } else if (side == TAP_RIGHT)
    {
        tapViewModel = &m_viewModel->rightTap;
    }

    return tapViewModel;
}

void GuiPresenter::screenTouched(const ScreenTouchedResponse& response)
{
    m_viewModel->buttonsVisible = response.buttonsEnabled();
    //m_viewModel->leftTap.beerName = "kiss-juice123";
    m_view.updateView(*m_viewModel);
}

}
