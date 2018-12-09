#ifndef SRC_TEST_CONTROLLER_USERINPUTCONTROLLERIMPLTEST_H_
#define SRC_TEST_CONTROLLER_USERINPUTCONTROLLERIMPLTEST_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class TapClearRequestObserverMock;
class ScreenTouchedRequestObserverMock;

class UserInputControllerImplTest : public testing::Test
{
public:
    UserInputControllerImplTest();
    virtual ~UserInputControllerImplTest();

protected:
    void SetUp();
    void TearDown();

    TapClearRequestObserverMock* m_clearObserver;
    ScreenTouchedRequestObserverMock* m_screenTouchedObserver;
};

}

#endif
