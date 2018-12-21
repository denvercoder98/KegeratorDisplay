#include "QmlButtonHandlerTest.h"
#include "devices/QmlButtonHandler.h"

#include "unit/controller/UserInputControllerMock.h"

using testing::NiceMock;

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
    EXPECT_CALL(controller, saveTap("left"))
        .Times(1);
    handler.saveTap("left");
}

}
