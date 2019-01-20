#ifndef SRC_TEST_PRESENTER_GUIVIEWMOCK_H_
#define SRC_TEST_PRESENTER_GUIVIEWMOCK_H_

#include <presenter/GuiView.h>
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class GuiViewMock : public GuiView
{
public:
    MOCK_METHOD1(updateView, void(const GuiViewModel&));
    MOCK_METHOD1(updateTemperature, void(const GuiViewTemperatureModel&));
    MOCK_METHOD1(updateTap, void(const TapViewModel& view));
    MOCK_METHOD1(updatePressure, void(const PressureViewModel& view));
    MOCK_METHOD0(run, void(void));
};

}

#endif
