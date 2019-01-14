#ifndef SRC_MAIN_STORAGE_FILEREADERIMPL_H_
#define SRC_MAIN_STORAGE_FILEREADERIMPL_H_

#include "FileReader.h"

namespace KegeratorDisplay {

class FileReaderImpl: public FileReader
{
public:
    FileReaderImpl();
    virtual ~FileReaderImpl();

    std::string read(const std::string& filename);
};

}

#endif
