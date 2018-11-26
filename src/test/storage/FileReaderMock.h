#ifndef SRC_TEST_STORAGE_FILEREADERMOCK_H_
#define SRC_TEST_STORAGE_FILEREADERMOCK_H_

#include <storage/FileReader.h>

namespace KegeratorDisplay {

class FileReaderMock : public FileReader
{
public:
    MOCK_METHOD1(read, std::string(const std::string&));
};

}

#endif
