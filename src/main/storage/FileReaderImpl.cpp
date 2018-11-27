#include "storage/FileReaderImpl.h"

#include <fstream>
#include <sstream>
#include <iostream>

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

    if (file.is_open()) {
        while (file.good()) {
            getline(file, line);
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
