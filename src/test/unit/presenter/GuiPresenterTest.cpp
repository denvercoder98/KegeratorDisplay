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
    m_temperatureModel(NULL),
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
    m_temperatureModel = new GuiViewTemperatureModel();
    m_view = new NiceMock<GuiViewMock>();
    m_presenter = new GuiPresenter(*m_view, m_viewModel, m_temperatureModel);
}

void GuiPresenterTest::TearDown()
{
    delete m_presenter;
    delete m_temperatureModel;
    delete m_view;
}

TEST_F(GuiPresenterTest, Create)
{
}

TEST_F(GuiPresenterTest, UpdateTemperatureUpdatesViewModel)
{
    EXPECT_CALL(*m_view, updateTemperature(_))
        .Times(1);
    m_presenter->updateTemperature(TemperatureUpdateResponse(11));
}


TEST_F(GuiPresenterTest, UpdateTemperatureUpdatesViewModelValue)
{
    GuiViewTemperatureModel tempModel;
    ON_CALL(*m_view, updateTemperature(_))
        .WillByDefault( SaveArg<0>(&tempModel) );
    m_presenter->updateTemperature(TemperatureUpdateResponse(11));

    EXPECT_EQ("11", tempModel.temperature);
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
    expectedViewModel.leftTap.side = "Left tap";
    expectedViewModel.leftTap.beerName = "A";
    expectedViewModel.leftTap.brewerName = "B";
    expectedViewModel.leftTap.abv = "4,1";
    expectedViewModel.leftTap.ibu = "30";
    expectedViewModel.leftTap.brewDate = "2018-01-01";
    expectedViewModel.leftTap.tapDate = "2018-01-14";
    expectedViewModel.leftTap.fg = "1.010";
    expectedViewModel.rightTap.side = "Right tap";

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
    expectedViewModel.rightTap.side = "Right tap";
    expectedViewModel.rightTap.beerName = "A";
    expectedViewModel.rightTap.brewerName = "B";
    expectedViewModel.rightTap.abv = "4,1";
    expectedViewModel.rightTap.ibu = "30";
    expectedViewModel.rightTap.brewDate = "2018-01-01";
    expectedViewModel.rightTap.tapDate = "2018-01-14";
    expectedViewModel.rightTap.fg = "1.010";
    expectedViewModel.leftTap.side = "Left tap";

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
    m_viewModel->leftTap.beerName = "A";
    m_viewModel->leftTap.brewerName = "B";
    m_viewModel->leftTap.abv = "4,1";
    m_viewModel->leftTap.ibu = "30";
    m_viewModel->leftTap.brewDate = "2018-01-01";
    m_viewModel->leftTap.tapDate = "2018-01-14";
    m_viewModel->leftTap.fg = "1.010";

    m_viewModel->rightTap.abv = "5,0";

    GuiViewModel expectedViewModel;
    expectedViewModel.leftTap.empty = true;
    expectedViewModel.leftTap.side = "Left tap";

    GuiViewModel receivedViewModel;
    EXPECT_CALL(*m_view, updateView(_))
        .WillOnce(SaveArg<0>(&receivedViewModel));

    m_presenter->clearTap(TapClearResponse(TAP_LEFT));
    EXPECT_EQ(expectedViewModel.leftTap, receivedViewModel.leftTap);
}

TEST_F(GuiPresenterTest, ClearRightTapClearsViewModel)
{
    m_viewModel->rightTap.beerName = "A";
    m_viewModel->rightTap.brewerName = "B";
    m_viewModel->rightTap.abv = "4,1";
    m_viewModel->rightTap.ibu = "30";
    m_viewModel->rightTap.brewDate = "2018-01-01";
    m_viewModel->rightTap.tapDate = "2018-01-14";
    m_viewModel->rightTap.fg = "1.010";

    m_viewModel->leftTap.abv = "5,0";

    GuiViewModel expectedViewModel;
    expectedViewModel.rightTap.empty = true;
    expectedViewModel.rightTap.side = "Right tap";

    GuiViewModel receivedViewModel;
    EXPECT_CALL(*m_view, updateView(_))
        .WillOnce(SaveArg<0>(&receivedViewModel));

    m_presenter->clearTap(TapClearResponse(TAP_RIGHT));
    EXPECT_EQ(expectedViewModel.rightTap, receivedViewModel.rightTap);
}

TEST_F(GuiPresenterTest, EmptyLeftTapClearsViewModel)
{
    m_viewModel->leftTap.empty = false;
    m_viewModel->leftTap.beerName = "A";
    m_viewModel->leftTap.brewerName = "B";
    m_viewModel->leftTap.abv = "4,1";
    m_viewModel->leftTap.ibu = "30";
    m_viewModel->leftTap.brewDate = "2018-01-01";
    m_viewModel->leftTap.tapDate = "2018-01-14";
    m_viewModel->leftTap.fg = "1.010";

    m_viewModel->rightTap.abv = "5,0";

    GuiViewModel expectedViewModel;
    expectedViewModel.leftTap.side = "Left tap";
    expectedViewModel.leftTap.empty = true;
    expectedViewModel.rightTap.abv = "5,0";
    expectedViewModel.rightTap.side = "Right tap";
    EXPECT_CALL(*m_view, updateView(expectedViewModel))
        .Times(1);

    BeerUpdateResponse emptyBeerUpdate("",
                          "",
                          "0,0", 0,
                          "1970-01-01",
                          "1970-01-01",
                          "0.000");
    TapUpdateResponse tapUpdate(TAP_LEFT, emptyBeerUpdate, true);
    m_presenter->updateTap(tapUpdate);
}


