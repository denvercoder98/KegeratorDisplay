#include "../interactors/TemperatureUpdateInteractorTest.h"

#include <interactors/TemperatureUpdateInteractor.h>

#include "unit/interactors/PresenterMock.h"
#include "unit/interactors/StorageMock.h"

using ::testing::_;
using ::testing::NiceMock;
using ::testing::Eq;
using ::testing::Return;

namespace KegeratorDisplay {

TemperatureUpdateInteractorTest::TemperatureUpdateInteractorTest()
{
}

TemperatureUpdateInteractorTest::~TemperatureUpdateInteractorTest()
{
}

TEST_F(TemperatureUpdateInteractorTest, Create)
{
    PresenterMock kegerator;
    NiceMock<StorageMock> storage;
    ON_CALL(storage, readTemperature())
        .WillByDefault(Return(new Temperature()));

    TemperatureUpdateInteractor interactor(&kegerator, storage);
}

TEST_F(TemperatureUpdateInteractorTest, ReadTemperatureFromStorage)
{
    Temperature *temperature = new Temperature();
    NiceMock<PresenterMock> kegerator;
    NiceMock<StorageMock> storage;

    TemperatureUpdateResponse expectedUpdate(5);
    EXPECT_CALL(storage, readTemperature())
        .Times(1)
        .WillRepeatedly(Return(temperature));
    TemperatureUpdateInteractor interactor(&kegerator, storage);
}


TEST_F(TemperatureUpdateInteractorTest, ReceiveTemperature)
{
    TemperatureUpdateRequest reading(5);
    NiceMock<PresenterMock> kegerator;
    NiceMock<StorageMock> storage;
    ON_CALL(storage, readTemperature())
        .WillByDefault(Return(new Temperature()));
   
    TemperatureUpdateInteractor interactor(&kegerator, storage);
    interactor.receiveTemperatureReading(reading);
}

TEST_F(TemperatureUpdateInteractorTest, UpdateTemperatureNotifiesObserver)
{
    NiceMock<PresenterMock> kegerator;

    NiceMock<StorageMock> storage;
    ON_CALL(storage, readTemperature())
        .WillByDefault(Return(new Temperature()));

    TemperatureUpdateInteractor interactor(&kegerator, storage);
    TemperatureUpdateRequest reading(3);

    EXPECT_CALL(kegerator, updateTemperature(_));
    interactor.receiveTemperatureReading(reading);
}

TEST_F(TemperatureUpdateInteractorTest, UpdateTemperatureNotifiesObserverCorrectValue)
{
    NiceMock<PresenterMock> kegerator;

    NiceMock<StorageMock> storage;
    ON_CALL(storage, readTemperature())
        .WillByDefault(Return(new Temperature()));

    TemperatureUpdateInteractor interactor(&kegerator, storage);
    TemperatureUpdateRequest reading(3);

    TemperatureUpdateResponse expectedUpdate(1);
    EXPECT_CALL(kegerator, updateTemperature(Eq(expectedUpdate)));
    interactor.receiveTemperatureReading(reading);
}

TEST_F(TemperatureUpdateInteractorTest, UpdateTemperatureWritesToStorage)
{
    NiceMock<PresenterMock> kegerator;

    NiceMock<StorageMock> storage;
    ON_CALL(storage, readTemperature())
        .WillByDefault(Return(new Temperature()));

    TemperatureUpdateInteractor interactor(&kegerator, storage);
    TemperatureUpdateRequest reading(3);

    EXPECT_CALL(storage, writeTemperature(_));
    interactor.receiveTemperatureReading(reading);
}

}
