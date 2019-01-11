#ifndef SRC_TEST_UNIT_DEVICES_SPIREADERMOCK_H_
#define SRC_TEST_UNIT_DEVICES_SPIREADERMOCK_H_

#include "devices/SpiReader.h"
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class SpiReaderMock : public SpiReader
{
public:
    MOCK_METHOD0(initialize, void(void));
    MOCK_METHOD2(read, void(unsigned char*, unsigned int));
};

}

#endif
