#include "DS18B20SensorReaderImplTest.h"
#include "devices/DS18B20SensorReaderImpl.h"
#include "devices/InvalidDS18B20SensorReaderArgument.h"
#include "unit/storage/FileReaderMock.h"

using testing::NiceMock;
using testing::_;
using testing::Return;

namespace KegeratorDisplay {

DS18B20SensorReaderImplTest::DS18B20SensorReaderImplTest()
{
}

DS18B20SensorReaderImplTest::~DS18B20SensorReaderImplTest()
{
}

TEST_F(DS18B20SensorReaderImplTest, Create)
{
    FileReader* fileReader = new NiceMock<FileReaderMock>();
    DS18B20SensorReaderImpl reader("device", fileReader);
}

TEST_F(DS18B20SensorReaderImplTest, ThrowsIfMissingFileReader)
{
    EXPECT_THROW(DS18B20SensorReaderImpl("device", NULL), InvalidDS18B20SensorReaderArgument);
}

TEST_F(DS18B20SensorReaderImplTest, ReadFromFileReader)
{
    NiceMock<FileReaderMock>* fileReader = new NiceMock<FileReaderMock>();
    DS18B20SensorReaderImpl reader("device", fileReader);
    EXPECT_CALL(*fileReader, read(_))
        .Times(1);
    reader.read();
}

TEST_F(DS18B20SensorReaderImplTest, ReadsFromConfiguredDevice)
{
    NiceMock<FileReaderMock>* fileReader = new NiceMock<FileReaderMock>();
    DS18B20SensorReaderImpl reader("device", fileReader);
    EXPECT_CALL(*fileReader, read("device"))
        .Times(1);
    reader.read();
}

TEST_F(DS18B20SensorReaderImplTest, ReadReturnsValueVerbatim)
{
    NiceMock<FileReaderMock>* fileReader = new NiceMock<FileReaderMock>();
    DS18B20SensorReaderImpl reader("device", fileReader);
    std::string expected = "abc123";
    ON_CALL(*fileReader, read("device"))
        .WillByDefault( Return(expected) );
    std::string readValue = reader.read();
    EXPECT_EQ(expected, readValue);
}

}
