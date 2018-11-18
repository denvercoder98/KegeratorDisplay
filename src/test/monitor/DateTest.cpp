#include "DateTest.h"
#include "src/main/monitor/Date.h"
#include "src/main/monitor/InvalidDateException.h"

namespace KegeratorDisplay {

DateTest::DateTest()
{
}

DateTest::~DateTest()
{
}

TEST_F(DateTest, Create)
{
    Date date(2018, 11, 20);
}

TEST_F(DateTest, InvalidMonthThrows)
{
    EXPECT_THROW(Date(2018, 111, 20), InvalidDateException);;
}

TEST_F(DateTest, InvalidDayThrows)
{
    EXPECT_THROW(Date(2018, 111, 20), InvalidDateException);;
}

TEST_F(DateTest, GetValue)
{
    Date date(2018, 11, 20);
    EXPECT_EQ("2018-11-20", date.value());
}

TEST_F(DateTest, GetValueSingleDigitDay)
{
    Date date(2018, 11, 2);
    EXPECT_EQ("2018-11-02", date.value());
}

TEST_F(DateTest, GetValueSingleDigitMonth)
{
    Date date(2018, 1, 2);
    EXPECT_EQ("2018-01-02", date.value());
}

}
