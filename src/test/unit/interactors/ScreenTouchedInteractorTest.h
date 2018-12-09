#ifndef SRC_TEST_UNIT_INTERACTORS_SCREENTOUCHEDINTERACTORTEST_H_
#define SRC_TEST_UNIT_INTERACTORS_SCREENTOUCHEDINTERACTORTEST_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class DeadlineTimerMock;
class PresenterMock;
class ScreenTouchedInteractor;

class ScreenTouchedInteractorTest : public testing::Test
{
public:
    ScreenTouchedInteractorTest();
    virtual ~ScreenTouchedInteractorTest();

protected:
    DeadlineTimerMock* m_timer;
    PresenterMock* m_presenter;
    ScreenTouchedInteractor* m_interactor;
};

}

#endif
