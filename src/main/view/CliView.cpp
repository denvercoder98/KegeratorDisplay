#include "CliView.h"
#include <iostream>

namespace KegeratorDisplay {

CliView::CliView()
{
}

CliView::~CliView()
{
}

void CliView::updateView(const PrintViewModel& viewModel)
{
	std::cout << viewModel.getTemperature() << std::endl;
}

}
