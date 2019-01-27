#include "QmlButtonHandlerTest.h"
#include "devices/QmlButtonHandler.h"
#include "controllers/DeviceTapData.h"

#include "unit/controllers/UserInputControllerMock.h"

using testing::NiceMock;
using testing::_;

namespace KegeratorDisplay {

QmlButtonHandlerTest::QmlButtonHandlerTest() :
    m_leftTap(),
    m_rightTap()
{
}

QmlButtonHandlerTest::~QmlButtonHandlerTest()
{
}

TEST_F(QmlButtonHandlerTest, Create)
{
    NiceMock<UserInputControllerMock> controller;
    QmlButtonHandler handler(controller, m_leftTap, m_rightTap);
}

TEST_F(QmlButtonHandlerTest, ClearLeftButton)
{
    NiceMock<UserInputControllerMock> controller;
    QmlButtonHandler handler(controller, m_leftTap, m_rightTap);

    EXPECT_CALL(controller, clearTap("left"))
        .Times(1);
    handler.clearTap("left");
}

TEST_F(QmlButtonHandlerTest, ClearRightButton)
{
    NiceMock<UserInputControllerMock> controller;
    QmlButtonHandler handler(controller, m_leftTap, m_rightTap);

    EXPECT_CALL(controller, clearTap("right"))
        .Times(1);
    handler.clearTap("right");
}

TEST_F(QmlButtonHandlerTest, ScreenTouched)
{
    NiceMock<UserInputControllerMock> controller;
    QmlButtonHandler handler(controller, m_leftTap, m_rightTap);

    EXPECT_CALL(controller, screenTouched())
        .Times(1);
    handler.screenTouched();
}

TEST_F(QmlButtonHandlerTest, CanCallSaveLeftTap)
{
    NiceMock<UserInputControllerMock> controller;
    QmlButtonHandler handler(controller, m_leftTap, m_rightTap);
    handler.saveTap("left");
}

TEST_F(QmlButtonHandlerTest, SaveLeftTapCallsController)
{
    NiceMock<UserInputControllerMock> controller;
    QmlButtonHandler handler(controller, m_leftTap, m_rightTap);
    EXPECT_CALL(controller, saveTap("left", _))
        .Times(1);
    handler.saveTap("left");
}

TEST_F(QmlButtonHandlerTest, SaveLeftTapCallsControllerWithTapData)
{
    NiceMock<UserInputControllerMock> controller;
    QmlButtonHandler handler(controller, m_leftTap, m_rightTap);
    m_leftTap.setFinalGravity("1.010");
    DeviceTapData tapData("", "", "", "", "", "", "", "1.010");
    EXPECT_CALL(controller, saveTap("left", tapData))
        .Times(1);
    handler.saveTap("left");
}

TEST_F(QmlButtonHandlerTest, SaveRightTapCallsControllerWithTapData)
{
    NiceMock<UserInputControllerMock> controller;
    QmlButtonHandler handler(controller, m_leftTap, m_rightTap);
    m_rightTap.setName("abc");
    m_rightTap.setFinalGravity("1.016");
    DeviceTapData tapData("abc", "", "", "", "", "", "", "1.016");
    EXPECT_CALL(controller, saveTap("right", tapData))
        .Times(1);
    handler.saveTap("right");
}

TEST_F(QmlButtonHandlerTest, SaveInvalidTapSideisIgnored)
{
    NiceMock<UserInputControllerMock> controller;
    QmlButtonHandler handler(controller, m_leftTap, m_rightTap);
    EXPECT_CALL(controller, saveTap(_ , _))
        .Times(0);
    handler.saveTap("invalid");
}

}
