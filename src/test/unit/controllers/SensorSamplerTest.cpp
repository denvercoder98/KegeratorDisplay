#include "SensorSamplerTest.h"

#include "controllers/InvalidSensorSamplerArgumentException.h"
#include "controllers/SensorSampler.h"

#include "SensorControllerMock.h"
#include "unit/thread/DeadlineTimerMock.h"
#include "unit/thread/MutexMock.h"

using ::testing::NiceMock;
using ::testing::_;
using ::testing::Invoke;

namespace KegeratorDisplay {

SensorSamplerTest::SensorSamplerTest() :
    m_timer(NULL),
    m_mutex(NULL),
    m_sensorController(NULL),
    m_sampler(NULL)
{
}

SensorSamplerTest::~SensorSamplerTest()
{
}

void SensorSamplerTest::SetUp()
{
    m_timer = new NiceMock<DeadlineTimerMock>();
    m_mutex = new NiceMock<MutexMock>();

    m_sampler = new SensorSampler(1, m_timer, m_mutex);
    m_sensorController = new NiceMock<SensorControllerMock>();
    m_sampler->addSensorController(m_sensorController);
}

void SensorSamplerTest::TearDown()
{
    delete m_sampler;
}

TEST_F(SensorSamplerTest, Create)
{
}

void runCallback(boost::posix_time::seconds seconds,
           boost::function<void(const boost::system::error_code&)> callback)
{
    boost::system::error_code error;
    callback(error);
}

void noop(boost::posix_time::seconds seconds,
           boost::function<void(const boost::system::error_code&)> callback)
{
}

void throwException()
{
    throw std::runtime_error("test");
}

TEST_F(SensorSamplerTest, MissingDeadlineTimerThrows)
{
    MutexMock* mutex = new NiceMock<MutexMock>();
    EXPECT_THROW(new SensorSampler(1, NULL, mutex), InvalidSensorSamplerArgumentException);
    delete mutex;
}

TEST_F(SensorSamplerTest, MissingMutexThrows)
{
    DeadlineTimerMock* timer = new NiceMock<DeadlineTimerMock>();
    EXPECT_THROW(new SensorSampler(1, timer, NULL), InvalidSensorSamplerArgumentException);
    delete timer;
}

TEST_F(SensorSamplerTest, RunSingleControllerProcess)
{
    EXPECT_CALL(*m_timer, asyncWaitSeconds(_, _))
        .WillOnce(Invoke(&runCallback))
        .WillRepeatedly(Invoke(&noop));

    EXPECT_CALL(*m_sensorController, process())
        .Times(1);

    m_sampler->start();
    m_sampler->stop();
}

TEST_F(SensorSamplerTest, RunMultipleControllersProcess)
{
    SensorControllerMock* anotherSensorController = new NiceMock<SensorControllerMock>();
    m_sampler->addSensorController(anotherSensorController);

    EXPECT_CALL(*m_timer, asyncWaitSeconds(_, _))
        .WillOnce(Invoke(&runCallback))
        .WillRepeatedly(Invoke(&noop));
    EXPECT_CALL(*m_sensorController, process())
        .Times(1);
    EXPECT_CALL(*anotherSensorController, process())
        .Times(1);

    m_sampler->start();
}

TEST_F(SensorSamplerTest, RunSingleControllerProcessMutexLockedUnlocked)
{
    EXPECT_CALL(*m_timer, asyncWaitSeconds(_, _))
        .WillOnce(Invoke(&runCallback))
        .WillRepeatedly(Invoke(&noop));
    EXPECT_CALL(*m_mutex, lock())
        .Times(1);
    EXPECT_CALL(*m_mutex, unlock())
        .Times(1);

    m_sampler->start();
}

TEST_F(SensorSamplerTest, AddControllerProcessMutexLockedUnlocked)
{
    EXPECT_CALL(*m_mutex, lock())
        .Times(1);
    EXPECT_CALL(*m_mutex, unlock())
        .Times(1);

    SensorControllerMock* anotherSensorController = new NiceMock<SensorControllerMock>();
    m_sampler->addSensorController(anotherSensorController);
}

TEST_F(SensorSamplerTest, ControllerProcessExceptionCaught)
{
    EXPECT_CALL(*m_timer, asyncWaitSeconds(_, _))
        .WillOnce(Invoke(&runCallback))
        .WillRepeatedly(Invoke(&noop));

    EXPECT_CALL(*m_sensorController, process())
        .WillOnce( Invoke(&throwException) );

    EXPECT_NO_THROW(m_sampler->start());
    m_sampler->stop();
}

}
