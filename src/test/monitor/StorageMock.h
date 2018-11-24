#ifndef SRC_TEST_MONITOR_STORAGEMOCK_H
#define SRC_TEST_MONITOR_STORAGEMOCK_H

#include "monitor/Storage.h"
#include "gmock/gmock.h"

namespace KegeratorDisplay {

class StorageMock : public Storage
{
public:
    MOCK_METHOD0(readTemperature, Temperature*(void));
    MOCK_METHOD0(readTap, Tap*(void));
};

}

#endif
