#ifndef SRC_TEST_UNIT_VIEW_QOBJECTS_QTAPTEST_H_
#define SRC_TEST_UNIT_VIEW_QOBJECTS_QTAPTEST_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class QTapTest : public testing::Test
{
public:
    QTapTest();
    virtual ~QTapTest();
};

}

#endif
