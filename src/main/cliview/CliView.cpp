#include "CliView.h"
#include <iostream>

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
