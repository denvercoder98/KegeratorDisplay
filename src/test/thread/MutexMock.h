#ifndef SRC_TEST_THREAD_MUTEXMOCK_H_
#define SRC_TEST_THREAD_MUTEXMOCK_H_

#include <thread/Mutex.h>

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
