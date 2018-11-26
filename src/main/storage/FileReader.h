#ifndef SRC_MAIN_STORAGE_FILEREADER_H_
#define SRC_MAIN_STORAGE_FILEREADER_H_

#include <string>

namespace KegeratorDisplay {

class FileReader
{
public:
    virtual ~FileReader() {};

    virtual std::string read(const std::string& filename) = 0;
};

}

#endif
