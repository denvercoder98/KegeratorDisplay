#ifndef SRC_TEST_MONITOR_TEMPERATUREREADINGOBSERVERMOCK_H_
#define SRC_TEST_MONITOR_TEMPERATUREREADINGOBSERVERMOCK_H_

#include "monitor/TemperatureReadingObserver.h"
#include "gmock/gmock.h"

namespace KegeratorDisplay {

class TemperatureReadingObserverMock : public TemperatureReadingObserver
{
public:
    MOCK_METHOD1(receiveTemperatureReading, void(const TemperatureReading& reading));

};

}

#endif
