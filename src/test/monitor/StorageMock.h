#ifndef SRC_TEST_MONITOR_STORAGEMOCK_H
#define SRC_TEST_MONITOR_STORAGEMOCK_H

#include "monitor/Storage.h"
#include "gmock/gmock.h"

namespace KegeratorDisplay {

class StorageMock : public Storage
{
public:
    MOCK_METHOD0(readTemperature, Temperature*(void));
    MOCK_METHOD1(writeTemperature, void(Temperature*));
    MOCK_METHOD0(readLeftTap, Tap*(void));
    MOCK_METHOD1(writeLeftTap, void(Tap*));
    MOCK_METHOD0(readRightTap, Tap*(void));
    MOCK_METHOD1(writeRightTap, void(Tap*));
};

}

#endif
