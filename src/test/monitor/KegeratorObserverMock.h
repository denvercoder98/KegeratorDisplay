#ifndef SRC_TEST_MONITOR_KEGERATOROBSERVERMOCK_H
#define SRC_TEST_MONITOR_KEGERATOROBSERVERMOCK_H

#include "src/main/monitor/KegeratorObserver.h"
#include "gmock/gmock.h"

class KegeratorObserverMock : public KegeratorObserver
{
public:
    MOCK_METHOD1(update, void(const TemperatureUpdate& update));
};

#endif
