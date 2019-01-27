#include "UserInputControllerImplTest.h"

#include "controllers/UserInputControllerImpl.h"

#include "unit/thread/ApplicationThreadFake.h"
#include "unit/interactors/TapClearRequestObserverMock.h"
#include "unit/interactors/ScreenTouchedRequestObserverMock.h"
#include "unit/interactors/TapUpdateRequestObserverMock.h"

using ::testing::NiceMock;

namespace KegeratorDisplay {

UserInputControllerImplTest::UserInputControllerImplTest() :
    m_thread(NULL),
    m_clearObserver(NULL),
    m_screenTouchedObserver(NULL),
    m_updateObserver(NULL)
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
    m_updateObserver = new NiceMock<TapUpdateRequestObserverMock>();
}

void UserInputControllerImplTest::TearDown()
{
    delete m_updateObserver;
    delete m_screenTouchedObserver;
    delete m_clearObserver;
    delete m_thread;
}

TEST_F(UserInputControllerImplTest, Create)
{
    UserInputControllerImpl controller(*m_thread, *m_clearObserver, *m_screenTouchedObserver, *m_updateObserver);
}

TEST_F(UserInputControllerImplTest, ClearLeftTapButtonInvokesInteractor)
{
    UserInputControllerImpl controller(*m_thread, *m_clearObserver, *m_screenTouchedObserver, *m_updateObserver);
    TapClearRequest expectedRequest(TAP_LEFT);
    EXPECT_CALL(*m_clearObserver, handleRequest(expectedRequest))
        .Times(1);
    controller.clearTap("left");
}

TEST_F(UserInputControllerImplTest, ClearRightTapButtonInvokesInteractor)
{
    UserInputControllerImpl controller(*m_thread, *m_clearObserver, *m_screenTouchedObserver, *m_updateObserver);
    TapClearRequest expectedRequest(TAP_RIGHT);
    EXPECT_CALL(*m_clearObserver, handleRequest(expectedRequest))
        .Times(1);
    controller.clearTap("right");
}

TEST_F(UserInputControllerImplTest, ScreenTapInvokesInteractor)
{
    UserInputControllerImpl controller(*m_thread, *m_clearObserver, *m_screenTouchedObserver, *m_updateObserver);
    ScreenTouchedRequest expectedRequest;
    EXPECT_CALL(*m_screenTouchedObserver, handleRequest(expectedRequest))
        .Times(1);
    controller.screenTouched();
}

TEST_F(UserInputControllerImplTest, SaveLeftTapInvokesInteractor)
{
    UserInputControllerImpl controller(*m_thread, *m_clearObserver, *m_screenTouchedObserver, *m_updateObserver);
    TapUpdateRequest expectedRequest(TapSide::TAP_LEFT, "1", "2", "3", "4", "5", "6", "7", "8");
    EXPECT_CALL(*m_updateObserver, updateTap(expectedRequest))
        .Times(1);
    controller.saveTap("left", DeviceTapData("1", "2", "3", "4", "5", "6", "7", "8"));
}

TEST_F(UserInputControllerImplTest, SaveLeftTapPostsWorkOnThread)
{
    UserInputControllerImpl controller(*m_thread, *m_clearObserver, *m_screenTouchedObserver, *m_updateObserver);
    controller.saveTap("left", DeviceTapData("", "", "", "", "", "", "", ""));
    EXPECT_TRUE(m_thread->isPosted());
}

TEST_F(UserInputControllerImplTest, SaveRightTapPostsWorkOnThread)
{
    UserInputControllerImpl controller(*m_thread, *m_clearObserver, *m_screenTouchedObserver, *m_updateObserver);
    controller.saveTap("right", DeviceTapData("", "", "", "", "", "", "", ""));
    EXPECT_TRUE(m_thread->isPosted());
}

}
