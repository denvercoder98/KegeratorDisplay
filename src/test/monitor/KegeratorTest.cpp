#include "KegeratorTest.h"
#include "monitor/Kegerator.h"
#include "monitor/Tap.h"

namespace KegeratorDisplay {

KegeratorTest::KegeratorTest()
{
}

KegeratorTest::~KegeratorTest()
{
}

TEST_F(KegeratorTest, Create)
{
    Kegerator kegerator(new Tap(), new Tap());
}

}
