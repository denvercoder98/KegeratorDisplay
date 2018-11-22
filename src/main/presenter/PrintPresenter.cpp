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

void PrintPresenter::update(const TemperatureUpdate& temperature)
{
    int value = temperature.value();
    std::stringstream ss;
    ss << "Temperature is: ";
    ss << value;
    m_viewModel->setTemperature(ss.str());
    PrintViewModel view(*m_viewModel);
    m_view->updateView(view);
}

}
