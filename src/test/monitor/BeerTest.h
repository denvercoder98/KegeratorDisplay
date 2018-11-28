#ifndef STC_TEST_MONITOR_BEERTEST_H_
#define STC_TEST_MONITOR_BEERTEST_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class Beer;

class BeerTest: public ::testing::Test
{
public:
    BeerTest();
    virtual ~BeerTest();

protected:
    void SetUp();
    void TearDown();

    Beer* m_beer;
};

}

#endif
