#ifndef SRC_MAIN_STORAGE_FILEREMOVERIMPL_H_
#define SRC_MAIN_STORAGE_FILEREMOVERIMPL_H_

#include <storage/FileRemover.h>

namespace KegeratorDisplay {

class FileRemoverImpl: public FileRemover
{
public:
    FileRemoverImpl();
    virtual ~FileRemoverImpl();

    void removeFile(const std::string& filename);
};

}

#endif
