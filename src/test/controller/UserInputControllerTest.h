#ifndef SRC_TEST_CONTROLLER_USERINPUTCONTROLLERTEST_H_
#define SRC_TEST_CONTROLLER_USERINPUTCONTROLLERTEST_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class TapClearRequestObserverMock;

class UserInputControllerTest : public testing::Test
{
public:
    UserInputControllerTest();
    virtual ~UserInputControllerTest();

protected:
    void SetUp();
    void TearDown();

    TapClearRequestObserverMock* m_clearObserver;
};

}

#endif
