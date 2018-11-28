#ifndef STC_TEST_MONITOR_TEMPERATUREUPDATEINTERACTORTEST_H_
#define STC_TEST_MONITOR_TEMPERATUREUPDATEINTERACTORTEST_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class TemperatureUpdateInteractorTest : public ::testing::Test {
public:
    TemperatureUpdateInteractorTest();
	virtual ~TemperatureUpdateInteractorTest();
};

}

#endif
