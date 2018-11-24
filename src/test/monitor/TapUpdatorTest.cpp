#include "TapUpdatorTest.h"
#include "monitor/TapUpdator.h"
#include "monitor/Beer.h"
#include "monitor/AlcoholByVolume.h"
#include "monitor/InternationalBitternessUnits.h"
#include "monitor/Date.h"
#include "monitor/SpecificGravity.h"
#include "monitor/InvalidTapUpdatorArgumentException.h"
#include "monitor/TapUpdate.h"
#include "StorageMock.h"
#include "KegeratorObserverMock.h"

using ::testing::NiceMock;
using ::testing::Return;
using ::testing::_;
using ::testing::Eq;

namespace KegeratorDisplay {

TapUpdatorTest::TapUpdatorTest() :
    m_observer(NULL),
    m_storage(NULL)
{
}

TapUpdatorTest::~TapUpdatorTest()
{
}

void TapUpdatorTest::SetUp()
{
    m_observer = new NiceMock<KegeratorObserverMock>();
    m_storage = new NiceMock<StorageMock>();
}

void TapUpdatorTest::prepareBeers()
{
    Beer* beerA = new Beer("Beer A",
        "Kalle Karlsson",
        AlcoholByVolume(5.2),
        InternationalBitternessUnits(40),
        Date(2018, 10, 1),
        Date(2018, 11, 1),
        SpecificGravity(1.010));
    Beer* beerB = new Beer("Beer B",
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

void TapUpdatorTest::TearDown()
{
    delete m_storage;
    delete m_observer;
}

TEST_F(TapUpdatorTest, Create)
{
    prepareBeers();
    TapUpdator(m_observer, m_storage);
}

TEST_F(TapUpdatorTest, MissingStorageThrows)
{
    EXPECT_THROW(TapUpdator(m_observer, NULL), InvalidTapUpdatorArgumentException);
}

TEST_F(TapUpdatorTest, MissingObserverThrows)
{
    EXPECT_THROW(TapUpdator(NULL, m_storage), InvalidTapUpdatorArgumentException);
}

TEST_F(TapUpdatorTest, ReadLeftTapStorageOnCreation)
{
    NiceMock<StorageMock> storage;
    Beer* beerA = new Beer("Beer A",
        "Kalle Karlsson",
        AlcoholByVolume(5.2),
        InternationalBitternessUnits(40),
        Date(2018, 10, 1),
        Date(2018, 11, 1),
        SpecificGravity(1.010));
    Beer* beerB = new Beer("Beer B",
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

    TapUpdator updator(m_observer, &storage);
}

TEST_F(TapUpdatorTest, ReadRightTapStorageOnCreation)
{
    NiceMock<StorageMock> storage;
    Beer* beerA = new Beer("Beer A",
        "Kalle Karlsson",
        AlcoholByVolume(5.2),
        InternationalBitternessUnits(40),
        Date(2018, 10, 1),
        Date(2018, 11, 1),
        SpecificGravity(1.010));
    Beer* beerB = new Beer("Beer B",
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

    TapUpdator updator(m_observer, &storage);
}

TEST_F(TapUpdatorTest, UpdateTapFromStorageOnCreation)
{
    NiceMock<StorageMock> storage;
    Beer* beerA = new Beer("Beer A",
        "Kalle Karlsson",
        AlcoholByVolume(5.2),
        InternationalBitternessUnits(40),
        Date(2018, 10, 1),
        Date(2018, 11, 1),
        SpecificGravity(1.010));
    Beer* beerB = new Beer("Beer B",
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

    BeerUpdate expectedLeftBeer("Beer A", "Kalle Karlsson", "5,2", 40, "2018-10-01", "2018-11-01", "1.010");
    TapUpdate expectedLeftTap(TAP_LEFT, expectedLeftBeer);
    BeerUpdate expectedRightBeer("Beer B", "Kalle Karlsson", "5,2", 40, "2018-10-01", "2018-11-01", "1.010");
    TapUpdate expectedRightTap(TAP_RIGHT, expectedRightBeer);

    EXPECT_CALL(*m_observer, updateTap(Eq(expectedLeftTap))).
        Times(1);
    EXPECT_CALL(*m_observer, updateTap(Eq(expectedRightTap))).
        Times(1);
    TapUpdator updator(m_observer, &storage);
}

}
