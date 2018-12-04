#ifndef SRC_TEST_STORAGE_FILEREMOVERMOCK_H_
#define SRC_TEST_STORAGE_FILEREMOVERMOCK_H_

#include "storage/FileRemover.h"
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class FileRemoverMock : public FileRemover
{
public:
    MOCK_METHOD1(removeFile, void(const std::string&));
};

}

#endif
