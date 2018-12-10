#include "UserInputControllerImplTest.h"

#include <controller/UserInputControllerImpl.h>

#include "unit/interactors/TapClearRequestObserverMock.h"
#include "unit/interactors/ScreenTouchedRequestObserverMock.h"

using ::testing::NiceMock;

namespace KegeratorDisplay {

UserInputControllerImplTest::UserInputControllerImplTest() :
    m_clearObserver(NULL),
    m_screenTouchedObserver(NULL)
{
}

UserInputControllerImplTest::~UserInputControllerImplTest()
{
}

void UserInputControllerImplTest::SetUp()
{
    m_clearObserver = new NiceMock<TapClearRequestObserverMock>();
    m_screenTouchedObserver = new NiceMock<ScreenTouchedRequestObserverMock>();
}

void UserInputControllerImplTest::TearDown()
{
    delete m_clearObserver;
    delete m_screenTouchedObserver;
}

TEST_F(UserInputControllerImplTest, Create)
{
    UserInputControllerImpl controller(*m_clearObserver, *m_screenTouchedObserver);
}

TEST_F(UserInputControllerImplTest, ClearLeftTapButtonInvokesInteractor)
{
    UserInputControllerImpl controller(*m_clearObserver, *m_screenTouchedObserver);
    TapClearRequest expectedRequest(TAP_LEFT);
    EXPECT_CALL(*m_clearObserver, handleRequest(expectedRequest))
        .Times(1);
    controller.clearTap("left");
}

TEST_F(UserInputControllerImplTest, ClearRightTapButtonInvokesInteractor)
{
    UserInputControllerImpl controller(*m_clearObserver, *m_screenTouchedObserver);
    TapClearRequest expectedRequest(TAP_RIGHT);
    EXPECT_CALL(*m_clearObserver, handleRequest(expectedRequest))
        .Times(1);
    controller.clearTap("right");
}

TEST_F(UserInputControllerImplTest, ScreenTapInvokesInteractor)
{
    UserInputControllerImpl controller(*m_clearObserver, *m_screenTouchedObserver);
    ScreenTouchedRequest expectedRequest;
    EXPECT_CALL(*m_screenTouchedObserver, handleRequest(expectedRequest))
        .Times(1);
    controller.screenTouched();
}

}
