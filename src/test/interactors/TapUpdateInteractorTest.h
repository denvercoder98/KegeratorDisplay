#ifndef SRC_TEST_INTERACTORS_TAPUPDATEINTERACTORTEST_H_
#define SRC_TEST_INTERACTORS_TAPUPDATEINTERACTORTEST_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class PresenterMock;
class StorageMock;

class TapUpdateInteractorTest : public ::testing::Test
{
public:
    TapUpdateInteractorTest();
    virtual ~TapUpdateInteractorTest();

protected:
    void SetUp();
    void TearDown();
    void prepareBeers();

    PresenterMock* m_observer;
    StorageMock* m_storage;
};

}

#endif
