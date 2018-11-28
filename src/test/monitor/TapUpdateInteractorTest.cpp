#include "TapUpdateInteractorTest.h"
#include "PresenterMock.h"
#include "StorageMock.h"
#include "monitor/TapUpdateInteractor.h"
#include "monitor/TapUpdateResponse.h"
#include "monitor/InvalidTapUpdateInteractorArgumentException.h"
#include "entities/Beer.h"
#include "entities/AlcoholByVolume.h"
#include "entities/InternationalBitternessUnits.h"
#include "entities/Date.h"
#include "entities/SpecificGravity.h"

using ::testing::NiceMock;
using ::testing::Return;
using ::testing::_;
using ::testing::Eq;

namespace KegeratorDisplay {

TapUpdateInteractorTest::TapUpdateInteractorTest() :
    m_observer(NULL),
    m_storage(NULL)
{
}

TapUpdateInteractorTest::~TapUpdateInteractorTest()
{
}

void TapUpdateInteractorTest::SetUp()
{
    m_observer = new NiceMock<PresenterMock>();
    m_storage = new NiceMock<StorageMock>();
}

void TapUpdateInteractorTest::prepareBeers()
{
    Beer beerA("Beer A",
        "Kalle Karlsson",
        AlcoholByVolume(5.2),
        InternationalBitternessUnits(40),
        Date(2018, 10, 1),
        Date(2018, 11, 1),
        SpecificGravity(1.010));
    Beer beerB("Beer B",
        "Sven Svensson",
        AlcoholByVolume(3.5),
        InternationalBitternessUnits(20),
        Date(2018, 10, 2),
        Date(2018, 11, 2),
        SpecificGravity(1.012));

    ON_CALL(*m_storage, readLeftTap)
        .WillByDefault(Return(new Tap(beerA)));
    ON_CALL(*m_storage, readRightTap)
        .WillByDefault(Return(new Tap(beerB)));
}

void TapUpdateInteractorTest::TearDown()
{
    delete m_storage;
    delete m_observer;
}

TEST_F(TapUpdateInteractorTest, Create)
{
    prepareBeers();
    TapUpdateInteractor(m_observer, m_storage);
}

TEST_F(TapUpdateInteractorTest, MissingStorageThrows)
{
    EXPECT_THROW(TapUpdateInteractor(m_observer, NULL), InvalidTapUpdateInteractorArgumentException);
}

TEST_F(TapUpdateInteractorTest, MissingObserverThrows)
{
    EXPECT_THROW(TapUpdateInteractor(NULL, m_storage), InvalidTapUpdateInteractorArgumentException);
}

TEST_F(TapUpdateInteractorTest, ReadLeftTapStorageOnCreation)
{
    NiceMock<StorageMock> storage;
    Beer beerA("Beer A",
        "Kalle Karlsson",
        AlcoholByVolume(5.2),
        InternationalBitternessUnits(40),
        Date(2018, 10, 1),
        Date(2018, 11, 1),
        SpecificGravity(1.010));
    Beer beerB("Beer B",
        "Kalle Karlsson",
        AlcoholByVolume(5.2),
        InternationalBitternessUnits(40),
        Date(2018, 10, 1),
        Date(2018, 11, 1),
        SpecificGravity(1.010));
    EXPECT_CALL(storage, readLeftTap)
        .WillOnce(Return(new Tap(beerA)));
    ON_CALL(storage, readRightTap)
        .WillByDefault(Return(new Tap(beerB)));

    TapUpdateInteractor updator(m_observer, &storage);
}

TEST_F(TapUpdateInteractorTest, ReadRightTapStorageOnCreation)
{
    NiceMock<StorageMock> storage;
    Beer beerA("Beer A",
        "Kalle Karlsson",
        AlcoholByVolume(5.2),
        InternationalBitternessUnits(40),
        Date(2018, 10, 1),
        Date(2018, 11, 1),
        SpecificGravity(1.010));
    Beer beerB("Beer B",
        "Kalle Karlsson",
        AlcoholByVolume(5.2),
        InternationalBitternessUnits(40),
        Date(2018, 10, 1),
        Date(2018, 11, 1),
        SpecificGravity(1.010));
    EXPECT_CALL(storage, readLeftTap)
        .WillOnce(Return(new Tap(beerA)));
    EXPECT_CALL(storage, readRightTap)
        .WillOnce(Return(new Tap(beerB)));

    TapUpdateInteractor updator(m_observer, &storage);
}

TEST_F(TapUpdateInteractorTest, UpdateTapFromStorageOnCreation)
{
    NiceMock<StorageMock> storage;
    Beer beerA("Beer A",
        "Kalle Karlsson",
        AlcoholByVolume(5.2),
        InternationalBitternessUnits(40),
        Date(2018, 10, 1),
        Date(2018, 11, 1),
        SpecificGravity(1.010));
    Beer beerB("Beer B",
        "Kalle Karlsson",
        AlcoholByVolume(5.2),
        InternationalBitternessUnits(40),
        Date(2018, 10, 1),
        Date(2018, 11, 1),
        SpecificGravity(1.010));
    ON_CALL(storage, readLeftTap)
        .WillByDefault(Return(new Tap(beerA)));
    ON_CALL(storage, readRightTap)
        .WillByDefault(Return(new Tap(beerB)));

    BeerUpdateResponse expectedLeftBeer("Beer A", "Kalle Karlsson", "5,2", 40, "2018-10-01", "2018-11-01", "1.010");
    TapUpdateResponse expectedLeftTap(TAP_LEFT, expectedLeftBeer);
    BeerUpdateResponse expectedRightBeer("Beer B", "Kalle Karlsson", "5,2", 40, "2018-10-01", "2018-11-01", "1.010");
    TapUpdateResponse expectedRightTap(TAP_RIGHT, expectedRightBeer);

    EXPECT_CALL(*m_observer, updateTap(Eq(expectedLeftTap))).
        Times(1);
    EXPECT_CALL(*m_observer, updateTap(Eq(expectedRightTap))).
        Times(1);
    TapUpdateInteractor updator(m_observer, &storage);
}

}