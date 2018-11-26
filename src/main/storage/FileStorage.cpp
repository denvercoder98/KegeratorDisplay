#include <storage/FileStorage.h>
#include "storage/FileWriter.h"
#include "storage/FileReader.h"
#include "monitor/Temperature.h"

#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/split_member.hpp>

BOOST_SERIALIZATION_SPLIT_FREE(KegeratorDisplay::Temperature)

namespace boost {
namespace serialization {

template<class Archive>
void save(Archive & ar, const KegeratorDisplay::Temperature& t, const unsigned int version)
{
    std::vector<int> readings = t.getReadings();
    ar & readings;
}

template<class Archive>
void load(Archive & ar, KegeratorDisplay::Temperature& t, const unsigned int version)
{
    std::vector<int> readings;
    ar & readings;
    t.setReadings(readings);
}

} // namespace serialization
} // namespace boost

namespace KegeratorDisplay {

FileStorage::FileStorage(const std::string& temperatureFilename, FileWriter* writer, FileReader* reader) :
    m_temperatureFilename(temperatureFilename),
    m_reader(reader),
    m_writer(writer)
{
}

FileStorage::~FileStorage()
{
    delete m_writer;
    delete m_reader;
}

Temperature* FileStorage::readTemperature()
{
    std::string serialized = m_reader->read(m_temperatureFilename);
    std::istringstream ss(serialized);
    boost::archive::text_iarchive ia(ss);
    Temperature *t = new Temperature();
    ia >> *t;
    return t;
}

void FileStorage::writeTemperature(Temperature* temperature)
{
    std::ostringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << *temperature;
    const std::string serialized = ss.str();
    m_writer->truncateAndWrite(m_temperatureFilename, serialized);
}

Tap* FileStorage::readLeftTap()
{

}

Tap* FileStorage::readRightTap()
{

}

}
