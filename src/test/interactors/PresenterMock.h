#ifndef SRC_TEST_INTERACTORS_PRESENTERMOCK_H
#define SRC_TEST_INTERACTORS_PRESENTERMOCK_H

#include "interactors/Presenter.h"

#include "gmock/gmock.h"

namespace KegeratorDisplay {

class PresenterMock : public Presenter
{
public:
    MOCK_METHOD1(updateTemperature, void(const TemperatureUpdateResponse& response));
    MOCK_METHOD1(updateTap, void(const TapUpdateResponse& response));
    MOCK_METHOD1(clearTap, void(const TapClearResponse& response));
};

}

#endif
