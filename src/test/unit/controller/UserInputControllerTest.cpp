#include "UserInputControllerTest.h"
#include "unit/interactors/TapClearRequestObserverMock.h"
#include "controller/UserInputController.h"
#include "controller/InvalidUserInputControllerArgumentException.h"

using ::testing::NiceMock;

namespace KegeratorDisplay {

UserInputControllerTest::UserInputControllerTest() :
    m_clearObserver(NULL)
{
}

UserInputControllerTest::~UserInputControllerTest()
{
}

void UserInputControllerTest::SetUp()
{
    m_clearObserver = new NiceMock<TapClearRequestObserverMock>();
}

void UserInputControllerTest::TearDown()
{
    delete m_clearObserver;
}

TEST_F(UserInputControllerTest, Create)
{
    UserInputController controller(m_clearObserver);
}

TEST_F(UserInputControllerTest, ThrowsOnMissingClearTapObserver)
{
    EXPECT_THROW(UserInputController(NULL), InvalidUserInputControllerArgumentException);
}

TEST_F(UserInputControllerTest, ClearLeftTapButtonInvokesInteractor)
{
    UserInputController controller(m_clearObserver);
    TapClearRequest expectedRequest(TAP_LEFT);
    EXPECT_CALL(*m_clearObserver, handleRequest(expectedRequest))
        .Times(1);
    controller.clearTap("left");
}

TEST_F(UserInputControllerTest, ClearRightTapButtonInvokesInteractor)
{
    UserInputController controller(m_clearObserver);
    TapClearRequest expectedRequest(TAP_RIGHT);
    EXPECT_CALL(*m_clearObserver, handleRequest(expectedRequest))
        .Times(1);
    controller.clearTap("right");
}

}
