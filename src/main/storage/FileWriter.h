#ifndef SRC_MAIN_STORAGE_FILEWRITER_H_
#define SRC_MAIN_STORAGE_FILEWRITER_H_

#include <string>

namespace KegeratorDisplay {

class FileWriter
{
public:
    virtual ~FileWriter() {};

    virtual void truncateAndWrite(const std::string& filename, const std::string& data) = 0;
};

}

#endif
