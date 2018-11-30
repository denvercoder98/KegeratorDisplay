#ifndef SRC_MAIN_STORAGE_FILEREMOVER_H_
#define SRC_MAIN_STORAGE_FILEREMOVER_H_

#include <iostream>

namespace KegeratorDisplay {

class FileRemover
{
public:
    virtual ~FileRemover() {};

    virtual void removeFile(const std::string& filename) = 0;
};

}

#endif
