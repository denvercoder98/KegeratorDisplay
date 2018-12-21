#ifndef SRC_TEST_UNIT_DEVICES_QMLBUTTONHANDLERTEST_H_
#define SRC_TEST_UNIT_DEVICES_QMLBUTTONHANDLERTEST_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "view/qobjects/QTap.h"

namespace KegeratorDisplay {

class QmlButtonHandlerTest : public testing::Test
{
public:
    QmlButtonHandlerTest();
    virtual ~QmlButtonHandlerTest();

protected:
    QTap m_leftTap;
    QTap m_rightTap;
};

}

#endif
