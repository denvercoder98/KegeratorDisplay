#ifndef SRC_MAIN_STORAGE_FILEWRITERIMPL_H_
#define SRC_MAIN_STORAGE_FILEWRITERIMPL_H_

#include <storage/FileWriter.h>

namespace KegeratorDisplay {

class FileWriterImpl: public FileWriter
{
public:
    FileWriterImpl();
    virtual ~FileWriterImpl();

    void truncateAndWrite(const std::string& filename, const std::string& data);
};

}

#endif
