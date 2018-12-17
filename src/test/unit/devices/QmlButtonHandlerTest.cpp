#include "QmlButtonHandlerTest.h"
#include "devices/QmlButtonHandler.h"

#include "unit/controller/UserInputControllerMock.h"

using testing::NiceMock;

namespace KegeratorDisplay {

QmlButtonHandlerTest::QmlButtonHandlerTest()
{
}

QmlButtonHandlerTest::~QmlButtonHandlerTest()
{
}

TEST_F(QmlButtonHandlerTest, Create)
{
    NiceMock<UserInputControllerMock> controller;
    QmlButtonHandler handler(controller);
}

TEST_F(QmlButtonHandlerTest, ClearLeftButton)
{
    NiceMock<UserInputControllerMock> controller;
    QmlButtonHandler handler(controller);

    EXPECT_CALL(controller, clearTap("left"))
        .Times(1);
    handler.clearTap("left");
}

TEST_F(QmlButtonHandlerTest, ClearRightButton)
{
    NiceMock<UserInputControllerMock> controller;
    QmlButtonHandler handler(controller);

    EXPECT_CALL(controller, clearTap("right"))
        .Times(1);
    handler.clearTap("right");
}

TEST_F(QmlButtonHandlerTest, ScreenTouched)
{
    NiceMock<UserInputControllerMock> controller;
    QmlButtonHandler handler(controller);

    EXPECT_CALL(controller, screenTouched())
        .Times(1);
    handler.screenTouched();
}

}
