#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <iostream>

#include "view/CliView.h"
#include "monitor/TemperatureInteractor.h"
#include "presenter/PrintPresenter.h"
#include "storage/BlackholeStorage.h"

using namespace KegeratorDisplay;

int main(int argc, char** argv)
{
	PrintView* view = new CliView();
	PrintViewModel* viewModel = new PrintViewModel();
	PrintPresenter* presenter = new PrintPresenter(view, viewModel);

	Storage* storage = new BlackholeStorage();

	TemperatureInteractor* interactor = new TemperatureInteractor(presenter, storage);

    std::cout << "main" << std::endl;

    return 0;
}
