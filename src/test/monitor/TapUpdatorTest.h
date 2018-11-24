#ifndef SRC_TEST_MONITOR_TAPUPDATORTEST_H_
#define SRC_TEST_MONITOR_TAPUPDATORTEST_H_

#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace KegeratorDisplay {

class TapUpdator;
class StorageMock;

class TapUpdatorTest : public ::testing::Test
{
public:
    TapUpdatorTest();
    virtual ~TapUpdatorTest();

protected:
    void SetUp();
    void TearDown();

    StorageMock* m_storage;
    TapUpdator* m_tapUpdator;
};

}

#endif
