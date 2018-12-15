#include "ApplicationThreadImplTest.h"
#include "thread/ApplicationThreadImpl.h"

namespace KegeratorDisplay {

ApplicationThreadImplTest::ApplicationThreadImplTest()
{
}

ApplicationThreadImplTest::~ApplicationThreadImplTest()
{
}

TEST_F(ApplicationThreadImplTest, Create)
{
    boost::asio::io_service ios;
    ApplicationThreadImpl a(ios);
}

void test() {};

TEST_F(ApplicationThreadImplTest, CanPost)
{
    boost::asio::io_service ios;
    ApplicationThreadImpl a(ios);
    a.post(test);
}

}
