#include <storage/FileWriterImpl.h>
#include <fstream>

namespace KegeratorDisplay {

FileWriterImpl::FileWriterImpl()
{
}

FileWriterImpl::~FileWriterImpl()
{
}

void FileWriterImpl::truncateAndWrite(const std::string& filename,
                                      const std::string& data)
{
    std::ofstream file(filename);
    if (file.is_open()) {
        file << data << std::endl;
        file.close();
    }
    else {
        //TODO raise exception?
    }
}

}
