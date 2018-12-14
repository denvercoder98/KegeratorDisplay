#include "UserInputControllerImplTest.h"

#include <controller/UserInputControllerImpl.h>

#include "unit/thread/ApplicationThreadFake.h"
#include "unit/interactors/TapClearRequestObserverMock.h"
#include "unit/interactors/ScreenTouchedRequestObserverMock.h"

using ::testing::NiceMock;

namespace KegeratorDisplay {

UserInputControllerImplTest::UserInputControllerImplTest() :
    m_thread(NULL),
    m_clearObserver(NULL),
    m_screenTouchedObserver(NULL)
{
}

UserInputControllerImplTest::~UserInputControllerImplTest()
{
}

void UserInputControllerImplTest::SetUp()
{
    m_thread = new ApplicationThreadFake();
    m_clearObserver = new NiceMock<TapClearRequestObserverMock>();
    m_screenTouchedObserver = new NiceMock<ScreenTouchedRequestObserverMock>();
}

void UserInputControllerImplTest::TearDown()
{
    delete m_screenTouchedObserver;
    delete m_clearObserver;
    delete m_thread;
}

TEST_F(UserInputControllerImplTest, Create)
{
    UserInputControllerImpl controller(*m_thread, *m_clearObserver, *m_screenTouchedObserver);
}

TEST_F(UserInputControllerImplTest, ClearLeftTapButtonInvokesInteractor)
{
    UserInputControllerImpl controller(*m_thread, *m_clearObserver, *m_screenTouchedObserver);
    TapClearRequest expectedRequest(TAP_LEFT);
    EXPECT_CALL(*m_clearObserver, handleRequest(expectedRequest))
        .Times(1);
    controller.clearTap("left");
}

TEST_F(UserInputControllerImplTest, ClearRightTapButtonInvokesInteractor)
{
    UserInputControllerImpl controller(*m_thread, *m_clearObserver, *m_screenTouchedObserver);
    TapClearRequest expectedRequest(TAP_RIGHT);
    EXPECT_CALL(*m_clearObserver, handleRequest(expectedRequest))
        .Times(1);
    controller.clearTap("right");
}

TEST_F(UserInputControllerImplTest, ScreenTapInvokesInteractor)
{
    UserInputControllerImpl controller(*m_thread, *m_clearObserver, *m_screenTouchedObserver);
    ScreenTouchedRequest expectedRequest;
    EXPECT_CALL(*m_screenTouchedObserver, handleRequest(expectedRequest))
        .Times(1);
    controller.screenTouched();
}

}
