#include "GuiPresenterTest.h"

#include <interactors/BeerUpdateResponse.h>

#include "GuiViewMock.h"
#include "presenter/GuiPresenter.h"

using testing::NiceMock;
using testing::_;
using testing::SaveArg;

namespace KegeratorDisplay {

GuiPresenterTest::GuiPresenterTest() :
    m_viewModel(NULL),
    m_view(NULL),
    m_presenter(NULL)
{
}

GuiPresenterTest::~GuiPresenterTest()
{
}

void GuiPresenterTest::SetUp()
{
    m_viewModel = new GuiViewModel();
    m_view = new NiceMock<GuiViewMock>();
    m_presenter = new GuiPresenter(m_view, m_viewModel);
}

void GuiPresenterTest::TearDown()
{
    delete m_presenter;
    delete m_view;
}

TEST_F(GuiPresenterTest, Create)
{
}

TEST_F(GuiPresenterTest, UpdateTemperatureUpdatesViewModel)
{
    EXPECT_CALL(*m_view, updateView(_))
        .Times(1);
    m_presenter->updateTemperature(TemperatureUpdateResponse(11));
}


TEST_F(GuiPresenterTest, UpdateTemperatureUpdatesViewModelValue)
{
    GuiViewModel viewModel;
    ON_CALL(*m_view, updateView(_))
        .WillByDefault( SaveArg<0>(&viewModel) );
    m_presenter->updateTemperature(TemperatureUpdateResponse(11));

    EXPECT_EQ("11", viewModel.temperature);
}

TEST_F(GuiPresenterTest, UpdateTapUpdatesViewModel)
{
    EXPECT_CALL(*m_view, updateView(_))
        .Times(1);
    BeerUpdateResponse beerUpdate("A",
                          "B",
                          "4,1", 30,
                          "2018-01-01",
                          "2018-01-14",
                          "1.010");
    TapUpdateResponse tapUpdate(TAP_LEFT, beerUpdate);
    m_presenter->updateTap(tapUpdate);
}

TEST_F(GuiPresenterTest, UpdateTapLeftUpdatesViewModelValue)
{
    GuiViewModel expectedViewModel;
    expectedViewModel.leftTapBeerName = "A";
    expectedViewModel.leftTapBrewerName = "B";
    expectedViewModel.leftTapAbv = "4,1";
    expectedViewModel.leftTapIbu = "30";
    expectedViewModel.leftTapBrewDate = "2018-01-01";
    expectedViewModel.leftTapTapDate = "2018-01-14";
    expectedViewModel.leftTapFg = "1.010";

    GuiViewModel viewModel;
    ON_CALL(*m_view, updateView(_))
        .WillByDefault( SaveArg<0>(&viewModel) );

    BeerUpdateResponse beerUpdate("A",
                          "B",
                          "4,1", 30,
                          "2018-01-01",
                          "2018-01-14",
                          "1.010");
    TapUpdateResponse tapUpdate(TAP_LEFT, beerUpdate);
    m_presenter->updateTap(tapUpdate);

    EXPECT_EQ(expectedViewModel, viewModel);
}

TEST_F(GuiPresenterTest, UpdateTapRightUpdatesViewModelValue)
{
    GuiViewModel expectedViewModel;
    expectedViewModel.rightTapBeerName = "A";
    expectedViewModel.rightTapBrewerName = "B";
    expectedViewModel.rightTapAbv = "4,1";
    expectedViewModel.rightTapIbu = "30";
    expectedViewModel.rightTapBrewDate = "2018-01-01";
    expectedViewModel.rightTapTapDate = "2018-01-14";
    expectedViewModel.rightTapFg = "1.010";

    GuiViewModel viewModel;
    ON_CALL(*m_view, updateView(_))
        .WillByDefault( SaveArg<0>(&viewModel) );

    BeerUpdateResponse beerUpdate("A",
                          "B",
                          "4,1", 30,
                          "2018-01-01",
                          "2018-01-14",
                          "1.010");
    TapUpdateResponse tapUpdate(TAP_RIGHT, beerUpdate);
    m_presenter->updateTap(tapUpdate);

    EXPECT_EQ(expectedViewModel, viewModel);
}

TEST_F(GuiPresenterTest, ClearLeftTapClearsViewModel)
{
    m_viewModel->leftTapBeerName = "A";
    m_viewModel->leftTapBrewerName = "B";
    m_viewModel->leftTapAbv = "4,1";
    m_viewModel->leftTapIbu = "30";
    m_viewModel->leftTapBrewDate = "2018-01-01";
    m_viewModel->leftTapTapDate = "2018-01-14";
    m_viewModel->leftTapFg = "1.010";

    m_viewModel->rightTapAbv = "5,0";

    GuiViewModel expectedViewModel;
    expectedViewModel.rightTapAbv = "5,0";
    EXPECT_CALL(*m_view, updateView(expectedViewModel))
        .Times(1);
    m_presenter->clearTap(TapClearResponse(TAP_LEFT));
}

TEST_F(GuiPresenterTest, ClearRightTapClearsViewModel)
{
    m_viewModel->rightTapBeerName = "A";
    m_viewModel->rightTapBrewerName = "B";
    m_viewModel->rightTapAbv = "4,1";
    m_viewModel->rightTapIbu = "30";
    m_viewModel->rightTapBrewDate = "2018-01-01";
    m_viewModel->rightTapTapDate = "2018-01-14";
    m_viewModel->rightTapFg = "1.010";

    m_viewModel->leftTapAbv = "5,0";

    GuiViewModel expectedViewModel;
    expectedViewModel.leftTapAbv = "5,0";
    EXPECT_CALL(*m_view, updateView(expectedViewModel))
        .Times(1);
    m_presenter->clearTap(TapClearResponse(TAP_RIGHT));
}

}
