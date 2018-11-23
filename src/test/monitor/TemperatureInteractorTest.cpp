#include "TemperatureInteractorTest.h"
#include "KegeratorObserverMock.h"
#include "StorageMock.h"
#include "monitor/TemperatureInteractor.h"

using ::testing::_;
using ::testing::NiceMock;
using ::testing::Eq;
using ::testing::Return;

namespace KegeratorDisplay {

TemperatureInteractorTest::TemperatureInteractorTest()
{
}

TemperatureInteractorTest::~TemperatureInteractorTest()
{
}

TEST_F(TemperatureInteractorTest, Create)
{
    KegeratorObserverMock kegerator;
    NiceMock<StorageMock> storage;
    ON_CALL(storage, readTemperature())
        .WillByDefault(Return(new Temperature()));

    TemperatureInteractor interactor(&kegerator, &storage);
}

TEST_F(TemperatureInteractorTest, ReadTemperatureFromStorage)
{
    Temperature *temperature = new Temperature();
    NiceMock<KegeratorObserverMock> kegerator;
    NiceMock<StorageMock> storage;

    TemperatureUpdate expectedUpdate(5);
    EXPECT_CALL(storage, readTemperature())
        .Times(1)
        .WillRepeatedly(Return(temperature));
    TemperatureInteractor interactor(&kegerator, &storage);
}


TEST_F(TemperatureInteractorTest, ReceiveTemperature)
{
    TemperatureReading reading(5);
    NiceMock<KegeratorObserverMock> kegerator;
    NiceMock<StorageMock> storage;
    ON_CALL(storage, readTemperature())
        .WillByDefault(Return(new Temperature()));
   
    TemperatureInteractor interactor(&kegerator, &storage);
    interactor.receiveTemperatureReading(reading);
}

TEST_F(TemperatureInteractorTest, UpdateTemperatureNotifiesObserver)
{
    NiceMock<KegeratorObserverMock> kegerator;

    NiceMock<StorageMock> storage;
    ON_CALL(storage, readTemperature())
        .WillByDefault(Return(new Temperature()));

    TemperatureInteractor interactor(&kegerator, &storage);
    TemperatureReading reading(3);

    EXPECT_CALL(kegerator, update(_));
    interactor.receiveTemperatureReading(reading);
}

TEST_F(TemperatureInteractorTest, UpdateTemperatureNotifiesObserverCorrectValue)
{
    NiceMock<KegeratorObserverMock> kegerator;

    NiceMock<StorageMock> storage;
    ON_CALL(storage, readTemperature())
        .WillByDefault(Return(new Temperature()));

    TemperatureInteractor interactor(&kegerator, &storage);
    TemperatureReading reading(3);

    TemperatureUpdate expectedUpdate(1);
    EXPECT_CALL(kegerator, update(Eq(expectedUpdate)));
    interactor.receiveTemperatureReading(reading);
}

}
