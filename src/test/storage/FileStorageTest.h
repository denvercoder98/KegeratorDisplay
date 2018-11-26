#ifndef SRC_TEST_STORAGE_FILESTORAGETEST_H_
#define SRC_TEST_STORAGE_FILESTORAGETEST_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class FileWriterMock;
class FileReaderMock;
class BoostSerializationFileStorage;

class FileStorageTest : public testing::Test
{
public:
    FileStorageTest();
    virtual ~FileStorageTest();

protected:
    void SetUp();
    void TearDown();

    FileWriterMock* m_writer;
    FileReaderMock* m_reader;
    BoostSerializationFileStorage* m_storage;
};

}

#endif
