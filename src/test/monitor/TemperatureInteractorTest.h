#ifndef STC_TEST_MONITOR_TEMPERATUREINTERACTORTEST_H_
#define STC_TEST_MONITOR_TEMPERATUREINTERACTORTEST_H_

#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace KegeratorDisplay {

class TemperatureInteractorTest : public ::testing::Test {
public:
	TemperatureInteractorTest();
	virtual ~TemperatureInteractorTest();
};

}

#endif
