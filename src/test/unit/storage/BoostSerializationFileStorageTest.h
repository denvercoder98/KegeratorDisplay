#ifndef SRC_TEST_STORAGE_BOOSTSERIALIZATIONFILESTORAGETEST_H_
#define SRC_TEST_STORAGE_BOOSTSERIALIZATIONFILESTORAGETEST_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class FileWriterMock;
class FileReaderMock;
class FileRemoverMock;
class BoostSerializationFileStorage;

class BoostSerializationFileStorageTest : public testing::Test
{
public:
    BoostSerializationFileStorageTest();
    virtual ~BoostSerializationFileStorageTest();

protected:
    void SetUp();
    void TearDown();

    FileWriterMock* m_writer;
    FileReaderMock* m_reader;
    FileRemoverMock* m_remover;
    BoostSerializationFileStorage* m_storage;
};

}

#endif
