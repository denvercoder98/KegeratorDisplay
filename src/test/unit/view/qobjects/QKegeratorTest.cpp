#include "QKegeratorTest.h"
#include "view/qobjects/QKegerator.h"

namespace KegeratorDisplay {

QKegeratorTest::QKegeratorTest()
{
}

QKegeratorTest::~QKegeratorTest()
{
}

TEST_F(QKegeratorTest, Create)
{
    QKegerator kegerator;
}

TEST_F(QKegeratorTest, DefaultHeadingEmpty)
{
    QKegerator kegerator;
    EXPECT_EQ("", kegerator.heading());
}

TEST_F(QKegeratorTest, SetHeading)
{
    QKegerator kegerator;
    kegerator.setHeading("abc123");
}

TEST_F(QKegeratorTest, GetHeading)
{
    QKegerator kegerator;
    kegerator.setHeading("abc123");
    EXPECT_EQ("abc123", kegerator.heading());
}

}
