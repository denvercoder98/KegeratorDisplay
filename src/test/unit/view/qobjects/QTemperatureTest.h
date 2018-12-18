#ifndef SRC_TEST_UNIT_VIEW_QOBJECTS_QTEMPERATURETEST_H_
#define SRC_TEST_UNIT_VIEW_QOBJECTS_QTEMPERATURETEST_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class QTemperatureTest : public testing::Test
{
public:
    QTemperatureTest();
    virtual ~QTemperatureTest();
};

}

#endif
