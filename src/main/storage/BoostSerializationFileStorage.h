#ifndef SRC_MAIN_STORAGE_BOOSTSERIALIZATIONFILESTORAGE_H_
#define SRC_MAIN_STORAGE_BOOSTSERIALIZATIONFILESTORAGE_H_

#include <interactors/Storage.h>
#include <string>

namespace KegeratorDisplay {

class FileWriter;
class FileReader;

class BoostSerializationFileStorage : public Storage
{
public:
    BoostSerializationFileStorage(const std::string& temperatureFilename,
                const std::string& leftTapFilename,
                const std::string& rightTapFilename,
                FileWriter* writer,
                FileReader* reader);
    virtual ~BoostSerializationFileStorage();

    virtual Temperature* readTemperature();
    void writeTemperature(Temperature* temperature);

    Tap* readLeftTap();
    void writeLeftTap(Tap*);

    Tap* readRightTap();
    void writeRightTap(Tap*);

private:
    Temperature* createTemperatureFromString(const std::string& serialized);
    Tap* createTapFromString(const std::string& serialized);

    std::string readFile(const std::string& filename);
    void writeFile(const std::string& filename, const std::string& data);

    const std::string serializeTemperature(Temperature* temperature);
    const std::string serializeTap(Tap* temperature);

    const std::string m_temperatureFilename;
    const std::string m_leftTapFilename;
    const std::string m_rightTapFilename;
    FileWriter* m_writer;
    FileReader* m_reader;
};

}

#endif
