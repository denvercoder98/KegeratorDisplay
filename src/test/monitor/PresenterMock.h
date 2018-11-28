#ifndef SRC_TEST_MONITOR_PRESENTERMOCK_H
#define SRC_TEST_MONITOR_PRESENTERMOCK_H

#include "monitor/Presenter.h"

#include "gmock/gmock.h"

namespace KegeratorDisplay {

class PresenterMock : public Presenter
{
public:
    MOCK_METHOD1(updateTemperature, void(const TemperatureUpdateResponse& update));
    MOCK_METHOD1(updateTap, void(const TapUpdateResponse& update));
};

}

#endif
