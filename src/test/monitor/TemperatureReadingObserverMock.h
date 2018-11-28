#ifndef SRC_TEST_MONITOR_TEMPERATUREREADINGOBSERVERMOCK_H_
#define SRC_TEST_MONITOR_TEMPERATUREREADINGOBSERVERMOCK_H_

#include <monitor/TemperatureUpdateRequestObserver.h>

#include "gmock/gmock.h"

namespace KegeratorDisplay {

class TemperatureReadingObserverMock : public TemperatureUpdateRequestObserver
{
public:
    MOCK_METHOD1(receiveTemperatureReading, void(const TemperatureUpdateRequest& reading));

};

}

#endif
