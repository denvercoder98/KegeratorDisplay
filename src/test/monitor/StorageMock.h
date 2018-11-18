#ifndef SRC_TEST_MONITOR_STORAGEMOCK_H
#define SRC_TEST_MONITOR_STORAGEMOCK_H

#include "src/main/monitor/Storage.h"
#include "gmock/gmock.h"

class StorageMock : public Storage
{
public:
    MOCK_METHOD0(readTemperature, Temperature*(void));
};

#endif
