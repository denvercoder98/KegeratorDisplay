#include "SensorSamplerTest.h"
#include "SensorControllerMock.h"
#include "src/main/controller/SensorSampler.h"

using ::testing::NiceMock;

namespace KegeratorDisplay {

SensorSamplerTest::SensorSamplerTest() :
    m_sensorController(NULL),
    m_sampler(NULL)
{
}

SensorSamplerTest::~SensorSamplerTest()
{
}

void SensorSamplerTest::SetUp()
{
    m_sensorController = new NiceMock<SensorControllerMock>();
    m_sampler = new SensorSampler();
}

void SensorSamplerTest::TearDown()
{
    delete m_sampler;
}

TEST_F(SensorSamplerTest, Create)
{
}

TEST_F(SensorSamplerTest, SampleSingleController)
{
    m_sampler->addSensorController(m_sensorController);

    EXPECT_CALL(*m_sensorController, process())
        .Times(1);

    m_sampler->sample();
}

TEST_F(SensorSamplerTest, SampleMultipleControllers)
{
    m_sampler->addSensorController(m_sensorController);
    SensorControllerMock* anotherSensorController = new NiceMock<SensorControllerMock>();
    m_sampler->addSensorController(anotherSensorController);

    EXPECT_CALL(*m_sensorController, process())
        .Times(1);
    EXPECT_CALL(*anotherSensorController, process())
        .Times(1);

    m_sampler->sample();
}

}
