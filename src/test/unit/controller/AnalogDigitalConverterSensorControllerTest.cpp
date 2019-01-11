#include "AnalogDigitalConverterSensorControllerTest.h"

#include <controllers/AnalogDigitalConverterSensorController.h>
#include <controllers/InvalidAnalogDigitalConverterSensorControllerArgumentException.h>
#include <controllers/SensorSampler.h>

#include "unit/interactors/AnalogDigitalConverterUpdateRequestObserverMock.h"
#include "AnalogDigitalConverterSensorMock.h"
#include "unit/thread/DeadlineTimerMock.h"
#include "unit/thread/MutexMock.h"

using testing::NiceMock;
using testing::Return;
using testing::_;

namespace KegeratorDisplay {

AnalogDigitalConverterSensorControllerTest::AnalogDigitalConverterSensorControllerTest()
{
}

AnalogDigitalConverterSensorControllerTest::~AnalogDigitalConverterSensorControllerTest()
{
}

TEST_F(AnalogDigitalConverterSensorControllerTest, Create)
{
    NiceMock<AnalogDigitalConverterSensorMock>* sensor = new NiceMock<AnalogDigitalConverterSensorMock>();
    NiceMock<AnalogDigitalConverterUpdateRequestObserverMock>* observer = new NiceMock<AnalogDigitalConverterUpdateRequestObserverMock>();
    AnalogDigitalConverterSensorController controller(
        AnalogDigitalConverterSensorController::ADC_10BITS,
        AnalogDigitalConverterSensorController::ADC_CHANNEL0,
        sensor,
        observer);
}

TEST_F(AnalogDigitalConverterSensorControllerTest, MissingSensorThrows)
{
    NiceMock<AnalogDigitalConverterUpdateRequestObserverMock>* observer = new NiceMock<AnalogDigitalConverterUpdateRequestObserverMock>();
    EXPECT_THROW(AnalogDigitalConverterSensorController(
                    AnalogDigitalConverterSensorController::ADC_10BITS,
                    AnalogDigitalConverterSensorController::ADC_CHANNEL0,
                    NULL,
                    observer),
                 InvalidAnalogDigitalConverterSensorControllerArgumentException);
}

TEST_F(AnalogDigitalConverterSensorControllerTest, MissingObserverThrows)
{
    NiceMock<AnalogDigitalConverterSensorMock>* sensor = new NiceMock<AnalogDigitalConverterSensorMock>();
    EXPECT_THROW(AnalogDigitalConverterSensorController(
                    AnalogDigitalConverterSensorController::ADC_10BITS,
                    AnalogDigitalConverterSensorController::ADC_CHANNEL0,
                    sensor,
                    NULL),
                 InvalidAnalogDigitalConverterSensorControllerArgumentException);
}

TEST_F(AnalogDigitalConverterSensorControllerTest, CanAddToSensorSampler)
{
    NiceMock<AnalogDigitalConverterSensorMock>* sensor = new NiceMock<AnalogDigitalConverterSensorMock>();
    NiceMock<AnalogDigitalConverterUpdateRequestObserverMock>* observer = new NiceMock<AnalogDigitalConverterUpdateRequestObserverMock>();
    AnalogDigitalConverterSensorController* controller = new AnalogDigitalConverterSensorController(
        AnalogDigitalConverterSensorController::ADC_10BITS,
        AnalogDigitalConverterSensorController::ADC_CHANNEL0,
        sensor,
        observer);
    DeadlineTimerMock* deadlineTimer = new NiceMock<DeadlineTimerMock>();
    MutexMock* mutex = new NiceMock<MutexMock>();
    SensorSampler sampler(1, deadlineTimer, mutex);
    sampler.addSensorController(controller);
}

TEST_F(AnalogDigitalConverterSensorControllerTest, ProcessReadsFromSensor)
{
    NiceMock<AnalogDigitalConverterSensorMock>* sensor = new NiceMock<AnalogDigitalConverterSensorMock>();
    NiceMock<AnalogDigitalConverterUpdateRequestObserverMock>* observer = new NiceMock<AnalogDigitalConverterUpdateRequestObserverMock>();
    AnalogDigitalConverterSensorController controller(
        AnalogDigitalConverterSensorController::ADC_10BITS,
        AnalogDigitalConverterSensorController::ADC_CHANNEL0,
        sensor,
        observer);

    EXPECT_CALL(*sensor, readChannel(_))
        .Times(1);
    controller.process();
}

TEST_F(AnalogDigitalConverterSensorControllerTest, ProcessReadsFromCorrectSensorChannel)
{
    NiceMock<AnalogDigitalConverterSensorMock>* sensor = new NiceMock<AnalogDigitalConverterSensorMock>();
    NiceMock<AnalogDigitalConverterUpdateRequestObserverMock>* observer = new NiceMock<AnalogDigitalConverterUpdateRequestObserverMock>();
    AnalogDigitalConverterSensorController controller(
        AnalogDigitalConverterSensorController::ADC_10BITS,
        AnalogDigitalConverterSensorController::ADC_CHANNEL6,
        sensor,
        observer);

    EXPECT_CALL(*sensor, readChannel(6))
        .Times(1);
    controller.process();
}

TEST_F(AnalogDigitalConverterSensorControllerTest, ProcessNotifiesAnalogDigitalConverterUpdateRequestObserver)
{
    NiceMock<AnalogDigitalConverterSensorMock>* sensor = new NiceMock<AnalogDigitalConverterSensorMock>();
    NiceMock<AnalogDigitalConverterUpdateRequestObserverMock>* observer = new NiceMock<AnalogDigitalConverterUpdateRequestObserverMock>();
    AnalogDigitalConverterSensorController controller(
        AnalogDigitalConverterSensorController::ADC_10BITS,
        AnalogDigitalConverterSensorController::ADC_CHANNEL0,
        sensor,
        observer);

    EXPECT_CALL(*observer, updateValue(_))
        .Times(1);
    controller.process();
}

TEST_F(AnalogDigitalConverterSensorControllerTest, ProcessNotifiesAnalogDigitalConverterUpdateRequestObserverZeroValue)
{
    NiceMock<AnalogDigitalConverterSensorMock>* sensor = new NiceMock<AnalogDigitalConverterSensorMock>();
    NiceMock<AnalogDigitalConverterUpdateRequestObserverMock>* observer = new NiceMock<AnalogDigitalConverterUpdateRequestObserverMock>();
    AnalogDigitalConverterSensorController controller(
        AnalogDigitalConverterSensorController::ADC_10BITS,
        AnalogDigitalConverterSensorController::ADC_CHANNEL0,
        sensor,
        observer);

    AdcReading10Bit expected(0);
    ON_CALL(*sensor, readChannel(_))
        .WillByDefault( Return(0) );
    EXPECT_CALL(*observer, updateValue(expected))
        .Times(1);
    controller.process();
}

TEST_F(AnalogDigitalConverterSensorControllerTest, ProcessNotifiesAnalogDigitalConverterUpdateRequestObserverValue)
{
    NiceMock<AnalogDigitalConverterSensorMock>* sensor = new NiceMock<AnalogDigitalConverterSensorMock>();
    NiceMock<AnalogDigitalConverterUpdateRequestObserverMock>* observer = new NiceMock<AnalogDigitalConverterUpdateRequestObserverMock>();
    AnalogDigitalConverterSensorController controller(
        AnalogDigitalConverterSensorController::ADC_10BITS,
        AnalogDigitalConverterSensorController::ADC_CHANNEL0,
        sensor,
        observer);

    ON_CALL(*sensor, readChannel(_))
        .WillByDefault( Return(512) );
    AdcReading10Bit expected(512);
    EXPECT_CALL(*observer, updateValue(expected))
        .Times(1);
    controller.process();
}

}