TEST_F(GuiPresenterTest, EmptyRightTapClearsViewModel)
{
    m_viewModel->rightTap.empty = false;
    m_viewModel->rightTap.beerName = "A";
    m_viewModel->rightTap.brewerName = "B";
    m_viewModel->rightTap.abv = "4,1";
    m_viewModel->rightTap.ibu = "30";
    m_viewModel->rightTap.brewDate = "2018-01-01";
    m_viewModel->rightTap.tapDate = "2018-01-14";
    m_viewModel->rightTap.fg = "1.010";

    m_viewModel->leftTap.abv = "5,0";

    GuiViewModel expectedViewModel;
    expectedViewModel.rightTap.side = "Right tap";
    expectedViewModel.rightTap.empty = true;
    expectedViewModel.leftTap.abv = "5,0";
    expectedViewModel.leftTap.side = "Left tap";
    EXPECT_CALL(*m_view, updateView(expectedViewModel))
        .Times(1);

    BeerUpdateResponse emptyBeerUpdate("",
                          "",
                          "0,0", 0,
                          "1970-01-01",
                          "1970-01-01",
                          "0.000");
    TapUpdateResponse tapUpdate(TAP_RIGHT, emptyBeerUpdate, true);
    m_presenter->updateTap(tapUpdate);
}

TEST_F(GuiPresenterTest, ScreenTouchedUpdatesViewModel)
{
    ScreenTouchedResponse response(true);

    GuiViewModel viewModel;
    EXPECT_CALL(*m_view, updateView(_))
        .WillOnce(SaveArg<0>(&viewModel));
    m_presenter->screenTouched(response);
    EXPECT_TRUE(viewModel.buttonsVisible);
}

TEST_F(GuiPresenterTest, ViewUpdatedWhenPresenterCreated)
{
    GuiViewModel* viewModel = new GuiViewModel();
    GuiViewTemperatureModel* tempModel = new GuiViewTemperatureModel();
    NiceMock<GuiViewMock> view;
    EXPECT_CALL(view, updateView(_))
        .Times(1);
    GuiPresenter presenter(view, viewModel, tempModel);
}

TEST_F(GuiPresenterTest, TagNamesSetWhenPresenterCreated)
{
    GuiViewModel* viewModel = new GuiViewModel();
    GuiViewTemperatureModel* tempModel = new GuiViewTemperatureModel();
    NiceMock<GuiViewMock> view;

    GuiViewModel receivedViewModel;
    EXPECT_CALL(view, updateView(_))
        .WillOnce(SaveArg<0>(&receivedViewModel));

    GuiPresenter presenter(view, viewModel, tempModel);
    EXPECT_EQ("Name: ", receivedViewModel.beerNameTag);
    EXPECT_EQ("Brewer Name: ", receivedViewModel.brewerNameTag);
    EXPECT_EQ("ABV: ", receivedViewModel.abvTag);
    EXPECT_EQ("IBU: ", receivedViewModel.ibuTag);
    EXPECT_EQ("Brew Date: ", receivedViewModel.brewDateTag);
    EXPECT_EQ("Tap Date: ", receivedViewModel.tapDateTag);
    EXPECT_EQ("FG: ", receivedViewModel.fgTag);
}

TEST_F(GuiPresenterTest, HeadingSetWhenPresenterCreated)
{
    GuiViewModel* viewModel = new GuiViewModel();
    GuiViewTemperatureModel* tempModel = new GuiViewTemperatureModel();
    NiceMock<GuiViewMock> view;

    GuiViewModel receivedViewModel;
    EXPECT_CALL(view, updateView(_))
        .WillOnce(SaveArg<0>(&receivedViewModel));

    GuiPresenter presenter(view, viewModel, tempModel);
    EXPECT_EQ("Kegerator Status", receivedViewModel.heading);
}

TEST_F(GuiPresenterTest, ClearButtonTagSetWhenPresenterCreated)
{
    GuiViewModel* viewModel = new GuiViewModel();
    GuiViewTemperatureModel* tempModel = new GuiViewTemperatureModel();
    NiceMock<GuiViewMock> view;

    GuiViewModel receivedViewModel;
    EXPECT_CALL(view, updateView(_))
        .WillOnce(SaveArg<0>(&receivedViewModel));

    GuiPresenter presenter(view, viewModel, tempModel);
    EXPECT_EQ("Clear", receivedViewModel.clearButtonTag);
}

TEST_F(GuiPresenterTest, SaveButtonTagSetWhenPresenterCreated)
{
    GuiViewModel* viewModel = new GuiViewModel();
    GuiViewTemperatureModel* tempModel = new GuiViewTemperatureModel();
    NiceMock<GuiViewMock> view;

    GuiViewModel receivedViewModel;
    EXPECT_CALL(view, updateView(_))
        .WillOnce(SaveArg<0>(&receivedViewModel));

    GuiPresenter presenter(view, viewModel, tempModel);
    EXPECT_EQ("Save", receivedViewModel.saveButtonTag);
}

}
