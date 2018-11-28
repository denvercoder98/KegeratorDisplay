#ifndef SRC_TEST_INTERACTORS_TEMPERATUREREADINGOBSERVERMOCK_H_
#define SRC_TEST_INTERACTORS_TEMPERATUREREADINGOBSERVERMOCK_H_

#include <interactors/TemperatureUpdateRequestObserver.h>

#include "gmock/gmock.h"

namespace KegeratorDisplay {

class TemperatureReadingObserverMock : public TemperatureUpdateRequestObserver
{
public:
    MOCK_METHOD1(receiveTemperatureReading, void(const TemperatureUpdateRequest& reading));

};

}

#endif
