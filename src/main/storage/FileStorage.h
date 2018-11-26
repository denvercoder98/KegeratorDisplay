#ifndef SRC_MAIN_STORAGE_FILESTORAGE_H_
#define SRC_MAIN_STORAGE_FILESTORAGE_H_

#include <monitor/Storage.h>
#include <string>

namespace KegeratorDisplay {

class FileWriter;
class FileReader;

class FileStorage : public Storage
{
public:
    FileStorage(const std::string& temperatureFilename, FileWriter* writer, FileReader* reader);
    virtual ~FileStorage();

    virtual Temperature* readTemperature();
    void writeTemperature(Temperature* temperature);

    virtual Tap* readLeftTap();
    virtual Tap* readRightTap();
private:
    const std::string m_temperatureFilename;
    FileWriter* m_writer;
    FileReader* m_reader;
};

}

#endif
