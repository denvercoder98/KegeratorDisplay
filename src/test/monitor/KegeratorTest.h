#ifndef STC_TEST_MONITOR_KEGERATORTEST_H_
#define STC_TEST_MONITOR_KEGERATORTEST_H_

#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace KegeratorDisplay {

class KegeratorTest : public ::testing::Test {
public:
	KegeratorTest();
	virtual ~KegeratorTest();
};

}

#endif
