#include "PrintPresenterTest.h"
#include "PrintViewMock.h"
#include "presenter/PrintPresenter.h"
#include "presenter/PrintViewModel.h"

using ::testing::NiceMock;
using ::testing::_;

namespace KegeratorDisplay {

PrintPresenterTest::PrintPresenterTest()
{
}

PrintPresenterTest::~PrintPresenterTest()
{
}

TEST_F(PrintPresenterTest, Create)
{
    PrintViewModel* viewModel = new PrintViewModel();
    NiceMock<PrintViewMock>* printView = new NiceMock<PrintViewMock>();
    PrintPresenter presenter(printView, viewModel);
}

TEST_F(PrintPresenterTest, UpdateTemperatureValue)
{
    PrintViewModel* viewModel = new PrintViewModel();
    NiceMock<PrintViewMock>* printView = new NiceMock<PrintViewMock>();
    PrintPresenter presenter(printView, viewModel);
    TemperatureUpdate temperatureUpdate(11);
    presenter.updateTemperature(temperatureUpdate);

    EXPECT_EQ("Temperature is: 11", viewModel->getTemperature());
}

TEST_F(PrintPresenterTest, UpdateTemperaturePrintView)
{
    PrintViewModel* viewModel = new PrintViewModel();
    NiceMock<PrintViewMock>* printView = new NiceMock<PrintViewMock>();
    PrintPresenter presenter(printView, viewModel);
    TemperatureUpdate temperatureUpdate(11);

    EXPECT_CALL(*printView, updateView(_))
        .Times(1);
    presenter.updateTemperature(temperatureUpdate);
}

TEST_F(PrintPresenterTest, UpdateLeftTapValue)
{
    PrintViewModel* viewModel = new PrintViewModel();
    NiceMock<PrintViewMock>* printView = new NiceMock<PrintViewMock>();
    PrintPresenter presenter(printView, viewModel);
    BeerUpdate beerUpdate("Beer A", "Kalle Karlsson", "1", 1, "1", "1", "1.015");
    TapUpdate tapUpdate(TAP_LEFT, beerUpdate);
    presenter.updateTap(tapUpdate);

    std::string expected = "Left tap:\n\tName: Beer A\n\tBrewer name: Kalle Karlsson\n";
    EXPECT_EQ(expected, viewModel->getLeftTapBeerInfo());
}

TEST_F(PrintPresenterTest, UpdateRightTapValue)
{
    PrintViewModel* viewModel = new PrintViewModel();
    NiceMock<PrintViewMock>* printView = new NiceMock<PrintViewMock>();
    PrintPresenter presenter(printView, viewModel);
    BeerUpdate beerUpdate("Beer B", "Kalle Karlsson", "1", 1, "1", "1", "1.015");
    TapUpdate tapUpdate(TAP_RIGHT, beerUpdate);
    presenter.updateTap(tapUpdate);

    std::string expected = "Right tap:\n\tName: Beer B\n\tBrewer name: Kalle Karlsson\n";
    EXPECT_EQ(expected, viewModel->getRightTapBeerInfo());
}

TEST_F(PrintPresenterTest, UpdateTapPrintView)
{
    PrintViewModel* viewModel = new PrintViewModel();
    NiceMock<PrintViewMock>* printView = new NiceMock<PrintViewMock>();
    PrintPresenter presenter(printView, viewModel);
    BeerUpdate beerUpdate("Beer B", "Kalle Karlsson", "1", 1, "1", "1", "1.015");
    TapUpdate tapUpdate(TAP_RIGHT, beerUpdate);

    EXPECT_CALL(*printView, updateView(_))
        .Times(1);
    presenter.updateTap(tapUpdate);
}

}
