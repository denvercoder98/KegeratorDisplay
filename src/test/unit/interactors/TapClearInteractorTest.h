#ifndef SRC_TEST_INTERACTORS_TAPCLEARINTERACTORTEST_H_
#define SRC_TEST_INTERACTORS_TAPCLEARINTERACTORTEST_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class PresenterMock;
class StorageMock;
class TapClearInteractor;

class TapClearInteractorTest: public testing::Test
{
public:
    TapClearInteractorTest();
    virtual ~TapClearInteractorTest();

protected:
    void SetUp();
    void TearDown();

    PresenterMock* m_presenter;
    StorageMock* m_storage;
    TapClearInteractor* m_interactor;
};

}

#endif
