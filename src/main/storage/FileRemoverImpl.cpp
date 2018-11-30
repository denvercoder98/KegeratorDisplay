#include "FileRemoverImpl.h"
#include <cstdio>

namespace KegeratorDisplay {

FileRemoverImpl::FileRemoverImpl()
{
}

FileRemoverImpl::~FileRemoverImpl()
{
}

void FileRemoverImpl::removeFile(const std::string& filename)
{
    remove(filename.c_str());
    //TODO error handling
}

}
