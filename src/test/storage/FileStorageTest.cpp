#include "FileStorageTest.h"
#include "FileWriterMock.h"
#include "FileReaderMock.h"
#include "storage/FileStorage.h"

using ::testing::NiceMock;
using ::testing::_;
using ::testing::SaveArg;
using ::testing::Return;

namespace KegeratorDisplay {

FileStorageTest::FileStorageTest() :
    m_writer(NULL),
    m_reader(NULL),
    m_storage(NULL)
{
}

FileStorageTest::~FileStorageTest()
{
}

void FileStorageTest::SetUp()
{
    m_writer = new NiceMock<FileWriterMock>();
    m_reader = new NiceMock<FileReaderMock>();
    m_storage = new FileStorage("file", m_writer, m_reader);
}

void FileStorageTest::TearDown()
{
    delete m_storage;
}

TEST_F(FileStorageTest, Create)
{
}

TEST_F(FileStorageTest, WriteTemperatureWritesToFile)
{
    Temperature originalTemperature;
    originalTemperature.addReading(1);
    originalTemperature.addReading(2);
    originalTemperature.addReading(3);

    EXPECT_CALL(*m_writer, truncateAndWrite("file", _))
        .Times(1);
    m_storage->writeTemperature(&originalTemperature);
}

TEST_F(FileStorageTest, ReadTemperatureReadsFromFile)
{
    Temperature originalTemperature;
    originalTemperature.addReading(1);
    originalTemperature.addReading(2);
    originalTemperature.addReading(3);

    EXPECT_CALL(*m_reader, read("file"))
        .Times(1)
        .WillOnce(Return("22 serialization::archive 12 0 0 6 0 3 2 1 0 0 0"));
    Temperature* temperature = m_storage->readTemperature();
    delete temperature;
}

TEST_F(FileStorageTest, WriteTemperatureCorrect)
{
    Temperature originalTemperature;
    originalTemperature.addReading(3);
    originalTemperature.addReading(2);
    originalTemperature.addReading(1);

    EXPECT_CALL(*m_writer, truncateAndWrite("file", "22 serialization::archive 12 0 0 6 0 3 2 1 0 0 0"))
        .Times(1);

    m_storage->writeTemperature(&originalTemperature);
}


TEST_F(FileStorageTest, ReadTemperatureCorrect)
{
    Temperature originalTemperature;
    originalTemperature.addReading(3);
    originalTemperature.addReading(2);
    originalTemperature.addReading(1);

    ON_CALL(*m_reader, read("file"))
        .WillByDefault(Return("22 serialization::archive 12 0 0 6 0 3 2 1 0 0 0"));
    Temperature* temperature = m_storage->readTemperature();
    EXPECT_EQ(originalTemperature, *temperature);
    delete temperature;
}
}
