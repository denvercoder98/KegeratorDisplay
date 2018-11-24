#include "TapUpdatorTest.h"
#include "monitor/TapUpdator.h"
#include "monitor/InvalidTapUpdatorArgumentException.h"
#include "StorageMock.h"

using ::testing::NiceMock;
using ::testing::Return;

namespace KegeratorDisplay {

TapUpdatorTest::TapUpdatorTest() :
    m_storage(NULL),
    m_tapUpdator(NULL)
{
}

TapUpdatorTest::~TapUpdatorTest()
{
}

void TapUpdatorTest::SetUp()
{
    m_storage = new NiceMock<StorageMock>();
    ON_CALL(*m_storage, readTap)
        .WillByDefault(Return(new Tap()));

    m_tapUpdator = new TapUpdator(m_storage);
}

void TapUpdatorTest::TearDown()
{
    delete m_tapUpdator;
    delete m_storage;
}

TEST_F(TapUpdatorTest, Create)
{
}

TEST_F(TapUpdatorTest, MissingStorageThrows)
{
    EXPECT_THROW(TapUpdator(NULL), InvalidTapUpdatorArgumentException);
}

TEST_F(TapUpdatorTest, ReadStorageOnCreation)
{
    NiceMock<StorageMock> storage;
    EXPECT_CALL(storage, readTap)
        .WillOnce(Return(new Tap()));

    TapUpdator updator(&storage);
}

}
