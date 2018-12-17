#include "QmlInputDeviceTest.h"
#include "QmlContextPropertyRegistratorMock.h"
#include "devices/QmlInputDevice.h"
#include "unit/controller/UserInputControllerMock.h"

#include <QtWidgets/qapplication.h>

using testing::NiceMock;
using testing::SaveArg;
using testing::_;

namespace KegeratorDisplay {

QmlInputDeviceTest::QmlInputDeviceTest()
{
}

QmlInputDeviceTest::~QmlInputDeviceTest()
{
}

TEST_F(QmlInputDeviceTest, Create)
{
    NiceMock<UserInputControllerMock> controller;
    NiceMock<QmlContextPropertyRegistratorMock> contextRegistrator;
    QmlInputDevice inputDevice(contextRegistrator, controller);
}

TEST_F(QmlInputDeviceTest, ButtonHandlerRegistered)
{
    NiceMock<UserInputControllerMock> controller;
    NiceMock<QmlContextPropertyRegistratorMock> contextRegistrator;

    EXPECT_CALL(contextRegistrator, setContextProperty("buttonHandler", _))
        .Times(1);
    QmlInputDevice inputDevuce(contextRegistrator, controller);
}

}
