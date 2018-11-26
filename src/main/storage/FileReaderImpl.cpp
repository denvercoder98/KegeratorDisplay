#include "storage/FileReaderImpl.h"

#include <fstream>
#include <sstream>

namespace KegeratorDisplay {

FileReaderImpl::FileReaderImpl()
{
}

FileReaderImpl::~FileReaderImpl()
{
}

std::string FileReaderImpl::read(const std::string& filename)
{
    std::ifstream file(filename);
    std::string line;
    std::ostringstream fileContentsStream;
    std::string fileContents = "";

    file.open(filename);
    if (file.is_open()) {
        while (getline(file, line)) {
            fileContentsStream << line << std::endl;
        }
        file.close();
        fileContents = fileContentsStream.str();
    }
    else {
        //TODO raise exception?
    }
    return fileContents;
}

}
