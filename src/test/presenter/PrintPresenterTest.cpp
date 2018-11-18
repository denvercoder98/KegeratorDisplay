#include "PrintPresenterTest.h"
#include "PrintViewMock.h"
#include "src/main/presenter/PrintPresenter.h"
#include "src/main/presenter/PrintViewModel.h"

using ::testing::NiceMock;
using ::testing::_;

PrintPresenterTest::PrintPresenterTest()
{
}

PrintPresenterTest::~PrintPresenterTest()
{
}

TEST_F(PrintPresenterTest, Create)
{
    PrintViewModel viewModel;
    NiceMock<PrintViewMock> printView;
    PrintPresenter presenter(&printView, &viewModel);
}

TEST_F(PrintPresenterTest, UpdateTemperatureValue)
{
    PrintViewModel viewModel;
    NiceMock<PrintViewMock> printView;
    PrintPresenter presenter(&printView, &viewModel);
    TemperatureUpdate temperatureUpdate(11);
    presenter.update(temperatureUpdate);

    EXPECT_EQ("Temperature is: 11", viewModel.getTemperature());
}

TEST_F(PrintPresenterTest, UpdateTemperaturePrintView)
{
    PrintViewModel viewModel;
    NiceMock<PrintViewMock> printView;
    PrintPresenter presenter(&printView, &viewModel);
    TemperatureUpdate temperatureUpdate(11);

    EXPECT_CALL(printView, updateView(_))
        .Times(1);
    presenter.update(temperatureUpdate);
}
