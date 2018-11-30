#include "storage/FileWriter.h"
#include "storage/FileReader.h"
#include "storage/FileRemover.h"
#include "storage/BoostSerializationFileStorage.h"
#include "storage/BoostSerializer.h"
#include "entities/Tap.h"
#include "entities/Temperature.h"

#include <sstream>
#include <string>

namespace KegeratorDisplay {

BoostSerializationFileStorage::BoostSerializationFileStorage(const std::string& temperatureFilename,
                         const std::string& leftTapFilename,
                         const std::string& rightTapFilename,
                         FileWriter* writer,
                         FileReader* reader,
                         FileRemover* remover) :
    m_temperatureFilename(temperatureFilename),
    m_leftTapFilename(leftTapFilename),
    m_rightTapFilename(rightTapFilename),
    m_reader(reader),
    m_writer(writer),
    m_remover(remover)
{
}

BoostSerializationFileStorage::~BoostSerializationFileStorage()
{
    delete m_writer;
    delete m_reader;
    delete m_remover;
}

Temperature* BoostSerializationFileStorage::readTemperature()
{
    std::string serialized = readFile(m_temperatureFilename);
    return createTemperatureFromString(serialized);
}

void BoostSerializationFileStorage::writeTemperature(Temperature* temperature)
{
    const std::string serialized = serializeTemperature(temperature);
    writeFile(m_temperatureFilename, serialized);
}

Tap* BoostSerializationFileStorage::readLeftTap()
{
    std::string serialized = readFile(m_leftTapFilename);
    return createTapFromString(serialized);
}

void BoostSerializationFileStorage::writeLeftTap(Tap* tap)
{
    std::string serialized = serializeTap(tap);
    writeFile(m_leftTapFilename, serialized);
}

Tap* BoostSerializationFileStorage::readRightTap()
{
    std::string serialized = readFile(m_rightTapFilename);
    return createTapFromString(serialized);
}

void BoostSerializationFileStorage::writeRightTap(Tap* tap)
{
    std::string serialized = serializeTap(tap);
    writeFile(m_rightTapFilename, serialized);
}

std::string BoostSerializationFileStorage::readFile(const std::string& filename)
{
    return m_reader->read(filename);
}

void BoostSerializationFileStorage::writeFile(const std::string& filename, const std::string& serialized)
{
    m_writer->truncateAndWrite(filename, serialized);
}

Temperature* BoostSerializationFileStorage::createTemperatureFromString(const std::string& serialized)
{
    if (serialized.empty()) {
        return new Temperature();
    }
    std::istringstream ss(serialized);
    boost::archive::text_iarchive ia(ss);
    Temperature *t = new Temperature();
    ia >> *t;
    return t;
}

Tap* BoostSerializationFileStorage::createTapFromString(const std::string& serialized)
{
    if (serialized.empty()) {
        return new Tap();
    }

    std::istringstream ss(serialized);
    boost::archive::text_iarchive ia(ss);
    Tap *t = new Tap();
    ia >> *t;
    return t;
}

const std::string BoostSerializationFileStorage::serializeTemperature(Temperature* temperature)
{
    std::ostringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << *temperature;
    const std::string serialized = ss.str();
    return serialized;
}

const std::string BoostSerializationFileStorage::serializeTap(Tap* tap)
{
    std::ostringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << *tap;
    const std::string serialized = ss.str();
    return serialized;
}

void BoostSerializationFileStorage::clearLeftTap()
{
    m_remover->removeFile(m_leftTapFilename);
}

void BoostSerializationFileStorage::clearRightTap()
{
    m_remover->removeFile(m_rightTapFilename);
}

}
