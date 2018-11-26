#ifndef SRC_TEST_STORAGE_FILEWRITERMOCK_H_
#define SRC_TEST_STORAGE_FILEWRITERMOCK_H_

#include <storage/FileWriter.h>

namespace KegeratorDisplay {

class FileWriterMock : public FileWriter
{
public:
    MOCK_METHOD2(truncateAndWrite, void(const std::string&, const std::string&));
};

}

#endif
