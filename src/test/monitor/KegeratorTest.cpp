#include "KegeratorTest.h"
#include "src/main/monitor/Kegerator.h"
#include "src/main/monitor/Tap.h"

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
