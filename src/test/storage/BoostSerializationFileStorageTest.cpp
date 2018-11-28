#include "BoostSerializationFileStorageTest.h"
#include "FileWriterMock.h"
#include "FileReaderMock.h"
#include "storage/BoostSerializationFileStorage.h"
#include "entities/Beer.h"

using ::testing::NiceMock;
using ::testing::_;
using ::testing::SaveArg;
using ::testing::Return;

#define EXPECTED_SERIALIZED_TEMP "22 serialization::archive 12 0 0 6 0 3 2 1 0 0 0"
#define EXPECTED_SERIALIZED_TAP "22 serialization::archive 12 0 0 0 0 4 Beer 5 Kalle 0 0 3 4,0 0 0 20 0 0 2015 2 13 2015 2 13 0 0 5 1.010"

namespace KegeratorDisplay {

BoostSerializationFileStorageTest::BoostSerializationFileStorageTest() :
    m_writer(NULL),
    m_reader(NULL),
    m_storage(NULL)
{
}

BoostSerializationFileStorageTest::~BoostSerializationFileStorageTest()
{
}

void BoostSerializationFileStorageTest::SetUp()
{
    m_writer = new NiceMock<FileWriterMock>();
    m_reader = new NiceMock<FileReaderMock>();
    m_storage = new BoostSerializationFileStorage("file", "fileLeft", "fileRight", m_writer, m_reader);
}

void BoostSerializationFileStorageTest::TearDown()
{
    delete m_storage;
}

TEST_F(BoostSerializationFileStorageTest, Create)
{
}

TEST_F(BoostSerializationFileStorageTest, WriteTemperatureWritesToFile)
{
    Temperature originalTemperature;
    originalTemperature.addReading(1);
    originalTemperature.addReading(2);
    originalTemperature.addReading(3);

    EXPECT_CALL(*m_writer, truncateAndWrite("file", _))
        .Times(1);
    m_storage->writeTemperature(&originalTemperature);
}

TEST_F(BoostSerializationFileStorageTest, ReadTemperatureReadsFromFile)
{
    EXPECT_CALL(*m_reader, read("file"))
        .Times(1)
        .WillOnce(Return(EXPECTED_SERIALIZED_TEMP));
    Temperature* temperature = m_storage->readTemperature();
    delete temperature;
}

TEST_F(BoostSerializationFileStorageTest, WriteTemperatureCorrect)
{
    Temperature originalTemperature;
    originalTemperature.addReading(3);
    originalTemperature.addReading(2);
    originalTemperature.addReading(1);

    EXPECT_CALL(*m_writer, truncateAndWrite("file", EXPECTED_SERIALIZED_TEMP))
        .Times(1);

    m_storage->writeTemperature(&originalTemperature);
}


TEST_F(BoostSerializationFileStorageTest, ReadTemperatureCorrect)
{
    Temperature originalTemperature;
    originalTemperature.addReading(3);
    originalTemperature.addReading(2);
    originalTemperature.addReading(1);

    ON_CALL(*m_reader, read("file"))
        .WillByDefault(Return(EXPECTED_SERIALIZED_TEMP));
    Temperature* temperature = m_storage->readTemperature();
    EXPECT_EQ(originalTemperature, *temperature);
    delete temperature;
}

TEST_F(BoostSerializationFileStorageTest, WriteLeftTapWritesToFile)
{
    Beer beer(
        "Beer",
        "Kalle",
        AlcoholByVolume(4),
        InternationalBitternessUnits(20),
        Date(2015, 2, 13),
        Date(2015, 2, 13),
        SpecificGravity(1.010));
    Tap tap(beer);

    EXPECT_CALL(*m_writer, truncateAndWrite("fileLeft", _))
        .Times(1);
    m_storage->writeLeftTap(&tap);
}

TEST_F(BoostSerializationFileStorageTest, ReadLeftTapReadsFromFile)
{
    EXPECT_CALL(*m_reader, read("fileLeft"))
        .Times(1)
        .WillOnce(Return(EXPECTED_SERIALIZED_TAP));
    Tap* tap = m_storage->readLeftTap();
    delete tap;
}

TEST_F(BoostSerializationFileStorageTest, WriteRightTapWritesToFile)
{
    Beer beer(
        "Beer",
        "Kalle",
        AlcoholByVolume(4),
        InternationalBitternessUnits(20),
        Date(2015, 2, 13),
        Date(2015, 2, 13),
        SpecificGravity(1.010));
    Tap tap(beer);

    EXPECT_CALL(*m_writer, truncateAndWrite("fileRight", _))
        .Times(1);
    m_storage->writeRightTap(&tap);
}

TEST_F(BoostSerializationFileStorageTest, ReadRightTapReadsFromFile)
{
    EXPECT_CALL(*m_reader, read("fileRight"))
        .Times(1)
        .WillOnce(Return(EXPECTED_SERIALIZED_TAP));
    Tap* tap = m_storage->readRightTap();
    delete tap;
}

TEST_F(BoostSerializationFileStorageTest, WriteLeftTapCorrect)
{
    Beer beer(
        "Beer",
        "Kalle",
        AlcoholByVolume(4),
        InternationalBitternessUnits(20),
        Date(2015, 2, 13),
        Date(2015, 2, 13),
        SpecificGravity(1.010));
    Tap originalTap(beer);

    EXPECT_CALL(*m_writer, truncateAndWrite("fileLeft", EXPECTED_SERIALIZED_TAP))
        .Times(1);

    m_storage->writeLeftTap(&originalTap);
}

TEST_F(BoostSerializationFileStorageTest, ReadLeftTapCorrect)
{
    Beer beer(
        "Beer",
        "Kalle",
        AlcoholByVolume(4),
        InternationalBitternessUnits(20),
        Date(2015, 2, 13),
        Date(2015, 2, 13),
        SpecificGravity(1.010));
    Tap originalTap(beer);

    ON_CALL(*m_reader, read("fileLeft"))
        .WillByDefault(Return(EXPECTED_SERIALIZED_TAP));
    Tap* tap = m_storage->readLeftTap();
    EXPECT_EQ(originalTap, *tap);
    delete tap;
}

TEST_F(BoostSerializationFileStorageTest, ReadRightTapCorrect)
{
    Beer beer(
        "Beer",
        "Kalle",
        AlcoholByVolume(4),
        InternationalBitternessUnits(20),
        Date(2015, 2, 13),
        Date(2015, 2, 13),
        SpecificGravity(1.010));
    Tap originalTap(beer);

    ON_CALL(*m_reader, read("fileRight"))
        .WillByDefault(Return(EXPECTED_SERIALIZED_TAP));
    Tap* tap = m_storage->readRightTap();
    EXPECT_EQ(originalTap, *tap);
    delete tap;
}

TEST_F(BoostSerializationFileStorageTest, ReadTemperatureEMpty)
{
    Temperature originalTemp;

    ON_CALL(*m_reader, read("file"))
        .WillByDefault(Return(""));
    Temperature* temp = m_storage->readTemperature();
    EXPECT_EQ(originalTemp, *temp);
    delete temp;
}

TEST_F(BoostSerializationFileStorageTest, ReadLeftTapEmpty)
{
    Beer beer;
    Tap originalTap(beer);

    ON_CALL(*m_reader, read("fileLeft"))
        .WillByDefault(Return(""));
    Tap* tap = m_storage->readLeftTap();
    EXPECT_EQ(originalTap, *tap);
    delete tap;
}

TEST_F(BoostSerializationFileStorageTest, ReadRightTapEmpty)
{
    Beer beer;
    Tap originalTap(beer);

    ON_CALL(*m_reader, read("fileRight"))
        .WillByDefault(Return(""));
    Tap* tap = m_storage->readRightTap();
    EXPECT_EQ(originalTap, *tap);
    delete tap;
}

}
