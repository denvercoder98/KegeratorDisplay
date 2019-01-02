#ifndef SRC_TEST_PRESENTER_GUIPRESENTERTEST_H_
#define SRC_TEST_PRESENTER_GUIPRESENTERTEST_H_

#include "presenter/GuiViewModel.h"
#include "presenter/GuiViewTemperatureModel.h"
#include "presenter/TapViewModel.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class GuiViewMock;
class GuiPresenter;

class GuiPresenterTest : public testing::Test
{
public:
    GuiPresenterTest();
    virtual ~GuiPresenterTest();

protected:
    void SetUp();
    void TearDown();

    GuiViewModel* m_viewModel;
    GuiViewTemperatureModel* m_temperatureModel;
    TapViewModel* m_tapModel;
    GuiViewMock* m_view;
    GuiPresenter* m_presenter;
};

}

#endif
