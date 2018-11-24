#ifndef SRC_TEST_MONITOR_TAPUPDATORTEST_H_
#define SRC_TEST_MONITOR_TAPUPDATORTEST_H_

#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace KegeratorDisplay {

class KegeratorObserverMock;
class StorageMock;

class TapUpdatorTest : public ::testing::Test
{
public:
    TapUpdatorTest();
    virtual ~TapUpdatorTest();

protected:
    void SetUp();
    void TearDown();
    void prepareBeers();

    KegeratorObserverMock* m_observer;
    StorageMock* m_storage;
};

}

#endif
