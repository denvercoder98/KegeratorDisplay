#ifndef SRC_TEST_SHARED_MUTEXMOCK_H_
#define SRC_TEST_SHARED_MUTEXMOCK_H_

#include "shared/Mutex.h"
#include "gmock/gmock.h"

namespace KegeratorDisplay {

class MutexMock : public Mutex
{
public:
    MOCK_METHOD0(lock, void(void));
    MOCK_METHOD0(unlock, void(void));
};

}

#endif
